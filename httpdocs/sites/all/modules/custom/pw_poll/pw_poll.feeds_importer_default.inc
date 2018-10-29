<?php
/**
 * @file
 * pw_poll.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function pw_poll_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_poll_comments_importer';
  $feeds_importer->config = array(
    'name' => 'GData Poll Comments Importer',
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
          'xpathparser:1' => 'systemuuid',
          'xpathparser:3' => 'txt',
          'xpathparser:4' => 'commentdate',
          'xpathparser:6' => 'voteuuid',
          'xpathparser:7' => 'author',
          'xpathparser:8' => 'author',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
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
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommentProcessor',
      'config' => array(
        'input_format' => 'filtered_html',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'comment_body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'created',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:6',
            'target' => 'nid_by_guid',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Blank source 1',
            'target' => 'status',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'name',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'skip_hash_check' => 1,
        'bundle' => 'comment_node_poll',
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'language' => 'und',
        'authorize' => 1,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_poll_comments_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_poll_importer';
  $feeds_importer->config = array(
    'name' => 'GData Poll Importer',
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
          'xpathparser:1' => 'systemuuid',
          'xpathparser:2' => 'systemuuid',
          'xpathparser:3' => 'title',
          'xpathparser:4' => 'teaser',
          'xpathparser:5' => 'txt',
          'xpathparser:6' => 'votingdate',
          'xpathparser:7' => 'voted',
          'xpathparser:8' => 'externalurl',
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
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_poll_date:start',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_voted',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_poll_external_url',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Blank source 1',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'managed_content',
        'skip_hash_check' => 1,
        'bundle' => 'poll',
        'insert_new' => '1',
        'update_non_existent' => 'skip',
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
  $export['gdata_poll_importer'] = $feeds_importer;

  return $export;
}
