<?php

/**
 * @file
 * Views related hooks for PW Parliaments Admin module
 */

/**
 * Implements hook_views_data().
 */
function pw_parliaments_admin_views_data() {
  $data = [];

  $data['pw_parliaments_admin_imports']['table']['group'] = t('PW Imports');
  $data['pw_parliaments_admin_imports']['table']['base'] = array(
    'field' => 'id',
    'title' => t('PW Imports'),
    'help' => t('Table stores the settings for each import.'),
    'weight' => -10,
  );

  $data['pw_parliaments_admin_imports']['parliament'] = array(
    'title' => t('Parliament id'),
    'help' => t('The parliament'),
    'relationship' => array(
      'base' => 'taxonomy_term_data',
      'base field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Parliament'),
    ),
  );

  $data['pw_parliaments_admin_imports']['file'] = array(
    'title' => t('CSV file'),
    'help' => t('CSV file'),
    'field' => array(
      'handler' => 'views_handler_field_file'
    ),
    'relationship' => array(
      'base' => 'file_managed',
      'base field' => 'fid',
      'handler' => 'views_handler_relationship',
      'label' => t('CSV file'),
    ),
  );

  $data['pw_parliaments_admin_imports']['file'] = array(
    'title' => t('Import type'),
    'help' => t('Import type'),
    'field' => array(
      'handler' => 'views_handler_field_import_type',
      'click sortable' => TRUE,
    )
  );
  return $data;
}