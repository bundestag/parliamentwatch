<?php

/**
 * @file
 * Include file storing all page callbacks define in PW Imports module
 */

use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\Status\ImportStatus;


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
function pw_parliaments_admin_editorm_pagecallback(Import $import) {
  $form = drupal_get_form('pw_parliaments_admin_import_form', $import);

  drupal_set_title($import->getLabel() .' bearbeiten');
  return $form;
}


function pw_parliaments_import_pagecallback(Import $import) {
  $output = [];
  $title = 'Import: '. $import->getLabel();
  drupal_set_title($title);

  switch ($import->getStatus()) {
    case ImportStatus::OK:
      $output['hint']['#markup'] = '<div style="color: green; font-weight: bold;"><p>Die Validierung der Datensätze ergab keine Probleme. Du kannst die Datensätze hier noch einmal prüfen und mit dem Import der Datensätze fortfahren.</p></div>
<p>Im nächsten Schritt werden die Wahlkreise in die Datenstruktur umgeformt, wie sie für das Portal benötigt wird. Hier besteht noch einmal die Möglichkeit zu prüfen, ob die in einem letzten Schritt dann erstellten Wahlkreise den erwarteten Wahlkreisen entsprechen werden. </p>';

      $output['form1'] = drupal_get_form('pw_parliaments_admin_start_constituency_structuring', $import);

      // list the data sets or pre entities
      $view_name = 'pw_administration_imports_constituency_datasets';
      break;
    case ImportStatus::FAILED:
      $output['hint']['#markup'] = '<div style="color: red; font-weight: bold;"><p>Die Validierung der Datensätze entdeckte einige Fehler in den Datensätzen. Bitte prüfe die Datensätze und erstelle einen neuen Import. Dazu kannst Du diese Datensätze mit den Fehlermeldungen exportieren und weiter bearbeiten.</p>
<p>Dieser Import wird in spätestens einem Monat gelöscht.</p></div>';
      $view_name = 'pw_administration_imports_constituency_datasets';
      break;
    case ImportStatus::DATA_STRUCTURED_FAILED:
      $output['hint']['#markup'] = '<div style="color: red; font-weight: bold;"><p>Bei der Strukturierung der Datensätze sind Fehler aufgetreten. Bitte prüfe die Datensätze und erstelle einen neuen Import. Dazu kannst Du diese Datensätze mit den Fehlermeldungen exportieren und weiter bearbeiten.</p>
<p>Dieser Import wird in spätestens einem Monat gelöscht.</p></div>';
      // list the pre datasets
      $view_name = 'pw_administration_imports_constituency_datasets';
    case ImportStatus::DATA_STRUCTURED_OK:
      $output['hint']['#markup'] = '<div style="color: green; font-weight: bold;"><p>Die Strukturierung der Datensätze scheint ohne Probleme funktioniert zu haben. Du kannst die Daten, so wie sie im nächsten Schritt erstellt werden dürften, hier noch einmal prüfen und mit dem Import der Datensätze fortfahren.</p></div>
<p>Im nächsten Schritt werden die Wahlkreise importiert. </p>';

      $output['form'] = drupal_get_form('pw_parliaments_admin_start_constituency_final_import', $import);

      // list the pre entities
      $view_name = 'pw_administration_imports_constituency_structured_data';
      break;
    case ImportStatus::IMPORT_FAILED:
      $output['hint']['#markup'] = '<div style="color: red; font-weight: bold;"><p>Beim Import der Daten scheint etwas schief gelaufen zu sein.</p></div>
<p>Prüfe die Fehlermeldungen und versuche es dann einfach noch einmal. </p>';

      $output['form'] = drupal_get_form('pw_parliaments_admin_start_constituency_final_import', $import);

      // list the pre entities
      $view_name = 'pw_administration_imports_constituency_structured_data';
      break;
    case ImportStatus::IMPORTED:
      $output['hint']['#markup'] = '<div style="color: green; font-weight: bold;"><p>Der Import der Daten ist abgeschlossen.</p></div>
<p>Prüfe die Fehlermeldungen und versuche es dann einfach noch einmal. </p>';

      // list the pre entities
      $view_name = 'pw_administration_imports_constituency_structured_data';
      break;
  }

  $views = views_get_view($view_name);
  if ( is_object($views) ) {
    $views->set_display('default');
    $views->set_arguments([$import->getId()]);
    $views->pre_execute();
    $output['view']['#markup'] = $views->render('default');
  }
  drupal_set_title($title);


  return $output;
}


function pw_parliaments_admin_start_constituency_structuring($form, &$form_state, Import $import) {
  $form = [];
  $form_state['storage']['import'] = $import;
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Daten für Import struktuieren'
  ];

  return $form;
}

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
          '\Drupal\pw_parliaments_admin\BatchStructureData::importData',
          [$import],
        ],
      ],
      'finished'   => '\Drupal\pw_parliaments_admin\BatchStructureData::finished',
    ];

    batch_set($batch);
  }

}


function pw_parliaments_import_pagecallback_datasets(Import $import) {
  $output = [];
  $title = 'Import: '. $import->getLabel() .' - Datensätze';
  drupal_set_title($title);

  $view_name = 'pw_administration_imports_constituency_datasets';
  $views = views_get_view($view_name);
  if ( is_object($views) ) {
    $views->set_display('default');
    $views->set_arguments([$import->getId()]);
    $views->pre_execute();
    $output['view']['#markup'] = $views->render('default');
  }
}


function pw_parliaments_admin_start_constituency_final_import($form, &$form_state, Import $import) {
  $form = [];
  $form_state['storage']['import'] = $import;
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Finalen Wahlkreis-Import starten'
  ];

  return $form;
}


function pw_parliaments_admin_start_constituency_final_import_submit(&$form, &$form_state) {
  $import = $form_state['storage']['import'];
  $form_state['redirect'] = 'admin/abgeordnetenwatch/imports/'. $import->getId();

  $batch = [
    'title'      => t('Importing data'),
    'operations' => [
      [
        '\Drupal\pw_parliaments_admin\BatchFinalImport::importData',
        [$import],
      ],
    ],
    'finished'   => '\Drupal\pw_parliaments_admin\BatchFinalImport::finished',
  ];

  batch_set($batch);
}