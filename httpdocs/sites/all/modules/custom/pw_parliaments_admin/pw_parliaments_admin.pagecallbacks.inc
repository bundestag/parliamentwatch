<?php

/**
 * @file
 * Include file storing all page callbacks define in PW Imports module
 */


/**
 * Page callback for add new import form
 *
 * @return array|mixed
 */
function pw_parliaments_admin_addform_pagecallback() {
  module_load_include('inc', 'pw_parliaments_admin', 'pw_parliaments_admin.import_form');
  $form = drupal_get_form('pw_parliaments_admin_import_form');
  return $form;
}


/**
 * Page callback for edit import form
 *
 * @param \Drupal\pw_parliaments_admin\Import\Import $import
 *
 * @return array|mixed
 */
function pw_parliaments_admin_editorm_pagecallback(\Drupal\pw_parliaments_admin\Import\Import $import) {
  $form = drupal_get_form('pw_parliaments_admin_import_form', $import);

  drupal_set_title($import->getLabel() .' bearbeiten');
  return $form;
}


function pw_parliaments_admin_view_pagecallback(\Drupal\pw_parliaments_admin\Import\Import $import) {
  drupal_set_title('Import: '. $import->getLabel());
  $output =[];

  $output['info'] = [
    '#markup' => 'Hallo'
  ];


  $output['form'] = drupal_get_form('pw_parliaments_admin_start_import', $import);
  return $output;
}


function pw_parliaments_admin_start_import($form, &$form_state, \Drupal\pw_parliaments_admin\Import\Import $import) {
  $form = [];
  $form_state['storage']['import'] = $import;
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Import starten'
  ];

  return $form;
}

function pw_parliaments_admin_start_import_submit(&$form, &$form_state) {
  /** @var \Drupal\pw_parliaments_admin\Import\Import $import */
  $import = $form_state['storage']['import'];

  $csvParser = $import->getCSVParser();
  $datasets = $csvParser->getDatasets();
  $transaction = db_transaction();
  try {
    if (!empty($datasets)) {
      $batch = [
        'title'      => t('Importing data'),
        'operations' => [
          [
            '\Drupal\pw_parliaments_admin\BatchCreatePreEntity::importData',
            [$import],
          ],
        ],
        'finished'   => '\Drupal\pw_parliaments_admin\BatchCreatePreEntity::finished',
      ];

      batch_set($batch);
    }
  }
  catch(\Exception $e) {
    $transaction->rollback();
    watchdog_exception('pw_parliaments_admin', $e);
    drupal_set_message('It was not possible to create the import data sets due to an error: '. $e->getMessage());
  }
}