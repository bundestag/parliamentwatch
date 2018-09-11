<?php
/**
 * @file
 * pw_speech.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pw_speech_taxonomy_default_vocabularies() {
  return array(
    'speech_top' => array(
      'name' => 'Speech Top',
      'machine_name' => 'speech_top',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
