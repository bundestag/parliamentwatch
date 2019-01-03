<?php

namespace Drupal\pw_datatransfers\Modtool\Actions\Questions;

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
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::DELETED);
  }

}