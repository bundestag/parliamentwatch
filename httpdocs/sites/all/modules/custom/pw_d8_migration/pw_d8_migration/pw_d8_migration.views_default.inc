<?php
/**
 * @file
 * pw_d8_migration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_d8_migration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'export_blog_categories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'export_blog_categories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_blog_categories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Taxonomie-Begriff: Taxonomie-Begriff UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sortierkriterien: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  /* Filterkriterium: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'blogcategories' => 'blogcategories',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/blog_categories.csv';
  $translatables['export_blog_categories'] = array(
    t('Master'),
    t('export_blog_categories'),
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
    t('uuid'),
    t('tid'),
    t('.'),
    t('name'),
    t('Data export'),
  );
  $export['export_blog_categories'] = $view;

  $view = new view();
  $view->name = 'export_blogpost';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'export_blogpost';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_blogpost';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'nid' => 'nid',
    'uid' => 'uid',
    'path' => 'path',
    'created' => 'created',
    'field_politician' => 'field_politician',
    'title' => 'title',
    'status' => 'status',
    'field_blogpost_license' => 'field_blogpost_license',
    'field_topics' => 'field_topics',
    'field_blogpost_categories' => 'field_blogpost_categories',
    'field_blog_main_category' => 'field_blog_main_category',
    'fid' => 'fid',
    'field_file_image_alt_text' => 'field_file_image_alt_text',
    'field_file_image_title_text' => 'field_file_image_title_text',
    'field_image_copyright' => 'field_image_copyright',
    'field_blogpost_intro' => 'field_blogpost_intro',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_politician' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_blogpost_license' => array(
      'sortable' => 0,
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
    'field_blogpost_categories' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_blog_main_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_alt_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_title_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image_copyright' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_blogpost_intro' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
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
  /* Beziehung: Dateiverwendung: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Feld: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Pfad */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'alias';
  /* Feld: Inhalt: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Inhalt: Politicians */
  $handler->display->display_options['fields']['field_politician']['id'] = 'field_politician';
  $handler->display->display_options['fields']['field_politician']['table'] = 'field_data_field_politician';
  $handler->display->display_options['fields']['field_politician']['field'] = 'field_politician';
  $handler->display->display_options['fields']['field_politician']['label'] = 'politicians';
  $handler->display->display_options['fields']['field_politician']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_politician']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_politician']['settings'] = array(
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
  $handler->display->display_options['fields']['field_politician']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_politician']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_politician']['separator'] = ',';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Lizenz anzeigen */
  $handler->display->display_options['fields']['field_blogpost_license']['id'] = 'field_blogpost_license';
  $handler->display->display_options['fields']['field_blogpost_license']['table'] = 'field_data_field_blogpost_license';
  $handler->display->display_options['fields']['field_blogpost_license']['field'] = 'field_blogpost_license';
  $handler->display->display_options['fields']['field_blogpost_license']['label'] = 'show_license';
  $handler->display->display_options['fields']['field_blogpost_license']['empty'] = '0';
  $handler->display->display_options['fields']['field_blogpost_license']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_blogpost_license']['settings'] = array(
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
  $handler->display->display_options['fields']['field_topics']['label'] = 'topics';
  $handler->display->display_options['fields']['field_topics']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_topics']['alter']['text'] = '[field_topics-tid]';
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
  $handler->display->display_options['fields']['field_topics']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_topics']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_topics']['separator'] = ',';
  /* Feld: Inhalt: Categories */
  $handler->display->display_options['fields']['field_blogpost_categories']['id'] = 'field_blogpost_categories';
  $handler->display->display_options['fields']['field_blogpost_categories']['table'] = 'field_data_field_blogpost_categories';
  $handler->display->display_options['fields']['field_blogpost_categories']['field'] = 'field_blogpost_categories';
  $handler->display->display_options['fields']['field_blogpost_categories']['label'] = 'blog_categories';
  $handler->display->display_options['fields']['field_blogpost_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_blogpost_categories']['alter']['text'] = '[field_blogpost_categories-tid]';
  $handler->display->display_options['fields']['field_blogpost_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_blogpost_categories']['settings'] = array(
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
  $handler->display->display_options['fields']['field_blogpost_categories']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_blogpost_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_blogpost_categories']['separator'] = ',';
  /* Feld: Inhalt: Hauptkategorie */
  $handler->display->display_options['fields']['field_blog_main_category']['id'] = 'field_blog_main_category';
  $handler->display->display_options['fields']['field_blog_main_category']['table'] = 'field_data_field_blog_main_category';
  $handler->display->display_options['fields']['field_blog_main_category']['field'] = 'field_blog_main_category';
  $handler->display->display_options['fields']['field_blog_main_category']['label'] = 'blog_category_main';
  $handler->display->display_options['fields']['field_blog_main_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_blog_main_category']['alter']['text'] = '[field_blog_main_category-tid]';
  $handler->display->display_options['fields']['field_blog_main_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_blog_main_category']['settings'] = array(
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
  $handler->display->display_options['fields']['field_blog_main_category']['group_column'] = 'entity_id';
  /* Feld: MAX(Datei: Datei-ID) */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['fid']['group_type'] = 'max';
  $handler->display->display_options['fields']['fid']['label'] = 'teaser_image';
  /* Feld: Datei: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'teaser_image_alt';
  $handler->display->display_options['fields']['field_file_image_alt_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_alt_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_alt_text']['group_column'] = 'entity_id';
  /* Feld: Datei: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'teaser_image_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_title_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_title_text']['group_column'] = 'entity_id';
  /* Feld: Datei: copyright */
  $handler->display->display_options['fields']['field_image_copyright']['id'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['table'] = 'field_data_field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['field'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_image_copyright']['label'] = 'teaser_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['settings'] = array(
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
  $handler->display->display_options['fields']['field_image_copyright']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Intro */
  $handler->display->display_options['fields']['field_blogpost_intro']['id'] = 'field_blogpost_intro';
  $handler->display->display_options['fields']['field_blogpost_intro']['table'] = 'field_data_field_blogpost_intro';
  $handler->display->display_options['fields']['field_blogpost_intro']['field'] = 'field_blogpost_intro';
  $handler->display->display_options['fields']['field_blogpost_intro']['label'] = 'teaser';
  $handler->display->display_options['fields']['field_blogpost_intro']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_blogpost_intro']['settings'] = array(
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
  $handler->display->display_options['fields']['field_blogpost_intro']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
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
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Sortierkriterien: Inhalt: Beitrags-ID */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blogpost' => 'blogpost',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_replacement'] = '';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/blogpost.csv';
  $translatables['export_blogpost'] = array(
    t('Master'),
    t('export_blogpost'),
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
    t('Displaying @start - @end of @total'),
    t('Datei'),
    t('uuid'),
    t('nid'),
    t('uid'),
    t('alias'),
    t('created'),
    t('politicians'),
    t('Titel'),
    t('Status'),
    t('show_license'),
    t('topics'),
    t('[field_topics-tid]'),
    t('blog_categories'),
    t('[field_blogpost_categories-tid]'),
    t('blog_category_main'),
    t('[field_blog_main_category-tid]'),
    t('teaser_image'),
    t('teaser_image_alt'),
    t('teaser_image_title'),
    t('teaser_image_copyright'),
    t('teaser'),
    t('body'),
    t('Data export'),
  );
  $export['export_blogpost'] = $view;

  $view = new view();
  $view->name = 'export_blogpost_comment';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'export_blogpost_comment';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_blogpost_comment';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'cid' => 'cid',
    'pid' => 'pid',
    'nid' => 'nid',
    'status' => 'status',
    'hostname' => 'hostname',
    'created' => 'created',
    'comment_body' => 'comment_body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'pid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hostname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
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
  );
  /* Beziehung: Kommentar: Inhalt */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Feld: Kommentar: Kommentar UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'comment';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Kommentar: ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'comment';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = 'id';
  $handler->display->display_options['fields']['cid']['link_to_comment'] = FALSE;
  /* Feld: Kommentar: Übergeordnete Kommentar-ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'comment';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = 'pid';
  $handler->display->display_options['fields']['pid']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['pid']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['pid']['hide_alter_empty'] = FALSE;
  /* Feld: Kommentar: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'comment';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'entity_id';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Feld: Kommentar: Author */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Kommentar: Bestätigt */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'comment';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Kommentar: Hostname */
  $handler->display->display_options['fields']['hostname']['id'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['table'] = 'comment';
  $handler->display->display_options['fields']['hostname']['field'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['label'] = 'hostname';
  /* Feld: Kommentar: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Kommentar: Comment */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['label'] = 'body';
  $handler->display->display_options['fields']['comment_body']['settings'] = array(
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
  /* Sortierkriterien: Kommentar: ID */
  $handler->display->display_options['sorts']['cid']['id'] = 'cid';
  $handler->display->display_options['sorts']['cid']['table'] = 'comment';
  $handler->display->display_options['sorts']['cid']['field'] = 'cid';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blogpost' => 'blogpost',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = '';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/blogpost_comment.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '500';
  $translatables['export_blogpost_comment'] = array(
    t('Master'),
    t('export_blogpost_comment'),
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
    t('Inhalt'),
    t('uuid'),
    t('id'),
    t('pid'),
    t('entity_id'),
    t('.'),
    t('name'),
    t('Status'),
    t('hostname'),
    t('created'),
    t('body'),
    t('Data export'),
  );
  $export['export_blogpost_comment'] = $view;

  $view = new view();
  $view->name = 'export_committees_memberships';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'export_committees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_committees_memberships';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'nid' => 'nid',
    'uid' => 'uid',
    'created' => 'created',
    'title' => 'title',
    'field_poll_date' => 'field_poll_date',
    'status' => 'status',
    'field_topics' => 'field_topics',
    'fid' => 'fid',
    'field_file_image_alt_text' => 'field_file_image_alt_text',
    'field_file_image_title_text' => 'field_file_image_title_text',
    'field_image_copyright' => 'field_image_copyright',
    'body_1' => 'body_1',
    'body' => 'body',
    'field_poll_related_links' => 'field_poll_related_links',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_poll_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
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
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_alt_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_title_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image_copyright' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_poll_related_links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Beziehung: Dateiverwendung: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Feld: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Pfad */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'alias';
  /* Feld: Inhalt: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Topics */
  $handler->display->display_options['fields']['field_topics']['id'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['table'] = 'field_data_field_topics';
  $handler->display->display_options['fields']['field_topics']['field'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['label'] = 'topics';
  $handler->display->display_options['fields']['field_topics']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_topics']['alter']['text'] = '[field_topics-tid]';
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
  $handler->display->display_options['fields']['field_topics']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_topics']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_topics']['separator'] = ',';
  /* Feld: MAX(Datei: Datei-ID) */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['fid']['group_type'] = 'max';
  $handler->display->display_options['fields']['fid']['label'] = 'teaser_image';
  /* Feld: Datei: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'teaser_image_alt';
  $handler->display->display_options['fields']['field_file_image_alt_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_alt_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_alt_text']['group_column'] = 'entity_id';
  /* Feld: Datei: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'teaser_image_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_title_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_title_text']['group_column'] = 'entity_id';
  /* Feld: Datei: copyright */
  $handler->display->display_options['fields']['field_image_copyright']['id'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['table'] = 'field_data_field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['field'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_image_copyright']['label'] = 'teaser_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['settings'] = array(
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
  $handler->display->display_options['fields']['field_image_copyright']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'teaser';
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['text'] = '[body_1-summary]';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
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
  $handler->display->display_options['fields']['body_1']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
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
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'parliament_period';
  $handler->display->display_options['fields']['field_parliament']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_parliament']['alter']['text'] = '[field_parliament-tid]';
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
  $handler->display->display_options['fields']['field_parliament']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_parliament']['delta_offset'] = '0';
  /* Feld: Inhalt: Alternate Members */
  $handler->display->display_options['fields']['field_committee_alt_members']['id'] = 'field_committee_alt_members';
  $handler->display->display_options['fields']['field_committee_alt_members']['table'] = 'field_data_field_committee_alt_members';
  $handler->display->display_options['fields']['field_committee_alt_members']['field'] = 'field_committee_alt_members';
  $handler->display->display_options['fields']['field_committee_alt_members']['label'] = 'alternate_member';
  $handler->display->display_options['fields']['field_committee_alt_members']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_alt_members']['alter']['text'] = '[field_committee_alt_members-target_id]';
  $handler->display->display_options['fields']['field_committee_alt_members']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_alt_members']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_alt_members']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_alt_members']['separator'] = ',';
  /* Feld: Inhalt: Alternate Secretaries (female) */
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['id'] = 'field_committee_alt_sec_female';
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['table'] = 'field_data_field_committee_alt_sec_female';
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['field'] = 'field_committee_alt_sec_female';
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['label'] = 'alternate_secretary_female';
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['alter']['text'] = '[field_committee_alt_sec_female-target_id]';
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_alt_sec_female']['separator'] = ',';
  /* Feld: Inhalt: Alternate Secretaries (male) */
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['id'] = 'field_committee_alt_secretaries';
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['table'] = 'field_data_field_committee_alt_secretaries';
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['field'] = 'field_committee_alt_secretaries';
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['label'] = 'alternate_secretary';
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['alter']['text'] = '[field_committee_alt_secretaries-target_id]';
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_alt_secretaries']['separator'] = ',';
  /* Feld: Inhalt: Alternate Spokesman */
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['id'] = 'field_committee_alt_spokesman';
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['table'] = 'field_data_field_committee_alt_spokesman';
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['field'] = 'field_committee_alt_spokesman';
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['label'] = 'alternate_spokesperson';
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['alter']['text'] = '[field_committee_alt_spokesman-target_id]';
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_alt_spokesman']['separator'] = ',';
  /* Feld: Inhalt: Alternate Spokeswoman */
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['id'] = 'field_committee_alt_spokeswoman';
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['table'] = 'field_data_field_committee_alt_spokeswoman';
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['field'] = 'field_committee_alt_spokeswoman';
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['label'] = 'alternate_spokesperson_female';
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['alter']['text'] = '[field_committee_alt_spokeswoman-target_id]';
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_alt_spokeswoman']['separator'] = ',';
  /* Feld: Inhalt: Chairman */
  $handler->display->display_options['fields']['field_committee_chairman']['id'] = 'field_committee_chairman';
  $handler->display->display_options['fields']['field_committee_chairman']['table'] = 'field_data_field_committee_chairman';
  $handler->display->display_options['fields']['field_committee_chairman']['field'] = 'field_committee_chairman';
  $handler->display->display_options['fields']['field_committee_chairman']['label'] = 'chairperson';
  $handler->display->display_options['fields']['field_committee_chairman']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_chairman']['alter']['text'] = '[field_committee_chairman-target_id]';
  $handler->display->display_options['fields']['field_committee_chairman']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_chairman']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_chairman']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_chairman']['separator'] = ',';
  /* Feld: Inhalt: Eligible Members */
  $handler->display->display_options['fields']['field_committee_eligible_members']['id'] = 'field_committee_eligible_members';
  $handler->display->display_options['fields']['field_committee_eligible_members']['table'] = 'field_data_field_committee_eligible_members';
  $handler->display->display_options['fields']['field_committee_eligible_members']['field'] = 'field_committee_eligible_members';
  $handler->display->display_options['fields']['field_committee_eligible_members']['label'] = 'eligible_member';
  $handler->display->display_options['fields']['field_committee_eligible_members']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_eligible_members']['alter']['text'] = '[field_committee_eligible_members-target_id]';
  $handler->display->display_options['fields']['field_committee_eligible_members']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_eligible_members']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_eligible_members']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_eligible_members']['separator'] = ',';
  /* Feld: Inhalt: Foreman */
  $handler->display->display_options['fields']['field_committee_foreman']['id'] = 'field_committee_foreman';
  $handler->display->display_options['fields']['field_committee_foreman']['table'] = 'field_data_field_committee_foreman';
  $handler->display->display_options['fields']['field_committee_foreman']['field'] = 'field_committee_foreman';
  $handler->display->display_options['fields']['field_committee_foreman']['label'] = 'foreperson';
  $handler->display->display_options['fields']['field_committee_foreman']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_foreman']['alter']['text'] = '[field_committee_foreman-target_id]';
  $handler->display->display_options['fields']['field_committee_foreman']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_foreman']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_foreman']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_foreman']['separator'] = ',';
  /* Feld: Inhalt: Forewoman */
  $handler->display->display_options['fields']['field_committee_forewoman']['id'] = 'field_committee_forewoman';
  $handler->display->display_options['fields']['field_committee_forewoman']['table'] = 'field_data_field_committee_forewoman';
  $handler->display->display_options['fields']['field_committee_forewoman']['field'] = 'field_committee_forewoman';
  $handler->display->display_options['fields']['field_committee_forewoman']['label'] = 'foreperson_female';
  $handler->display->display_options['fields']['field_committee_forewoman']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_forewoman']['alter']['text'] = '[field_committee_forewoman-target_id]';
  $handler->display->display_options['fields']['field_committee_forewoman']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_forewoman']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_forewoman']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_forewoman']['separator'] = ',';
  /* Feld: Inhalt: Members */
  $handler->display->display_options['fields']['field_committee_members']['id'] = 'field_committee_members';
  $handler->display->display_options['fields']['field_committee_members']['table'] = 'field_data_field_committee_members';
  $handler->display->display_options['fields']['field_committee_members']['field'] = 'field_committee_members';
  $handler->display->display_options['fields']['field_committee_members']['label'] = 'member';
  $handler->display->display_options['fields']['field_committee_members']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_members']['alter']['text'] = '[field_committee_members-target_id]';
  $handler->display->display_options['fields']['field_committee_members']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_members']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_members']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_members']['separator'] = ',';
  /* Feld: Inhalt: Secretaries (female) */
  $handler->display->display_options['fields']['field_committee_sec_female']['id'] = 'field_committee_sec_female';
  $handler->display->display_options['fields']['field_committee_sec_female']['table'] = 'field_data_field_committee_sec_female';
  $handler->display->display_options['fields']['field_committee_sec_female']['field'] = 'field_committee_sec_female';
  $handler->display->display_options['fields']['field_committee_sec_female']['label'] = 'secretary_female';
  $handler->display->display_options['fields']['field_committee_sec_female']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_sec_female']['alter']['text'] = '[field_committee_sec_female-target_id]';
  $handler->display->display_options['fields']['field_committee_sec_female']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_sec_female']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_sec_female']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_sec_female']['separator'] = ',';
  /* Feld: Inhalt: Secretaries (male) */
  $handler->display->display_options['fields']['field_committee_secretaries']['id'] = 'field_committee_secretaries';
  $handler->display->display_options['fields']['field_committee_secretaries']['table'] = 'field_data_field_committee_secretaries';
  $handler->display->display_options['fields']['field_committee_secretaries']['field'] = 'field_committee_secretaries';
  $handler->display->display_options['fields']['field_committee_secretaries']['label'] = 'secretary';
  $handler->display->display_options['fields']['field_committee_secretaries']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_secretaries']['alter']['text'] = '[field_committee_secretaries-target_id]';
  $handler->display->display_options['fields']['field_committee_secretaries']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_secretaries']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_secretaries']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_secretaries']['separator'] = ',';
  /* Feld: Inhalt: Spokesman */
  $handler->display->display_options['fields']['field_committee_spokesman']['id'] = 'field_committee_spokesman';
  $handler->display->display_options['fields']['field_committee_spokesman']['table'] = 'field_data_field_committee_spokesman';
  $handler->display->display_options['fields']['field_committee_spokesman']['field'] = 'field_committee_spokesman';
  $handler->display->display_options['fields']['field_committee_spokesman']['label'] = 'spokesperson';
  $handler->display->display_options['fields']['field_committee_spokesman']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_spokesman']['alter']['text'] = '[field_committee_spokesman-target_id]';
  $handler->display->display_options['fields']['field_committee_spokesman']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_spokesman']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_spokesman']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_spokesman']['separator'] = ',';
  /* Feld: Inhalt: Spokeswoman */
  $handler->display->display_options['fields']['field_committee_spokeswoman']['id'] = 'field_committee_spokeswoman';
  $handler->display->display_options['fields']['field_committee_spokeswoman']['table'] = 'field_data_field_committee_spokeswoman';
  $handler->display->display_options['fields']['field_committee_spokeswoman']['field'] = 'field_committee_spokeswoman';
  $handler->display->display_options['fields']['field_committee_spokeswoman']['label'] = 'spokesperson_female';
  $handler->display->display_options['fields']['field_committee_spokeswoman']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_spokeswoman']['alter']['text'] = '[field_committee_spokeswoman-target_id]';
  $handler->display->display_options['fields']['field_committee_spokeswoman']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_spokeswoman']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_spokeswoman']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_spokeswoman']['separator'] = ',';
  /* Feld: Inhalt: Vice Chairman */
  $handler->display->display_options['fields']['field_committee_vice_chairman']['id'] = 'field_committee_vice_chairman';
  $handler->display->display_options['fields']['field_committee_vice_chairman']['table'] = 'field_data_field_committee_vice_chairman';
  $handler->display->display_options['fields']['field_committee_vice_chairman']['field'] = 'field_committee_vice_chairman';
  $handler->display->display_options['fields']['field_committee_vice_chairman']['label'] = 'vice_chairperson';
  $handler->display->display_options['fields']['field_committee_vice_chairman']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee_vice_chairman']['alter']['text'] = '[field_committee_vice_chairman-target_id]';
  $handler->display->display_options['fields']['field_committee_vice_chairman']['settings'] = array(
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
  $handler->display->display_options['fields']['field_committee_vice_chairman']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_committee_vice_chairman']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_committee_vice_chairman']['separator'] = ',';
  /* Sortierkriterien: Inhalt: Beitrags-ID */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'committee' => 'committee',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/committees_memberships.csv';
  $translatables['export_committees_memberships'] = array(
    t('Master'),
    t('export_committees_memberships'),
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
    t('Datei'),
    t('uuid'),
    t('nid'),
    t('uid'),
    t('alias'),
    t('created'),
    t('Titel'),
    t('Status'),
    t('topics'),
    t('[field_topics-tid]'),
    t('teaser_image'),
    t('teaser_image_alt'),
    t('teaser_image_title'),
    t('teaser_image_copyright'),
    t('teaser'),
    t('[body_1-summary]'),
    t('body'),
    t('parliament_period'),
    t('[field_parliament-tid]'),
    t('alternate_member'),
    t('[field_committee_alt_members-target_id]'),
    t('alternate_secretary_female'),
    t('[field_committee_alt_sec_female-target_id]'),
    t('alternate_secretary'),
    t('[field_committee_alt_secretaries-target_id]'),
    t('alternate_spokesperson'),
    t('[field_committee_alt_spokesman-target_id]'),
    t('alternate_spokesperson_female'),
    t('[field_committee_alt_spokeswoman-target_id]'),
    t('chairperson'),
    t('[field_committee_chairman-target_id]'),
    t('eligible_member'),
    t('[field_committee_eligible_members-target_id]'),
    t('foreperson'),
    t('[field_committee_foreman-target_id]'),
    t('foreperson_female'),
    t('[field_committee_forewoman-target_id]'),
    t('member'),
    t('[field_committee_members-target_id]'),
    t('secretary_female'),
    t('[field_committee_sec_female-target_id]'),
    t('secretary'),
    t('[field_committee_secretaries-target_id]'),
    t('spokesperson'),
    t('[field_committee_spokesman-target_id]'),
    t('spokesperson_female'),
    t('[field_committee_spokeswoman-target_id]'),
    t('vice_chairperson'),
    t('[field_committee_vice_chairman-target_id]'),
    t('Data export'),
  );
  $export['export_committees_memberships'] = $view;

  $view = new view();
  $view->name = 'export_file';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'export_file';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_files';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'fid' => 'fid',
    'uid' => 'uid',
    'uri' => 'uri',
    'filename' => 'filename',
    'field_file_image_alt_text' => 'field_file_image_alt_text',
    'field_image_copyright' => 'field_image_copyright',
    'status' => 'status',
    'field_file_image_title_text' => 'field_file_image_title_text',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uri' => array(
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
    'field_file_image_alt_text' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image_copyright' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_title_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Kopfzeile: Global: Result summary with an additional token to change the items/page */
  $handler->display->display_options['header']['webform_result']['id'] = 'webform_result';
  $handler->display->display_options['header']['webform_result']['table'] = 'views';
  $handler->display->display_options['header']['webform_result']['field'] = 'webform_result';
  /* Beziehung: Datei: Benutzer, der hochgeladen hat */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Feld: Datei: Datei UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Datei: Datei-ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = 'id';
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Datei: Pfad */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['label'] = 'path';
  /* Feld: Datei: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = 'name';
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
  /* Sortierkriterien: Datei: Datei-ID */
  $handler->display->display_options['sorts']['fid']['id'] = 'fid';
  $handler->display->display_options['sorts']['fid']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['fid']['field'] = 'fid';
  /* Filterkriterium: Datei: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/file.csv';
  $translatables['export_file'] = array(
    t('Master'),
    t('export_files'),
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
    t('Zeige @start - @end von @total. @items_per_page_links'),
    t('Benutzer, der hochgeladen hat'),
    t('uuid'),
    t('id'),
    t('uid'),
    t('path'),
    t('name'),
    t('Data export'),
  );
  $export['export_file'] = $view;

  $view = new view();
  $view->name = 'export_fractions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'export_fractions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_fractions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'tid' => 'tid',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Feld: Taxonomie-Begriff: Taxonomie-Begriff UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sortierkriterien: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  /* Filterkriterium: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'fraction' => 'fraction',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/fractions.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['export_fractions'] = array(
    t('Master'),
    t('export_fractions'),
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
    t('uuid'),
    t('tid'),
    t('.'),
    t('name'),
    t('Data export'),
  );
  $export['export_fractions'] = $view;

  $view = new view();
  $view->name = 'export_newsletter_paragraphs_text';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'paragraphs_item';
  $view->human_name = 'export_newsletter_paragraphs_text';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_newsletter_paragraphs_text';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'item_id' => 'item_id',
    'field_file_image_alt_text' => 'field_file_image_alt_text',
    'field_image_copyright' => 'field_image_copyright',
    'fid' => 'fid',
    'field_pg_content_title' => 'field_pg_content_title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_alt_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image_copyright' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pg_content_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Beziehung: Seitenabschnittselement: Bild (field_pg_content_img:fid) */
  $handler->display->display_options['relationships']['field_pg_content_img_fid']['id'] = 'field_pg_content_img_fid';
  $handler->display->display_options['relationships']['field_pg_content_img_fid']['table'] = 'field_data_field_pg_content_img';
  $handler->display->display_options['relationships']['field_pg_content_img_fid']['field'] = 'field_pg_content_img_fid';
  /* Feld: Seitenabschnittselement: Seitenabschnittselement ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'paragraphs_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = 'pid';
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Feld: Seitenabschnittselement: Titel */
  $handler->display->display_options['fields']['field_pg_content_title']['id'] = 'field_pg_content_title';
  $handler->display->display_options['fields']['field_pg_content_title']['table'] = 'field_data_field_pg_content_title';
  $handler->display->display_options['fields']['field_pg_content_title']['field'] = 'field_pg_content_title';
  $handler->display->display_options['fields']['field_pg_content_title']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_pg_content_title']['settings'] = array(
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
  /* Feld: Datei: Datei-ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'field_pg_content_img_fid';
  $handler->display->display_options['fields']['fid']['label'] = 'teaser_image';
  /* Feld: Datei: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'field_pg_content_img_fid';
  /* Feld: Datei: copyright */
  $handler->display->display_options['fields']['field_image_copyright']['id'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['table'] = 'field_data_field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['field'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['relationship'] = 'field_pg_content_img_fid';
  $handler->display->display_options['fields']['field_image_copyright']['label'] = 'teaser_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['settings'] = array(
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
  /* Feld: Seitenabschnittselement: Body */
  $handler->display->display_options['fields']['field_pg_content_body']['id'] = 'field_pg_content_body';
  $handler->display->display_options['fields']['field_pg_content_body']['table'] = 'field_data_field_pg_content_body';
  $handler->display->display_options['fields']['field_pg_content_body']['field'] = 'field_pg_content_body';
  $handler->display->display_options['fields']['field_pg_content_body']['label'] = 'body';
  $handler->display->display_options['fields']['field_pg_content_body']['settings'] = array(
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
  /* Feld: Seitenabschnittselement: Zielgruppe */
  $handler->display->display_options['fields']['field_pg_donate_targetgroup']['id'] = 'field_pg_donate_targetgroup';
  $handler->display->display_options['fields']['field_pg_donate_targetgroup']['table'] = 'field_data_field_pg_donate_targetgroup';
  $handler->display->display_options['fields']['field_pg_donate_targetgroup']['field'] = 'field_pg_donate_targetgroup';
  $handler->display->display_options['fields']['field_pg_donate_targetgroup']['label'] = 'target_group';
  $handler->display->display_options['fields']['field_pg_donate_targetgroup']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_pg_donate_targetgroup']['settings'] = array(
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
  $handler->display->display_options['fields']['field_pg_donate_targetgroup']['delta_offset'] = '0';
  /* Feld: Feld: Im Archiv anzeigen */
  $handler->display->display_options['fields']['field_show']['id'] = 'field_show';
  $handler->display->display_options['fields']['field_show']['table'] = 'field_data_field_show';
  $handler->display->display_options['fields']['field_show']['field'] = 'field_show';
  $handler->display->display_options['fields']['field_show']['label'] = 'show_archive';
  $handler->display->display_options['fields']['field_show']['empty'] = '0';
  $handler->display->display_options['fields']['field_show']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_show']['settings'] = array(
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
  /* Feld: Seitenabschnittselement: Link */
  $handler->display->display_options['fields']['field_pg_content_link']['id'] = 'field_pg_content_link';
  $handler->display->display_options['fields']['field_pg_content_link']['table'] = 'field_data_field_pg_content_link';
  $handler->display->display_options['fields']['field_pg_content_link']['field'] = 'field_pg_content_link';
  $handler->display->display_options['fields']['field_pg_content_link']['label'] = 'links';
  $handler->display->display_options['fields']['field_pg_content_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pg_content_link']['alter']['text'] = '[field_pg_content_link-url]|[field_pg_content_link-title]';
  $handler->display->display_options['fields']['field_pg_content_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pg_content_link']['settings'] = array(
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
  $handler->display->display_options['fields']['field_pg_content_link']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_pg_content_link']['delta_offset'] = '0';
  /* Feld: Seitenabschnittselement: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'paragraphs_item';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Sortierkriterien: Seitenabschnittselement: Seitenabschnittselement ID */
  $handler->display->display_options['sorts']['item_id']['id'] = 'item_id';
  $handler->display->display_options['sorts']['item_id']['table'] = 'paragraphs_item';
  $handler->display->display_options['sorts']['item_id']['field'] = 'item_id';
  /* Filterkriterium: Seitenabschnittselement: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'paragraphs_item';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'paragraphs_pw_content' => 'paragraphs_pw_content',
    'paragraphs_pw_donate' => 'paragraphs_pw_donate',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/newsletter_paragraphs_text.csv';
  $translatables['export_newsletter_paragraphs_text'] = array(
    t('Master'),
    t('export_newsletter_paragraphs_text'),
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
    t('Bild von field_pg_content_img'),
    t('pid'),
    t('.'),
    t('Titel'),
    t('teaser_image'),
    t('Alt Text'),
    t('teaser_image_copyright'),
    t('body'),
    t('target_group'),
    t('show_archive'),
    t('links'),
    t('[field_pg_content_link-url]|[field_pg_content_link-title]'),
    t('bundle'),
    t('Data export'),
  );
  $export['export_newsletter_paragraphs_text'] = $view;

  $view = new view();
  $view->name = 'export_newsletters';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'export_newsletters';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_newsletters';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'nid' => 'nid',
    'uid' => 'uid',
    'path' => 'path',
    'created' => 'created',
    'field_politician' => 'field_politician',
    'title' => 'title',
    'status' => 'status',
    'field_show' => 'field_show',
    'field_piwik_campaign' => 'field_piwik_campaign',
    'fid' => 'fid',
    'field_file_image_alt_text' => 'field_file_image_alt_text',
    'field_file_image_title_text' => 'field_file_image_title_text',
    'field_image_copyright' => 'field_image_copyright',
    'body_1' => 'body_1',
    'field_newsletter_summary' => 'field_newsletter_summary',
    'body' => 'body',
    'field_newsletter_paragraph' => 'field_newsletter_paragraph',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_politician' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_show' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_piwik_campaign' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_alt_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_title_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image_copyright' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_newsletter_summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_newsletter_paragraph' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Kopfzeile: Global: Ergebnis-Zusammenfassung */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Beziehung: Dateiverwendung: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Feld: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Pfad */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'alias';
  /* Feld: Inhalt: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Inhalt: Politicians */
  $handler->display->display_options['fields']['field_politician']['id'] = 'field_politician';
  $handler->display->display_options['fields']['field_politician']['table'] = 'field_data_field_politician';
  $handler->display->display_options['fields']['field_politician']['field'] = 'field_politician';
  $handler->display->display_options['fields']['field_politician']['label'] = 'politicians';
  $handler->display->display_options['fields']['field_politician']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_politician']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_politician']['settings'] = array(
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
  $handler->display->display_options['fields']['field_politician']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_politician']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_politician']['separator'] = ',';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Feld: Im Archiv anzeigen */
  $handler->display->display_options['fields']['field_show']['id'] = 'field_show';
  $handler->display->display_options['fields']['field_show']['table'] = 'field_data_field_show';
  $handler->display->display_options['fields']['field_show']['field'] = 'field_show';
  $handler->display->display_options['fields']['field_show']['label'] = 'show_archive';
  $handler->display->display_options['fields']['field_show']['empty'] = '0';
  $handler->display->display_options['fields']['field_show']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_show']['settings'] = array(
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
  $handler->display->display_options['fields']['field_show']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Piwik Campaign */
  $handler->display->display_options['fields']['field_piwik_campaign']['id'] = 'field_piwik_campaign';
  $handler->display->display_options['fields']['field_piwik_campaign']['table'] = 'field_data_field_piwik_campaign';
  $handler->display->display_options['fields']['field_piwik_campaign']['field'] = 'field_piwik_campaign';
  $handler->display->display_options['fields']['field_piwik_campaign']['label'] = 'campaign';
  $handler->display->display_options['fields']['field_piwik_campaign']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_piwik_campaign']['settings'] = array(
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
  $handler->display->display_options['fields']['field_piwik_campaign']['group_column'] = 'entity_id';
  /* Feld: MAX(Datei: Datei-ID) */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['fid']['group_type'] = 'max';
  $handler->display->display_options['fields']['fid']['label'] = 'teaser_image';
  /* Feld: Datei: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'teaser_image_alt';
  $handler->display->display_options['fields']['field_file_image_alt_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_alt_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_alt_text']['group_column'] = 'entity_id';
  /* Feld: Datei: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'teaser_image_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_title_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_title_text']['group_column'] = 'entity_id';
  /* Feld: Datei: copyright */
  $handler->display->display_options['fields']['field_image_copyright']['id'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['table'] = 'field_data_field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['field'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_image_copyright']['label'] = 'teaser_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['settings'] = array(
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
  $handler->display->display_options['fields']['field_image_copyright']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'teaser_old';
  $handler->display->display_options['fields']['body_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['text'] = '[body_1-summary]';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
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
  $handler->display->display_options['fields']['body_1']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Zusammenfassung */
  $handler->display->display_options['fields']['field_newsletter_summary']['id'] = 'field_newsletter_summary';
  $handler->display->display_options['fields']['field_newsletter_summary']['table'] = 'field_data_field_newsletter_summary';
  $handler->display->display_options['fields']['field_newsletter_summary']['field'] = 'field_newsletter_summary';
  $handler->display->display_options['fields']['field_newsletter_summary']['label'] = 'teaser';
  $handler->display->display_options['fields']['field_newsletter_summary']['empty'] = '[body_1]';
  $handler->display->display_options['fields']['field_newsletter_summary']['settings'] = array(
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
  $handler->display->display_options['fields']['field_newsletter_summary']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
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
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Abschnitt */
  $handler->display->display_options['fields']['field_newsletter_paragraph']['id'] = 'field_newsletter_paragraph';
  $handler->display->display_options['fields']['field_newsletter_paragraph']['table'] = 'field_data_field_newsletter_paragraph';
  $handler->display->display_options['fields']['field_newsletter_paragraph']['field'] = 'field_newsletter_paragraph';
  $handler->display->display_options['fields']['field_newsletter_paragraph']['label'] = 'paragraphs';
  $handler->display->display_options['fields']['field_newsletter_paragraph']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_newsletter_paragraph']['alter']['text'] = '[field_newsletter_paragraph-revision_id]';
  $handler->display->display_options['fields']['field_newsletter_paragraph']['settings'] = array(
    'view_mode' => 'full',
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
  $handler->display->display_options['fields']['field_newsletter_paragraph']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_newsletter_paragraph']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_newsletter_paragraph']['separator'] = ',';
  /* Sortierkriterien: Inhalt: Beitrags-ID */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'newsletter' => 'newsletter',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = '';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/newsletters.csv';
  $translatables['export_newsletters'] = array(
    t('Master'),
    t('export_newsletters'),
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
    t('Displaying @start - @end of @total'),
    t('Datei'),
    t('uuid'),
    t('nid'),
    t('uid'),
    t('alias'),
    t('created'),
    t('politicians'),
    t('Titel'),
    t('Status'),
    t('show_archive'),
    t('campaign'),
    t('teaser_image'),
    t('teaser_image_alt'),
    t('teaser_image_title'),
    t('teaser_image_copyright'),
    t('teaser_old'),
    t('[body_1-summary]'),
    t('teaser'),
    t('[body_1]'),
    t('body'),
    t('paragraphs'),
    t('[field_newsletter_paragraph-revision_id]'),
    t('Data export'),
  );
  $export['export_newsletters'] = $view;

  $view = new view();
  $view->name = 'export_parliament_periods';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'export_parliament_periods';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'parliament_periods';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'tid' => 'tid',
    'name' => 'name',
    'field_parliament_election' => 'field_parliament_election',
    'field_parliament_valid_2' => 'field_parliament_valid_2',
    'field_parliament_valid_3' => 'field_parliament_valid_3',
    'field_parliament_valid' => 'field_parliament_valid',
    'field_parliament_valid_1' => 'field_parliament_valid_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament_election' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament_valid_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament_valid_3' => array(
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
  );
  /* Feld: Taxonomie-Begriff: Taxonomie-Begriff UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Feld: Taxonomie-Begriff: Election */
  $handler->display->display_options['fields']['field_parliament_election']['id'] = 'field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['table'] = 'field_data_field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['field'] = 'field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['label'] = 'election_date';
  $handler->display->display_options['fields']['field_parliament_election']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
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
  $handler->display->display_options['fields']['field_parliament_valid_2']['id'] = 'field_parliament_valid_2';
  $handler->display->display_options['fields']['field_parliament_valid_2']['table'] = 'field_data_field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid_2']['field'] = 'field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid_2']['label'] = 'start_date_election_project';
  $handler->display->display_options['fields']['field_parliament_valid_2']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
    'fromto' => 'value',
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
  $handler->display->display_options['fields']['field_parliament_valid_2']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_parliament_valid_2']['delta_offset'] = '0';
  /* Feld: Taxonomie-Begriff: Valid Date */
  $handler->display->display_options['fields']['field_parliament_valid_3']['id'] = 'field_parliament_valid_3';
  $handler->display->display_options['fields']['field_parliament_valid_3']['table'] = 'field_data_field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid_3']['field'] = 'field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid_3']['label'] = 'end_date_election_project';
  $handler->display->display_options['fields']['field_parliament_valid_3']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
    'fromto' => 'value2',
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
  $handler->display->display_options['fields']['field_parliament_valid_3']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_parliament_valid_3']['delta_offset'] = '0';
  /* Feld: Taxonomie-Begriff: Valid Date */
  $handler->display->display_options['fields']['field_parliament_valid']['id'] = 'field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid']['table'] = 'field_data_field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid']['field'] = 'field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid']['label'] = 'start_date_legislature_project';
  $handler->display->display_options['fields']['field_parliament_valid']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
    'fromto' => 'value',
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
  $handler->display->display_options['fields']['field_parliament_valid']['delta_offset'] = '1';
  /* Feld: Taxonomie-Begriff: Valid Date */
  $handler->display->display_options['fields']['field_parliament_valid_1']['id'] = 'field_parliament_valid_1';
  $handler->display->display_options['fields']['field_parliament_valid_1']['table'] = 'field_data_field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid_1']['field'] = 'field_parliament_valid';
  $handler->display->display_options['fields']['field_parliament_valid_1']['label'] = 'end_date_legislature_project';
  $handler->display->display_options['fields']['field_parliament_valid_1']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
    'fromto' => 'value2',
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
  /* Feld: Taxonomie-Begriff: Previous parliament */
  $handler->display->display_options['fields']['field_parliament_previous']['id'] = 'field_parliament_previous';
  $handler->display->display_options['fields']['field_parliament_previous']['table'] = 'field_data_field_parliament_previous';
  $handler->display->display_options['fields']['field_parliament_previous']['field'] = 'field_parliament_previous';
  $handler->display->display_options['fields']['field_parliament_previous']['label'] = 'previous_parliament_period';
  $handler->display->display_options['fields']['field_parliament_previous']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_parliament_previous']['alter']['text'] = '[field_parliament_previous-tid]';
  $handler->display->display_options['fields']['field_parliament_previous']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_parliament_previous']['settings'] = array(
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
  /* Sortierkriterien: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  /* Filterkriterium: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'parliaments' => 'parliaments',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/parliament_periods.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['export_parliament_periods'] = array(
    t('Master'),
    t('parliament_periods'),
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
    t('uuid'),
    t('tid'),
    t('.'),
    t('name'),
    t('election_date'),
    t('start_date_election_project'),
    t('end_date_election_project'),
    t('start_date_legislature_project'),
    t('end_date_legislature_project'),
    t('previous_parliament_period'),
    t('[field_parliament_previous-tid]'),
    t('Data export'),
  );
  $export['export_parliament_periods'] = $view;

  $view = new view();
  $view->name = 'export_parliaments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'export_parliaments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_parliaments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'tid' => 'tid',
    'name' => 'name',
    'field_parliament_election' => 'field_parliament_election',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parliament_election' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Feld: Taxonomie-Begriff: Taxonomie-Begriff UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Feld: Taxonomie-Begriff: Election */
  $handler->display->display_options['fields']['field_parliament_election']['id'] = 'field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['table'] = 'field_data_field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['field'] = 'field_parliament_election';
  $handler->display->display_options['fields']['field_parliament_election']['label'] = 'election_date';
  $handler->display->display_options['fields']['field_parliament_election']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
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
  /* Sortierkriterien: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  /* Filterkriterium: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'parliaments' => 'parliaments',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/parliaments.csv';
  $translatables['export_parliaments'] = array(
    t('Master'),
    t('export_parliaments'),
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
    t('uuid'),
    t('tid'),
    t('.'),
    t('name'),
    t('election_date'),
    t('Data export'),
  );
  $export['export_parliaments'] = $view;

  $view = new view();
  $view->name = 'export_parties';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'export_parties';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_parties';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'tid' => 'tid',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Feld: Taxonomie-Begriff: Taxonomie-Begriff UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sortierkriterien: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  /* Filterkriterium: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'party' => 'party',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/parties.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['export_parties'] = array(
    t('Master'),
    t('export_parties'),
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
    t('uuid'),
    t('tid'),
    t('.'),
    t('name'),
    t('Data export'),
  );
  $export['export_parties'] = $view;

  $view = new view();
  $view->name = 'export_polls';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'export_polls';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_polls';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'nid' => 'nid',
    'uid' => 'uid',
    'created' => 'created',
    'title' => 'title',
    'field_poll_date' => 'field_poll_date',
    'status' => 'status',
    'field_topics' => 'field_topics',
    'fid' => 'fid',
    'field_file_image_alt_text' => 'field_file_image_alt_text',
    'field_file_image_title_text' => 'field_file_image_title_text',
    'field_image_copyright' => 'field_image_copyright',
    'body_1' => 'body_1',
    'body' => 'body',
    'field_poll_related_links' => 'field_poll_related_links',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_poll_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
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
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_alt_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_title_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image_copyright' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_poll_related_links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Beziehung: Dateiverwendung: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Feld: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Pfad */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'alias';
  /* Feld: Inhalt: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Poll Date */
  $handler->display->display_options['fields']['field_poll_date']['id'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['table'] = 'field_data_field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['field'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'poll_date';
  $handler->display->display_options['fields']['field_poll_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_poll_date']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
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
  $handler->display->display_options['fields']['field_poll_date']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Topics */
  $handler->display->display_options['fields']['field_topics']['id'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['table'] = 'field_data_field_topics';
  $handler->display->display_options['fields']['field_topics']['field'] = 'field_topics';
  $handler->display->display_options['fields']['field_topics']['label'] = 'topics';
  $handler->display->display_options['fields']['field_topics']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_topics']['alter']['text'] = '[field_topics-tid]';
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
  $handler->display->display_options['fields']['field_topics']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_topics']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_topics']['separator'] = ',';
  /* Feld: MAX(Datei: Datei-ID) */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['fid']['group_type'] = 'max';
  $handler->display->display_options['fields']['fid']['label'] = 'teaser_image';
  /* Feld: Datei: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'teaser_image_alt';
  $handler->display->display_options['fields']['field_file_image_alt_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_alt_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_alt_text']['group_column'] = 'entity_id';
  /* Feld: Datei: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'teaser_image_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_title_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_title_text']['group_column'] = 'entity_id';
  /* Feld: Datei: copyright */
  $handler->display->display_options['fields']['field_image_copyright']['id'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['table'] = 'field_data_field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['field'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['field_image_copyright']['label'] = 'teaser_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['settings'] = array(
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
  $handler->display->display_options['fields']['field_image_copyright']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'teaser';
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['text'] = '[body_1-summary]';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
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
  $handler->display->display_options['fields']['body_1']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
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
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Related Links */
  $handler->display->display_options['fields']['field_poll_related_links']['id'] = 'field_poll_related_links';
  $handler->display->display_options['fields']['field_poll_related_links']['table'] = 'field_data_field_poll_related_links';
  $handler->display->display_options['fields']['field_poll_related_links']['field'] = 'field_poll_related_links';
  $handler->display->display_options['fields']['field_poll_related_links']['label'] = 'related_links';
  $handler->display->display_options['fields']['field_poll_related_links']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_poll_related_links']['alter']['text'] = '[field_poll_related_links-url]|[field_poll_related_links-url]';
  $handler->display->display_options['fields']['field_poll_related_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_poll_related_links']['settings'] = array(
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
  $handler->display->display_options['fields']['field_poll_related_links']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_poll_related_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_poll_related_links']['separator'] = ',';
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['label'] = 'parliament_period';
  $handler->display->display_options['fields']['field_parliament']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_parliament']['alter']['text'] = '[field_parliament-tid]';
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
  /* Sortierkriterien: Inhalt: Beitrags-ID */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poll' => 'poll',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/polls.csv';
  $translatables['export_polls'] = array(
    t('Master'),
    t('export_polls'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Datei'),
    t('uuid'),
    t('nid'),
    t('uid'),
    t('alias'),
    t('created'),
    t('Titel'),
    t('poll_date'),
    t('Status'),
    t('topics'),
    t('[field_topics-tid]'),
    t('teaser_image'),
    t('teaser_image_alt'),
    t('teaser_image_title'),
    t('teaser_image_copyright'),
    t('teaser'),
    t('[body_1-summary]'),
    t('body'),
    t('related_links'),
    t('[field_poll_related_links-url]|[field_poll_related_links-url]'),
    t('parliament_period'),
    t('[field_parliament-tid]'),
    t('Data export'),
  );
  $export['export_polls'] = $view;

  $view = new view();
  $view->name = 'export_polls_comment';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'export_polls_comment';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_polls_comment';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'cid' => 'cid',
    'pid' => 'pid',
    'nid' => 'nid',
    'status' => 'status',
    'hostname' => 'hostname',
    'created' => 'created',
    'comment_body' => 'comment_body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'pid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hostname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
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
  );
  /* Beziehung: Kommentar: Inhalt */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Feld: Kommentar: Kommentar UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'comment';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Kommentar: ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'comment';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = 'id';
  $handler->display->display_options['fields']['cid']['link_to_comment'] = FALSE;
  /* Feld: Kommentar: Übergeordnete Kommentar-ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'comment';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = 'pid';
  $handler->display->display_options['fields']['pid']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['pid']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['pid']['hide_alter_empty'] = FALSE;
  /* Feld: Kommentar: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'comment';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'entity_id';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Feld: Kommentar: Author */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Kommentar: Bestätigt */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'comment';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Kommentar: Hostname */
  $handler->display->display_options['fields']['hostname']['id'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['table'] = 'comment';
  $handler->display->display_options['fields']['hostname']['field'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['label'] = 'hostname';
  /* Feld: Kommentar: Beitragsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Feld: Kommentar: Comment */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['label'] = 'body';
  $handler->display->display_options['fields']['comment_body']['settings'] = array(
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
  /* Sortierkriterien: Kommentar: ID */
  $handler->display->display_options['sorts']['cid']['id'] = 'cid';
  $handler->display->display_options['sorts']['cid']['table'] = 'comment';
  $handler->display->display_options['sorts']['cid']['field'] = 'cid';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poll' => 'poll',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = '';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/polls_comment.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '500';
  $translatables['export_polls_comment'] = array(
    t('Master'),
    t('export_polls_comment'),
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
    t('Inhalt'),
    t('uuid'),
    t('id'),
    t('pid'),
    t('entity_id'),
    t('.'),
    t('name'),
    t('Status'),
    t('hostname'),
    t('created'),
    t('body'),
    t('Data export'),
  );
  $export['export_polls_comment'] = $view;

  $view = new view();
  $view->name = 'export_press_review';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'export_press_review';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_blogpost';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Beziehung: Dateiverwendung: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Attachment */
  $handler->display->display_options['fields']['field_press_article_attachment']['id'] = 'field_press_article_attachment';
  $handler->display->display_options['fields']['field_press_article_attachment']['table'] = 'field_data_field_press_article_attachment';
  $handler->display->display_options['fields']['field_press_article_attachment']['field'] = 'field_press_article_attachment';
  $handler->display->display_options['fields']['field_press_article_attachment']['label'] = 'attachment';
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['text'] = '[field_press_article_attachment-fid]';
  $handler->display->display_options['fields']['field_press_article_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_article_attachment']['settings'] = array(
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
  /* Feld: Inhalt: Date of publication */
  $handler->display->display_options['fields']['field_press_article_date']['id'] = 'field_press_article_date';
  $handler->display->display_options['fields']['field_press_article_date']['table'] = 'field_data_field_press_article_date';
  $handler->display->display_options['fields']['field_press_article_date']['field'] = 'field_press_article_date';
  $handler->display->display_options['fields']['field_press_article_date']['label'] = 'publishing_date';
  $handler->display->display_options['fields']['field_press_article_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_date']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
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
  /* Feld: Inhalt: External link */
  $handler->display->display_options['fields']['field_press_article_link']['id'] = 'field_press_article_link';
  $handler->display->display_options['fields']['field_press_article_link']['table'] = 'field_data_field_press_article_link';
  $handler->display->display_options['fields']['field_press_article_link']['field'] = 'field_press_article_link';
  $handler->display->display_options['fields']['field_press_article_link']['label'] = 'link_uri';
  $handler->display->display_options['fields']['field_press_article_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_press_article_link']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_press_article_link']['settings'] = array(
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
  /* Feld: Inhalt: Publisher */
  $handler->display->display_options['fields']['field_press_article_publisher']['id'] = 'field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['table'] = 'field_data_field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['field'] = 'field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['label'] = 'publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_press_article_publisher']['settings'] = array(
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
  /* Sortierkriterien: Inhalt: Beitrags-ID */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_article' => 'press_article',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/press_review.csv';
  $translatables['export_press_review'] = array(
    t('Master'),
    t('export_blogpost'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Datei'),
    t('uuid'),
    t('nid'),
    t('Titel'),
    t('Status'),
    t('attachment'),
    t('[field_press_article_attachment-fid]'),
    t('publishing_date'),
    t('link_uri'),
    t('publisher'),
    t('Data export'),
  );
  $export['export_press_review'] = $view;

  $view = new view();
  $view->name = 'export_topics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'export_topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_topics';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Taxonomie-Begriff: Taxonomie-Begriff UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sortierkriterien: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  /* Filterkriterium: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'topics' => 'topics',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/topics.csv';
  $translatables['export_topics'] = array(
    t('Master'),
    t('export_topics'),
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
    t('uuid'),
    t('tid'),
    t('.'),
    t('name'),
    t('Data export'),
  );
  $export['export_topics'] = $view;

  $view = new view();
  $view->name = 'export_user_administrative';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'export_user_administrative';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_user_administrative';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: Aktiv */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'email';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['label'] = 'roles';
  $handler->display->display_options['fields']['rid']['separator'] = ',';
  /* Sortierkriterien: Benutzer: Uid */
  $handler->display->display_options['sorts']['uid']['id'] = 'uid';
  $handler->display->display_options['sorts']['uid']['table'] = 'users';
  $handler->display->display_options['sorts']['uid']['field'] = 'uid';
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    30037204 => '30037204',
    51622513 => '51622513',
    29859578 => '29859578',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/user_administrative.csv';
  $translatables['export_user_administrative'] = array(
    t('Master'),
    t('export_user_administrative'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('uuid'),
    t('uid'),
    t('Status'),
    t('username'),
    t('email'),
    t('roles'),
    t('Data export'),
  );
  $export['export_user_administrative'] = $view;

  $view = new view();
  $view->name = 'export_user_politician';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'export_user_politician';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_user_politician';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'uid' => 'uid',
    'status' => 'status',
    'name' => 'name',
    'mail' => 'mail',
    'rid' => 'rid',
    'fid' => 'fid',
    'field_file_image_alt_text' => 'field_file_image_alt_text',
    'field_file_image_title_text' => 'field_file_image_title_text',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
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
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_alt_text' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_image_title_text' => array(
      'sortable' => 1,
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
  /* Beziehung: Dateiverwendung: Datei */
  $handler->display->display_options['relationships']['user_to_file']['id'] = 'user_to_file';
  $handler->display->display_options['relationships']['user_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['user_to_file']['field'] = 'user_to_file';
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: Aktiv */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'email';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['label'] = 'roles';
  $handler->display->display_options['fields']['rid']['separator'] = ',';
  /* Feld: MAX(Datei: Datei-ID) */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'user_to_file';
  $handler->display->display_options['fields']['fid']['group_type'] = 'max';
  $handler->display->display_options['fields']['fid']['label'] = 'picture';
  /* Feld: Datei: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'user_to_file';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'picture_alt';
  $handler->display->display_options['fields']['field_file_image_alt_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_alt_text']['group_column'] = 'entity_id';
  /* Feld: Datei: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'user_to_file';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'picture_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_file_image_title_text']['settings'] = array(
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
  $handler->display->display_options['fields']['field_file_image_title_text']['group_column'] = 'entity_id';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'first_name';
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
  $handler->display->display_options['fields']['field_user_fname']['group_column'] = 'entity_id';
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'last_name';
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
  $handler->display->display_options['fields']['field_user_lname']['group_column'] = 'entity_id';
  /* Sortierkriterien: Benutzer: Uid */
  $handler->display->display_options['sorts']['uid']['id'] = 'uid';
  $handler->display->display_options['sorts']['uid']['table'] = 'users';
  $handler->display->display_options['sorts']['uid']['field'] = 'uid';
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    181527986 => '181527986',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'export/user_politician.csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '500';
  $translatables['export_user_politician'] = array(
    t('Master'),
    t('export_user_politician'),
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
    t('Displaying @start - @end of @total'),
    t('Datei'),
    t('uuid'),
    t('uid'),
    t('Status'),
    t('username'),
    t('email'),
    t('roles'),
    t('picture'),
    t('picture_alt'),
    t('picture_title'),
    t('first_name'),
    t('last_name'),
    t('Data export'),
  );
  $export['export_user_politician'] = $view;

  $view = new view();
  $view->name = 'export_votes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'export_votes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'export_votes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'bypass node access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uuid' => 'uuid',
    'nid' => 'nid',
    'field_vote_node' => 'field_vote_node',
    'field_vote_user' => 'field_vote_user',
    'field_parliament' => 'field_parliament',
    'field_vote' => 'field_vote',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uuid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'field_vote_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_vote_user' => array(
      'sortable' => 0,
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
    'field_vote' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Feld: Inhalt: Inhalt UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'uuid';
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Feld: Inhalt: Abstimmung */
  $handler->display->display_options['fields']['field_vote_node']['id'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['field'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['label'] = 'poll';
  $handler->display->display_options['fields']['field_vote_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_vote_node']['settings'] = array(
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
  /* Feld: Inhalt: Politician Reference */
  $handler->display->display_options['fields']['field_vote_user']['id'] = 'field_vote_user';
  $handler->display->display_options['fields']['field_vote_user']['table'] = 'field_data_field_vote_user';
  $handler->display->display_options['fields']['field_vote_user']['field'] = 'field_vote_user';
  $handler->display->display_options['fields']['field_vote_user']['label'] = 'politician';
  $handler->display->display_options['fields']['field_vote_user']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_vote_user']['settings'] = array(
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
  $handler->display->display_options['fields']['field_parliament']['label'] = 'parliament_period';
  $handler->display->display_options['fields']['field_parliament']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_parliament']['alter']['text'] = '[field_parliament-tid]';
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
  /* Feld: Inhalt: Vote */
  $handler->display->display_options['fields']['field_vote']['id'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['table'] = 'field_data_field_vote';
  $handler->display->display_options['fields']['field_vote']['field'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['label'] = 'vote';
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
  /* Sortierkriterien: Inhalt: Beitrags-ID */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Filterkriterium: Inhalt: Abstimmung (field_vote_node) */
  $handler->display->display_options['filters']['field_vote_node_target_id']['id'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['field_vote_node_target_id']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['filters']['field_vote_node_target_id']['field'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['field_vote_node_target_id']['operator'] = 'not empty';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'export/votes.csv';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '500';
  $translatables['export_votes'] = array(
    t('Master'),
    t('export_votes'),
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
    t('uuid'),
    t('nid'),
    t('poll'),
    t('politician'),
    t('parliament_period'),
    t('[field_parliament-tid]'),
    t('vote'),
    t('Data export'),
  );
  $export['export_votes'] = $view;

  return $export;
}
