<?php


namespace Drupal\pw_datatransfers\Modtool\Actions;

use Drupal\pw_datatransfers\Modtool\DrupalEntity\DataQuestion;


/**
 * An abstract base class for actions related to questions.
 *
 */
abstract class ActionBaseQuestion implements DataActionInterface {

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

}