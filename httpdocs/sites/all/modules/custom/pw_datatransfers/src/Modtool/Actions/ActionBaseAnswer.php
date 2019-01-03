<?php

namespace Drupal\pw_datatransfers\Modtool\Actions;

use Drupal\pw_datatransfers\Exception\DataActionException;
use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataAnswer;
use Drupal\pw_datatransfers\Modtool\ModtoolMessageStatus;


abstract class ActionBaseAnswer implements DataActionInterface {

  /**
   * @var \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataAnswer
   */
  protected $dataAnswer;

  public function __construct(DataAnswer $dataanswer) {
    $this->dataAnswer = $dataanswer;
  }


  public function getEntity() {
    return $this->dataAnswer->getEntity();
  }


  public function getDataEntity() {
    return $this->dataAnswer;
  }



  /**
   * Before release we check if the sent message has the status "released"
   *
   * @return TRUE
   * Just in case no error appeared. Otherwise it throws an exception
   *
   * @throws \Drupal\pw_datatransfers\Exception\DataActionException
   */
  public function check() {
    $modtoolMessage = $this->dataAnswer->getModtoolMessage();

    if ($modtoolMessage->getStatus() != ModtoolMessageStatus::RELEASED) {
      $status_message = ModtoolMessageStatus::getStatusLabel($modtoolMessage->getStatus() );
      throw new DataActionException('The answer should have the status released but it has the status '. $modtoolMessage->getStatus() .' ('. $status_message. ')');
    }

    return TRUE;
  }

}