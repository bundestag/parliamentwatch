<?php
/**
 * @file
 * pw_blog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_blog_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|blogpost|form';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blogpost';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta-Daten',
    'weight' => '1',
    'children' => array(
      0 => 'field_blogpost_categories',
      1 => 'field_politician',
      2 => 'field_topics',
      3 => 'field_blogpost_license',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_meta|node|blogpost|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Meta-Daten');

  return $field_groups;
}
