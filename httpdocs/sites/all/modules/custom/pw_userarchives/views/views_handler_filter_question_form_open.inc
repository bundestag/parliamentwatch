<?php

class views_handler_filter_question_form_open extends views_handler_filter_boolean_operator {
  public function get_value_options() {
    $this->value_options = array(1 => 'offen', 0 => 'geschlossen');
  }
}