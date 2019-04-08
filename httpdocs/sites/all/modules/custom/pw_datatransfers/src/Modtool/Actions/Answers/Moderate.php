<?php


namespace Drupal\pw_datatransfers\Modtool\Actions\Answers;


use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: answer
 *  - action: moderate
 *  - description: the answer gets deleted.
 */

class Moderate extends Delete {
  /**
 * @inheritdoc
 */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::MODERATED);
  }
}
