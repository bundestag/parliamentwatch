<?php

namespace Drupal\pw_datatransfers\Modtool\Actions\Questions;


use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;

/**
 * Actionclass
 *  - message type: question
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
