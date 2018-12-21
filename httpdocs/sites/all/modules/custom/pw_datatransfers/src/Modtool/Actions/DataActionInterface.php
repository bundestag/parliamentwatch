<?php


namespace Drupal\pw_datatransfers\Modtool\Actions;


interface DataActionInterface {

  /**
   * Run the tasks/ actions chosen in the Modtool
   */
  public function run();


  /**
   * Do any checks before the actual action is running in this method
   *
   * @return TRUE
   *
   * @throws \Drupal\pw_datatransfers\Exception\DataActionException
   */
  public function check();

  /**
   * Get the Drupal entity updated/ added during the action
   *
   * @return object
   */
  public function getEntity();


  /**
   * Get the DataEntity class
   *
   * @return \Drupal\pw_datatransfers\Modtool\DataEntityInterface
   */
  public function getDataEntity();
}