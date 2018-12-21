<?php


namespace Drupal\pw_datatransfers\Modtool\Actions;


use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;


/**
 * Actionclass
 *  - message type: answer
 *  - action: release
 *  - description: a new answer will be created and an answer already existing
 *    in Drupal will be updated by the data/ values sent from Modtool. The status
 *    of the comment will be 1.
 */
class DataAnswerActionRelease extends DataActionAnswersBase {


  /**
   * On release an existing answer may be updated or a new answer may be
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
    $answer->status = 1;
    comment_save($answer);
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
    $modtoolMessage = $this->dataAnswer->getModtoolMessage();

    if ($modtoolMessage->getStatus() != ModtoolMessageStatus::RELEASED) {
      $status_message = ModtoolMessageStatus::getStatusLabel($modtoolMessage->getStatus() );
      throw new DataActionException('The answer should have the status released but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message. ')');
    }

    return TRUE;
  }

}