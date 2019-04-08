<?php

namespace Drupal\pw_datatransfers\Modtool\Actions\Questions;


use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: question
 *  - action: unrelease
 *  - description: the answer gets deleted.
 */
class Unrelease extends Delete {

  /**
   * @inheritdoc
   */
  public function check() {
    $this->checkMessageStatus(ModtoolMessageStatus::UNRELEASED);
  }
}
