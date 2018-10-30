<?php

/*
 * @file
 * pw_api.votes.inc
 */


/**
 *
 * @param $parliament
 *    Can be parliament name or term uuid.
 * @return array $votes
 *   All votes to petitions as array.
 */

function pw_api_petitions($parliament) {

  $petitions = array();

  // translate uuid into parliament name
  if(preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $parliament, $uuid)){
    $parliament_term = array_pop(entity_uuid_load('taxonomy_term', $uuid));
  }
  else{
    $parliament_term = array_pop(taxonomy_get_term_by_name($parliament, 'parliaments'));
  }

   // query for all nodes of type petition
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'pw_petition')
  ->fieldCondition('field_parliament', 'tid', $parliament_term->tid)
  ->propertyCondition('status', NODE_PUBLISHED)
  ->propertyOrderBy('created', 'DESC');
  $result_nodes = $query->execute();

  if(isset($result_nodes['node'])){

    foreach(array_keys($result_nodes['node']) as $target_node_id){

      $node = node_load($target_node_id);
      $petitions['petition_'.$target_node_id] = array();
      $petitions['petition_'.$target_node_id]['title'] = $node->title;
      $petitions['petition_'.$target_node_id]['uuid'] = $node->uuid;
      $date_field = field_get_items('node', $node, 'field_petition_end_date');
      $petition_date = $date_field?substr($date_field[0]['value'], 0, 10):'';
      $petitions['petition_'.$target_node_id]['date'] = $petition_date;
      $status = field_get_items('node', $node, 'field_petition_status');
      $petitions['petition_'.$target_node_id]['status'] = $status[0]['value'];
      $petitions['petition_'.$target_node_id]['url'] = url('node/'.$node->nid, array('absolute' => TRUE));
      if($status[0]['value'] == 'passed_parliament'){

        // add voting behaviour
        $votes = pw_api_add_votes($parliament_term, $target_node_id, $petition_date);
        $stats = array();
        foreach($votes as $vote){
          $key = $vote['vote'];
          $stats[$key] = key_exists($key, $stats)?$stats[$key]+1:1;
        }
        ksort($stats);
        $petitions['petition_'.$target_node_id]['stats'] = $stats;
        $petitions['petition_'.$target_node_id]['votes'] = $votes;
      }
      else{
        $petitions['petition_'.$target_node_id]['votes'] = '';
      }
    }
  }

  return array('petitions' => $petitions);
}

/**
 *
 * @param $parliament
 *    Can be parliament name or term uuid.
 * @return array $votes
 *   All votes to polls as array.
 */

function pw_api_polls($parliament) {

  $polls = array();

    // translate uuid into parliament name
  if(preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $parliament, $uuid)){
    $parliament_term = array_pop(entity_uuid_load('taxonomy_term', $uuid));
  }
  else{
    $parliament_term = array_pop(taxonomy_get_term_by_name($parliament, 'parliaments'));
  }

  $parameters = drupal_get_query_parameters();
  $subsets = isset($parameters['subsets'])?[$parameters['subsets']]:[];

  // query for all nodes of type poll
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'poll')
  ->fieldCondition('field_parliament', 'tid', $parliament_term->tid)
  ->propertyCondition('status', NODE_PUBLISHED)
  ->propertyOrderBy('created', 'DESC');
  $result_nodes = $query->execute();

  if(isset($result_nodes['node'])){
    foreach(array_keys($result_nodes['node']) as $target_node_id){
      $poll = pw_api_poll($parliament_term, $target_node_id, $subsets);
      $polls['poll_'.$target_node_id] = $poll['poll'];
    }
  }

  $subsets = ['votes'];

  // add meta data and return
  return pw_api_meta_data($polls, 'polls', $subsets);
}


/**
 *
 * @param $parliament
 *    Can be parliament name, term uuid or term object.
 * @param $poll
 *    Can be name, nid or node uuid
 * @return array $poll
 *   All data of a single poll with stats and votes.
 */

function pw_api_poll($parliament, $poll, $subsets = ['votes']) {

  // translate uuid into parliament name
  if (is_object($parliament)) {
    $parliament_term = $parliament;
  }
  elseif (preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $parliament, $uuid)){
    $parliament_term = array_pop(entity_uuid_load('taxonomy_term', $uuid));
  }
  else {
    $parliament_term = array_pop(taxonomy_get_term_by_name($parliament, 'parliaments'));
  }

  // translate uuid into poll
  if (preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $poll, $uuid)) {
    $nid = entity_get_id_by_uuid('node', [$uuid]);
    $node = node_load(array_pop($nid));
  }
  elseif (is_numeric($poll)) {
    $node = node_load($poll);
  }
  else {

     // query for polls by poll name and parliament
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'poll')
    ->fieldCondition('field_parliament', 'tid', $parliament_term->tid)
    ->propertyCondition('title', $poll)
    ->propertyCondition('status', NODE_PUBLISHED);
    $result = $query->execute();
    if ($result['node']) {
      $node = node_load(key($result['node']));
    }
  }

  $vocabulary = taxonomy_vocabulary_machine_name_load('topics');
  $terms_topics = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));

  $poll = array();

  $poll['meta'] = array();
  $poll['meta']['uuid'] = $node->uuid;
  $poll['meta']['edited'] = date('Y-m-d H:i', $node->changed);
  $topics = field_get_items('node', $node, 'field_topics');
  $poll['meta']['topics'] = array();
  foreach ($topics as $topic) {
    $poll['meta']['topics']['topic_'.$topic['tid']] = $terms_topics[$topic['tid']]->name;
  }
  $poll['meta']['url'] = url('node/' . $node->nid, array('absolute' => TRUE));

  // add sub datasets
  $pathinfo = pathinfo(current_path());
  if ($pathinfo['filename'] == 'polls') {
    $dataset_types = ['poll'];
    $path_types_parliaments = ['name' => strtolower($parliament_term->name), 'uuid' => $parliament_term->uuid];
    $path_types = ['name' => strtolower($node->title), 'uuid' => $node->uuid];
    $poll['meta']['datasets'] = pw_api_urls_datasets($dataset_types, $path_types, $path_types_parliaments);
  }
  else {
    $dataset_types = ['polls'];
    $path_types = ['name' => strtolower($parliament_term->name), 'uuid' => $parliament_term->uuid];
    $poll['meta']['datasets'] = pw_api_urls_datasets($dataset_types, $path_types);
  }

  $poll['title'] = $node->title;
  $date_field = field_get_items('node', $node, 'field_poll_date');
  $poll_date = substr($date_field[0]['value'], 0, 10);
  $poll['date'] = $poll_date;
  $body = field_get_items('node', $node, 'body');
  $poll['summary'] = trim(strip_tags($body[0]['summary']));
  $status = field_get_items('node', $node, 'field_voted');
  if($status[0]['value'] == '1'){
    $poll['status'] = t('voted');

    // add voting behaviour
    $votes = pw_api_add_votes($parliament_term, $node->nid, $poll_date);
    $stats = ['total' => []];
    foreach($votes as $vote){
      $key_vote = $vote['vote'];
      $key_fraction = $vote['party'];
      if (!key_exists($key_vote, $stats['total'])) {
        $stats['total'][$key_vote] = 1;
      }
      else {
        $stats['total'][$key_vote]++;
      }
      if (!key_exists($key_fraction, $stats)) {
        $stats[$key_fraction] = [$key_vote => 1];
      }
      else {
        $stats[$key_fraction][$key_vote]++;
      }
    }
    #ksort($stats);
    $poll['stats'] = $stats;
    if (in_array('votes', $subsets)) {
      $poll['votes'] = $votes;
    }
  }
  else{
    $poll['status'] = $poll_date > date('Y-m-d')?t('pending'):t('unknown');
  }

  return array('poll' => $poll);
}


/**
 *
 * @param object $parliament_term
 *    Parliament as term.
 * @param int $target_node_id
 *    Id of node on which was voted.
 * @param date $vote_date
 *    Important to query for right user revisions.
 * @return array $poll
 *   All data of a single poll with stats and votes.
 */

function pw_api_add_votes($parliament_term, $target_node_id, $vote_date){

  // return array
  $votes = array();

  // query for all votes on target node
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'vote')
  ->fieldCondition('field_parliament', 'tid', $parliament_term->tid)
  ->fieldCondition('field_vote_node', 'target_id', $target_node_id)
  ->propertyCondition('status', NODE_PUBLISHED)
  ->propertyOrderBy('created', 'DESC');
  $result_votes = $query->execute();

  if(isset($result_votes['node'])){

    $query = db_select('node', 'n');
    $query->condition('n.nid', array_keys($result_votes['node']));

    // join taxonomy terms to retrieve voting behaviour
    $query->join('field_data_field_vote', 'vote', "n.nid = vote.entity_id AND vote.bundle = 'vote'");
    $query->join('taxonomy_term_data', 'vote_term', "vote.field_vote_tid = vote_term.tid");
    $query->join('field_data_field_votes_label', 'vote_label', "vote_term.tid = vote_label.entity_id AND vote_label.entity_type = 'taxonomy_term'");
    $query->addField('vote_label', 'field_votes_label_value', 'vote_label');

    // join target user to retrieve user data
    $query->join('field_data_field_vote_user', 'vote_user', "n.nid = vote_user.entity_id AND vote_user.bundle = 'vote'");
    $query->join('user_archive_cache', 'uac', "vote_user.field_vote_user_target_id = uac.uid");
    $query->addField('uac', 'vid');
    $query->addField('uac', 'fraction_name', 'fraction');
    _pw_uac_add_conditions($query, array(
      'parliament' => $parliament_term->name,
      'roles' => 'deputy',
      'date' => $vote_date,
      )
    );

    //$query->groupBy('uac.uid');

    // join users to retrieve uuid
    $query->join('users', 'u', "vote_user.field_vote_user_target_id = u.uid");
    $query->addField('u', 'uuid');

    // join to retrieve first name
    $query->join('field_revision_field_user_fname', 'u_fname', "uac.vid = u_fname.revision_id");
    $query->addField('u_fname', 'field_user_fname_value', 'first_name');

    // join to retrieve last name
    $query->join('field_revision_field_user_lname', 'u_lname', "uac.vid = u_lname.revision_id");
    $query->addField('u_lname', 'field_user_lname_value', 'last_name');

    // join to retrieve title name
    $query->leftJoin('field_revision_field_user_prefix', 'u_degree', "uac.vid = u_degree.revision_id");
    $query->addField('u_degree', 'field_user_prefix_value', 'degree');

    // join to retrieve party
    $query->join('field_revision_field_user_party', 'u_party', "uac.vid = u_party.revision_id");
    $query->join('taxonomy_term_data', 'party_term', "u_party.field_user_party_tid = party_term.tid");
    $query->addField('party_term', 'name', 'party');

    // join to retrieve constituency
    $query->leftJoin('field_revision_field_user_constituency', 'u_constituency', "uac.vid = u_constituency.revision_id");
    $query->leftJoin('taxonomy_term_data', 'constituency_term', "u_constituency.field_user_constituency_tid = constituency_term.tid");
    $query->addField('constituency_term', 'name', 'constituency');

    // join to retrieve list
    $query->leftJoin('field_revision_field_user_list', 'u_list', "uac.vid = u_list.revision_id");
    $query->leftJoin('taxonomy_term_data', 'list_term', "u_list.field_user_list_tid = list_term.tid");
    $query->addField('list_term', 'name', 'list');

    // sort
    $query->orderBy('party');
    $query->orderBy('vote_label');
    $query->orderBy('u_lname.field_user_lname_value');
    $query->orderBy('u_fname.field_user_fname_value');

    // get results
    $result = $query->execute();

    // fetch and write results
    while($record = $result->fetchObject()){
      $vote = array();
      $vote['fullname'] = trim($record->degree.' '.$record->first_name.' '.$record->last_name);
      $vote['uuid'] = $record->uuid;
      $vote['party'] = $record->party;
      $vote['fraction'] = $record->fraction;
      $vote['constituency'] = $record->constituency;
      $vote['list'] = $record->list;
      $vote['vote'] = $record->vote_label;
      $votes['deputy_'.$record->vid] = $vote;
    }
  }

  return $votes;
}
