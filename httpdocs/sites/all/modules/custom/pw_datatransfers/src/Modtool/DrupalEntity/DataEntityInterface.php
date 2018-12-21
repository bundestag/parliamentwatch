<?php

namespace Drupal\pw_datatransfers\Modtool\DrupalEntity;

/**
 * Interface DataEntityInterface
 *
 * Describes some basic functions the DataEntity classes for each message type
 * must have.
 *
 */
interface DataEntityInterface {

  /**
   * Create a new Drupal entity for a question/ answer. The new entity should
   * be as empty as possible - all values sent by the Modtool should be
   * set in $this->setDrupalEntityValuesFromJson()
   *
   * @return object
   * The Drupal node/ comment of the question/ dialogue
   */
  public function createDrupalEntity();


  /**
   * Load a Drupal entity from the given ModtoolMessage by it's
   * message id
   *
   * @return object|NULL
   */
  public function loadDrupalEntity();


  /**
   * Set the values for the entiy
   *
   * @param object $entity
   * A Drupal node or comment
   *
   * @return void
   */
  public function setDrupalEntityValuesFromJson($entity);

}