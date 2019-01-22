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


  /**
   * Get the question id (node nid of dialogue)
   *
   * @return int|string
   */
  public function getDrupalQuestionId();


  /**
   * Get the answer id (comment cid of answer comment). Can be null
   *
   * @return int|string|null
   */
  public function getDrupalAnswerId();


  /**
   * Static helper to load the corresponding Drupal entity for a question or answer
   * even if we do not have a ModtoolMessage
   *
   * @param $id
   *
   * @return object|boolean
   * The node object for questions, the comment object for answers. FALSE if none was found.
   */
  public static function loadDrupalEntityById($id);
}