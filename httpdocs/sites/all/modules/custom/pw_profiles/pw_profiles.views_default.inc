<?php
/**
 * @file
 * pw_profiles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_profiles_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'politicians';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Politicians';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Politicians Overview';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Politiker pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 20, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle anzeigen -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'field_user_constituency' => 'field_user_constituency',
    'field_user_commitee' => 'field_user_commitee',
    'field_user_questions_get' => 'field_user_questions_get',
    'field_user_answers_give' => 'field_user_answers_give',
    'field_user_address_locality' => 'field_user_address_locality',
    'rid' => 'rid',
    'field_user_list_position' => 'field_user_list_position',
    'edit_node' => 'edit_node',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_list_position';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_party' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_parliament' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_constituency' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_commitee' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_questions_get' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_answers_give' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_list_position' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_lname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Feld: Stapelverarbeitungen: Benutzer */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pw_login_once_send_mail_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Feld: Benutzer: Partei */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Benutzer: Parlament */
  $handler->display->display_options['fields']['field_user_parliament']['id'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['field'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['delta_offset'] = '0';
  /* Feld: Benutzer: Wahlkreis */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Benutzer: Adresse - Ort (z. B. Stadt) */
  $handler->display->display_options['fields']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['label'] = 'Ort';
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Feld: Benutzer: Listenposition */
  $handler->display->display_options['fields']['field_user_list_position']['id'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['table'] = 'field_data_field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['field'] = 'field_user_list_position';
  /* Feld: Benutzer: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'hidden';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'hidden';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  /* Sortierkriterien: Benutzer: Erstellungsdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator_id'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['label'] = 'Vorname';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['description'] = 'Suche nach Vornamen.';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['identifier'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator_id'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['label'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['description'] = 'Suche nach Nachnamen.';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['identifier'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    181527986 => '181527986',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = TRUE;
  /* Filterkriterium: Benutzer: E-Mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['description'] = 'Suche nach E-Mail-Adressen.';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer: Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Partei';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['description'] = 'Suche nach Parteien.';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['identifier'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_party_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Benutzer: Parlament (field_user_parliament) */
  $handler->display->display_options['filters']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_parliament_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator_id'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['description'] = 'Suche nach Parlamenten.';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['identifier'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_parliament_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_parliament_tid']['vocabulary'] = 'parliaments';
  /* Filterkriterium: Benutzer: Wahlkreis (field_user_constituency) */
  $handler->display->display_options['filters']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['filters']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_constituency_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_constituency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator_id'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['label'] = 'Wahlkreis';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['description'] = 'Suche nach Wahlkreisen.';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_constituency_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: Benutzer: Adresse - Ort (z. B. Stadt) */
  $handler->display->display_options['filters']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['filters']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['group'] = 1;
  $handler->display->display_options['filters']['field_user_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['operator_id'] = 'field_user_address_locality_op';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['label'] = 'Wohnort';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['description'] = 'Suche nach Wohnorten.';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['operator'] = 'field_user_address_locality_op';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['identifier'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );

  /* Display: Politicians Overview */
  $handler = $view->new_display('page', 'Politicians Overview', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'field_user_constituency' => 'field_user_constituency',
    'field_user_commitee' => 'field_user_commitee',
    'field_user_questions_get' => 'field_user_questions_get',
    'field_user_answers_give' => 'field_user_answers_give',
    'field_user_address_locality' => 'field_user_address_locality',
    'rid' => 'rid',
    'field_user_list_position' => 'field_user_list_position',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_list_position';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_lname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_party' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_parliament' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_constituency' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_commitee' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_questions_get' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_answers_give' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_list_position' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Stapelverarbeitungen: Benutzer */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pw_login_once_send_mail_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Politiker';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'hidden';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'hidden';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Feld: Benutzer: Partei */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Benutzer: Parlament */
  $handler->display->display_options['fields']['field_user_parliament']['id'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['field'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['delta_offset'] = '0';
  /* Feld: Benutzer: Wahlkreis */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Benutzer: Adresse - Ort (z. B. Stadt) */
  $handler->display->display_options['fields']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['label'] = 'Ort';
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Feld: Benutzer: Listenposition */
  $handler->display->display_options['fields']['field_user_list_position']['id'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['table'] = 'field_data_field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['field'] = 'field_user_list_position';
  /* Feld: Benutzer: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator_id'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['label'] = 'Vorname';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['description'] = 'Suche nach Vornamen.';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['identifier'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator_id'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['label'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['description'] = 'Suche nach Nachnamen.';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['identifier'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    181527986 => '181527986',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = TRUE;
  /* Filterkriterium: Benutzer: E-Mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['description'] = 'Suche nach E-Mail-Adressen.';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer: Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Partei';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['description'] = 'Suche nach Parteien.';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['identifier'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_party_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Benutzer: Parlament (field_user_parliament) */
  $handler->display->display_options['filters']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_parliament_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator_id'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['description'] = 'Suche nach Parlamenten.';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['identifier'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_parliament_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_parliament_tid']['vocabulary'] = 'parliaments';
  /* Filterkriterium: Benutzer: Wahlkreis (field_user_constituency) */
  $handler->display->display_options['filters']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['filters']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_constituency_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_constituency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator_id'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['label'] = 'Wahlkreis';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['description'] = 'Suche nach Wahlkreisen.';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_constituency_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: Benutzer: Adresse - Ort (z. B. Stadt) */
  $handler->display->display_options['filters']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['filters']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['group'] = 1;
  $handler->display->display_options['filters']['field_user_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['operator_id'] = 'field_user_address_locality_op';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['label'] = 'Wohnort';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['description'] = 'Suche nach Wohnorten.';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['operator'] = 'field_user_address_locality_op';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['identifier'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['path'] = 'admin/people/politicians';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Politicians';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Politicians Bulk Edit */
  $handler = $view->new_display('page_with_page_title', 'Politicians Bulk Edit', 'page_with_page_title_1');
  $translatables['politicians'] = array(
    t('Master'),
    t('Politicians Overview'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Politiker pro Seite'),
    t('- Alle anzeigen -'),
    t('Versatz'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('weiter'),
    t('letzte Seite »'),
    t('Bitte auswählen'),
    t('Name'),
    t('E-Mail'),
    t('Partei'),
    t('Parlament'),
    t('Wahlkreis'),
    t('Ort'),
    t('Rollen'),
    t('Listenposition'),
    t('hidden'),
    t('Vorname'),
    t('Suche nach Vornamen.'),
    t('Nachname'),
    t('Suche nach Nachnamen.'),
    t('Suche nach E-Mail-Adressen.'),
    t('Suche nach Parteien.'),
    t('Suche nach Parlamenten.'),
    t('Suche nach Wahlkreisen.'),
    t('Wohnort'),
    t('Suche nach Wohnorten.'),
    t('Politiker'),
    t('Politicians Bulk Edit'),
  );
  $export['politicians'] = $view;

  $view = new view();
  $view->name = 'pw_admin_user_revisionen';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'user_revision';
  $view->human_name = 'PW Admin User Revisionen';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PW Admin User Revisionen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    51622513 => '51622513',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'vid' => 'vid',
    'timestamp' => 'timestamp',
    'field_user_parliament-revision_id' => 'field_user_parliament-revision_id',
    'field_user_party-revision_id' => 'field_user_party-revision_id',
    'field_user_fraction-revision_id' => 'field_user_fraction-revision_id',
    'field_user_constituency-revision_id' => 'field_user_constituency-revision_id',
    'edit_revision_1' => 'edit_revision_1',
    'revert_revision' => 'revert_revision',
    'delete_revision' => 'delete_revision',
    'user_role' => 'user_role',
    'fraction_name' => 'fraction_name',
    'parliament_name' => 'parliament_name',
    'nothing' => 'nothing',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'vid';
  $handler->display->display_options['style_options']['info'] = array(
    'vid' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_parliament-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_party-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fraction-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_constituency-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_revision_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'revert_revision' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_revision' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user_role' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fraction_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'parliament_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ctools_dropdown' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Feld: User revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'user_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  /* Feld: User revision: Erstellungsdatum */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'user_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Feld: Benutzer (Historische Daten): Parlament */
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['id'] = 'field_user_parliament-revision_id';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['table'] = 'field_revision_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['field'] = 'field_user_parliament-revision_id';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Feld: Benutzer (Historische Daten): Partei */
  $handler->display->display_options['fields']['field_user_party-revision_id']['id'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['fields']['field_user_party-revision_id']['field'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party-revision_id']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_user_party-revision_id']['delta_offset'] = '0';
  /* Feld: Benutzer (Historische Daten): Fraktion */
  $handler->display->display_options['fields']['field_user_fraction-revision_id']['id'] = 'field_user_fraction-revision_id';
  $handler->display->display_options['fields']['field_user_fraction-revision_id']['table'] = 'field_revision_field_user_fraction';
  $handler->display->display_options['fields']['field_user_fraction-revision_id']['field'] = 'field_user_fraction-revision_id';
  $handler->display->display_options['fields']['field_user_fraction-revision_id']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_fraction-revision_id']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Feld: Benutzer (Historische Daten): Wahlkreis */
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['id'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['table'] = 'field_revision_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['field'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['delta_offset'] = '0';
  /* Feld: User revision:  */
  $handler->display->display_options['fields']['edit_revision_1']['id'] = 'edit_revision_1';
  $handler->display->display_options['fields']['edit_revision_1']['table'] = 'user_revision';
  $handler->display->display_options['fields']['edit_revision_1']['field'] = 'edit_revision';
  $handler->display->display_options['fields']['edit_revision_1']['label'] = '‚Bearbeiten‘-Link';
  $handler->display->display_options['fields']['edit_revision_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_revision_1']['text'] = 'Bearbeiten';
  /* Feld: User revision: ‚Zurück‘-Link */
  $handler->display->display_options['fields']['revert_revision']['id'] = 'revert_revision';
  $handler->display->display_options['fields']['revert_revision']['table'] = 'user_revision';
  $handler->display->display_options['fields']['revert_revision']['field'] = 'revert_revision';
  $handler->display->display_options['fields']['revert_revision']['exclude'] = TRUE;
  /* Feld: User revision: Link löschen */
  $handler->display->display_options['fields']['delete_revision']['id'] = 'delete_revision';
  $handler->display->display_options['fields']['delete_revision']['table'] = 'user_revision';
  $handler->display->display_options['fields']['delete_revision']['field'] = 'delete_revision';
  $handler->display->display_options['fields']['delete_revision']['exclude'] = TRUE;
  /* Feld: PW User archive: Link to public profile */
  $handler->display->display_options['fields']['link_to_public_profile']['id'] = 'link_to_public_profile';
  $handler->display->display_options['fields']['link_to_public_profile']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['link_to_public_profile']['field'] = 'link_to_public_profile';
  $handler->display->display_options['fields']['link_to_public_profile']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link_to_public_profile']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['link_to_public_profile']['alter']['text'] = '<li>[link_to_public_profile]</li>';
  $handler->display->display_options['fields']['link_to_public_profile']['text'] = 'Profil ansehen';
  /* Feld: PW User archive: Benutzerrolle */
  $handler->display->display_options['fields']['user_role']['id'] = 'user_role';
  $handler->display->display_options['fields']['user_role']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['user_role']['field'] = 'user_role';
  $handler->display->display_options['fields']['user_role']['exclude'] = TRUE;
  $handler->display->display_options['fields']['user_role']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['user_role']['alter']['text'] = '<li>[user_role]</li>';
  /* Feld: PW User archive: Fraction name */
  $handler->display->display_options['fields']['fraction_name']['id'] = 'fraction_name';
  $handler->display->display_options['fields']['fraction_name']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['fraction_name']['field'] = 'fraction_name';
  $handler->display->display_options['fields']['fraction_name']['label'] = 'Fraktion';
  $handler->display->display_options['fields']['fraction_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fraction_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['fraction_name']['alter']['text'] = '<li>[fraction_name]</li>';
  $handler->display->display_options['fields']['fraction_name']['element_label_colon'] = FALSE;
  /* Feld: PW User archive: Parliament name */
  $handler->display->display_options['fields']['parliament_name']['id'] = 'parliament_name';
  $handler->display->display_options['fields']['parliament_name']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['parliament_name']['field'] = 'parliament_name';
  $handler->display->display_options['fields']['parliament_name']['label'] = 'Parlament';
  $handler->display->display_options['fields']['parliament_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['parliament_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['parliament_name']['alter']['text'] = '<li>[parliament_name]</li>';
  $handler->display->display_options['fields']['parliament_name']['element_label_colon'] = FALSE;
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Öffentliches Profil';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>
[link_to_public_profile]
[user_role]
[fraction_name]
[parliament_name]
</ul>';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Optionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_revision_1' => 'edit_revision_1',
    'revert_revision' => 'revert_revision',
    'delete_revision' => 'delete_revision',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 0;
  /* Kontextfilter: Benutzer: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title'] = 'Revisionen für %1';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filterkriterium: Benutzer (Historische Daten): Fraktion (field_user_fraction) */
  $handler->display->display_options['filters']['field_user_fraction_tid']['id'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['table'] = 'field_revision_field_user_fraction';
  $handler->display->display_options['filters']['field_user_fraction_tid']['field'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_fraction_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fraction_tid']['expose']['operator_id'] = 'field_user_fraction_tid_op';
  $handler->display->display_options['filters']['field_user_fraction_tid']['expose']['label'] = 'Fraktion';
  $handler->display->display_options['filters']['field_user_fraction_tid']['expose']['operator'] = 'field_user_fraction_tid_op';
  $handler->display->display_options['filters']['field_user_fraction_tid']['expose']['identifier'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
    127500594 => 0,
    52344559 => 0,
    109923392 => 0,
  );
  $handler->display->display_options['filters']['field_user_fraction_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_fraction_tid']['vocabulary'] = 'fraction';
  /* Filterkriterium: Benutzer (Historische Daten): Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Partei';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['identifier'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
    127500594 => 0,
    52344559 => 0,
    109923392 => 0,
  );
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/revisions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Revisionen';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['pw_admin_user_revisionen'] = array(
    t('Master'),
    t('PW Admin User Revisionen'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Versatz'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Vid'),
    t('Erstellungsdatum'),
    t('Parlament'),
    t('Partei'),
    t('Fraktion'),
    t('Wahlkreis'),
    t('‚Bearbeiten‘-Link'),
    t('Bearbeiten'),
    t('‚Zurück‘-Link'),
    t('Link löschen'),
    t('Link to public profile'),
    t('<li>[link_to_public_profile]</li>'),
    t('Profil ansehen'),
    t('Benutzerrolle'),
    t('<li>[user_role]</li>'),
    t('<li>[fraction_name]</li>'),
    t('<li>[parliament_name]</li>'),
    t('Öffentliches Profil'),
    t('<ul>
[link_to_public_profile]
[user_role]
[fraction_name]
[parliament_name]
</ul>'),
    t('Optionen'),
    t('Alle'),
    t('Revisionen für %1'),
    t('Page'),
  );
  $export['pw_admin_user_revisionen'] = $view;

  return $export;
}
