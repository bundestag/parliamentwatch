<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 20.12.2018
 * Time: 15:39
 */

namespace Drupal\pw_datatransfers\Modtool;


use DateTime;
use Drupal\pw_datatransfers\Exception\InvalidSourceException;

class ModtoolMessage {

  protected $jsonData = NULL;

  protected $validated = FALSE;

  protected $dialogueId = NULL;

  public function __construct($json_data, $dialogueId) {
    $this->jsonData = $json_data;
    $this->dialogueId = $dialogueId;
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



  public function getData($key) {
    if (!$this->validated) {
      $this->validate();
    }

    if (isset($this->jsonData->{$key})) {
      return $this->jsonData{$key};
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

    // validate parliament
    if (!isset($this->jsonData->context) || !is_string($this->jsonData->context)) {
      throw new InvalidSourceException('No context/ parliament was found in sent JSON.');
    }

    // validate text
    if (!isset($this->jsonData->text) || !is_string($this->jsonData->text)) {
      throw new InvalidSourceException('No valid text was found in sent JSON.');
    }

    // validate summary
    if (!isset($this->jsonData->keyword_text) || !is_string($this->jsonData->keyword_text)) {
      throw new InvalidSourceException('No valid summary text was found in sent JSON.');
    }

    // validate type
    $allowed_types = ['question', 'answer'];
    if (!isset($this->jsonData->type) || !is_string($this->jsonData->type)) {
      throw new InvalidSourceException('No valid message type was found in sent JSON.');
    }
    else if (!array_key_exists($this->jsonData->type, $allowed_types)) {
      throw new InvalidSourceException('The message type '. $this->jsonData->type .' found in sent JSON is not a valid type.');
    }

    // validate inserted dated
    if (!isset($this->jsonData->inserted_date) || (is_null($this->jsonData->inserted_date))) {
      throw new InvalidSourceException('Required inserted date field missing in sent JSON.');
    }
    else if (!is_string($this->jsonData->inserted_date) ) {
      throw new InvalidSourceException('Inserted date field in sent JSON is not a string.');
    }
    else if ($this->isValidDate($this->jsonData->inserted_date)) {
      throw new InvalidSourceException('Inserted date field in sent JSON is not a valid date.');
    }

    // validate annotation
    $annotation_text_key = 'annotation.text';
    if (isset($this->jsonData->{$annotation_text_key}) && $this->jsonData->{$annotation_text_key} !== NULL && !is_string($this->jsonData->{$annotation_text_key})) {
      throw new InvalidSourceException('There was aproblem with the annotation text found in sent JSON is not a valid string.');
    }
 }



  protected function isValidDate($date_string, $format = FALSE) {
    if (!$format) {
      $format = 'Y-m-dTG:i:s';
    }

    $d = DateTime::createFromFormat($format, $date_string);
    return ($d && $d->format($format) === $date_string);
  }
}