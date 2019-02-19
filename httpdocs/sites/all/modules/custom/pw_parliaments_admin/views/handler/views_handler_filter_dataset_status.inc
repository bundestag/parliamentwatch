<?php

class views_handler_filter_dataset_status extends views_handler_filter_in_operator {
  public function get_value_options() {
    $this->value_options = \Drupal\pw_parliaments_admin\Status\DataSetStatus::getPossibleOptions();
  }
}