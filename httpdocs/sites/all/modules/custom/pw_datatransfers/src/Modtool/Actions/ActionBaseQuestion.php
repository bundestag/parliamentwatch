<?php


namespace Drupal\pw_datatransfers\Modtool\Actions;

use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;
use Drupal\pw_datatransfers\Modtool\ModtoolMessage;
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
   * @var \Drupal\pw_datatransfers\Modtool\ModtoolMessage
   */
  protected $modtoolMessage;


  /**
   * DataActionQuestionBase constructor.
   *
   * @param \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion $data_question
   * The DataEntityBase of the question
   *
   * @param \Drupal\pw_datatransfers\Modtool\ModtoolMessage $modtool_message
   * The ModtoolMessage class for the message received from Modtool
   */
  public function __construct(DataQuestion $data_question, ModtoolMessage $modtool_message) {
    $this->dataQuestion = $data_question;
    $this->modtoolMessage = $modtool_message;
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
      $status_message_label = ModtoolMessageStatus::getOptionLabel($modtoolMessage->getStatus() );
      $target_status_label = ModtoolMessageStatus::getOptionLabel($status);
      throw new DataActionException('The question should have the status '. $status .' ('. $target_status_label .')  but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message_label. ')');
    }

    return TRUE;
  }

}
