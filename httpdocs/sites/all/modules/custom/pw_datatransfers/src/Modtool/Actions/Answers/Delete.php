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
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::DELETED);
  }

  /**
   * @inheritdoc
   */
  public function getSuccessMessage() {
    return t('The answer !messageid was deleted from Drupal.', ['!messageid' => $this->getMessageId()]);
  }

  /**
   * @inheritdoc
   */
  public function getErrorMessage() {
    return t('When trying to delete the answer !messageid from Drupal an error appeared.', ['!messageid' => $this->getMessageId()]);
  }
}