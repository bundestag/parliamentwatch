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
 * @param \Drupal\pw_parliaments_admin\Entity\Import $import
 *
 * @return array|mixed
 */
function pw_parliaments_admin_editorm_pagecallback(\Drupal\pw_parliaments_admin\Entity\Import $import) {
  module_load_include('inc', 'pw_parliaments_admin', 'pw_parliaments_admin.import_form');
  $form = drupal_get_form('pw_parliaments_admin_import_form', $import);
  return $form;
}


function pw_parliaments_admin_view_pagecallback(\Drupal\pw_parliaments_admin\Entity\Import $import) {

  return 'hallo';
}
