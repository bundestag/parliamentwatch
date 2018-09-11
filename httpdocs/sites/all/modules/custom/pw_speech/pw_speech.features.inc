<?php
/**
 * @file
 * pw_speech.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_speech_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pw_speech_node_info() {
  $items = array(
    'speech' => array(
      'name' => t('Speech'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
