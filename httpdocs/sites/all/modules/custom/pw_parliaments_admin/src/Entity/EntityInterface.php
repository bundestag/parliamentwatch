<?php


namespace Drupal\pw_parliaments_admin\Entity;


/**
 * To avoid the messy Drupal 7 entity API we use this Interface and the EntiyBase
 * abstract class to implement a simple base save and loading system
 */
interface EntityInterface {

  /**
   * Load a single PreEntity from database by conditions defined in the
   * array. It is only suitable for "=" conditions which can be defined
   * es key value pairs within the array
   *
   * @param string|int $id
   * The id of the entity to load
   *
   * @return \Drupal\pw_parliaments_admin\PreEntityInterface|NULL
   */
  public static function load($id);

  public function save();

  public static function getDatabaseTable();

}