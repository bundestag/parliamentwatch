<?php

/**
 * Views field handler for rendering an edit user revision link
 */

class views_handler_field_user_revision_link_edit extends views_handler_field_user_link {

  /**
   * Constructor for views handler revision edit link.
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['vid'] = 'vid';
  }

  /**
   * Access control for user revision edit.
   */
  public function access() {
    return user_access('edit user revisions');
  }

  /**
   * Creates a renderable link text for user revision edit.
   */
  public function render_link($data, $values) {
    if (!$this->access()) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $this->options['alter']['make_link'] = TRUE;

    $account = user_load($values->{$this->aliases['uid']});
    // check for the current revision
    if ($account->vid == $values->{$this->aliases['vid']}) {
      $path =  "user/" . $values->{$this->aliases['uid']} . "/edit";
    }
    else {
      $path = "user/" . $values->{$this->aliases['uid']} . "/revisions/" . $values->{$this->aliases['vid']} . "/edit";
    }

    $this->options['alter']['path'] = $path;
    $this->options['alter']['query'] = drupal_get_destination();

    return $text;
  }
}
