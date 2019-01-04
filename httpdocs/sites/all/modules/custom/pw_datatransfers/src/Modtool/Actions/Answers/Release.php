<?php


namespace Drupal\pw_datatransfers\Modtool\Actions\Answers;


use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseAnswer;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;


/**
 * Actionclass
 *  - message type: answer
 *  - action: release
 *  - description: a new answer will be created and an answer already existing
 *    in Drupal will be updated by the data/ values sent from Modtool. The status
 *    of the comment will be 1.
 */
class Release extends ActionBaseAnswer {


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
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::RELEASED);
  }

  /**
   * @inheritdoc
   */
  public function getSuccessMessage() {
    return t('The answer !messageid was released in Drupal.', ['!messageid' => $this->getMessageId()]);
  }

  /**
   * @inheritdoc
   */
  public function getErrorMessage() {
    return t('When trying to release the answer !messageid in Drupal an error appeared.', ['!messageid' => $this->getMessageId()]);
  }
}