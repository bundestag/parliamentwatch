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


  /**
   * DialogueImportCheck constructor.
   *
   * @param \Drupal\pw_datatransfers\Modtool\DialogueImport $dialogue_import
   */
  public function __construct(DialogueImport $dialogue_import) {
    $this->dialogueImport = $dialogue_import;
  }


  /**
   * Check if the question is stored in Drupal
   *
   * @return bool
   * True if the question was sucessfully loaded, false if not
   */
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


  /**
   * Check if the answers given from Modtool are stored in Drupal. It returns
   * TRUE when no answers were defined in teh XML from Modtool
   *
   * @return bool
   * True if no answers were defined in XML from Modtool or if there are
   * answers and they have been sucessfully loaded from Drupal
   */
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