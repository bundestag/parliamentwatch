<?php
/**
 * @file
 * pw_press.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pw_press_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_press_article';
  $strongarm->value = '0';
  $export['comment_anonymous_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_press_release';
  $strongarm->value = '0';
  $export['comment_anonymous_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_press_article';
  $strongarm->value = 1;
  $export['comment_default_mode_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_press_release';
  $strongarm->value = 1;
  $export['comment_default_mode_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_press_article';
  $strongarm->value = '50';
  $export['comment_default_per_page_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_press_release';
  $strongarm->value = '50';
  $export['comment_default_per_page_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_press_article';
  $strongarm->value = 1;
  $export['comment_form_location_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_press_release';
  $strongarm->value = 1;
  $export['comment_form_location_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_press_article';
  $strongarm->value = '1';
  $export['comment_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_press_release';
  $strongarm->value = '1';
  $export['comment_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_press_article';
  $strongarm->value = '1';
  $export['comment_preview_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_press_release';
  $strongarm->value = '1';
  $export['comment_preview_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_press_article';
  $strongarm->value = 1;
  $export['comment_subject_field_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_press_release';
  $strongarm->value = 1;
  $export['comment_subject_field_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_press_article';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_press_release';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_press_article';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_press_release';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_press_article';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_press_release';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__press_article';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'colorbox' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'pw_newsletter' => array(
        'custom_settings' => FALSE,
      ),
      'tile' => array(
        'custom_settings' => TRUE,
      ),
      'list_item' => array(
        'custom_settings' => FALSE,
      ),
      'embedded' => array(
        'custom_settings' => FALSE,
      ),
      'tabular' => array(
        'custom_settings' => FALSE,
      ),
      'timeline' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '2',
        ),
        'path' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '36',
            'visible' => FALSE,
          ),
          'tile' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '-100',
            'visible' => TRUE,
          ),
          'tile' => array(
            'weight' => '-100',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__press_release';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'colorbox' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'pw_newsletter' => array(
        'custom_settings' => FALSE,
      ),
      'tile' => array(
        'custom_settings' => TRUE,
      ),
      'list_item' => array(
        'custom_settings' => FALSE,
      ),
      'embedded' => array(
        'custom_settings' => FALSE,
      ),
      'tabular' => array(
        'custom_settings' => FALSE,
      ),
      'timeline' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'feeds' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '32',
            'visible' => FALSE,
          ),
          'tile' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'sharethis' => array(
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'tile' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_press_article';
  $strongarm->value = '2';
  $export['language_content_type_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_press_release';
  $strongarm->value = '2';
  $export['language_content_type_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_press_article';
  $strongarm->value = array();
  $export['menu_options_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_press_release';
  $strongarm->value = array();
  $export['menu_options_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_press_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_press_release';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_press_article';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_press_release';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_press_article';
  $strongarm->value = '1';
  $export['node_preview_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_press_release';
  $strongarm->value = '1';
  $export['node_preview_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_press_article';
  $strongarm->value = 0;
  $export['node_submitted_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_press_release';
  $strongarm->value = 1;
  $export['node_submitted_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_press_article_de_pattern';
  $strongarm->value = 'ueber-uns/presse/presseartikel/[node:field-press-article-date:custom:Y-m-d]/[node:title]';
  $export['pathauto_node_press_article_de_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_press_article_pattern';
  $strongarm->value = 'about/press/press-articles/[node:field-press-article-date:custom:Y-m-d]/[node:title]';
  $export['pathauto_node_press_article_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_press_article_und_pattern';
  $strongarm->value = 'ueber-uns/presse/presseartikel/[node:field-press-article-date:custom:Y-m-d]/[node:title]';
  $export['pathauto_node_press_article_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_press_release_de_pattern';
  $strongarm->value = 'ueber-uns/presse/pressemitteilungen/[node:field-press-release-date:custom:Y-m-d]/[node:title]';
  $export['pathauto_node_press_release_de_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_press_release_pattern';
  $strongarm->value = 'ueber-uns/presse/pressemitteilungen/[node:field-press-release-date:custom:Y-m-d]/[node:title]';
  $export['pathauto_node_press_release_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_press_release_und_pattern';
  $strongarm->value = 'ueber-uns/presse/pressemitteilungen/[node:field-press-release-date:custom:Y-m-d]/[node:title]';
  $export['pathauto_node_press_release_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_module_press_article';
  $strongarm->value = 'rh_node';
  $export['rh_module_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_action_press_article';
  $strongarm->value = '3';
  $export['rh_node_action_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_override_press_article';
  $strongarm->value = 0;
  $export['rh_node_override_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_press_article';
  $strongarm->value = 'ueber-uns/presse/pressespiegel';
  $export['rh_node_redirect_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_response_press_article';
  $strongarm->value = '301';
  $export['rh_node_redirect_response_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sync_translations_press_release';
  $strongarm->value = '0';
  $export['sync_translations_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_node_press_article';
  $strongarm->value = 0;
  $export['webform_node_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_node_press_release';
  $strongarm->value = 0;
  $export['webform_node_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'weight_default_press_release';
  $strongarm->value = '0';
  $export['weight_default_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'weight_enabled_press_release';
  $strongarm->value = '0';
  $export['weight_enabled_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'weight_menu_press_release';
  $strongarm->value = '0';
  $export['weight_menu_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'weight_range_press_release';
  $strongarm->value = '20';
  $export['weight_range_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_press_article';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_press_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_press_release';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_press_release'] = $strongarm;

  return $export;
}
