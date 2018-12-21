<?php

namespace Drupal\pw_datatransfers\Modtool\Actions;

use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: question
 *  - action: hold
 *  - description: an existing question in Drupal gets the status 0 and will
 *    be updated by the values sent from Modtool. If no question exists it will
 *    be created with status = 0.
 */
class DataQuestionActionHold extends DataActionQuestionBase {


  /**
   * On release an existing question may be updated or a new question may be
   * created
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
    $question->status = 0;
    node_save($question);
  }


  /**
   * Before set on hold we check if the sent message has the status "hold"
   *
   * @return TRUE
   * Just in case no error appeared. Otherwise it throws an exception
   *
   * @throws \Drupal\pw_datatransfers\Exception\DataActionException
   */
  public function check() {
    $modtoolMessage = $this->dataQuestion->getModtoolMessage();

    if ($modtoolMessage->getStatus() != ModtoolMessageStatus::HOLD) {
      $status_message = ModtoolMessageStatus::getStatusLabel($modtoolMessage->getStatus() );
      throw new DataActionException('The question '. $modtoolMessage->getMessageId() .' should have status "hold" but it has the status '. $modtoolMessage->getStatus() .'('. $status_message. ')');
    }

    return TRUE;
  }

}