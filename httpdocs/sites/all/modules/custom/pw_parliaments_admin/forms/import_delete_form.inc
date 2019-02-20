<?php

use Drupal\pw_parliaments_admin\Import\Import;

/**
 * @file
 * Delete a single import
 */


function pw_parliaments_admin_deleteform($form, &$form_state, Import $import) {
  $form_state['storage']['import'] = $import;
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Wirklich löschen'
  ];

  return $form;
}


function pw_parliaments_admin_deleteform_submit(&$form, &$form_state) {
  /** @var Import $import */
  $import = $form_state['storage']['import'];
  $import->delete();
  $form_state['redirect'] = 'admin/abgeordnetenwatch/wahlen-parlamente/imports';
}