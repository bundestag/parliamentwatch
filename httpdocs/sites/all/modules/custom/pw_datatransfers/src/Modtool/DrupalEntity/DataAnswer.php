<?php


namespace Drupal\pw_datatransfers\Modtool\DrupalEntity;


use stdClass;

class DataAnswer extends DataEntityBase {


  public function createDrupalEntity() {
    $modtoolMessage = $this->modtoolMessage;
    $answer = new stdClass();
    $answer->language = LANGUAGE_NONE;
    $answer->type = 'dialogue';
    $this->isNew = TRUE;
    $answer->title = 'Frage von ' . $modtoolMessage->getSenderName();
    node_object_prepare($answer);

    $answer->uid = 0;
    return $answer;
  }

  public function loadDrupalEntity() {
    $modtoolAnswer = $this->modtoolMessage;
    $question = NULL;

    if ($message_id = $modtoolAnswer->getMessageId()) {
      $question = load_answer_by_message_id($message_id);
    }

    return $question;
  }

  public function setDrupalEntityValuesFromJson($entity) {
    // TODO: Implement setDrupalEntityValuesFromJson() method.
  }
}