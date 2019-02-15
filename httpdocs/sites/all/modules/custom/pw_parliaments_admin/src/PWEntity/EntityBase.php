<?php


namespace Drupal\pw_parliaments_admin\PWEntity;


/**
 * To avoid the messy Drupal 7 entity API we use this
 * abstract class to implement a simple base save and loading system. To use
 * this class please note the following:
 *
 *  - the class extending this class needs a database table. Define it in hook_schema
 *  - name each property of the class in the same way as the database table column
 *    where this property should be stored
 *
 */
abstract class EntityBase implements EntityInterface {

  /**
   * @var int
   * The id of the entity
   */
  protected $id;


  /**
   * @var \Drupal\pw_parliaments_admin\PWEntity\EntityBase|FALSE
   * During updating we store the original values before updating here
   */
  protected $beforeUpdate = FALSE;


  /**
   * Turn the class into an array suitbale for saving to database
   *
   * @return array
   */
  abstract protected function toArrayForSaving();


  /**
   * Get an array of data loaded from a table for a single entity.
   *
   * Use this in the specific Entity implementations as a central function for
   * loading from data
   *
   * @param string $table
   * The table name where the entity is stored
   *
   * @param array $conditions
   * An array of conditions. Only "=" is possible, the key of the array is
   * the column name, the value to check
   *
   * @return array
   * An array of the fields. Empty if no entity found
   */
  public static function loadFromDatabase($table, array $conditions) {
    if (empty($conditions)) {
      return NULL;
    }

    $query = db_select($table, 'c');
    foreach ($conditions as $column => $value) {
      $query->condition($column, $value);
    }

    $query->fields('c');

    $result = $query->execute()->fetchAssoc();
    if (!$result) {
      $result = [];
    }

    return $result;
  }

  /**
   * Save the current object to the database
   *
   * @throws \Exception
   */
  function saveToDatabase($table) {
    $transaction = db_transaction();

    try {
      $values_as_array = $this->toArrayForSaving();
      unset($values_as_array['id']);
      if ($this->id === NULL) {
        $query = db_insert($table);
        $query->fields($values_as_array);
        $this->id = $query->execute();
      }
      else {
        $this->beforeUpdate = clone($this);
        $query = db_update($table);
        $query->condition('id', $this->id);
        $query->fields($values_as_array);
        $query->execute();
      }
    }
    catch (\Exception $e) {
      $transaction->rollback();
      watchdog_exception('pw_parliaments_admin', $e);
      drupal_set_message('An error appeared during saving: '. $e->getMessage());
      throw $e;
    }

  }


  /**
   * @return \Drupal\pw_parliaments_admin\PWEntity\EntityBase|FALSE
   */
  protected function getBeforeUpdateVersion() {
    return $this->beforeUpdate;
  }
}