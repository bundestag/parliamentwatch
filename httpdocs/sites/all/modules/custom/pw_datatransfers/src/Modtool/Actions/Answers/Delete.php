<?php

namespace Drupal\pw_datatransfers\Modtool\Actions\Answers;

use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseAnswer;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: answer
 *  - action: delete
 *  - description: an existing answer in Drupal will be deleted. If none was
 *    found nothing will be done
 */
class Delete extends ActionBaseAnswer {


  /**
   * Delete the answer from Drupal if found
   */
  public function run() {
    $answer = $this->dataAnswer->loadDrupalEntity();

    if ($answer) {
      $this->dataAnswer->setEntity($answer);
      $this->check();

      comment_delete($answer->cid);
    }
  }


  /**
   * Before deletion we check if the sent message has the status "deleted"
   *
   * @return TRUE
   * Just in case no error appeared. Otherwise it throws an exception
   *
   * @throws \Drupal\pw_datatransfers\Exception\DataActionException
   */
  public function check() {
    $modtoolMessage = $this->dataAnswer->getModtoolMessage();

    if ($modtoolMessage->getStatus() != ModtoolMessageStatus::DELETED) {
      $status_message = ModtoolMessageStatus::getStatusLabel($modtoolMessage->getStatus() );
      throw new DataActionException('The answer should have status deleted but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message. ')');
    }

    return TRUE;
  }

}