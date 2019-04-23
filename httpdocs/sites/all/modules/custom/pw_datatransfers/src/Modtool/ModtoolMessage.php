<?php

namespace Drupal\pw_datatransfers\Modtool;

use DateTime;
use Drupal\pw_datatransfers\Exception\InvalidSourceException;


/**
 *
 * This class represents the Modtool message as it is sent to Drupal.
 *
 *
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


  /**
   * ModtoolMessage constructor.
   *
   * @param object $json_data
   * Decoded JSON data sent from Modtool to Drupal
   *
   * @param string|int $dialogue_id
   * The dialogue id from Modtool
   *
   * @param string|int $message_id
   * The message id of the message within the Modtool
   */
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

  public function getIsStandardAnswer() {
    return $this->getData('isStandard');
  }

  /**
   * Get the politician UUID depending on the type of message
   *
   * @return string|null
   * The UUID of the politician in Drupal
   *
   * @throws \Drupal\pw_datatransfers\Exception\InvalidSourceException
   */
  public function getPoliticianUUID() {
    switch ($this->getType()) {
      case 'question':
        return $this->getData('recipient_external_id');
      case 'answer':
        return $this->getData('sender_external_id');
    }
    return NULL;
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
    return $this->getData('annotation_text');
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
   * @todo - for answers: check if sender uuid is set
   * @todo - sender and recipient id checken
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

    // validate type
    $allowed_types = ['question', 'answer'];
    if (!isset($this->jsonData->type) || !is_string($this->jsonData->type)) {
      throw new InvalidSourceException('No valid message type was found in sent JSON.');
    }
    else if (!in_array($this->jsonData->type, $allowed_types)) {
      throw new InvalidSourceException('The message type '. $this->jsonData->type .' found in sent JSON is not a valid type.');
    }

    // validate isStandard
    // - for answers it needs to be set and it needs to have a boolean value
    if (!isset($this->jsonData->isStandard) && $this->jsonData->type == 'answer') {
      throw new InvalidSourceException('No isStandard field was found in sent JSON.');
    }
    else if (isset($this->jsonData->isStandard)  && $this->jsonData->type == 'answer' && !is_bool($this->jsonData->isStandard) ) {
      throw new InvalidSourceException('No valid isStandard field value was found in sent JSON.');
    }

    // validate inserted dated
    if (!isset($this->jsonData->inserted_date) || is_null($this->jsonData->inserted_date)) {
      throw new InvalidSourceException('Required inserted date field missing in sent JSON.');
    }
    else if (!is_string($this->jsonData->inserted_date) ) {
      throw new InvalidSourceException('Inserted date field in sent JSON is not a string.');
    }
    else if (!$this->isValidDate($this->jsonData->inserted_date)) {
      throw new InvalidSourceException('Inserted date field value '. $this->jsonData->inserted_date .' in sent JSON is not a valid date.');
    }


    // validate updated dated
    if (!is_string($this->jsonData->updated) ) {
      throw new InvalidSourceException('Updated date field in sent JSON is not a string.');
    }
    else if (!$this->isValidDate($this->jsonData->updated)) {
      throw new InvalidSourceException('Updated date field value '. $this->jsonData->inserted_date .' in sent JSON is not a valid date.');
    }

    // validate annotation
    if (isset($this->jsonData->annotation_text) && $this->jsonData->annotation_text !== NULL && !is_string($this->jsonData->annotation_text)) {
      throw new InvalidSourceException('The annotation text found in sent JSON is not a valid string.');
    }

    // validate documents
    if (isset($this->jsonData->documents) && !empty($this->jsonData->documents)) {
      $info = field_info_instance('node', 'field_dialogue_attachments', 'dialogue');
      $allowed_extensions = explode(' ', $info["settings"]["file_extensions"]);

      foreach ($this->jsonData->documents as $document_url) {
        $file_pathinfo = pathinfo($document_url);

        // check for allowed file extensions
        if (!in_array($file_pathinfo['extension'], $allowed_extensions)) {
          throw new InvalidSourceException('The file '. $document_url .' has not an allowed file extension. Allowed are the following extensions: '. implode(', ',$allowed_extensions));
        }
        $file_temp = $this->loadDocument($document_url);
        if (!$file_temp) {
          throw new InvalidSourceException('It was not possible to load the file '. $document_url);
        }
      }
    }

    // validate topic
    // for questions topic is required
    if ($this->jsonData->type == 'question' && !isset($this->jsonData->topic) || empty($this->jsonData->topic) || !is_string($this->jsonData->topic) ) {
      throw new InvalidSourceException('No valid topic was found in sent JSON. Either it is not set, it is empty or it is not a string.');
    }

    // when a topic is set validate that it exists in Drupal
    if (isset($this->jsonData->topic) && is_string($this->jsonData->topic)) {
      $topic_result = array_values(taxonomy_get_term_by_name($this->jsonData->topic, 'dialogue_topics'));
      if (!$topic_result) {
        throw new InvalidSourceException('The topic '. $this->jsonData->topic .' found in sent JSON is not a term of dialogue topics in Drupal.');
      }
    }

    $this->validated = TRUE;
 }


  /**
   * Check if a given date string is a valid date
   *
   *
   * @param string $date_string
   * The date string, e.g. "2018-12-19T13:40:05+01:00"
   *
   * @param string|FALSE $format
   * The format of the date string. Optional, default is 'c' or 'Y-m-d\TH:i:sP'
   *
   * @return bool
   */
  protected function isValidDate($date_string, $format = FALSE) {
    if (!$format) {
      $format = 'Y-m-d\TH:i:sP';
    }

    $d = DateTime::createFromFormat($format, $date_string);
    return ($d && $d->format($format) === $date_string);
  }


  /**
   * Load the document/ attachment file of a message from Modtool server
   *
   * @param string $document_url
   *
   * @return false|string
   */
  public function loadDocument($document_url) {
    $opts = array('http' =>
      array(
        'header' => "Authorization: Basic ". variable_get('modtool_api_credentials', FALSE)
      )
    );
    $context  = stream_context_create($opts);
    return file_get_contents(pw_globals_helper_file($document_url), FALSE, $context);
  }
}
