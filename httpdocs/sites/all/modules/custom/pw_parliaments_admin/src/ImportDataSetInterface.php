<?php


namespace Drupal\pw_parliaments_admin;


use Drupal\pw_parliaments_admin\Entity\EntityInterface;
use Drupal\pw_parliaments_admin\Import\Import;

/**
 * ImportDataSet classes describe a single entry from a CSV. Together with a
 * PreDrupalEntity class it describes how a Drupal entity will be gained from
 * the CSV entry. The PreDrupalEntity will then really creating the Drupal entities.
 */
interface ImportDataSetInterface extends EntityInterface {


  /**
   *
   * Turn the ImportDataSet into an PreEntity and save it to the database. This
   * function needs to do all the stuff needed to prepare the data for a later
   * import into Drupal.
   */
  public function preEntity();



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
   * @return \Drupal\pw_parliaments_admin\ImportDataSetInterface
   */
  public static function createFromCSVArray(array $dataFromCsv, Import $import);

  /**
   * Validate if the field values of the dataset are valid. Add errors to a
   * validationErrors[] array
   *
   *
   * @return void
   */
  public function validate();


  /**
   * Get the validation errors. Should call validate in case that validation
   * did not run yet.
   *
   * @return array
   * An array of validation errors. Empty if none was found
   */
  public function getValidationErrors();


  public function hasErrors();


  /**
   * get the label for a dataset
   *
   * @return string
   */
  public function getLabel();
}