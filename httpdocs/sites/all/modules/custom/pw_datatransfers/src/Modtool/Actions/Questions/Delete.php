<?php

namespace Drupal\pw_datatransfers\Modtool\Actions\Questions;

use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseQuestion;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: question
 *  - action: delete
 *  - description: an existing question in Drupal will be deleted. If none was
 *    found nothing will be done
 */
class Delete extends ActionBaseQuestion {


  /**
   * Delete the question from Drupal if found
   */
  public function run() {
    $question = $this->dataQuestion->loadDrupalEntity();

    if ($question) {
      $this->dataQuestion->setEntity($question);
      $this->check();

      node_delete($question->nid);
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
    $modtoolMessage = $this->dataQuestion->getModtoolMessage();

    if ($modtoolMessage->getStatus() != ModtoolMessageStatus::DELETED) {
      $status_message = ModtoolMessageStatus::getStatusLabel($modtoolMessage->getStatus() );
      throw new DataActionException('The question should have status deleted but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message. ')');
    }

    return TRUE;
  }

}