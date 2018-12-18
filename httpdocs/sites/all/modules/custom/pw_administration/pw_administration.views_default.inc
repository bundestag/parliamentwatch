<?php
/**
 * @file
 * pw_administration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_administration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'administration_files';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Administration: Files';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administration: Files';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    30037204 => '30037204',
    51622513 => '51622513',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'fid' => 'fid',
    'filename' => 'filename',
    'type' => 'type',
    'filesize' => 'filesize',
    'timestamp' => 'timestamp',
    'uuid' => 'uuid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filesize' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Feld: Datei: Datei-ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['fid']['alter']['path'] = 'file/[fid]/edit';
  /* Feld: Datei: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Feld: Datei: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'file_managed';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Feld: Datei: Größe */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  /* Feld: Datei: Upload-Datum */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Upload Datum';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Feld: Datei: Datei UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Sortierkriterien: Datei: Upload-Datum */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['timestamp']['expose']['label'] = 'Upload Datum';
  /* Sortierkriterien: Datei: Datei-ID */
  $handler->display->display_options['sorts']['fid']['id'] = 'fid';
  $handler->display->display_options['sorts']['fid']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['fid']['field'] = 'fid';
  $handler->display->display_options['sorts']['fid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['fid']['expose']['label'] = 'Datei-ID';
  /* Sortierkriterien: Datei: Name */
  $handler->display->display_options['sorts']['filename']['id'] = 'filename';
  $handler->display->display_options['sorts']['filename']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['filename']['field'] = 'filename';
  $handler->display->display_options['sorts']['filename']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['filename']['expose']['label'] = 'Name';
  /* Sortierkriterien: Datei: Größe */
  $handler->display->display_options['sorts']['filesize']['id'] = 'filesize';
  $handler->display->display_options['sorts']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['filesize']['field'] = 'filesize';
  $handler->display->display_options['sorts']['filesize']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['filesize']['expose']['label'] = 'Größe';
  /* Filterkriterium: Datei: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
  );
  /* Filterkriterium: Datei: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/file';
  $translatables['administration_files'] = array(
    t('Master'),
    t('Administration: Files'),
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
    t('Datei-ID'),
    t('Typ'),
    t('Größe'),
    t('Upload Datum'),
    t('Datei UUID'),
    t('Name'),
    t('Page'),
  );
  $export['administration_files'] = $view;

  $view = new view();
  $view->name = 'pw_administration_antworten';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'PW Administration Antworten';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Politiker-Antworten';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer comments';
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
    'uid' => 'uid',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'field_dialogue_sender_name' => 'field_dialogue_sender_name',
    'created' => 'created',
    'field_dialogue_comment_body' => 'field_dialogue_comment_body',
    'field_dialogue_id' => 'field_dialogue_id',
    'field_dialogue_message_id' => 'field_dialogue_message_id',
    'view_node' => 'view_node',
    'field_user_address_thoroughfare' => 'field_user_address_thoroughfare',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_lname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dialogue_sender_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dialogue_comment_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dialogue_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dialogue_message_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_address_thoroughfare' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Beziehung: Kommentar: Inhalt */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['id'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['table'] = 'field_data_field_dialogue_recipient';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['field'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['label'] = 'Politiker';
  /* Feld: Stapelverarbeitungen: Kommentar */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_comment';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Einträge exportieren',
      'settings' => array(
        'url' => 'admin/abgeordnetenwatch/fragen/antworten/export',
      ),
    ),
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
        'show_all_tokens' => 0,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::comment_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichen',
    ),
    'action::comment_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichung zurücknehmen',
    ),
  );
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['settings'] = array(
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
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Politiker';
  $handler->display->display_options['fields']['field_user_lname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname], [field_user_fname]';
  $handler->display->display_options['fields']['field_user_lname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_lname']['settings'] = array(
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
  /* Feld: Inhalt: Sender Name */
  $handler->display->display_options['fields']['field_dialogue_sender_name']['id'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['field'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['label'] = 'Fragesteller';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['settings'] = array(
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
  /* Feld: Kommentar: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Datum';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Kommentar: Comment Body */
  $handler->display->display_options['fields']['field_dialogue_comment_body']['id'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['table'] = 'field_data_field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['field'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['label'] = 'Antwort';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['settings'] = array(
    'trim_length' => '600',
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
  /* Feld: Feld: Dialogue ID */
  $handler->display->display_options['fields']['field_dialogue_id']['id'] = 'field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['table'] = 'field_data_field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['field'] = 'field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  /* Feld: Feld: Message ID */
  $handler->display->display_options['fields']['field_dialogue_message_id']['id'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['table'] = 'field_data_field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['field'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  /* Feld: Inhalt: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Ansehen';
  /* Feld: Kommentar: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['label'] = '';
  $handler->display->display_options['fields']['edit_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_comment']['text'] = 'Bearbeiten';
  /* Feld: Kommentar: Link löschen */
  $handler->display->display_options['fields']['delete_comment']['id'] = 'delete_comment';
  $handler->display->display_options['fields']['delete_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['delete_comment']['field'] = 'delete_comment';
  $handler->display->display_options['fields']['delete_comment']['label'] = '';
  $handler->display->display_options['fields']['delete_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_comment']['text'] = 'Löschen';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'view_node' => 'view_node',
    'edit_comment' => 'edit_comment',
    'delete_comment' => 'delete_comment',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 0;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Inhalt: Sender Name (field_dialogue_sender_name) */
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['id'] = 'field_dialogue_sender_name_value';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['field'] = 'field_dialogue_sender_name_value';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['operator_id'] = 'field_dialogue_sender_name_value_op';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['label'] = 'Fragesteller';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['operator'] = 'field_dialogue_sender_name_value_op';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['identifier'] = 'field_dialogue_sender_name_value';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator_id'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['label'] = 'Vorname (Politiker)';
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
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['filters']['field_user_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator_id'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['label'] = 'Nachname (Politiker)';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['identifier'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Feld: Dialogue ID (field_dialogue_id) */
  $handler->display->display_options['filters']['field_dialogue_id_value']['id'] = 'field_dialogue_id_value';
  $handler->display->display_options['filters']['field_dialogue_id_value']['table'] = 'field_data_field_dialogue_id';
  $handler->display->display_options['filters']['field_dialogue_id_value']['field'] = 'field_dialogue_id_value';
  $handler->display->display_options['filters']['field_dialogue_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_dialogue_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['operator_id'] = 'field_dialogue_id_value_op';
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['label'] = 'Dialogue ID';
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['operator'] = 'field_dialogue_id_value_op';
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['identifier'] = 'field_dialogue_id_value';
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Feld: Message ID (field_dialogue_message_id) */
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['id'] = 'field_dialogue_message_id_value';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['table'] = 'field_data_field_dialogue_message_id';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['field'] = 'field_dialogue_message_id_value';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['operator_id'] = 'field_dialogue_message_id_value_op';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['label'] = 'Message ID';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['operator'] = 'field_dialogue_message_id_value_op';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['identifier'] = 'field_dialogue_message_id_value';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 'All';
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_node']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_node']['expose']['label'] = 'Frage veröffentlicht';
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = 'status_node_op';
  $handler->display->display_options['filters']['status_node']['expose']['identifier'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Kommentar: Bestätigt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Genemigter Kommentar';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/fragen/antworten';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Antworten';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

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
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['settings'] = array(
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
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Politiker';
  $handler->display->display_options['fields']['field_user_lname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname], [field_user_fname]';
  $handler->display->display_options['fields']['field_user_lname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_lname']['settings'] = array(
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
  /* Feld: Inhalt: Sender Name */
  $handler->display->display_options['fields']['field_dialogue_sender_name']['id'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['field'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['label'] = 'Fragesteller';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['settings'] = array(
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
  /* Feld: Kommentar: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Datum';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Kommentar: Comment Body */
  $handler->display->display_options['fields']['field_dialogue_comment_body']['id'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['table'] = 'field_data_field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['field'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['label'] = 'Antwort';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['settings'] = array(
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
  /* Feld: Feld: Dialogue ID */
  $handler->display->display_options['fields']['field_dialogue_id']['id'] = 'field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['table'] = 'field_data_field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['field'] = 'field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  /* Feld: Feld: Message ID */
  $handler->display->display_options['fields']['field_dialogue_message_id']['id'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['table'] = 'field_data_field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['field'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Kommentar: ID */
  $handler->display->display_options['arguments']['cid']['id'] = 'cid';
  $handler->display->display_options['arguments']['cid']['table'] = 'comment';
  $handler->display->display_options['arguments']['cid']['field'] = 'cid';
  $handler->display->display_options['arguments']['cid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['cid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['cid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['cid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['cid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['cid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/fragen/antworten/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/fragen/antworten';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_antworten'] = array(
    t('Master'),
    t('Politiker-Antworten'),
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
    t('Inhalt'),
    t('Politiker'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Löschen'),
    t('Werte ändern'),
    t('Veröffentlichen'),
    t('Veröffentlichung zurücknehmen'),
    t('[field_user_lname], [field_user_fname]'),
    t('Fragesteller'),
    t('Datum'),
    t('Antwort'),
    t('Dialogue ID'),
    t('Message ID'),
    t('Ansehen'),
    t('Bearbeiten'),
    t('Aktionen'),
    t('Vorname (Politiker)'),
    t('Nachname (Politiker)'),
    t('Frage veröffentlicht'),
    t('Genemigter Kommentar'),
    t('Page'),
    t('Data export'),
    t('Alle'),
  );
  $export['pw_administration_antworten'] = $view;

  $view = new view();
  $view->name = 'pw_administration_comments';
  $view->description = 'List and edit site comments and the comment moderation queue.';
  $view->tag = 'admin';
  $view->base_table = 'comment';
  $view->human_name = 'PW Administration Comments';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Kommentare';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer comments';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'timestamp' => 'timestamp',
    'title' => 'title',
    'created' => 'created',
    'subject' => 'subject',
    'name' => 'name',
    'comment_body' => 'comment_body',
    'view_comment' => 'view_comment',
    'approve_comment' => 'approve_comment',
    'replyto_comment' => 'replyto_comment',
    'edit_comment' => 'edit_comment',
    'delete_comment' => 'edit_comment',
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
    'name_1' => 'name_1',
    'mail' => 'mail',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'subject' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'comment_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_comment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'approve_comment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'replyto_comment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_comment' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_comment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Ungefilterter Text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Keine Kommentare verfügbar.';
  /* Beziehung: Kommentar: Inhalt */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Beitrag';
  /* Beziehung: Kommentar: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'comment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Feld: Stapelverarbeitungen: Kommentar */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_comment';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Delete',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::comment_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
      'postpone_processing' => 0,
    ),
    'action::comment_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
      'postpone_processing' => 0,
    ),
  );
  /* Feld: Kommentar: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'comment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'changed';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Geschrieben';
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '16';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Feld: Kommentar: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Kommentar: Titel */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  $handler->display->display_options['fields']['subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['subject']['element_label_colon'] = FALSE;
  /* Feld: Kommentar: Autor */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Feld: Kommentar: Comment */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['label'] = '';
  $handler->display->display_options['fields']['comment_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
  /* Feld: Kommentar: ‚Anzeigen‘-Link */
  $handler->display->display_options['fields']['view_comment']['id'] = 'view_comment';
  $handler->display->display_options['fields']['view_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['view_comment']['field'] = 'view_comment';
  $handler->display->display_options['fields']['view_comment']['label'] = '';
  $handler->display->display_options['fields']['view_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_comment']['text'] = 'Ansehen';
  /* Feld: Kommentar: Link bestätigen. */
  $handler->display->display_options['fields']['approve_comment']['id'] = 'approve_comment';
  $handler->display->display_options['fields']['approve_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['approve_comment']['field'] = 'approve_comment';
  $handler->display->display_options['fields']['approve_comment']['label'] = '';
  $handler->display->display_options['fields']['approve_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['approve_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['approve_comment']['text'] = 'Genehmigen';
  /* Feld: Kommentar: ‚Antworten‘-Link */
  $handler->display->display_options['fields']['replyto_comment']['id'] = 'replyto_comment';
  $handler->display->display_options['fields']['replyto_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['replyto_comment']['field'] = 'replyto_comment';
  $handler->display->display_options['fields']['replyto_comment']['label'] = '';
  $handler->display->display_options['fields']['replyto_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['replyto_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['replyto_comment']['text'] = 'Antworten';
  /* Feld: Kommentar: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['label'] = '';
  $handler->display->display_options['fields']['edit_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_comment']['element_label_colon'] = FALSE;
  /* Feld: Kommentar: Link löschen */
  $handler->display->display_options['fields']['delete_comment']['id'] = 'delete_comment';
  $handler->display->display_options['fields']['delete_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['delete_comment']['field'] = 'delete_comment';
  $handler->display->display_options['fields']['delete_comment']['label'] = '';
  $handler->display->display_options['fields']['delete_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_comment']['element_label_colon'] = FALSE;
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Kommentar';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="comment-view-meta">Kommentar <strong>[subject]</strong> von <strong>[name]</strong> geschrieben am <strong>[created]</strong></div>
<div class="comment-view-title">Verfasst in <strong>[title]</strong></div>
<div class="comment-view-body">[comment_body]</div>';
  /* Feld: Kommentar: Autor */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'comment';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['link_to_user'] = FALSE;
  /* Feld: Kommentar: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'comment';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'view_comment' => 'view_comment',
    'approve_comment' => 'approve_comment',
    'replyto_comment' => 'replyto_comment',
    'edit_comment' => 'edit_comment',
    'delete_comment' => 'delete_comment',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 0;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Kommentar: Bestätigt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Genemigter Kommentar';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Kommentar: Titel */
  $handler->display->display_options['filters']['subject']['id'] = 'subject';
  $handler->display->display_options['filters']['subject']['table'] = 'comment';
  $handler->display->display_options['filters']['subject']['field'] = 'subject';
  $handler->display->display_options['filters']['subject']['operator'] = 'contains';
  $handler->display->display_options['filters']['subject']['group'] = 1;
  $handler->display->display_options['filters']['subject']['exposed'] = TRUE;
  $handler->display->display_options['filters']['subject']['expose']['operator_id'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['subject']['expose']['operator'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['identifier'] = 'subject';
  $handler->display->display_options['filters']['subject']['expose']['remember'] = TRUE;
  /* Filterkriterium: Benutzer: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Autor';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  /* Filterkriterium: Inhalt: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'nid';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Erstellt in';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'nodeTitle';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;

  /* Display: Unpublished */
  $handler = $view->new_display('page', 'Unpublished', 'page_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Kommentar: Titel */
  $handler->display->display_options['filters']['subject']['id'] = 'subject';
  $handler->display->display_options['filters']['subject']['table'] = 'comment';
  $handler->display->display_options['filters']['subject']['field'] = 'subject';
  $handler->display->display_options['filters']['subject']['operator'] = 'contains';
  $handler->display->display_options['filters']['subject']['group'] = 1;
  $handler->display->display_options['filters']['subject']['exposed'] = TRUE;
  $handler->display->display_options['filters']['subject']['expose']['operator_id'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['subject']['expose']['operator'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['identifier'] = 'subject';
  $handler->display->display_options['filters']['subject']['expose']['remember'] = TRUE;
  /* Filterkriterium: Benutzer: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Autor';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  /* Filterkriterium: Inhalt: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'nid';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Erstellt in';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'nodeTitle';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Filterkriterium: Kommentar: Bestätigt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Veröffentlicht';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  $handler->display->display_options['path'] = 'admin/content/comment/approval';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Nicht freigegebene Kommentare';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Published - Default Tab */
  $handler = $view->new_display('page', 'Published - Default Tab', 'page_1');
  $handler->display->display_options['path'] = 'admin/content/comment/new';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Veröffentlichte Kommentare';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Published - Menu Eintrag */
  $handler = $view->new_display('page', 'Published - Menu Eintrag', 'page_4');
  $handler->display->display_options['path'] = 'admin/content/comment';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Kommentare';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['pw_administration_comments'] = array(
    t('Defaults'),
    t('Kommentare'),
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
    t('Keine Kommentare verfügbar.'),
    t('Beitrag'),
    t('Autor'),
    t('Bitte auswählen'),
    t('Delete'),
    t('Change value'),
    t('Publish'),
    t('Unpublish'),
    t('Geschrieben'),
    t('Ansehen'),
    t('Genehmigen'),
    t('Antworten'),
    t('Kommentar'),
    t('<div class="comment-view-meta">Kommentar <strong>[subject]</strong> von <strong>[name]</strong> geschrieben am <strong>[created]</strong></div>
<div class="comment-view-title">Verfasst in <strong>[title]</strong></div>
<div class="comment-view-body">[comment_body]</div>'),
    t('E-Mail'),
    t('Aktionen'),
    t('Genemigter Kommentar'),
    t('Titel'),
    t('Erstellt in'),
    t('Unpublished'),
    t('Veröffentlicht'),
    t('Published - Default Tab'),
    t('Published - Menu Eintrag'),
  );
  $export['pw_administration_comments'] = $view;

  $view = new view();
  $view->name = 'pw_administration_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Inhalt';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
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
    'title' => 'title',
    'type' => 'type',
    'uuid' => 'uuid',
    'name' => 'name',
    'status' => 'status',
    'changed' => 'changed',
    'created' => 'created',
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uuid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Beziehung: Inhalt: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Feld: Stapelverarbeitungen: Inhalt */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Autor ändern',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Einträge exportieren',
      'settings' => array(
        'url' => 'admin/content/export/',
      ),
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichung zurücknehmen',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 1,
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
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::metatag_modify_metatags_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Metatags ändern',
    ),
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Aktualisiert';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Feld: Inhalt: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Datum';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Löschen';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]  [delete_node] ';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
    'sidejob' => 'sidejob',
    'vote' => 'vote',
    'webform' => 'webform',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Inhalt: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['body_value']['group'] = 1;
  $handler->display->display_options['filters']['body_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['body_value']['expose']['operator_id'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['label'] = 'Text';
  $handler->display->display_options['filters']['body_value']['expose']['operator'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['identifier'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'poll' => 'poll',
    'committee' => 'committee',
    'blogpost' => 'blogpost',
    'page' => 'page',
    'pw_kc_position' => 'pw_kc_position',
    'pw_kc_thesis' => 'pw_kc_thesis',
    'newsletter' => 'newsletter',
    'partners' => 'partners',
    'pw_petition' => 'pw_petition',
    'press_article' => 'press_article',
    'press_release' => 'press_release',
    'pw_testimonial' => 'pw_testimonial',
    'election_programme' => 'election_programme',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  /* Filterkriterium: Benutzer: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Veröffentlicht';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Inhalt UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'node';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['group'] = 1;
  $handler->display->display_options['filters']['uuid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uuid']['expose']['operator_id'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['label'] = 'UUID';
  $handler->display->display_options['filters']['uuid']['expose']['operator'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['identifier'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Beitragsdatum */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Datum (JJJJ-MM-TT HH:MM:SS)';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Feld: Parliament (field_parliament) */
  $handler->display->display_options['filters']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['filters']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_parliament_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator_id'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['identifier'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_parliament_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_parliament_tid']['vocabulary'] = 'parliaments';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content';
  $handler->display->display_options['menu']['title'] = 'Inhalt';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Beitrags-ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'admin/content/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/content';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_content'] = array(
    t('Master'),
    t('Inhalt'),
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
    t('Autor'),
    t('Bitte auswählen'),
    t('Autor ändern'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('Metatags ändern'),
    t('Titel'),
    t('Typ'),
    t('UUID'),
    t('Veröffentlicht'),
    t('Aktualisiert'),
    t('Datum'),
    t('Aktionen'),
    t('[edit_node]  [delete_node] '),
    t('Bearbeiten'),
    t('Text'),
    t('Name'),
    t('Datum (JJJJ-MM-TT HH:MM:SS)'),
    t('Parlament'),
    t('Page'),
    t('Data export'),
    t('Alle'),
  );
  $export['pw_administration_content'] = $view;

  $view = new view();
  $view->name = 'pw_administration_fragen';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Fragen';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Fragen verwalten';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'field_dialogue_sender_name' => 'field_dialogue_sender_name',
    'created' => 'created',
    'field_dialogue_topic' => 'field_dialogue_topic',
    'field_parliament' => 'field_parliament',
    'field_dialogue_id' => 'field_dialogue_id',
    'field_dialogue_message_id' => 'field_dialogue_message_id',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_lname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dialogue_sender_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dialogue_topic' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dialogue_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dialogue_message_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['id'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['table'] = 'field_data_field_dialogue_recipient';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['field'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['label'] = 'Politiker';
  /* Feld: Stapelverarbeitungen: Inhalt */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Einträge exportieren',
      'settings' => array(
        'url' => 'admin/abgeordnetenwatch/fragen/export',
      ),
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichung zurücknehmen',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 1,
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
        'show_all_tokens' => 0,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['settings'] = array(
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
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Politiker';
  $handler->display->display_options['fields']['field_user_lname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname], [field_user_fname]';
  $handler->display->display_options['fields']['field_user_lname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_lname']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => 'user/',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Feld: Inhalt: Sender Name */
  $handler->display->display_options['fields']['field_dialogue_sender_name']['id'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['field'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['label'] = 'Fragesteller';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['settings'] = array(
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
  /* Feld: Inhalt: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Datum';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Feld: Dialogue ID */
  $handler->display->display_options['fields']['field_dialogue_id']['id'] = 'field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['table'] = 'field_data_field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['field'] = 'field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  /* Feld: Feld: Message ID */
  $handler->display->display_options['fields']['field_dialogue_message_id']['id'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['table'] = 'field_data_field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['field'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Frage';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
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
  /* Feld: Inhalt: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Zur Frage';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Benutzer: First Name (field_user_fname:format) */
  $handler->display->display_options['filters']['field_user_fname_format']['id'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_format']['field'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['filters']['field_user_fname_format']['group'] = 1;
  $handler->display->display_options['filters']['field_user_fname_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['operator_id'] = 'field_user_fname_format_op';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['label'] = 'Vorname';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['operator'] = 'field_user_fname_format_op';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['identifier'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['filters']['field_user_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator_id'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['label'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['identifier'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Sender Name (field_dialogue_sender_name) */
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['id'] = 'field_dialogue_sender_name_value';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['field'] = 'field_dialogue_sender_name_value';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['operator_id'] = 'field_dialogue_sender_name_value_op';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['label'] = 'Fragesteller';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['operator'] = 'field_dialogue_sender_name_value_op';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['identifier'] = 'field_dialogue_sender_name_value';
  $handler->display->display_options['filters']['field_dialogue_sender_name_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Feld: Dialogue ID (field_dialogue_id) */
  $handler->display->display_options['filters']['field_dialogue_id_value']['id'] = 'field_dialogue_id_value';
  $handler->display->display_options['filters']['field_dialogue_id_value']['table'] = 'field_data_field_dialogue_id';
  $handler->display->display_options['filters']['field_dialogue_id_value']['field'] = 'field_dialogue_id_value';
  $handler->display->display_options['filters']['field_dialogue_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['operator_id'] = 'field_dialogue_id_value_op';
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['label'] = 'Dialogue ID';
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['operator'] = 'field_dialogue_id_value_op';
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['identifier'] = 'field_dialogue_id_value';
  $handler->display->display_options['filters']['field_dialogue_id_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Feld: Message ID (field_dialogue_message_id) */
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['id'] = 'field_dialogue_message_id_value';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['table'] = 'field_data_field_dialogue_message_id';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['field'] = 'field_dialogue_message_id_value';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['operator_id'] = 'field_dialogue_message_id_value_op';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['label'] = 'Message ID';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['operator'] = 'field_dialogue_message_id_value_op';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['identifier'] = 'field_dialogue_message_id_value';
  $handler->display->display_options['filters']['field_dialogue_message_id_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Partei des Politiker';
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
  /* Filterkriterium: Feld: Topic (field_dialogue_topic) */
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['id'] = 'field_dialogue_topic_tid';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['table'] = 'field_data_field_dialogue_topic';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['field'] = 'field_dialogue_topic_tid';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['value'] = '';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['operator_id'] = 'field_dialogue_topic_tid_op';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['label'] = 'Thema';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['operator'] = 'field_dialogue_topic_tid_op';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['identifier'] = 'field_dialogue_topic_tid';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['vocabulary'] = 'dialogue_topics';
  /* Filterkriterium: Feld: Parliament (field_parliament) */
  $handler->display->display_options['filters']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['filters']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator_id'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['identifier'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_parliament_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_parliament_tid']['vocabulary'] = 'parliaments';

  /* Display: Page default Reiter */
  $handler = $view->new_display('page', 'Page default Reiter', 'page_1');
  $handler->display->display_options['display_description'] = 'Der Default Reiter';
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/fragen/fragen';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Fragen';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Fragen & Antworten';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Menu Punkt */
  $handler = $view->new_display('page', 'Menu Punkt', 'page_2');
  $handler->display->display_options['display_description'] = 'Page um einen Menü Punkt im Management Menu zu erstellen';
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/fragen';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Fragen & Antworten';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Fragen & Antworten';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Massen-Export */
  $handler = $view->new_display('views_data_export', 'Massen-Export', 'views_data_export_2');
  $handler->display->display_options['display_description'] = 'Liefert den Button zum Export am Ende der View';
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
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['settings'] = array(
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
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Politiker';
  $handler->display->display_options['fields']['field_user_lname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname], [field_user_fname]';
  $handler->display->display_options['fields']['field_user_lname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_lname']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => 'user/',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Feld: Inhalt: Sender Name */
  $handler->display->display_options['fields']['field_dialogue_sender_name']['id'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['field'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['label'] = 'Fragesteller';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['settings'] = array(
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
  /* Feld: Inhalt: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Datum';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Feld: Dialogue ID */
  $handler->display->display_options['fields']['field_dialogue_id']['id'] = 'field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['table'] = 'field_data_field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['field'] = 'field_dialogue_id';
  $handler->display->display_options['fields']['field_dialogue_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  /* Feld: Feld: Message ID */
  $handler->display->display_options['fields']['field_dialogue_message_id']['id'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['table'] = 'field_data_field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['field'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
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
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Frage';
  $handler->display->display_options['fields']['body']['settings'] = array(
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Beitrags-ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/fragen/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'page_2' => 'page_2',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/fragen';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_fragen'] = array(
    t('Master'),
    t('Fragen verwalten'),
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
    t('Politiker'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('[field_user_lname], [field_user_fname]'),
    t('Fragesteller'),
    t('Datum'),
    t('Dialogue ID'),
    t('Message ID'),
    t('Frage'),
    t('Zur Frage'),
    t('Vorname'),
    t('Nachname'),
    t('Partei des Politiker'),
    t('Thema'),
    t('Parlament'),
    t('Page default Reiter'),
    t('Der Default Reiter'),
    t('Menu Punkt'),
    t('Page um einen Menü Punkt im Management Menu zu erstellen'),
    t('Massen-Export'),
    t('Liefert den Button zum Export am Ende der View'),
    t('Alle'),
  );
  $export['pw_administration_fragen'] = $view;

  $view = new view();
  $view->name = 'pw_administration_sidejobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Sidejobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nebentätigkeiten verwalten';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'delete any sidejob content';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'field_parliament' => 'field_parliament',
    'field_vote_node' => 'field_vote_node',
    'field_vote' => 'field_vote',
    'field_voted' => 'field_voted',
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_lname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_vote_node' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_vote' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_voted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_politician_target_id']['id'] = 'field_politician_target_id';
  $handler->display->display_options['relationships']['field_politician_target_id']['table'] = 'field_data_field_politician';
  $handler->display->display_options['relationships']['field_politician_target_id']['field'] = 'field_politician_target_id';
  $handler->display->display_options['relationships']['field_politician_target_id']['label'] = 'Politiker';
  /* Feld: Stapelverarbeitungen: Inhalt */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Einträge exportieren',
      'settings' => array(
        'url' => 'admin/abgeordnetenwatch/sidejobs/export',
      ),
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichung zurücknehmen',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 1,
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
        'show_all_tokens' => 0,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['settings'] = array(
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
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Politiker';
  $handler->display->display_options['fields']['field_user_lname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname], [field_user_fname]';
  $handler->display->display_options['fields']['field_user_lname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_lname']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => 'user/',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Feld: Inhalt: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
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
  /* Feld: Inhalt: Organization */
  $handler->display->display_options['fields']['field_sidejob_organization']['id'] = 'field_sidejob_organization';
  $handler->display->display_options['fields']['field_sidejob_organization']['table'] = 'field_data_field_sidejob_organization';
  $handler->display->display_options['fields']['field_sidejob_organization']['field'] = 'field_sidejob_organization';
  $handler->display->display_options['fields']['field_sidejob_organization']['label'] = 'Organisation';
  $handler->display->display_options['fields']['field_sidejob_organization']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sidejob_organization']['settings'] = array(
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
  /* Feld: Inhalt: Topics */
  $handler->display->display_options['fields']['field_topics']['id'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['table'] = 'field_data_field_topics';
  $handler->display->display_options['fields']['field_topics']['field'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['label'] = 'Themen';
  $handler->display->display_options['fields']['field_topics']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_topics']['settings'] = array(
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
  $handler->display->display_options['fields']['field_topics']['delta_offset'] = '0';
  /* Feld: Inhalt: Classification */
  $handler->display->display_options['fields']['field_sidejob_classification']['id'] = 'field_sidejob_classification';
  $handler->display->display_options['fields']['field_sidejob_classification']['table'] = 'field_data_field_sidejob_classification';
  $handler->display->display_options['fields']['field_sidejob_classification']['field'] = 'field_sidejob_classification';
  $handler->display->display_options['fields']['field_sidejob_classification']['settings'] = array(
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
  /* Feld: Inhalt: Date End */
  $handler->display->display_options['fields']['field_sidejob_date_end']['id'] = 'field_sidejob_date_end';
  $handler->display->display_options['fields']['field_sidejob_date_end']['table'] = 'field_data_field_sidejob_date_end';
  $handler->display->display_options['fields']['field_sidejob_date_end']['field'] = 'field_sidejob_date_end';
  $handler->display->display_options['fields']['field_sidejob_date_end']['settings'] = array(
    'format_type' => 'date_only_short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
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
  /* Feld: Inhalt: Date Start */
  $handler->display->display_options['fields']['field_sidejob_date_start']['id'] = 'field_sidejob_date_start';
  $handler->display->display_options['fields']['field_sidejob_date_start']['table'] = 'field_data_field_sidejob_date_start';
  $handler->display->display_options['fields']['field_sidejob_date_start']['field'] = 'field_sidejob_date_start';
  $handler->display->display_options['fields']['field_sidejob_date_start']['settings'] = array(
    'format_type' => 'date_only_short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
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
  /* Feld: Inhalt: Job category */
  $handler->display->display_options['fields']['field_sidejob_job_category']['id'] = 'field_sidejob_job_category';
  $handler->display->display_options['fields']['field_sidejob_job_category']['table'] = 'field_data_field_sidejob_job_category';
  $handler->display->display_options['fields']['field_sidejob_job_category']['field'] = 'field_sidejob_job_category';
  $handler->display->display_options['fields']['field_sidejob_job_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sidejob_job_category']['settings'] = array(
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
  /* Feld: Benutzer: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_user']['text'] = 'Profil';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] [delete_node] ';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Löschen';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'view_user' => 'view_user',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sidejob' => 'sidejob',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Benutzer: First Name (field_user_fname:format) */
  $handler->display->display_options['filters']['field_user_fname_format']['id'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_format']['field'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['filters']['field_user_fname_format']['group'] = 1;
  $handler->display->display_options['filters']['field_user_fname_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['operator_id'] = 'field_user_fname_format_op';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['label'] = 'Vorname';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['operator'] = 'field_user_fname_format_op';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['identifier'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['filters']['field_user_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator_id'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['label'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['identifier'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Feld: Parliament (field_parliament) */
  $handler->display->display_options['filters']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['filters']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_parliament_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator_id'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['identifier'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_parliament_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_parliament_tid']['vocabulary'] = 'parliaments';
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Veröffentlicht';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Job category (field_sidejob_job_category) */
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['id'] = 'field_sidejob_job_category_tid';
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['table'] = 'field_data_field_sidejob_job_category';
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['field'] = 'field_sidejob_job_category_tid';
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['expose']['operator_id'] = 'field_sidejob_job_category_tid_op';
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['expose']['label'] = 'Job category';
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['expose']['operator'] = 'field_sidejob_job_category_tid_op';
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['expose']['identifier'] = 'field_sidejob_job_category_tid';
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['vocabulary'] = 'job_categories';
  /* Filterkriterium: Inhalt: Topics (field_topics) */
  $handler->display->display_options['filters']['field_topics_tid']['id'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['table'] = 'field_data_field_topics';
  $handler->display->display_options['filters']['field_topics_tid']['field'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_topics_tid']['expose']['operator_id'] = 'field_topics_tid_op';
  $handler->display->display_options['filters']['field_topics_tid']['expose']['label'] = 'Themen';
  $handler->display->display_options['filters']['field_topics_tid']['expose']['operator'] = 'field_topics_tid_op';
  $handler->display->display_options['filters']['field_topics_tid']['expose']['identifier'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_topics_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_topics_tid']['vocabulary'] = 'topics';
  /* Filterkriterium: Inhalt: Job (field_job) */
  $handler->display->display_options['filters']['field_job_tid']['id'] = 'field_job_tid';
  $handler->display->display_options['filters']['field_job_tid']['table'] = 'field_data_field_job';
  $handler->display->display_options['filters']['field_job_tid']['field'] = 'field_job_tid';
  $handler->display->display_options['filters']['field_job_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_job_tid']['expose']['operator_id'] = 'field_job_tid_op';
  $handler->display->display_options['filters']['field_job_tid']['expose']['label'] = 'Job';
  $handler->display->display_options['filters']['field_job_tid']['expose']['operator'] = 'field_job_tid_op';
  $handler->display->display_options['filters']['field_job_tid']['expose']['identifier'] = 'field_job_tid';
  $handler->display->display_options['filters']['field_job_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_job_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_job_tid']['vocabulary'] = 'sidejob_jobs';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/sidejobs';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Sidejobs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

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
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['settings'] = array(
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
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Politiker';
  $handler->display->display_options['fields']['field_user_lname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname], [field_user_fname]';
  $handler->display->display_options['fields']['field_user_lname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_lname']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => 'user/',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Feld: Inhalt: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
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
  /* Feld: Inhalt: Organization */
  $handler->display->display_options['fields']['field_sidejob_organization']['id'] = 'field_sidejob_organization';
  $handler->display->display_options['fields']['field_sidejob_organization']['table'] = 'field_data_field_sidejob_organization';
  $handler->display->display_options['fields']['field_sidejob_organization']['field'] = 'field_sidejob_organization';
  $handler->display->display_options['fields']['field_sidejob_organization']['label'] = 'Organisation';
  $handler->display->display_options['fields']['field_sidejob_organization']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sidejob_organization']['settings'] = array(
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
  /* Feld: Inhalt: Topics */
  $handler->display->display_options['fields']['field_topics']['id'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['table'] = 'field_data_field_topics';
  $handler->display->display_options['fields']['field_topics']['field'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['label'] = 'Themen';
  $handler->display->display_options['fields']['field_topics']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_topics']['settings'] = array(
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
  $handler->display->display_options['fields']['field_topics']['delta_offset'] = '0';
  /* Feld: Inhalt: Classification */
  $handler->display->display_options['fields']['field_sidejob_classification']['id'] = 'field_sidejob_classification';
  $handler->display->display_options['fields']['field_sidejob_classification']['table'] = 'field_data_field_sidejob_classification';
  $handler->display->display_options['fields']['field_sidejob_classification']['field'] = 'field_sidejob_classification';
  $handler->display->display_options['fields']['field_sidejob_classification']['settings'] = array(
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
  /* Feld: Inhalt: Date End */
  $handler->display->display_options['fields']['field_sidejob_date_end']['id'] = 'field_sidejob_date_end';
  $handler->display->display_options['fields']['field_sidejob_date_end']['table'] = 'field_data_field_sidejob_date_end';
  $handler->display->display_options['fields']['field_sidejob_date_end']['field'] = 'field_sidejob_date_end';
  $handler->display->display_options['fields']['field_sidejob_date_end']['settings'] = array(
    'format_type' => 'date_only_short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
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
  /* Feld: Inhalt: Date Start */
  $handler->display->display_options['fields']['field_sidejob_date_start']['id'] = 'field_sidejob_date_start';
  $handler->display->display_options['fields']['field_sidejob_date_start']['table'] = 'field_data_field_sidejob_date_start';
  $handler->display->display_options['fields']['field_sidejob_date_start']['field'] = 'field_sidejob_date_start';
  $handler->display->display_options['fields']['field_sidejob_date_start']['settings'] = array(
    'format_type' => 'date_only_short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
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
  /* Feld: Inhalt: Job category */
  $handler->display->display_options['fields']['field_sidejob_job_category']['id'] = 'field_sidejob_job_category';
  $handler->display->display_options['fields']['field_sidejob_job_category']['table'] = 'field_data_field_sidejob_job_category';
  $handler->display->display_options['fields']['field_sidejob_job_category']['field'] = 'field_sidejob_job_category';
  $handler->display->display_options['fields']['field_sidejob_job_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sidejob_job_category']['settings'] = array(
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Beitrags-ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/sidejobs/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/sidejobs';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_sidejobs'] = array(
    t('Master'),
    t('Nebentätigkeiten verwalten'),
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
    t('Politiker'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('[field_user_lname], [field_user_fname]'),
    t('Job'),
    t('Organisation'),
    t('Themen'),
    t('Classification'),
    t('Date End'),
    t('Date Start'),
    t('Job category'),
    t('Profil'),
    t('[edit_node] [delete_node] '),
    t('Bearbeiten'),
    t('Aktionen'),
    t('Vorname'),
    t('Nachname'),
    t('Parlament'),
    t('Veröffentlicht'),
    t('Page'),
    t('Data export'),
    t('Alle'),
  );
  $export['pw_administration_sidejobs'] = $view;

  $view = new view();
  $view->name = 'pw_administration_votings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Votings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stimmen/ Votes verwalten';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any vote content';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'field_parliament' => 'field_parliament',
    'field_vote_node' => 'field_vote_node',
    'field_poll_date' => 'field_poll_date',
    'field_vote' => 'field_vote',
    'field_voted' => 'field_voted',
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_poll_date';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_lname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_vote_node' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_poll_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_vote' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_voted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_vote_user_target_id']['id'] = 'field_vote_user_target_id';
  $handler->display->display_options['relationships']['field_vote_user_target_id']['table'] = 'field_data_field_vote_user';
  $handler->display->display_options['relationships']['field_vote_user_target_id']['field'] = 'field_vote_user_target_id';
  $handler->display->display_options['relationships']['field_vote_user_target_id']['label'] = 'Politiker';
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_vote_node_target_id']['id'] = 'field_vote_node_target_id';
  $handler->display->display_options['relationships']['field_vote_node_target_id']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['relationships']['field_vote_node_target_id']['field'] = 'field_vote_node_target_id';
  $handler->display->display_options['relationships']['field_vote_node_target_id']['label'] = 'Abstimmung';
  /* Feld: Stapelverarbeitungen: Inhalt */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Einträge exportieren',
      'settings' => array(
        'url' => 'admin/abgeordnetenwatch/votings/export',
      ),
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichung zurücknehmen',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 1,
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
        'show_all_tokens' => 0,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['settings'] = array(
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
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Politiker';
  $handler->display->display_options['fields']['field_user_lname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname], [field_user_fname]';
  $handler->display->display_options['fields']['field_user_lname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_lname']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => 'user/',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['settings'] = array(
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
  $handler->display->display_options['fields']['field_parliament']['delta_offset'] = '0';
  /* Feld: Inhalt: Node Reference */
  $handler->display->display_options['fields']['field_vote_node']['id'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['field'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['label'] = 'Abstimmung/ Petition';
  $handler->display->display_options['fields']['field_vote_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
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
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_vote_node_target_id';
  /* Feld: Inhalt: Poll Date */
  $handler->display->display_options['fields']['field_poll_date']['id'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['table'] = 'field_data_field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['field'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum';
  $handler->display->display_options['fields']['field_poll_date']['settings'] = array(
    'format_type' => 'date_only_short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
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
  /* Feld: Inhalt: Vote */
  $handler->display->display_options['fields']['field_vote']['id'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['table'] = 'field_data_field_vote';
  $handler->display->display_options['fields']['field_vote']['field'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['label'] = 'Stimme';
  $handler->display->display_options['fields']['field_vote']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_vote']['settings'] = array(
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
  /* Feld: Inhalt: Voted */
  $handler->display->display_options['fields']['field_voted']['id'] = 'field_voted';
  $handler->display->display_options['fields']['field_voted']['table'] = 'field_data_field_voted';
  $handler->display->display_options['fields']['field_voted']['field'] = 'field_voted';
  $handler->display->display_options['fields']['field_voted']['label'] = 'Stimmverhalten';
  $handler->display->display_options['fields']['field_voted']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_voted']['settings'] = array(
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
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Löschen';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] [delete_node] ';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vote' => 'vote',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Benutzer: First Name (field_user_fname:format) */
  $handler->display->display_options['filters']['field_user_fname_format']['id'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_format']['field'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['filters']['field_user_fname_format']['group'] = 1;
  $handler->display->display_options['filters']['field_user_fname_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['operator_id'] = 'field_user_fname_format_op';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['label'] = 'Vorname';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['operator'] = 'field_user_fname_format_op';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['identifier'] = 'field_user_fname_format';
  $handler->display->display_options['filters']['field_user_fname_format']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['filters']['field_user_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator_id'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['label'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['identifier'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Abstimmung';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Feld: Parliament (field_parliament) */
  $handler->display->display_options['filters']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['filters']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_parliament_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator_id'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['identifier'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_parliament_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_parliament_tid']['vocabulary'] = 'parliaments';
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Veröffentlicht';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Vote (field_vote) */
  $handler->display->display_options['filters']['field_vote_tid']['id'] = 'field_vote_tid';
  $handler->display->display_options['filters']['field_vote_tid']['table'] = 'field_data_field_vote';
  $handler->display->display_options['filters']['field_vote_tid']['field'] = 'field_vote_tid';
  $handler->display->display_options['filters']['field_vote_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_vote_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_vote_tid']['expose']['operator_id'] = 'field_vote_tid_op';
  $handler->display->display_options['filters']['field_vote_tid']['expose']['label'] = 'Stimme';
  $handler->display->display_options['filters']['field_vote_tid']['expose']['operator'] = 'field_vote_tid_op';
  $handler->display->display_options['filters']['field_vote_tid']['expose']['identifier'] = 'field_vote_tid';
  $handler->display->display_options['filters']['field_vote_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_vote_tid']['vocabulary'] = 'votes';
  /* Filterkriterium: Inhalt: Voted (field_voted) */
  $handler->display->display_options['filters']['field_voted_value']['id'] = 'field_voted_value';
  $handler->display->display_options['filters']['field_voted_value']['table'] = 'field_data_field_voted';
  $handler->display->display_options['filters']['field_voted_value']['field'] = 'field_voted_value';
  $handler->display->display_options['filters']['field_voted_value']['group'] = 1;
  $handler->display->display_options['filters']['field_voted_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_voted_value']['expose']['operator_id'] = 'field_voted_value_op';
  $handler->display->display_options['filters']['field_voted_value']['expose']['label'] = 'Stimmverhalten';
  $handler->display->display_options['filters']['field_voted_value']['expose']['operator'] = 'field_voted_value_op';
  $handler->display->display_options['filters']['field_voted_value']['expose']['identifier'] = 'field_voted_value';
  $handler->display->display_options['filters']['field_voted_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'poll' => 'poll',
    'pw_petition' => 'pw_petition',
  );
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Abstimmung/ Petition';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/votings';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Stimmen/ Votes';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Beitrags-ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/votings/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/votings';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_votings'] = array(
    t('Master'),
    t('Stimmen/ Votes verwalten'),
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
    t('Politiker'),
    t('Abstimmung'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('[field_user_lname], [field_user_fname]'),
    t('Parliament'),
    t('Abstimmung/ Petition'),
    t('Typ'),
    t('Datum'),
    t('Stimme'),
    t('Stimmverhalten'),
    t('Aktionen'),
    t('[edit_node] [delete_node] '),
    t('Bearbeiten'),
    t('Vorname'),
    t('Nachname'),
    t('Parlament'),
    t('Veröffentlicht'),
    t('Page'),
    t('Data export'),
    t('Alle'),
  );
  $export['pw_administration_votings'] = $view;

  return $export;
}
