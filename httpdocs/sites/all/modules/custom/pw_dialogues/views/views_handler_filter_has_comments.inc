<?php

/**
* @file
* Views filter "has comments"
*/


class views_handler_filter_has_comments extends views_handler_filter_boolean_operator {

  function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";

    if (empty($this->value)) {
      if ($this->accept_null) {
        $or = db_or()
          ->condition($field, 0, '=')
          ->condition($field, NULL, 'IS NULL');
        $this->query->add_where($this->options['group'], $or);
      }
      else {
        $this->query->add_where($this->options['group'], $field, 0, '=');
      }
    }
    else {
      $this->query->add_where($this->options['group'], $field, 0, '<>');
    }
  }
}