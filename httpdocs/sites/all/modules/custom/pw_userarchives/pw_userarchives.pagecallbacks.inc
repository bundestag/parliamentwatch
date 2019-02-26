<?php

/**
 * @file
 * Page callbacks for PW Userarchive module
 */


/**
 * An archive profile
 */
function pw_userarchives_archive_profile($account, $vid) {
  return user_revision_show($account, $vid);
}