<?php

/*
 * @file
 * pw_api.profile.inc
 */


/**
 * Page callback; returns single profile based on given filters.
 *
 * Sets a custom cache ttl.
 *
 * @param
 *
 * @return array
 *   The profile as an associative array
 */

function pw_api_profile($username, $parliament=FALSE) {

  // translate uuid into user and username
  if(preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $username, $uuid)){
    $user_entity = entity_uuid_load('user', $uuid);
    $user_entity = array_pop($user_entity);
    $username = $user_entity->name;
  }

  // filter by parliament
  if($parliament){

    // translate uuid into parliament name
    if(preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $parliament, $uuid)){
      $parliament_term = entity_uuid_load('taxonomy_term', $uuid);
      $parliament = array_pop($parliament_term)->name;
    }

    // load user revision
    $query = db_select('user_archive_cache', 'uac');
    $query->fields('uac', array('uid', 'vid'));
    _pw_uac_add_conditions($query, array(
        'parliament' => $parliament,
        'username' => $username
        )
    );
    $query->orderBy("uac.vid", 'DESC');
    $result = $query->execute()->fetchAssoc();
    $user = user_revision_load($result['uid'], $result['vid']);
  }

  // select user by name
  else{
    $user = user_load_by_name($username);
  }

  if(!$user){
    return MENU_NOT_FOUND;
  }

  $profile = array('profile' => pw_api_user_to_array($user, array('votes', 'dialogues', 'sidejobs')));

  return $profile;
}


/**
 * Return multiple profiles. The page callback is used for the following paths:
 *  - api/parliament/[PARLIAMENT]/deputies.json
 *  - api/parliament/[PARLIAMENT]/deputies.xml
 *  - api/parliament/[PARLIAMENT]/candidates.json
 *  - api/parliament/[PARLIAMENT]/candidates.xml
 *  - api/parliament/[PARLIAMENT]/profiles.json
 *  - api/parliament/[PARLIAMENT]/profiles.xml
 *
 * @param $parliament
 * @param $file_type
 *
 * @return array
 */
function pw_api_multiple_profiles($parliament, $file_type) {

  // translate uuid into parliament name
  if(preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $parliament, $uuid)){
    $parliament_terms = entity_uuid_load('taxonomy_term', $uuid);
    $parliament = reset($parliament_terms)->name;
  }
  else{
    $parliament_terms = taxonomy_get_term_by_name($parliament, 'parliaments');
  }

  // query for users
  $pathinfo = pathinfo(current_path());
  $query = db_select('user_archive_cache', 'uac');
  $query->fields('uac', array('uid', 'vid'));

  switch ($pathinfo['filename'] ) {
    case 'deputies':
      _pw_uac_add_conditions($query, array('parliament' => $parliament, 'roles' => 'deputy'));
      $query->addExpression('MAX(vid)', 'max_vid');
      $query->groupBy('uac.uid');
      break;

    case 'candidates':
      _pw_uac_add_conditions($query, array('parliament' => $parliament, 'roles' => 'candidate'));
      $query->addExpression('MAX(vid)', 'max_vid');
      $query->groupBy('uac.uid');
      break;

      // it should only be "profiles" as s filename possible
    default:
      _pw_uac_add_conditions($query, array('parliament' => $parliament,));
      $query->addExpression('MAX(vid)', 'max_vid');
      $query->groupBy('uac.uid');
      break;
  }


  $result = $query->execute()->fetchCol(1);
  $parameters = drupal_get_query_parameters();
  $subsets = isset($parameters['subsets'])?array($parameters['subsets']):array();

  $profiles = array();
  foreach (pw_userarchives_politician_load_multiple($result) as $user) {
    $profiles['profile_'.$user->uid] = pw_api_user_to_array($user, $subsets);
  }

  $contributer = [];
  $field_contributer = field_get_items('taxonomy_term', reset($parliament_terms), 'field_contributer');
  $i = 0;
  foreach ($field_contributer as $field_value) {
    $contributer[] = $field_value['value'];
  }

  $subsets = ['votes', 'dialogues', 'sidejobs'];

  // add meta data and return
  return pw_api_meta_data($profiles, 'profiles', $subsets, $contributer);
}

function pw_api_user_to_array($user, $subsets = array()) {

  $profile = array();

  try{

    // wrap user
    $w_user = entity_metadata_wrapper('user', $user);

    // allowed target content types
    $field_info = field_info_field('field_vote_node');
    $types_allowed = array_keys($field_info['settings']['handler_settings']['target_bundles']);

    // fill user data into array
    $profile['meta'] = array();
    $profile['meta']['status'] = $w_user->status->value();
    $profile['meta']['edited'] = date('Y-m-d H:i', $user->revision_timestamp);
    $profile['meta']['uuid'] = $w_user->uuid->value();
    $profile['meta']['username'] = $w_user->name->value();

    // fetch stats into meta
    $query = db_select('user_archive_cache', 'uac');
    $query->fields('uac', array('number_of_questions', 'number_of_answers', 'number_of_standard_replies', 'actual_profile'));
    _pw_uac_add_conditions($query, array(
        'vid' => $user->vid,
      )
    );
    $result = $query->execute()->fetchAssoc();
    $profile['meta']['questions'] = (int) $result['number_of_questions'];
    $profile['meta']['answers'] = (int) $result['number_of_answers'];
    $profile['meta']['standard_replies'] = (int) $result['number_of_standard_replies'];

    // publish roles for authorized users
    if(user_access('access authorized api')){
      $roles = array();
      foreach($w_user->field_user_roles_for_view_mode_s as $role){
        $roles[] = $role->value()->name;
      }
      $profile['meta']['roles'] = $roles;
    }
    if ($result['actual_profile'] == 0) {
          $path = 'profile/' . $user->name . '/archive/' . $user->vid;
      }
    else {
        $path = 'user/' . $user->uid;
    }
    $profile['meta']['url'] = url($path, array('absolute' => TRUE));

    $profile['personal'] = array();
    $profile['personal']['degree'] = $w_user->field_user_prefix->value();
    $profile['personal']['first_name'] = $w_user->field_user_fname->value();
    $profile['personal']['last_name'] = $w_user->field_user_lname->value();
    $profile['personal']['gender'] = $w_user->field_user_gender->value();
    $profile['personal']['birthyear'] = !empty($w_user->field_user_birthday->value())?date('Y', $w_user->field_user_birthday->value()):null;
    $profile['personal']['education'] = $w_user->field_user_education->value();
    $profile['personal']['profession'] = $w_user->field_user_job_skills->value();

    // publish private email for authorized users
    if(user_access('access authorized api')){
      $profile['personal']['email'] = $w_user->mail->value();
      $profile['personal']['email2'] = $w_user->field_user_public_mail->value();
      $profile['personal']['phone'] = $w_user->field_user_phone->value();
      $profile['personal']['mobile'] = $w_user->field_user_mobile->value();
      // load kc theses
      $kc_theses = pw_kandidatencheck_by_user_revision_query($user)->execute();
      if (isset($kc_theses['node'])){
        $profile['meta']['candidate_match_theses'] = sizeof($kc_theses['node']);
      }
      else {
        $profile['meta']['candidate_match_theses'] = 0;
      }
    }

    $profile['party'] = $w_user->field_user_party->label();

    // add location
    $profile['personal']['location'] = array();
    $profile['personal']['location']['country'] = $w_user->field_user_address->country->value();
    $profile['personal']['location']['state'] = $w_user->field_user_address->administrative_area->value();
    $profile['personal']['location']['city'] = $w_user->field_user_address->locality->value();
    $profile['personal']['location']['postal_code'] = $w_user->field_user_address->postal_code->value();

    // add picture
    $profile['personal']['picture'] = array();
    if($w_user->field_user_picture->value()){
      $profile['personal']['picture']['url'] = file_create_url($w_user->field_user_picture->file->value()->uri);
      if($w_user->field_user_picture->file->field_image_copyright->value()){
        $profile['personal']['picture']['copyright'] = $w_user->field_user_picture->file->field_image_copyright->value->value();
      }
      else{
        $profile['personal']['picture']['copyright'] = '';
      }
    }
    else{
      $portrait_info = field_info_field('field_user_picture');
      $file = file_load($portrait_info['settings']['default_image']);
      $profile['personal']['picture']['url'] = file_create_url($file->uri);
      $profile['personal']['picture']['copyright'] = '';
    }

    // add parliament
    $profile['parliament'] = array();
    $profile['parliament']['name'] = $w_user->field_user_parliament->label();
    $profile['parliament']['uuid'] = $w_user->field_user_parliament->uuid->value();
    if ($w_user->field_user_joined->value()) {
      $profile['parliament']['joined'] = format_date($w_user->field_user_joined->value(), 'custom', 'Y-m-d');
    }
    if ($w_user->field_user_retired->value()) {
      $profile['parliament']['retired'] = format_date($w_user->field_user_retired->value(), 'custom', 'Y-m-d');
    }

    // add political roles
    $profile['roles'] = array();
    foreach ($w_user->field_user_political_roles->value() as $role) {
      $profile['roles']['role_'.$role->tid] = $role->name;
    }

    // add constituency
    $profile['constituency'] = array();
    if(sizeof($w_user->field_user_constituency) > 0){
      $profile['constituency']['name'] = $w_user->field_user_constituency[0]->label();
      $profile['constituency']['uuid'] = $w_user->field_user_constituency[0]->uuid->value();
      $profile['constituency']['number'] = $w_user->field_user_constituency[0]->field_constituency_nr->value();
      $profile['constituency']['result'] = $w_user->field_user_election_result->value();
      $profile['constituency']['won'] = $w_user->field_user_constituency_won->value();
    }

    // add list
    $profile['list'] = array();
    if($w_user->field_user_list->getIdentifier()){
      $profile['list']['name'] = $w_user->field_user_list->label();
      $profile['list']['uuid'] = $w_user->field_user_list->uuid->value();
      $profile['list']['position'] = $w_user->field_user_list_position->label();
      $profile['list']['won'] = $w_user->field_user_list_won->value();
    }

    // add committees
    $profile['committees'] = array();
    foreach (pw_committees_get_memberships($user) as $role => $memberships) {
      foreach ($memberships as $membership) {
        $profile['committees']['committee_'.$membership->nid]['uuid'] = $membership->uuid;
        $profile['committees']['committee_'.$membership->nid]['name'] = $membership->title;
        $profile['committees']['committee_'.$membership->nid]['role'] = $role;
      }
    }

    // add sidejobs
    if(in_array('sidejobs', $subsets)){
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'sidejob')
        ->fieldCondition('field_parliament', 'tid', $w_user->field_user_parliament->tid->value())
        ->fieldCondition('field_politician', 'target_id', $w_user->uid->value())
        ->propertyCondition('status', NODE_PUBLISHED);
      $result = $query->execute();

      $profile['sidejobs'] = array();
      if(isset($result['node'])){

        $nodes = node_load_multiple(array_keys($result['node']));
        $interval_mapping = array(0 => 'once', 1 => 'monthly', 12 => 'yearly');

        foreach ($nodes as $node) {
          $w_sidejob = entity_metadata_wrapper('node', $node);
          $profile['sidejobs']['sidejob_'.$node->nid] = array();
          $profile['sidejobs']['sidejob_'.$node->nid]['meta']['uuid'] = $node->uuid;
          $profile['sidejobs']['sidejob_'.$node->nid]['meta']['topics'] = array();
          foreach ($w_sidejob->field_topics->value() as $topic) {
            $profile['sidejobs']['sidejob_'.$node->nid]['meta']['topics']['topic_'.$topic->tid] = $topic->name;
          }
          $profile['sidejobs']['sidejob_'.$node->nid]['organization'] = $w_sidejob->field_sidejob_organization->label();
          $profile['sidejobs']['sidejob_'.$node->nid]['job'] = $w_sidejob->field_job->label();
          $profile['sidejobs']['sidejob_'.$node->nid]['job_category'] = $w_sidejob->field_sidejob_job_category->label();

          $computed_income = pw_sidejobs_income_range($node);
          if (!empty($computed_income)) {
            $profile['sidejobs']['sidejob_' . $node->nid]['income']['total_min'] = $computed_income[0];
            $profile['sidejobs']['sidejob_' . $node->nid]['income']['total_max'] = $computed_income[1];
          }

          if ($w_sidejob->field_sidejob_classification->value()) {
            $date_range = pw_sidejobs_date($node);
            if (count($date_range) == 2) {
              $profile['sidejobs']['sidejob_' . $node->nid]['income']['date']['start'] = $date_range[0]->format('Y-m-d');
              $profile['sidejobs']['sidejob_' . $node->nid]['income']['date']['end'] = $date_range[1]->format('Y-m-d');
            }
            else {
              $profile['sidejobs']['sidejob_' . $node->nid]['income']['date'] = $date_range[0]->format('Y-m-d');
            }
            $profile['sidejobs']['sidejob_' . $node->nid]['income']['classification'] = $w_sidejob->field_sidejob_classification->value();
            if (!empty($w_sidejob->field_sidejob_income_interval->value())) {
              $profile['sidejobs']['sidejob_' . $node->nid]['income']['interval'] = t($interval_mapping[$w_sidejob->field_sidejob_income_interval->value()]);
            } else {
              $profile['sidejobs']['sidejob_' . $node->nid]['income']['interval'] = t('once');
            }
          }
        }
      }
    }

    // add votes
    if(in_array('votes', $subsets)){
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'vote')
        ->fieldCondition('field_parliament', 'tid', $w_user->field_user_parliament->tid->value())
        ->fieldCondition('field_vote_user', 'target_id', $w_user->uid->value())
        ->propertyCondition('status', NODE_PUBLISHED)
        ->propertyOrderBy('created', 'DESC');
      $result = $query->execute();


      $profile['votes'] = array();
      if(isset($result['node'])){

        $query = db_select('node', 'n');

        // join taxonomy terms to retrieve voting behaviour
        $query->join('field_data_field_vote', 'vote', "n.nid = vote.entity_id AND vote.bundle = 'vote'");
        $query->join('taxonomy_term_data', 'vote_term', "vote.field_vote_tid = vote_term.tid");
        $query->join('field_data_field_votes_label', 'vote_label', "vote_term.tid = vote_label.entity_id AND vote_label.entity_type = 'taxonomy_term'");
        $query->addField('vote_label', 'field_votes_label_value', 'vote_label');

        // join target petition or poll to retrieve title, uuid and created date
        $query->join('field_data_field_vote_node', 'vote_node', "n.nid = vote_node.entity_id AND vote_node.bundle = 'vote'");
        $query->join('node', 'target_node', "vote_node.field_vote_node_target_id = target_node.nid");
        $query->fields('target_node', array('title', 'uuid', 'created', 'nid', 'type'));

        // load only vote of current user
        $query->condition('n.nid', array_keys($result['node']));

        // get results
        $result = $query->execute();

        // fetch and write results
        while($record = $result->fetchObject()){
          if(in_array($record->type, $types_allowed)){
            $type = str_replace('pw_', '', $record->type);
            $profile['votes'][$type.'_'.$record->nid]['uuid'] = $record->uuid;
            $profile['votes'][$type.'_'.$record->nid]['title'] = $record->title;
            $profile['votes'][$type.'_'.$record->nid]['date'] = date("Y-m-d", $record->created);
            $profile['votes'][$type.'_'.$record->nid]['vote'] = $record->vote_label;
            $profile['votes'][$type.'_'.$record->nid]['url'] = url('node/'.$record->nid, array('absolute' => TRUE));
          }
        }
      }
    }

    // add data from user_archive_cache meta table
    if(in_array('dialogues', $subsets)){
      $result = db_query("SELECT number_of_questions, number_of_answers FROM user_archive_cache WHERE vid = :vid", array(':vid' => $w_user->vid->value()))->fetchAssoc();
      $profile['questions'] = array();

      // add dialogues
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'dialogue')
        ->fieldCondition('field_parliament', 'tid', $w_user->field_user_parliament->tid->value())
        ->fieldCondition('field_dialogue_recipient', 'target_id', $w_user->uid->value())
        ->propertyCondition('status', NODE_PUBLISHED)
        ->propertyOrderBy('created', 'DESC');
      $result = $query->execute();

      if(isset($result['node'])){
        $dialogues = node_load_multiple(array_keys($result['node']), array(), TRUE);
        foreach ($dialogues as $nid => $dialogue) {

          // wrap dialogue
          $w_dialogue = entity_metadata_wrapper('node', $dialogue);

          $profile['questions']['question_'.$nid] = array();
          $profile['questions']['question_'.$nid]['id'] = $w_dialogue->field_dialogue_id->value();
          $profile['questions']['question_'.$nid]['date'] = date("Y-m-d", $w_dialogue->created->value());
          $profile['questions']['question_'.$nid]['category'] = $w_dialogue->field_dialogue_topic->label();
          $profile['questions']['question_'.$nid]['url'] = url('node/'.$nid, array('absolute' => TRUE));

          // add answers
          $profile['questions']['question_'.$nid]['answers'] = array();
          foreach ($w_dialogue->comments as $key => $answer) {
            $profile['questions']['question_'.$nid]['answers']['answer_'.$key] = array();
            $profile['questions']['question_'.$nid]['answers']['answer_'.$key]['date'] = date("Y-m-d", $answer->created->value());
            $profile['questions']['question_'.$nid]['answers']['answer_'.$key]['summary'] = $answer->field_dialogue_comment_body->summary->value();
          }
        }
      }
    }
  }
  catch (EntityMetadataWrapperException $exc) {
    watchdog('pw_api',  'See '  . __FUNCTION__ . '() <pre>' .  $exc->getTraceAsString() . '</pre>', NULL, WATCHDOG_ERROR);
    $profile['error'] = 'See '  . __FUNCTION__ . '() ' .  $exc->getTraceAsString();
  }

  return $profile;
}
