<?php
/**
 * @file
 * pw_administration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pw_administration_user_default_permissions() {
  $permissions = array();

  // Exported permission: can reset user archive table.
  $permissions['can reset user archive table'] = array(
    'name' => 'can reset user archive table',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pw_userarchives',
  );

  return $permissions;
}
