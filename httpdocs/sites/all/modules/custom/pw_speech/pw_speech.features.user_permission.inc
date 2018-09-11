<?php
/**
 * @file
 * pw_speech.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pw_speech_user_default_permissions() {
  $permissions = array();

  // Exported permission: create speech content.
  $permissions['create speech content'] = array(
    'name' => 'create speech content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any speech content.
  $permissions['delete any speech content'] = array(
    'name' => 'delete any speech content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own speech content.
  $permissions['delete own speech content'] = array(
    'name' => 'delete own speech content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete terms in 50.
  $permissions['delete terms in 50'] = array(
    'name' => 'delete terms in 50',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any speech content.
  $permissions['edit any speech content'] = array(
    'name' => 'edit any speech content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own speech content.
  $permissions['edit own speech content'] = array(
    'name' => 'edit own speech content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit terms in 50.
  $permissions['edit terms in 50'] = array(
    'name' => 'edit terms in 50',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
