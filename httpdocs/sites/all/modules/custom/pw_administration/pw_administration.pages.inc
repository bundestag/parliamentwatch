<?php

use Drupal\pw_administration\Controller\Zeugnisnoten;

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
  $date_question = FALSE;
  $date_question_kulanz = FALSE;
  $date_answer = FALSE;
  $date_answer_kulanz = FALSE;
  $bundesland = FALSE;
  $output_checks = 0;
  $output_kulanz = 0;

  $form = drupal_get_form('pw_administration_zeugnisnoten_form');
  $output .= render($form);

  $query_params = drupal_get_query_parameters();

  if (isset($query_params["parliament"]) && is_numeric($query_params["parliament"])) {
    $parliament = $query_params["parliament"];
  }

  if (isset($query_params["date_question"]) && !empty($query_params["date_question"])) {
    $date_question = Zeugnisnoten::turnDateArrayToTimestamp($query_params["date_question"]);
  }

  if (isset($query_params["date_question_kulanz"]) && !empty($query_params["date_question_kulanz"])) {
    $date_question_kulanz = Zeugnisnoten::turnDateArrayToTimestamp($query_params["date_question_kulanz"]);
  }

  if (isset($query_params["date_answer"]) && !empty($query_params["date_answer"])) {
    $date_answer = Zeugnisnoten::turnDateArrayToTimestamp($query_params["date_answer"]);
  }

  if (isset($query_params["date_answer_kulanz"]) && !empty($query_params["date_answer_kulanz"])) {
    $date_answer_kulanz = Zeugnisnoten::turnDateArrayToTimestamp($query_params["date_answer_kulanz"]);
  }

  if (isset($query_params["bundesland"]) && is_string($query_params["bundesland"])) {
    $bundesland = $query_params["bundesland"];
  }

  if (isset($query_params["output_checks"]) && is_string($query_params["output_checks"])) {
    $output_checks = $query_params["output_checks"];
  }

  if (isset($query_params["output_kulanz"]) && is_string($query_params["output_kulanz"])) {
    $output_kulanz = $query_params["output_kulanz"];
  }
  $controller = new Zeugnisnoten($parliament, $date_question, $date_question_kulanz, $date_answer, $date_answer_kulanz, $bundesland, $output_checks, $output_kulanz);
  $output .= $controller->build();

  return $output;
}


function pw_administration_zeugnisnoten_form($form, &$form_state) {
  $form = [];

  $format = 'd.m.Y H:i';

  $default_question_date = Zeugnisnoten::getDefaultQuestionTime();
  $default_question_date_kulanz = Zeugnisnoten::getDefaultQuestionKulanzTime();
  $default_answer_date = Zeugnisnoten::getDefaultAnswerTime();
  $default_answer_date_kulanz = Zeugnisnoten::getDefaultAnswerKulanzTime();
  $form['#method'] = 'get';
  $query_params = drupal_get_query_parameters();

  $default_form_value_parliament = 26909;
  if (isset($form_state["input"]['parliament'])) {
    $default_form_value_parliament = $form_state["input"]['parliament'];
  }
  else if (isset($query_params['parliament'])) {
    $default_form_value_parliament = $query_params['parliament'];
  }

  $form['parliament'] = [
    '#type' => 'select',
    '#title' => 'Parlament',
    '#multiple' => FALSE,
    '#required' => TRUE,
    '#options' => taxonomy_allowed_values(field_info_field('field_parliament')),
    '#default_value' => $default_form_value_parliament,
    '#prefix' => '<div class="aw_adminform__item">',
    '#suffix' => '</div>'
  ];

  $field_bundesland = field_info_field('field_bundesland');
  $allowed_values = list_allowed_values($field_bundesland);
  $default_form_value_bundesland = NULL;
  if (isset($form_state["input"]['bundesland'])) {
    $default_form_value_bundesland = $form_state["input"]['bundesland'];
  }
  else if (isset($query_params['bundesland'])) {
    $default_form_value_bundesland = $query_params['bundesland'];
  }

  // add "all" option to Bundesland
  $allowed_values = array('all' => 'Alle') + $allowed_values;
  $form['bundesland'] = [
    '#type' => 'select',
    '#title' => 'Bundesland',
    '#options' => $allowed_values,
    '#default_value' => $default_form_value_bundesland,
    '#prefix' => '<div class="aw_adminform__item">',
    '#suffix' => '</div>'
  ];

  $default_form_value_output_checks = 0;
  if (isset($form_state["input"]['output_checks'])) {
    $default_form_value_output_checks = $form_state["input"]['output_checks'];
  }
  else if (isset($query_params['output_checks'])) {
    $default_form_value_output_checks = $query_params['output_checks'];
  }
  $form['output_checks'] = [
    '#type' => 'checkbox',
    '#title' => 'Ausgabe mit internen Checks',
    '#default_value' => $default_form_value_output_checks,
    '#return_value' => 1,
    '#prefix' => '<div class="aw_adminform__item">',
    '#suffix' => '</div>'
  ];

  $default_form_value_output_kulanz = 0;
  if (isset($form_state["input"]['output_kulanz'])) {
    $default_form_value_output_kulanz = $form_state["input"]['output_kulanz'];
  }
  else if (isset($query_params['output_kulanz'])) {
    $default_form_value_output_kulanz = $query_params['output_kulanz'];
  }
  $form['output_kulanz'] = [
    '#type' => 'checkbox',
    '#title' => 'Ausgabe mit Kulanz',
    '#default_value' => $default_form_value_output_kulanz,
    '#return_value' => 1,
    '#prefix' => '<div class="aw_adminform__item">',
    '#suffix' => '</div><div class="flexbox-linebreak"></div>',
    '#states' => [
      'visible' => ['#edit-output-checks' => ['checked' => TRUE]]
    ]
  ];

  $default_form_value_date_question = $default_question_date;
  if (isset($form_state["input"]['date_question'])) {
    $default_form_value_date_question = $form_state["input"]['date_question'];
  }
  else if (isset($query_params['date_question']) && !empty($query_params["date_question"])) {
    $default_form_value_date_question = $query_params["date_question"];
  }
  $form['date_question'] = [
    '#type' => 'date_select',
    '#title' => 'Stichtag Fragen',
    '#date_format' => $format,
    '#default_value' => $default_form_value_date_question,
    '#prefix' => '<div class="aw_adminform__item date-element date_question">',
    '#suffix' => '</div>',
  ];


  $default_form_value_date_question_kulanz = $default_question_date_kulanz;
  if (isset($form_state["input"]['date_question_kulanz'])) {
    $default_form_value_date_question_kulanz = $form_state["input"]['date_question_kulanz'];
  }
  else if (isset($query_params['date_question_kulanz']) && !empty($query_params["date_question_kulanz"])) {
    $default_form_value_date_question_kulanz = $query_params['date_question_kulanz'];
  }
  $form['date_question_kulanz'] = [
    '#type' => 'date_select',
    '#title' => 'Stichtag Fragen Kulanz',
    '#date_format' => $format,
    '#default_value' =>  $default_form_value_date_question_kulanz,
    '#prefix' => '<div class="aw_adminform__item date-element date_question_kulanz">',
    '#suffix' => '</div>',
  ];

  $default_form_value_date_answer = $default_answer_date;
  if (isset($form_state["input"]['date_answer'])) {
    $default_form_value_date_answer = $form_state["input"]['date_answer'];
  }
  else if (isset($query_params['date_answer']) && !empty($query_params["date_answer"])) {
    $default_form_value_date_answer = $query_params["date_answer"];
  }
  $form['date_answer'] = [
    '#type' => 'date_select',
    '#title' => 'Stichtag Antworten',
    '#date_format' => $format,
    '#default_value' =>  $default_form_value_date_answer,
    '#prefix' => '<div class="aw_adminform__item date-element date_answer">',
    '#suffix' => '</div>'
  ];


  $default_form_value_date_answer_kulanz =$default_answer_date_kulanz;
  if (isset($form_state["input"]['date_answer_kulanz'])) {
    $default_form_value_date_answer_kulanz = $form_state["input"]['date_answer_kulanz'];
  }
  else if (isset($query_params['date_answer_kulanz']) && !empty($query_params["date_answer_kulanz"])) {
    $default_form_value_date_answer_kulanz = $query_params["date_answer_kulanz"];
  }
  $form['date_answer_kulanz'] = [
    '#type' => 'date_select',
    '#title' => 'Stichtag Antworten Kulanz',
    '#date_format' => $format,
    '#default_value' =>  $default_form_value_date_answer_kulanz,
    '#prefix' => '<div class="aw_adminform__item date-element date_answer_kulanz">',
    '#suffix' => '</div><div class="flexbox-linebreak"></div>'
  ];



  $form['action'] = [
    '#type' => 'actions'
  ];

  $form['action']['submit'] = [
    '#type' => 'submit',
    '#value' => 'Absenden'
  ];

  $form['#attributes'] = [
    'class' => 'aw_adminform'
  ];

  return $form;
}

