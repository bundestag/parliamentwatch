<?php


namespace Drupal\pw_datatransfers\Modtool;


interface DataActionInterface {

  /**
   * Run the tasks/ actions chosen in the Modtool
   */
  public function run();
}