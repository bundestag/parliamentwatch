<?php
/**
 * @file
 * pw_gdata_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function pw_gdata_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_bavarian_streets_importer';
  $feeds_importer->config = array(
    'name' => 'Bavarian streets importer',
    'description' => 'Importiert Adressen für die Stimmkreise in München und Nürnberg',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'parliament',
          'xpathparser:1' => 'stimmkreis',
          'xpathparser:2' => 'concat',
          'xpathparser:3' => 'concat(stimmkreis, \'-\', parliament)',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_parliament',
            'term_search' => '0',
            'autocreate' => 0,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_constituency_nr',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_constituency_street',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'Temporary target 1',
            'unique' => TRUE,
          ),
        ),
        'insert_new' => '0',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'constituency',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_bavarian_streets_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_committee_importer';
  $feeds_importer->config = array(
    'name' => 'GData Committee Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'parliament',
          'xpathparser:1' => 'committee',
          'xpathparser:2' => 'description',
          'xpathparser:3' => 'systemuuid',
          'xpathparser:4' => 'systemuuid',
          'xpathparser:5' => 'members/mitglied',
          'xpathparser:6' => 'members/vorsitz',
          'xpathparser:7' => 'members/stellvvorsitz',
          'xpathparser:8' => 'members/stellvmitglied',
          'xpathparser:9' => 'members/sprecher',
          'xpathparser:10' => 'members/stellvsprecher',
          'xpathparser:11' => 'members/schriftf',
          'xpathparser:12' => 'members/stellvschriftf',
          'xpathparser:13' => 'members/beratmitglied',
          'xpathparser:14' => 'topics',
          'xpathparser:15' => 'members/obmann',
          'xpathparser:16' => 'members/obfrau',
          'xpathparser:17' => 'members/sprecherin',
          'xpathparser:18' => 'members/stellv_sprecherin',
          'xpathparser:20' => 'members/stellv_schriftf_in',
          'xpathparser:21' => 'members/mitwirkungsberechtigtes_mitglied',
          'xpathparser:22' => 'members/schriftf_in',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_parliament',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_committee_members:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_committee_chairman:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_committee_vice_chairman:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_committee_alt_members:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_committee_spokesman:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_committee_alt_spokesman:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_committee_secretaries:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_committee_alt_secretaries:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_committee_advisory_members:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_topics',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_committee_foreman:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_committee_forewoman:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_committee_spokeswoman:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_committee_alt_spokeswoman:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_committee_alt_sec_female:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_committee_eligible_members:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_committee_sec_female:uuid',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'committee',
        'language' => 'de',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_committee_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_constituency_importer';
  $feeds_importer->config = array(
    'name' => 'GData Constituency Importer',
    'description' => 'Imports Constituencies from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'parliament',
          'xpathparser:1' => 'constituency',
          'xpathparser:3' => 'constituencynumber',
          'xpathparser:4' => 'systemuuid',
          'xpathparser:5' => 'systemuuid',
          'xpathparser:6' => 'areacodes',
          'xpathparser:7' => 'concat(parliament,\'-\',state)',
          'xpathparser:8' => 'areacodesdescription',
          'xpathparser:9' => 'electoralregion',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'name',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_constituency_nr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_constituency_area_codes',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'parentguid',
            'unique' => 0,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_constituency_ac_descriptor',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_electoral_region',
            'term_search' => '1',
            'autocreate' => 0,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'constituency',
        'vocabulary' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_constituency_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_elected_profiles';
  $feeds_importer->config = array(
    'name' => 'GData Profiles After Election Updater',
    'description' => 'Sets results after elections. Also overwrites all email addresses to reduce data.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:2' => 'constituencywon',
          'xpathparser:3' => 'listwon',
          'xpathparser:4' => 'constituencyresult',
          'xpathparser:8' => '',
          'xpathparser:9' => '',
          'xpathparser:10' => 'parliament',
          'xpathparser:12' => 'systemuuid',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:12' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:12' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          51622513 => 0,
          181527986 => 0,
          140336230 => 0,
          185431326 => 0,
          178386088 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_user_constituency_won',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_user_list_won',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_user_election_result',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_user_parliament',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:12',
            'target' => 'name',
            'unique' => 1,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'user',
        'insert_new' => 1,
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_elected_profiles'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_electoral_region_importer';
  $feeds_importer->config = array(
    'name' => 'GData Electoral Region Importer',
    'description' => 'Imports Electoral Regions from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:1' => 'parliament',
          'xpathparser:2' => 'electoralregion',
          'xpathparser:3' => 'notes',
          'xpathparser:4' => 'systemuuid',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'description',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'electoral_region',
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_electoral_region_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_external_links_importer';
  $feeds_importer->config = array(
    'name' => 'GData External Links Importer',
    'description' => 'Imports external links from a Google Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:2' => 'systemuuid',
          'xpathparser:3' => 'systemuuid',
          'xpathparser:5' => 'url',
        ),
        'rawXML' => array(
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          30037204 => 0,
          51622513 => 0,
          181527986 => 0,
          140336230 => 0,
          185431326 => 0,
          178386088 => 0,
          29859578 => 0,
          127500594 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:2',
            'target' => 'name',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:3',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_user_links_more:url',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'user',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_external_links_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_lists_importer';
  $feeds_importer->config = array(
    'name' => 'GData Lists Importer',
    'description' => 'Imports Lists from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:1' => 'parliament',
          'xpathparser:2' => 'electoralregion',
          'xpathparser:3' => 'list',
          'xpathparser:4' => 'systemuuid',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_electoral_region',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'election_list',
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_lists_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_parliaments_importer';
  $feeds_importer->config = array(
    'name' => 'GData Parliaments Importer',
    'description' => 'Imports Parliaments from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:3' => 'systemuuid',
          'xpathparser:0' => 'parliament',
          'xpathparser:1' => 'dateelection',
          'xpathparser:2' => 'dateperiodstart',
          'xpathparser:4' => 'dateperiodend',
          'xpathparser:5' => 'systemuuid',
          'xpathparser:6' => 'premiumprice',
        ),
        'rawXML' => array(
          'xpathparser:3' => 0,
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:3' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:0',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_parliament_election:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_parliament_valid:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_parliament_valid:end',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_premium_profile_price',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'parliaments',
        'vocabulary' => 0,
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_parliaments_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_party_importer';
  $feeds_importer->config = array(
    'name' => 'GData Party Importer',
    'description' => 'Imports Parties from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:1' => 'party',
          'xpathparser:2' => 'systemuuid',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'party',
        'vocabulary' => 0,
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_party_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_profiles_importer_v2';
  $feeds_importer->config = array(
    'name' => 'GData Profiles Importer v2',
    'description' => 'Imports Profiles from GData Spreadsheet (v2)',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:2' => 'email',
          'xpathparser:3' => 'systemuuid',
          'xpathparser:4' => 'systemroles',
          'xpathparser:7' => 'nameprefix',
          'xpathparser:8' => 'birthday',
          'xpathparser:9' => 'birthdayend',
          'xpathparser:10' => 'gender',
          'xpathparser:11' => 'firstname',
          'xpathparser:12' => 'lastname',
          'xpathparser:14' => 'phone',
          'xpathparser:15' => 'county',
          'xpathparser:16' => 'residence',
          'xpathparser:18' => 'children',
          'xpathparser:19' => 'marriagestatus',
          'xpathparser:20' => 'education',
          'xpathparser:21' => 'profession',
          'xpathparser:22' => 'politicalroles',
          'xpathparser:23' => 'txtpoliticalgoals',
          'xpathparser:24' => 'party',
          'xpathparser:25' => 'parliament',
          'xpathparser:26' => 'constituency',
          'xpathparser:27' => 'listposition',
          'xpathparser:28' => 'constituencyresult',
          'xpathparser:29' => 'pictureurl',
          'xpathparser:30' => 'picturecopyright',
          'xpathparser:31' => 'txtabout',
          'xpathparser:35' => 'systemroles',
          'xpathparser:36' => 'list',
          'xpathparser:37' => 'fraction',
          'xpathparser:40' => 'datejoined',
          'xpathparser:41' => 'dateretired',
          'xpathparser:42' => 'constituencywon',
          'xpathparser:43' => 'listwon',
          'xpathparser:44' => 'mobile',
          'xpathparser:45' => 'moreurls1',
          'xpathparser:46' => 'moreurls1title',
          'xpathparser:47' => 'moreurls2',
          'xpathparser:48' => 'moreurls2title',
          'xpathparser:49' => 'moreurls3',
          'xpathparser:50' => 'moreurls3title',
          'xpathparser:51' => 'email2',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
          'xpathparser:23' => 0,
          'xpathparser:24' => 0,
          'xpathparser:25' => 0,
          'xpathparser:26' => 0,
          'xpathparser:27' => 0,
          'xpathparser:28' => 0,
          'xpathparser:29' => 0,
          'xpathparser:30' => 0,
          'xpathparser:31' => 0,
          'xpathparser:35' => 0,
          'xpathparser:36' => 0,
          'xpathparser:37' => 0,
          'xpathparser:40' => 0,
          'xpathparser:41' => 0,
          'xpathparser:42' => 0,
          'xpathparser:43' => 0,
          'xpathparser:44' => 0,
          'xpathparser:45' => 0,
          'xpathparser:46' => 0,
          'xpathparser:47' => 0,
          'xpathparser:48' => 0,
          'xpathparser:49' => 0,
          'xpathparser:50' => 0,
          'xpathparser:51' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
            'xpathparser:23' => 0,
            'xpathparser:24' => 0,
            'xpathparser:25' => 0,
            'xpathparser:26' => 0,
            'xpathparser:27' => 0,
            'xpathparser:28' => 0,
            'xpathparser:29' => 0,
            'xpathparser:30' => 0,
            'xpathparser:31' => 0,
            'xpathparser:35' => 0,
            'xpathparser:36' => 0,
            'xpathparser:37' => 0,
            'xpathparser:40' => 0,
            'xpathparser:41' => 0,
            'xpathparser:42' => 0,
            'xpathparser:43' => 0,
            'xpathparser:44' => 0,
            'xpathparser:45' => 0,
            'xpathparser:46' => 0,
            'xpathparser:47' => 0,
            'xpathparser:48' => 0,
            'xpathparser:49' => 0,
            'xpathparser:50' => 0,
            'xpathparser:51' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          51622513 => 0,
          181527986 => 0,
          140336230 => 0,
          185431326 => 0,
          178386088 => 0,
          29859578 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'mail',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'roles',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_user_prefix',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_user_birthday:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_user_birthday:end',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_user_gender',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_user_fname',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_user_lname',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_user_phone',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Blank source 1',
            'target' => 'field_user_address:country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_user_address:administrative_area',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_user_address:locality',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_user_childs',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_user_marriage_status',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_user_education',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_user_job_skills',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_user_political_roles',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'xpathparser:23',
            'target' => 'field_user_political_goals',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'xpathparser:24',
            'target' => 'field_user_party',
            'term_search' => '0',
            'autocreate' => 0,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'xpathparser:25',
            'target' => 'field_user_parliament',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'xpathparser:26',
            'target' => 'field_user_constituency',
            'term_search' => '1',
            'autocreate' => 0,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'xpathparser:27',
            'target' => 'field_user_list_position',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'xpathparser:28',
            'target' => 'field_user_election_result',
            'unique' => FALSE,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'xpathparser:29',
            'target' => 'field_user_picture',
            'unique' => FALSE,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'xpathparser:30',
            'target' => 'field_user_picture_copyright',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'xpathparser:31',
            'target' => 'field_user_about',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'xpathparser:35',
            'target' => 'field_user_roles_for_view_mode_s',
            'unique' => FALSE,
            'language' => 'und',
          ),
          29 => array(
            'source' => 'xpathparser:36',
            'target' => 'field_user_list',
            'term_search' => '1',
            'autocreate' => 0,
            'language' => 'und',
          ),
          30 => array(
            'source' => 'Blank source 2',
            'target' => 'name',
            'unique' => 1,
            'language' => 'und',
          ),
          31 => array(
            'source' => 'xpathparser:37',
            'target' => 'field_user_fraction',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          32 => array(
            'source' => 'xpathparser:40',
            'target' => 'field_user_joined:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          33 => array(
            'source' => 'xpathparser:41',
            'target' => 'field_user_retired:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          34 => array(
            'source' => 'xpathparser:42',
            'target' => 'field_user_constituency_won',
            'unique' => FALSE,
            'language' => 'und',
          ),
          35 => array(
            'source' => 'xpathparser:43',
            'target' => 'field_user_list_won',
            'unique' => FALSE,
            'language' => 'und',
          ),
          36 => array(
            'source' => 'xpathparser:44',
            'target' => 'field_user_mobile',
            'unique' => FALSE,
            'language' => 'und',
          ),
          37 => array(
            'source' => 'xpathparser:45',
            'target' => 'field_user_links_more:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          38 => array(
            'source' => 'xpathparser:46',
            'target' => 'field_user_links_more:title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          39 => array(
            'source' => 'xpathparser:47',
            'target' => 'field_user_links_more:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          40 => array(
            'source' => 'xpathparser:48',
            'target' => 'field_user_links_more:title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          41 => array(
            'source' => 'xpathparser:49',
            'target' => 'field_user_links_more:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          42 => array(
            'source' => 'xpathparser:50',
            'target' => 'field_user_links_more:title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          43 => array(
            'source' => 'xpathparser:51',
            'target' => 'field_user_public_mail',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'user',
        'insert_new' => 1,
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_profiles_importer_v2'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_states_importer';
  $feeds_importer->config = array(
    'name' => 'GData States Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'parliament',
          'xpathparser:1' => 'state',
          'xpathparser:5' => 'concat(parliament,\'-\',state)',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '//row[state!=\'\']',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'name',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'constituency',
        'vocabulary' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_states_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_subject_importer';
  $feeds_importer->config = array(
    'name' => 'GData Subject Importer',
    'description' => 'imports subjects for question form',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:2' => 'subject',
          'xpathparser:3' => 'parliament',
        ),
        'rawXML' => array(
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:2',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_parliament',
            'term_search' => '1',
            'autocreate' => 0,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'dialogue_topics',
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_subject_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_topic_updater';
  $feeds_importer->config = array(
    'name' => 'GData Topic Updater',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:1' => 'topic',
          'xpathparser:2' => 'systemuuid',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_topics',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '0',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'sidejob',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_topic_updater'] = $feeds_importer;

  return $export;
}
