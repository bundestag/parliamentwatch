<?php


namespace Drupal\pw_datatransfers\Modtool\Actions;

use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;


/**
 * An abstract base class for actions related to questions.
 *
 */
abstract class ActionBaseQuestion implements ActionInterface {

  /**
   * @var \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion
   */
  protected $dataQuestion;


  /**
   * DataActionQuestionBase constructor.
   *
   * @param \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion $dataquestion
   */
  public function __construct(DataQuestion $dataquestion) {
    $this->dataQuestion = $dataquestion;
  }


  /**
   * @inheritdoc
   */
  public function getEntity() {
    return $this->dataQuestion->getEntity();
  }


  /**
   * @inheritdoc
   */
  public function getDataEntity() {
    return $this->dataQuestion;
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
    $modtoolMessage = $this->getDataEntity()->getModtoolMessage();

    if ($modtoolMessage->getStatus() != $status) {
      $status_message_label = ModtoolMessageStatus::getStatusLabel($modtoolMessage->getStatus() );
      $target_status_label = ModtoolMessageStatus::getStatusLabel($status);
      throw new DataActionException('The question should have the status '. $status .' ('. $target_status_label .')  but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message_label. ')');
    }

    return TRUE;
  }



  public function getModtoolMessage() {
    return $this->getDataEntity()->getModtoolMessage();
  }


  public function getMessageId() {
    return $this->getModtoolMessage()->getMessageId();
  }
}