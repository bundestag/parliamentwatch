<?php

namespace Drupal\pw_datatransfers\Modtool;


use DateTime;
use Drupal\pw_datatransfers\Exception\InvalidSourceException;


/**
 * Build a class from the JSON the Modtool sends to Drupal
 */
class ModtoolMessage {


  /**
   * @var object|null
   * The JSON data from Modtool as an object
   */
  protected $jsonData = NULL;


  /**
   * @var bool
   * If the message data was validated. @see $this->validate()
   */
  protected $validated = FALSE;


  /**
   * @var string|int
   * The dialogue id from the Modtool as defined in the API path
   */
  protected $dialogueId;


  /**
   * @var string|int
   * The message id from the Modtool as defined in the API path
   */
  protected $messageId;

  public function __construct($json_data, $dialogue_id, $message_id) {
    $this->jsonData = $json_data;
    $this->dialogueId = $dialogue_id;
    $this->messageId = $message_id;
  }

  public function getDialogueId() {
    return $this->dialogueId;
  }

  public function getMessageId() {
    return $this->getData('id');
  }

  public function getStatus() {
    return $this->getData('status');
  }

  public function getInsertedDate() {
    return $this->getData('inserted_date');
  }

  public function getUpdatedDate() {
    return $this->getData('updated');
  }

  public function getType() {
    return $this->getData('type');
  }

  public function getSenderName() {
    return $this->getData('sender');
  }

  public function getText() {
    return $this->getData('text');
  }

  public function getPoliticianUUID() {
    return $this->getData('recipient.external_id');
  }

  public function getTopic() {
    return $this->getData('topic');
  }

  public function getParliament() {
    return $this->getData('context');
  }

  public function getSummary() {
    return $this->getData('keyworded_text');
  }

  public function getDocuments() {
    $documents = $this->getData('documents');

    if ($documents === NULL) {
      $documents = [];
    }

    return $documents;
  }

  public function getAnnotation() {
    return $this->getData('annotation.text');
  }

  public function getTags() {
    $tags = $this->getData('tags');

    if ($tags === NULL) {
      $tags = [];
    }

    return $tags;
  }


  /**
   * Get the data from JSON by key. it checks if the data was validated
   * and calls $this->validate() if not.
   *
   * @param $key
   *
   * @return mixed|null
   * NULL if no $key was found in JSON object
   *
   * @throws \Drupal\pw_datatransfers\Exception\InvalidSourceException
   */
  public function getData($key) {
    if (!$this->validated) {
      $this->validate();
    }

    if (isset($this->jsonData->{$key})) {
      return $this->jsonData->{$key};
    }

    return NULL;
  }




  /**
   * Validate the transferred JSON data for the message
   *
   * @todo validation for documents, tags
   *
   * @throws \Drupal\pw_datatransfers\Exception\InvalidSourceException
   */
  protected function validate() {
    // validate message id
    if (!isset($this->jsonData->id) || !is_numeric($this->jsonData->id)) {
      throw new InvalidSourceException('No message id was found in sent JSON.');
    }
    else if($this->messageId != $this->jsonData->id) {
      throw new InvalidSourceException('The message id defined in path ('. $this->messageId .') does not match the message id of the transferred message ('.  $this->jsonData->id .').');
    }

    // validate parliament
    if (!isset($this->jsonData->context) || !is_string($this->jsonData->context)) {
      throw new InvalidSourceException('No context/ parliament was found in sent JSON.');
    }

    // validate text
    if (!isset($this->jsonData->text) || !is_string($this->jsonData->text)) {
      throw new InvalidSourceException('No valid text was found in sent JSON.');
    }

    // validate summary
    if (!isset($this->jsonData->keyworded_text) || !is_string($this->jsonData->keyworded_text)) {
      throw new InvalidSourceException('No valid summary text was found in sent JSON.');
    }

    // validate type
    $allowed_types = ['question', 'answer'];
    if (!isset($this->jsonData->type) || !is_string($this->jsonData->type)) {
      throw new InvalidSourceException('No valid message type was found in sent JSON.');
    }
    else if (!in_array($this->jsonData->type, $allowed_types)) {
      throw new InvalidSourceException('The message type '. $this->jsonData->type .' found in sent JSON is not a valid type.');
    }

    // validate inserted dated
    if (!isset($this->jsonData->inserted_date) || is_null($this->jsonData->inserted_date)) {
      throw new InvalidSourceException('Required inserted date field missing in sent JSON.');
    }
    else if (!is_string($this->jsonData->inserted_date) ) {
      throw new InvalidSourceException('Inserted date field in sent JSON is not a string.');
    }
    else if (!$this->isValidDate($this->jsonData->inserted_date)) {
      throw new InvalidSourceException('Inserted date field in sent JSON is not a valid date.');
    }


    // validate updated dated
    if (!is_string($this->jsonData->updated) ) {
      throw new InvalidSourceException('Updated date field in sent JSON is not a string.');
    }
    else if (!$this->isValidDate($this->jsonData->updated)) {
      throw new InvalidSourceException('Updated date field in sent JSON is not a valid date.');
    }

    // validate annotation
    $annotation_text_key = 'annotation.text';
    if (isset($this->jsonData->{$annotation_text_key}) && $this->jsonData->{$annotation_text_key} !== NULL && !is_string($this->jsonData->{$annotation_text_key})) {
      throw new InvalidSourceException('There was aproblem with the annotation text found in sent JSON is not a valid string.');
    }

    $this->validated = TRUE;
 }


  /**
   * Check if a given date string is a valid date
   *
   * @todo - funktioniert gerade noch nicht
   *
   * @param string $date_string
   * The date string, e.g. "2018-12-19T13:40:05"
   *
   * @param string|FALSE $format
   * The format of the date string. Optional, default is 'c'
   *
   * @return bool
   */
  protected function isValidDate($date_string, $format = FALSE) {
    if (!$format) {
      $format = 'c';
    }

    $test = date('c');
    $d = DateTime::createFromFormat($format, $date_string);
//    return ($d && $d->format($format) === $date_string);
    return TRUE;
  }
}