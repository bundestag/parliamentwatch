<?php
/**
 * @file
 * pw_globals.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function pw_globals_field_default_fields() {
  $fields = array();

  // Exported field: 'comment-comment_node_page-comment_body'.
  $fields['comment-comment_node_page-comment_body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'comment',
      ),
      'field_name' => 'comment_body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'comment_node_page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'comment',
      'field_name' => 'comment_body',
      'label' => 'Comment',
      'required' => TRUE,
      'settings' => array(
        'exclude_cv' => FALSE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'comment-comment_node_webform-comment_body'.
  $fields['comment-comment_node_webform-comment_body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'comment',
      ),
      'field_name' => 'comment_body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'comment_node_webform',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'comment',
      'field_name' => 'comment_body',
      'label' => 'Comment',
      'required' => TRUE,
      'settings' => array(
        'exclude_cv' => FALSE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-page-body'.
  $fields['node-page-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'colorbox' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '29',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'smart_trim',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'more_link' => '0',
            'more_text' => 'Read more',
            'summary_handler' => 'full',
            'trim_length' => '600',
            'trim_link' => '0',
            'trim_options' => array(
              'text' => 0,
            ),
            'trim_preserve_tags' => '',
            'trim_suffix' => '...',
            'trim_type' => 'chars',
          ),
          'type' => 'smart_trim_format',
          'weight' => '2',
        ),
        'tile' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'exclude_cv' => FALSE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-page-field_teaser_image'.
  $fields['node-page-field_teaser_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_teaser_image',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'deleted' => '0',
      'description' => 'Wird im Megamenü und auf Übersichtsseiten angezeigt.',
      'display' => array(
        'colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'medium',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '[node:url]',
              'linked' => 0,
            ),
          ),
          'type' => 'image',
          'weight' => '1',
        ),
        'tile' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'width_medium',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'image',
          'weight' => '0',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_teaser_image',
      'label' => 'Teaser image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'exclude_cv' => FALSE,
        'file_directory' => 'teaserimage',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '2 MB',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'private' => 0,
            'public' => 'public',
            'youtube' => 0,
          ),
          'allowed_types' => array(
            'application' => 0,
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 'media_default--media_browser_1',
            'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
            'media_internet' => 0,
            'upload' => 'upload',
            'youtube' => 0,
          ),
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-pw_testimonial-field_testimonial_fullname'.
  $fields['node-pw_testimonial-field_testimonial_fullname'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_testimonial_fullname',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '32',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'pw_testimonial',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Bitte im Format "Titel Vorname Nachname" eingeben.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'pw_newsletter' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '2',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_testimonial_fullname',
      'label' => 'Vollständiger Name',
      'required' => 1,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'copyright' => 'copyright',
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'html_mail' => 'html_mail',
            'managed_content' => 'managed_content',
            'php_code' => 'php_code',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'copyright' => array(
                'weight' => '0',
              ),
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'html_mail' => array(
                'weight' => '0',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => 1,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-pw_testimonial-field_testimonial_month'.
  $fields['node-pw_testimonial-field_testimonial_month'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_testimonial_month',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 0,
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'pw_testimonial',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_remaining_days' => FALSE,
          ),
          'type' => 'date_default',
          'weight' => 3,
        ),
        'pw_newsletter' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '31',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_testimonial_month',
      'label' => 'Anzeige Monat',
      'required' => 1,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'd.m.Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_select',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-pw_testimonial-field_testimonial_portrait'.
  $fields['node-pw_testimonial-field_testimonial_portrait'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_testimonial_portrait',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'pw_testimonial',
      'deleted' => '0',
      'description' => 'Zielformat ist quadratisch als klassisches Schulterstück bzw. Büste.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'square_small',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'image',
          'weight' => '2',
        ),
        'pw_newsletter' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'square_small',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'image',
          'weight' => '0',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_testimonial_portrait',
      'label' => 'Porträt',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'exclude_cv' => FALSE,
        'file_directory' => 'testmonial-portraits',
        'file_extensions' => 'png jpg jpeg',
        'max_filesize' => '500 KB',
        'max_resolution' => '',
        'min_resolution' => '140x140',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'private' => 0,
            'public' => 'public',
            'youtube' => 0,
          ),
          'allowed_types' => array(
            'application' => 0,
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 'media_default--media_browser_1',
            'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
            'media_internet' => 0,
            'upload' => 'upload',
            'youtube' => 0,
          ),
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-pw_testimonial-field_testimonial_quote'.
  $fields['node-pw_testimonial-field_testimonial_quote'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_testimonial_quote',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'pw_testimonial',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Was macht abgeordnetenwatch.de so besonders?',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'pw_newsletter' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '1',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_testimonial_quote',
      'label' => 'Zitat',
      'required' => 1,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'copyright' => 'copyright',
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'html_mail' => 'html_mail',
            'managed_content' => 'managed_content',
            'newsletter' => 0,
            'php_code' => 'php_code',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'copyright' => array(
                'weight' => '0',
              ),
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'html_mail' => array(
                'weight' => '0',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'newsletter' => array(
                'weight' => '0',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => '320',
          'maxlength_js_enforce' => 1,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '2',
        ),
        'type' => 'text_textarea',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-webform-body'.
  $fields['node-webform-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'webform',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'exclude_cv' => FALSE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'node-webform-field_teaser_image'.
  $fields['node-webform-field_teaser_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_teaser_image',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'webform',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'image',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_teaser_image',
      'label' => 'Teaser image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'exclude_cv' => FALSE,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'private' => 0,
            'public' => 'public',
            'youtube' => 0,
          ),
          'allowed_types' => array(
            'application' => 0,
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 0,
            'media_default--media_browser_my_files' => 0,
            'media_internet' => 0,
            'upload' => 0,
          ),
        ),
        'type' => 'media_generic',
        'weight' => '42',
      ),
    ),
  );

  // Exported field: 'node-webform-field_webform_footer'.
  $fields['node-webform-field_webform_footer'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_footer',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'webform',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'colorbox' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
      ),
      'ds_extras_field_template' => 'theme_ds_field_reset',
      'entity_type' => 'node',
      'field_name' => 'field_webform_footer',
      'label' => 'Footer',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'html_mail' => 'html_mail',
            'managed_content' => 'managed_content',
            'php_code' => 'php_code',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'html_mail' => array(
                'weight' => '0',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 1,
          'profile' => 'managed_content',
        ),
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => '',
          'maxlength_js_enforce' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-affiliates-field_affiliate_logo'.
  $fields['taxonomy_term-affiliates-field_affiliate_logo'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_affiliate_logo',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'affiliates',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'image',
          'weight' => 2,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_affiliate_logo',
      'label' => 'Affiliate Logo',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'exclude_cv' => FALSE,
        'file_directory' => 'affiliates',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'filefield_sources' => array(
            'filefield_sources' => array(
              'attach' => 0,
              'clipboard' => 0,
              'reference' => 0,
              'remote' => 'remote',
              'upload' => 'upload',
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'move',
              'path' => 'file_attach',
            ),
            'source_imce' => array(
              'imce_mode' => 0,
            ),
            'source_reference' => array(
              'autocomplete' => '0',
            ),
          ),
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-affiliates-field_affiliate_url'.
  $fields['taxonomy_term-affiliates-field_affiliate_url'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_affiliate_url',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'affiliates',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'link_default',
          'weight' => 1,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_affiliate_url',
      'label' => 'Affiliate URL',
      'required' => 0,
      'settings' => array(
        'absolute_url' => 1,
        'attributes' => array(
          'class' => '',
          'configurable_class' => 0,
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Suche',
          'enable' => 0,
          'profile' => '',
        ),
        'rel_remove' => 'default',
        'title' => 'none',
        'title_label_use_field_label' => 0,
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-constituency-field_constituency_ac_descriptor'.
  $fields['taxonomy_term-constituency-field_constituency_ac_descriptor'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_constituency_ac_descriptor',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '9999',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'constituency',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => 4,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_constituency_ac_descriptor',
      'label' => 'AC Descriptor',
      'required' => FALSE,
      'settings' => array(
        'exclude_cv' => FALSE,
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-constituency-field_constituency_area_codes'.
  $fields['taxonomy_term-constituency-field_constituency_area_codes'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_constituency_area_codes',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'area_codex',
            'parent' => '0',
          ),
        ),
        'options_list_callback' => NULL,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'constituency',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 3,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_constituency_area_codes',
      'label' => 'Area Codes',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-constituency-field_constituency_nr'.
  $fields['taxonomy_term-constituency-field_constituency_nr'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_constituency_nr',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '10',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'constituency',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'constituency number or similar identifier ',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_constituency_nr',
      'label' => 'Number',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'ds_code' => 'ds_code',
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'managed_content' => 'managed_content',
            'php_code' => 'php_code',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'ds_code' => array(
                'weight' => '-5',
              ),
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '5',
        ),
        'type' => 'text_textfield',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-constituency-field_constituency_street'.
  $fields['taxonomy_term-constituency-field_constituency_street'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_constituency_street',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'constituency',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Strassenauswahl - hier für München, Nürnberg verwendet',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => 6,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_constituency_street',
      'label' => 'Street',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'copyright' => 'copyright',
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'html_mail' => 'html_mail',
            'managed_content' => 'managed_content',
            'newsletter' => 'newsletter',
            'php_code' => 'php_code',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'copyright' => array(
                'weight' => '0',
              ),
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'html_mail' => array(
                'weight' => '0',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'newsletter' => array(
                'weight' => '0',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Suchen',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-constituency-field_electoral_region'.
  $fields['taxonomy_term-constituency-field_electoral_region'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_electoral_region',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'electoral_region',
            'parent' => '0',
          ),
        ),
        'options_list_callback' => NULL,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'constituency',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 5,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_electoral_region',
      'label' => 'Electoral Region',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-constituency-field_parliament'.
  $fields['taxonomy_term-constituency-field_parliament'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'parliaments',
            'parent' => '0',
          ),
        ),
        'options_list_callback' => NULL,
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'constituency',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament',
      'label' => 'Parliament',
      'required' => 1,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-election_list-field_electoral_region'.
  $fields['taxonomy_term-election_list-field_electoral_region'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_electoral_region',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'electoral_region',
            'parent' => '0',
          ),
        ),
        'options_list_callback' => NULL,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'election_list',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 0,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_electoral_region',
      'label' => 'Electoral Region',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-election_list-field_parliament'.
  $fields['taxonomy_term-election_list-field_parliament'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'parliaments',
            'parent' => '0',
          ),
        ),
        'options_list_callback' => NULL,
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'election_list',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 1,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament',
      'label' => 'Parliament',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-electoral_region-field_parliament'.
  $fields['taxonomy_term-electoral_region-field_parliament'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'parliaments',
            'parent' => '0',
          ),
        ),
        'options_list_callback' => NULL,
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'electoral_region',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 0,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament',
      'label' => 'Parliament',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '32',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_affiliates'.
  $fields['taxonomy_term-parliaments-field_affiliates'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_affiliates',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'affiliates',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => array(
        0 => array(
          'tid' => '27266',
          'vid' => '42',
          'name' => 'Spiegel Online',
          'description' => '',
          'format' => 'managed_content',
          'weight' => '0',
          'uuid' => '0fd94ea3-b506-4f38-a4fc-df75f8dad1e8',
          'vocabulary_machine_name' => 'affiliates',
          'field_affiliate_url' => array(
            'und' => array(
              0 => array(
                'url' => 'www.spiegel.de',
                'title' => NULL,
                'attributes' => array(),
              ),
            ),
          ),
          'field_affiliate_logo' => array(
            'und' => array(
              0 => array(
                'fid' => '215723',
                'uid' => '129697',
                'filename' => 'spiegel-online-logo-250px.png',
                'uri' => 'public://affiliates/spiegel-online-logo-250px.png',
                'filemime' => 'image/png',
                'filesize' => '1908',
                'status' => '1',
                'timestamp' => '1499249962',
                'type' => 'image',
                'uuid' => '20521780-4eb2-477e-8e84-25d06bb49cc1',
                'field_image_copyright' => array(
                  'und' => array(
                    0 => array(
                      'value' => '',
                      'format' => 'copyright',
                      'safe_value' => '',
                    ),
                  ),
                ),
                'field_file_image_alt_text' => array(),
                'field_file_image_title_text' => array(),
                'metadata' => array(
                  'height' => 182,
                  'width' => 250,
                ),
                'alt' => '',
                'title' => '',
                'height' => '182',
                'width' => '250',
              ),
            ),
          ),
          'path' => array(
            'pathauto' => '1',
          ),
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 12,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'exclude_cv' => 0,
      'field_name' => 'field_affiliates',
      'label' => 'Affiliates',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_contributer'.
  $fields['taxonomy_term-parliaments-field_contributer'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_contributer',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Say thank you to the contributer.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => 13,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'exclude_cv' => 0,
      'field_name' => 'field_contributer',
      'label' => 'Contributer',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'copyright' => 'copyright',
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'html_mail' => 'html_mail',
            'managed_content' => 'managed_content',
            'newsletter' => 'newsletter',
            'php_code' => 'php_code',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'copyright' => array(
                'weight' => '0',
              ),
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'html_mail' => array(
                'weight' => '0',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'newsletter' => array(
                'weight' => '0',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Suchen',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_electoral_law'.
  $fields['taxonomy_term-parliaments-field_electoral_law'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_electoral_law',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'page' => 'page',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'link' => FALSE,
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'entityreference_label',
          'weight' => 11,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_electoral_law',
      'label' => 'Electoral law',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_icon_class'.
  $fields['taxonomy_term-parliaments-field_icon_class'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_icon_class',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '100',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => array(
        0 => array(
          'value' => 'icon-de',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '8',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_icon_class',
      'label' => 'Icon Class',
      'required' => 1,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'copyright' => 'copyright',
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'html_mail' => 'html_mail',
            'managed_content' => 'managed_content',
            'php_code' => 'php_code',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'copyright' => array(
                'weight' => '0',
              ),
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'html_mail' => array(
                'weight' => '0',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_parliament_candidate_check'.
  $fields['taxonomy_term-parliaments-field_parliament_candidate_check'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament_candidate_check',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'link_default',
          'weight' => 14,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament_candidate_check',
      'label' => 'Kandidaten-Check',
      'required' => 0,
      'settings' => array(
        'absolute_url' => 1,
        'attributes' => array(
          'class' => '',
          'configurable_class' => 0,
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'exclude_cv' => FALSE,
        'linkit' => array(
          'button_text' => 'Suchen',
          'enable' => 0,
          'profile' => '',
        ),
        'rel_remove' => 'default',
        'title' => 'none',
        'title_label_use_field_label' => 0,
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '17',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_parliament_election'.
  $fields['taxonomy_term-parliaments-field_parliament_election'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament_election',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_remaining_days' => FALSE,
          ),
          'type' => 'date_default',
          'weight' => '2',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament_election',
      'label' => 'Election',
      'required' => 1,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'd.m.Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'text_parts' => array(),
          'year_range' => '2000:2100',
        ),
        'type' => 'date_select',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_parliament_filter_disabled'.
  $fields['taxonomy_term-parliaments-field_parliament_filter_disabled'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament_filter_disabled',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'field_user_address_administrative_area' => 'administrative area',
          'field_electoral_region_tid' => 'electoral region',
          'field_user_list_tid' => 'list',
          'field_user_list_position_tid' => 'list position',
          'field_user_constituency_tid' => 'constituency',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => array(
        0 => array(
          'value' => 'field_user_address_administrative_area',
        ),
        1 => array(
          'value' => 'field_electoral_region_tid',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'list_default',
          'weight' => '5',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament_filter_disabled',
      'label' => 'Filter Disabled',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_parliament_patron'.
  $fields['taxonomy_term-parliaments-field_parliament_patron'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament_patron',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'page' => 'page',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'link' => FALSE,
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'entityreference_label',
          'weight' => 13,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament_patron',
      'label' => 'Patron',
      'required' => FALSE,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => 60,
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '16',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_parliament_previous'.
  $fields['taxonomy_term-parliaments-field_parliament_previous'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament_previous',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'parliaments',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 15,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament_previous',
      'label' => 'Previous parliament',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '18',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_parliament_valid'.
  $fields['taxonomy_term-parliaments-field_parliament_valid'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_parliament_valid',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'repeat' => '0',
        'timezone_db' => '',
        'todate' => 'required',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_remaining_days' => FALSE,
          ),
          'type' => 'date_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_remaining_days' => FALSE,
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '0',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_parliament_valid',
      'label' => 'Valid Date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'blank',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'Y-m-d H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'text_parts' => array(),
          'year_range' => '2000:2100',
        ),
        'type' => 'date_select',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_premium_profile_price'.
  $fields['taxonomy_term-parliaments-field_premium_profile_price'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_premium_profile_price',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => array(
        0 => array(
          'value' => '179',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => '3',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_premium_profile_price',
      'label' => 'Premium Profile Price',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'number',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-parliaments-field_shown_metrics'.
  $fields['taxonomy_term-parliaments-field_shown_metrics'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_shown_metrics',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'questions' => 'Fragen und Antworten',
          'sidejobs' => 'Nebentätigkeiten',
          'speeches' => 'Gehaltene Reden',
          'voting_behavior' => 'Abstimmungsverhalten',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'parliaments',
      'default_value' => array(
        0 => array(
          'value' => 'questions',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'list_default',
          'weight' => 9,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_shown_metrics',
      'label' => 'Dargestellte Metriken',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_buttons',
        'weight' => '14',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('AC Descriptor');
  t('Affiliate Logo');
  t('Affiliate URL');
  t('Affiliates');
  t('Anzeige Monat');
  t('Area Codes');
  t('Bitte im Format "Titel Vorname Nachname" eingeben.');
  t('Body');
  t('Comment');
  t('Contributer');
  t('Dargestellte Metriken');
  t('Election');
  t('Electoral Region');
  t('Electoral law');
  t('Filter Disabled');
  t('Footer');
  t('Icon Class');
  t('Kandidaten-Check');
  t('Number');
  t('Parliament');
  t('Patron');
  t('Porträt');
  t('Premium Profile Price');
  t('Previous parliament');
  t('Say thank you to the contributer.');
  t('Strassenauswahl - hier für München, Nürnberg verwendet');
  t('Street');
  t('Teaser image');
  t('Valid Date');
  t('Vollständiger Name');
  t('Was macht abgeordnetenwatch.de so besonders?');
  t('Wird im Megamenü und auf Übersichtsseiten angezeigt.');
  t('Zielformat ist quadratisch als klassisches Schulterstück bzw. Büste.');
  t('Zitat');
  t('constituency number or similar identifier ');

  return $fields;
}
