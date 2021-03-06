<?php


namespace Drupal\pw_parliaments_admin\Import\Interfaces;


use Drupal\pw_parliaments_admin\PWEntity\EntityInterface;
use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\Import\Interfaces\ImportValidation;

/**
 * ImportDataSet classes describe a single entry from a CSV. Together with a
 * StructuredData class it describes how a Drupal entity will be gained from
 * the CSV entry.
 *
 * Be aware that you need to define a database table for that class
 */
interface ImportDataSetInterface extends EntityInterface, ImportValidation {


  /**
   *
   * Turn the ImportDataSet into an structuredData and save it to the database. This
   * function needs to do all the stuff needed to prepare the data for a later
   * import into Drupal.
   *
   * @return \Drupal\pw_parliaments_admin\Import\ConstituencyImport\ConstituencyStructuredData|\Drupal\pw_parliaments_admin\PWEntity\EntityInterface
   */
  public function createStructuredData();



  /**
   * Defines each field of the dataset in an array. The array should have
   * the following structure:
   *
   * 'NAME_OF_FIELD_IN_CSV' => [
   *    'required' => TRUE / FALSE,
   *    'csv' => TRUE when the field is taken from CSV
   *    'csv_required' => TRUE when the field needs to be set in CSV
   * ]
   *
   * @return array
   */
  public static function getFieldsInCSV();


  /**
   * Create a new instance of an ImportDataSet from the array the CSVParser
   * generates.
   *
   * @param array $dataFromCsv
   * An array of field values parsed from the CSV
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface
   */
  public static function createFromCSVArray(array $dataFromCsv, Import $import);


  /**
   * Get the fully namespaced class name of the related structured data
   *
   * @return string
   * Empty of no structured data
   */
  public static function getStructuredDataClassName();


  public function setStatus($status);

  /**
   * Reset the status when an import starts
   */
  public function resetStatus();
}