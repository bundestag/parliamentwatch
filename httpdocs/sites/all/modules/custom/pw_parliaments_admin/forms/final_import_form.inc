<?php

/**
 * @file
 * Functions for starting the final import form
 */

use Drupal\pw_parliaments_admin\Import\Import;


/**
 *
 * Form builder function for starting final import form
 * @param $form
 * @param $form_state
 * @param \Import $import
 *
 * @return array
 */
function pw_parliaments_admin_start_constituency_final_import($form, &$form_state, Import $import) {
  $form = [];
  $form_state['storage']['import'] = $import;
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Finalen Wahlkreis-Import starten'
  ];

  return $form;
}


/**
 * Submit handler for final import form
 * @param $form
 * @param $form_state
 */
function pw_parliaments_admin_start_constituency_final_import_submit(&$form, &$form_state) {
  $import = $form_state['storage']['import'];
  $form_state['redirect'] = 'admin/abgeordnetenwatch/imports/'. $import->getId();

  $batch = [
    'title'      => t('Importing data'),
    'operations' => [
      [
        '\Drupal\pw_parliaments_admin\Import\Batch\BatchFinalImport::importData',
        [$import],
      ],
    ],
    'finished'   => '\Drupal\pw_parliaments_admin\Import\Batch\BatchFinalImport::finished',
  ];

  batch_set($batch);
}