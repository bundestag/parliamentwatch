<?php


namespace Drupal\pw_datatransfers\Modtool\Actions;


use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;


/**
 * Base class for DataAction classes related to questions
 */
abstract class DataActionQuestionBase implements DataActionInterface {

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
   * @return object|null
   */
  public function getEntity() {
    return $this->dataQuestion->getEntity();
  }


  /**
   * @return \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion
   */
  public function getDataEntity() {
    return $this->dataQuestion;
  }

}