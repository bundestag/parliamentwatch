<?php


namespace Drupal\pw_userarchives;

use Drupal\pw_globals\Politician;
use Drupal\pw_globals\PoliticianUserRevision;


/**
 * Manages all UserArchiveEntry items for a single politician. This class is used
 * to update, create or delete entries in user_archive_cache table
 *
 * @todo pw_reset_actuale_profile() Aufrufen
 * @todo pw_delete_old_user_revisions() integrieren (irgendwo)
 *
 */
class UserArchiveManager {

  /**
   * @var \Drupal\pw_globals\Politician
   */
  protected $politician;


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
      $entriesToArchive = $this->getEntriesToArchiveByRevisions();
      $existingArchiveEntries = $this->getExistingUserArchiveEntriesByUid($this->politician->getId());

      $this->deleteOutdatedArchiveEntries($entriesToArchive, $existingArchiveEntries);
      $this->updateExistingArchiveEntries($entriesToArchive, $existingArchiveEntries);
      $this->insertNewArchiveEntries($entriesToArchive, $existingArchiveEntries);

      if ($reset_actual_profile) {
        pw_reset_actuale_profile($this->politician->getId());
      }
    }
    catch (\Exception $e) {
      $transaction->rollback();
      $error_message = 'An error appeared while rebuilding user archive entries for user '. $this->politician->getId() .' ('. check_plain($this->politician->getFullName()) .'): '. $e->getMessage();
      drupal_set_message($error_message, 'error');
      watchdog_exception('PW User Archives', $e, $error_message);
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
  protected function getEntriesToArchiveByRevisions() {
    $user_revision_vids = $this->loadUserRevisionsVids();
    $items_to_archive = [];

    foreach ($user_revision_vids as $vid) {
      $politicianUserRevision = PoliticianUserRevision::loadFromUidAndVid($this->politician->getId(), $vid);
      $user_role = $politicianUserRevision->getPoliticianRole();

      $fraction_name = NULL;
      $fraction = $politicianUserRevision->getFraction();
      if ($fraction !== NULL) {
        $fraction_name = $fraction->getName();
      }

      $question_form_open = (int) $this->checkIfQuestionFormOpen($politicianUserRevision);
      $uid = $this->politician->getId();
      $user_name = $this->politician->getAccount()->name;

      $parliament = $politicianUserRevision->getParliament();
      $parliament_name = $parliament->getName();
      $timestamp = $parliament->getElectionDate();
      $number_of_questions = count($politicianUserRevision->getQuestionsNids());
      $number_of_answers = $politicianUserRevision->getAnswersCids('non-standard');
      $number_of_standard_replies = $politicianUserRevision->getAnswersCids('standard');

      $user_joined = $politicianUserRevision->getJoinedDate();
      if ($user_joined !== NULL) {
        $user_joined = date('Y-m-d', $user_joined);
      }
      $user_retired = $politicianUserRevision->getRetiredDate();
      if ($user_retired !== NULL) {
        $user_retired = date('Y-m-d', $user_retired);
      }

      $actual_profile = (int) $politicianUserRevision->isActualProfile();

      $items_to_archive[$vid] = new UserArchiveEntry($uid, $user_name, $user_role, $vid, $parliament_name, $timestamp, $fraction_name, $actual_profile , $user_joined, $user_retired, $question_form_open, $number_of_questions, $number_of_answers, $number_of_standard_replies );
    }

    return $items_to_archive;
  }

  /**
   * Load the user revisions vids of those revisions with the highest vid of
   * each combination of parliament, fraction and user role
   *
   * @return array
   * Array of user revision vids or empty if none was found
   */
  protected function loadUserRevisionsVids() {
    // db_select: user revision
    $query = db_select('user_revision', 'ur');
    $query->addExpression('MAX(ur.vid)', 'vid');

    // join taxonomy terms for parliament names
    $query->join('field_revision_field_user_parliament', 'u_parl', "u_parl.entity_type = 'user' AND ur.vid = u_parl.revision_id");
    $query->join('taxonomy_term_data', 'parliament', 'parliament.tid = u_parl.field_user_parliament_tid');

    // join fractions for fraction tids
    $query->leftJoin('field_revision_field_user_fraction', 'fraction_tid', "fraction_tid.entity_type = 'user' AND fraction_tid.revision_id = ur.vid");
    $query->leftJoin('taxonomy_term_data', 'fraction', 'fraction.tid = fraction_tid.field_user_fraction_tid');

    // join revisionable roles for user_roles
    $query->join('field_revision_field_user_roles_for_view_mode_s', 'role_tid', "role_tid.entity_type = 'user' AND role_tid.revision_id = ur.vid");
    $query->join('taxonomy_term_data', 'role', 'role.tid = role_tid.field_user_roles_for_view_mode_s_tid');

    // query conditions
    $query->condition('ur.status', '1');
    $query->condition('ur.uid', $this->politician->getId());
    $query->condition('role.name', array('Deputy', 'Candidate'));

    // add fields
    $query->groupBy('ur.uid, u_parl.field_user_parliament_tid, role_tid.field_user_roles_for_view_mode_s_tid, fraction_tid.field_user_fraction_tid');

    // fetch all relevant vids as flat array
    return $query->execute()->fetchCol();
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
  public function checkIfQuestionFormOpen(PoliticianUserRevision $userRevision) {
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
   * Load the user archive items which are currently stored in table
   *
   * @param int|string $uid
   * The Drupal user uid of the politician
   *
   * @return \Drupal\pw_userarchives\UserArchiveEntry[]
   * An array of UserArchiveEntry objects. Empty if none was found
   */
  protected function getExistingUserArchiveEntriesByUid($uid) {
    $query = db_select('user_archive_cache', 'uac')
      ->condition('uac.uid', $uid)
      ->fields('uac')
      ->execute();

    $entries = [];

    while ($record = $query->fetchAssoc()) {
      $userArchiveEntry = UserArchiveEntry::createFromDataBaseArray($record);
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

      $politician_index = search_api_index_load('politician_archive_index');
      if ($politician_index && !empty($deleted_vids)) {
        search_api_track_item_delete('user_revision', $deleted_vids);
      }
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

      $politician_index = search_api_index_load('politician_archive_index');
      if ($politician_index && !empty($updated_vids)) {
        search_api_track_item_change('user_revision', $updated_vids);
      }
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

      $politician_index = search_api_index_load('politician_archive_index');
      if ($politician_index && !empty($inserted_vids)) {
        search_api_track_item_insert('user_revision', $inserted_vids);
      }
    }
    catch (\Exception $e) {
      $transaction->rollback();
      throw $e;
    }
  }
}