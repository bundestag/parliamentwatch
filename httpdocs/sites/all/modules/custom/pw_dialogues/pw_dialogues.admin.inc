<?php

/**
 * @file pw_dialogues.admin.inc
 *
 */

/**
 * Form constructor for the dialogues importer settings form.
 *
 * @ingroup forms
 */
function pw_dialogues_admin_settings_form($form, &$form_state) {
  $form['pw_dialogues_source'] = array(
    '#type' => 'textfield',
    '#title' => t('XML source API'),
    '#default_value' => variable_get('pw_dialogues_importer_source', ''),
    '#description' => t('If set, dialogues will be imported from this URL during cron runs.'),
    '#element_validate' => array('pw_dialogues_admin_validate_url'),
    '#size' => 100,
  );

  return system_settings_form($form);
}

/**
 * Form element validation handler for pw_dialogues_admin_settings_form().
 */
function pw_dialogues_admin_validate_url(&$element, &$form_state) {
  $value = trim($element['#value']);
  form_set_value($element, $value, $form_state);

  if ($value != '' && !valid_url($value, TRUE)) {
    form_error($element, t('The URL %url is not valid.', array('%url' => $value)));
  }
}


/**
 * Form builder.
 */
function pw_dialogues_admin_reimport($form, &$form_state) {
  $term_options_list = array();
  if ($voc_parliaments = taxonomy_vocabulary_machine_name_load('parliaments')) {
    $efq = new EntityFieldQuery();
    $result = $efq->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', $voc_parliaments->vid)
      ->execute();
    if (!empty($result['taxonomy_term'])) {
      $terms = taxonomy_term_load_multiple(array_keys($result['taxonomy_term']));
      foreach ($terms as $term) {
        $term_options_list[$term->tid] = $term->name;
      }
    }
    //$term_options_list = taxonomy_get_tree($voc_parliaments->vid);
    $term_options_list = array_map('check_plain', $term_options_list);
  }

  // print result table after submission
  if(isset($form_state['storage']['results'])) {

    // clear message queue filled by feeds importer
    drupal_get_messages('status');

    // result table
    $form['pw_dialogues_admin_reimport_result_table'] = array(
      '#type' => 'item',
      '#title' => t('Results'),
      '#markup' => $form_state['storage']['results'],
    );
  }

  $form['pw_dialogues_admin_reimport_parliament'] = array(
    '#type' => 'select',
    '#title' => t('Parliament to import for'),
    '#options' => $term_options_list,
    '#default_value' => variable_get('pw_dialogues_admin_reimport_parliament_tids', ''),
    '#multiple' => TRUE,
    '#size' => 20,
    '#required' => TRUE,
  );

  $form['pw_dialogues_admin_reimport_user_names'] = array(
    '#type' => 'textfield',
    '#title' => t('Restrict to this politicians'),
    '#size' => 30,
    '#maxlength' => 60,
    '#autocomplete_path' => 'user/autocomplete',
    '#default_value' => variable_get('pw_dialogues_admin_reimport_user_names', ''),
  );

  // add submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Update Dialogues',
  );

  $form['pw_dialogues_admin_reimport_delete_existing'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete dialogues before import.'),
  );

  // add custom submit handler
  $form['#submit'][] = 'pw_dialogues_admin_reimport_submit';

  return $form;
}


/**
 * Form submit handler.
 */
function pw_dialogues_admin_reimport_submit($form, &$form_state) {

  // all the parliaments to refresh
  $parliament_tids = $form['pw_dialogues_admin_reimport_parliament']['#value'];
  variable_set('pw_dialogues_admin_reimport_parliament_tids', $parliament_tids);

  // specific user(s) only
  $user_names = $form['pw_dialogues_admin_reimport_user_names']['#value'];
  variable_set('pw_dialogues_admin_reimport_user_names', $user_names);
  $uids = array();
  if(!empty($user_names)){
    foreach(explode(',', $user_names) as $user_name){
      $user = user_load_by_name(trim($user_name));
      if(!empty($user)){
        $uids[] = $user->uid;
      }
    }
  }

  // base url to build on
  $baseurl_modsystem = variable_get('pw_dialogues_importer_source', FALSE);
  if(!$baseurl_modsystem){
    drupal_set_message('variable pw_dialogues_importer_source no set. exiting.', 'error');
    return;
  }

  // prepare table to list results of comparison
  $header = array(
    array('data' => t('Parliament')),
    array('data' => t('Politician')),
    array('data' => t('Dialogue ID')),
    array('data' => t('Before/After Import')),
    array('data' => t('Changes'), 'sort' => 'asc')
  );
  $rows = array();

  $terms = taxonomy_term_load_multiple($parliament_tids);
  foreach ($terms as $parliament) {

    // load all politicians from parliament
    $query = db_select('user_archive_cache', 'uac');
    $query->fields('uac');
    $query->condition('parliament_name', $parliament->name);
    if(!empty($uids)){
      $query->condition('uid', $uids);
    }
    $result_uac = $query->execute();

    if($result_uac->rowCount() == 0){
      drupal_set_message('No users found for '.$parliament->name, 'warning');
      continue;
    }
    while($record = $result_uac->fetchObject()){

      // load full user
      if(!$user = user_load($record->uid)){
        drupal_set_message('user with uid '.$record->uid.' not found!', 'error');
        continue;
      }

      // we need this link later
      $user_path = $record->actual_profile == 1?'user/'.$record->uid:'profile/'.$record->uid.'/archive/'.$record->vid;
      $user_link = l(_pw_get_fullname($user), $user_path, array('attributes' => array('target' => '_blank')));

      // retrieve dialogue_id and comment count for before/after comparison
      $efq = new EntityFieldQuery();
      $efq->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'dialogue')
        ->fieldCondition('field_dialogue_recipient', 'target_id', $record->uid)
        ->fieldCondition('field_parliament', 'tid', $parliament->tid);

      // stats before
      $result_dialogues_before = $efq->execute();
      $dialogue_stats_before = pw_dialogues_admin_reimport_dialogue_stats($result_dialogues_before);

      // delete dialogues
      if($form['pw_dialogues_admin_reimport_delete_existing']['#value'] == 1 && !empty($result_dialogues_before['node'])) {
        node_delete_multiple(array_keys($result_dialogues_before['node']));
      }

      // download xml and import
      $url_import = $baseurl_modsystem.'?user_id='.$user->uuid.'&user_id_e=1&context='.$parliament->name;
      $headers = get_headers($url_import);
      if(!strpos($headers[0], '200 OK')){
        drupal_set_message(format_string('Got @code for @url.', array('@code' => $headers[0], '@url' => $url_import)), 'error');
        continue;
      }
      pw_dialogues_do_import_questions($url_import);
      pw_dialogues_do_import_answers($url_import);

      // stats after
      $result_dialogues_after= $efq->execute();
      $dialogue_stats_after = pw_dialogues_admin_reimport_dialogue_stats($result_dialogues_after);

      // dialogues which either still exists or otherwise has been deleted
      foreach($dialogue_stats_before as $dialogue_id => $dialogue_data) {
        $count_answers_before = $dialogue_data['count_answers'];

        // dialogue still exists
        if(array_key_exists($dialogue_id, $dialogue_stats_after)){
          $count_answers_after = $dialogue_stats_after[$dialogue_id]['count_answers'];
          $dialogue_nid = $dialogue_stats_after[$dialogue_id]['nid'];
          $node_link = l($dialogue_id, 'node/'.$dialogue_nid, array('attributes' => array('target' => '_blank')));
          $text_result_after_import = format_plural($count_answers_after, '@count Antwort', '@count Antworten', array('@count' => $count_answers_after));

          // flag as changed yes/no
          $changes = $count_answers_before != $count_answers_after;
        }

        // dialogue deleted
        else{
          $text_result_after_import = '-';
          $node_link = '-';
          $changes = TRUE;
        }

        $text_result_before_import = format_plural($count_answers_before, '@count Antwort', '@count Antworten', array('@count' => $count_answers));
        $rows[] = array(
          array('data' => $parliament->name),
          array('data' => $user_link),
          array('data' => $node_link),
          array('data' => $text_result_before_import.'/'.$text_result_after_import),
          array('data' => $changes?'YES':'-')
        );
      }

      // dialogues which are new after import
      $dialogues_new = array_diff_assoc($dialogue_stats_after, $dialogue_stats_before);
      foreach($dialogues_new as $dialogue_id => $dialogue_data) {
        $count_answers_after = $dialogue_data['count_answers'];
        $node_link = l($dialogue_id, 'node/'.$dialogue_data['nid'], array('attributes' => array('target' => '_blank')));
        $text_result_after_import = format_plural($count_answers_after, '@count Antwort', '@count Antworten', array('@count' => $count_answers));
        $rows[] = array(
          array('data' => $parliament->name),
          array('data' => $user_link),
          array('data' => $node_link),
          array('data' => '-/'.$text_result_after_import),
          array('data' => 'YES')
        );
      }
      $form_state['storage']['results'] = theme('table', array('header' => $header, 'rows' => $rows));
      $form_state['rebuild'] = TRUE;

      // rewrite user archive cache
      pw_userarchives_cron_ALT($record->uid);
    }
  }
}
function pw_dialogues_admin_reimport_dialogue_stats($result_dialogues){
  $dialogues_stats = array();
  if(!empty($result_dialogues['node'])) {
    $dialogue_nids = array_keys($result_dialogues['node']);
    if (!empty($dialogue_nids)) {
      $nodes_dialogue = node_load_multiple($dialogue_nids);
      foreach ($nodes_dialogue as $nid => $node) {
        $dialogue_id = field_get_items('node', $node, 'field_dialogue_id');
        $dialogues_stats[$dialogue_id[0]['value']] = array(
          'nid' => $nid,
          'count_answers' => $node->comment_count
        );
      }
    }
  }
  return $dialogues_stats;
}
