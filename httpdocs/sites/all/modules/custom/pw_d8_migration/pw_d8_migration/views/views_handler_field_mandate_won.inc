<?php



class views_handler_field_mandate_won extends views_handler_field {
  public function query() {
  }


  public function render($values) {
    // load the user revision
    $user_revision = user_revision_load($values->user_archive_cache_uid, $values->vid);
    $constituency_won = $this->hasConstituencyWon($user_revision);
    $list_won = $this->hasListWon($user_revision);

    if ($constituency_won && $list_won) {
      return 'Wert für "Wahlkreis gewonnen" und "Liste gewonnen" gesetzt';
    }
    else if ($constituency_won) {
      return 'constituency';
    }
    else if ($list_won) {
      return 'list';
    }
    return NULL;
  }

  protected function hasListWon($user_revision) {
    if (isset($user_revision->field_user_list_won["und"][0]["value"])) {
      return $user_revision->field_user_list_won["und"][0]["value"];
    }
    else {
      return 0;
    }
  }

  protected function hasConstituencyWon($user_revision) {
    if (isset($user_revision->field_user_constituency_won["und"][0]["value"])) {
      return $user_revision->field_user_constituency_won["und"][0]["value"];
    }
    else {
      return 0;
    }
  }
}
