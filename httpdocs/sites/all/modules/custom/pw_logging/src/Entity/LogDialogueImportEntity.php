<?php


namespace Drupal\pw_datatransfers\Entity;


use Entity;

/**
 *
 */
class LogDialogueImportEntity extends Entity {

  protected $comment_cids = NULL;

  protected $dialogue_nids = NULL;

  protected $question_message_ids = NULL;

  protected $answer_message_ids = NULL;

  /**
   * Constructor as a helper to the parent constructor.
   *
   * @param array $values
   * @param string $entity_type
   *
   * @throws \Exception
   */
  public function __construct(array $values = array(), $entity_type = 'dialogue_import_log') {
    parent::__construct($values, $entity_type);

    if (isset($values['comment_cids'])) {
      $this->comment_cids = $values['comment_cids'];
    }

    if (isset($values['dialogue_nids'])) {
      $this->comment_cids = $values['dialogue_nids'];
    }

    if (isset($values['question_message_ids'])) {
      $this->comment_cids = $values['question_message_ids'];
    }

    if (isset($values['answer_message_ids'])) {
      $this->comment_cids = $values['answer_message_ids'];
    }
  }


  public function addCommentCid($cid) {
    $this->comment_cids[] = $cid;
  }


  public function addDialogueNid($nid) {
    $this->dialogue_nids = $nid;
  }

  public function addMessageIdQuestion($message_id) {
    $this->question_message_ids = $message_id;
  }

  public function addMessageIdAnswer($message_id) {
    $this->answer_message_ids = $message_id;
  }

  public function getCommentCids() {
    if (is_array($this->comment_cids)) {
      return $this->comment_cids;
    }
     return array();
  }

  public function getDialogueNids() {
    if (is_array($this->dialogue_nids)) {
      return $this->dialogue_nids;
    }
    return array();
  }

  public function getQuestionMessageIds() {
    if (is_array($this->question_message_ids)) {
      return $this->question_message_ids;
    }
    return array();
  }

  public function getAnswerMessageIds() {
    if (is_array($this->answer_message_ids)) {
      return $this->answer_message_ids;
    }
    return array();
  }
}