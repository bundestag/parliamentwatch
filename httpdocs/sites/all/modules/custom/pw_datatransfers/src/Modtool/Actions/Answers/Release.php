<?php


namespace Drupal\pw_datatransfers\Modtool\Actions\Answers;


use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseAnswer;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;
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
    $this->checkIfQuestionIsReleased();
  }


  /**
   * Check if the question for the answer is released. If not we do not
   * release the answer either.
   *
   * @return bool
   *
   * @throws \Drupal\pw_datatransfers\Exception\DataActionException
   */
  protected function checkIfQuestionIsReleased() {
    $question_nid = $this->dataAnswer->getDrupalQuestionId();
    $question = DataQuestion::loadDrupalEntityById($question_nid);

    if (!$question) {
      throw new DataActionException('There is no question found for the answer.');
    }

    if (!$question->status) {
      throw new DataActionException('The answer could not be released because the corresponing question is not released yet.');
    }

    return TRUE;
  }

}