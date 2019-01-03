<?php


namespace Drupal\pw_datatransfers\Modtool\DrupalEntity;


use DateTime;
use Drupal\pw_datatransfers\Exception\DatatransfersException;
use stdClass;

class DataAnswer extends DataEntityBase {

  /**
   * Create a new Drupal comment object for an answer
   *
   * @return object|\stdClass
   * A new Drupal comment object
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  public function createDrupalEntity() {
    $question = load_question_by_dialogue_id($this->modtoolMessage->getDialogueId());

    if ($question && isset($question->nid)) {
      $answer = new stdClass();
      $answer->nid = $question->nid;
      $answer->subject = 'Antwort von ' .$this->modtoolMessage->getSenderName();
      $answer->uid = 0;
      $this->isNew = TRUE;
      return $answer;
    }

    throw new DatatransfersException('It was not possible to load a question node for the answer');
  }


  /**
   * Load the Drupal comment object of the answer
   *
   * @return object|null
   */
  public function loadDrupalEntity() {
    $modtoolAnswer = $this->modtoolMessage;
    $comment = NULL;

    if ($message_id = $modtoolAnswer->getMessageId()) {
      $comment = load_answer_by_message_id($message_id);
    }

    return $comment;
  }


  /**
   * Update the comment by the values sent from Modtool. The values are received
   * from the ModtoolMessage class
   *
   * @param object $comment
   * Drupal comment object of the answer which should be updated. Can be a newly
   * created comment object with no values or a comment object of an existing answer.
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  public function setDrupalEntityValuesFromJson($comment) {
    $modtoolMessage = $this->modtoolMessage;
    $dialogue_id = $modtoolMessage->getDialogueId();


    $date_created = new DateTime($modtoolMessage->getInsertedDate());
    $comment->created = $date_created->format('U');

    $date_updated = new DateTime($modtoolMessage->getUpdatedDate());
    $comment->changed = $date_updated->format('U');


    // set the sender/ politician
    $politician_uuid = $modtoolMessage->getPoliticianUUID();
    $sender_uid = array_values(entity_get_id_by_uuid('user', [$politician_uuid]));
    if (empty($sender_uid)) {
      throw new DatatransfersException('No user account found for the sender of the answer.');
    }
    $comment->uid = $sender_uid;

    $comment->field_dialogue_comment_body = [LANGUAGE_NONE => [0 => [
      'value' => htmlspecialchars(json_decode($modtoolMessage->getText())),
      'summary' => htmlspecialchars(json_decode($modtoolMessage->getSummary())),
      'format' => 'managed_content',
    ]]];

    $comment->field_dialogue_id = [LANGUAGE_NONE => [0 => [
      'value' => $dialogue_id,
    ]]];

    $comment->field_dialogue_message_id = [LANGUAGE_NONE => [0 => [
      'value' => $modtoolMessage->getMessageId(),
    ]]];

    $comment->field_dialogue_message_type = [LANGUAGE_NONE => [0 => [
      'value' => $modtoolMessage->getType(),
    ]]];

    $comment->field_dialogue_sender_fullname = [LANGUAGE_NONE => [0 => [
      'value' => $modtoolMessage->getData('sender'),
    ]]];

    // @todo - documents import implementieren
    $comment->field_dialogue_documents[LANGUAGE_NONE] = [];
//    foreach ($modtoolMessage->getDocuments() as $item) {
//      $comment->field_dialogue_documents[LANGUAGE_NONE][] = ['url' => trim($item->textContent)];
//    }

    // @todo - tags import implementieren
    $comment->field_dialogue_tags[LANGUAGE_NONE] = [];
//    foreach ($modtoolMessage->getTags() as $item) {
//      $term = array_values(taxonomy_get_term_by_name(trim($item->textContent), 'dialogue_tags'));
//      if (!empty($term)) {
//        $comment->field_dialogue_tags[LANGUAGE_NONE][] = ['tid' => $term[0]->tid];
//      }
//    };

    $annotation = $modtoolMessage->getAnnotation();
    if (!empty($annotation)) {
      $comment->field_dialogue_annotation = [LANGUAGE_NONE => [0 => [
        'value' => $annotation,
      ]]];
    }


    //@todo - check if topics should really be set for comments separated
//    $topic = array_values(taxonomy_get_term_by_name($xpath->evaluate('string(topic)', $answer_from_modtool), 'dialogue_topics'));
//    if (!empty($topic)) {
//      $comment->field_dialogue_topic = [LANGUAGE_NONE => [0 => [
//        'tid' => $topic[0]->tid,
//      ]]];
//    }
  }
}