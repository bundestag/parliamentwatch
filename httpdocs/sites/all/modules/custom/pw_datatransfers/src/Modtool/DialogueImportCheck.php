<?php


namespace Drupal\pw_datatransfers\Modtool;

/**
 * Check if all data related to a dialogue is really stored
 * in Drupal
 */

class DialogueImportCheck {

  /**
   * @var \Drupal\pw_datatransfers\Modtool\DialogueImport
   */
  protected $dialogueImport;


  public function __construct(DialogueImport $dialogue_import) {
    $this->dialogueImport = $dialogue_import;
  }



  public function checkForQuestion() {
    $question_message_id = $this->dialogueImport->getMessageIdOfQuestion();

    if (is_numeric($question_message_id)) {
      $question_node = load_question_by_message_id($question_message_id);
      if ($question_node) {
        return TRUE;
      }
    }

    return FALSE;
  }

  public function checkForAnswer() {
    $answer_message_ids = $this->dialogueImport->getMessageIdsOfAnswers();

    // as no answers were added we simply return true
    if (empty($answer_message_ids)) {
      return TRUE;
    }
    else {
      foreach ($answer_message_ids as $message_id) {
        $answer = load_answer_by_message_id($message_id);
        // if one answer cannot be loaded directy return false
        if (!$answer) {
          return FALSE;
        }
      }

      // all answers set were succefully loaded as nodes
      return TRUE;
    }
  }
}