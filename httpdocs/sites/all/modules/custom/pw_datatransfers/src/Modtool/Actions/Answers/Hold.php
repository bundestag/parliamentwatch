<?php


namespace Drupal\pw_datatransfers\Modtool\Actions\Answers;


use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: answer
 *  - action: hold
 *  - description: the answer gets deleted.
 */

class Hold extends Delete {
  /**
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::HOLD);
  }
}
