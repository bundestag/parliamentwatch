<?php

/*
 * @file
 * pw_api.topics.inc
 */


/**
 *
 * @param object $vocabulary
 * The vocabulary object
 *
 * @return array
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
  return pw_api_meta_data_terms($terms, $vocabulary);
}
