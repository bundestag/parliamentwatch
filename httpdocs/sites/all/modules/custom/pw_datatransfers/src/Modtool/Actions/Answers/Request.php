<?php


namespace Drupal\pw_datatransfers\Modtool\Actions\Answers;


use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\Actions\ActionBaseAnswer;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;


/**
 * Actionclass
 *  - message type: answer
 *  - action: request
 *  - description: We do not change anything for answers. Requested answers
 *    which are relased stay published
 */
class Request extends ActionBaseAnswer {


  /**
   * When moderated an existing answer may be updated or a new answer may be
   * created
   */
  public function run() {
  }


  /**
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::REQUESTED);
  }

}
