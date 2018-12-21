<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 14.12.2018
 * Time: 09:07
 */

namespace Drupal\pw_datatransfers\Modtool\Actions;


use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

class DataQuestionActionRelease implements DataActionInterface {

  protected $dataQuestion;

  public function __construct(DataQuestion $dataquestion) {
    $this->dataQuestion = $dataquestion;
  }

  /**
   * On release an existing question may be updated or a new question may be
   * released
   */
  public function run() {
    $question = $this->dataQuestion->loadDrupalEntity();

    if (!$question) {
      $question = $this->dataQuestion->createDrupalEntity();
    }

    $this->dataQuestion->setDrupalEntityValuesFromJson($question);
    $this->dataQuestion->setEntity($question);
    $this->check();

    // release the question
    $question->status = 1;
    node_save($question);
  }


  /**
   * Before release we check if the sent message has the status "released"
   *
   * @return TRUE
   * Just in case no error appeared. Otherwise it throws an exception
   *
   * @throws \Drupal\pw_datatransfers\Exception\DataActionException
   */
  public function check() {
    $modtoolMessage = $this->dataQuestion->getModtoolMessage();

    if ($modtoolMessage->getStatus() != ModtoolMessageStatus::RELEASED) {
      $status_message = ModtoolMessageStatus::getStatusLabel($modtoolMessage->getStatus() );
      throw new DataActionException('The question '. $modtoolMessage->getMessageId() .' should be released but it has the status'. $status_message);
    }

    return TRUE;
  }


  public function getEntity() {
    return $this->dataQuestion->getEntity();
  }


  public function getDataEntity() {
    return $this->dataQuestion;
  }
}