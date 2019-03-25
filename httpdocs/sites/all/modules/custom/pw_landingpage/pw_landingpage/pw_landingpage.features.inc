<?php
/**
 * @file
 * pw_landingpage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_landingpage_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pw_landingpage_node_info() {
  $items = array(
    'landingpage' => array(
      'name' => t('Landingpage'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function pw_landingpage_paragraphs_info() {
  $items = array(
    'landingpage_contributor' => array(
      'name' => 'Person',
      'bundle' => 'landingpage_contributor',
      'locked' => '1',
    ),
    'landingpage_contributor_group' => array(
      'name' => 'Personen-Gruppe',
      'bundle' => 'landingpage_contributor_group',
      'locked' => '1',
    ),
    'landingpage_headline' => array(
      'name' => 'Überschrift',
      'bundle' => 'landingpage_headline',
      'locked' => '1',
    ),
    'landingpage_text' => array(
      'name' => 'Text',
      'bundle' => 'landingpage_text',
      'locked' => '1',
    ),
  );
  return $items;
}
