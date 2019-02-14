<?php

class views_handler_field_import_type extends views_handler_field {

  public function render($values) {
    $value = $this->get_value($values);
    return \Drupal\pw_parliaments_admin\Import\ImportTypes::getOptionLabel($value);
  }
}