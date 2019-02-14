<?php

namespace Drupal\pw_parliaments_admin\Import\Interfaces;

use Drupal\pw_parliaments_admin\CsvParser;
use Drupal\pw_parliaments_admin\Import\Import;

/**
 * Defines functions needed for Import classes. An Import class describes
 * the settings for an import like the parliament for which the
 * data will be imported, stores the CSV file and an import check status. For each
 * type of import (for example import of constituencies, profiles and election
 * results are each a type of import) a seperate Import class needs to be defined
 * which needs to implement this interface.
 */
interface ImportTypeInterface {

  /**
   * Renders the information on the pre check like a preview of the
   * CSV and information about the fields required and used on import.
   *
   * Use ImportDataSet::getFieldsInCSV() to get the information about the fields
   * used for the actual type of import
   *
   * @return string
   */
  public function renderPreCheck(CsvParser $csvparse);


  /**
   * Depending on the chosen type of import another ImportDataSet class
   * will be needed.
   *
   * @param array $dataSet
   * An array of data set fields and values parsed by the CSV parser
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface
   */
  public function createNewImportDataSetFromCSVArray(array $dataSet, Import $import);


  /**
   * @param array $database_array
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface
   */
  public function getImportDataSetFromDataBaseArray(array $database_array);

  /**
   * Get the autoloading path for the actual ImportDataSet class used for the
   * type of import.
   *
   * @return string
   */
  public function getImportDataSetClassName();


  /**
   * Get the autoloading path for the actual ImportDataSet class used for the
   * type of import.
   *
   * @return string
   */
  public function getStructuredDataClassName();


  /**
   * @param array $database_array
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\StructuredDataInterface
   */
  public function getStructuredDataFromDataBaseArray(array $database_array);

  /**
   * Get all required CSV fields which are needed for the specific type of import
   *
   * @return array
   *
   * Array of CSV fields required for a specific import type
   */
  public function getRequiredFieldsForCSV();


  /**
   * Define if the ImportType needs a step between CSV import and Drupal import
   * where the data received from CSV gets turned into another structure.
   *
   * @return bool
   */
  public function needsDataStructuring();


  /**
   * Get the machine readable name of the view for specific type of entity
   *
   * @param string $entity_type
   * The entity type which the view should list. Can ba 'dataset' or
   * 'structured_data'
   *
   * @return string
   * The name of the view. An empty string if none was found
   */
  public function getViewName($entity_type = 'dataset');
}