<?php

/**
 * Views field handler for creating a link to the public profile of a politician
 */


class views_handler_field_user_archive_profile_link extends views_handler_field_user_link {

  public function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['vid'] = 'vid';
  }

  /**
   * Access control for user revision view.
   */
  public function access() {
    // here we check if the revision has an entry in user archive
    return user_access('view user revisions');
  }

  /**
   * Creates a renderable link text for user revision edit.
   */
  public function render_link($data, $values) {
    if (!$this->access() || $values->{$this->aliases['vid']} == NULL || $values->{$this->aliases['uid']} == NULL) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $this->options['alter']['make_link'] = TRUE;

    $account = $values->_field_data["vid"]["entity"];
    if ($account->vid == $values->{$this->aliases['vid']}) {
      $path =  "user/" . $values->{$this->aliases['uid']};
    }
    else {
      $path = "user/" . $values->{$this->aliases['uid']} . "/revisions/" . $values->{$this->aliases['vid']} . "/view";
    }

    $this->options['alter']['path'] = $path;
    $this->options['alter']['query'] = drupal_get_destination();

    return $text;
  }
}