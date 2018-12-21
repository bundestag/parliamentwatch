<?php

namespace Drupal\pw_datatransfers\Modtool\Actions;

use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataAnswer;


abstract class DataActionAnswersBase implements DataActionInterface {

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

}