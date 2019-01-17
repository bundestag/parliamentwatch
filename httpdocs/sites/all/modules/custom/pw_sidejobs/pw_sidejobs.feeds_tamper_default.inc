<?php
/**
 * @file
 * pw_sidejobs.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function pw_sidejobs_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_sidejobs_importer-blank_source_1-default_value';
  $feeds_tamper->importer = 'gdata_sidejobs_importer';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'DE',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['gdata_sidejobs_importer-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_sidejobs_importer-blank_source_2-default_value';
  $feeds_tamper->importer = 'gdata_sidejobs_importer';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'DE',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['gdata_sidejobs_importer-blank_source_2-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_sidejobs_importer-xpathparser_14-explode';
  $feeds_tamper->importer = 'gdata_sidejobs_importer';
  $feeds_tamper->source = 'xpathparser:14';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['gdata_sidejobs_importer-xpathparser_14-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_sidejobs_importer-xpathparser_2-find_replace';
  $feeds_tamper->importer = 'gdata_sidejobs_importer';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'â€œ',
    'replace' => '"',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Replace â€œ';
  $export['gdata_sidejobs_importer-xpathparser_2-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_sidejobs_importer-xpathparser_3-find_replace';
  $feeds_tamper->importer = 'gdata_sidejobs_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'â€œ',
    'replace' => '"',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Replace â€œ';
  $export['gdata_sidejobs_importer-xpathparser_3-find_replace'] = $feeds_tamper;

  return $export;
}
