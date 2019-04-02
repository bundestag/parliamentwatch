<?php
/**
 * @file
 * pw_partners.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function pw_partners_field_default_fields() {
  $fields = array();

  // Exported field: 'node-partners-body'.
  $fields['node-partners-body'] = array(
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
      'bundle' => 'partners',
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

  // Exported field: 'node-partners-field_main_partners'.
  $fields['node-partners-field_main_partners'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_main_partners',
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
      'bundle' => 'partners',
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
        1 => array(
          'description' => '',
          'field_affiliate_logo' => array(
            'und' => array(
              0 => array(
                'fid' => '215725',
                'uid' => '129697',
                'filename' => 'welt-logo-250px.png',
                'uri' => 'public://affiliates/welt-logo-250px.png',
                'filemime' => 'image/png',
                'filesize' => '4656',
                'status' => '1',
                'timestamp' => '1499250030',
                'type' => 'image',
                'uuid' => 'b66a9a31-352d-4657-bf27-e98db59593d2',
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
                  'height' => 125,
                  'width' => 250,
                ),
                'alt' => '',
                'title' => '',
                'height' => '125',
                'width' => '250',
              ),
            ),
          ),
          'field_affiliate_url' => array(
            'und' => array(
              0 => array(
                'url' => 'www.welt.de',
                'title' => NULL,
                'attributes' => array(),
              ),
            ),
          ),
          'format' => 'managed_content',
          'name' => 'Welt',
          'path' => array(
            'pathauto' => '1',
          ),
          'tid' => '27268',
          'uuid' => '41e7d382-5c72-45ef-8f8d-fa946264a9d8',
          'vid' => '42',
          'vocabulary_machine_name' => 'affiliates',
          'weight' => '0',
        ),
        2 => array(
          'description' => '',
          'field_affiliate_logo' => array(
            'und' => array(
              0 => array(
                'fid' => '215724',
                'uid' => '129697',
                'filename' => 't-online-logo-250px.png',
                'uri' => 'public://affiliates/t-online-logo-250px.png',
                'filemime' => 'image/png',
                'filesize' => '957',
                'status' => '1',
                'timestamp' => '1499250010',
                'type' => 'image',
                'uuid' => '6eeb3fa5-6cfb-4107-b429-9c2222629236',
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
                  'height' => 57,
                  'width' => 250,
                ),
                'alt' => '',
                'title' => '',
                'height' => '57',
                'width' => '250',
              ),
            ),
          ),
          'field_affiliate_url' => array(
            'und' => array(
              0 => array(
                'url' => 'www.t-online.de/',
                'title' => NULL,
                'attributes' => array(),
              ),
            ),
          ),
          'format' => 'managed_content',
          'name' => 'T Online',
          'path' => array(
            'pathauto' => '1',
          ),
          'tid' => '27267',
          'uuid' => '2764e54e-0914-4a26-ac06-7f13dde32ccc',
          'vid' => '42',
          'vocabulary_machine_name' => 'affiliates',
          'weight' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
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
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_main_partners',
      'label' => 'Main Partners',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'options',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'options_select',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-partners-field_parliament'.
  $fields['node-partners-field_parliament'] = array(
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
      'bundle' => 'partners',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
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
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
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
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-partners-field_partners'.
  $fields['node-partners-field_partners'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_partners',
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
      'bundle' => 'partners',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
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
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_partners',
      'label' => 'Partners',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'options',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'options_select',
        'weight' => '4',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Main Partners');
  t('Parliament');
  t('Partners');

  return $fields;
}
