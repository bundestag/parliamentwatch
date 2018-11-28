<?php

/**
 * Admin related pages for user revisions and user archives
 */


/**
 * Form to edit an user revision. All the user revision edit logic is mostly taken
 * from the User Revision Edit module
 */
function pw_userarchives_user_revision_edit_form($form, &$form_state, $user_revision) {

  // Prepare loading the user profile form.
  form_load_include($form_state, 'inc', 'user', 'user.pages');

  // Populate form state.
  $form_state += form_state_defaults();

  // Rebuild the entire user profile form for our needs;
  // we can not use drupal_get_form() here, we need drupal_build_form()
  // without the final processing from drupal_process_form().
  $form = drupal_retrieve_form('user_profile_form', $form_state);
  drupal_prepare_form('user_profile_form', $form, $form_state);

  // Save the revision to the form.
  $form['#user_revision'] = $user_revision;

  $form['revision_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Revision information'),
    '#collapsible' => TRUE,
    '#attributes' => array(
      'class' => array('user-profile-form-revision-information'),
    ),
    '#weight' => 20,
    '#access' => user_access('choose user revisions'),
  );

  // Make log message editable.
  $form['revision_information']['log'] = array(
    '#type' => 'textarea',
    '#title' => t('Revision log message'),
    '#rows' => 4,
    '#description' =>
      t('Provide an explanation of the changes you are making. This will help other authors understand your motivations.'),
    '#default_value' => $user_revision->log,
  );

  $form['vid'] = array(
    '#type' => 'value',
    '#value' => $user_revision->vid,
  );
  $form['ip'] = array(
    '#type' => 'value',
    '#value' => ip_address(),
  );

  // Add a cancel button.
  $form['actions']['cancel'] = array(
    '#type'   => 'submit',
    '#value'  => t('Cancel'),
    '#access' => TRUE,
    '#weight' => 55,
    '#submit' => array('pw_userarchives_user_revision_edit_form_cancel_submit'),
    '#limit_validation_errors' => array(),
  );

  // Remove global user settings as we only edit the revision.
  unset($form['signature_settings']);
  unset($form['account']['status']);
  unset($form['account']['pass']);
  unset($form['account']['roles']);
  unset($form['timezone']);

  // Clear all callbacks to avoid editing the user and not the revision.
  unset($form['#submit']);
  $form['#submit'] = array('pw_userarchives_user_revision_edit_form_submit');

  return $form;
}

/**
 * Submit callback for edit revision form.
 */
function pw_userarchives_user_revision_edit_form_submit($form, &$form_state) {
  $user_revision = $form['#user_revision'];
  form_state_values_clean($form_state);

  // Update user_revision
  entity_form_submit_build_entity('user', $user_revision, $form, $form_state);
  _pw_userarchives_user_revision_edit_save($user_revision, $form_state['values']);
  pw_userarchives_cron($user_revision->uid);


  // add redirect just in case no destination is set
  $destination = drupal_get_destination();
  if ($destination["destination"] == current_path()) {
    $form_state['redirect'] = 'user/' . $user_revision->uid . '/revisions';
  }

  // Clear the cache because pages can contain revision information.
  cache_clear_all();

  watchdog(
    'user',
    "Modified {$user_revision->name} revision {$user_revision->vid}."
  );

  drupal_set_message(
    t('Updated revision %vid of %user.',
      array(
        '%vid' => $user_revision->vid,
        '%user' => $user_revision->name,
      )
    ),
    'status'
  );
}

/**
 * Submit callback for edit revision form cancel button.
 */
function pw_userarchives_user_revision_edit_form_cancel_submit($form, &$form_state) {
  $user_revision = $form['#user_revision'];

  // add redirect just in case no destination is set
  $destination = drupal_get_destination();
  if ($destination["destination"] == current_path()) {
    $form_state['redirect'] = 'user/' . $user_revision->uid . '/revisions';
  }
  else {
    $form_state['redirect'] = $destination["destination"];
  }
}
