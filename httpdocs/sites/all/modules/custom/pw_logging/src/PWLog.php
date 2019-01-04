<?php


namespace Drupal\pw_logging;


use \Drupal\pw_logging\Entity\Logentry;

/**
 * Helper class for logging. It defines the possible actions
 */
class PWLog {

  protected $action;

  protected $status;

  protected $generalMessage;

  protected $errorMessage;

  protected $details;

  protected $detailsClass;

  protected $targetTool;

  protected $sourceTool;

  protected $exception;


  public function __construct($action, $status, $message_general, $error_message, array $details = [], \Exception $exception = NULL) {
    $this->action = $action;
    $this->status = $status;
    $this->generalMessage = $message_general;
    $this->errorMessage = $error_message;
    $this->details = $details;
    $this->setTargetTool($action);
    $this->setSourceTool($action);
    $this->exception = $exception;
  }


  public function log() {
    $transaction = db_transaction();
    try {
      $logentry = $this->saveLogEntry();
      $this->saveDetails($logentry);
    }
    catch (\Exception $e) {
      $transaction->rollback();
      watchdog_exception('pw_logging', $e);
    }
  }

  protected function saveLogEntry() {
    $logentry = entity_create('pwlogentry', []);
    $logentry->tool_target = $this->targetTool;
    $logentry->tool_source = $this->sourceTool;
    $logentry->action = $this->action;
    $logentry->message_general = $this->generalMessage;
    $logentry->message_error = $this->errorMessage;
    $logentry->status = $this->status;
    $logentry->date = time();
    $logentry->exception = $this->exception;
    $logentry->save();
    return $logentry;
  }


  protected function saveDetails(Logentry $logentry) {
    $detailClass = $this->getDetailsClass($this->action);

    if ($detailClass !== NULL) {
      $detailEntity = $detailClass::createFromLogDetails($logentry, $this->details);
      $detailEntity->save();
    }
  }

  protected function getDetailsClass($action) {
    $details = $this->actionsInformation($action);

    if (isset($details['detail_class'])) {
      return $details['detail_class'];
    }

    return NULL;
  }


  protected function setTargetTool($action) {
    $details = $this->actionsInformation($action);

    if (isset($details['target_tool'])) {
      $this->targetTool = $details['target_tool'];
    }
    else {
      $this->targetTool = NULL;
    }
  }


  protected function setSourceTool($action) {
    $details = $this->actionsInformation($action);

    if (isset($details['source_tool'])) {
      $this->sourceTool = $details['source_tool'];
    }
    else {
      $this->sourceTool = NULL;
    }
  }
  protected function actionsInformation($action = FALSE) {
    $all_actions_information = [
      'update_from_modtool' => [
        'detail_class' => '\Drupal\pw_logging\Entity\Details\ModtoolLogDetails',
        'target_tool' => 'drupal',
        'source_tool' => 'modtool'
      ]
    ];

    if ($action && array_key_exists($action, $all_actions_information)) {
      return $all_actions_information[$action];
    }
    else {
      return $all_actions_information;
    }
  }
}