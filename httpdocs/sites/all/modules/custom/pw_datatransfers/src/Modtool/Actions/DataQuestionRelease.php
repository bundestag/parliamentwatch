<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 14.12.2018
 * Time: 09:07
 */

namespace Drupal\pw_datatransfers\Modtool\Actions;


use Drupal\pw_datatransfers\Modtool\DataActionInterface;
use Drupal\pw_datatransfers\Modtool\DataQuestion;

class DataQuestionRelease implements DataActionInterface {

  protected $dataQuestion;

  public function __construct(DataQuestion $dataquestion) {
    $this->dataQuestion = $dataquestion;
  }

  public function run() {

  }
}