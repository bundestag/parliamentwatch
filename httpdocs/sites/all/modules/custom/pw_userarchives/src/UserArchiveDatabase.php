<?php

namespace Drupal\pw_userarchives;


/**
 * A central class for managing user archive cache related database
 * queries.
 */
class UserArchiveDatabase {

  /**
   * Load the user revisions vids of those revisions with the highest vid of
   * each combination of parliament, fraction and user role
   *
   * @param string $politician_uid
   * The Drupal user uid of the politician. Optional
   *
   * @param string $parliament_tid
   * The term id of the parliament the user revisions are needed for. Optional
   *
   * @param string $role
   * Can be "Deputy" or "Candidate". Optional, if empty all candidacies and mandates will
   * be loaded
   *
   * @return array
   * Array of user revision vids
   *
   */
  public static function loadUserRevisionVidsForArchive($politician_uid = '', $parliament_tid = '', $role = '') {
    if (empty($role)) {
      $role = ['Deputy', 'Candidate'];
    }

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

    if (!empty($politician_uid)) {
      $query->condition('ur.uid', $politician_uid);
    }
    $query->condition('role.name', $role);

    if (!empty($parliament_tid)) {
      $query->condition('parliament.tid', $parliament_tid);
    }

    // add fields
    $query->groupBy('ur.uid, u_parl.field_user_parliament_tid, role_tid.field_user_roles_for_view_mode_s_tid, fraction_tid.field_user_fraction_tid');

    // fetch all relevant vids as flat array
    return $query->execute()->fetchCol();
  }


  /**
   * Load existing user archive entries by conditions.
   *
   * @param array $conditions
   * Define each condition as [COLUMN_NAME] => [VALUE]. If value is a single
   * value "=" will be used for comparison. If value is an array "IN" will be
   * the used operator. As a condition any field/ column in user_archive_cache
   * table can be used.
   *
   * @return array
   * An array of results where each result is an array of column/ value pairs.
   */
  public static function getExistingArchiveEntries($conditions = []) {
    $records = [];

    try {
      $query = db_select('user_archive_cache', 'uac')
        ->fields('uac');

      foreach ($conditions as $key => $value) {
        $query->condition('uac.'. $key, $value);
      };

      $result = $query->execute();

      while ($record = $result->fetchAssoc()) {
        $records[] = $record;
      }
      return $records;
    }
    catch (\Exception $e) {
      watchdog_exception('pw_userarchives', $e, $e->getMessage());
      return $records;
    }
  }


  /**
   * Get the user revision which is valid for a given user, parliament, date and
   * role.
   *
   * For politicians who have more than one candidate or deputy profile maybe
   * caused by party or fraction changes this function helps to get the revision
   * which stores the valid data for a given date.
   *
   * @param int|string $uid
   * The Drupal user uid
   *
   * @param string $parliament_name
   * The parliament's term name
   *
   * @param string $date
   *  The date on format 'Y-m-d'
   *
   * @param string $role
   * Can be 'deputy' or 'candidate'. Optional, default is 'deputy'
   *
   * @return object|FALSE
   * False if no user revision was loaded - the user revision otherwise
   */
  public static function getRevisionValidOnDate($uid, $parliament_name, $date, $role = 'deputy') {
    $q = db_select('user_archive_cache', 'uac');
    $q->fields('uac', ['vid'])
      ->orderBy('uac.timestamp', 'DESC')
      ->condition('uac.uid', $uid)
      ->condition('uac.user_role', $role)
      ->condition('uac.parliament_name', $parliament_name);
    $or_user_joined = db_or();
    $or_user_joined->condition('uac.user_joined', $date, '<=');
    $or_user_joined->condition('uac.user_joined', NULL);
    $q->condition($or_user_joined);
    $or_user_retired = db_or();
    $or_user_retired->condition('uac.user_retired', $date, '>');
    $or_user_retired->condition('uac.user_retired', NULL);
    $q->condition($or_user_retired);

    return user_revision_load($uid, $q->execute()->fetchField());
  }

}
