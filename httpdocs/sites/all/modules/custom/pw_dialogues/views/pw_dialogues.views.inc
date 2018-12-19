<?php

/**
 * @file
 * Views integration for dialogues
 */

/**
 * Implements hook_views_data().
 */
function pw_dialogues_views_data() {
  // comment_count
  $data['node_comment_statistics']['has_comment'] = array(
    'title' => t('Has comment'),
    'real field' => 'comment_count',
    'help' => t('Filter to see if entity has comments.'),
    'filter' => array(
      'handler' => 'views_handler_filter_has_comments',
    ),
  );

  return $data;
}