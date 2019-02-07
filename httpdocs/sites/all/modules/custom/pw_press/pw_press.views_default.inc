<?php
/**
 * @file
 * pw_press.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_press_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'press_articles';
  $view->description = 'A list of articles about the project found in the press';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Press articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presseartikel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
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
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'pw-list-item clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Beziehung: Dateiverwendung: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Feld: Inhalt: Publisher */
  $handler->display->display_options['fields']['field_press_article_publisher']['id'] = 'field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['table'] = 'field_data_field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['field'] = 'field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['label'] = '';
  $handler->display->display_options['fields']['field_press_article_publisher']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_publisher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_publisher']['element_default_classes'] = FALSE;
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
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>[field_press_article_publisher]</h4>
<div class="medium">[title]</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'grid-4';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Gerenderter Inhalt */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'tile';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sortierkriterien: Inhalt: Date of publication (field_press_article_date) */
  $handler->display->display_options['sorts']['field_press_article_date_value']['id'] = 'field_press_article_date_value';
  $handler->display->display_options['sorts']['field_press_article_date_value']['table'] = 'field_data_field_press_article_date';
  $handler->display->display_options['sorts']['field_press_article_date_value']['field'] = 'field_press_article_date_value';
  $handler->display->display_options['sorts']['field_press_article_date_value']['order'] = 'DESC';
  /* Sortierkriterien: Inhalt: Veröffentlicht */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'node';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['sorts']['status']['order'] = 'DESC';
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_article' => 'press_article',
  );
  /* Filterkriterium: Global: Feld-Filter kombinieren */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Suchen';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_press_article_publisher' => 'field_press_article_publisher',
    'title' => 'title',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'ueber-uns/presse/pressespiegel';

  /* Display: Teaser */
  $handler = $view->new_display('block', 'Teaser', 'teaser');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Alle Artikel im Pressespiegel anzeigen';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'push-bottom-l';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Date of publication */
  $handler->display->display_options['fields']['field_press_article_date']['id'] = 'field_press_article_date';
  $handler->display->display_options['fields']['field_press_article_date']['table'] = 'field_data_field_press_article_date';
  $handler->display->display_options['fields']['field_press_article_date']['field'] = 'field_press_article_date';
  $handler->display->display_options['fields']['field_press_article_date']['label'] = '';
  $handler->display->display_options['fields']['field_press_article_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_date']['settings'] = array(
    'format_type' => 'date_only_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Publisher */
  $handler->display->display_options['fields']['field_press_article_publisher']['id'] = 'field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['table'] = 'field_data_field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['field'] = 'field_press_article_publisher';
  $handler->display->display_options['fields']['field_press_article_publisher']['label'] = '';
  $handler->display->display_options['fields']['field_press_article_publisher']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_publisher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_publisher']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_publisher']['type'] = 'text_plain';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>[field_press_article_publisher]</h4>
<div class="medium">[title]</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Datei: Pfad */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uri']['alter']['text'] = 'Video';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['uri']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Feld: Inhalt: Attachment */
  $handler->display->display_options['fields']['field_press_article_attachment']['id'] = 'field_press_article_attachment';
  $handler->display->display_options['fields']['field_press_article_attachment']['table'] = 'field_data_field_press_article_attachment';
  $handler->display->display_options['fields']['field_press_article_attachment']['field'] = 'field_press_article_attachment';
  $handler->display->display_options['fields']['field_press_article_attachment']['label'] = '';
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['text'] = 'pdf-Download';
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['path'] = '[uri]';
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['alt'] = 'pdf-Download';
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['link_class'] = 'link-download';
  $handler->display->display_options['fields']['field_press_article_attachment']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_press_article_attachment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_attachment']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_press_article_attachment']['element_wrapper_class'] = 'text-right download';
  $handler->display->display_options['fields']['field_press_article_attachment']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_attachment']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_article_attachment']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_press_article_attachment']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Feld: Inhalt: External link */
  $handler->display->display_options['fields']['field_press_article_link']['id'] = 'field_press_article_link';
  $handler->display->display_options['fields']['field_press_article_link']['table'] = 'field_data_field_press_article_link';
  $handler->display->display_options['fields']['field_press_article_link']['field'] = 'field_press_article_link';
  $handler->display->display_options['fields']['field_press_article_link']['label'] = '';
  $handler->display->display_options['fields']['field_press_article_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_link']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_press_article_link']['element_wrapper_class'] = 'text-right download';
  $handler->display->display_options['fields']['field_press_article_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_link']['click_sort_column'] = 'url';
  /* Feld: Inhalt: Soundfile */
  $handler->display->display_options['fields']['field_press_article_sound']['id'] = 'field_press_article_sound';
  $handler->display->display_options['fields']['field_press_article_sound']['table'] = 'field_data_field_press_article_sound';
  $handler->display->display_options['fields']['field_press_article_sound']['field'] = 'field_press_article_sound';
  $handler->display->display_options['fields']['field_press_article_sound']['label'] = '';
  $handler->display->display_options['fields']['field_press_article_sound']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_sound']['alter']['text'] = 'Sound';
  $handler->display->display_options['fields']['field_press_article_sound']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_sound']['alter']['path'] = '[uri]?width=500&height=500&iframe=true';
  $handler->display->display_options['fields']['field_press_article_sound']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_sound']['alter']['link_class'] = 'link-sound colorbox-load';
  $handler->display->display_options['fields']['field_press_article_sound']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_sound']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_press_article_sound']['element_wrapper_class'] = 'text-right download';
  $handler->display->display_options['fields']['field_press_article_sound']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_sound']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_article_sound']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Feld: Inhalt: Video */
  $handler->display->display_options['fields']['field_press_article_video']['id'] = 'field_press_article_video';
  $handler->display->display_options['fields']['field_press_article_video']['table'] = 'field_data_field_press_article_video';
  $handler->display->display_options['fields']['field_press_article_video']['field'] = 'field_press_article_video';
  $handler->display->display_options['fields']['field_press_article_video']['label'] = '';
  $handler->display->display_options['fields']['field_press_article_video']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_video']['alter']['text'] = 'Video';
  $handler->display->display_options['fields']['field_press_article_video']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_video']['alter']['path'] = '[uri]?&width=500&height=500&iframe=true';
  $handler->display->display_options['fields']['field_press_article_video']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_video']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_video']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_video']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_video']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_press_article_video']['alter']['link_class'] = 'link-video colorbox-load';
  $handler->display->display_options['fields']['field_press_article_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_video']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_press_article_video']['element_wrapper_class'] = 'text-right download';
  $handler->display->display_options['fields']['field_press_article_video']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_article_video']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_press_article_video']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_article_video']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit press article';
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'delete press article';
  /* Feld: Global: Kontextlinks */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_press_article_date' => 0,
    'field_press_article_publisher' => 0,
    'title' => 0,
    'uri' => 0,
    'field_press_article_attachment' => 0,
    'field_press_article_link' => 0,
    'field_press_article_video' => 0,
  );
  $translatables['press_articles'] = array(
    t('Master'),
    t('Presseartikel'),
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
    t('zurück'),
    t('weiter'),
    t('letzte Seite »'),
    t('Datei'),
    t('<h4>[field_press_article_publisher]</h4>
<div class="medium">[title]</div>'),
    t('Suchen'),
    t('Page'),
    t('Teaser'),
    t('Alle Artikel im Pressespiegel anzeigen'),
    t('Video'),
    t('pdf-Download'),
    t('Sound'),
    t('[title]'),
    t('edit press article'),
    t('delete press article'),
  );
  $export['press_articles'] = $view;

  $view = new view();
  $view->name = 'press_release';
  $view->description = 'A list of teasered press releases';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Press release';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pressemitteilungen';
  $handler->display->display_options['css_class'] = 'push-bottom-l';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Versatz';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'pw-list-item clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'pushfloat-2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['field_press_release_body']['id'] = 'field_press_release_body';
  $handler->display->display_options['fields']['field_press_release_body']['table'] = 'field_data_field_press_release_body';
  $handler->display->display_options['fields']['field_press_release_body']['field'] = 'field_press_release_body';
  $handler->display->display_options['fields']['field_press_release_body']['label'] = '';
  $handler->display->display_options['fields']['field_press_release_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_press_release_body']['alter']['max_length'] = '400';
  $handler->display->display_options['fields']['field_press_release_body']['alter']['more_link_text'] = 'weiterlesen';
  $handler->display->display_options['fields']['field_press_release_body']['alter']['more_link_path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_press_release_body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_press_release_body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_press_release_body']['alter']['preserve_tags'] = '<a>';
  $handler->display->display_options['fields']['field_press_release_body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_press_release_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_release_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_release_body']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Feld: Inhalt: Gerenderter Inhalt */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'tile';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sortierkriterien: Inhalt: Date (field_press_release_date) */
  $handler->display->display_options['sorts']['field_press_release_date_value']['id'] = 'field_press_release_date_value';
  $handler->display->display_options['sorts']['field_press_release_date_value']['table'] = 'field_data_field_press_release_date';
  $handler->display->display_options['sorts']['field_press_release_date_value']['field'] = 'field_press_release_date_value';
  $handler->display->display_options['sorts']['field_press_release_date_value']['order'] = 'DESC';
  /* Sortierkriterien: Inhalt: Beitragsdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_release' => 'press_release',
  );
  /* Filterkriterium: Global: Feld-Filter kombinieren */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Feld-Filter kombinieren';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_press_release_body' => 'field_press_release_body',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'about/press/press-releases';

  /* Display: Menu Block */
  $handler = $view->new_display('block', 'Menu Block', 'menu_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Neueste Pressemitteilungen';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'alle Pressemitteilungen';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'views-row-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_press_release_date']['id'] = 'field_press_release_date';
  $handler->display->display_options['fields']['field_press_release_date']['table'] = 'field_data_field_press_release_date';
  $handler->display->display_options['fields']['field_press_release_date']['field'] = 'field_press_release_date';
  $handler->display->display_options['fields']['field_press_release_date']['label'] = '';
  $handler->display->display_options['fields']['field_press_release_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_press_release_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_release_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_release_date']['settings'] = array(
    'format_type' => 'date_only_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'normal-weight medium';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;

  /* Display: Teaser */
  $handler = $view->new_display('block', 'Teaser', 'teaser');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Alle Pressemitteilungen anzeigen';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'push-bottom-l';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_press_release_date']['id'] = 'field_press_release_date';
  $handler->display->display_options['fields']['field_press_release_date']['table'] = 'field_data_field_press_release_date';
  $handler->display->display_options['fields']['field_press_release_date']['field'] = 'field_press_release_date';
  $handler->display->display_options['fields']['field_press_release_date']['label'] = '';
  $handler->display->display_options['fields']['field_press_release_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_press_release_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_release_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_press_release_date']['settings'] = array(
    'format_type' => 'date_only_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Feld: Inhalt: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'text-right read-more';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'weiterlesen';
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit press release';
  /* Feld: Inhalt: Link löschen */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'delete press release';
  /* Feld: Global: Kontextlinks */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_press_release_date' => 0,
    'title' => 0,
    'field_press_release_body' => 0,
    'view_node' => 0,
  );
  $translatables['press_release'] = array(
    t('Master'),
    t('Pressemitteilungen'),
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
    t('zurück'),
    t('weiter'),
    t('letzte Seite »'),
    t('weiterlesen'),
    t('Feld-Filter kombinieren'),
    t('Page'),
    t('Menu Block'),
    t('Neueste Pressemitteilungen'),
    t('alle Pressemitteilungen'),
    t('Teaser'),
    t('Alle Pressemitteilungen anzeigen'),
    t('edit press release'),
    t('delete press release'),
  );
  $export['press_release'] = $view;

  return $export;
}
