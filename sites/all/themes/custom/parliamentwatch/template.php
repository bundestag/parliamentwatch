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
 * Removes unnecessary core css files.
 */
function parliamentwatch_css_alter(&$css) {
  unset($css[drupal_get_path('module','system') . '/system.base.css']);
  unset($css[drupal_get_path('module','system') . '/system.menus.css']);
  unset($css[drupal_get_path('module','system') . '/system.theme.css']);
  unset($css[drupal_get_path('module','system') . '/system.messages.css']);
  unset($css[drupal_get_path('module','filter') . '/filter.css']);
  unset($css[drupal_get_path('module','comment') . '/comment.css']);
  unset($css[drupal_get_path('module','search') . '/search.css']);
  unset($css[drupal_get_path('module','node') . '/node.css']);
  unset($css[drupal_get_path('module','field') . '/theme/field.css']);
  unset($css[drupal_get_path('module','user') . '/user.css']);
}

/**
 * Implements hook_media_wysiwyg_token_to_markup().
 */
function parliamentwatch_media_wysiwyg_token_to_markup_alter(&$element, $tag_info, $settings) {
  unset($element['content']['#type']);
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
    $is_blog_or_petition_page = menu_get_object('node') ? in_array(menu_get_object('node')->type, ['blogpost', 'pw_petition']) : FALSE;
    $is_profile_page = in_array(menu_get_item()['page_callback'], ['user_view_page', 'user_revision_show']);

    if (!$has_container && !$has_filters && !$is_blog_or_petition_page && !$is_profile_page) {
      $page['content']['system_main']['#prefix'] = '<div class="container">';
      $page['content']['system_main']['#suffix'] = '</div>';
    }
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

    if ($config['menu_name'] == 'main-menu' && $config['level'] == 2) {
      $active_path = menu_tree_get_path('main-menu');

      if ($active_path) {
        $parliament_term = menu_get_item($active_path)['map'][1];
        $text = $parliament_term->name;
        $path = entity_uri('taxonomy_term', $parliament_term)['path'];
      }
      else {
        $trail = menu_get_active_trail();
        $text = $trail[1]['link_title'];
        $path = $trail[1]['link_path'];
      }

      $variables['title_suffix']['indicator'] = [
        '#markup' => l($text, $path, ['attributes' => ['class' => ['header__subnav__indicator']]])
      ];
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
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  $day = sprintf('<span class="date__day">%s</span>', format_date($node->created, 'custom', 'j'));
  $month = sprintf('<span class="date__month">%s</span>', format_date($node->created, 'custom', 'M'));
  $year = sprintf('<span class="date__year">%s</span>', format_date($node->created, 'custom', 'Y'));
  $variables['date'] = sprintf('<span class="date">%s%s%s</span>', $day, $month, $year);

  if (isset($variables['content']['field_teaser_image'])) {
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
      ['name' => 'Nicht abgestimmt', 'color' => '#a6a6a6', 'count' => $node->result['no-show']],
    ];
    $variables['yays'] = $node->result['yes'];
    $variables['nays'] = $node->result['no'];
  }

  if ($variables['type'] == 'pw_kc_position') {
    $account = user_load($node->field_pw_kc_user_reference[LANGUAGE_NONE][0]['target_id']);
    $variables['user_display_name'] = _pw_get_fullname($account);
    $variables['user_picture'] = field_view_field('user', $account, 'field_user_picture', ['label' => 'hidden', 'settings' => ['image_style' => 'media_thumbnail']]);
  }

  if ($variables['type'] == 'dialogue' && $variables['view_mode'] != 'embedded') {
    $account = pw_dialogues_recipient_user_revision($node);
    $variables['user_display_name'] = _pw_get_fullname($account);
    $variables['user_picture'] = field_view_field('user', $account, 'field_user_picture', ['label' => 'hidden', 'settings' => ['image_style' => 'media_thumbnail']]);
    $variables['user_party'] = field_view_field('user', $account, 'field_user_party', ['label' => 'hidden', 'type' => 'taxonomy_term_reference_plain']);
    $variables['user_url'] = url(entity_uri('user', $account)['path']);
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

  $gender = $account->field_user_gender[LANGUAGE_NONE][0]['value'];

  if (_pw_user_has_role($account, 'Candidate')) {
    $variables['role'] = t('Candidate', [], ['context' => $gender]);
  }
  elseif (_pw_user_has_role($account, 'Deputy')) {
    $variables['role'] = t('Deputy', [], ['context' => $gender]);
  }

  if (isset($variables['user_profile']['votes_total'])) {
    $variables['voting_ratio'] = round(100 * $variables['user_profile']['votes_attended'] / $variables['user_profile']['votes_total'], 0);
  }

  if (isset($variables['field_user_party']) && $variables['elements']['#view_mode'] == 'full') {
    $text = $variables['field_user_party'][0]['taxonomy_term']->name;
    if (_pw_user_has_role($account, 'Candidate')) {
      $path = 'profiles/' . $variables['field_user_parliament'][0]['tid'] . '/candidates';
    }
    elseif (_pw_user_has_role($account, 'Deputy')) {
      $path = 'profiles/' . $variables['field_user_parliament'][0]['tid'] . '/deputies';
    }
    $options = ['query' => ['party[]' => $variables['field_user_party'][0]['tid']]];
    $variables['user_profile']['field_user_party'][0]['#markup'] = l($text, $path, $options);
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

  if (isset($variables['field_user_list_position'])) {
    if ($variables['field_user_list_position'][0]['tid'] == 19706) {
      $variables['user_profile']['field_user_list_position'][0]['#markup'] = t('no information');
    }
  }

  if (isset($variables['field_user_picture'])) {
    $variables['user_profile']['field_user_picture_copyright'] = field_view_field('file', file_load($variables['field_user_picture'][0]['fid']), 'field_image_copyright', 'default');
  }
}

/**
 * Implements hook_preprocess_comment().
 */
function parliamentwatch_preprocess_comment(&$variables) {
  $elements = $variables['elements'];
  $variables['theme_hook_suggestions'][] = $variables['theme_hook_suggestion'];
  $variables['theme_hook_suggestions'][] = $variables['theme_hook_original'] . '__' . $elements['#view_mode'];
  unset($variables['theme_hook_suggestion']);

  if ($elements['#bundle'] == 'comment_node_dialogue' && $elements['#view_mode'] == 'tile') {
    $account = user_load($elements['#comment']->uid);
    $variables['user_picture'] = field_view_field('user', $account, 'field_user_picture', ['label' => 'hidden', 'settings' => ['image_style' => 'media_thumbnail']]);
  }
}

/**
 * Implements hook_preprocess_field().
 */
function parliamentwatch_preprocess_field(&$variables) {
  $element = $variables['element'];
  if($element['#bundle'] == 'pw_petition') {
    $variables['theme_hook_suggestions'][] = 'field__' . $element['#bundle'] . '__' . $element['#field_name'];
  }
  $variables['theme_hook_suggestions'][] = 'field__' . $element['#bundle'] . '__' . $element['#view_mode'];
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
    $out[] = $loc['postal_code'].' '.$locality;
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
function parliamentwatch_menu_tree__main_menu(&$variables) {
  return $variables['tree'];
}

/**
 * Overrides theme_menu_link() for main menu.
 */
function parliamentwatch_menu_link__main_menu(array $variables) {
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
function parliamentwatch_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<div class="nav-mobile-trigger"><i class="icon icon-investigation"></i></div>';
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
function parliamentwatch_disable_messages_status_messages($vars) {
  $messages = $vars['messages'];
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
 * Overrides theme_pager().
 */
function parliamentwatch_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  global $pager_total;

  $li_next = theme('pager_next', [
    'text' => (isset($tags[3]) ? $tags[3] : t('next ›')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ]);

  if ($pager_total[$element] > 1) {
    if ($li_next) {
      $items[] = ['class' => ['pager__next'], 'data' => $li_next];
    }

    return theme('item_list', [
      'items' => $items,
      'attributes' => ['class' => ['pager']],
    ]);
  }
}

/**
 * Overrides theme_item_list().
 */
function parliamentwatch_item_list(&$variables) {
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
function parliamentwatch_item_list__constituency_selection(&$variables) {
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
      $output .= '<a ' . drupal_attributes($attributes) . '" class="btn btn--small">' . t('Select constituency') . '</a>';
      $output .= "</div>\n";
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
  $element['#attributes']['type'] = 'text';
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
