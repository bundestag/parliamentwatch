<?php


namespace Drupal\pw_parliaments_admin\Import\Interfaces;

use Drupal\pw_parliaments_admin\PWEntity\EntityInterface;
use Drupal\pw_parliaments_admin\Import\Interfaces\ImportValidation;

/**
 * Structured data may be needed before a CSV dataset may be imported into Drupal.
 * For example the import of constituencies is done by importing a zip
 */
interface StructuredDataInterface extends EntityInterface, ImportValidation {

  /**
   * Get the fully namespaced class name of the related data set
   *
   * @return string
   */
  public static function getDataSetClassName();


  /**
   * Load the related data set
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface[]
   * Array of datasets or an empty array
   */
  public function getRelatedDataSets();

  public function setEntityId($id);

  public function setEntityRevisionVid($vid);

  public function import();

  public function setStatus($status);

  /**
   * Reset the status when an import starts
   */
  public function resetStatus();
}