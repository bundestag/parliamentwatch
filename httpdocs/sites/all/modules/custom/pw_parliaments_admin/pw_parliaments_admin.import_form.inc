<?php

/**
 * @file
 * All related functionf for add/ edit import form
 */


/**
 * Form builder for add and edit import entity
 *
 * @param $form
 * @param $form_state
 * @param \Drupal\pw_parliaments_admin\Entity\Import|NULL $import
 * Optional the Import class of the import edited
 *
 * @return array
 */
function pw_parliaments_admin_import_form($form, &$form_state, \Drupal\pw_parliaments_admin\Entity\Import $import = NULL) {
  $form = [];

  $form_state['storage']['import'] = $import;

  $vocabulary = taxonomy_vocabulary_machine_name_load('parliaments');
  $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
  $parliaments_options = [];
  foreach ($terms as $tid => $term) {
    $parliaments_options[$tid] = $term->name;
  }

  $form['label'] = [
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#maxlength' => 255,
    '#required' => TRUE
  ];

  $form['parliament'] = [
    '#type' => 'select',
    '#title' => t('Parliament'),
    '#options' => $parliaments_options,
    '#required' => TRUE
  ];

  $form['type'] = [
    '#type' => 'select',
    '#title' => t('Type of data to import'),
    '#options' => \Drupal\pw_parliaments_admin\Entity\Import::getPossibleImportsOptions(),
    '#required' => TRUE
  ];

  $form['file'] = [
    '#type' => 'managed_file',
    '#title' => t('Choose the CSV'),
    '#upload_location' => variable_get('picture_upload_location'),
    '#upload_validators' => array(
      'file_validate_extensions' => array('csv')
    ),
    '#required' => TRUE
  ];

  $form['actions'] = [
    '#ytpe' => 'actions'
  ] ;
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Submit')
  ];

  return $form;
}


/**
 * Import add/ edit form validator
 *
 * @param $form
 * @param $form_state
 */
function pw_parliaments_admin_import_form_validate(&$form, &$form_state) {
  if (isset($form_state["input"]["file"]["fid"]) && $form_state["input"]["file"]["fid"] == 0) {
    $file = file_save_upload('file');
    if (!$file) {
      form_set_error('file', t('It was not possible to upload the CSV file'));
    }
    else {
      $form_state['values']['file'] = $file;
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
  try {
    /** @var \Drupal\pw_parliaments_admin\Entity\Import $import */
    $import = new \Drupal\pw_parliaments_admin\Entity\Import();
    $import->setLabel($form_state['values']['label']);
    $import->setParliamentId($form_state['values']['parliament']);
    $import->setFile($form_state['values']['file']);
    $import->setType($form_state['values']['type']);
    $import->save();
    drupal_set_message('The import was successfully saved');
    $form_state['redirect'] = 'admin/abgeordnetenwatch/imports/'. $import->getId();
  }
  catch (\Exception $e) {
    drupal_set_message('An error occured: '. $e->getMessage(), 'error');
  }

}