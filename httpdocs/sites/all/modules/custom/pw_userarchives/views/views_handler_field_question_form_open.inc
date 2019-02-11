<?php

class views_handler_field_question_form_open extends views_handler_field_boolean {

  public function render($values) {
    $value = $values->{$this->field_alias};
    return $value ? 'offen' : 'geschlossen';
  }
}