<?php


namespace Drupal\pw_datatransfers\Modtool\Actions;


use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;

abstract class DataActionQuestionBase implements DataActionInterface {

  protected $dataQuestion;

  public function __construct(DataQuestion $dataquestion) {
    $this->dataQuestion = $dataquestion;
  }


  public function getEntity() {
    return $this->dataQuestion->getEntity();
  }


  public function getDataEntity() {
    return $this->dataQuestion;
  }

}