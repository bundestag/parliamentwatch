<?php
/**
 * @file
 * pw_newsletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_newsletter_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pw_newsletter_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function pw_newsletter_node_info() {
  $items = array(
    'newsletter' => array(
      'name' => t('Newsletter'),
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
function pw_newsletter_paragraphs_info() {
  $items = array(
    'paragraphs_pw_blog' => array(
      'name' => 'Blog Artikel',
      'bundle' => 'paragraphs_pw_blog',
      'locked' => '1',
    ),
    'paragraphs_pw_content' => array(
      'name' => 'Textabschnitt',
      'bundle' => 'paragraphs_pw_content',
      'locked' => '1',
    ),
    'paragraphs_pw_donate' => array(
      'name' => 'Spendenaufruf',
      'bundle' => 'paragraphs_pw_donate',
      'locked' => '1',
    ),
    'paragraphs_pw_list' => array(
      'name' => 'Liste',
      'bundle' => 'paragraphs_pw_list',
      'locked' => '1',
    ),
    'paragraphs_pw_testmonial' => array(
      'name' => 'Fördermitglied Störer',
      'bundle' => 'paragraphs_pw_testmonial',
      'locked' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function pw_newsletter_weight_features_default_settings() {
  $settings = array();

  $settings['newsletter'] = array(
    'enabled' => '0',
    'range' => '20',
    'menu_weight' => '0',
    'default' => '0',
    'sync_translations' => '0',
  );

  return $settings;
}
