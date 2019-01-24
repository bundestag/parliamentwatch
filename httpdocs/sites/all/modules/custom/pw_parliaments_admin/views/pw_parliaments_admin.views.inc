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
    'title' => t('Imports - Single imports'),
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


  $data['pw_parliaments_admin_imports']['type'] = array(
    'title' => t('Type'),
    'help' => t('The type'),
    'field' => array(
      'handler' => 'views_handler_field_import_type',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    )
  );


  $data['pw_parliaments_admin_imports']['status'] = array(
    'title' => t('Status'),
    'help' => t('The status'),
    'field' => array(
      'handler' => 'views_handler_field_import_status',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    )
  );


  // constituency datasets
  $data['pw_parliaments_admin_imports_constituencies_datasets']['table']['group'] = t('Constituency Dataset');
  $data['pw_parliaments_admin_imports_constituencies_datasets']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Imports - Constituency Dataset'),
    'help' => t('Table stores the constituency datasets from the CSV.'),
    'weight' => -10,
  );

  $data['pw_parliaments_admin_imports_constituencies_datasets']['id'] = array(
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

  $data['pw_parliaments_admin_imports_constituencies_datasets']['parliament'] = array(
    'title' => t('Parliament'),
    'help' => t('The parliament'),
    'relationship' => array(
      'base' => 'taxonomy_term_data',
      'base field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Parliament'),
    ),
  );


  $data['pw_parliaments_admin_imports_constituencies_datasets']['constituency'] = array(
    'title' => t('Constituency'),
    'help' => t('The name of the constituency'),
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


  $data['pw_parliaments_admin_imports_constituencies_datasets']['constituency_nr'] = array(
    'title' => t('Constituency nr'),
    'help' => t('The nr of the constituency'),
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

  $data['pw_parliaments_admin_imports_constituencies_datasets']['status'] = array(
    'title' => t('Status'),
    'help' => t('The status'),
    'field' => array(
      'handler' => 'views_handler_field_dataset_status',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_dataset_status',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'numeric' => TRUE,
    ),
  );


  $data['pw_parliaments_admin_imports_constituencies_datasets']['electoral_region'] = array(
    'title' => t('Electoral region'),
    'help' => t('The electoral region'),
    'relationship' => array(
      'base' => 'taxonomy_term_data',
      'base field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Electoral region'),
    ),
  );


  $data['pw_parliaments_admin_imports_constituencies_datasets']['area_code'] = array(
    'title' => t('Area code'),
    'help' => t('Area code'),
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



  $data['pw_parliaments_admin_imports_constituencies_datasets']['area_code_descriptor'] = array(
    'title' => t('Area code descriptor'),
    'help' => t('Area code descrptor'),
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


  $data['pw_parliaments_admin_imports_constituencies_datasets']['street'] = array(
    'title' => t('Street'),
    'help' => t('Street'),
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


  $data['pw_parliaments_admin_imports_constituencies_datasets']['errors'] = array(
    'title' => t('Constituency errors'),
    'help' => t('The errors'),
    'field' => array(
      'handler' => 'views_handler_field'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    )
  );

  $data['pw_parliaments_admin_imports_constituencies_datasets']['import'] = array(
    'title' => 'Import',
    'help' => t('The import the dataset belongs to'),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'relationship' => array(
      'title' => 'Import',
      'help' => t('The import the dataset belongs to'),
      'handler' => 'views_handler_relationship',
      'base' => 'pw_parliaments_admin_imports',
      'field' => 'id',
      'label' => 'Import',
    ),
  );


  // constituency datasets
  $data['pw_parliaments_admin_imports_constituencies_structured']['table']['group'] = t('Constituency Structured Data');
  $data['pw_parliaments_admin_imports_constituencies_structured']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Imports - Constituency Structured Data'),
    'help' => t('Table stores the structured data for constituency datasets from the CSV.'),
    'weight' => -10,
  );

  $data['pw_parliaments_admin_imports_constituencies_structured']['id'] = array(
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

  $data['pw_parliaments_admin_imports_constituencies_structured']['name'] = array(
    'title' => t('Constituency'),
    'help' => t('The name of the constituency'),
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

  $data['pw_parliaments_admin_imports_constituencies_structured']['field_constituency_nr'] = array(
    'title' => t('Constituency nr'),
    'help' => t('The nr of the constituency'),
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

  $data['pw_parliaments_admin_imports_constituencies_structured']['field_constituency_area_codes'] = array(
    'title' => t('Area codes'),
    'help' => t('Area codes'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    )
  );

  $data['pw_parliaments_admin_imports_constituencies_structured']['field_constituency_ac_descriptor'] = array(
    'title' => t('Area code descriptors'),
    'help' => t('Area code descriptors'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    )
  );

  $data['pw_parliaments_admin_imports_constituencies_structured']['field_constituency_street'] = array(
    'title' => t('Streets'),
    'help' => t('Streets'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    )
  );

  $data['pw_parliaments_admin_imports_constituencies_structured']['field_electoral_region'] = array(
    'title' => t('Electoral region'),
    'help' => t('The electoral region'),
    'relationship' => array(
      'base' => 'taxonomy_term_data',
      'base field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Electoral region'),
    ),
  );

  $data['pw_parliaments_admin_imports_constituencies_structured']['field_parliament'] = array(
    'title' => t('Parliament'),
    'help' => t('The parliament'),
    'relationship' => array(
      'base' => 'taxonomy_term_data',
      'base field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Parliament'),
    ),
  );


  $data['pw_parliaments_admin_imports_constituencies_structured']['import'] = array(
    'title' => 'Import',
    'help' => t('The import the structured data belongs to'),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'relationship' => array(
      'title' => 'Import',
      'help' => t('The import the dataset belongs to'),
      'handler' => 'views_handler_relationship',
      'base' => 'pw_parliaments_admin_imports',
      'field' => 'id',
      'label' => 'Import',
    ),
  );
  return $data;
}