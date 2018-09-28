<?php
/**
 * @file
 * pw_gdpr.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pw_gdpr_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'piwik_codesnippet_before';
  $strongarm->value = '_paq.push([\'disableCookies\']);';
  $export['piwik_codesnippet_before'] = $strongarm;

  return $export;
}
