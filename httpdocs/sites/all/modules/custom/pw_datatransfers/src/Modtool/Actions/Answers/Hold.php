<?php


namespace Drupal\pw_datatransfers\Modtool\Actions\Answers;


use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseAnswer;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;


/**
 * Actionclass
 *  - message type: answer
 *  - action: hold
 *  - description: an existing answer in Drupal gets the status 0 and will
 *    be updated by the values sent from Modtool. If no answer exists it will
 *    be created with status = 0.
 */
class Hold extends ActionBaseAnswer {


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
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::HOLD);
  }

  /**
   * @inheritdoc
   */
  public function getSuccessMessage() {
    return t('The answer !messageid was set on hold in Drupal.', ['!messageid' => $this->getMessageId()]);
  }

  /**
   * @inheritdoc
   */
  public function getErrorMessage() {
    return t('When trying to set the answer !messageid on hold in Drupal an error appeared.', ['!messageid' => $this->getMessageId()]);
  }
}