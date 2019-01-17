<?php

namespace Drupal\pw_parliaments_admin;


use Drupal\pw_parliaments_admin\Entity\EntityBase;

abstract class ImportDataSetBase extends EntityBase implements ImportDataSetInterface {

  protected $validationErrors = [];


  /**
   * Set a validation error on a field
   *
   * @param $field
   * @param $error
   */
  protected function setValidationError($field, $error) {
    $this->validationErrors[$field][] = $error;
  }


  public function getValidationErrors() {
    return $this->validationErrors;
  }

  public function hasErrors() {
    return (count($this->getValidationErrors()) > 0);
  }


}