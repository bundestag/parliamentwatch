<?php

/*
 * @file
 * pw_api.topics.inc
 */



/**
 *
 * @return array $topics
 *   Returns all topics.
 */

function pw_api_terms($vocabulary) {

  $terms = [];

  // load topics
  $terms_topics = entity_load('taxonomy_term', FALSE, ['vid' => $vocabulary->vid]);
  foreach ($terms_topics as $tid => $term) {
    $terms[$tid] = $term->name;
  }

  asort($terms);

  // add meta data and return
  return pw_api_meta_data($terms, $vocabulary->machine_name);
}
