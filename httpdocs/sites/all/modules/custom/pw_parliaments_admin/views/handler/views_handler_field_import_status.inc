<?php

class views_handler_field_import_status extends views_handler_field {

  public function render($values) {
    $value = $this->get_value($values);
    return \Drupal\pw_parliaments_admin\Status\ImportStatus::getOptionLabel($value);
  }
}