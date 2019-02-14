<?php

namespace Drupal\pw_parliaments_admin\Import;


use Drupal\pw_parliaments_admin\Import\Interfaces\ImportTypeInterface;
use Drupal\pw_parliaments_admin\Status\DataSetStatus;


/**
 * Abstract base class for ImportTypes. Each type of import needs to be defined
 * by a class extending this abstract class. It defines which DataSet and
 * maybe StructuredData classes are connected to this type of import.
 *
 */
abstract class ImportTypeBase implements ImportTypeInterface {

  /**
   * @var bool
   * Indicating if a data structurng step is needed for the current import type.
   */
  protected $needsDataStructuring = FALSE;

  /**
   * @var string
   * The full namespaced name of the class of the datasets
   */
  protected $dataSetClass = '';


  /**
   * @var string
   * The full namespaced name of the class of the pre entity - if none
   * is needed for the type of import this is empty. Needs to be set if
   * $this->needsDataStructuring is set to TRUE
   */
  protected $structuredDataClass = '';


  /**
   * Get the fully PSR-4 class name for the corresponding dataset class
   *
   * @return string
   */
  public function getImportDataSetClassName() {
    return $this->dataSetClass;
  }


  /**
   * Get the fully PSR-4 class name for the corresponding structured data class.
   * Can be an empty string if no structured data is used for the type of import.
   *
   * @return string
   */
  public function getStructuredDataClassName() {
    return $this->structuredDataClass;
  }


  /**
   * Create a new instance of a dataset from an array received from CSVParser
   *
   * @param array $dataSet
   * Array of singe entry in CSV, received from CSVParser
   *
   * @param \Drupal\pw_parliaments_admin\Import\Import $import
   * The Import class
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface|\Drupal\pw_parliaments_admin\ImportDataSetInterface
   */
  public function createNewImportDataSetFromCSVArray(array $dataSet, Import $import) {
    /** @var \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface $class */
    $class = $this->dataSetClass;
    return $class::createFromCSVArray($dataSet, $import);
  }


  /**
   *
   * Create a new instance of dataset by the data received from dataset database table
   *
   * @param array $database_array
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface|mixed
   */
  public function getImportDataSetFromDataBaseArray(array $database_array) {
    /** @var \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface $class */
    $class = $this->dataSetClass;
    return $class::createFromDataBaseArray($database_array);
  }


  /**
   * Create a new instance of StructuredData from an array received from the
   * database
   *
   * @param array $database_array
   *
   * @return \Drupal\pw_parliaments_admin\Import\Interfaces\StructuredDataInterface|\Drupal\pw_parliaments_admin\PWEntity\EntityInterface
   */
  public function getStructuredDataFromDataBaseArray(array $database_array) {
    /** @var \Drupal\pw_parliaments_admin\Import\Interfaces\StructuredDataInterface $class */
    $class = $this->structuredDataClass;
    return $class::createFromDataBaseArray($database_array);
  }


  /**
   * Get the fields/ CSV columns required for the Import
   *
   * @return array
   */
  public function getRequiredFieldsForCSV() {
    /** @var \Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface $dataSetClass */
    $dataSetClass = $this->getImportDataSetClassName();
    $fields = $dataSetClass::getFieldsInCSV();
    $required_fields = [];
    foreach ($fields as $name => $info) {
      if ($info['csv_required']) {
        $required_fields[$name] = $name;
      }
    }

    return $required_fields;
  }


  /**
   * @return bool
   */
  public function needsDataStructuring() {
    return $this->needsDataStructuring;
  }
}