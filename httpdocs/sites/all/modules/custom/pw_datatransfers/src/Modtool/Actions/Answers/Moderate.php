<?php


namespace Drupal\pw_datatransfers\Modtool\Actions\Answers;


use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseAnswer;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;


/**
 * Actionclass
 *  - message type: answer
 *  - action: moderate
 *  - description: an existing answer in Drupal gets the status 0 and will
 *    be updated by the values sent from Modtool. If no answer exists it will
 *    be created with status = 0.
 */
class Moderate extends ActionBaseAnswer {


  /**
   * When moderated an existing answer may be updated or a new answer may be
   * created
   */
  public function run() {
    $answer = $this->dataAnswer->loadDrupalEntity();

    if (!$answer) {
      $answer = $this->dataAnswer->createDrupalEntity();
    }

    $this->dataAnswer->setDrupalEntityValuesFromJson($answer);
    $this->dataAnswer->setEntity($answer);
    $this->check();

    // release the answer
    $answer->status = 0;
    comment_save($answer);
  }


  /**
   * Before moderate we check if the sent message has the status "moderated"
   *
   * @return TRUE
   * Just in case no error appeared. Otherwise it throws an exception
   *
   * @throws \Drupal\pw_datatransfers\Exception\DataActionException
   */
  public function check() {
    $modtoolMessage = $this->dataAnswer->getModtoolMessage();

    if ($modtoolMessage->getStatus() != ModtoolMessageStatus::MODERATED) {
      $status_message = ModtoolMessageStatus::getStatusLabel($modtoolMessage->getStatus() );
      throw new DataActionException('The answer should have status moderated but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message. ')');
    }

    return TRUE;
  }

}