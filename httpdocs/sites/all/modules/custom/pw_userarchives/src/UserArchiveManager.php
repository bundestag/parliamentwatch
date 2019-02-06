<?php


namespace Drupal\pw_userarchives;

use Drupal\pw_globals\Parliament;
use Drupal\pw_globals\Politician;
use Drupal\pw_globals\PoliticianUserRevision;


/**
 * Manages all UserArchiveEntry items for a single politician. This class is used
 * to update, create or delete entries in user_archive_cache table
 *
 * @todo pw_delete_old_user_revisions() integrieren (irgendwo)
 *
 */
class UserArchiveManager {

  /**
   * @var \Drupal\pw_globals\Politician
   */
  protected $politician;


  /**
   * @var array
   * Array of user revision vids for which a new entry in user archive cache
   * was created
   */
  protected $insertedVids = [];


  /**
   * @var array
   * Array of user revision vids for which user archive entries already existed
   * and which were updated
   */
  protected $updatedVids = [];


  /**
   * @var array
   * Array of user revision vids for which user archive entries already existed
   * and which were deleted from user archive cache
   */
  protected $deletedVids = [];

  /**
   * UserArchiveManager constructor.
   *
   * @param \Drupal\pw_globals\Politician $politican
   */
  public function __construct(Politician $politican) {
    $this->politician = $politican;
  }


  /**
   * Call this function to update, insert or delete user archive entries
   * for a politician
   *
   * @param bool $reset_actual_profile
   * Default is true. If true pw_reset_actuale_profile() will be called
   *
   * @throws \Exception
   */
  public function updateEntries($reset_actual_profile = TRUE) {
    $transaction = db_transaction();
    try {
      $entriesToArchive = $this->createEntriesToArchiveByRevisions();
      $existingArchiveEntries = $this->getExistingUserArchiveEntriesByUid($this->politician->getId());

      $this->deleteOutdatedArchiveEntries($entriesToArchive, $existingArchiveEntries);
      $this->updateExistingArchiveEntries($entriesToArchive, $existingArchiveEntries);
      $this->insertNewArchiveEntries($entriesToArchive, $existingArchiveEntries);

      if ($reset_actual_profile) {
        pw_reset_actuale_profile($this->politician->getId());
      }

      $this->updateSearchAPI();
    }
    catch (\Exception $e) {
      $transaction->rollback();
      $error_message = 'An error appeared while rebuilding user archive entries for user '. $this->politician->getId() .' ('. check_plain($this->politician->getFullName()) .'): '. $e->getMessage();
      drupal_set_message('An error appeared. Please contact the site administrator', 'warning');
      watchdog_exception('pw_userarchives', $e, $error_message);
    }
  }


  /**
   *
   * Collects the user revision vids which should be in user archive table and
   * collect all data needed for user archive. The data is added to initialised
   * instances of \Drupal\pw_userarchives\UserArchiveEntry
   *
   * @return \Drupal\pw_userarchives\UserArchiveEntry[]
   * An array of fresh UserArchiveEntry classes - or empty if no user revision
   *   was found for archiving. These classes already have all data which needs
   *   to be added to user_archive_cache
   *
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  protected function createEntriesToArchiveByRevisions() {
    $user_revision_vids = UserArchiveDatabase::loadUserRevisionVidsForArchive($this->politician->getId());
    $items_to_archive = [];

    foreach ($user_revision_vids as $vid) {
      $politicianUserRevision = PoliticianUserRevision::loadFromUidAndVid($this->politician->getId(), $vid);
      $userArchiveEntry = UserArchiveEntry::createFromPolicitianUserRevision($politicianUserRevision);
      if ($userArchiveEntry !== NULL) {
        $items_to_archive[$vid] = $userArchiveEntry;
      }
    }

    return $items_to_archive;
  }


  /**
   * Checks if the question form is open
   *
   * @param \Drupal\pw_globals\PoliticianUserRevision $userRevision
   *
   * @return bool
   * TRUE when the question form is open, FALSE if it is closed
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public static function checkIfQuestionFormOpen(PoliticianUserRevision $userRevision) {
    if ($userRevision->isQuestionFormClosed()) {
      return FALSE;
    }

    $parliament = $userRevision->getParliament();

    if ($userRevision->isActiveMandate() && $parliament->isActiveLegislatureProject()) {
      return TRUE;
    }

    if ($userRevision->isActiveCandidacy() && $parliament->isActiveElectionProject()) {
      return TRUE;
    }

    return FALSE;
  }


  /**
   * Calculate on which day in the future we need to re-validate if the
   * question form is open or closed. It delivers the date in UTC
   *
   */
  public static function calcQuestionFormOpenChange(PoliticianUserRevision $userRevision) {
    // we do not need to re-validate the date when the form is closed by
    // configuration in user revision
    if ($userRevision->isQuestionFormClosed()) {
      return NULL;
    }

    $parliament = $userRevision->getParliament();
    $current_time = REQUEST_TIME;

    // check for user revisions with active mandate. This is also true for archive
    // profiles of mandates in the past
    if ($userRevision->isActiveMandate()) {
      $period = $parliament->getLegislatureValidTimePeriod();
      $period_in_UTC = $parliament->getLegislatureValidTimePeriod('UTC');
      if (empty($period) || !isset($period['start']) || !isset($period['end'])) {
        return NULL;
      }

      // if the politician has an active mandate and the legislature did already start
      // we need to change the question form open state at the end of the legislature
      if ($parliament->isActiveLegislatureProject()) {
        return $period_in_UTC['end'];
      }

      // if the politician has an active mandate for a future legislature
      // we need to change the question form open state when the legislature starts
      if (!$parliament->isActiveLegislatureProject() && $current_time < $period['start']) {
        return $period_in_UTC['start'];
      }
    }

    // check for user revisions with active candidacy. This is also true for archive
    // profiles of candidacies in the past
    if ($userRevision->isActiveCandidacy()) {
      $period = $parliament->getElectionValidTimePeriod();
      $period_in_UTC = $parliament->getElectionValidTimePeriod('UTC');
      if (empty($period) || !isset($period['start']) || !isset($period['end'])) {
        return NULL;
      }

      // if the politician has an active candidacy and the election period did already start
      // we need to change the question form open state at the end of the election period
      if ($parliament->isActiveElectionProject()) {
        return $period_in_UTC['end'];
      }

      // if the politician has an active candidacy for a future election project
      // we need to change the question form open state when the election starts
      if (!$parliament->isActiveElectionProject() && $current_time < $period['start']) {
        return $period_in_UTC['start'];
      }
    }

    return NULL;
  }

  /**
   * Load the user archive items which are currently stored in table
   *
   * @param int|string $uid
   * The Drupal user uid of the politician
   *
   * @return \Drupal\pw_userarchives\UserArchiveEntry[]
   * An array of UserArchiveEntry objects. Empty if none was found
   */
  protected function getExistingUserArchiveEntriesByUid($uid) {
    $entries = [];
    $entriesFromDatabase = UserArchiveDatabase::getExistingArchiveEntries(['uid' => $uid]);

    foreach ($entriesFromDatabase as $entriyFromDatabase) {
      $userArchiveEntry = UserArchiveEntry::createFromDataBaseArray($entriyFromDatabase);
      $entries[$userArchiveEntry->getVid()] = $userArchiveEntry;
    }

    return $entries;
  }


  /**
   * Delete those user archive entries which are outdated. They are outdated when
   * the user revisions were not found in loadUserRevisionsVids()
   *
   * @see \Drupal\pw_userarchives\UserArchiveManager->loadUserRevisionsVids()
   *
   * @param \Drupal\pw_userarchives\UserArchiveEntry[] $entriesToAddToArchive
   * Array of UserArchiveEntry instances for those user revisions which need to
   * be found/ stored in user_archive_cache table. Can be empty.
   *
   * @param \Drupal\pw_userarchives\UserArchiveEntry[] $existingArchiveEntries
   * Array of UserArchiveEntry instances of those entries currently found in
   * user_archive_cache table. Can be empty
   *
   * @throws \Exception
   */
  protected function deleteOutdatedArchiveEntries(array $entriesToAddToArchive, array $existingArchiveEntries) {
    $transaction = db_transaction();
    try {
      /** @var  \Drupal\pw_userarchives\UserArchiveEntry $userArchiveEntry */
      $deleted_vids = [];
      foreach ($existingArchiveEntries as $archived_vid => $userArchiveEntry) {
        if (!array_key_exists($archived_vid, $entriesToAddToArchive)) {
          $userArchiveEntry->delete();
          $deleted_vids[] = $archived_vid;
        }
      }

      $this->deletedVids = $deleted_vids;
    }
    catch (\Exception $e) {
      $transaction->rollback();
      throw $e;
    }
  }


  /**
   * Update those user archive entries of user revisions which were not found
   * in loadUserRevisionsVids anymore.
   *
   * @see \Drupal\pw_userarchives\UserArchiveManager->loadUserRevisionsVids()
   *
   * @param \Drupal\pw_userarchives\UserArchiveEntry[] $entriesToAddToArchive
   * Array of UserArchiveEntry instances for those user revisions which need to
   * be found/ stored in user_archive_cache table. Can be empty.
   *
   * @param \Drupal\pw_userarchives\UserArchiveEntry[] $existingArchiveEntries
   * Array of UserArchiveEntry instances of those entries currently found in
   * user_archive_cache table. Can be empty
   *
   * @throws \Exception
   */
  protected function updateExistingArchiveEntries(array $entriesToAddToArchive, array $existingArchiveEntries) {
    $transaction = db_transaction();
    try {
      $updated_vids = [];
      /** @var  \Drupal\pw_userarchives\UserArchiveEntry $userArchiveEntry */
      foreach ($existingArchiveEntries as $archived_vid => $userArchiveEntry) {
        if (array_key_exists($archived_vid, $entriesToAddToArchive)) {
          /** @var \Drupal\pw_userarchives\UserArchiveEntry $entryToAdd */
          $entryToAdd = $entriesToAddToArchive[$archived_vid];
          // we simple "move" the unique  id of the user archive entry
          // from the existing one to the newly created one
          $entryToAdd->setId($userArchiveEntry->getId());
          $entryToAdd->save();
          $updated_vids[] = $archived_vid;
        }
      }

      $this->updatedVids = $updated_vids;
    }
    catch (\Exception $e) {
      $transaction->rollback();
      throw $e;
    }
  }



  /**
   * Insert those user revisions to the user_archive_cache table which are not
   * already stored there.
   *
   * @see \Drupal\pw_userarchives\UserArchiveManager->loadUserRevisionsVids()
   *
   * @param \Drupal\pw_userarchives\UserArchiveEntry[] $entriesToAddToArchive
   * Array of UserArchiveEntry instances for those user revisions which need to
   * be found/ stored in user_archive_cache table. Can be empty.
   *
   * @param \Drupal\pw_userarchives\UserArchiveEntry[] $existingArchiveEntries
   * Array of UserArchiveEntry instances of those entries currently found in
   * user_archive_cache table. Can be empty
   *
   * @throws \Exception
   */
  protected function insertNewArchiveEntries(array $entriesToAddToArchive, array $existingArchiveEntries) {
    $transaction = db_transaction();
    try {
      $inserted_vids = [];
      /** @var  \Drupal\pw_userarchives\UserArchiveEntry $newUserArchiveEntry */
      foreach ($entriesToAddToArchive as $vid => $newUserArchiveEntry) {
        if (!array_key_exists($vid, $existingArchiveEntries)) {
          $newUserArchiveEntry->save();
          $inserted_vids[] = $vid;
        }
      }

      $this->insertedVids = $inserted_vids;
    }
    catch (\Exception $e) {
      $transaction->rollback();
      throw $e;
    }
  }


  /**
   * Acts as a bridge to UserArchiveSearchAPI class. Collect the inserted and
   * updated user archive entries' vids and those of the entries deleted and call
   * UserArchiveSearchAPI to update the search index.
   */
  protected function updateSearchAPI() {
    // put inserted and updated user revision vids in one array
    $change_items = array_merge($this->updatedVids, $this->insertedVids);
    if (!empty($change_items)) {
      $searchApiChange = new UserArchiveSearchAPI($change_items, 'change');
      $searchApiChange->updateSearchIndex();
    }

    if (!empty($this->deletedVids)) {
      $searchApiDelete = new UserArchiveSearchAPI($this->deletedVids, 'delete');
      $searchApiDelete->updateSearchIndex();
    }
  }


  /**
   * Checks if updates are needed when a parliament term was updated
   *
   * @param object $parliament
   * The term object of the parliament
   *
   * @return bool
   * True if an update is needed, fals if not or if an error appeared.
   */
  public static function updatesNeededOnParliamentUpdate($parliament) {
    if (!is_object($parliament) || !isset($parliament->tid) ) {
      return FALSE;
    }

    try {
      $originalParliament = new Parliament($parliament->original);
      $changedParliament = new Parliament($parliament);

      if ($originalParliament->getName() != $changedParliament->getName()) {
        return TRUE;
      }

      // check if election period has changed somehow
      $electionPeriodOriginal = $originalParliament->getElectionValidTimePeriod();
      $electionPeriodChanged = $changedParliament->getElectionValidTimePeriod();
      if ($electionPeriodOriginal !== $electionPeriodChanged) {
        return TRUE;
      }

      // check if legislature period has changed somehow
      $legislaturePeriodOriginal = $originalParliament->getLegislatureValidTimePeriod();
      $legislaturePeriodChanged = $changedParliament->getLegislatureValidTimePeriod();
      if ($legislaturePeriodOriginal !== $legislaturePeriodChanged) {
        return TRUE;
      }
    }
    catch (\Exception $e) {
      $error_message = 'An error appeared while trying to check if user archive needs update after parliament update: ';
      watchdog_exception('pw_userarchives', $e, $error_message . $e->getMessage());
      drupal_set_message($error_message .'Please contact the amdin', 'warning');
      return FALSE;
    }

    return FALSE;
  }
}