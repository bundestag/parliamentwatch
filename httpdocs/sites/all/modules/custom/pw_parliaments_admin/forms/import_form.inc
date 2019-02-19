<?php

use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\Status\ImportStatus;

/**
 * @file
 * Functions for the edit/ add a single import form
 */

/**
 * Form builder for add and edit import entity
 *
 * @param $form
 * @param $form_state
 * @param \Drupal\pw_parliaments_admin\Import\Import|NULL $import
 * Optional the Import class of the import edited
 *
 * @return array
 */
function pw_parliaments_admin_import_form($form, &$form_state, Import $import = NULL) {
  $form = [];

  $vocabulary = taxonomy_vocabulary_machine_name_load('parliaments');
  $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
  $parliaments_options = [];
  foreach ($terms as $tid => $term) {
    $parliaments_options[$tid] = $term->name;
  }

  $importDone = FALSE;
  if ($import !== NULL && $import->getStatus() != ImportStatus::CREATED) {
    $importDone = TRUE;
  }

  $form['label'] = [
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#maxlength' => 255,
    '#required' => TRUE,
    '#default_value' => ($import !== NULL) ? $import->getLabel() : ''
  ];

  $form['parliament'] = [
    '#type' => 'select',
    '#title' => t('Parliament'),
    '#options' => $parliaments_options,
    '#required' => TRUE,
    '#default_value' => ($import !== NULL) ? $import->getParliamentId() : '',
    '#disabled' => $importDone
  ];

  $form['type'] = [
    '#type' => 'select',
    '#title' => t('Type of data to import'),
    '#options' => \Drupal\pw_parliaments_admin\Import\ImportTypes::getPossibleOptions(),
    '#required' => TRUE,
    '#default_value' => ($import !== NULL) ? $import->getType() : '',
    '#disabled' => $importDone
  ];

  $form['file'] = [
    '#type' => 'managed_file',
    '#title' => t('Choose the CSV'),
    '#upload_location' => variable_get('picture_upload_location'),
    '#upload_validators' => array(
      'file_validate_extensions' => array('csv')
    ),
    '#required' => TRUE,
    '#default_value' => ($import !== NULL) ? $import->getFileId() : '',
    '#disabled' =>  $importDone
  ];

  $form['actions'] = [
    '#ytpe' => 'actions'
  ] ;
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Submit')
  ];

  $form_state['storage']['import_original'] = $import;

  return $form;
}


/**
 * Import add/ edit form validator
 *
 * @param $form
 * @param $form_state
 */
function pw_parliaments_admin_import_form_validate(&$form, &$form_state) {
  if ($form_state['values']['file'] !== 0 && isset($form_state["input"]["file"]["fid"]) && $form_state["input"]["file"]["fid"] == 0) {
    $file = file_save_upload('file');
    if (!$file) {
      form_set_error('file', t('It was not possible to upload the CSV file'));
    }
    else {
      $form_state['values']['file'] = $file;
    }
  }

  if ($form_state['values']['file'] !== 0) {
    $file_id = NULL;
    if (is_object($form_state['values']['file'])) {
      $file_id = $form_state['values']['file']->fid;
    }
    else if(is_numeric($form_state['values']['file'])) {
      $file_id = $form_state['values']['file'];
    }

    // update or instantiate the Import class
    if (isset($form_state['storage']['import_original'])) {
      $import = clone($form_state['storage']['import_original']);
      $import->setLabel($form_state['values']['label']);
    }
    else {
      /** @var \Drupal\pw_parliaments_admin\Import\Import $import */
      $import = new Import($form_state['values']['label'], $form_state['values']['parliament'], $file_id, $form_state['values']['type']);
    }

    // store the instantiated or created import
    $form_state['storage']['import'] = $import;

    // validate the CSV to assure that all required fields are found
    if (!$import->AllRequiredFieldsExist()) {
      /** @var \Drupal\pw_parliaments_admin\CsvParser $csvParser */
      $csvHeader = $import->getCSVParser()->getHeader();
      $required_fields = $import->getRequiredFieldsForCSV();
      $missing_fields = [];
      foreach ($required_fields as $required_field) {
        if (!in_array($required_field, $csvHeader)) {
          $missing_fields[] = $required_field;
        }
      }
      $error_message = 'The following fields are required for import: '. implode(', ', $missing_fields);
      form_set_error('file', $error_message);
    }
  }

}


/**
 * Import add/ edit form submit handler
 *
 * @param $form
 * @param $form_state
 */
function pw_parliaments_admin_import_form_submit(&$form, &$form_state) {
  $transaction = db_transaction();
  try {
    /** @var \Drupal\pw_parliaments_admin\Import\Import $import */
    $import = $form_state['storage']['import'];
    $import->save();
    drupal_set_message('The import was successfully saved');
    $form_state['redirect'] = 'admin/abgeordnetenwatch/imports/'. $import->getId();

    // we always start to Batch import datasets when the import was created
    $batchImport = ($import->getStatus() == ImportStatus::CREATED);
    if ($batchImport) {
      $batch = [
        'title'      => t('Importing data'),
        'operations' => [
          [
            '\Drupal\pw_parliaments_admin\Import\Batch\BatchCreateDataSet::importData',
            [$import],
          ],
        ],
        'finished'   => '\Drupal\pw_parliaments_admin\Import\Batch\BatchCreateDataSet::finished',
      ];
      batch_set($batch);
    }
  }
  catch (\Exception $e) {
    $transaction->rollback();
    watchdog_exception('pw_parliaments_admin', $e);
    drupal_set_message('An error occured: '. $e->getMessage(), 'error');
  }

}
