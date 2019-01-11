<?php


/**
 * @file
 * Hooks related to Views module for PW Administration module
 */

/**

 * Implements hook_views_data().

 */

/**
 * Implements hook_views_data().
 */
function pw_administration_views_data() {
  $data = array();

  $data['views']['pw_administration_create_new'] = [
    'title' => t('PW Administration - Create new'),
    'help' => t('Offers a "Create new ..." link on administration pages.'),
    'area' => [
      'handler' => 'pw_administration_views_handler_area_create_new',
    ],
  ];


  return $data;
}