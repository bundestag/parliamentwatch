<?php

/**
 * @file
 * Include file storing all page callbacks define in PW Imports module
 */

use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\Controller\ImportDetailpageController;



/**
 * Page callback for add new import form
 *
 * @return array|mixed
 */
function pw_parliaments_admin_addform_pagecallback() {
  module_load_include('inc', 'pw_parliaments_admin', 'forms/import_form');
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
function pw_parliaments_admin_editform_pagecallback(Import $import) {
  module_load_include('inc', 'pw_parliaments_admin', 'forms/import_form');
  $form = drupal_get_form('pw_parliaments_admin_import_form', $import);
  drupal_set_title($import->getLabel() .' bearbeiten');
  return $form;
}


/**
 *
 * Page callback for viewing a single import detail page
 *
 * @param \Drupal\pw_parliaments_admin\Import\Import $import
 *
 * @return array
 */
function pw_parliaments_import_pagecallback(Import $import) {
  $output = [];
  $title = 'Import: '. $import->getLabel();
  drupal_set_title($title);
  $controller = new ImportDetailpageController($import);
  $output['hint']['#markup'] = $controller->getTextMarkup();

  if ($controller->nextStep()) {
    $output['form'] = $controller->getForm();
  }

  $output['view']['#markup'] = $controller->getView();

  return $output;
}


/**
 * Page callback for datasets overview. This is used to show the original
 * datasets when structured data was created
 *
 * @param \Drupal\pw_parliaments_admin\Import\Import $import
 */
function pw_parliaments_import_pagecallback_datasets(Import $import) {
  $output = [];
  $title = 'Import: '. $import->getLabel() .' - Datensätze';
  drupal_set_title($title);

  $view_name = $import->getImportTypeClass()->getViewName();
  $views = views_get_view($view_name);
  if ( is_object($views) ) {
    $views->set_display('default');
    $views->set_arguments([$import->getId()]);
    $views->pre_execute();
    $output['view']['#markup'] = $views->render('default');
  }

  return $output;
}


/**
 * Page callback for delete import confirmation form
 *
 * @param \Drupal\pw_parliaments_admin\Import\Import $import
 *
 * @return array|mixed
 */
function pw_parliaments_admin_deleteform_pagecallback(Import $import) {
  module_load_include('inc', 'pw_parliaments_admin', 'forms/import_delete_form');
  $form = drupal_get_form('pw_parliaments_admin_deleteform', $import);
  drupal_set_title($import->getLabel() .' löschen');
  return $form;
}