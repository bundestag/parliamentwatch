<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 14.12.2018
 * Time: 08:46
 */

namespace Drupal\pw_datatransfers\Modtool;


use Drupal\pw_datatransfers\Modtool\Actions\DataQuestionRelease;

class DataQuestion {

  protected $json = NULL;

  public function __construct($json) {
    $this->json = $json;
  }

  public function getJson() {
    return $this->json;
  }

  public function action($action) {
    switch ($action) {
      case 'release':
        $releaseAction = new DataQuestionRelease($this);
        $releaseAction->run();
        break;
    }
  }
}