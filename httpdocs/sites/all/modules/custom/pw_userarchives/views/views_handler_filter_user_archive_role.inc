<?php

class views_handler_filter_user_archive_role extends views_handler_filter_in_operator {

  /**
   * {@inheritdoc}
   */
  public function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = 'Rolle';
      $types = pw_userarchives_politician_roles();
      $options = array();
      foreach ($types as $type => $label) {
        $options[$type] = $label;
      }
      asort($options);
      $this->value_options = $options;
    }
  }

}
