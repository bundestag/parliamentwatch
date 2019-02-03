<?php

/**
 * @file pw_maintenance.user_merge.inc
 *
 */



/**
 * Form builder for merging users.
 */
function pw_maintenance_user_merge($form, &$form_state) {

  $user_source = isset($form_state['values']['user_source']) ? $form_state['values']['user_source'] : '';

  $form['user_source'] = array(
    '#type' => 'textfield',
    '#title' => t('User source'),
    '#autocomplete_path' => 'user/autocomplete',
    '#default_value' => '',
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'dependent_parliaments_callback',
      'wrapper' => 'select-replace',
    ),
  );

  $options = get_parliaments_options($user_source);
  $form['parliaments_replace'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Parliaments'),
    '#prefix' => '<div id="select-replace">',
    '#suffix' => '</div>',
    '#options' => $options,
    '#default_value' => isset($form_state['values']['parliaments_replace']) ? $form_state['values']['parliaments_replace'] : $options,
  );

  $form['user_target'] = array(
    '#type' => 'textfield',
    '#title' => t('User target'),
    '#autocomplete_path' => 'user/autocomplete',
    '#default_value' => '',
    '#required' => TRUE,
  );

  // add submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Merge Users',
  );

  // add custom submit handler
  $form['#submit'][] = 'pw_maintenance_user_merge_submit';

  return $form;
}




/**
 * Selects just the second dropdown to be returned for re-rendering.
 *
 * Since the controlling logic for populating the form is in the form builder
 * function, all we do here is select the element and return it to be updated.
 *
 * @return array
 *   Renderable array (the second dropdown)
 */
function dependent_parliaments_callback($form, $form_state) {
  return $form['parliaments_replace'];
}

/**
 * Helper function to populate the second dropdown.
 *
 * This would normally be pulling data from the database.
 *
 * @param string $key
 *   This will determine which set of options is returned.
 *
 * @return array
 *   Dropdown options
 */
function get_parliaments_options($user_source = '') {
  if (empty($user_source)) {
    return [];
  }
  $query = db_select('user_archive_cache', 'uac')
  ->fields('uac', ['parliament_name', 'user_role']);
  _pw_uac_add_conditions($query, [
      'username' => $user_source,
    ]
  );

  $options = [];
  foreach ($query->execute()->fetchAll() as $result) {
    $options[] = $result->parliament_name . ' (' . t($result->user_role) . ')';
  }
  return $options;
}


/**
 * Form submit handler.
 * Merges one user into another by running through all tables and updates them.
 */
function pw_maintenance_user_merge_submit($form, &$form_state) {

  // user
  global $user;

  // selected users to merge
  $user_source = user_load_by_name($form['user_source']['#value']);
  if(!$user_source){
    drupal_set_message('User '.$form['user_source']['#value'].' not exists.', 'error');
    return FALSE;
  }
  $user_target = user_load_by_name($form['user_target']['#value']);
  if(!$user_target){
    drupal_set_message('User '.$form['user_target']['#value'].' not exists.', 'error');
    return FALSE;
  }
  if($user_source->uid == $user_target->uid){
    drupal_set_message('Can not merge user object into itself.', 'error');
    return FALSE;
  }

  // load all database schemes
  $schemes = drupal_get_schema(NULL, TRUE);
  $excluded_tables = array('feeds_item', 'users', 'users_roles', 'user_archive_cache');
  $schemes = array_diff_key($schemes, array_flip($excluded_tables));
  ksort($schemes);

  foreach($schemes as $table => $schema){
    if (strpos($table, 'field_deleted_') === 0) {
      continue;
    }

    // update tables with columns uid
    if(array_key_exists('uid', $schema['fields'])){
      db_update($table)
        ->fields(array(
          'uid' => $user_target->uid,
        ))
        ->condition('uid', $user_source->uid)
        ->execute();
    }

    // update tables with columns entity_type=user and entity_id excluding field_data-tables which will be handled by user_delete later
    if(array_key_exists('entity_id', $schema['fields']) && array_key_exists('entity_type', $schema['fields']) && !preg_match('/^field_data_/', $table)){
      db_update($table)
        ->fields(array(
          'entity_id' => $user_target->uid,
        ))
        ->condition('entity_id', $user_source->uid)
        ->condition('entity_type', 'user')
        ->execute();
    }

    // update references to the user stored eg. in node fields
    $field_name = preg_replace('/^field_[^_]+_/', '', $table);
    if(array_key_exists($field_name.'_target_id', $schema['fields'])){
      $field_info = field_info_field($field_name);
      if($field_info['settings']['target_type'] == 'user'){

        // update entities
        if (preg_match('/^field_data_/', $table)) {
          $efq_query = new EntityFieldQuery();
          $efq_query->fieldCondition($field_name, 'target_id', $user_source->uid);
          $result = $efq_query->execute();
          foreach ($result as $key => $entity_ids) {
            $entities = call_user_func($key . '_load_multiple', array_keys($entity_ids));
            foreach ($entities as $entity) {
              $entity->{$field_name}[LANGUAGE_NONE][0]['target_id'] = $user_target->uid;
              call_user_func($key . '_save', $entity);
            }
          }
        }
        else {
          // update revisions
          db_update($table)
            ->fields(array(
              $field_name . '_target_id' => $user_target->uid,
            ))
            ->condition($field_name . '_target_id', $user_source->uid)
            ->execute();
        }
      }
    }
  }

  // add redirect from the source user to the target one
  if(module_exists('redirect')){
    if(($redirect = redirect_load_by_source("user/".$user_source->uid, LANGUAGE_NONE, array(), FALSE)) ||
        ($redirect = redirect_load_by_source("profile/".$user_source->name, LANGUAGE_NONE, array(), FALSE))){
      $redirect->status = 1;
      $redirect->redirect = 'user/'.$user_target->uid;
    }
    else{
      $redirect = new stdClass();
      redirect_object_prepare($redirect, array(
        'source' => 'profile/'.$user_source->name,
        'redirect' => 'user/'.$user_target->uid,
        )
      );
    }
    redirect_save($redirect);
  }

  // connect all user revisions with the target user
  db_update("user_revision")
    ->fields(array(
      'name' => $user_target->name,
    ))
    ->condition('uid', $user_target->uid)
    ->execute();

  // update associated files
  db_update("file_usage")
    ->fields(array(
      'id' => $user_target->uid,
    ))
    ->condition('id', $user_source->uid)
    ->condition('type', 'user')
    ->execute();

  // delete all entries from meta table related to the source user
  db_delete('user_archive_cache')
    ->condition('uid', $user_source->uid)
    ->execute();

  // user names for output
  $user_source_fullname = _pw_get_fullname($user_source);

  // remove source user from system
  user_delete($user_source->uid);

  // clear field caches to refresh field information in forms
  field_cache_clear();

  // rebuild meta table
  pw_userarchives_cron_ALT($user_target->uid);

  // message to the frontend
  $msg = 'User '.$user_source_fullname.' (UUID: '.$user_source->uuid.') merged into '.l(_pw_get_fullname($user_target), 'user/'.$user_target->uid).' (UUID: '.$user_target->uuid.')';
  drupal_set_message($msg);
  watchdog('pw_maintenance', $msg);
}
