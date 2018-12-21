<?php


namespace Drupal\pw_datatransfers\Controller;


use Drupal\pw_datatransfers\Exception\DatatransfersException;
use Drupal\pw_datatransfers\Exception\SourceNotFoundException;
use Drupal\pw_datatransfers\Modtool\Actions\DataQuestionActionRelease;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataAnswer;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataEntityBase;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;

/**
 * Helper class for better control over the Modtool import dialogue page callback
 */
class ModtoolActionsController {

  protected $responseArray = [];

  protected $dialogueId = NULL;

  protected $messageType = NULL;

  protected $messageId = NULL;

  protected $action = NULL;


  /**
   * ModtoolActionsController constructor.
   *
   * We build the response array here. Do not add any other keys later in code
   * without adding the new key here. use $this->setResponseValue() to set a value
   *
   * @param $dialogue_id
   * @param $message_type
   * @param $message_id
   * @param $action
   */
  public function __construct($dialogue_id, $message_type, $message_id, $action) {
    $this->dialogueId = $dialogue_id;
    $this->messageType = $message_type;
    $this->messageId = $message_id;
    $this->action = $action;

    $this->responseArray = [
      'status' => NULL,
      'status_text' => NULL,
      'dialogue_id' => $dialogue_id,
      'message_type' => $message_type,
      'message_id' => $message_id,
      'action' => $action,
      'drupal_question_id' => NULL,
      'drupal_answer_id' => NULL
    ];
  }


  /**
   * Start the controller
   *
   * @return array
   * The reponse array
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  public function start() {
    try {
      $actionClass = NULL;
      $this->authentication();
      $this->httpChecks();

      $actionClass = $this->getActionClass();
      $actionClass->run();
    }
    catch (\Exception $e) {
      watchdog_exception('pw_dialogues', $e);
      $status_header = drupal_get_http_header('status');
      if (!$status_header) {
        drupal_add_http_header('Status', '500 Internal Server Error');
      }
      $this->setStatus('error', $e->getMessage());
      return $this->responseArray;
    }


    // set the success response
    $dataEntity = $actionClass->getDataEntity();
    switch ($this->messageType) {
      case 'question':
        $this->successQuestion($dataEntity);
        break;
      case 'answer':
        $this->successAnswer($dataEntity);
        break;
    }

    return $this->responseArray;
  }


  /**
   * For better control for the response we do the authentication here
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  protected function authentication() {
    if (!empty($_SERVER['REDIRECT_HTTP_AUTHORIZATION'])) {
      $credentials = base64_decode(substr($_SERVER['REDIRECT_HTTP_AUTHORIZATION'], 6));
      list($_SERVER['PHP_AUTH_USER'], $_SERVER['PHP_AUTH_PW']) = explode(':', $credentials, 2);
    }

    if (!isset($_SERVER['PHP_AUTH_USER']) || !isset($_SERVER['PHP_AUTH_PW'])) {
      drupal_add_http_header('Status', '401 Unauthorized');
      throw new DatatransfersException('401 Unauthorized - credentials not found');
    }

    $uid = user_authenticate($_SERVER['PHP_AUTH_USER'], $_SERVER['PHP_AUTH_PW']);

    if (!$uid) {
      drupal_add_http_header('Status', '401 Unauthorized');
      throw new DatatransfersException('401 Unauthorized - no user found for sent credentials');
    }

    $account = user_load($uid);

    if (!in_array(user_role_load_by_name('API User')->rid, array_keys($account->roles))) {
      drupal_add_http_header('Status', '403 Forbidden');
      throw new DatatransfersException('403 Forbidden - user has no permission');
    }
  }



  /**
   * Here we check if POST was used as method and if the content type was
   * set to application/x-www-form-urlencoded
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  protected function httpChecks() {
    if ($_SERVER['REQUEST_METHOD'] != 'POST') {
      drupal_add_http_header('Status', '405 Method Not Allowed');
      drupal_add_http_header('Allow', 'POST');
      throw new DatatransfersException('405 Method Not Allowed');
    }

    if (strpos($_SERVER['CONTENT_TYPE'] , 'application/x-www-form-urlencoded') !== 0) {
      drupal_add_http_header('Status', '415 Unsupported Media Type');
      throw new DatatransfersException('415 Unsupported Media Type');
    }
  }



  /**
   * Get the action class corresponding to the message type and action
   *
   * @return \Drupal\pw_datatransfers\Modtool\Actions\DataActionInterface
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   * @throws \Drupal\pw_datatransfers\Exception\SourceNotFoundException
   */
  protected function getActionClass() {
    $dataClass = NULL;

    if ($this->messageType == 'question') {
      $dataClass = $this->getActionClassQuestions();
    }
    elseif ($this->messageType == 'answer') {
      $dataClass = $this->getActionClassAnswers();
    }

    if ($dataClass === NULL) {
      throw new DatatransfersException($this->messageType .' is not a valid message type');
    }

    return $dataClass;
  }


  /**
   * Create an DataAction class which handles the defined action for a question
   *
   * @return \Drupal\pw_datatransfers\Modtool\Actions\DataActionInterface
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   * @throws \Drupal\pw_datatransfers\Exception\SourceNotFoundException
   */
  protected function getActionClassQuestions() {
    $modtoolMessage = $this->getModtoolMessage();
    $dataClass = new DataQuestion($modtoolMessage);
    $dataAction = NULL;

    switch ($this->action) {
      case 'release':
        $dataAction = new DataQuestionActionRelease($dataClass);
        break;
    }

    if (!$dataAction) {
      throw new DatatransfersException($this->action .' is not a valid action for a question');
    }

    return $dataAction;
  }


  /**
   * Create an DataAction class which handles the defined action for an answer
   *
   *  @return \Drupal\pw_datatransfers\Modtool\Actions\DataActionInterface
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   * @throws \Drupal\pw_datatransfers\Exception\SourceNotFoundException
   */
  protected function getActionClassAnswers() {
    $modtoolMessage = $this->getModtoolMessage();
    $dataClass = new DataAnswer($modtoolMessage);
    $dataAction = NULL;


    if (!$dataAction) {
      throw new DatatransfersException($this->action .' is not a valid action for an answer');
    }

    return $dataAction;
  }


  /**
   * Get a ModtoolMessage class from the sent JSON
   *
   * @return \Drupal\pw_datatransfers\Modtool\ModtoolMessage|null
   * @throws \Drupal\pw_datatransfers\Exception\SourceNotFoundException
   */
  protected function getModtoolMessage() {
    $modtoolMessage = NULL;

    if (isset($_POST['message'])) {
      $json_data = json_decode($_POST['message']);
      $modtoolMessage = new \Drupal\pw_datatransfers\Modtool\ModtoolMessage($json_data->message, $this->dialogueId);
    }

    if ($modtoolMessage === NULL) {
      throw new SourceNotFoundException('It was not possible to receive a JSON');
    }

    return $modtoolMessage;
  }


  /**
   * Set the status and status text for the response array
   *
   * @param string $status
   * The status - should be "error" or "success"
   *
   * @param string $status_text
   * The text describing the error or the success
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  protected function setStatus($status, $status_text) {
    $this->setResponseValue('status', $status);
    $this->setResponseValue('status_text', $status_text);
  }


  /**
   * Set the value of a field in the response array
   *
   * @param $key
   * @param $value
   *
   */
  protected function setResponseValue($key, $value) {
    if (array_key_exists($key, $this->responseArray)) {
      $this->responseArray[$key] = $value;
    }
  }


  /**
   * Create the success response for a question
   *
   * @param \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataEntityBase $dataQuestion
   */
  protected function successQuestion(DataEntityBase $dataQuestion) {
    $question = $dataQuestion->getEntity();
    $question_nid = $question->nid;
    global $base_url;
    $node_path = $base_url .'/node/'. $question_nid;
    if ($dataQuestion->isNew) {
      drupal_add_http_header('Status', '201 Created');
      drupal_add_http_header('Location', $node_path);
      $this->setResponseValue('status', 'success');
      $this->setResponseValue('status_text', 'New question created');
      $this->setResponseValue('drupal_question_id', $question_nid);
    }
    else {
      drupal_add_http_header('Status', '303 See Other');
      drupal_add_http_header('Location', $node_path);
      $this->setResponseValue('status', 'success');
      $this->setResponseValue('status_text', 'Question updated');
      $this->setResponseValue('drupal_question_id', $question_nid);
    }
  }



  /**
   * Create the success response for an answer
   *
   * @param \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataEntityBase $dataQuestion
   */
  protected function successAnswer(DataEntityBase $dataAnswer) {
    $comment = $dataAnswer->getEntity();
    $comment_cid = $comment->cid;
    $question_nid = $comment->nid;
    global $base_url;
    $node_path = $base_url .'/node/'. $question_nid;
    if ($dataAnswer->isNew) {
      drupal_add_http_header('Status', '201 Created');
      drupal_add_http_header('Location', $node_path);
      $this->setResponseValue('status', 'success');
      $this->setResponseValue('status_text', 'New answer created');
      $this->setResponseValue('drupal_question_id', $question_nid);
      $this->setResponseValue('drupal_answer_id', $comment_cid);
    }
    else {
      drupal_add_http_header('Status', '303 See Other');
      drupal_add_http_header('Location', $node_path);
      $this->setResponseValue('status', 'success');
      $this->setResponseValue('status_text', 'Answer updated');
      $this->setResponseValue('drupal_question_id', $question_nid);
      $this->setResponseValue('drupal_answer_id', $comment_cid);
    }
  }
}