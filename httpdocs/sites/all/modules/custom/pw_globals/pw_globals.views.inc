<?php


/**
 * Implements hook_views_data_alter().
 */
function pw_globals_views_data_alter(&$data) {
  $data['taxonomy_term_data']['area_code_descriptor'] = array(
    'title' => t('Area code descriptor'),
    'help' => t('The area code descriptor suitable for a single area code.'),
    'field' => array(
      'handler' => 'views_handler_field_area_code_descriptor'
    )
  );
}
