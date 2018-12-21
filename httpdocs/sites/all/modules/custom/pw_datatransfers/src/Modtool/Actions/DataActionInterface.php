<?php


namespace Drupal\pw_datatransfers\Modtool\Actions;


/**
 * Interface for action related classes - each class describes what should be
 * done for a specific message type. For each message type and for each action
 * another action class may be used.
 *
 * @see \Drupal\pw_datatransfers\Modtool\ModtoolMessage->getActionClass()
 */
interface DataActionInterface {

  /**
   * Run the tasks/ actions chosen in the Modtool. Before starting the real
   * script call $this->check() within this function $this->run()
   * to do any validation checks.
   */
  public function run();


  /**
   * Do any checks before the actual action is running in this method. If a check
   * fails throw an DataActionException
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
   * @return \Drupal\pw_datatransfers\Modtool\DrupalEntity\DataEntityBase
   */
  public function getDataEntity();
}