<?php

namespace Drupal\pw_userarchives;


use Drupal\pw_globals\PWUser;

/**
 * Manages a complete reset of the user archive cache table
 */
class BatchResetUserArchiveCacheTable {

  public static function runBatch(&$context) {
    if (empty($context['sandbox'])) {

      $query = db_select('user_revision', 'ur');
      // join revisionable roles for user_roles
      $query->join('field_revision_field_user_roles_for_view_mode_s', 'role_tid', "role_tid.entity_type = 'user' AND role_tid.revision_id = ur.vid");
      $query->join('taxonomy_term_data', 'role', 'role.tid = role_tid.field_user_roles_for_view_mode_s_tid');
      $query->condition('ur.status', '1');
      $query->condition('role.name', array('Deputy', 'Candidate'));
      $query->addField('ur', 'uid');
      $query->groupBy('uid');

      $result = $query->execute()->fetchAll();

      $context['sandbox']['progress'] = 0;
      $context['sandbox']['max'] = count($result);
      $context['sandbox']['last_id'] = 1;
    }

    $limit = 300;
    $query = db_select('user_revision', 'ur');
    // join revisionable roles for user_roles
    $query->join('field_revision_field_user_roles_for_view_mode_s', 'role_tid', "role_tid.entity_type = 'user' AND role_tid.revision_id = ur.vid");
    $query->join('taxonomy_term_data', 'role', 'role.tid = role_tid.field_user_roles_for_view_mode_s_tid');
    $query->condition('ur.status', '1');
    $query->condition('role.name', array('Deputy', 'Candidate'));
    $query->condition('uid', $context['sandbox']['last_id'], '>');
    $query->addField('ur', 'uid');
    $query->groupBy('uid');
    $query->orderBy('uid');
    $query->range(0, $limit);
    $result = $query->execute()->fetchAllAssoc('uid');

    $accounts = user_load_multiple(array_keys($result));

    foreach ($accounts as $account) {
      pw_userarchives_update_by_user($account);
      $PWUser = new PWUser($account);
      $message = 'Entries updated for '. $PWUser->getFullName();
      $context['results'][] = $message;
      $context['sandbox']['progress']++;
      $context['message'] = $message;
      $context['sandbox']['last_id'] = $PWUser->uid;
    }


    if ($context['sandbox']['progress'] != $context['sandbox']['max'] && $context['sandbox']['progress'] < $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
    else {
      $context['finished'] = 1;
    }
  }


  public static function finished($success, $results, $operations) {
    $count_results = count($results);
    if ($success) {
      drupal_set_message('Es wurden Profile für '. $count_results .' Politiker erstellt.');
    }
    else {
      drupal_set_message('Es wurden Profile für '. $count_results .' Politiker erstellt, allerdings lief etwas schief.', 'warning');
    }

  }

}