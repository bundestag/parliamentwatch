<?php


namespace Drupal\pw_datatransfers\Controller;


use Drupal\pw_datatransfers\Exception\DatatransfersException;
use Drupal\pw_datatransfers\Exception\InvalidSourceException;
use Drupal\pw_datatransfers\Exception\SourceNotFoundException;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataAnswer;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataEntityBase;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;

/**
 * Helper class for better control over the Modtool import dialogue page callback
 */
class ModtoolActionsController {

  /**
   * @var array
   * See constructor for the structure of the array
   */
  protected $responseArray = [];


  /**
   * @var integer|string
   * The dialogue id from Modtool as defined in the path
   */
  protected $dialogueId = NULL;


  /**
   * @var string
   * The message type from Modtool as defined in the path
   */
  protected $messageType = NULL;


  /**
   * @var integer|string
   * The message id from Modtool as defined in the path
   */
  protected $messageId = NULL;


  /**
   * @var string
   * The action from Modtool as defined in the path
   */
  protected $action = NULL;


  /**
   * @var \Drupal\pw_datatransfers\Modtool\Actions\ActionInterface
   */
  protected $actionClass = NULL;


  /**
   * @var \Drupal\pw_datatransfers\Modtool\ModtoolMessage
   * The ModtoolMessage class created from the JSON
   */
  protected $modtoolMessage;


  /**
   * @var DataEntityBase
   * The DataClass building the bridge to Drupal entities
   */
  protected $dataClass;


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

      $this->setModtoolMessage();
      $this->setDataClass();

      $this->actionClass = $this->getActionClass();
      $this->actionClass->run();
    }
    // catch DataTransfersExceptions to have user friendly error messages
    catch (DatatransfersException $d) {
      $this->setErrorResponse($d->getMessage(), $d);
      return $this->responseArray;
    }
      // catch all other exceptions to avoid cryptic error messages
    catch (\Exception $e) {
      $this->setErrorResponse('500 Internal Server Error', $e);
      return $this->responseArray;
    }


    $this->setSuccessResponse();
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
      throw new DatatransfersException('401 Unauthorized - no match found for sent credentials');
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

    if (strpos($_SERVER['CONTENT_TYPE'] , 'application/json') !== 0) {
      drupal_add_http_header('Status', '415 Unsupported Media Type');
      throw new DatatransfersException('415 Unsupported Media Type');
    }
  }



  /**
   * Get the action class corresponding to the message type and action
   *
   * @return \Drupal\pw_datatransfers\Modtool\Actions\ActionInterface
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
   * @return \Drupal\pw_datatransfers\Modtool\Actions\ActionInterface
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   * @throws \Drupal\pw_datatransfers\Exception\SourceNotFoundException
   */
  protected function getActionClassQuestions() {
    switch ($this->action) {
      case 'release':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Questions\Release($this->dataClass);
        break;
      case 'moderate':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Questions\Moderate($this->dataClass);
        break;
      case 'hold':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Questions\Hold($this->dataClass);
        break;
      case 'request':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Questions\Request($this->dataClass);
        break;
      case 'unrelease':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Questions\Unrelease($this->dataClass);
        break;
      case 'delete':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Questions\Delete($this->dataClass);
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
   *  @return \Drupal\pw_datatransfers\Modtool\Actions\ActionInterface
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   * @throws \Drupal\pw_datatransfers\Exception\SourceNotFoundException
   */
  protected function getActionClassAnswers() {
    $dataAction = NULL;
    switch ($this->action) {
      case 'release':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Answers\Release($this->dataClass);
        break;
      case 'moderate':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Answers\Moderate($this->dataClass);
        break;
      case 'hold':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Answers\Hold($this->dataClass);
        break;
      case 'request':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Answers\Request($this->dataClass);
        break;
      case 'unrelease':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Answers\Unrelease($this->dataClass);
        break;
      case 'delete':
        $dataAction = new \Drupal\pw_datatransfers\Modtool\Actions\Answers\Delete($this->dataClass);
        break;
    }

    if (!$dataAction) {
      throw new DatatransfersException($this->action .' is not a valid action for an answer');
    }

    return $dataAction;
  }


  /**
   * Set the ModtoolMessage class from the sent JSON
   *
   * @throws \Drupal\pw_datatransfers\Exception\SourceNotFoundException
   * @throws \Drupal\pw_datatransfers\Exception\InvalidSourceException
   */
  protected function setModtoolMessage() {
    $modtoolMessage = NULL;
    $received_json = file_get_contents("php://input",  TRUE);
    $json_data = json_decode($received_json);

    if (!$json_data) {
      throw new SourceNotFoundException('It was not possible to receive a JSON');
    }
    $modtoolMessage = new \Drupal\pw_datatransfers\Modtool\ModtoolMessage($json_data->message, $this->dialogueId, $this->messageId);


    if ($modtoolMessage->getType() !== $this->messageType) {
      throw new InvalidSourceException('The type ('. $modtoolMessage->getType() .') of the message sent does not match the message type defined in path ('. $this->messageType .').');
    }

    $this->modtoolMessage = $modtoolMessage;
  }


  /**
   * Set the DataClass representing the Drupal node entity of the message
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  protected function setDataClass() {
    $dataClass = NULL;

    switch ($this->messageType) {
      case 'question':
        $dataClass = new DataQuestion($this->modtoolMessage);
        break;
      case 'answer':
        $dataClass = new DataAnswer($this->modtoolMessage);
        break;
    }

    if (!$dataClass) {
      throw new DatatransfersException('The defined message type ('. $this->messageType .') is not a valid type.');
    }

    $this->dataClass = $dataClass;
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
   *
   * Set HTTP header and response array on failure
   *
   * @param string $text
   * The error text which should be shown in response array
   *
   * @param \Exception $exception
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  protected function setErrorResponse($text, \Exception $exception) {
    watchdog_exception('pw_datatransfers', $exception);
    $status_header = drupal_get_http_header('status');
    if (!$status_header) {
      drupal_add_http_header('Status', '500 Internal Server Error');
    }
    $this->setStatus('error', $text);
  }


  /**
   * Set HTTP header and response array on success
   */
  protected function setSuccessResponse() {
    // set the success response
    $dataEntity = $this->actionClass->getDataEntity();

    if ($dataEntity->isNew) {
      drupal_add_http_header('Status', '201 Created');
      $this->setResponseValue('status', 'success');
      $this->setResponseValue('status_text', 'New '. $this->messageType .' created');
    }
    elseif ($dataEntity->isDeleted) {
      drupal_add_http_header('Status', '205 Deleted');
      $this->setResponseValue('status', 'success');
      $this->setResponseValue('status_text', 'The '. $this->messageType .' was deleted');
    }
    else {
      drupal_add_http_header('Status', '200 OK');
      $this->setResponseValue('status', 'success');
      $this->setResponseValue('status_text', $this->messageType .' updated');
    }
    switch ($this->messageType) {
      case 'question':
        $this->setResponseValue('drupal_question_id', $dataEntity->getDrupalQuestionId());
        break;
      case 'answer':
        $this->setResponseValue('drupal_question_id', $dataEntity->getDrupalQuestionId());
        $this->setResponseValue('drupal_answer_id', $dataEntity->getDrupalAnswerId());
        break;
    }
  }

}
