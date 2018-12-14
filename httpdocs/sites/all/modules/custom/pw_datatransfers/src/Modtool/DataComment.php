<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 14.12.2018
 * Time: 08:49
 */

namespace Drupal\pw_datatransfers\Modtool;


class DataComment {

  protected $json = NULL;

  public function __construct($json) {
    $this->json = $json;
  }
}