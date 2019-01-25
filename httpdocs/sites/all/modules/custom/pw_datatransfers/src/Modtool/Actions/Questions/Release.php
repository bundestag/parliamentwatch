<?php

namespace Drupal\pw_datatransfers\Modtool\Actions\Questions;

use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseQuestion;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: question
 *  - action: release
 *  - description: a new question will be created and an question already existing
 *    in Drupal will be updated by the data/ values sent from Modtool. The status
 *    of the node will be 1.
 */
class Release extends ActionBaseQuestion {


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
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::RELEASED);
  }
}