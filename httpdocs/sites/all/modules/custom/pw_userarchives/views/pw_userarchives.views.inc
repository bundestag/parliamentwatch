<?php

/**
 * Views integration for user archive data
 */

/**
 * Implements hook_views_data()
 */
function pw_userarchives_views_data() {

  $data['user_archive_cache']['table']['group']  = t('PW User archive');
  $data['user_archive_cache']['table']['base'] = array(
    'field' => 'vid',
    'title' => t('PW User archive'),
    'help' => t('Entries for users into user archive cache table.'),
  );

  $data['user_archive_cache']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'user_revision' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

  $data['user_archive_cache']['vid'] = array(
    'title' => t('Vid'),
    'help' => t('The revision ID of the user revision.'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'views_handler_field_user'
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'user_revision',
      'base field' => 'vid',
      'title' => t('User revision'),
      'label' => t('Get the user revision from an user archive entry.'),
    ),
  );

  $data['user_archive_cache']['uid'] = array(
    'title' => t('Uid'),
    'help' => t('The uid field of the user archive cache table'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'title' => t('User'),
      'label' => t('Get all user archive entries from an user.'),
    ),
  );

  $data['user_archive_cache']['user_name'] = array(
    'title' => t('User name'),
    'help' => t('The user name.'),
    'field' => array(
      'handler' => 'views_handler_field_user_name',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['user_archive_cache']['user_role'] = array(
    'title' => t('User role'),
    'help' => t('The user role.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_archive_role',
    )
  );

  $data['user_archive_cache']['parliament_name'] = array(
    'title' => t('Parliament name'),
    'help' => t('The parliament name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['user_archive_cache']['fraction_name'] = array(
    'title' => t('Fraction name'),
    'help' => t('The fraction name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['user_archive_cache']['question_form_open'] = array(
    'title' => t('Question form open'),
    'help' => t('Question form open.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean'
    ),
    'filter' => array(
      'handler'=> 'views_handler_filter_boolean_operator'
    )
  );


  $data['user_archive_cache']['link_to_public_profile'] = array(
    'field' => array(
      'title' => t('Link to public profile'),
      'help' => t('Link to the public profile - may be the archived version of a profile'),
      'handler' => 'views_handler_field_user_archive_profile_link'
    )
  );

  // Adds edit revision link.
  $data['user_revision']['edit_revision'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the revision.'),
      'handler' => 'views_handler_field_user_revision_link_edit',
    ),
  );


  return $data;
}
