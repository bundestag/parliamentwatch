<?php

namespace Drupal\pw_datatransfers\Modtool\Actions\Questions;

use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseQuestion;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: question
 *  - action: moderate
 *  - description: an existing question in Drupal gets the status 0 and will
 *    be updated by the values sent from Modtool. If no question exists it will
 *    be created with status = 0.
 */
class Moderate extends ActionBaseQuestion {


  /**
   * When a question is moderated an existing question may be updated or a new question may be
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
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::MODERATED);
  }

}