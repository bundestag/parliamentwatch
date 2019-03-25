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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
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
    t('weiter'),
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
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
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Antworten';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Ergebnisse gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
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
  /* Feld: Kommentar: Standard reply */
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['id'] = 'field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['table'] = 'field_data_field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['field'] = 'field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['label'] = 'Standard-Antwort';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['settings'] = array(
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
  /* Feld: Feld: Message ID */
  $handler->display->display_options['fields']['field_dialogue_message_id_1']['id'] = 'field_dialogue_message_id_1';
  $handler->display->display_options['fields']['field_dialogue_message_id_1']['table'] = 'field_data_field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id_1']['field'] = 'field_dialogue_message_id';
  $handler->display->display_options['fields']['field_dialogue_message_id_1']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_dialogue_message_id_1']['label'] = 'Message ID Frage';
  $handler->display->display_options['fields']['field_dialogue_message_id_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_message_id_1']['alter']['path'] = 'admin/abgeordnetenwatch/fragen?field_dialogue_message_id_value=[field_dialogue_message_id_1-value]';
  $handler->display->display_options['fields']['field_dialogue_message_id_1']['settings'] = array(
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
  /* Filterkriterium: Inhalt: Beitrags-ID */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Node Id der Frage';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Kommentar veröffentlicht';
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
  /* Filterkriterium: Kommentar: Standard reply (field_dialogue_is_standard_reply) */
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['id'] = 'field_dialogue_is_standard_reply_value';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['table'] = 'field_data_field_dialogue_is_standard_reply';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['field'] = 'field_dialogue_is_standard_reply_value';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['expose']['operator_id'] = 'field_dialogue_is_standard_reply_value_op';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['expose']['label'] = 'Ist Standardantwort';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['expose']['operator'] = 'field_dialogue_is_standard_reply_value_op';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['expose']['identifier'] = 'field_dialogue_is_standard_reply_value';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['expose']['remember_roles'] = array(
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Antworten'),
    t('Keine Ergebnisse gefunden'),
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
    t('Standard-Antwort'),
    t('Dialogue ID'),
    t('Message ID'),
    t('Message ID Frage'),
    t('Ansehen'),
    t('Bearbeiten'),
    t('Aktionen'),
    t('Node Id der Frage'),
    t('Vorname (Politiker)'),
    t('Nachname (Politiker)'),
    t('Frage veröffentlicht'),
    t('Kommentar veröffentlicht'),
    t('Ist Standardantwort'),
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
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
  /* Beziehung: Kommentar: Inhalt */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Beitrag';
  /* Beziehung: Kommentar: Author */
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
  /* Feld: Kommentar: Author */
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
  /* Feld: Kommentar: Author */
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
    t('weiter'),
    t('letzte Seite »'),
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
    t('Author'),
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
  $view->name = 'pw_administration_committees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Committees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ausschüsse';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'name' => 'name',
    'field_topics' => 'field_topics',
    'uuid' => 'uuid',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_topics' => array(
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
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
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
  /* Kopfzeile: Global: PW Administration - Create new */
  $handler->display->display_options['header']['pw_administration_create_new']['id'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['table'] = 'views';
  $handler->display->display_options['header']['pw_administration_create_new']['field'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['entity_to_create'] = 'committee';
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Ausschüssen';
  /* Beziehung: Inhalt: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Beziehung: Feld: Parliament (field_parliament) */
  $handler->display->display_options['relationships']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['relationships']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['relationships']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['relationships']['field_parliament_tid']['label'] = 'Parlament';
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
        'url' => 'admin/abgeordnetenwatch/wahlen-parlamente/committees/export',
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
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichen',
    ),
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_parliament_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Parlament';
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Feld: Inhalt: Topics */
  $handler->display->display_options['fields']['field_topics']['id'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['table'] = 'field_data_field_topics';
  $handler->display->display_options['fields']['field_topics']['field'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['label'] = 'Themen';
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
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Löschen';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'committee' => 'committee',
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
  /* Filterkriterium: Inhalt: Topics (field_topics) */
  $handler->display->display_options['filters']['field_topics_tid']['id'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['table'] = 'field_data_field_topics';
  $handler->display->display_options['filters']['field_topics_tid']['field'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_topics_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_topics_tid']['vocabulary'] = 'topics';
  /* Filterkriterium: Feld: Parliament (field_parliament) */
  $handler->display->display_options['filters']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['filters']['field_parliament_tid']['field'] = 'field_parliament_tid';
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
  $handler->display->display_options['filters']['field_parliament_tid']['type'] = 'select';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/committees';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ausschüsse';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'ausschuesse.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Inhalt: Committee URL */
  $handler->display->display_options['fields']['field_committee_url']['id'] = 'field_committee_url';
  $handler->display->display_options['fields']['field_committee_url']['table'] = 'field_data_field_committee_url';
  $handler->display->display_options['fields']['field_committee_url']['field'] = 'field_committee_url';
  $handler->display->display_options['fields']['field_committee_url']['label'] = 'Ausschuss Webseite';
  $handler->display->display_options['fields']['field_committee_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_committee_url']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_committee_url']['settings'] = array(
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
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
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
  /* Feld: Inhalt: Topics */
  $handler->display->display_options['fields']['field_topics']['id'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['table'] = 'field_data_field_topics';
  $handler->display->display_options['fields']['field_topics']['field'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['label'] = 'Themen';
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
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'committee' => 'committee',
  );
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/committees/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/committees';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_committees'] = array(
    t('Master'),
    t('Ausschüsse'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Ausschüssen'),
    t('Autor'),
    t('Parlament'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('Veröffentlichen'),
    t('Name'),
    t('Themen'),
    t('UUID'),
    t('‚Bearbeiten‘-Link'),
    t('Bearbeiten'),
    t('Link löschen'),
    t('Aktionen'),
    t('Titel'),
    t('Veröffentlicht'),
    t('Page'),
    t('Data export'),
    t('ID'),
    t('Ausschuss Webseite'),
    t('Alle'),
  );
  $export['pw_administration_committees'] = $view;

  $view = new view();
  $view->name = 'pw_administration_committees_by_parliament';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Committees by Parliament';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ausschüsse';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_committee_url' => 'field_committee_url',
    'field_parliament' => 'field_parliament',
    'field_topics' => 'field_topics',
    'uuid' => 'uuid',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'field_committee_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_topics' => array(
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
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
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
  /* Kopfzeile: Global: PW Administration - Create new */
  $handler->display->display_options['header']['pw_administration_create_new']['id'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['table'] = 'views';
  $handler->display->display_options['header']['pw_administration_create_new']['field'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['entity_to_create'] = 'committee';
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Ausschüssen';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Ausschüsse gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
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
    'action::pathauto_node_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
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
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichen',
    ),
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
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
  /* Feld: Inhalt: Topics */
  $handler->display->display_options['fields']['field_topics']['id'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['table'] = 'field_data_field_topics';
  $handler->display->display_options['fields']['field_topics']['field'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['label'] = 'Themen';
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
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Löschen';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['title'] = '%1 - Ausschüsse';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'committee' => 'committee',
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
  /* Filterkriterium: Inhalt: Topics (field_topics) */
  $handler->display->display_options['filters']['field_topics_tid']['id'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['table'] = 'field_data_field_topics';
  $handler->display->display_options['filters']['field_topics_tid']['field'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_topics_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_topics_tid']['vocabulary'] = 'topics';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%/committees';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Ausschüsse';
  $handler->display->display_options['menu']['weight'] = '40';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'ausschuesse.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Inhalt: Committee URL */
  $handler->display->display_options['fields']['field_committee_url']['id'] = 'field_committee_url';
  $handler->display->display_options['fields']['field_committee_url']['table'] = 'field_data_field_committee_url';
  $handler->display->display_options['fields']['field_committee_url']['field'] = 'field_committee_url';
  $handler->display->display_options['fields']['field_committee_url']['label'] = 'Ausschuss Webseite';
  $handler->display->display_options['fields']['field_committee_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_committee_url']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_committee_url']['settings'] = array(
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
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
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
  /* Feld: Inhalt: Topics */
  $handler->display->display_options['fields']['field_topics']['id'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['table'] = 'field_data_field_topics';
  $handler->display->display_options['fields']['field_topics']['field'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['label'] = 'Themen';
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
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  /* Kontextfilter: Inhalt: Beitrags-ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'committee' => 'committee',
  );
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'taxonomy/term/%/committees/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/committees';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_committees_by_parliament'] = array(
    t('Master'),
    t('Ausschüsse'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Ausschüssen'),
    t('Keine Ausschüsse gefunden'),
    t('Bitte auswählen'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('Veröffentlichen'),
    t('Name'),
    t('Parlament'),
    t('Themen'),
    t('UUID'),
    t('‚Bearbeiten‘-Link'),
    t('Bearbeiten'),
    t('Link löschen'),
    t('Aktionen'),
    t('Alle'),
    t('%1 - Ausschüsse'),
    t('Titel'),
    t('Veröffentlicht'),
    t('Page'),
    t('Data export'),
    t('ID'),
    t('Ausschuss Webseite'),
  );
  $export['pw_administration_committees_by_parliament'] = $view;

  $view = new view();
  $view->name = 'pw_administration_constituencies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'PW Administration Constituencies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Electoral Regions';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_parliament' => 'field_parliament',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
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
  );
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Wahlkreise';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Constituency gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Stapelverarbeitungen: Taxonomie-Begriff */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_taxonomy_term';
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
    'action::term_merge_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Feld: Taxonomie-Begriff: Number */
  $handler->display->display_options['fields']['field_constituency_nr']['id'] = 'field_constituency_nr';
  $handler->display->display_options['fields']['field_constituency_nr']['table'] = 'field_data_field_constituency_nr';
  $handler->display->display_options['fields']['field_constituency_nr']['field'] = 'field_constituency_nr';
  $handler->display->display_options['fields']['field_constituency_nr']['label'] = 'Wahlkreis-Nr.';
  $handler->display->display_options['fields']['field_constituency_nr']['settings'] = array(
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
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
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
  /* Feld: Taxonomie-Begriff: Electoral Region */
  $handler->display->display_options['fields']['field_electoral_region']['id'] = 'field_electoral_region';
  $handler->display->display_options['fields']['field_electoral_region']['table'] = 'field_data_field_electoral_region';
  $handler->display->display_options['fields']['field_electoral_region']['field'] = 'field_electoral_region';
  $handler->display->display_options['fields']['field_electoral_region']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_electoral_region']['settings'] = array(
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
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Löschen';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Löschen';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'taxonomy/term/[tid]/delete';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['title'] = '%1 - Constituencies';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  /* Filterkriterium: Taxonomie-Begriff: Vokabular */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    17 => '17',
  );
  $handler->display->display_options['filters']['vid']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%/constituencies';
  $handler->display->display_options['menu']['title'] = 'Electoral Regions';
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
  $handler->display->display_options['style_options']['filename'] = 'constituencies.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'ID';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Feld: Taxonomie-Begriff: Number */
  $handler->display->display_options['fields']['field_constituency_nr']['id'] = 'field_constituency_nr';
  $handler->display->display_options['fields']['field_constituency_nr']['table'] = 'field_data_field_constituency_nr';
  $handler->display->display_options['fields']['field_constituency_nr']['field'] = 'field_constituency_nr';
  $handler->display->display_options['fields']['field_constituency_nr']['label'] = 'Wahlkreis-Nr.';
  $handler->display->display_options['fields']['field_constituency_nr']['settings'] = array(
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
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
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
  /* Feld: Taxonomie-Begriff: Electoral Region */
  $handler->display->display_options['fields']['field_electoral_region']['id'] = 'field_electoral_region';
  $handler->display->display_options['fields']['field_electoral_region']['table'] = 'field_data_field_electoral_region';
  $handler->display->display_options['fields']['field_electoral_region']['field'] = 'field_electoral_region';
  $handler->display->display_options['fields']['field_electoral_region']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_electoral_region']['settings'] = array(
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
  /* Feld: Taxonomie-Begriff: Area Codes */
  $handler->display->display_options['fields']['field_constituency_area_codes']['id'] = 'field_constituency_area_codes';
  $handler->display->display_options['fields']['field_constituency_area_codes']['table'] = 'field_data_field_constituency_area_codes';
  $handler->display->display_options['fields']['field_constituency_area_codes']['field'] = 'field_constituency_area_codes';
  $handler->display->display_options['fields']['field_constituency_area_codes']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_constituency_area_codes']['settings'] = array(
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
  $handler->display->display_options['fields']['field_constituency_area_codes']['delta_offset'] = '0';
  /* Feld: Taxonomie-Begriff: AC Descriptor */
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['id'] = 'field_constituency_ac_descriptor';
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['table'] = 'field_data_field_constituency_ac_descriptor';
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['field'] = 'field_constituency_ac_descriptor';
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['label'] = 'Area Code Descriptor';
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['settings'] = array(
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
  /* Feld: Taxonomie-Begriff: Street */
  $handler->display->display_options['fields']['field_constituency_street']['id'] = 'field_constituency_street';
  $handler->display->display_options['fields']['field_constituency_street']['table'] = 'field_data_field_constituency_street';
  $handler->display->display_options['fields']['field_constituency_street']['field'] = 'field_constituency_street';
  $handler->display->display_options['fields']['field_constituency_street']['settings'] = array(
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
  $handler->display->display_options['fields']['field_constituency_street']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  $handler->display->display_options['path'] = 'taxonomy/term/%/constituencies/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/electoral-regions';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_constituencies'] = array(
    t('Master'),
    t('Electoral Regions'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Wahlkreise'),
    t('Keine Constituency gefunden'),
    t('Begriff-ID'),
    t('.'),
    t('Bitte auswählen'),
    t('Löschen'),
    t('Werte ändern'),
    t('Name'),
    t('Wahlkreis-Nr.'),
    t('Parlament'),
    t('Electoral Region'),
    t('Bearbeiten'),
    t('Aktionen'),
    t('Alle'),
    t('%1 - Constituencies'),
    t('Page'),
    t('Data export'),
    t('ID'),
    t('Area Codes'),
    t('Area Code Descriptor'),
    t('Street'),
  );
  $export['pw_administration_constituencies'] = $view;

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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
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
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Einträge gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Beziehung: Inhalt: Author */
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
      'override_label' => 1,
      'label' => 'Veröffentlichen',
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
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
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
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]  [delete_node] ';
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
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poll' => 'poll',
    'committee' => 'committee',
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
    t('weiter'),
    t('letzte Seite »'),
    t('Keine Einträge gefunden'),
    t('Autor'),
    t('Bitte auswählen'),
    t('Autor ändern'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('Veröffentlichen'),
    t('Metatags ändern'),
    t('Titel'),
    t('Parlament'),
    t('Typ'),
    t('UUID'),
    t('Veröffentlicht'),
    t('Aktualisiert'),
    t('Datum'),
    t('[edit_node]  [delete_node] '),
    t('Bearbeiten'),
    t('Aktionen'),
    t('Text'),
    t('Name'),
    t('Datum (JJJJ-MM-TT HH:MM:SS)'),
    t('Page'),
    t('Data export'),
    t('Alle'),
  );
  $export['pw_administration_content'] = $view;

  $view = new view();
  $view->name = 'pw_administration_electoral_regions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'PW Administration Electoral Regions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Electoral Regions';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_parliament' => 'field_parliament',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
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
  );
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Elecotral Regions';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Electoral Regions gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Stapelverarbeitungen: Taxonomie-Begriff */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_taxonomy_term';
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
    'action::term_merge_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
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
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Löschen';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Löschen';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'taxonomy/term/[tid]/delete';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['title'] = '%1 - Electoral Regions';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  /* Filterkriterium: Taxonomie-Begriff: Vokabular */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    39 => '39',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%/electoral-regions';
  $handler->display->display_options['menu']['title'] = 'Electoral Regions';
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
  $handler->display->display_options['style_options']['filename'] = 'electoral-regions.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'ID';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  $handler->display->display_options['path'] = 'taxonomy/term/%/electoral-regions/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/electoral-regions';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_electoral_regions'] = array(
    t('Master'),
    t('Electoral Regions'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Elecotral Regions'),
    t('Keine Electoral Regions gefunden'),
    t('Begriff-ID'),
    t('.'),
    t('Bitte auswählen'),
    t('Löschen'),
    t('Werte ändern'),
    t('Name'),
    t('Parlament'),
    t('Bearbeiten'),
    t('Aktionen'),
    t('Alle'),
    t('%1 - Electoral Regions'),
    t('Page'),
    t('Data export'),
    t('ID'),
  );
  $export['pw_administration_electoral_regions'] = $view;

  $view = new view();
  $view->name = 'pw_administration_files';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'PW Administration: Files';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
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
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Einträge gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
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
  $translatables['pw_administration_files'] = array(
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
    t('weiter'),
    t('letzte Seite »'),
    t('Keine Einträge gefunden'),
    t('Datei-ID'),
    t('Typ'),
    t('Größe'),
    t('Upload Datum'),
    t('Datei UUID'),
    t('Name'),
    t('Page'),
  );
  $export['pw_administration_files'] = $view;

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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
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
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Fragen';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Ergebnisse gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
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
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  /* Feld: Inhalt: Anzahl an Kommentaren */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Anzahl Antworten (Kommentare)';
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['path'] = 'admin/abgeordnetenwatch/fragen/antworten?nid=[nid]';
  $handler->display->display_options['fields']['comment_count']['empty'] = 'keine';
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
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
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
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
  $handler->display->display_options['filters']['field_user_fname_value']['group_info']['label'] = 'First Name (field_user_fname)';
  $handler->display->display_options['filters']['field_user_fname_value']['group_info']['identifier'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_user_fname_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
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
  /* Filterkriterium: Inhalt: Has comment */
  $handler->display->display_options['filters']['has_comment']['id'] = 'has_comment';
  $handler->display->display_options['filters']['has_comment']['table'] = 'node_comment_statistics';
  $handler->display->display_options['filters']['has_comment']['field'] = 'has_comment';
  $handler->display->display_options['filters']['has_comment']['value'] = 'All';
  $handler->display->display_options['filters']['has_comment']['group'] = 1;
  $handler->display->display_options['filters']['has_comment']['exposed'] = TRUE;
  $handler->display->display_options['filters']['has_comment']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['has_comment']['expose']['label'] = 'Beantwortet';
  $handler->display->display_options['filters']['has_comment']['expose']['operator'] = 'has_comment_op';
  $handler->display->display_options['filters']['has_comment']['expose']['identifier'] = 'has_comment';
  $handler->display->display_options['filters']['has_comment']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['group'] = 1;
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
  /* Feld: Inhalt: Anzahl an Kommentaren */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Anzahl Antworten (Kommentare)';
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Fragen'),
    t('Keine Ergebnisse gefunden'),
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
    t('Anzahl Antworten (Kommentare)'),
    t('keine'),
    t('.'),
    t('Zur Frage'),
    t('Vorname'),
    t('First Name (field_user_fname)'),
    t('Nachname'),
    t('Beantwortet'),
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
  $view->name = 'pw_administration_imports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'pw_parliaments_admin_imports';
  $view->human_name = 'PW Administration Imports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Importe';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administrate an import';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'label' => 'label',
    'type' => 'type',
    'name' => 'name',
    'filename' => 'filename',
    'status' => 'status',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filename' => array(
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
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
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
  /* Kopfzeile: Global: PW Administration - Create new */
  $handler->display->display_options['header']['pw_administration_create_new']['id'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['table'] = 'views';
  $handler->display->display_options['header']['pw_administration_create_new']['field'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['empty'] = TRUE;
  $handler->display->display_options['header']['pw_administration_create_new']['entity_to_create'] = 'pw_import';
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Importen';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Importe gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Beziehung: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['relationships']['parliament']['id'] = 'parliament';
  $handler->display->display_options['relationships']['parliament']['table'] = 'pw_parliaments_admin_imports';
  $handler->display->display_options['relationships']['parliament']['field'] = 'parliament';
  $handler->display->display_options['relationships']['parliament']['label'] = 'Parliament';
  /* Beziehung: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['relationships']['file']['id'] = 'file';
  $handler->display->display_options['relationships']['file']['table'] = 'pw_parliaments_admin_imports';
  $handler->display->display_options['relationships']['file']['field'] = 'file';
  $handler->display->display_options['relationships']['file']['label'] = 'CSV-Datei';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'pw_parliaments_admin_imports';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'pw_parliaments_admin_imports';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = 'Importieren';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = 'admin/abgeordnetenwatch/imports/[id]';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'pw_parliaments_admin_imports';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'parliament';
  $handler->display->display_options['fields']['name']['label'] = 'Parlament';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/abgeordnetenwatch/imports/[id]';
  /* Feld: Datei: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'file';
  $handler->display->display_options['fields']['filename']['label'] = 'CSV';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'pw_parliaments_admin_imports';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/abgeordnetenwatch/imports/[id]/edit';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Löschen';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Löschen';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/abgeordnetenwatch/imports/[id]/delete';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/imports';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Importe';
  $handler->display->display_options['menu']['name'] = 'management';
  $translatables['pw_administration_imports'] = array(
    t('Master'),
    t('Importe'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Importen'),
    t('Keine Importe gefunden'),
    t('Parliament'),
    t('CSV-Datei'),
    t('Importieren'),
    t('Beschädigte Behandlungsroutine pw_parliaments_admin_imports.type'),
    t('Parlament'),
    t('CSV'),
    t('Bearbeiten'),
    t('Löschen'),
    t('Aktionen'),
    t('Page'),
  );
  $export['pw_administration_imports'] = $view;

  $view = new view();
  $view->name = 'pw_administration_imports_constituency_datasets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'pw_parliaments_admin_imports_constituencies_datasets';
  $view->human_name = 'PW Administration Imports Constituency Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administrate an import';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'constituency' => 'constituency',
    'constituency_nr' => 'constituency_nr',
    'area_code' => 'area_code',
    'area_code_descriptor' => 'area_code_descriptor',
    'street' => 'street',
  );
  $handler->display->display_options['style_options']['default'] = 'constituency';
  $handler->display->display_options['style_options']['info'] = array(
    'constituency' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'constituency_nr' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'area_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'area_code_descriptor' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'street' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Datensätzen';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Es wurden keine Wahlkreis-Datensätze gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['constituency']['id'] = 'constituency';
  $handler->display->display_options['fields']['constituency']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['fields']['constituency']['field'] = 'constituency';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['constituency_nr']['id'] = 'constituency_nr';
  $handler->display->display_options['fields']['constituency_nr']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['fields']['constituency_nr']['field'] = 'constituency_nr';
  $handler->display->display_options['fields']['constituency_nr']['label'] = 'Constituency nr';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['area_code']['id'] = 'area_code';
  $handler->display->display_options['fields']['area_code']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['fields']['area_code']['field'] = 'area_code';
  $handler->display->display_options['fields']['area_code']['label'] = 'Area code';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['area_code_descriptor']['id'] = 'area_code_descriptor';
  $handler->display->display_options['fields']['area_code_descriptor']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['fields']['area_code_descriptor']['field'] = 'area_code_descriptor';
  $handler->display->display_options['fields']['area_code_descriptor']['label'] = 'Area code descriptor';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['street']['id'] = 'street';
  $handler->display->display_options['fields']['street']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['fields']['street']['field'] = 'street';
  $handler->display->display_options['fields']['street']['label'] = 'Street';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['errors']['id'] = 'errors';
  $handler->display->display_options['fields']['errors']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['fields']['errors']['field'] = 'errors';
  $handler->display->display_options['fields']['errors']['label'] = 'Fehler';
  /* Kontextfilter: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['arguments']['import']['id'] = 'import';
  $handler->display->display_options['arguments']['import']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['arguments']['import']['field'] = 'import';
  $handler->display->display_options['arguments']['import']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['import']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['import']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['import']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['import']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['import']['summary_options']['items_per_page'] = '25';
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['constituency_nr']['id'] = 'constituency_nr';
  $handler->display->display_options['filters']['constituency_nr']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['filters']['constituency_nr']['field'] = 'constituency_nr';
  $handler->display->display_options['filters']['constituency_nr']['exposed'] = TRUE;
  $handler->display->display_options['filters']['constituency_nr']['expose']['operator_id'] = 'constituency_nr_op';
  $handler->display->display_options['filters']['constituency_nr']['expose']['label'] = 'Constituency nr';
  $handler->display->display_options['filters']['constituency_nr']['expose']['operator'] = 'constituency_nr_op';
  $handler->display->display_options['filters']['constituency_nr']['expose']['identifier'] = 'constituency_nr';
  $handler->display->display_options['filters']['constituency_nr']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['constituency']['id'] = 'constituency';
  $handler->display->display_options['filters']['constituency']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['filters']['constituency']['field'] = 'constituency';
  $handler->display->display_options['filters']['constituency']['exposed'] = TRUE;
  $handler->display->display_options['filters']['constituency']['expose']['operator_id'] = 'constituency_op';
  $handler->display->display_options['filters']['constituency']['expose']['label'] = 'Wahlkreis';
  $handler->display->display_options['filters']['constituency']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['constituency']['expose']['operator'] = 'constituency_op';
  $handler->display->display_options['filters']['constituency']['expose']['identifier'] = 'constituency';
  $handler->display->display_options['filters']['constituency']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'in';
  $handler->display->display_options['filters']['status']['value'] = array();
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['area_code']['id'] = 'area_code';
  $handler->display->display_options['filters']['area_code']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['filters']['area_code']['field'] = 'area_code';
  $handler->display->display_options['filters']['area_code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['area_code']['expose']['operator_id'] = 'area_code_op';
  $handler->display->display_options['filters']['area_code']['expose']['label'] = 'Area code';
  $handler->display->display_options['filters']['area_code']['expose']['operator'] = 'area_code_op';
  $handler->display->display_options['filters']['area_code']['expose']['identifier'] = 'area_code';
  $handler->display->display_options['filters']['area_code']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['area_code_descriptor']['id'] = 'area_code_descriptor';
  $handler->display->display_options['filters']['area_code_descriptor']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['filters']['area_code_descriptor']['field'] = 'area_code_descriptor';
  $handler->display->display_options['filters']['area_code_descriptor']['exposed'] = TRUE;
  $handler->display->display_options['filters']['area_code_descriptor']['expose']['operator_id'] = 'area_code_descriptor_op';
  $handler->display->display_options['filters']['area_code_descriptor']['expose']['label'] = 'Area code descriptor';
  $handler->display->display_options['filters']['area_code_descriptor']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['area_code_descriptor']['expose']['operator'] = 'area_code_descriptor_op';
  $handler->display->display_options['filters']['area_code_descriptor']['expose']['identifier'] = 'area_code_descriptor';
  $handler->display->display_options['filters']['area_code_descriptor']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['street']['id'] = 'street';
  $handler->display->display_options['filters']['street']['table'] = 'pw_parliaments_admin_imports_constituencies_datasets';
  $handler->display->display_options['filters']['street']['field'] = 'street';
  $handler->display->display_options['filters']['street']['exposed'] = TRUE;
  $handler->display->display_options['filters']['street']['expose']['operator_id'] = 'street_op';
  $handler->display->display_options['filters']['street']['expose']['label'] = 'Street';
  $handler->display->display_options['filters']['street']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['street']['expose']['operator'] = 'street_op';
  $handler->display->display_options['filters']['street']['expose']['identifier'] = 'street';
  $handler->display->display_options['filters']['street']['expose']['remember_roles'] = array(
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

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'constituencies.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/imports/%/datasets-export';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
  );
  $translatables['pw_administration_imports_constituency_datasets'] = array(
    t('Master'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Datensätzen'),
    t('Es wurden keine Wahlkreis-Datensätze gefunden'),
    t('Beschädigte Behandlungsroutine pw_parliaments_admin_imports_constituencies_datasets.constituency'),
    t('Constituency nr'),
    t('Area code'),
    t('Area code descriptor'),
    t('Street'),
    t('Status'),
    t('Fehler'),
    t('Alle'),
    t('Wahlkreis'),
    t('Data export'),
  );
  $export['pw_administration_imports_constituency_datasets'] = $view;

  $view = new view();
  $view->name = 'pw_administration_imports_constituency_structured_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'pw_parliaments_admin_imports_constituencies_structured';
  $view->human_name = 'PW Administration Imports Constituency Structured Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administrate an import';
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
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_constituency_nr' => 'field_constituency_nr',
    'field_constituency_area_codes' => 'field_constituency_area_codes',
    'field_constituency_ac_descriptor' => 'field_constituency_ac_descriptor',
    'field_constituency_street' => 'field_constituency_street',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_constituency_nr' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_constituency_area_codes' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_constituency_ac_descriptor' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_constituency_street' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Wahlkreisen';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine strukturierten Daten gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Wahlkreis';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['field_constituency_nr']['id'] = 'field_constituency_nr';
  $handler->display->display_options['fields']['field_constituency_nr']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['fields']['field_constituency_nr']['field'] = 'field_constituency_nr';
  $handler->display->display_options['fields']['field_constituency_nr']['label'] = 'Constituency nr';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['field_constituency_area_codes']['id'] = 'field_constituency_area_codes';
  $handler->display->display_options['fields']['field_constituency_area_codes']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['fields']['field_constituency_area_codes']['field'] = 'field_constituency_area_codes';
  $handler->display->display_options['fields']['field_constituency_area_codes']['label'] = 'Area codes';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['id'] = 'field_constituency_ac_descriptor';
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['field'] = 'field_constituency_ac_descriptor';
  $handler->display->display_options['fields']['field_constituency_ac_descriptor']['label'] = 'Area code descriptors';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['field_constituency_street']['id'] = 'field_constituency_street';
  $handler->display->display_options['fields']['field_constituency_street']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['fields']['field_constituency_street']['field'] = 'field_constituency_street';
  $handler->display->display_options['fields']['field_constituency_street']['label'] = 'Streets';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['errors']['id'] = 'errors';
  $handler->display->display_options['fields']['errors']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['fields']['errors']['field'] = 'errors';
  $handler->display->display_options['fields']['errors']['label'] = 'Errors';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Kontextfilter: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['arguments']['import']['id'] = 'import';
  $handler->display->display_options['arguments']['import']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['arguments']['import']['field'] = 'import';
  $handler->display->display_options['arguments']['import']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['import']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['import']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['import']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['import']['summary_options']['items_per_page'] = '25';
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['id'] = 'field_constituency_ac_descriptor';
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['field'] = 'field_constituency_ac_descriptor';
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['expose']['operator_id'] = 'field_constituency_ac_descriptor_op';
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['expose']['label'] = 'Area code descriptors';
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['expose']['operator'] = 'field_constituency_ac_descriptor_op';
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['expose']['identifier'] = 'field_constituency_ac_descriptor';
  $handler->display->display_options['filters']['field_constituency_ac_descriptor']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['field_constituency_area_codes']['id'] = 'field_constituency_area_codes';
  $handler->display->display_options['filters']['field_constituency_area_codes']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['filters']['field_constituency_area_codes']['field'] = 'field_constituency_area_codes';
  $handler->display->display_options['filters']['field_constituency_area_codes']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_constituency_area_codes']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_constituency_area_codes']['expose']['operator_id'] = 'field_constituency_area_codes_op';
  $handler->display->display_options['filters']['field_constituency_area_codes']['expose']['label'] = 'Area codes';
  $handler->display->display_options['filters']['field_constituency_area_codes']['expose']['operator'] = 'field_constituency_area_codes_op';
  $handler->display->display_options['filters']['field_constituency_area_codes']['expose']['identifier'] = 'field_constituency_area_codes';
  $handler->display->display_options['filters']['field_constituency_area_codes']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['field_constituency_nr']['id'] = 'field_constituency_nr';
  $handler->display->display_options['filters']['field_constituency_nr']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['filters']['field_constituency_nr']['field'] = 'field_constituency_nr';
  $handler->display->display_options['filters']['field_constituency_nr']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_constituency_nr']['expose']['operator_id'] = 'field_constituency_nr_op';
  $handler->display->display_options['filters']['field_constituency_nr']['expose']['label'] = 'Constituency nr';
  $handler->display->display_options['filters']['field_constituency_nr']['expose']['operator'] = 'field_constituency_nr_op';
  $handler->display->display_options['filters']['field_constituency_nr']['expose']['identifier'] = 'field_constituency_nr';
  $handler->display->display_options['filters']['field_constituency_nr']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['field_constituency_street']['id'] = 'field_constituency_street';
  $handler->display->display_options['filters']['field_constituency_street']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['filters']['field_constituency_street']['field'] = 'field_constituency_street';
  $handler->display->display_options['filters']['field_constituency_street']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_constituency_street']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_constituency_street']['expose']['operator_id'] = 'field_constituency_street_op';
  $handler->display->display_options['filters']['field_constituency_street']['expose']['label'] = 'Streets';
  $handler->display->display_options['filters']['field_constituency_street']['expose']['operator'] = 'field_constituency_street_op';
  $handler->display->display_options['filters']['field_constituency_street']['expose']['identifier'] = 'field_constituency_street';
  $handler->display->display_options['filters']['field_constituency_street']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Wahlkreis';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'pw_parliaments_admin_imports_constituencies_structured';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'in';
  $handler->display->display_options['filters']['status']['value'] = array();
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
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
  $translatables['pw_administration_imports_constituency_structured_data'] = array(
    t('Master'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Wahlkreisen'),
    t('Keine strukturierten Daten gefunden'),
    t('Wahlkreis'),
    t('Constituency nr'),
    t('Area codes'),
    t('Area code descriptors'),
    t('Streets'),
    t('Errors'),
    t('Status'),
    t('Alle'),
  );
  $export['pw_administration_imports_constituency_structured_data'] = $view;

  $view = new view();
  $view->name = 'pw_administration_parliaments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'PW Administration Parliaments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Parlamente';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'tid' => 'tid',
    'name' => 'name',
    'field_parliament_election' => 'field_parliament_election',
    'field_parliament_valid' => 'field_parliament_valid',
    'field_parliament_valid_1' => 'field_parliament_valid_1',
    'field_affiliates' => 'field_affiliates',
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'field_parliament_election';
  $handler->display->display_options['style_options']['info'] = array(
    'tid' => array(
      'sortable' => 0,
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
    'field_parliament_election' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament_valid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament_valid_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_affiliates' => array(
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
    'ctools_dropdown' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Kopfzeile: Global: PW Administration - Create new */
  $handler->display->display_options['header']['pw_administration_create_new']['id'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['table'] = 'views';
  $handler->display->display_options['header']['pw_administration_create_new']['field'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['entity_to_create'] = 'parliament';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Parlamente gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'ID';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Feld: Taxonomie-Begriff: Election */
  $handler->display->display_options['fields']['field_parliament_election']['id'] = 'field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['table'] = 'field_data_field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['field'] = 'field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['label'] = 'Wahl';
  $handler->display->display_options['fields']['field_parliament_election']['settings'] = array(
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
  /* Feld: Taxonomie-Begriff: Valid Date */
  $handler->display->display_options['fields']['field_parliament_valid']['id'] = 'field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid']['table'] = 'field_data_field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid']['field'] = 'field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid']['label'] = 'Valid Date1 (Wahlperiode)';
  $handler->display->display_options['fields']['field_parliament_valid']['settings'] = array(
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
  $handler->display->display_options['fields']['field_parliament_valid']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_parliament_valid']['delta_offset'] = '0';
  /* Feld: Taxonomie-Begriff: Valid Date */
  $handler->display->display_options['fields']['field_parliament_valid_1']['id'] = 'field_parliament_valid_1';
  $handler->display->display_options['fields']['field_parliament_valid_1']['table'] = 'field_data_field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid_1']['field'] = 'field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid_1']['label'] = 'Valid Date 2 (Legislatur)';
  $handler->display->display_options['fields']['field_parliament_valid_1']['settings'] = array(
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
  $handler->display->display_options['fields']['field_parliament_valid_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_parliament_valid_1']['delta_offset'] = '1';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Politiker';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Politiker-Übersicht';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'taxonomy/term/[tid]/politicians';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_5']['id'] = 'nothing_5';
  $handler->display->display_options['fields']['nothing_5']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_5']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_5']['label'] = 'Ausschüsse';
  $handler->display->display_options['fields']['nothing_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_5']['alter']['text'] = 'Ausschüsse';
  $handler->display->display_options['fields']['nothing_5']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_5']['alter']['path'] = 'taxonomy/term/[tid]/committees';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['label'] = 'Abstimmungen';
  $handler->display->display_options['fields']['nothing_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = 'Abstimmungen';
  $handler->display->display_options['fields']['nothing_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_3']['alter']['path'] = 'taxonomy/term/[tid]/polls';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_6']['id'] = 'nothing_6';
  $handler->display->display_options['fields']['nothing_6']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_6']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_6']['label'] = 'Electoral Regions';
  $handler->display->display_options['fields']['nothing_6']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_6']['alter']['text'] = 'Electoral Regions';
  $handler->display->display_options['fields']['nothing_6']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_6']['alter']['path'] = 'taxonomy/term/[tid]/electoral-regions';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_7']['id'] = 'nothing_7';
  $handler->display->display_options['fields']['nothing_7']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_7']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_7']['label'] = 'Constituencies';
  $handler->display->display_options['fields']['nothing_7']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_7']['alter']['text'] = 'Constituencies';
  $handler->display->display_options['fields']['nothing_7']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_7']['alter']['path'] = 'taxonomy/term/[tid]/constituencies';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['label'] = 'Links';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '<ul>
<li>[nothing_2]</li>
<li>[nothing_3]</li>
<li>[nothing_5]</li>
<li>[nothing_6]</li>
<li>[nothing_7]</li>
</ul>';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Löschen';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Löschen';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'taxonomy/term/[tid]/delete';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Filterkriterium: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'parliaments' => 'parliaments',
  );
  /* Filterkriterium: Taxonomie-Begriff: Begriff */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = '';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'parliaments';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/parliaments';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Parlamente';
  $handler->display->display_options['menu']['name'] = 'management';
  $translatables['pw_administration_parliaments'] = array(
    t('Master'),
    t('Parlamente'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Keine Parlamente gefunden'),
    t('ID'),
    t('.'),
    t('Name'),
    t('Wahl'),
    t('Valid Date1 (Wahlperiode)'),
    t('Valid Date 2 (Legislatur)'),
    t('Politiker'),
    t('Politiker-Übersicht'),
    t('Ausschüsse'),
    t('Abstimmungen'),
    t('Electoral Regions'),
    t('Constituencies'),
    t('Links'),
    t('<ul>
<li>[nothing_2]</li>
<li>[nothing_3]</li>
<li>[nothing_5]</li>
<li>[nothing_6]</li>
<li>[nothing_7]</li>
</ul>'),
    t('Bearbeiten'),
    t('Löschen'),
    t('Aktionen'),
    t('Page'),
  );
  $export['pw_administration_parliaments'] = $view;

  $view = new view();
  $view->name = 'pw_administration_parties';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'PW Administration Parties';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Parteien';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit terms in 19';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'tid' => 'tid',
    'name' => 'name',
    'description' => 'description',
    'uuid' => 'uuid',
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'tid' => array(
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
    'description' => array(
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
    'ctools_dropdown' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Kopfzeile: Global: PW Administration - Create new */
  $handler->display->display_options['header']['pw_administration_create_new']['id'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['table'] = 'views';
  $handler->display->display_options['header']['pw_administration_create_new']['field'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['entity_to_create'] = 'party';
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Parteien';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Parlamente gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'ID';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Feld: Taxonomie-Begriff: Begriffsbeschreibung */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Beschreibung';
  /* Feld: Taxonomie-Begriff: Taxonomie-Begriff UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Löschen';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Löschen';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'taxonomy/term/[tid]/delete';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Filterkriterium: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'party' => 'party',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/parties';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Parteien';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['pw_administration_parties'] = array(
    t('Master'),
    t('Parteien'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Parteien'),
    t('Keine Parlamente gefunden'),
    t('ID'),
    t('.'),
    t('Name'),
    t('Beschreibung'),
    t('UUID'),
    t('Bearbeiten'),
    t('Löschen'),
    t('Aktionen'),
    t('Page'),
  );
  $export['pw_administration_parties'] = $view;

  $view = new view();
  $view->name = 'pw_administration_politicians';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'PW Administration Politicians';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Politiker verwalten';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
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
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'field_user_lname' => 'field_user_lname',
    'field_user_fname' => 'field_user_fname',
    'mail' => 'mail',
    'name' => 'name',
    'rid' => 'rid',
    'uuid' => 'uuid',
    'name_4' => 'name_4',
    'name_1' => 'name_1',
    'field_user_constituency' => 'field_user_constituency',
    'name_2' => 'name_2',
    'name_3' => 'name_3',
    'field_user_joined' => 'field_user_joined',
    'field_user_retired' => 'field_user_retired',
    'nothing_1' => 'nothing_1',
    'edit_node' => 'edit_node',
    'nothing' => 'nothing',
    'cancel_node' => 'cancel_node',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_lname';
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
    'field_user_lname' => array(
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
      'empty_column' => 0,
    ),
    'mail' => array(
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
    'rid' => array(
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
    'name_4' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_constituency' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_joined' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_retired' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cancel_node' => array(
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
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Politikern';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Politiker gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Beziehung: Benutzer: Parlament (field_user_parliament) */
  $handler->display->display_options['relationships']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['relationships']['field_user_parliament_tid']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['relationships']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['relationships']['field_user_parliament_tid']['label'] = 'Parlament';
  /* Beziehung: Benutzer: Liste (field_user_list) */
  $handler->display->display_options['relationships']['field_user_list_tid']['id'] = 'field_user_list_tid';
  $handler->display->display_options['relationships']['field_user_list_tid']['table'] = 'field_data_field_user_list';
  $handler->display->display_options['relationships']['field_user_list_tid']['field'] = 'field_user_list_tid';
  $handler->display->display_options['relationships']['field_user_list_tid']['label'] = 'Liste';
  /* Beziehung: Benutzer: Listenposition (field_user_list_position) */
  $handler->display->display_options['relationships']['field_user_list_position_tid']['id'] = 'field_user_list_position_tid';
  $handler->display->display_options['relationships']['field_user_list_position_tid']['table'] = 'field_data_field_user_list_position';
  $handler->display->display_options['relationships']['field_user_list_position_tid']['field'] = 'field_user_list_position_tid';
  $handler->display->display_options['relationships']['field_user_list_position_tid']['label'] = 'Listenposition';
  /* Beziehung: Benutzer: Partei (field_user_party) */
  $handler->display->display_options['relationships']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['relationships']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['relationships']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['relationships']['field_user_party_tid']['label'] = 'Partei';
  /* Feld: Stapelverarbeitungen: Benutzer */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
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
        'url' => 'admin/abgeordnetenwatch/wahlen-parlamente/politicians/export',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
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
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
  );
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Name';
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
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'Vorname';
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
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Benutzername';
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_4']['id'] = 'name_4';
  $handler->display->display_options['fields']['name_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_4']['field'] = 'name';
  $handler->display->display_options['fields']['name_4']['relationship'] = 'field_user_party_tid';
  $handler->display->display_options['fields']['name_4']['label'] = 'Partei';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_user_parliament_tid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Aktuelles/ letztes Parlament';
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = TRUE;
  /* Feld: Benutzer: Wahlkreis */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_constituency']['settings'] = array(
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
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'field_user_list_tid';
  $handler->display->display_options['fields']['name_2']['label'] = 'Liste';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_3']['id'] = 'name_3';
  $handler->display->display_options['fields']['name_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_3']['field'] = 'name';
  $handler->display->display_options['fields']['name_3']['relationship'] = 'field_user_list_position_tid';
  $handler->display->display_options['fields']['name_3']['label'] = 'Listenposition';
  /* Feld: Benutzer: Parlament beigetreten */
  $handler->display->display_options['fields']['field_user_joined']['id'] = 'field_user_joined';
  $handler->display->display_options['fields']['field_user_joined']['table'] = 'field_data_field_user_joined';
  $handler->display->display_options['fields']['field_user_joined']['field'] = 'field_user_joined';
  $handler->display->display_options['fields']['field_user_joined']['settings'] = array(
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
  /* Feld: Benutzer: Parlament verlassen */
  $handler->display->display_options['fields']['field_user_retired']['id'] = 'field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['table'] = 'field_data_field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['field'] = 'field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['settings'] = array(
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
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Links';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Alle Revisionen';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'user/[uid]/revisions';
  /* Feld: Benutzer: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Revisionen';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user/[uid]/revisions';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Link zum Account löschen */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cancel_node']['text'] = 'Löschen';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_node' => 'edit_node',
    'nothing' => 'nothing',
    'cancel_node' => 'cancel_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    181527986 => '181527986',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
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
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['operator'] = 'allwords';
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
  /* Filterkriterium: Benutzer: E-Mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Benutzername';
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
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid_1']['id'] = 'rid_1';
  $handler->display->display_options['filters']['rid_1']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid_1']['field'] = 'rid';
  $handler->display->display_options['filters']['rid_1']['value'] = array(
    140336230 => '140336230',
    185431326 => '185431326',
  );
  $handler->display->display_options['filters']['rid_1']['group'] = 1;
  $handler->display->display_options['filters']['rid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid_1']['expose']['operator_id'] = 'rid_1_op';
  $handler->display->display_options['filters']['rid_1']['expose']['label'] = 'Rollen';
  $handler->display->display_options['filters']['rid_1']['expose']['operator'] = 'rid_1_op';
  $handler->display->display_options['filters']['rid_1']['expose']['identifier'] = 'rid_1';
  $handler->display->display_options['filters']['rid_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['rid_1']['expose']['reduce'] = TRUE;
  /* Filterkriterium: Benutzer: Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Benutzer: Fraktion (field_user_fraction) */
  $handler->display->display_options['filters']['field_user_fraction_tid']['id'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['table'] = 'field_data_field_user_fraction';
  $handler->display->display_options['filters']['field_user_fraction_tid']['field'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_user_fraction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_fraction_tid']['vocabulary'] = 'fraction';
  /* Filterkriterium: Benutzer: Parlament (field_user_parliament) */
  $handler->display->display_options['filters']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator_id'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['label'] = 'Aktuelles/ letztes Parlament';
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
  $handler->display->display_options['filters']['field_user_parliament_tid']['type'] = 'select';
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
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_user_constituency_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: Benutzer: Geschlecht (field_user_gender) */
  $handler->display->display_options['filters']['field_user_gender_value']['id'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['table'] = 'field_data_field_user_gender';
  $handler->display->display_options['filters']['field_user_gender_value']['field'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_gender_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['operator_id'] = 'field_user_gender_value_op';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['label'] = 'Geschlecht';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['operator'] = 'field_user_gender_value_op';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['identifier'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: Listenposition (field_user_list_position) */
  $handler->display->display_options['filters']['field_user_list_position_tid']['id'] = 'field_user_list_position_tid';
  $handler->display->display_options['filters']['field_user_list_position_tid']['table'] = 'field_data_field_user_list_position';
  $handler->display->display_options['filters']['field_user_list_position_tid']['field'] = 'field_user_list_position_tid';
  $handler->display->display_options['filters']['field_user_list_position_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_list_position_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_list_position_tid']['expose']['operator_id'] = 'field_user_list_position_tid_op';
  $handler->display->display_options['filters']['field_user_list_position_tid']['expose']['label'] = 'Listenposition';
  $handler->display->display_options['filters']['field_user_list_position_tid']['expose']['operator'] = 'field_user_list_position_tid_op';
  $handler->display->display_options['filters']['field_user_list_position_tid']['expose']['identifier'] = 'field_user_list_position_tid';
  $handler->display->display_options['filters']['field_user_list_position_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_user_list_position_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_list_position_tid']['vocabulary'] = 'list_position';
  /* Filterkriterium: Benutzer: Parlament verlassen (field_user_retired) */
  $handler->display->display_options['filters']['field_user_retired_value']['id'] = 'field_user_retired_value';
  $handler->display->display_options['filters']['field_user_retired_value']['table'] = 'field_data_field_user_retired';
  $handler->display->display_options['filters']['field_user_retired_value']['field'] = 'field_user_retired_value';
  $handler->display->display_options['filters']['field_user_retired_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_retired_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_retired_value']['expose']['operator_id'] = 'field_user_retired_value_op';
  $handler->display->display_options['filters']['field_user_retired_value']['expose']['label'] = 'Parlament verlassen (field_user_retired)';
  $handler->display->display_options['filters']['field_user_retired_value']['expose']['operator'] = 'field_user_retired_value_op';
  $handler->display->display_options['filters']['field_user_retired_value']['expose']['identifier'] = 'field_user_retired_value';
  $handler->display->display_options['filters']['field_user_retired_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_user_retired_value']['group_info']['label'] = 'Parlament verlassen';
  $handler->display->display_options['filters']['field_user_retired_value']['group_info']['identifier'] = 'field_user_retired_value';
  $handler->display->display_options['filters']['field_user_retired_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Ausgeschieden',
      'operator' => '!=',
      'value' => 'now',
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/politicians';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Politiker';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'politiker.csv';
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
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'Vorname';
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
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Nachname';
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname], [field_user_fname]';
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
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Feld: Benutzer: Partei */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party']['settings'] = array(
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
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Benutzer: Parlament */
  $handler->display->display_options['fields']['field_user_parliament']['id'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['field'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['settings'] = array(
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
  /* Feld: Benutzer: Wahlkreis */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_constituency']['settings'] = array(
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
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Benutzer: Liste */
  $handler->display->display_options['fields']['field_user_list']['id'] = 'field_user_list';
  $handler->display->display_options['fields']['field_user_list']['table'] = 'field_data_field_user_list';
  $handler->display->display_options['fields']['field_user_list']['field'] = 'field_user_list';
  $handler->display->display_options['fields']['field_user_list']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_list']['settings'] = array(
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
  /* Feld: Benutzer: Listenposition */
  $handler->display->display_options['fields']['field_user_list_position']['id'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['table'] = 'field_data_field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['field'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_list_position']['settings'] = array(
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
  /* Feld: Benutzer: Parlament beigetreten */
  $handler->display->display_options['fields']['field_user_joined']['id'] = 'field_user_joined';
  $handler->display->display_options['fields']['field_user_joined']['table'] = 'field_data_field_user_joined';
  $handler->display->display_options['fields']['field_user_joined']['field'] = 'field_user_joined';
  $handler->display->display_options['fields']['field_user_joined']['settings'] = array(
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
  /* Feld: Benutzer: Parlament verlassen */
  $handler->display->display_options['fields']['field_user_retired']['id'] = 'field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['table'] = 'field_data_field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['field'] = 'field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['settings'] = array(
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Benutzer: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/politicians/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/politicians';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_politicians'] = array(
    t('Master'),
    t('Politiker verwalten'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Politikern'),
    t('Keine Politiker gefunden'),
    t('Parlament'),
    t('Liste'),
    t('Listenposition'),
    t('Partei'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Löschen'),
    t('Change value'),
    t('Name'),
    t('Vorname'),
    t('E-Mail'),
    t('Benutzername'),
    t('Rollen'),
    t('UUID'),
    t('Aktuelles/ letztes Parlament'),
    t('Wahlkreis'),
    t('Parlament beigetreten'),
    t('Parlament verlassen'),
    t('Links'),
    t('Alle Revisionen'),
    t('Bearbeiten'),
    t('Revisionen'),
    t('Aktionen'),
    t('Nachname'),
    t('Fraktion'),
    t('Geschlecht'),
    t('Parlament verlassen (field_user_retired)'),
    t('Page'),
    t('Data export'),
    t('Uid'),
    t('[field_user_lname], [field_user_fname]'),
    t('Alle'),
  );
  $export['pw_administration_politicians'] = $view;

  $view = new view();
  $view->name = 'pw_administration_politicians_of_parliament';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'user_archive_cache';
  $view->human_name = 'PW Administration Politicians of Parliament';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Politiker';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'field_user_lname-revision_id' => 'field_user_lname-revision_id',
    'field_user_fname-revision_id' => 'field_user_fname-revision_id',
    'user_role' => 'user_role',
    'name_5' => 'name_5',
    'name_1' => 'name_1',
    'field_user_joined-revision_id' => 'field_user_joined-revision_id',
    'field_user_retired-revision_id' => 'field_user_retired-revision_id',
    'name_2' => 'name_2',
    'field_user_list_won-revision_id' => 'field_user_list_won-revision_id',
    'name_3' => 'name_3',
    'field_user_constituency-revision_id' => 'field_user_constituency-revision_id',
    'field_user_constituency_won-revision_id' => 'field_user_constituency_won-revision_id',
    'field_user_election_result-revision_id' => 'field_user_election_result-revision_id',
    'question_form_open' => 'question_form_open',
    'uuid' => 'uuid',
    'name' => 'name',
    'edit_revision' => 'edit_revision',
    'nothing' => 'nothing',
    'ctools_dropdown' => 'ctools_dropdown',
    'question_form_open_1' => 'question_form_open_1',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_lname-revision_id';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
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
    'field_user_fname-revision_id' => array(
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
    'name_5' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_joined-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_retired-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_list_won-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_3' => array(
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
    'field_user_constituency_won-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_election_result-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'question_form_open' => array(
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_revision' => array(
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
    'question_form_open_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<p>Zeigt @start - @end von @total Politiker-Profilen</p>

Diese Übersicht listet die Profile für Kandidaturen wie für Mandate auf. Wenn ein/e Politiker/in doppelt aufgeführt ist, sollte das daran liegen, dass jeweils das Profil für die Kandidatur und für das gewonnene Mandat aufgelistet werden.';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Politiker gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Beziehung: PW User archive: User revision */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'user_archive_cache';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  $handler->display->display_options['relationships']['vid']['label'] = 'User Revision';
  $handler->display->display_options['relationships']['vid']['required'] = TRUE;
  /* Beziehung: Benutzer (Historische Daten): Fraktion (field_user_fraction) */
  $handler->display->display_options['relationships']['field_user_fraction_tid']['id'] = 'field_user_fraction_tid';
  $handler->display->display_options['relationships']['field_user_fraction_tid']['table'] = 'field_revision_field_user_fraction';
  $handler->display->display_options['relationships']['field_user_fraction_tid']['field'] = 'field_user_fraction_tid';
  $handler->display->display_options['relationships']['field_user_fraction_tid']['relationship'] = 'vid';
  $handler->display->display_options['relationships']['field_user_fraction_tid']['label'] = 'Fraktion';
  /* Beziehung: Benutzer (Historische Daten): Liste (field_user_list) */
  $handler->display->display_options['relationships']['field_user_list_tid']['id'] = 'field_user_list_tid';
  $handler->display->display_options['relationships']['field_user_list_tid']['table'] = 'field_revision_field_user_list';
  $handler->display->display_options['relationships']['field_user_list_tid']['field'] = 'field_user_list_tid';
  $handler->display->display_options['relationships']['field_user_list_tid']['relationship'] = 'vid';
  $handler->display->display_options['relationships']['field_user_list_tid']['label'] = 'Liste';
  /* Beziehung: Benutzer (Historische Daten): Listenposition (field_user_list_position) */
  $handler->display->display_options['relationships']['field_user_list_position_tid']['id'] = 'field_user_list_position_tid';
  $handler->display->display_options['relationships']['field_user_list_position_tid']['table'] = 'field_revision_field_user_list_position';
  $handler->display->display_options['relationships']['field_user_list_position_tid']['field'] = 'field_user_list_position_tid';
  $handler->display->display_options['relationships']['field_user_list_position_tid']['relationship'] = 'vid';
  $handler->display->display_options['relationships']['field_user_list_position_tid']['label'] = 'Listenposition';
  /* Beziehung: Benutzer (Historische Daten): Partei (field_user_party) */
  $handler->display->display_options['relationships']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['relationships']['field_user_party_tid']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['relationships']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['relationships']['field_user_party_tid']['relationship'] = 'vid';
  $handler->display->display_options['relationships']['field_user_party_tid']['label'] = 'Partei';
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id']['id'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['label'] = 'Nachname';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['path'] = 'user/[uid]';
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
  /* Feld: Benutzer (Historische Daten): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id']['id'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['label'] = 'Vorname';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['alter']['path'] = 'user/[uid]';
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
  /* Feld: PW User archive: Benutzerrolle */
  $handler->display->display_options['fields']['user_role']['id'] = 'user_role';
  $handler->display->display_options['fields']['user_role']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['user_role']['field'] = 'user_role';
  $handler->display->display_options['fields']['user_role']['label'] = 'Profil für';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_5']['id'] = 'name_5';
  $handler->display->display_options['fields']['name_5']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_5']['field'] = 'name';
  $handler->display->display_options['fields']['name_5']['relationship'] = 'field_user_party_tid';
  $handler->display->display_options['fields']['name_5']['label'] = 'Partei';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_user_fraction_tid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Fraktion';
  /* Feld: Benutzer (Historische Daten): Parlament beigetreten */
  $handler->display->display_options['fields']['field_user_joined-revision_id']['id'] = 'field_user_joined-revision_id';
  $handler->display->display_options['fields']['field_user_joined-revision_id']['table'] = 'field_revision_field_user_joined';
  $handler->display->display_options['fields']['field_user_joined-revision_id']['field'] = 'field_user_joined-revision_id';
  $handler->display->display_options['fields']['field_user_joined-revision_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_user_joined-revision_id']['settings'] = array(
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
  /* Feld: Benutzer (Historische Daten): Parlament verlassen */
  $handler->display->display_options['fields']['field_user_retired-revision_id']['id'] = 'field_user_retired-revision_id';
  $handler->display->display_options['fields']['field_user_retired-revision_id']['table'] = 'field_revision_field_user_retired';
  $handler->display->display_options['fields']['field_user_retired-revision_id']['field'] = 'field_user_retired-revision_id';
  $handler->display->display_options['fields']['field_user_retired-revision_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_user_retired-revision_id']['settings'] = array(
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
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'field_user_list_tid';
  $handler->display->display_options['fields']['name_2']['label'] = 'Liste';
  /* Feld: Benutzer (Historische Daten): Liste gewonnen */
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['id'] = 'field_user_list_won-revision_id';
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['table'] = 'field_revision_field_user_list_won';
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['field'] = 'field_user_list_won-revision_id';
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['alter']['text'] = 'Ja';
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['empty'] = 'Nein';
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_user_list_won-revision_id']['settings'] = array(
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
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_3']['id'] = 'name_3';
  $handler->display->display_options['fields']['name_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_3']['field'] = 'name';
  $handler->display->display_options['fields']['name_3']['relationship'] = 'field_user_list_position_tid';
  $handler->display->display_options['fields']['name_3']['label'] = 'Listenposition';
  /* Feld: Benutzer (Historische Daten): Wahlkreis */
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['id'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['table'] = 'field_revision_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['field'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['relationship'] = 'vid';
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
  /* Feld: Benutzer (Historische Daten): Wahlkreis gewonnen */
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['id'] = 'field_user_constituency_won-revision_id';
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['table'] = 'field_revision_field_user_constituency_won';
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['field'] = 'field_user_constituency_won-revision_id';
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['alter']['text'] = 'Ja';
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['empty'] = 'Nein';
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_user_constituency_won-revision_id']['settings'] = array(
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
  /* Feld: Benutzer (Historische Daten): Wahlkreisergebnis */
  $handler->display->display_options['fields']['field_user_election_result-revision_id']['id'] = 'field_user_election_result-revision_id';
  $handler->display->display_options['fields']['field_user_election_result-revision_id']['table'] = 'field_revision_field_user_election_result';
  $handler->display->display_options['fields']['field_user_election_result-revision_id']['field'] = 'field_user_election_result-revision_id';
  $handler->display->display_options['fields']['field_user_election_result-revision_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_user_election_result-revision_id']['settings'] = array(
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
  /* Feld: PW User archive: Question form open */
  $handler->display->display_options['fields']['question_form_open']['id'] = 'question_form_open';
  $handler->display->display_options['fields']['question_form_open']['table'] = 'user_archive_cache';
  $handler->display->display_options['fields']['question_form_open']['field'] = 'question_form_open';
  $handler->display->display_options['fields']['question_form_open']['label'] = 'Frageformular';
  $handler->display->display_options['fields']['question_form_open']['not'] = 0;
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['relationship'] = 'vid';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'vid';
  $handler->display->display_options['fields']['name']['label'] = 'Benutzername';
  /* Feld: User revision: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_revision']['id'] = 'edit_revision';
  $handler->display->display_options['fields']['edit_revision']['table'] = 'user_revision';
  $handler->display->display_options['fields']['edit_revision']['field'] = 'edit_revision';
  $handler->display->display_options['fields']['edit_revision']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_revision']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_revision']['text'] = 'Bearbeiten';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Links';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Alle Revisionen';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user/[uid]/revisions';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_revision' => 'edit_revision',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 0;
  /* Kontextfilter: Benutzer (Historische Daten): Parlament (field_user_parliament) */
  $handler->display->display_options['arguments']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['table'] = 'field_revision_field_user_parliament';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['relationship'] = 'vid';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_user_parliament_tid']['title'] = '%1 - Kandidaten & Abgeordnete';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_user_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  /* Filterkriterium: PW User archive: Benutzerrolle */
  $handler->display->display_options['filters']['user_role']['id'] = 'user_role';
  $handler->display->display_options['filters']['user_role']['table'] = 'user_archive_cache';
  $handler->display->display_options['filters']['user_role']['field'] = 'user_role';
  $handler->display->display_options['filters']['user_role']['group'] = 1;
  $handler->display->display_options['filters']['user_role']['exposed'] = TRUE;
  $handler->display->display_options['filters']['user_role']['expose']['operator_id'] = 'user_role_op';
  $handler->display->display_options['filters']['user_role']['expose']['label'] = 'Profil für';
  $handler->display->display_options['filters']['user_role']['expose']['operator'] = 'user_role_op';
  $handler->display->display_options['filters']['user_role']['expose']['identifier'] = 'user_role';
  $handler->display->display_options['filters']['user_role']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer (Historische Daten): First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_user_fname_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
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
  /* Filterkriterium: Benutzer (Historische Daten): Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_user_lname_value']['operator'] = 'allwords';
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
  /* Filterkriterium: Benutzer (Historische Daten): Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
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
  /* Filterkriterium: Benutzer (Historische Daten): Fraktion (field_user_fraction) */
  $handler->display->display_options['filters']['field_user_fraction_tid']['id'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['table'] = 'field_revision_field_user_fraction';
  $handler->display->display_options['filters']['field_user_fraction_tid']['field'] = 'field_user_fraction_tid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_user_fraction_tid']['group'] = 1;
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
  /* Filterkriterium: Benutzer (Historische Daten): Liste (field_user_list) */
  $handler->display->display_options['filters']['field_user_list_tid']['id'] = 'field_user_list_tid';
  $handler->display->display_options['filters']['field_user_list_tid']['table'] = 'field_revision_field_user_list';
  $handler->display->display_options['filters']['field_user_list_tid']['field'] = 'field_user_list_tid';
  $handler->display->display_options['filters']['field_user_list_tid']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_user_list_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_list_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_list_tid']['expose']['operator_id'] = 'field_user_list_tid_op';
  $handler->display->display_options['filters']['field_user_list_tid']['expose']['label'] = 'Liste';
  $handler->display->display_options['filters']['field_user_list_tid']['expose']['operator'] = 'field_user_list_tid_op';
  $handler->display->display_options['filters']['field_user_list_tid']['expose']['identifier'] = 'field_user_list_tid';
  $handler->display->display_options['filters']['field_user_list_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_user_list_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_list_tid']['vocabulary'] = 'election_list';
  /* Filterkriterium: Benutzer (Historische Daten): Liste gewonnen (field_user_list_won) */
  $handler->display->display_options['filters']['field_user_list_won_value']['id'] = 'field_user_list_won_value';
  $handler->display->display_options['filters']['field_user_list_won_value']['table'] = 'field_revision_field_user_list_won';
  $handler->display->display_options['filters']['field_user_list_won_value']['field'] = 'field_user_list_won_value';
  $handler->display->display_options['filters']['field_user_list_won_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_user_list_won_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_list_won_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_list_won_value']['expose']['operator_id'] = 'field_user_list_won_value_op';
  $handler->display->display_options['filters']['field_user_list_won_value']['expose']['label'] = 'Liste gewonnen';
  $handler->display->display_options['filters']['field_user_list_won_value']['expose']['operator'] = 'field_user_list_won_value_op';
  $handler->display->display_options['filters']['field_user_list_won_value']['expose']['identifier'] = 'field_user_list_won_value';
  $handler->display->display_options['filters']['field_user_list_won_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer (Historische Daten): Wahlkreis (field_user_constituency) */
  $handler->display->display_options['filters']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['table'] = 'field_revision_field_user_constituency';
  $handler->display->display_options['filters']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_constituency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator_id'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['label'] = 'Wahlkreis';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_user_constituency_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: PW User archive: Question form open */
  $handler->display->display_options['filters']['question_form_open']['id'] = 'question_form_open';
  $handler->display->display_options['filters']['question_form_open']['table'] = 'user_archive_cache';
  $handler->display->display_options['filters']['question_form_open']['field'] = 'question_form_open';
  $handler->display->display_options['filters']['question_form_open']['value'] = 'All';
  $handler->display->display_options['filters']['question_form_open']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_form_open']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['question_form_open']['expose']['label'] = 'Frageformular';
  $handler->display->display_options['filters']['question_form_open']['expose']['operator'] = 'question_form_open_op';
  $handler->display->display_options['filters']['question_form_open']['expose']['identifier'] = 'question_form_open';
  $handler->display->display_options['filters']['question_form_open']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Benutzer: Benutzer UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'users';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'vid';
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
  /* Filterkriterium: Benutzer: E-Mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'vid';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'taxonomy/term/%/politicians';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Politiker';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['pw_administration_politicians_of_parliament'] = array(
    t('Master'),
    t('Politiker'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('<p>Zeigt @start - @end von @total Politiker-Profilen</p>

Diese Übersicht listet die Profile für Kandidaturen wie für Mandate auf. Wenn ein/e Politiker/in doppelt aufgeführt ist, sollte das daran liegen, dass jeweils das Profil für die Kandidatur und für das gewonnene Mandat aufgelistet werden.'),
    t('Keine Politiker gefunden'),
    t('User Revision'),
    t('Fraktion'),
    t('Liste'),
    t('Listenposition'),
    t('Partei'),
    t('Uid'),
    t('Nachname'),
    t('Vorname'),
    t('Profil für'),
    t('Parlament beigetreten'),
    t('Parlament verlassen'),
    t('Liste gewonnen'),
    t('Ja'),
    t('Nein'),
    t('Wahlkreis'),
    t('Wahlkreis gewonnen'),
    t('Wahlkreisergebnis'),
    t('Frageformular'),
    t('Benutzer UUID'),
    t('Benutzername'),
    t('‚Bearbeiten‘-Link'),
    t('Bearbeiten'),
    t('Links'),
    t('Alle Revisionen'),
    t('Aktionen'),
    t('Alle'),
    t('%1 - Kandidaten & Abgeordnete'),
    t('UUID'),
    t('E-Mail'),
    t('Page'),
  );
  $export['pw_administration_politicians_of_parliament'] = $view;

  $view = new view();
  $view->name = 'pw_administration_polls';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Polls';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Abstimmungen';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any poll content';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title' => 'title',
    'name_1' => 'name_1',
    'status' => 'status',
    'field_poll_date' => 'field_poll_date',
    'changed' => 'changed',
    'name' => 'name',
    'uuid' => 'uuid',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'name_1' => array(
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
    'field_poll_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'name' => array(
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
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
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
  /* Kopfzeile: Global: PW Administration - Create new */
  $handler->display->display_options['header']['pw_administration_create_new']['id'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['table'] = 'views';
  $handler->display->display_options['header']['pw_administration_create_new']['field'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['empty'] = TRUE;
  $handler->display->display_options['header']['pw_administration_create_new']['entity_to_create'] = 'poll';
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Abstimmungen';
  /* Beziehung: Inhalt: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Beziehung: Feld: Parliament (field_parliament) */
  $handler->display->display_options['relationships']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['relationships']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['relationships']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['relationships']['field_parliament_tid']['label'] = 'Parlament';
  /* Feld: Stapelverarbeitungen: Inhalt */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 0;
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
        'url' => 'admin/abgeordnetenwatch/wahlen-parlamente/polls/export',
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
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichen',
    ),
  );
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_parliament_tid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Parlament';
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = TRUE;
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Poll Date */
  $handler->display->display_options['fields']['field_poll_date']['id'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['table'] = 'field_data_field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['field'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum Abstimmung';
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
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Löschen';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Links';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Übersicht Stimmen/ Votes';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/votes';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 0;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poll' => 'poll',
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
  /* Filterkriterium: Inhalt: Topics (field_topics) */
  $handler->display->display_options['filters']['field_topics_tid']['id'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['table'] = 'field_data_field_topics';
  $handler->display->display_options['filters']['field_topics_tid']['field'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_topics_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_topics_tid']['vocabulary'] = 'topics';
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
  $handler->display->display_options['filters']['field_parliament_tid']['type'] = 'select';
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
  /* Filterkriterium: Benutzer: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Autor';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/polls';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Abstimmungen';
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
  $handler->display->display_options['style_options']['filename'] = 'abstimmungen.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['fields']['uuid_1']['table'] = 'node';
  $handler->display->display_options['fields']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid_1']['label'] = 'UUID';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
  $handler->display->display_options['fields']['field_parliament']['type'] = 'taxonomy_term_reference_plain';
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
  /* Feld: Inhalt: Committees */
  $handler->display->display_options['fields']['field_poll_committees']['id'] = 'field_poll_committees';
  $handler->display->display_options['fields']['field_poll_committees']['table'] = 'field_data_field_poll_committees';
  $handler->display->display_options['fields']['field_poll_committees']['field'] = 'field_poll_committees';
  $handler->display->display_options['fields']['field_poll_committees']['label'] = 'Ausschüsse';
  $handler->display->display_options['fields']['field_poll_committees']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
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
  $handler->display->display_options['fields']['field_poll_committees']['delta_offset'] = '0';
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Voted */
  $handler->display->display_options['fields']['field_voted']['id'] = 'field_voted';
  $handler->display->display_options['fields']['field_voted']['table'] = 'field_data_field_voted';
  $handler->display->display_options['fields']['field_voted']['field'] = 'field_voted';
  $handler->display->display_options['fields']['field_voted']['label'] = 'Stimmverhalten';
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
  /* Feld: Inhalt: Poll Date */
  $handler->display->display_options['fields']['field_poll_date']['id'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['table'] = 'field_data_field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['field'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum Abstimmung';
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
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['relationship'] = 'uid';
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
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/polls/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/polls';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_polls'] = array(
    t('Master'),
    t('Abstimmungen'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Abstimmungen'),
    t('Autor'),
    t('Parlament'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('Veröffentlichen'),
    t('Titel'),
    t('Veröffentlicht'),
    t('Datum Abstimmung'),
    t('Letztes Update'),
    t('UUID'),
    t('‚Bearbeiten‘-Link'),
    t('Bearbeiten'),
    t('Links'),
    t('Übersicht Stimmen/ Votes'),
    t('Aktionen'),
    t('Themen'),
    t('Page'),
    t('Data export'),
    t('ID'),
    t('Ausschüsse'),
    t('Stimmverhalten'),
    t('Benutzer UUID'),
    t('Alle'),
  );
  $export['pw_administration_polls'] = $view;

  $view = new view();
  $view->name = 'pw_administration_polls_by_parliament';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Polls by Parliament';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Abstimmungen';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any poll content';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title' => 'title',
    'field_parliament' => 'field_parliament',
    'status' => 'status',
    'field_poll_date' => 'field_poll_date',
    'changed' => 'changed',
    'name' => 'name',
    'uuid' => 'uuid',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'field_parliament' => array(
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
    'field_poll_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'name' => array(
      'sortable' => 1,
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
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
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
  /* Kopfzeile: Global: PW Administration - Create new */
  $handler->display->display_options['header']['pw_administration_create_new']['id'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['table'] = 'views';
  $handler->display->display_options['header']['pw_administration_create_new']['field'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['entity_to_create'] = 'poll';
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Abstimmungen';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Abstimmungen gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Beziehung: Inhalt: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Feld: Stapelverarbeitungen: Inhalt */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::pathauto_node_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
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
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Veröffentlichen',
    ),
  );
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
  $handler->display->display_options['fields']['field_parliament']['type'] = 'taxonomy_term_reference_plain';
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
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Poll Date */
  $handler->display->display_options['fields']['field_poll_date']['id'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['table'] = 'field_data_field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['field'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum Abstimmung';
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
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Löschen';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Stimmen/ Votes';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Übersicht Stimmen/ Votes';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/votes';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 0;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['title'] = '%1 - Abstimmungen';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poll' => 'poll',
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
  /* Filterkriterium: Inhalt: Topics (field_topics) */
  $handler->display->display_options['filters']['field_topics_tid']['id'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['table'] = 'field_data_field_topics';
  $handler->display->display_options['filters']['field_topics_tid']['field'] = 'field_topics_tid';
  $handler->display->display_options['filters']['field_topics_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_topics_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_topics_tid']['vocabulary'] = 'topics';
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
  /* Filterkriterium: Benutzer: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Autor';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%/polls';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Abstimmungen';
  $handler->display->display_options['menu']['weight'] = '30';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'abstimmungen.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['fields']['uuid_1']['table'] = 'node';
  $handler->display->display_options['fields']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid_1']['label'] = 'UUID';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'Parlament';
  $handler->display->display_options['fields']['field_parliament']['type'] = 'taxonomy_term_reference_plain';
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
  /* Feld: Inhalt: Committees */
  $handler->display->display_options['fields']['field_poll_committees']['id'] = 'field_poll_committees';
  $handler->display->display_options['fields']['field_poll_committees']['table'] = 'field_data_field_poll_committees';
  $handler->display->display_options['fields']['field_poll_committees']['field'] = 'field_poll_committees';
  $handler->display->display_options['fields']['field_poll_committees']['label'] = 'Ausschüsse';
  $handler->display->display_options['fields']['field_poll_committees']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
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
  $handler->display->display_options['fields']['field_poll_committees']['delta_offset'] = '0';
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Voted */
  $handler->display->display_options['fields']['field_voted']['id'] = 'field_voted';
  $handler->display->display_options['fields']['field_voted']['table'] = 'field_data_field_voted';
  $handler->display->display_options['fields']['field_voted']['field'] = 'field_voted';
  $handler->display->display_options['fields']['field_voted']['label'] = 'Stimmverhalten';
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
  /* Feld: Inhalt: Poll Date */
  $handler->display->display_options['fields']['field_poll_date']['id'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['table'] = 'field_data_field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['field'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum Abstimmung';
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
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uuid']['label'] = 'Autor UUID';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
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
  $handler->display->display_options['path'] = 'taxonomy/term/%/polls/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'taxonomy/term/%/polls';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_polls_by_parliament'] = array(
    t('Master'),
    t('Abstimmungen'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Abstimmungen'),
    t('Keine Abstimmungen gefunden'),
    t('Autor'),
    t('Bitte auswählen'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('Veröffentlichen'),
    t('Titel'),
    t('Parlament'),
    t('Veröffentlicht'),
    t('Datum Abstimmung'),
    t('Letztes Update'),
    t('UUID'),
    t('‚Bearbeiten‘-Link'),
    t('Bearbeiten'),
    t('Stimmen/ Votes'),
    t('Übersicht Stimmen/ Votes'),
    t('Aktionen'),
    t('Alle'),
    t('%1 - Abstimmungen'),
    t('Themen'),
    t('Page'),
    t('Data export'),
    t('ID'),
    t('Ausschüsse'),
    t('Stimmverhalten'),
    t('Autor UUID'),
  );
  $export['pw_administration_polls_by_parliament'] = $view;

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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'name' => 'name',
    'field_job' => 'field_job',
    'field_sidejob_organization' => 'field_sidejob_organization',
    'field_sidejob_job_category' => 'field_sidejob_job_category',
    'field_topics' => 'field_topics',
    'field_sidejob_date_end' => 'field_sidejob_date_end',
    'field_sidejob_date_start' => 'field_sidejob_date_start',
    'field_sidejob_classification' => 'field_sidejob_classification',
    'field_sidejob_income_interval' => 'field_sidejob_income_interval',
    'sidejobs_income' => 'sidejobs_income',
    'changed' => 'changed',
    'view_user' => 'view_user',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_job' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sidejob_organization' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sidejob_job_category' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_topics' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sidejob_date_end' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sidejob_date_start' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sidejob_classification' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sidejob_income_interval' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sidejobs_income' => array(
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
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
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
  /* Kopfzeile: Global: PW Administration - Create new */
  $handler->display->display_options['header']['pw_administration_create_new']['id'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['table'] = 'views';
  $handler->display->display_options['header']['pw_administration_create_new']['field'] = 'pw_administration_create_new';
  $handler->display->display_options['header']['pw_administration_create_new']['entity_to_create'] = 'sidejob';
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Nebentätigkeiten';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Einträge gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_politician_target_id']['id'] = 'field_politician_target_id';
  $handler->display->display_options['relationships']['field_politician_target_id']['table'] = 'field_data_field_politician';
  $handler->display->display_options['relationships']['field_politician_target_id']['field'] = 'field_politician_target_id';
  $handler->display->display_options['relationships']['field_politician_target_id']['label'] = 'Politiker';
  /* Beziehung: Benutzer: Partei (field_user_party) */
  $handler->display->display_options['relationships']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['relationships']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['relationships']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['relationships']['field_user_party_tid']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['relationships']['field_user_party_tid']['label'] = 'Partei';
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
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_user_party_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Partei';
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
  /* Feld: Inhalt: Income Interval */
  $handler->display->display_options['fields']['field_sidejob_income_interval']['id'] = 'field_sidejob_income_interval';
  $handler->display->display_options['fields']['field_sidejob_income_interval']['table'] = 'field_data_field_sidejob_income_interval';
  $handler->display->display_options['fields']['field_sidejob_income_interval']['field'] = 'field_sidejob_income_interval';
  $handler->display->display_options['fields']['field_sidejob_income_interval']['label'] = 'Intervall';
  $handler->display->display_options['fields']['field_sidejob_income_interval']['settings'] = array(
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
  /* Feld: Inhalt: Sidejob income */
  $handler->display->display_options['fields']['sidejobs_income']['id'] = 'sidejobs_income';
  $handler->display->display_options['fields']['sidejobs_income']['table'] = 'node';
  $handler->display->display_options['fields']['sidejobs_income']['field'] = 'sidejobs_income';
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
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
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
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
  $handler->display->display_options['filters']['field_sidejob_job_category_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_topics_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_job_tid']['group'] = 1;
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
  /* Filterkriterium: Benutzer: Partei (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['relationship'] = 'field_politician_target_id';
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
  /* Filterkriterium: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Letztes Update';
  $handler->display->display_options['filters']['changed']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Classification (field_sidejob_classification) */
  $handler->display->display_options['filters']['field_sidejob_classification_value']['id'] = 'field_sidejob_classification_value';
  $handler->display->display_options['filters']['field_sidejob_classification_value']['table'] = 'field_data_field_sidejob_classification';
  $handler->display->display_options['filters']['field_sidejob_classification_value']['field'] = 'field_sidejob_classification_value';
  $handler->display->display_options['filters']['field_sidejob_classification_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sidejob_classification_value']['expose']['operator_id'] = 'field_sidejob_classification_value_op';
  $handler->display->display_options['filters']['field_sidejob_classification_value']['expose']['label'] = 'Classification';
  $handler->display->display_options['filters']['field_sidejob_classification_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_sidejob_classification_value']['expose']['operator'] = 'field_sidejob_classification_value_op';
  $handler->display->display_options['filters']['field_sidejob_classification_value']['expose']['identifier'] = 'field_sidejob_classification_value';
  $handler->display->display_options['filters']['field_sidejob_classification_value']['expose']['remember_roles'] = array(
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
  /* Filterkriterium: Inhalt: Income Interval (field_sidejob_income_interval) */
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['id'] = 'field_sidejob_income_interval_value';
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['table'] = 'field_data_field_sidejob_income_interval';
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['field'] = 'field_sidejob_income_interval_value';
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['expose']['operator_id'] = 'field_sidejob_income_interval_value_op';
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['expose']['label'] = 'Intervall';
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['expose']['operator'] = 'field_sidejob_income_interval_value_op';
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['expose']['identifier'] = 'field_sidejob_income_interval_value';
  $handler->display->display_options['filters']['field_sidejob_income_interval_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/sidejobs';
  $handler->display->display_options['menu']['type'] = 'normal';
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
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'Vorname';
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
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Nachname';
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
  /* Feld: Benutzer: Partei */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['relationship'] = 'field_politician_target_id';
  $handler->display->display_options['fields']['field_user_party']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party']['settings'] = array(
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
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
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
  /* Feld: Inhalt: Income Interval */
  $handler->display->display_options['fields']['field_sidejob_income_interval']['id'] = 'field_sidejob_income_interval';
  $handler->display->display_options['fields']['field_sidejob_income_interval']['table'] = 'field_data_field_sidejob_income_interval';
  $handler->display->display_options['fields']['field_sidejob_income_interval']['field'] = 'field_sidejob_income_interval';
  $handler->display->display_options['fields']['field_sidejob_income_interval']['label'] = 'Intervall';
  $handler->display->display_options['fields']['field_sidejob_income_interval']['settings'] = array(
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
  /* Feld: Inhalt: Sidejob income */
  $handler->display->display_options['fields']['sidejobs_income']['id'] = 'sidejobs_income';
  $handler->display->display_options['fields']['sidejobs_income']['table'] = 'node';
  $handler->display->display_options['fields']['sidejobs_income']['field'] = 'sidejobs_income';
  $handler->display->display_options['fields']['sidejobs_income']['label'] = 'Gesamteinkünfte';
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Nebentätigkeiten'),
    t('Keine Einträge gefunden'),
    t('Politiker'),
    t('Partei'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('[field_user_lname], [field_user_fname]'),
    t('Job'),
    t('Organisation'),
    t('Job category'),
    t('Themen'),
    t('Date End'),
    t('Date Start'),
    t('Classification'),
    t('Intervall'),
    t('Sidejob income'),
    t('Letztes Update'),
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
    t('Gesamteinkünfte'),
    t('Alle'),
  );
  $export['pw_administration_sidejobs'] = $view;

  $view = new view();
  $view->name = 'pw_administration_taxonomy_term_list';
  $view->description = 'Manage tagging, categorization, and classification of your content.';
  $view->tag = 'admin';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'PW Administration: Taxonomy Term List';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Begriffe';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer taxonomy';
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
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'tid_1' => 'tid_1',
    'name_1' => 'name_1',
    'name' => 'name',
    'description' => 'description',
    'uuid' => 'uuid',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'tid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
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
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
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
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Begriff';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'taxonomy/term/[tid_1]/nodes';
  /* Feld: Taxonomie-Begriff: Begriffsbeschreibung */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Beschreibung';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Feld: Taxonomie-Begriff: Taxonomie-Begriff UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'taxonomy/term/[tid_1]/edit';
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Löschen';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Löschen';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'taxonomy/term/[tid_1]/delete';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Kontextfilter: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['arguments']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['machine_name']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['machine_name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['machine_name']['title'] = 'Begriffe in %1';
  $handler->display->display_options['arguments']['machine_name']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['machine_name']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['machine_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['machine_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['machine_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['machine_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['machine_name']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['machine_name']['limit'] = '0';
  /* Filterkriterium: Taxonomie-Begriff: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'word';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  /* Filterkriterium: Feld: Parliament (field_parliament) */
  $handler->display->display_options['filters']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['filters']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator_id'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['label'] = 'Parliament';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['operator'] = 'field_parliament_tid_op';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['identifier'] = 'field_parliament_tid';
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_parliament_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_parliament_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_parliament_tid']['vocabulary'] = 'parliaments';

  /* Display: Seite */
  $handler = $view->new_display('page', 'Seite', 'page_1');
  $handler->display->display_options['path'] = 'admin/structure/taxonomy/%';
  $translatables['pw_administration_taxonomy_term_list'] = array(
    t('Defaults'),
    t('Begriffe'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Begriff-ID'),
    t('.'),
    t('Begriff'),
    t('Beschreibung'),
    t('UUID'),
    t('Bearbeiten'),
    t('Löschen'),
    t('Aktionen'),
    t('Alle'),
    t('Begriffe in %1'),
    t('%1'),
    t('Name'),
    t('Parliament'),
    t('Seite'),
  );
  $export['pw_administration_taxonomy_term_list'] = $view;

  $view = new view();
  $view->name = 'pw_administration_term_nodes_tagged_by';
  $view->description = 'Listet alle Nodes auf, die mit einem Term getaggt sind';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Term - Nodes Tagged by';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nodes tagged';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer taxonomy';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'changed' => 'changed',
    'type' => 'type',
    'status' => 'status',
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
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Es wurden keine Nodes gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
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
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Kontextfilter: Inhalt: Besitzt eine Taxonomiebegriff-ID. */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = 'Nodes getaggt mit %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%/nodes';
  $handler->display->display_options['menu']['title'] = 'Nodes';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['pw_administration_term_nodes_tagged_by'] = array(
    t('Master'),
    t('Nodes tagged'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Es wurden keine Nodes gefunden'),
    t('Titel'),
    t('Typ'),
    t('Veröffentlicht'),
    t('Letztes Update'),
    t('‚Bearbeiten‘-Link'),
    t('Link löschen'),
    t('Aktionen'),
    t('Alle'),
    t('Nodes getaggt mit %1'),
    t('Page'),
  );
  $export['pw_administration_term_nodes_tagged_by'] = $view;

  $view = new view();
  $view->name = 'pw_administration_users';
  $view->description = 'List, add, and edit users.';
  $view->tag = 'admin';
  $view->base_table = 'users';
  $view->human_name = 'PW Administration: Users';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Benutzer';
  $handler->display->display_options['css_class'] = 'pw-administration-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    30037204 => '30037204',
    51622513 => '51622513',
  );
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 50, 100, 500, 1000';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'field_user_lname' => 'field_user_lname',
    'field_user_fname' => 'field_user_fname',
    'field_user_party' => 'field_user_party',
    'mail' => 'name',
    'uuid' => 'uuid',
    'status' => 'status',
    'rid' => 'rid',
    'field_user_retired' => 'field_user_retired',
    'access' => 'access',
    'name_1' => 'name_1',
    'created' => 'created',
    'edit_node' => 'edit_node',
    'cancel_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'access';
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
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'field_user_lname' => array(
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
      'empty_column' => 0,
    ),
    'field_user_party' => array(
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
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_retired' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'cancel_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Benutzern';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Ungefilterter Text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Keine Benutzer verfügbar.';
  /* Feld: Stapelverarbeitungen: Benutzer */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Einträge exportieren',
      'settings' => array(
        'url' => 'admin/people/export/',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Send e-mail',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Change user roles',
    ),
  );
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Benutzername';
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Nachname';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'Vorname';
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Benutzer: Aktiv */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['type'] = 'ul';
  /* Feld: Benutzer: Letzter Zugriff */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'User-Name';
  $handler->display->display_options['fields']['name_1']['alter']['max_length'] = '64';
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name_1']['link_to_user'] = FALSE;
  $handler->display->display_options['fields']['name_1']['format_username'] = FALSE;
  /* Feld: Benutzer: Erstellungsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Mitglied seit';
  $handler->display->display_options['fields']['created']['date_format'] = 'raw time ago';
  /* Feld: Benutzer: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Bearbeiten';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Bearbeiten';
  /* Feld: Benutzer: Link zum Account löschen */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cancel_node']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['cancel_node']['text'] = 'Löschen';
  /* Feld: Global: Dropdown links */
  $handler->display->display_options['fields']['ctools_dropdown']['id'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['table'] = 'views';
  $handler->display->display_options['fields']['ctools_dropdown']['field'] = 'ctools_dropdown';
  $handler->display->display_options['fields']['ctools_dropdown']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['ctools_dropdown']['fields'] = array(
    'edit_node' => 'edit_node',
    'cancel_node' => 'cancel_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Filterkriterium: Nachname */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['ui_name'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_value']['operator'] = 'contains';
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
  );
  /* Filterkriterium: Benutzer: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );
  $handler->display->display_options['filters']['uid']['group'] = 1;
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
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
  );
  /* Filterkriterium: Benutzer: Name (unformatiert) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Benutzername';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  /* Filterkriterium: Benutzer: E-Mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember'] = TRUE;
  /* Filterkriterium: Benutzer: Benutzer UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'users';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['operator'] = 'contains';
  $handler->display->display_options['filters']['uuid']['group'] = 1;
  $handler->display->display_options['filters']['uuid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uuid']['expose']['operator_id'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['label'] = 'UUID';
  $handler->display->display_options['filters']['uuid']['expose']['operator'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['identifier'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    40118511 => 0,
  );
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Aktiv';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Rolle';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember'] = TRUE;

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
  /* Feld: Stapelverarbeitungen: Benutzer */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Einträge exportieren',
      'settings' => array(
        'url' => 'admin/people/export/',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Send e-mail',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Change user roles',
    ),
  );
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'UID';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Nachname';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'Vorname';
  /* Feld: Benutzer: Partei */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['label'] = 'Party';
  $handler->display->display_options['fields']['field_user_party']['settings'] = array(
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
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Benutzer: Parlament */
  $handler->display->display_options['fields']['field_user_parliament']['id'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['field'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['settings'] = array(
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
  /* Feld: Benutzer: Wahlkreis */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['settings'] = array(
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
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Benutzer: Listenposition */
  $handler->display->display_options['fields']['field_user_list_position']['id'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['table'] = 'field_data_field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['field'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['settings'] = array(
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
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Feld: Benutzer: Aktiv */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['type'] = 'ul';
  /* Feld: Benutzer: Parlament verlassen */
  $handler->display->display_options['fields']['field_user_retired']['id'] = 'field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['table'] = 'field_data_field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['field'] = 'field_user_retired';
  $handler->display->display_options['fields']['field_user_retired']['label'] = 'Ausgeschieden am';
  $handler->display->display_options['fields']['field_user_retired']['settings'] = array(
    'format_type' => 'date_only_short',
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
  /* Feld: Benutzer: Letzter Zugriff */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'User-Name';
  $handler->display->display_options['fields']['name_1']['alter']['max_length'] = '64';
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name_1']['link_to_user'] = FALSE;
  $handler->display->display_options['fields']['name_1']['format_username'] = FALSE;
  /* Feld: Benutzer: Data URL */
  $handler->display->display_options['fields']['field_user_data_url']['id'] = 'field_user_data_url';
  $handler->display->display_options['fields']['field_user_data_url']['table'] = 'field_data_field_user_data_url';
  $handler->display->display_options['fields']['field_user_data_url']['field'] = 'field_user_data_url';
  $handler->display->display_options['fields']['field_user_data_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_user_data_url']['settings'] = array(
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
  /* Feld: Benutzer: Erstellungsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Mitglied seit';
  $handler->display->display_options['fields']['created']['date_format'] = 'raw time ago';
  /* Feld: Benutzer: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Aktionen';
  /* Feld: Benutzer: Link zum Account löschen */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cancel_node']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer: Adresse - Ort (z. B. Stadt) */
  $handler->display->display_options['fields']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['label'] = 'Wohnort';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Benutzer: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'admin/people/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'page_2' => 'page_2',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Seite */
  $handler = $view->new_display('page', 'Seite', 'page_1');
  $handler->display->display_options['path'] = 'admin/people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Seite - Default Tab */
  $handler = $view->new_display('page', 'Seite - Default Tab', 'page_2');
  $handler->display->display_options['path'] = 'admin/people/people';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['pw_administration_users'] = array(
    t('Defaults'),
    t('Benutzer'),
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Benutzern'),
    t('Keine Benutzer verfügbar.'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Send e-mail'),
    t('Delete'),
    t('Change value'),
    t('Change user roles'),
    t('Benutzername'),
    t('Nachname'),
    t('Vorname'),
    t('UUID'),
    t('Aktiv'),
    t('Rollen'),
    t('Letzter Zugriff'),
    t('User-Name'),
    t('Mitglied seit'),
    t('Bearbeiten'),
    t('Löschen'),
    t('Aktionen'),
    t('E-Mail'),
    t('Rolle'),
    t('Data export'),
    t('UID'),
    t('Name'),
    t('Party'),
    t('Parlament'),
    t('Wahlkreis'),
    t('Listenposition'),
    t('Ausgeschieden am'),
    t('Data URL'),
    t('Wohnort'),
    t('Alle'),
    t('Seite'),
    t('Seite - Default Tab'),
  );
  $export['pw_administration_users'] = $view;

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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'name' => 'name',
    'title' => 'title',
    'type' => 'type',
    'field_poll_date' => 'field_poll_date',
    'field_vote' => 'field_vote',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'type' => array(
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
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
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
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Stimmen/ Votes';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Einträge gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
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
  /* Beziehung: Feld: Parliament (field_parliament) */
  $handler->display->display_options['relationships']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['relationships']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['relationships']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['relationships']['field_parliament_tid']['label'] = 'Parlament';
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
        'url' => 'admin/abgeordnetenwatch/wahlen-parlamente/votings/export',
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
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_parliament_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Parlament';
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Abstimmung/ Petition';
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
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum Abstimmung';
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
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
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
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vote' => 'vote',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
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
  $handler->display->display_options['filters']['field_parliament_tid']['type'] = 'select';
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
  $handler->display->display_options['filters']['field_vote_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_vote_tid']['vocabulary'] = 'votes';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'poll' => 'poll',
    'pw_petition' => 'pw_petition',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
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
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/votings';
  $handler->display->display_options['menu']['type'] = 'normal';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Vote Id';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'Vorname';
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
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Nachname';
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
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['fields']['uid']['label'] = 'Politiker Id';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
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
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_parliament_tid';
  $handler->display->display_options['fields']['tid']['label'] = 'Parliament Id';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Inhalt: Abstimmung */
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
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum Abstimmung';
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
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
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
  $handler->display->display_options['path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/votings/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/abgeordnetenwatch/wahlen-parlamente/votings';
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Stimmen/ Votes'),
    t('Keine Einträge gefunden'),
    t('Politiker'),
    t('Abstimmung'),
    t('Parlament'),
    t('Bitte auswählen'),
    t('Einträge exportieren'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('[field_user_lname], [field_user_fname]'),
    t('Abstimmung/ Petition'),
    t('Typ'),
    t('Datum Abstimmung'),
    t('Stimme'),
    t('Letztes Update'),
    t('[edit_node] [delete_node] '),
    t('Bearbeiten'),
    t('Aktionen'),
    t('Vorname'),
    t('Nachname'),
    t('Veröffentlicht'),
    t('Page'),
    t('Data export'),
    t('Vote Id'),
    t('Politiker Id'),
    t('Parliament'),
    t('Parliament Id'),
    t('.'),
    t('Stimmverhalten'),
    t('Alle'),
  );
  $export['pw_administration_votings'] = $view;

  $view = new view();
  $view->name = 'pw_administration_votings_by_poll';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Administration Votings by Poll';
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
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'field_parliament' => 'field_parliament',
    'field_vote_node' => 'field_vote_node',
    'type' => 'type',
    'field_poll_date' => 'field_poll_date',
    'field_vote' => 'field_vote',
    'field_voted' => 'field_voted',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'ctools_dropdown' => 'ctools_dropdown',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
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
    'type' => array(
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
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
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
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeigt @start - @end von @total Stimmen/ Votes';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Einträge gefunden';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
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
  /* Beziehung: Feld: Parliament (field_parliament) */
  $handler->display->display_options['relationships']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['relationships']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['relationships']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['relationships']['field_parliament_tid']['label'] = 'Parliament Term';
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
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
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
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['fields']['ctools_dropdown']['check_access'] = 1;
  /* Kontextfilter: Inhalt: Abstimmung (field_vote_node) */
  $handler->display->display_options['arguments']['field_vote_node_target_id']['id'] = 'field_vote_node_target_id';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['field'] = 'field_vote_node_target_id';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_vote_node_target_id']['title'] = '%1 - Stimmen/ Votes';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_vote_node_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['validate_options']['types'] = array(
    'poll' => 'poll',
  );
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vote' => 'vote',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['filters']['field_user_fname_value']['group'] = 1;
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
  $handler->display->display_options['filters']['field_vote_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_vote_tid']['vocabulary'] = 'votes';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'poll' => 'poll',
    'pw_petition' => 'pw_petition',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
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
  $handler->display->display_options['path'] = 'node/%/votes';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Stimmen/ Votes';
  $handler->display->display_options['menu']['weight'] = '20';
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
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Vote Id';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'Vorname';
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
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Nachname';
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
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_vote_user_target_id';
  $handler->display->display_options['fields']['uid']['label'] = 'Politiker Id';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
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
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_parliament_tid';
  $handler->display->display_options['fields']['tid']['label'] = 'Parliament Id';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Inhalt: Abstimmung */
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
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum Abstimmung';
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
  /* Feld: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Letztes Update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_only_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Abstimmung (field_vote_node) */
  $handler->display->display_options['arguments']['field_vote_node_target_id']['id'] = 'field_vote_node_target_id';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['field'] = 'field_vote_node_target_id';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_vote_node_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_vote_node_target_id']['validate_options']['types'] = array(
    'poll' => 'poll',
  );
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
  $handler->display->display_options['path'] = 'node/%/votes/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['pw_administration_votings_by_poll'] = array(
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
    t('weiter'),
    t('letzte Seite »'),
    t('Zeigt @start - @end von @total Stimmen/ Votes'),
    t('Keine Einträge gefunden'),
    t('Politiker'),
    t('Abstimmung'),
    t('Parliament Term'),
    t('Bitte auswählen'),
    t('Veröffentlichung zurücknehmen'),
    t('Löschen'),
    t('Werte ändern'),
    t('[field_user_lname], [field_user_fname]'),
    t('Stimme'),
    t('Letztes Update'),
    t('[edit_node] [delete_node] '),
    t('Bearbeiten'),
    t('Aktionen'),
    t('Alle'),
    t('%1 - Stimmen/ Votes'),
    t('Vorname'),
    t('Nachname'),
    t('Veröffentlicht'),
    t('Abstimmung/ Petition'),
    t('Page'),
    t('Data export'),
    t('Vote Id'),
    t('Politiker Id'),
    t('Parliament'),
    t('Parliament Id'),
    t('.'),
    t('Typ'),
    t('Datum Abstimmung'),
    t('Stimmverhalten'),
  );
  $export['pw_administration_votings_by_poll'] = $view;

  return $export;
}
