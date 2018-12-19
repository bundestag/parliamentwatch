<?php

/**
 * Implements hook_theme().
 */
function parliamentwatch_theme(&$existing, $type, $theme, $path) {
  return array(
    'filterbar' => [
      'render element' => 'form',
      'template' => 'templates/filterbar',
    ],
    'user_login' => [
      'render element' => 'form',
      'template' => 'templates/user-login'
    ],
    'user_pass' => [
      'render element' => 'form',
      'template' => 'templates/user-pass'
    ],
  );
}

/**
 * Implements hook_form_alter().
 */
function parliamentwatch_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['actions'])) {
    $form['actions']['#type'] = 'container';
    $form['actions']['#attributes'] = ['class' => ['form__item']];
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function parliamentwatch_form_user_login_alter(&$form, &$form_state) {
  $form['#theme'] = 'user_login';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function parliamentwatch_form_user_pass_alter(&$form, &$form_state) {
  $form['#theme'] = 'user_pass';
  $form['actions']['submit']['#value'] = t('Reset password');
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function parliamentwatch_form_comment_form_alter(&$form, &$form_state) {
  global $user;
  if ($user->uid) {
    $form['author']['_author']['#title'] = t('You are logged in as');
  }
  $form['actions']['submit']['#value'] = t('Add comment');
  $form['author']['homepage']['#access'] = FALSE;
}

/**
 * Implements hook_css_alter().
 *
 * Removes unnecessary core & contributed css files.
 */
function parliamentwatch_css_alter(&$css) {
  unset($css['misc/ui/jquery.ui.core.css']);
  unset($css['misc/ui/jquery.ui.theme.css']);
  unset($css[drupal_get_path('module','system') . '/system.base.css']);
  unset($css[drupal_get_path('module','system') . '/system.menus.css']);
  unset($css[drupal_get_path('module','system') . '/system.theme.css']);
  unset($css[drupal_get_path('module','system') . '/system.messages.css']);
  unset($css[drupal_get_path('module','comment') . '/comment.css']);
  unset($css[drupal_get_path('module','ckeditor') . '/css/ckeditor.css']);
  unset($css[drupal_get_path('module','ctools') . '/css/ctools.css']);
  unset($css[drupal_get_path('module','field') . '/theme/field.css']);
  unset($css[drupal_get_path('module','filter') . '/filter.css']);
  unset($css[drupal_get_path('module','media_wysiwyg') . '/css/media_wysiwyg.base.css']);
  unset($css[drupal_get_path('module','node') . '/node.css']);
  unset($css[drupal_get_path('module','jquery_update') . '/replace/ui/themes/base/minified/jquery.ui.core.css']);
  unset($css[drupal_get_path('module','jquery_update') . '/replace/ui/themes/base/minified/jquery.ui.theme.min.css']);
  unset($css[drupal_get_path('module','search') . '/search.css']);
  unset($css[drupal_get_path('module','tagadelic') . '/tagadelic.css']);
  unset($css[drupal_get_path('module','user') . '/user.css']);
  unset($css[drupal_get_path('module','views') . '/css/views.css']);
  unset($css[drupal_get_path('module','webform') . '/css/webform.css']);
  unset($css[drupal_get_path('module','webform_confirm_email') . '/webform_confirm_email.css']);
  unset($css[drupal_get_path('module','date') . '/date_popup/themes/datepicker.1.7.css']);
  unset($css[drupal_get_path('module','date_api') . '/date.css']);
}

/**
 * Implements hook_media_wysiwyg_token_to_markup().
 */
function parliamentwatch_media_wysiwyg_token_to_markup_alter(&$element, $tag_info, $settings) {
  $element['content']['#theme_wrappers'] = ['container__figure'];
  if (!empty($tag_info['fields']['alignment'])) {
    $element['content']['#attributes']['class'] = [drupal_html_class('figure-align--' . $tag_info['fields']['alignment'])];
  }
  else {
    unset($element['content']['#attributes']['class']);
  }
}

/**
 * Implements hook_page_alter().
 */
function parliamentwatch_page_alter(&$page) {
  if (isset($page['content']['system_main'])) {
    $filter = function ($item) {
      return strpos($item, 'container') === 0;
    };

    $has_container = !empty(array_filter($page['content']['system_main']['#theme_wrappers'], $filter));
    $has_filters = isset($page['content']['system_main']['filters']);
    $is_blog_or_petition_or_dialogue_page_or_poll_page_or_committee_page = menu_get_object('node') ? in_array(menu_get_object('node')->type, ['blogpost', 'dialogue', 'pw_petition', 'poll', 'committee']) : FALSE;
    $is_profile_page = in_array(menu_get_item()['page_callback'], ['user_view_page', 'user_revision_show']);
    $is_comment_reply_page = menu_get_item()['page_callback'] == 'comment_reply';
    $is_topic_page = menu_get_item()['page_callback'] == 'pw_globals_taxonomy_term_page';

    if (!$has_container && !$has_filters && !$is_blog_or_petition_or_dialogue_page_or_poll_page_or_committee_page && !$is_profile_page && !$is_comment_reply_page && !$is_topic_page) {
      $page['content']['system_main']['#prefix'] = '<div class="container">';
      $page['content']['system_main']['#suffix'] = '</div>';
    }

    if ($is_comment_reply_page) {
      $page['content']['system_main']['comment_form']['#prefix'] = '<div class="container">';
      $page['content']['system_main']['comment_form']['#suffix'] = '</div>';
    }
  }
}

/**
 * Implements hook_preprocess_page().
 */
function parliamentwatch_preprocess_page(&$variables) {
  if ($GLOBALS['theme_key'] == 'parliamentwatch') {
    drupal_add_library('system', 'jquery.cookie');
  }

  if (menu_get_item()['tab_root'] == 'user') {
    $variables['tabs']['#primary'] = '';
  }
}

/**
 * Implements hook_preprocess_region().
 */
function parliamentwatch_preprocess_region(&$variables) {
  if ($variables['region'] == 'content_tabs') {
    $elements = element_children($variables['elements']);
    foreach ($elements as $key) {
      $text = $variables['elements'][$key]['#block']->subject;
      $options = [
        'attributes' => ['class' => ['nav__item__link']],
        'external' => TRUE,
        'fragment' => drupal_html_class("block-$key"),
      ];
      $class = ['nav__item'];
      if ($key == reset($elements)) {
        $class[] = 'nav__item--active';
      }
      $variables['tabs'][] = [
        'data' => l($text, '', $options),
        'class' => $class,
      ];
    }
  }
}

/**
 * Implements hook_preprocess_block().
 */
function parliamentwatch_preprocess_block(&$variables) {
  $exclude_classes = [
    'block',
    drupal_html_class('block-' . $variables['block']->module),
    drupal_html_class('block-menu'),
  ];
  $variables['classes_array'] = array_diff($variables['classes_array'], $exclude_classes);

  if ($variables['block']->module == 'menu_block') {
    $config = $variables['elements']['#config'];
    $variables['theme_hook_suggestions'][] = strtr('block__' . $config['menu_name'] . '__level-' . $config['level'], '-', '_');

    if ($config['menu_name'] == 'main-menu' && $config['level'] == 3) {
      $trail = menu_get_active_trail();

      if (isset($trail[2]) && $trail[2]['menu_name'] == 'main-menu') {
        $parliament_term = menu_get_item($trail[2]['link_path'])['map'][2];
      }
      elseif (menu_tree_get_path('main-menu')) {
        $parliament_term = menu_get_item(menu_tree_get_path('main-menu'))['map'][1];
      }

      if (isset($parliament_term)) {
        $predecessors = pw_parliaments_predecessors($parliament_term);
        $successors = pw_parliaments_successors($parliament_term);

        $variables['title_suffix']['indicator'] = [
          '#theme' => 'item_list__archive_dropdown',
          '#items' => array_reverse(array_merge($predecessors, [$parliament_term], $successors, [$parliament_term])),
        ];
      }
    }
  }

  if ($variables['block']->region == 'content_tabs') {
    $variables['classes_array'][] = 'tabs__content';
    if ($variables['block_id'] == 1) {
      $variables['classes_array'][] = 'tabs__content--active';
    }
  }

  if ($variables['block']->module == 'pw_globals' && $variables['block']->delta == 'politician_search_form') {
    $parliament_term = menu_get_object('taxonomy_term', 2);

    if ($parliament_term) {
      $variables['icon_class'] = $parliament_term->field_icon_class[LANGUAGE_NONE][0]['value'];
    }
  }

  if ($variables['block']->module == 'pw_globals' && $variables['block']->delta == 'title') {
    $variables['classes_array'][] = 'title';

    if (menu_get_object('node')) {
      $variables['classes_array'][] = drupal_html_class('title--' . menu_get_object('node')->type);
    }

    if (menu_get_item()['path'] == 'dialogues/%/%/%') {
      $account = $variables['elements']['#account'];
      $parliament = $variables['elements']['#parliament'];
      $variables['parliament'] = $parliament->name;
      $variables['theme_hook_suggestions'][] = 'block__pw_globals__title__dialogues';
      $variables['user_party'] = pw_profiles_party($account)->name;
      $variables['user_picture'] = field_view_field('user', $account, 'field_user_picture', ['label' => 'hidden', 'settings' => ['image_style' => 'square_small']]);
      if (_pw_user_has_role($account, 'Candidate')) {
        $variables['user_role'] = t('Candidate', [], ['context' => pw_profiles_gender($account)]);
      }
      elseif (_pw_user_has_role($account, 'Deputy')) {
        $variables['user_role'] = t('Deputy', [], ['context' => pw_profiles_gender($account)]);
      }
      $variables['user_url'] = url(entity_uri('user', $account)['path']);
    }
  }

  if ($variables['block']->module == 'pw_dialogues' && $variables['block']->delta == 'recent') {
    $term = menu_get_object('taxonomy_term', 2);
    if ($term) {
      $today = new DateTime();
      $election_date = new DateTime($term->field_parliament_election[LANGUAGE_NONE][0]['value'], new DateTimeZone($term->field_parliament_election[LANGUAGE_NONE][0]['timezone']));
      if ($today < $election_date) {
        $variables['overview_url'] = url('dialogues/' . $term->tid . '/candidates');
      }
      else {
        $variables['overview_url'] = url('dialogues/' . $term->tid . '/deputies');
      }
    }
  }
}

/**
 * Implements hook_preprocess_block().
 */
function parliamentwatch_preprocess_menu_block_wrapper(&$variables) {
  $variables['classes_array'] = [
    'nav',
    'nav--' . $variables['config']['menu_name'],
    'nav--' . $variables['config']['menu_name'] . '--level-' . $variables['config']['level'],
  ];
}

/**
 * Implements hook_preprocess_node().
 */
function parliamentwatch_preprocess_node(&$variables) {
  $node = $variables['node'];

  $exclude_classes = [
    'node',
    'node-sticky',
    'node-promoted',
    drupal_html_class('node-' . $variables['type']),
  ];
  $variables['classes_array'] = array_diff($variables['classes_array'], $exclude_classes);
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  $day = sprintf('<span class="date__day">%s</span>', format_date($node->created, 'custom', 'j'));
  $month = sprintf('<span class="date__month">%s</span>', format_date($node->created, 'custom', 'M'));
  $year = sprintf('<span class="date__year">%s</span>', format_date($node->created, 'custom', 'Y'));
  $variables['date'] = sprintf('<span class="date">%s%s%s</span>', $day, $month, $year);

  if (isset($variables['field_teaser_image'][0]['fid'])) {
    $variables['content']['field_teaser_image_copyright'] = field_view_field('file', file_load($variables['field_teaser_image'][0]['fid']), 'field_image_copyright', 'default');
  }

  if ($variables['type'] == 'blogpost' && $variables['view_mode'] == 'full') {
    $variables['username'] = _pw_get_fullname(user_load($node->uid));
    $variables['date'] = format_date($node->created, 'short');
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['username'], '!datetime' => $variables['date']));
  }

  if ($variables['type'] == 'poll' && isset($node->result)) {
    $variables['result'] = [
      ['name' => 'Ja', 'color' => '#9fd773', 'count' => $node->result['yes']],
      ['name' => 'Nein', 'color' => '#cc6c5b', 'count' => $node->result['no']],
      ['name' => 'Enthalten', 'color' => '#e2e2e2', 'count' => $node->result['abstain']],
      ['name' => 'Nicht beteiligt', 'color' => '#a6a6a6', 'count' => $node->result['no-show']],
    ];
    $variables['yays'] = $node->result['yes'];
    $variables['nays'] = $node->result['no'];
    $variables['voterCount'] = $node->result['yes'] + $node->result['no'] + $node->result['abstain'] + $node->result['no-show'];
  }

  if ($variables['type'] == 'pw_kc_position') {
    $account = user_load($node->field_pw_kc_user_reference[LANGUAGE_NONE][0]['target_id']);
    $variables['user_display_name'] = _pw_get_fullname($account);
    $variables['user_picture'] = field_view_field('user', $account, 'field_user_picture', ['label' => 'hidden', 'settings' => ['image_style' => 'square_medium']]);
  }

  // for sidejobs on profile pages set the activity
  if ($variables['type'] == 'sidejob' && $variables['view_mode'] == 'embedded') {
    $node_entity_wrapper = entity_metadata_wrapper('node', $node);
    $variables['activity'] = drupal_render($variables["content"]["field_job"]);
    $job_category = $node_entity_wrapper->field_sidejob_job_category->value();

    // show value of field_sidejob_classification as activity when set to tid = 29231
    if (is_object($job_category) && isset($job_category->tid) && $job_category->tid == 29231) {
      $variables['activity'] = t('Financial share');
    }
  }
}

/**
 * Implements hook_preprocess_user_profile().
 */
function parliamentwatch_preprocess_user_profile(&$variables) {
  $account = $variables['elements']['#account'];

  $variables['theme_hook_suggestions'][] = 'user_profile__' . $variables['elements']['#view_mode'];
  $variables['user_url'] = url(entity_uri('user', $account)['path']);
  $variables['display_name'] = _pw_get_fullname($account);
  $variables['is_consultable'] = _pw_is_profile_consultable($account);

  if (isset($account->number_of_questions)) {
    $variables['questions'] = $account->number_of_questions;
    $variables['answers'] = $account->number_of_answers;
    if ($account->number_of_questions > 0) {
      $variables['answer_ratio'] = round(100 * $account->number_of_answers / $account->number_of_questions, 0);
    }
    else {
      $variables['answer_ratio'] = 0;
    }
  }

  $gender = '';
  if (isset($account->field_user_gender[LANGUAGE_NONE])) {
    $gender = $account->field_user_gender[LANGUAGE_NONE][0]['value'];
  }

  if (_pw_user_has_role($account, 'Candidate')) {
    $variables['role'] = t('Candidate', [], ['context' => $gender]);
  }
  elseif (_pw_user_has_role($account, 'Deputy')) {
    $variables['role'] = t('Deputy', [], ['context' => $gender]);
  }

  if (isset($variables['user_profile']['votes_total'])) {
    $variables['voting_ratio'] = round(100 * $variables['user_profile']['votes_attended'] / $variables['user_profile']['votes_total'], 0);
  }

  if (_pw_user_has_role($account, 'Candidate')) {
    $path = 'profiles/' . $variables['field_user_parliament'][0]['tid'] . '/candidates';
  }
  elseif (_pw_user_has_role($account, 'Deputy')) {
    $path = 'profiles/' . $variables['field_user_parliament'][0]['tid'] . '/deputies';
  }

  if ($variables['elements']['#view_mode'] == 'full' && isset($path)) {
    if (isset($variables['field_user_party'])) {
      $text = $variables['field_user_party'][0]['taxonomy_term']->name;
      $options = ['query' => ['party[]' => $variables['field_user_party'][0]['tid']]];

      $variables['user_profile']['field_user_party'][0]['#markup'] = l($text, $path, $options);
    }
    else {
      $variables['user_profile']['field_user_party'][0]['#markup'] = 'parteilos';
    }

  }

  if (isset($account->field_user_retired_reason) && !empty($account->field_user_retired_reason)) {
    $variables['field_user_retired_reason'] = $account->field_user_retired_reason["und"][0]["safe_value"];
  }

  if (isset($variables['field_user_constituency']) && $variables['elements']['#view_mode'] == 'full' && isset($path)) {
    $placeholders = [
      '@number' => $variables['field_user_constituency'][0]['taxonomy_term']->field_constituency_nr['und'][0]['value'],
      '@title' => $variables['user_profile']['field_user_constituency'][0]['#markup']
    ];
    if (strpos(pw_profiles_parliament($account)->name, 'Bayern') === 0) {
      $text = t('Constituency @number: @title', $placeholders, ['context' => 'Bayern']);
    }
    else {
      $text = t('Constituency @number: @title', $placeholders, ['context' => '']);
    }
    $options = ['query' => ['constituency' => $variables['field_user_constituency'][0]['tid']]];
    $variables['user_profile']['field_user_constituency'][0]['#markup'] = l($text, $path, $options);
  }

  if (isset($variables['field_user_list']) && $variables['elements']['#view_mode'] == 'full' && isset($path)) {
    $text = $variables['user_profile']['field_user_list'][0]['#markup'];
    $options = array('query' => array('list' => $variables['field_user_list'][0]['tid'], 'party['. $variables['field_user_party'][0]['tid'] .']' => $variables['field_user_party'][0]['tid']));

    $variables['user_profile']['field_user_list'][0]['#markup'] = l($text, $path, $options);
  }

  if (isset($variables['field_user_birthday'])) {
    $timezone = new DateTimeZone($variables['field_user_birthday'][0]['timezone']);
    $date = new DateTime($variables['field_user_birthday'][0]['value'], $timezone);

    $variables['field_user_birthday'][0]['iso_8601'] = $date->format(DateTime::ISO8601);
  }

  if (isset($variables['field_user_childs'])) {
    if ($variables['field_user_childs'][0]['value'] == 0) {
      $variables['user_profile']['field_user_childs'][0]['#markup'] = t('None');
    }
    elseif ($variables['field_user_childs'][0]['value'] == -1) {
      unset($variables['user_profile']['field_user_childs']);
    }
  }

  if (isset($variables['field_user_picture'])) {
    $variables['user_profile']['field_user_picture_copyright'] = field_view_field('file', file_load($variables['field_user_picture'][0]['fid']), 'field_image_copyright', 'default');
    $variables['user_profile']["field_user_picture"][0]["#item"]["alt"] = $variables['display_name'];
    $variables['user_profile']["field_user_picture"][0]["#item"]["title"] = $variables['display_name'];
  }
}

/**
 * Implements hook_preprocess_table().
 */
function parliamentwatch_preprocess_table(&$variables) {
  if ($variables['theme_hook_original'] == 'table__poll_votes') {
    $variables['attributes'] = ['class' => ['table', 'table--poll-votes', 'table--sortable']];
    drupal_add_js(path_to_theme() . '/js/contrib/jquery.dynatable.js');
  }
}

/**
 * Implements hook_preprocess_comment().
 */
function parliamentwatch_preprocess_comment(&$variables) {
  $elements = $variables['elements'];

  if (isset($variables['theme_hook_suggestion'])) {
    $variables['theme_hook_suggestions'][] = $variables['theme_hook_suggestion'];
    unset($variables['theme_hook_suggestion']);
  }

  $variables['theme_hook_suggestions'][] = $variables['theme_hook_original'] . '__' . $elements['#view_mode'];


  if ($elements['#bundle'] == 'comment_node_dialogue' && $elements['#view_mode'] != 'full') {
    $account = user_load($elements['#comment']->uid);
    $variables['user_display_name'] = _pw_get_fullname($account);
    $variables['user_party'] = field_view_field('user', $account, 'field_user_party', ['label' => 'hidden', 'type' => 'taxonomy_term_reference_plain']);
  }
  if ($elements['#bundle'] == 'comment_node_dialogue' && $elements['#view_mode'] == 'tile') {
    $account = user_load($elements['#comment']->uid);
    $variables['user_picture'] = field_view_field('user', $account, 'field_user_picture', ['label' => 'hidden', 'settings' => ['image_style' => 'square_small']]);
    $variables['user_url'] = url(entity_uri('user', $account)['path']);
  }
}

/**
 * Implements hook_preprocess_field().
 */
function parliamentwatch_preprocess_field(&$variables) {
  $element = $variables['element'];
  $variables['theme_hook_suggestions'][] = 'field__' . $element['#bundle'] . '__' . $element['#view_mode'];

  if ($element['#bundle'] == 'sidejob' && $element['#field_name'] == 'field_politician' && $element['#view_mode'] == 'teaser') {
    $variables['items'][0]['#label'] = t("@politician's sidejob", ['@politician' => _pw_get_fullname($element[0]['#item']['entity'])]);
    $variables['items'][0]['#uri']['options']['fragment'] = 'block-pw-sidejobs-profile';
  }

  if ($element['#field_name'] == 'field_topics' && $element['#formatter'] == 'taxonomy_term_reference_link') {
    foreach ($variables['items'] as &$item) {
      $item['#options']['attributes']['title'] = t('More contents on the topic “!name”', ['!name' => $item['#title']]);
    }
  }

  if ($element['#field_name'] == 'field_blogpost_categories' && $element['#formatter'] == 'taxonomy_term_reference_link') {
    foreach ($variables['items'] as &$item) {
      $item['#options']['attributes']['title'] = t('More blog articles from the category “!name”', ['!name' => $item['#title']]);
    }
  }

  if ($element['#field_name'] == 'field_dialogue_topic') {
    $parliament = pw_globals_parliament($element['#object']);
    $role_name = pw_dialogues_before_election($element['#object']) ? 'candidates' : 'deputies';
    foreach ($variables['items'] as &$item) {
      $item['#href'] = url("dialogues/$parliament->tid/$role_name");
      $item['#title'] = '# ' . $item['#title'];
      $item['#options']['query'] = ['topic' => [$item['#options']['entity']->tid]];
      $item['#options']['attributes']['title'] = t('More contents on the topic “!name”', ['!name' => $item['#title']]);
      $item['#options']['attributes']['class'][] = 'question__meta__tag';
      $item['#options']['attributes']['class'][] = 'tile__meta__tag';
    }
  }

}

/**
 * Overrides theme_addressfield_formatter__linear().
 */
function parliamentwatch_addressfield_formatter__linear($vars) {
  $loc = $vars['address'];

  // Determine which location components to render
  $out = array();
  if (!empty($loc['name_line']) && $vars['name_line']) {
    $out[] = $loc['name_line'];
  }
  if (!empty($loc['organisation_name']) && $vars['organisation_name']) {
    $out[] = $loc['organisation_name'];
  }
  if (!empty($loc['thoroughfare'])) {
    $out[] = $loc['thoroughfare'];
  }
  if (!empty($loc['premise']) && $vars['premise']) {
    $out[] = $loc['premise'];
  }
  if (!empty($loc['administrative_area'])) {
    $out[] = $loc['administrative_area'];
  }
  if (!empty($loc['locality'])) {
    $locality = $loc['locality'];
  }
  if (!empty($loc['postal_code'])) {
    $out[] = $loc['postal_code'] . ' ' . $locality;
  }
  if ($loc['country'] != addressfield_tokens_default_country() && $country_name = _addressfield_tokens_country($loc['country'])) {
    $out[] = $country_name;
  }

  // Render the location components
  $output = implode(', ', $out);

  return $output;
}

/**
 * Overrides theme_filter_tips_more_info().
 */
function parliamentwatch_filter_tips_more_info() {
  return '';
}

/**
 * Overrides theme_menu_tree() for main menu.
 */
function parliamentwatch_menu_tree__main_menu($variables) {
  return $variables['tree'];
}

/**
 * Overrides theme_menu_link() for main menu.
 */
function parliamentwatch_menu_link__main_menu($variables) {
  $element = $variables['element'];
  $sub_menu = '';
  $prefix = '';
  $suffix = '';

  $callback = function ($tid) {
    return "taxonomy/term/$tid";
  };
  $state_parliament_paths = array_map($callback, variable_get('parliamentwatch_state_parliament_tids', []));

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  if ($element['#href'] == reset($state_parliament_paths)) {
    $trail = menu_get_active_trail();
    if (isset($trail[1]['link_path']) && in_array($trail[1]['link_path'], $state_parliament_paths)) {
      $prefix .= '<li class="nav__item nav__item--active nav__item--dropdown dropdown--hover">';
    }
    else {
      $prefix .= '<li class="nav__item nav__item--dropdown dropdown dropdown--hover">';
    }
    $prefix .= '<a class="nav__item__link dropdown__text" href="#">Landtage</a>';
    $prefix .= '<a class="nav__item__trigger dropdown__trigger" href="#"><i class="icon icon-arrow-down"></i></a>';
    $prefix .= '<ul class="dropdown__list">';
  }
  elseif ($element['#href'] == end($state_parliament_paths)) {
    $suffix .= '</ul></li>';
  }

  if (in_array($element['#href'], $state_parliament_paths)) {
    $element['#attributes']['class'] = ['dropdown__list__item'];
    $element['#localized_options']['attributes']['class'][] = 'dropdown__list__item__link';
  }
  else {
    $element['#attributes']['class'] = ['nav__item'];
    $element['#localized_options']['attributes']['class'][] = 'nav__item__link';
    $element['#localized_options']['attributes']['class'][] = 'nav__item__link--' . drupal_html_class($element['#title']);

    if (in_array('active-trail', $element['#localized_options']['attributes']['class'])) {
      $element['#attributes']['class'][] = 'nav__item--active';
    }
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  return $prefix . '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>$suffix\n";
}

/**
 * Overrides theme_menu_local_tasks() for local task tab-navigation.
 */
function parliamentwatch_menu_local_tasks($variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="nav nav--tab primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="nav nav--tab secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}

/**
 * Overrides theme_disable_messages_status_messages() for local task tab-navigation.
 */
function parliamentwatch_disable_messages_status_messages($variables) {
  $messages = $variables['messages'];
  $output = '';
  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach ($messages as $type => $arr_messages) {
    $output .= "<div class='messages_container'><div class=\"messages messages--$type\">\n";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($arr_messages) > 1) {
      $output .= " <ul>\n";
      foreach ($arr_messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= array_shift($arr_messages);
    }
    $output .= "</div></div>\n";
  }
  return $output;
}

/**
 * Overrides theme_container().
 */
function parliamentwatch_container($variables) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += ['#attributes' => []];

  return '<div' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';
}

/**
 * Overrides theme_container() for tiles.
 */
function parliamentwatch_container__tiles($variables) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += ['#attributes' => []];
  $element['#attributes']['class'][] = 'tile-wrapper';

  if (isset($element['#modifier'])) {
    $element['#attributes']['class'][] = drupal_html_class('tile-wrapper--' . $element['#modifier']);
  }

  return '<div ' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';
}

/**
 * Overrides theme_container() for tiles.
 */
function parliamentwatch_container__small_tiles($variables) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += ['#attributes' => []];
  $element['#attributes']['class'] = ['container'];

  return '<div class="small-tiles">' . $element['#children'] . '</div>';
}

/**
 * Overrides theme_container() for teaser overview.
 */
function parliamentwatch_container__overview($variables) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += ['#attributes' => []];
  $element['#attributes']['class'][] = 'overview';

  if (isset($element['#modifier'])) {
    $element['#attributes']['class'][] = drupal_html_class('overview--' . $element['#modifier']);
  }

  return '<div ' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';
}

/**
 * Overrides theme_container() for timeline.
 */
function parliamentwatch_container__timeline($variables) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += ['#attributes' => []];
  $element['#attributes']['class'] = ['poll__timeline__item'];

  return '<div' . drupal_attributes($element['#attributes']) . '><div class="poll__timeline__item__date">' . $element['#date'] . '</div>' . $element['#children'] . '</div>';
}

/**
 * Overrides theme_container() for swiper.
 */
function parliamentwatch_container__swiper($variables) {
  $element = $variables['element'];

  $output = '<div class="swiper-container-wrapper">';
  $output .= '<div class="swiper-container swiper-container--tile">';
  $output .= '<div class="swiper-wrapper">' . $element['#children'] . '</div>';
  $output .= '<div class="swiper-button-prev"></div>';
  $output .= '<div class="swiper-button-next"></div>';
  $output .= '</div>';
  $output .= '</div>';

  return $output;
}

/**
 * Overrides theme_container() for figure.
 */
function parliamentwatch_container__figure($variables) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += ['#attributes' => []];

  return '<figure' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</figure>';
}

/**
 * Overrides theme_container() for filterbar.
 */
function parliamentwatch_container__filterbar($variables) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += ['#attributes' => []];
  $element['#attributes']['class'][] = 'filterbar';

  $output = '<div ' . drupal_attributes($element['#attributes']) . '>';
  $output .= '<div class="filterbar__inner">' . $element['#children'];
  $output .= '<ul class="filterbar__view_options">';
  $output .= '<li class="filterbar__view_options__item active">';
  $output .= '<a href="#" class="filterbar__view_options__item__link"><i class="icon icon-th"></i></a>';
  $output .= '</li></ul>';
  $output .= '</div></div>';
  $output .= '<div class="filterbar-placeholder"></div>';

  return $output;
}

/**
 * Overrides theme_pager().
 */
function parliamentwatch_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = 5;
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager__item pager__item--first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager__item pager__item--previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager__item pager__item--ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager__item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager__item pager__item--current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager__item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager__item pager__item--ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager__item pager__item--next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager__item pager__item--last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
        'items' => $items,
        'attributes' => array('class' => array('pager')),
      ));
  }
}

/**
 * Overrides theme_item_list().
 */
function parliamentwatch_item_list($variables) {
  $items = $variables['items'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  if (!empty($items)) {
    $output = "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  return $output;
}

/**
 * Overrides theme_item_list() for constituency selection.
 */
function parliamentwatch_item_list__constituency_selection($variables) {
  $items = $variables['items'];
  $attributes = $variables['attributes'];

  if (!empty($items)) {
    $output = '<div class="constituency-selection">';
    $output .= '<p>' . t('We have found multiple constituencies for the postal code you have entered. Please select one of the localities below:') . '</p>';
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      $output .= '<div class="tile constituency-selection__item">';
      $output .= '<div class="tile__title mh-item">' . $data . '</div>';
      $output .= '<a ' . drupal_attributes($attributes) . ' class="btn btn--small">' . t('Select constituency') . '</a>';
      $output .= "</div>\n";
    }
    $output .= '</div>';
  }
  return $output;
}

/**
 * Overrides theme_item_list() for archive dropdown.
 */
function parliamentwatch_item_list__archive_dropdown($variables) {
  $output = '';
  $items = $variables['items'];
  $pattern = '/(\w+) (\d{4}-\d{4})/';
  $replacement = '\1<span>\2</span>';

  if (!empty($items)) {
    $first = array_shift($items);

    $output = '<div class="header__subnav__archive dropdown dropdown--hover">';
    $output .= '<span>';
    $output .= '<span class="header__subnav__archive__indicator">' . preg_replace($pattern, $replacement, $first->name) . '</span>';
    $output .= '</span>';
    $output .= '<ul class="header__subnav__archive__list dropdown__list">';

    $link_options = ['html' => TRUE, 'attributes' => ['class' => ['header__subnav__archive__list__item__link']]];
    foreach ($items as $item) {
      if ($first->name == $item->name) {
        $output .= '<li class="header__subnav__archive__list__item header__subnav__archive__list__item--active">';
      }
      else {
        $output .= '<li class="header__subnav__archive__list__item">';
      }
      $output .= l($item->name, entity_uri('taxonomy_term', $item)['path'], $link_options);
      $output .= "</li>\n";

    }
    $output .= "</div>";
  }

  return $output;
}

/**
 * Overrides theme_item_list() for archive dropdown.
 */
function parliamentwatch_item_list__politician_dropdown($variables) {
  $output = '';
  $items = $variables['items'];

  if (!empty($items)) {
    $first = array_shift($items);

    $output = '<div class="dropdown dropdown--default dropdown--hover">';
    $output .= '<span>' . check_plain($first['title']) . '</span>';
    $output .= '<ul class="dropdown__list">';

    $link_options = ['html' => TRUE];
    foreach ($items as $item) {
      if ($first['title'] == $item['title']) {
        $output .= '<li class="active">';
      }
      else {
        $output .= '<li>';
      }
      $output .= l($item['title'], $item['path']);
      $output .= "</li>\n";

    }
    $output .= "</div>";
  }

  return $output;
}

/**
 * Overrides theme_form().
 */
function parliamentwatch_form($variables) {
  $element = $variables['element'];
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, ['method']);
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }
  $element['#attributes']['class'][] = 'form';
  $element['#attributes']['class'][] = 'form--' . $element['#id'];
  return '<form' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</form>';
}

/**
 * Overrides theme_webform_element().
 */
function parliamentwatch_webform_element($variables) {
  $element = &$variables['element'];
  $variables['#attributes']['class'] = array_diff($element['#wrapper_attributes']['class'], ['form-item']);
  return parliamentwatch_form_element($variables);
}

/**
 * Overrides theme_form_element().
 */
function parliamentwatch_form_element($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += ['#title_display' => 'before'];

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  if (isset($variables['#attributes']['class'])) {
    $attributes['class'] = $variables['#attributes']['class'];
  }
  $attributes['class'][] = 'form__item';
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form__item--' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form__item--' . strtr($element['#name'], [' ' => '-', '_' => '-', '[' => '-', ']' => '']);
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form__item--disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Overrides theme_form_element_label().
 */
function parliamentwatch_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = ['class' => ['form__item__label']];
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'][] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'][] = 'sr-only';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', ['!title' => $title, '!required' => $required]) . "</label>\n";
}

/**
 * Overrides theme_textfield().
 */
function parliamentwatch_textfield($variables) {
  $element = $variables['element'];
  if (!isset($element['#attributes']['type'])) {
    $element['#attributes']['type'] = 'text';
  }
  element_set_attributes($element, ['id', 'name', 'value', 'size', 'maxlength']);
  _parliamentwatch_form_set_class($element, ['form__item__control']);

  $extra = '';
  if ($element['#autocomplete_path'] && !empty($element['#autocomplete_input'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = [];
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#autocomplete_input']['#id'];
    $attributes['value'] = $element['#autocomplete_input']['#url_value'];
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}

/**
 * Overrides theme_password().
 */
function parliamentwatch_password($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, ['id', 'name', 'size', 'maxlength']);
  _form_set_class($element, ['form__item__control']);

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Overrides theme_textarea().
 */
function parliamentwatch_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, ['id', 'name', 'cols', 'rows']);
  _parliamentwatch_form_set_class($element, ['form__item__control']);

  return '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
}

/**
 * Overrides theme_select().
 */
function parliamentwatch_select($variables) {
  $element = $variables['element'];
  if (isset($element['#title'])) {
    $element['#attributes']['data-placeholder'] = $element['#title'];
  }
  element_set_attributes($element, ['id', 'name', 'size']);
  _parliamentwatch_form_set_class($element, ['form__item__control']);

  return '<select data-width="100%" ' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select>';
}

/**
 * Overrides theme_checkboxes().
 */
function parliamentwatch_checkboxes($variables) {
  return $variables['element']['#children'];
}

/**
 * Overrides theme_checkbox().
 */
function parliamentwatch_checkbox($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes($element, ['id', 'name', '#return_value' => 'value']);

  // Unchecked checkbox has #value of integer 0.
  if (!empty($element['#checked'])) {
    $element['#attributes']['checked'] = 'checked';
  }
  _parliamentwatch_form_set_class($element, ['form__item__control']);

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Overrides theme_radio().
 */
function parliamentwatch_radio($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'radio';
  element_set_attributes($element, array('id', 'name', '#return_value' => 'value'));

  if (isset($element['#return_value']) && $element['#value'] !== FALSE && $element['#value'] == $element['#return_value']) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, ['form__item__control']);

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Overrides theme_button().
 */
function parliamentwatch_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, ['id', 'name']);

  $element['#attributes']['class'] = ['btn'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'btn--disabled';
  }

  return '<button' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</button>';
}

/**
 * Overrides theme_profile_search_summary().
 */
function parliamentwatch_profile_search_summary($variables) {
  $output = '';
  $facets = $variables['response']['search_api_facets'];
  $link_options = [
    'attributes' => [
      'class' => ['filter-summary__content__link'],
      'data-ajax-target' => '#ajax',
    ],
  ];

  $options['@count'] = $variables['response']['result count'];
  $options['@class'] = implode(' ', $link_options['attributes']['class']);
  $options['@data-ajax-target'] = $link_options['attributes']['data-ajax-target'];

  if (!empty($variables['filters']['party'])) {
    $parties_count = count($variables['filters']['party']);
    $parties_text = format_plural($parties_count, '1 party', '@count parties');
    $options['!parties'] = l($parties_text, current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'party')]);
  }
  else {
    $parties_count = count(_pw_profiles_facet_values($facets['field_user_party']));
    $parties_text = format_plural($parties_count, '1 party', '@count parties');
    $options['!parties'] = "<span>$parties_text</span>";
  }

  if (strpos($variables['parliament']->name, 'Bayern') === 0) {
    $constituency_context = 'Bayern';
    $list_context = 'Bayern';
  }
  else {
    $constituency_context = '';
    $list_context = '';
  }

  if (!empty($variables['filters']['constituency'])) {
    $constituency = taxonomy_term_load((int) $variables['filters']['constituency']);
    $url = url(current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'constituency')]);
    $constituencies_text = t('<span>in</span> <a href="@url" class="filter-summary__content__link">constituency @name</a>', ['@name' => $constituency->name, '@url' => $url], ['context' => $constituency_context]);
    $options['!constituencies'] = $constituencies_text;
  }
  else {
    $facet_values = _pw_profiles_facet_values($facets['field_user_constituency']);
    $constituencies_count = count($facet_values);
    $constituencies = taxonomy_term_load_multiple($facet_values);
    $constituencies_text = format_plural($constituencies_count, 'in constituency @name', 'and @count constituencies', ['@name' => reset($constituencies)->name], ['context' => $constituency_context]);
    $options['!constituencies'] = "<span>$constituencies_text</span>";
  }

  $output .= '<div class="filter-summary">';
  $output .= '<div class="filter-summary__content">';

  if (empty($variables['filters']['gender'])) {
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1 candidate from</span> !parties !constituencies', '<span>Found @count candidates from</span> !parties !constituencies', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1 deputy from</span> !parties !constituencies', '<span>Found @count deputies from</span> !parties !constituencies', $options);
    }
  }
  elseif ($variables['filters']['gender'] == ['male' => 'male', 'female' => 'female']) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female or male</a> <span>candidate from </span> !parties !constituencies','<span>Found @count <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female and male</a> <span>candidates from </span> !parties !constituencies', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female or male</a> <span>deputy from </span> !parties !constituencies','<span>Found @count <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female and male</a> <span>deputies from </span> !parties !constituencies', $options);
    }
  }
  elseif (!empty($variables['filters']['gender']['male'])) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>candidate from</span> !parties !constituencies', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>candidates from</span> !parties !constituencies', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>deputy from</span> !parties !constituencies', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>deputies from</span> !parties !constituencies', $options);
    }
  }
  elseif (!empty($variables['filters']['gender']['female'])) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>candidate from </span> !parties !constituencies', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>candidates from </span> !parties !constituencies', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>deputy from </span> !parties !constituencies', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>deputies from </span> !parties !constituencies', $options);
    }
  }

  if ($variables['role_name'] == 'candidates') {
    $summary_mobile = format_plural($variables['response']['result count'], 'Found 1 candidate', 'Found @count candidates', $options);
  }
  else {
    $summary_mobile = format_plural($variables['response']['result count'], 'Found 1 deputy', 'Found @count deputies', $options);
  }

  if (!empty($variables['filters']['list'])) {
    $list = taxonomy_term_load($variables['filters']['list']);
  }

  if (!empty($variables['filters']['list_position'])) {
    $list_position = taxonomy_term_load($variables['filters']['list_position']);
  }

  if (isset($list) && isset($list_position)) {
    $list_link = l($list->name, current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'list')]);
    $position_text = t('list position @position', ['@position' => $list_position->name], ['context' => $list_context]);
    $position_link = l($position_text, current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'list_position')]);
    $summary .= t('<span> having </span>!position<span> of </span>!list', ['!position' => $position_link, '!list' => $list_link]);
  }
  elseif (isset($list)) {
    $list_link = l($list->name, current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'list')]);
    $summary .= t('<span> of </span>!list', ['!list' => $list_link], ['context' => $list_context]);
  }
  elseif (isset($list_position)) {
    $position_text = t('list position @position', ['@position' => $list_position->name], ['context' => $list_context]);
    $position_link = l($position_text, current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'list_position')]);
    $summary .= t('<span> having </span>!position', ['!position' => $position_link], ['context' => $list_context]);
  }

  if (!empty(array_filter($variables['filters']))) {
    $summary_mobile .= ', ' . t('filtered by:');
  }
  else {
    $summary_mobile .= '.';
  }

  $output .= '<p class="filter-summary__content--mobile">';
  $output .= $summary_mobile;
  $output .= '</p><p>';
  $output .= $summary;

  if (!empty($variables['filters']['keys'])) {
    $options['!keys'] = l(check_plain($variables['filters']['keys']), current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'keys')]);
    $output .= t('<span>, matching </span>!keys', $options);
  }

  $output .= '</p>';

  if (!empty(array_filter($variables['filters']))) {
    $options = $link_options;
    $options['html'] = TRUE;
    $options['attributes']['class'] = ['btn'];
    $output .= ' ' . l('<i class="icon icon-close"></i>' . t('Reset all filters'), current_path(), $options);
  }

  $output .= '</div>';
  $output .= '<p>' . t('<strong>Sorted by:</strong> number of answers') . '</p>';
  $output .= '</div>';

  return $output;
}

/**
 * Overrides theme_dialogue_search_summary().
 */
function parliamentwatch_dialogue_search_summary($variables) {
  $output = '';
  $link_options = [
    'attributes' => [
      'class' => ['filter-summary__content__link'],
      'data-ajax-target' => '#ajax',
    ],
  ];

  $options['@count'] = $variables['response']['result count'];
  $options['@class'] = implode(' ', $link_options['attributes']['class']);
  $options['@data-ajax-target'] = $link_options['attributes']['data-ajax-target'];

  $output .= '<div class="filter-summary">';
  $output .= '<div class="filter-summary__content">';

  $summary = format_plural($variables['response']['result count'], '<span>Found 1 question</span>', '<span>Found @count questions</span>', $options);
  $summary_mobile = format_plural($variables['response']['result count'], 'Found 1 question', 'Found @count questions', $options);

  if (!empty($variables['filters']['topic'])) {
    $topic_links = '';
    for ($i = 0; $i < count($variables['filters']['topic']); $i++) {
      if ($i > 0 && $i < count($variables['filters']['topic']) - 1) {
        $topic_links .= '<span>, </span>';
      }
      elseif ($i > 0 && $i == count($variables['filters']['topic']) - 1) {
        $topic_links .= t('<span> and </span>');
      }
      $value = array_values($variables['filters']['topic'])[$i];
      $topics_text = _pw_dialogues_options($variables['filters']['topic'])[$value];
      $topic_links .= l($topics_text, current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'topic', $value)]);
    }
    $summary .= t("<span> related to </span>!topic_links", ['!topic_links' => $topic_links]);
  }

  if (!empty($variables['filters']['date'])) {
    $date_url = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'date')]);
    $date_args = [
      '@class' => $options['@class'],
      '@data-ajax-target' => $options['@data-ajax-target'],
      '@start' => format_date(strtotime($variables['filters']['date'][0]), 'date_only_short'),
      '@end' => format_date(strtotime($variables['filters']['date'][1]), 'date_only_short'),
      '!url' => $date_url,
    ];
    $summary .= t('<span> between </span><a class="@class" data-ajax-target="@data-ajax-target" href="!url">@start and @end</a>', $date_args);
  }

  if (!empty($variables['filters']['has-reply'])) {
    $has_reply_url = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'has-reply')]);
    $has_reply_args = [
      '@class' => $options['@class'],
      '@data-ajax-target' => $options['@data-ajax-target'],
      '!url' => $has_reply_url
    ];
    $summary .= t('<span> having been </span><a class="@class" data-ajax-target="@data-ajax-target" href="!url">answered</a>', $has_reply_args);
  }

  if (!empty($variables['filters']['ignore-standard-replies'])) {
    $ignore_standard_replies_text = t('ignoring standard replies');
    $summary .= '<span> </span>' . l($ignore_standard_replies_text, current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'ignore-standard-replies')]);
  }

  if (!empty(array_filter($variables['filters']))) {
    $summary_mobile .= ', ' . t('filtered by:');
  }
  else {
    $summary_mobile .= '.';
  }

  $output .= '<p class="filter-summary__content--mobile">';
  $output .= $summary_mobile;
  $output .= '</p><p>';
  $output .= $summary;

  if (!empty($variables['filters']['keys'])) {
    $options['!keys'] = l(check_plain($variables['filters']['keys']), current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'keys')]);
    $output .= t('<span>, matching </span>!keys', $options);
  }

  $output .= '</p>';

  if (!empty(array_filter($variables['filters']))) {
    $options = $link_options;
    $options['html'] = TRUE;
    $options['attributes']['class'] = ['btn'];
    $output .= ' ' . l('<i class="icon icon-close"></i>' . t('Reset all filters'), current_path(), $options);
  }

  $output .= '</div>';
  $output .= '<p>' . t('<strong>Sorted by:</strong> date of question') . '</p>';
  $output .= '</div>';

  return $output;
}

/**
 * Override theme_tablesort_indicator()
 */
function parliamentwatch_tablesort_indicator($variables) {
  if ($variables['style'] == "asc") {
    return '<i class="icon icon-arrow-up"></i>';
  }
  else {
    return '<i class="icon icon-arrow-down"></i>';
  }
}

/**
 * Sets a form element's class attribute.
 *
 * Adds 'error' class as needed.
 *
 * @param array $element
 *   The form element.
 * @param array $name
 *   The class names to be added.
 */
function _parliamentwatch_form_set_class(array &$element, array $name) {
  $element['#attributes']['class'] = $name;
  // This function is invoked from form element theme functions, but the
  // rendered form element may not necessarily have been processed by
  // form_builder().
  if (isset($element['#parents']) && form_get_error($element) !== NULL && !empty($element['#validated'])) {
    $element['#attributes']['class'][] = 'form__item__control--invalid';
  }
  if (isset($element['#attributes']['data-autosuggest-url'])) {
    $element['#attributes']['class'][] = 'form__item__control--autosuggest';
  }
}

t('Candidate', [], ['context' => 'female']);
t('Candidate', [], ['context' => 'male']);
t('Deputy', [], ['context' => 'female']);
t('Deputy', [], ['context' => 'male']);
t('<span>in</span> <a href="@url" class="filter-summary__content__link">constituency @name</a>', [], ['context' => '']);
t('<span>in</span> <a href="@url" class="filter-summary__content__link">constituency @name</a>', [], ['context' => 'Bayern']);
format_plural(0, '1 constituency', '@count constituencies', [], ['context' => '']);
format_plural(0, '1 constituency', '@count constituencies', [], ['context' => 'Bayern']);
format_plural(0, 'in constituency @name', 'and @count constituencies', [], ['context' => '']);
format_plural(0, 'in constituency @name', 'and @count constituencies', [], ['context' => 'Bayern']);
