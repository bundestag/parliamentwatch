<?php


namespace Drupal\pw_parliaments_admin\Import\Interfaces;


/**
 * Use this interface for classes which will need some kind of validation
 */
interface ImportValidation {


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

  public function setValidationError($error);
}