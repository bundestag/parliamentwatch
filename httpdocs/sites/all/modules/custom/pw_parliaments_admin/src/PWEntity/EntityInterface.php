<?php


namespace Drupal\pw_parliaments_admin\PWEntity;


/**
 * To avoid the messy Drupal 7 entity API we use this Interface and the EntiyBase
 * abstract class to implement a simple base save and loading system
 */
interface EntityInterface {

  /**
   * Load a single structuredData from database by conditions defined in the
   * array. It is only suitable for "=" conditions which can be defined
   * es key value pairs within the array
   *
   * @param string|int $id
   * The id of the entity to load
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\StructuredDataInterface|NULL
   */
  public static function load($id);


  /**
   * Save the current object data to the database (update/ insert)
   */
  public function save();


  /**
   * Get the name of the database table where the entity is stored
   *
   * @return string
   */
  public static function getDatabaseTable();


  /**
   * @return int
   * The unique id of the entity
   */
  public function getId();


  /**
   * get the label for an entity
   *
   * @return string
   */
  public function getLabel();


  /**
   * Create a new class from the data loaded from the database
   *
   * @param array $database_data
   *
   * @return \Drupal\pw_parliaments_admin\PWEntity\EntityInterface
   */
  public static function createFromDataBaseArray(array $database_data);


  /**
   * Deletes the current object data from the database
   */
  public function delete();
}