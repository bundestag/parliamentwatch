<?php

class pw_administration_views_handler_area_create_new extends views_handler_area {

  protected $entityCreation = [
    'poll' => [
      'linktext' => 'Neue Abtimmung erstellen',
      'path' => 'node/add/poll'
    ],
    'committee' => [
      'linktext' => 'Neuen Ausschuss erstellen',
      'path' => 'node/add/committee'
    ]
  ];


  function option_definition() {
    $options = parent::option_definition();
    $options['entity_to_create'] = array('default' => '');
    return $options;
  }


  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['entity_to_create'] = array(
      '#type' => 'select',
      '#title' => t('Create new...'),
      '#options' => array(
        'poll' => t('Poll'),
        'committee' => t('Committee')
      ),
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
      $output = l($info_array['linktext'], $info_array['path'], $link_options);
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