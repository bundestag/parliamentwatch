<?php

/**
 * @file
 * Page callback for the PW Administration module
 */


function pw_administration_dashboard_pagecallback() {
  $output = 'Hier kommen demnächst hilfreiche Übersichten - z.B. die zuletzt importierten Fragen/ Antworten/ Nebenjobs u.ä.';


  return $output;
}


function pw_administration_wahlenparlamente_pagecallback() {
  $output = 'Hier kommen demnächst hilfreiche Übersichten - z.B. aktuelle Wahlprojekte, noch zu recherchierende Kandidaten u.ä.';


  return $output;
}


function pw_administration_zeugnisnoten_pagecallback() {
  $output = '';
  $parliament = FALSE;
  $date_questions = FALSE;
  $date_answers = FALSE;
  $bundesland = FALSE;

  $form = drupal_get_form('pw_administration_zeugnisnoten_form');
  $output .= render($form);

  $query_params = drupal_get_query_parameters();

  if (isset($query_params["parliament"]) && is_numeric($query_params["parliament"])) {
    $parliament = $query_params["parliament"];
  }

  if (isset($query_params["date_question"]) && isset($query_params["date_question"]["date"])) {
    $date_questions = $query_params["date_question"]["date"];
  }

  if (isset($query_params["date_answer"]) && isset($query_params["date_answer"]["date"])) {
    $date_answers = $query_params["date_answer"]["date"];
  }

  if (isset($query_params["bundesland"]) && is_string($query_params["bundesland"])) {
    $bundesland = $query_params["bundesland"];
  }

  $controller = new \Drupal\pw_administration\Controller\Zeugnisnoten($parliament, $date_questions, $date_answers, $bundesland);
  $output .= $controller->build();

  return $output;
}


function pw_administration_zeugnisnoten_form($form, &$form_state) {
  $form = [];

  $format = 'd.m.Y';
  $date_now = time();
  $default_question_date = $date_now - (14 * 24 * 60 * 60); // 14 days
  $default_answer_date = $date_now;
  $form['#method'] = 'get';
  $form['parliament'] = [
    '#type' => 'select',
    '#title' => 'Parlament',
    '#multiple' => FALSE,
    '#required' => TRUE,
    '#options' => taxonomy_allowed_values(field_info_field('field_parliament')),
    '#default_value' => isset($form_state["input"]['parliament']) ? $form_state["input"]['parliament'] : 26909
  ];

  $form['date_question'] = [
    '#type' => 'date_text',
    '#title' => 'Datum, bis zu dem die Fragen eingegangen sein sollen',
    '#date_format' => $format,
    '#default_value' => isset($form_state["input"]['date_question']) ? $form_state["input"]['date_question'] : date('Y-m-d', $default_question_date)
  ];

  $form['date_answer'] = [
    '#type' => 'date_text',
    '#title' => 'Datum, bis zu dem die Antworten eingegangen sein sollen',
    '#date_format' => $format,
    '#default_value' => isset($form_state["input"]['date_answer']) ? $form_state["input"]['date_answer'] : date('Y-m-d', $default_answer_date)
  ];

  $field_bundesland = field_info_field('field_bundesland');
  $allowed_values = list_allowed_values($field_bundesland);
  $form['bundesland'] = [
    '#type' => 'select',
    '#title' => 'Bundesland',
    '#options' => $allowed_values,
    '#default_value' => isset($form_state["input"]['bundesland']) ? $form_state["input"]['bundesland'] : NULL
  ];

  $form['action'] = [
    '#type' => 'action'
  ];

  $form['action']['submit'] = [
    '#type' => 'submit',
    '#value' => 'Absenden'
  ];

  return $form;
}

function pw_administration_zeugnisnoten_form_submit($form, &$form_state) {
  drupal_set_message('submitted');
}
