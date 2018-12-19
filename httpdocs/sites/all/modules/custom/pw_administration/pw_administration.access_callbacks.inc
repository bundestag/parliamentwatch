<?php

/**
 * @file
 * access callbacks for page callbacks defined in PW Administration module
 */

use Drupal\pw_globals\PWUser;


/**
 * Access callback for Abgeordnetenwatch admin dashboard
 */
function pw_administration_dashboard_pagecallback_access() {
  $pwUser = new PWUser();

  if ($pwUser->hasRole(PWUser::ROLE_ADMINISTRATOR) ||
    $pwUser->hasRole(PWUser::ROLE_CONTENT_MANAGER) ) {
    return TRUE;
  }

  return FALSE;
}