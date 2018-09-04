<?php
/**
 * @file
 * pw_gdata_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function pw_gdata_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_importer-city-php';
  $feeds_tamper->importer = 'csv_importer';
  $feeds_tamper->source = 'city';
  $feeds_tamper->plugin_id = 'php';
  $feeds_tamper->settings = array(
    'php' => '$user_name = $item[\'system_username\'];
$user = user_load_by_name($user_name);
return $user->field_user_address[\'und\'][0][\'locality\'];',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Execute php code';
  $export['csv_importer-city-php'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_importer-country_default-default_value';
  $feeds_tamper->importer = 'csv_importer';
  $feeds_tamper->source = 'country_default';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'DE',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['csv_importer-country_default-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_importer-county-replace_county_code';
  $feeds_tamper->importer = 'csv_importer';
  $feeds_tamper->source = 'county';
  $feeds_tamper->plugin_id = 'replace_county_code';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Replace German county name to abbrev';
  $export['csv_importer-county-replace_county_code'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_importer-postal_code-php';
  $feeds_tamper->importer = 'csv_importer';
  $feeds_tamper->source = 'postal_code';
  $feeds_tamper->plugin_id = 'php';
  $feeds_tamper->settings = array(
    'php' => '$user_name = $item[\'system_username\'];
$user = user_load_by_name($user_name);
return $user->field_user_address[\'und\'][0][\'postal_code\'];',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Execute php code';
  $export['csv_importer-postal_code-php'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_committee_importer-xpathparser_14-explode';
  $feeds_tamper->importer = 'gdata_committee_importer';
  $feeds_tamper->source = 'xpathparser:14';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '", "',
    'limit' => '',
    'real_separator' => '", "',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['gdata_committee_importer-xpathparser_14-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_committee_importer-xpathparser_14-find_replace';
  $feeds_tamper->importer = 'gdata_committee_importer';
  $feeds_tamper->source = 'xpathparser:14';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '"',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['gdata_committee_importer-xpathparser_14-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_constituency_importer-xpathparser_6-explode';
  $feeds_tamper->importer = 'gdata_constituency_importer';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['gdata_constituency_importer-xpathparser_6-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_constituency_importer-xpathparser_6-find_replace_regex';
  $feeds_tamper->importer = 'gdata_constituency_importer';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/0([1-9][0-9]{3})/',
    'replace' => '$1',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_constituency_importer-xpathparser_6-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_constituency_importer-xpathparser_8-find_replace_regex';
  $feeds_tamper->importer = 'gdata_constituency_importer';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/([0-9]+)\\((.+)\\)/U',
    'replace' => '$1:$2',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_constituency_importer-xpathparser_8-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_constituency_importer-xpathparser_9-find_term_id_by_parliament';
  $feeds_tamper->importer = 'gdata_constituency_importer';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_term_id_by_parliament';
  $feeds_tamper->settings = array(
    'position_parliament' => '0',
    'target_vocabulary_id' => '39',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Find Electoral Region ID';
  $export['gdata_constituency_importer-xpathparser_9-find_term_id_by_parliament'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_elected_profiles-xpathparser_12-find_username_by_uuid';
  $feeds_tamper->importer = 'gdata_elected_profiles';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'find_username_by_uuid';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Finds username by UUID';
  $export['gdata_elected_profiles-xpathparser_12-find_username_by_uuid'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_external_links_importer-xpathparser_2-find_username_by_uuid';
  $feeds_tamper->importer = 'gdata_external_links_importer';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'find_username_by_uuid';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Finds username by UUID';
  $export['gdata_external_links_importer-xpathparser_2-find_username_by_uuid'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_external_links_importer-xpathparser_5-explode';
  $feeds_tamper->importer = 'gdata_external_links_importer';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Explode';
  $export['gdata_external_links_importer-xpathparser_5-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_external_links_importer-xpathparser_5-profiles_external_urls';
  $feeds_tamper->importer = 'gdata_external_links_importer';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'profiles_external_urls';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Imports external links';
  $export['gdata_external_links_importer-xpathparser_5-profiles_external_urls'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_lists_importer-xpathparser_2-find_term_id_by_parliament';
  $feeds_tamper->importer = 'gdata_lists_importer';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'find_term_id_by_parliament';
  $feeds_tamper->settings = array(
    'position_parliament' => '1',
    'target_vocabulary_id' => '39',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find Electoral Region ID';
  $export['gdata_lists_importer-xpathparser_2-find_term_id_by_parliament'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_parliaments_importer-xpathparser_1-required';
  $feeds_tamper->importer = 'gdata_parliaments_importer';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_parliaments_importer-xpathparser_1-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-blank_source_1-default_value';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'DE',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default country code';
  $export['gdata_profiles_importer_v2-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-blank_source_2-username_creator';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'username_creator';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Username Creator & Validator';
  $export['gdata_profiles_importer_v2-blank_source_2-username_creator'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_1-username_creator';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'username_creator';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Username Creator & Validator';
  $export['gdata_profiles_importer_v2-xpathparser_1-username_creator'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_14-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:14';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/^\\s*$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_importer_v2-xpathparser_14-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_16-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:16';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/^\\s*$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_importer_v2-xpathparser_16-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_19-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:19';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/^\\s*$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_importer_v2-xpathparser_19-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_2-set_default_email';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'set_default_email';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set Default E-Mail';
  $export['gdata_profiles_importer_v2-xpathparser_2-set_default_email'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_20-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:20';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/^\\s*$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_importer_v2-xpathparser_20-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_21-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:21';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/^\\s*$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_importer_v2-xpathparser_21-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_22-explode';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:22';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['gdata_profiles_importer_v2-xpathparser_22-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_24-required';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:24';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_profiles_importer_v2-xpathparser_24-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_25-required';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:25';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_profiles_importer_v2-xpathparser_25-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_26-find_term_id_by_parliament';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:26';
  $feeds_tamper->plugin_id = 'find_term_id_by_parliament';
  $feeds_tamper->settings = array(
    'position_parliament' => '25',
    'target_vocabulary_id' => '17',
  );
  $feeds_tamper->weight = 12;
  $feeds_tamper->description = 'Find Constituency Term ID';
  $export['gdata_profiles_importer_v2-xpathparser_26-find_term_id_by_parliament'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_27-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:27';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/^\\s*$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_importer_v2-xpathparser_27-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_3-check_uuid_name';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'check_uuid_name';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'UUID fits to first_name or last_name';
  $export['gdata_profiles_importer_v2-xpathparser_3-check_uuid_name'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_3-required';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_profiles_importer_v2-xpathparser_3-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_35-explode';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:35';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Explode';
  $export['gdata_profiles_importer_v2-xpathparser_35-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_35-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:35';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\s+/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Delete whitespaces';
  $export['gdata_profiles_importer_v2-xpathparser_35-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_36-find_term_id_by_parliament';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:36';
  $feeds_tamper->plugin_id = 'find_term_id_by_parliament';
  $feeds_tamper->settings = array(
    'position_parliament' => '25',
    'target_vocabulary_id' => '38',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find List Term ID';
  $export['gdata_profiles_importer_v2-xpathparser_36-find_term_id_by_parliament'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_37-set_fraction_to_party';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:37';
  $feeds_tamper->plugin_id = 'set_fraction_to_party';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set Fraction To Party If Empty';
  $export['gdata_profiles_importer_v2-xpathparser_37-set_fraction_to_party'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_4-explode';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Explode';
  $export['gdata_profiles_importer_v2-xpathparser_4-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_4-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\s+/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Delete whitespaces';
  $export['gdata_profiles_importer_v2-xpathparser_4-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_44-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:44';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/^\\s*$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_importer_v2-xpathparser_44-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_49-explode';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:49';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['gdata_profiles_importer_v2-xpathparser_49-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_49-rewrite';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:49';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[xpathparser:45]|[xpathparser:47]|[xpathparser:49]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['gdata_profiles_importer_v2-xpathparser_49-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_50-explode';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:50';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['gdata_profiles_importer_v2-xpathparser_50-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_50-rewrite';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:50';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[xpathparser:46]|[xpathparser:48]|[xpathparser:50]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['gdata_profiles_importer_v2-xpathparser_50-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_importer_v2-xpathparser_8-set_empty_birthday';
  $feeds_tamper->importer = 'gdata_profiles_importer_v2';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'set_empty_birthday';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Set Empty Birthday';
  $export['gdata_profiles_importer_v2-xpathparser_8-set_empty_birthday'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_updater-xpathparser_1-find_username_by_uuid';
  $feeds_tamper->importer = 'gdata_profiles_updater';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'find_username_by_uuid';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Finds username by his UUID';
  $export['gdata_profiles_updater-xpathparser_1-find_username_by_uuid'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_updater-xpathparser_5-explode';
  $feeds_tamper->importer = 'gdata_profiles_updater';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Explode';
  $export['gdata_profiles_updater-xpathparser_5-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_updater-xpathparser_5-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_updater';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\s+/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_updater-xpathparser_5-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_updater-xpathparser_6-explode';
  $feeds_tamper->importer = 'gdata_profiles_updater';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Explode';
  $export['gdata_profiles_updater-xpathparser_6-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_updater-xpathparser_6-find_replace_regex';
  $feeds_tamper->importer = 'gdata_profiles_updater';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\s+/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['gdata_profiles_updater-xpathparser_6-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_profiles_updater-xpathparser_7-set_default_email';
  $feeds_tamper->importer = 'gdata_profiles_updater';
  $feeds_tamper->source = 'xpathparser:7';
  $feeds_tamper->plugin_id = 'set_default_email';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set Default E-Mail';
  $export['gdata_profiles_updater-xpathparser_7-set_default_email'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_subject_importer-xpathparser_3-add_parliament';
  $feeds_tamper->importer = 'gdata_subject_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'add_parliament';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Add term to existing parliament terms on update';
  $export['gdata_subject_importer-xpathparser_3-add_parliament'] = $feeds_tamper;

  return $export;
}
