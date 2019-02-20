<?php
/**
 * @file
 * pw_newsletter.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function pw_newsletter_filter_default_formats() {
  $formats = array();

  // Exported format: Newsletter.
  $formats['newsletter'] = array(
    'format' => 'newsletter',
    'name' => 'Newsletter',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'media_filter_paragraph_fix' => array(
        'weight' => '-49',
        'status' => '1',
        'settings' => array(
          'replace' => 0,
        ),
      ),
      'media_filter' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-47',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'pathologic' => array(
        'weight' => '-45',
        'status' => '1',
        'settings' => array(
          'settings_source' => 'global',
          'local_paths' => '',
          'protocol_style' => 'full',
          'local_settings' => array(
            'protocol_style' => 'full',
            'local_paths' => '',
          ),
        ),
      ),
      'filter_encrypt' => array(
        'weight' => '-39',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
