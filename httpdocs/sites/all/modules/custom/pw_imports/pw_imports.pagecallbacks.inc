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
function pw_imports_addform_pagecallback() {
  module_load_include('inc', 'pw_imports', 'pw_imports.import_form');
  $form = drupal_get_form('pw_imports_import_form');
  return $form;
}


/**
 * Page callback for edit import form
 *
 * @param \Drupal\pw_imports\Import\Import $import
 *
 * @return array|mixed
 */
function pw_imports_editorm_pagecallback(\Drupal\pw_imports\Import\Import $import) {
  module_load_include('inc', 'pw_imports', 'pw_imports.import_form');
  $form = drupal_get_form('pw_imports_import_form', $import);
  return $form;
}


function pw_imports_view_pagecallback(\Drupal\pw_imports\Import\Import $import) {

  return 'hallo';
}
