<?php
/**
 * @file
 * pw_partners.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_partners_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pw_partners_node_info() {
  $items = array(
    'partners' => array(
      'name' => t('Partners'),
      'base' => 'node_content',
      'description' => t('List of media partners'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
