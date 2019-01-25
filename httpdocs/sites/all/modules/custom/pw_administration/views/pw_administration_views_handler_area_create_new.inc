<?php

class pw_administration_views_handler_area_create_new extends views_handler_area {

  protected $entityCreation = [
    'poll' => [
      'options_label' => 'Poll',
      'linktext' => 'Neue Abtimmung erstellen',
      'path' => 'node/add/poll'
    ],
    'committee' => [
      'options_label' => 'Committee',
      'linktext' => 'Neuen Ausschuss erstellen',
      'path' => 'node/add/committee'
    ],
    'parliament' => [
      'options_label' => 'Parliament',
      'linktext' => 'Neues Parlament erstellen',
      'path' => 'admin/structure/taxonomy/parliaments/add'
    ],
    'party' => [
      'options_label' => 'Party',
      'linktext' => 'Neue Partei erstellen',
      'path' => 'admin/structure/taxonomy/party/add'
    ],
    'sidejob' => [
      'options_label' => 'Nebentätigkeit',
      'linktext' => 'Neue Nebentätigkeit erstellen',
      'path' => 'node/add/sidejob'
    ]
  ];


  function option_definition() {
    $options = parent::option_definition();
    $options['entity_to_create'] = array('default' => '');
    return $options;
  }


  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = [];
    foreach ($this->entityCreation as $key => $entity_creation_information) {
      $options[$key] = t($entity_creation_information['options_label']);
    }

    $form['entity_to_create'] = array(
      '#type' => 'select',
      '#title' => t('Create new...'),
      '#options' => $options,
      '#default_value' => isset($this->options['entity_to_create']) ? $this->options['entity_to_create'] : '',
    );
  }


  /**
   * Render the area.
   */
  public function render($empty = FALSE) {
    $entity_to_create = $this->options['entity_to_create'];
    $output = '';

    if (isset($this->entityCreation[$entity_to_create])) {
      $info_array = $this->entityCreation[$entity_to_create];
      $link_options = $this->getLinkOptions();
      $output = '<ul class="action-links"><li>'. l($info_array['linktext'], $info_array['path'], $link_options) .'</li></ul>';
    }
    return $output;
  }


  protected function getLinkOptions() {
    $link_options = [];
    $entity_to_create = $this->options['entity_to_create'];

    // add parliament to add poll link
    if ($entity_to_create == 'poll' && $this->view->name == 'pw_administration_polls_by_parliament') {
      $link_options['query'] = ['edit[field_parliament][und]' => $this->view->args[0]];
    }

    // add parliament to add committee link
    if ($entity_to_create == 'committee' && $this->view->name == 'pw_administration_committees_by_parliament') {
      $link_options['query'] = ['edit[field_parliament][und]' => $this->view->args[0]];
    }

    return $link_options;
  }
}