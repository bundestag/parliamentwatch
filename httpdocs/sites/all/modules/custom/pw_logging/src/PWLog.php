<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 04.01.2019
 * Time: 10:50
 */

namespace Drupal\pw_logging;


use Drupal\pw_datatransfers\Entity\Logentry;

/**
 * Helper class for logging. It defines the possible actions
 */
class PWLog {

  protected $action;

  protected $status;

  protected $message;

  protected $details;

  protected $detailsClass;

  protected $targetTool;

  protected $sourceTool;

  protected $exception;


  public function __construct($action, $status, $message, array $details = [], \Exception $exception = NULL) {
    $this->action = $action;
    $this->status = $status;
    $this->message = $message;
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
    $logentry_wrapper = entity_metadata_wrapper('pwlogentry', $logentry);
    $logentry_wrapper->tool_target->set($this->targetTool);
    $logentry_wrapper->tool_source->set($this->sourceTool);
    $logentry_wrapper->action->set($this->action);
    $logentry_wrapper->message->set($this->message);
    $logentry_wrapper->status->set($this->status);
    $logentry_wrapper->exception->set($this->exception);
    $logentry_wrapper->save();
    return $logentry;
  }


  protected function saveDetails(Logentry $logentry) {
    $detailClass = $this->getDetailsClass($this->action);

    $detailEntity = $detailClass::createFromLogDetails($logentry, $this->details);
    $detailClass->save();
  }

  protected function getDetailsClass($action) {
    $details = $this->actionsInformation($action);

    if (isset($details['details_class'])) {
      return $details['details_class'];
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
        'detail_class' => '\Drupal\pw_datatransfers\Entity\Details\ModtoolLogDetails',
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