<?php

class views_handler_filter_structured_data_status extends views_handler_filter_in_operator {
  public function get_value_options() {
    $this->value_options = \Drupal\pw_parliaments_admin\Status\StructuredDataStatus::getPossibleOptions();
  }
}