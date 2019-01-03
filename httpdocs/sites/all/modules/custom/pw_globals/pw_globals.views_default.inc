<?php
/**
 * @file
 * pw_globals.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_globals_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'aufr_umen_politiker_parteilos_fraktionslos';
  $view->description = 'Listet Politiker auf, die bei Partei den Wert fraktionslos und bei Fraktion den Wert parteilos haben';
  $view->tag = 'default';
  $view->base_table = 'user_revision';
  $view->human_name = 'Aufräumen: Politiker parteilos/ fraktionslos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aufräumen: Politiker parteilos/ fraktionslos';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_user_fname-revision_id' => 'field_user_fname-revision_id',
    'field_user_lname-revision_id' => 'field_user_lname-revision_id',
    'field_user_parliament-revision_id' => 'field_user_parliament-revision_id',
    'user_role' => 'user_role',
    'field_user_fraction-revision_id' => 'field_user_fraction-revision_id',
    'field_user_party-revision_id' => 'field_user_party-revision_id',
    'link_to_public_profile' => 'link_to_public_profile',
    'edit_revision' => 'edit_revision',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_lname-revision_id';
  $handler->display->display_options['style_options']['info'] = array(
    'field_user_fname-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_lname-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_parliament-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user_role' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'field_user_party-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_to_public_profile' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_revision' => array(
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
  /* Kopfzeile: Global: Textbereich */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Listet Politiker auf, die bei Partei den Wert fraktionslos und bei Fraktion den Wert parteilos haben';
  $handler->display->display_options['header']['area']['format'] = 'managed_content';
  /* Feld: Stapelverarbeitungen: User revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'user_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Löschen',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Werte ändern',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
  );
  /* Feld: Benutzer (Historische Daten): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id']['id'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['settings'] = array(
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
  /* Feld: Benutzer (Historische Daten): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id']['id'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['label'] = 'Name';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['text'] = '[field_user_lname-revision_id], [field_user_fname-revision_id]';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['settings'] = array(
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
  /* Feld: PW User archive: Benutzerrolle */
  $handler->display->display_options['fields']['user_role']['id'] = 'user_role';
  $handler->display->display_options['fields']['user_role']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['user_role']['field'] = 'user_role';
  $handler->display->display_options['fields']['user_role']['label'] = 'Rolle';
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
  /* Feld: PW User archive: Link to public profile */
  $handler->display->display_options['fields']['link_to_public_profile']['id'] = 'link_to_public_profile';
  $handler->display->display_options['fields']['link_to_public_profile']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['link_to_public_profile']['field'] = 'link_to_public_profile';
  $handler->display->display_options['fields']['link_to_public_profile']['label'] = '';
  $handler->display->display_options['fields']['link_to_public_profile']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link_to_public_profile']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link_to_public_profile']['text'] = 'Ansehen';
  /* Feld: User revision: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_revision']['id'] = 'edit_revision';
  $handler->display->display_options['fields']['edit_revision']['table'] = 'user_revision';
  $handler->display->display_options['fields']['edit_revision']['field'] = 'edit_revision';
  $handler->display->display_options['fields']['edit_revision']['label'] = '';
  $handler->display->display_options['fields']['edit_revision']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_revision']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_revision']['text'] = 'Bearbeiten';
  /* Feld: User revision: Link löschen */
  $handler->display->display_options['fields']['delete_revision']['id'] = 'delete_revision';
  $handler->display->display_options['fields']['delete_revision']['table'] = 'user_revision';
  $handler->display->display_options['fields']['delete_revision']['field'] = 'delete_revision';
  $handler->display->display_options['fields']['delete_revision']['label'] = '';
  $handler->display->display_options['fields']['delete_revision']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_revision']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_revision']['text'] = 'Löschen';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'link_to_public_profile' => 'link_to_public_profile',
    'edit_revision' => 'edit_revision',
    'delete_revision' => 'delete_revision',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  /* Filterkriterium: Benutzer (Historische Daten): Fraktion (field_user_fraction) */
  $handler->display->display_options['filters']['field_user_fraction_tid']['id'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['table'] = 'field_revision_field_user_fraction';
  $handler->display->display_options['filters']['field_user_fraction_tid']['field'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['value'] = array(
    19750 => '19750',
  );
  $handler->display->display_options['filters']['field_user_fraction_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_fraction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_fraction_tid']['vocabulary'] = 'fraction';
  /* Filterkriterium: Benutzer (Historische Daten): Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['value'] = array(
    17362 => '17362',
  );
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Benutzer (Historische Daten): First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 2;
  $handler->display->display_options['filters']['field_user_fname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator_id'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['label'] = 'Vorname';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['identifier'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer (Historische Daten): Last name (field_user_lname:format) */
  $handler->display->display_options['filters']['field_user_lname_format']['id'] = 'field_user_lname_format';
  $handler->display->display_options['filters']['field_user_lname_format']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_format']['field'] = 'field_user_lname_format';
  $handler->display->display_options['filters']['field_user_lname_format']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_user_lname_format']['group'] = 2;
  $handler->display->display_options['filters']['field_user_lname_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_format']['expose']['operator_id'] = 'field_user_lname_format_op';
  $handler->display->display_options['filters']['field_user_lname_format']['expose']['label'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_format']['expose']['operator'] = 'field_user_lname_format_op';
  $handler->display->display_options['filters']['field_user_lname_format']['expose']['identifier'] = 'field_user_lname_format';
  $handler->display->display_options['filters']['field_user_lname_format']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer (Historische Daten): Parlament (field_user_parliament) */
  $handler->display->display_options['filters']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['table'] = 'field_revision_field_user_parliament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_parliament_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_user_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator_id'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['identifier'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_user_parliament_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_parliament_tid']['vocabulary'] = 'parliaments';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/aufr-umen-politiker-parteilos-fraktionslos';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Stapelverarbeitungen: User revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'user_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Löschen',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Werte ändern',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
  );
  /* Feld: Benutzer (Historische Daten): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id']['id'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['label'] = 'Vorname';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['settings'] = array(
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
  /* Feld: Benutzer (Historische Daten): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id']['id'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['label'] = 'Nachname';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['text'] = '[field_user_lname-revision_id], [field_user_fname-revision_id]';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['settings'] = array(
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
  /* Feld: PW User archive: Benutzerrolle */
  $handler->display->display_options['fields']['user_role']['id'] = 'user_role';
  $handler->display->display_options['fields']['user_role']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['user_role']['field'] = 'user_role';
  $handler->display->display_options['fields']['user_role']['label'] = 'Rolle';
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
  $handler->display->display_options['path'] = 'admin/aufr-umen-politiker-parteilos-fraktionslos/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/aufr-umen-politiker-parteilos-fraktionslos';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['aufr_umen_politiker_parteilos_fraktionslos'] = array(
    t('Master'),
    t('Aufräumen: Politiker parteilos/ fraktionslos'),
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
    t('Listet Politiker auf, die bei Partei den Wert fraktionslos und bei Fraktion den Wert parteilos haben'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Löschen'),
    t('Werte ändern'),
    t('Name'),
    t('[field_user_lname-revision_id], [field_user_fname-revision_id]'),
    t('Parlament'),
    t('Rolle'),
    t('Fraktion'),
    t('Partei'),
    t('Ansehen'),
    t('Bearbeiten'),
    t('Dropdown links'),
    t('Vorname'),
    t('Nachname'),
    t('Page'),
    t('Data export'),
  );
  $export['aufr_umen_politiker_parteilos_fraktionslos'] = $view;

  return $export;
}
