<?php

use Drupal\pw_parliaments_admin\Import\Import;

/**
 * @file
 * Functions related to the "start structuring data" form
 */


/**
 * Form builder function for "start structuring data" form
 * @param $form
 * @param $form_state
 * @param \Drupal\pw_parliaments_admin\Import\Import $import
 *
 * @return array
 */
function pw_parliaments_admin_start_constituency_structuring($form, &$form_state, Import $import) {
  $form = [];
  $form_state['storage']['import'] = $import;
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Daten für Import struktuieren'
  ];

  return $form;
}


/**
 * Submit handler for "start structuring data" form
 * @param $form
 * @param $form_state
 */
function pw_parliaments_admin_start_constituency_structuring_submit(&$form, &$form_state) {
  /** @var \Drupal\pw_parliaments_admin\Import\Import $import */
  $import = $form_state['storage']['import'];
  $form_state['redirect'] = 'admin/abgeordnetenwatch/imports/'. $import->getId();
  $csvParser = $import->getCSVParser();
  $datasets = $csvParser->getDatasets();
  if (!empty($datasets)) {
    $batch = [
      'title'      => t('Importing data'),
      'operations' => [
        [
          '\Drupal\pw_parliaments_admin\Import\Batch\BatchStructureData::importData',
          [$import],
        ],
      ],
      'finished'   => '\Drupal\pw_parliaments_admin\Import\Batch\BatchStructureData::finished',
    ];

    batch_set($batch);
  }

}
