<?php
/**
 * @file
 * pw_committees.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function pw_committees_field_default_fields() {
  $fields = array();

  // Exported field: 'node-committee-body'.
  $fields['node-committee-body'] = array(
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
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'field_delimiter' => '',
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
            'field_delimiter' => '',
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
          'module' => 'smart_trim',
          'settings' => array(
            'field_delimiter' => '',
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
            'trim_length' => '150',
            'trim_link' => '0',
            'trim_options' => array(
              'text' => 0,
            ),
            'trim_preserve_tags' => '',
            'trim_suffix' => '...',
            'trim_type' => 'chars',
          ),
          'type' => 'smart_trim_format',
          'weight' => '0',
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
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-committee-field_committee_alt_members'.
  $fields['node-committee-field_committee_alt_members'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_committee_alt_members',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'users' => array(
          'columns' => array(
            'target_id' => 'uid',
          ),
          'table' => 'users',
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
          'target_bundles' => array(),
        ),
        'target_type' => 'user',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'field_delimiter' => '',
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
            'links' => 1,
            'use_content_language' => 1,
            'view_mode' => 'tile',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'field_delimiter' => '',
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
          'weight' => '7',
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_committee_alt_members',
      'label' => 'Alternate Members',
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
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-committee-field_committee_chairman'.
  $fields['node-committee-field_committee_chairman'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_committee_chairman',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'users' => array(
          'columns' => array(
            'target_id' => 'uid',
          ),
          'table' => 'users',
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
          'target_bundles' => array(),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'user',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'field_delimiter' => '',
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
            'links' => 1,
            'use_content_language' => 1,
            'view_mode' => 'tile',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'field_delimiter' => '',
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
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_committee_chairman',
      'label' => 'Chairman',
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
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-committee-field_committee_members'.
  $fields['node-committee-field_committee_members'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_committee_members',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'users' => array(
          'columns' => array(
            'target_id' => 'uid',
          ),
          'table' => 'users',
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
          'target_bundles' => array(),
        ),
        'target_type' => 'user',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'field_delimiter' => '',
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
            'links' => 1,
            'use_content_language' => 1,
            'view_mode' => 'tile',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'field_delimiter' => '',
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
          'weight' => '6',
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_committee_members',
      'label' => 'Members',
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
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-committee-field_committee_spokesman'.
  $fields['node-committee-field_committee_spokesman'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_committee_spokesman',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'users' => array(
          'columns' => array(
            'target_id' => 'uid',
          ),
          'table' => 'users',
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
          'target_bundles' => array(),
        ),
        'target_type' => 'user',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'field_delimiter' => '',
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
            'links' => 1,
            'use_content_language' => 1,
            'view_mode' => 'tile',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'field_delimiter' => '',
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
          'weight' => '4',
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_committee_spokesman',
      'label' => 'Spokesman',
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
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-committee-field_committee_url'.
  $fields['node-committee-field_committee_url'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_committee_url',
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
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'URL to the external source, e.g. the parliaments committe page.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(
            'field_delimiter' => '',
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
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(
            'field_delimiter' => '',
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
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_committee_url',
      'label' => 'Committee URL',
      'required' => 0,
      'settings' => array(
        'absolute_url' => 1,
        'attributes' => array(
          'class' => '',
          'configurable_class' => 0,
          'configurable_title' => 0,
          'rel' => '',
          'target' => '_blank',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'linkit' => array(
          'button_text' => 'Suchen',
          'enable' => 0,
          'profile' => '',
        ),
        'rel_remove' => 'default',
        'title' => 'value',
        'title_label_use_field_label' => 0,
        'title_maxlength' => '128',
        'title_value' => 'Weitere Informationen zum Ausschuss "[current-page:title]" auf bundestag.de',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-committee-field_committee_vice_chairman'.
  $fields['node-committee-field_committee_vice_chairman'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_committee_vice_chairman',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'users' => array(
          'columns' => array(
            'target_id' => 'uid',
          ),
          'table' => 'users',
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
          'target_bundles' => array(),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'user',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'field_delimiter' => '',
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
            'links' => 1,
            'use_content_language' => 1,
            'view_mode' => 'tile',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'field_delimiter' => '',
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
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_committee_vice_chairman',
      'label' => 'Vice Chairman',
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
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-committee-field_parliament'.
  $fields['node-committee-field_parliament'] = array(
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
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'field_delimiter' => '',
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
        'tile' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'field_delimiter' => '',
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
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
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
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-committee-field_teaser_image'.
  $fields['node-committee-field_teaser_image'] = array(
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
      'bundle' => 'committee',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'field_delimiter' => '',
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
          'weight' => '9',
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
            'field_delimiter' => '',
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
          'weight' => '9',
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
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
        'wysiwyg_insert' => 0,
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
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-committee-field_topics'.
  $fields['node-committee-field_topics'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_topics',
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
            'vocabulary' => 'topics',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'committee',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'field_delimiter' => '',
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
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tile' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'field_delimiter' => '',
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
          'weight' => '8',
        ),
      ),
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_topics',
      'label' => 'Topics',
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
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alternate Members');
  t('Body');
  t('Chairman');
  t('Committee URL');
  t('Members');
  t('Parliament');
  t('Spokesman');
  t('Teaser image');
  t('Topics');
  t('URL to the external source, e.g. the parliaments committe page.');
  t('Vice Chairman');

  return $fields;
}