<?php


namespace Drupal\pw_datatransfers\Entity;

use Drupal\pw_datatransfers\Modtool\DialogueImport;
use Drupal\pw_datatransfers\Modtool\DialogueImportCheck;

/**
 * Helper for creating a log entry for a dialogue import
 */
class LogDialogueImportCreator {

  /**
   * @var string
   * Can be "failed" or "success"
   */
  protected $status;


  /**
   * @var null|\Exception
   * The exception which might be thrown
   */
  protected $exception = NULL;

  /**
   * @var null| DialogueImport
   * The DialogueImport class used for the import
   */
  protected $dialogueImport = NULL;


  /**
   * @var null| DialogueImportCheck
   * The DialogueImportCheck used to check if everything worked out well
   */
  protected $dialogueImportCheck = NULL;



  public function __construct($status) {
    $this->status = $status;
  }

  public function log() {
    $logentry_values =  [
      'message' =>  $this->createMessage(),
      'dialogue_id' => $this->getDialogueId(),
      'exception' => $this->getException(),
      'dialogue_nid' => $this->getDrupalQuestionNodeNid(),
      'comment_cid' => $this->getDrupalCommentCid()
    ];
  }


  /**
   * @param \Exception $exception
   */
  public function setException(\Exception $exception) {
    $this->exception = $exception;
  }


  /**
   * @param \Drupal\pw_datatransfers\Modtool\DialogueImport $dialogue_import
   */
  public function setDialogueImport(DialogueImport $dialogue_import) {
    $this->dialogueImport = $dialogue_import;
  }


  /**
   * @param \Drupal\pw_datatransfers\Modtool\DialogueImportCheck $dialogueImportCheck
   */
  public function setDialogueImportCheck(DialogueImportCheck $dialogueImportCheck) {
    $this->dialogueImportCheck = $dialogueImportCheck;
  }



  /**
   * Create the message.
   *
   * @return string
   */
  protected function createMessage() {
    if ($this->status == 'success') {
      return t('Import was sucessfull');
    }
    else {
      if ($this->exception !== NULL) {
        return $this->exception->getMessage();
      }
      else {
        return t('An unknown problem occured');
      }
    }
  }


  protected function getDialogueId() {
    if ($this->dialogueImport != NULL) {
      return $this->dialogueImport->getDialogueId();
    }
    return NULL;
  }

  protected function getDrupalQuestionNodeNid() {
    if ($this->dialogueImport != NULL ) {
      $question_node = $this->dialogueImport->getSavedQuestionNode();
      if ($question_node != NULL && isset ($question_node->nid)) {
        return $question_node->nid;
      }
    }
    return NULL;
  }

  protected function getDrupalCommentCid() {

  }

  protected function getException() {
    return $this->exception;
  }
}