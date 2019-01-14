<?php

class views_handler_field_user_archive_role extends views_handler_field {
  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $value = $this->get_value($values);
    $roles = pw_userarchives_politician_roles();
    return $roles[$value];
  }
}