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

  $data['pw_parliaments_admin_imports']['id'] = array(
    'title' => t('Id'),
    'help' => t('The id'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    )
  );

  $data['pw_parliaments_admin_imports']['label'] = array(
    'title' => t('Label'),
    'help' => t('The label'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    )
  );

  $data['pw_parliaments_admin_imports']['parliament'] = array(
    'title' => t('Parliament'),
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
      'entity type' => 'file',
      'handler' => 'views_handler_relationship',
      'label' => t('CSV file'),
    ),
  );


  return $data;
}