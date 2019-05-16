<?php

namespace Drupal\pw_datatransfers\Modtool\Actions;

use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataAnswer;
use Drupal\pw_datatransfers\Modtool\ModtoolMessage;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;


/**
 * An abstract base class for actions related to answers.
 *
 */
abstract class ActionBaseAnswer implements ActionInterface {

  /**
   * @var \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataAnswer
   */
  protected $dataAnswer;


  /**
   * @var \Drupal\pw_datatransfers\Modtool\ModtoolMessage
   */
  protected $modtoolMessage;

  /**
   * ActionBaseAnswer constructor.
   *
   * @param \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataAnswer $data_answer
   * The DataEntityBase of the answer
   *
   * @param \Drupal\pw_datatransfers\Modtool\ModtoolMessage $modtool_message
   * The ModtoolMessage class for the message received from Modtool
   */
  public function __construct(DataAnswer $data_answer, ModtoolMessage $modtool_message) {
    $this->dataAnswer = $data_answer;
    $this->modtoolMessage = $modtool_message;
  }


  /**
   * @inheritdoc
   */
  public function getEntity() {
    return $this->dataAnswer->getEntity();
  }


  /**
   * @inheritdoc
   */
  public function getDataEntity() {
    return $this->dataAnswer;
  }



  /**
   * Check if the message sent from Modtool has the correct status.
   *
   * For example wghen an answer should be released the answer sent
   * to Drupal should have this status.
   *
   * @param integer $status
   * The key of the status which should be checked
   *
   * @return bool
   *
   * @throws \Drupal\pw_datatransfers\Exception\DataActionException
   */
  protected function checkMessageStatus($status) {
    $modtoolMessage = $this->dataAnswer->getModtoolMessage();

    if ($modtoolMessage->getStatus() != $status) {
      $status_message_label = ModtoolMessageStatus::getOptionLabel($modtoolMessage->getStatus() );
      $target_status_label = ModtoolMessageStatus::getOptionLabel($status);
      throw new DataActionException('The answer should have the status '. $status .' ('. $target_status_label .')  but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message_label. ')');
    }

    return TRUE;
  }
}
