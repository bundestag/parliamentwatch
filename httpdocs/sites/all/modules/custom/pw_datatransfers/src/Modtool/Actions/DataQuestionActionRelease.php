<?php

namespace Drupal\pw_datatransfers\Modtool\Actions;

use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: question
 *  - action: release
 *  - description: a new question will be created and an question already existing
 *    in Drupal will be updated by the data/ values sent from Modtool. The status
 *    of the node will be 1.
 */
class DataQuestionActionRelease extends DataActionQuestionBase {


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
      throw new DataActionException('The question should have the status released but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message. ')');
    }

    return TRUE;
  }

}