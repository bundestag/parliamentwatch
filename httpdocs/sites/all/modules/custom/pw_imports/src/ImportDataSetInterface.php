<?php


namespace Drupal\pw_imports;


/**
 * ImportDataSet classes describe a single entry from a CSV and it's
 * relation to Drupal entities.
 */
interface ImportDataSetInterface {


  /**
   * Do the actual import of the data defined in the dataset. Always revalidate
   * before really importing the data to Drupal and throw an exception when
   * validation failed or when import failed.
   *
   * @return TRUE
   * True if everything worked fine. Otherwise it throws an exception
   *
   * @throws \Drupal\pw_imports\Exception\ImportException
   */
  public function import();


  /**
   * Validate if the field values of the dataset are valid.
   *
   * Validation should run for the whole dataset and all it's fields to
   * get a full overview about invalid data. Therefore each ImportDataSet class
   * stores the validation results for each field in a validations result array.
   * Additionally to avoid multiple runs through validation a property named
   * "validated" should be set to true. In this method validation should just run
   * when validated = FALSE or if $revalidate = TRUE
   *
   * @param bool $revalidate
   * Indicating if the validation should run although it might already has run
   *
   * @return void
   */
  public function validate($revalidate = FALSE);


  /**
   * Get the validation errors. Should call validate in case that validation
   * did not run yet.
   *
   * @return array
   * An array of validation errors. Empty if none was found
   */
  public function getValidationErrors();


  /**
   * Defines each field of the dataset in an array. The array should have
   * the following structure:
   *
   * 'NAME_OF_FIELD_IN_CSV' => [
   *    'required' => TRUE / FALSE
   * ]
   *
   * @return array
   */
  public static function getFields();
}