<?php
/**
 * @file
 * pw_profiles.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_profiles_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_managed_content|user|user|form';
  $field_group->group_name = 'group_managed_content';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Managed Content',
    'weight' => '12',
    'children' => array(
      0 => 'field_user_gender',
      1 => 'field_user_question_form_closed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-managed-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_managed_content|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_admin|user|user|form';
  $field_group->group_name = 'group_user_admin';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Admin Settings',
    'weight' => '14',
    'children' => array(
      0 => 'field_user_external_url',
      1 => 'field_user_roles_for_view_mode_s',
      2 => 'field_user_data_url',
      3 => 'ckeditor',
      4 => 'redirect',
      5 => 'timezone',
      6 => 'xmlsitemap',
      7 => 'locale',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Admin Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-user-admin field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_user_admin|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_affiliation|user|user|form';
  $field_group->group_name = 'group_user_affiliation';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Political Affiliation',
    'weight' => '9',
    'children' => array(
      0 => 'field_user_parliament',
      1 => 'field_user_party',
      2 => 'field_user_political_roles',
      3 => 'field_user_valid',
      4 => 'field_user_election_result',
      5 => 'field_user_constituency_won',
      6 => 'field_user_list_won',
      7 => 'field_user_fraction',
      8 => 'field_user_joined',
      9 => 'field_user_retired',
      10 => 'field_user_retired_reason',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Political Affiliation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-user-affiliation field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_user_affiliation|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_personal_data|user|user|form';
  $field_group->group_name = 'group_user_personal_data';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Data',
    'weight' => '8',
    'children' => array(
      0 => 'field_user_birthday',
      1 => 'field_user_childs',
      2 => 'field_user_job_skills',
      3 => 'field_user_marriage_status',
      4 => 'field_user_pseudonym',
      5 => 'field_user_address',
      6 => 'field_user_constituency',
      7 => 'field_user_education',
      8 => 'field_user_list_position',
      9 => 'field_user_age',
      10 => 'field_user_phone',
      11 => 'field_user_public_mail',
      12 => 'field_user_list',
      13 => 'field_user_mobile',
      14 => 'field_user_died',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-user-personal-data field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_user_personal_data|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_about|user|user|form';
  $field_group->group_name = 'group_user_premium_about';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'About me',
    'weight' => '18',
    'children' => array(
      0 => 'field_user_about',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'About me',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-user-premium-about field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_user_premium_about|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_fields|user|user|form';
  $field_group->group_name = 'group_user_premium_fields';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Premium Fields',
    'weight' => '11',
    'children' => array(
      0 => 'group_user_premium',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Premium Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => ' group-user-premium-fields field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_user_premium_fields|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_gallery|user|user|form';
  $field_group->group_name = 'group_user_premium_gallery';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'Image Gallery',
    'weight' => '20',
    'children' => array(
      0 => 'field_user_image_gallery',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-user-premium-gallery field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_premium_gallery|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_goals|user|user|form';
  $field_group->group_name = 'group_user_premium_goals';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'Political Goals',
    'weight' => '21',
    'children' => array(
      0 => 'field_user_political_goals',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-user-premium-goals field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_premium_goals|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_links|user|user|form';
  $field_group->group_name = 'group_user_premium_links';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'External Links',
    'weight' => '19',
    'children' => array(
      0 => 'field_user_links_more',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-user-premium-links field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_premium_links|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium|user|user|form';
  $field_group->group_name = 'group_user_premium';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium_fields';
  $field_group->data = array(
    'label' => 'Premium fields',
    'weight' => '8',
    'children' => array(
      0 => 'group_user_premium_about',
      1 => 'group_user_premium_gallery',
      2 => 'group_user_premium_goals',
      3 => 'group_user_premium_links',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-user-premium field-group-tabs',
      ),
    ),
  );
  $field_groups['group_user_premium|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About me');
  t('Admin Settings');
  t('External Links');
  t('Image Gallery');
  t('Managed Content');
  t('Personal Data');
  t('Political Affiliation');
  t('Political Goals');
  t('Premium Fields');
  t('Premium fields');

  return $field_groups;
}
