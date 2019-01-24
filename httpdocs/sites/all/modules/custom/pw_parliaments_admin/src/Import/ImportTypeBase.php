<?php

namespace Drupal\pw_parliaments_admin\Import;


use Drupal\pw_parliaments_admin\ImportTypeInterface;
use Drupal\pw_parliaments_admin\Status\DataSetStatus;

abstract class ImportTypeBase implements ImportTypeInterface {

  /**
   * @var string
   * The full namespaced name of the class of the datasets
   */
  protected $dataSetClass = '';


  /**
   * @var string
   * The full namespaced name of the class of the pre entity - if none
   * is needed for the type of import this is empty
   */
  protected $structuredDataClass = '';


  public function getImportDataSetClassName() {
    return $this->dataSetClass;
  }

  public function getStructuredDataClassName() {
    return $this->structuredDataClass;
  }


  public function createNewImportDataSetFromCSVArray(array $dataSet, Import $import) {
    /** @var \Drupal\pw_parliaments_admin\ImportDataSetInterface $class */
    $class = $this->dataSetClass;
    return $class::createFromCSVArray($dataSet, $import);
  }

  /**
   * @param array $database_array
   *
   * @return \Drupal\pw_parliaments_admin\ImportDataSetInterface|mixed
   */
  public function getImportDataSetFromDataBaseArray(array $database_array) {
    /** @var \Drupal\pw_parliaments_admin\ImportDataSetInterface $class */
    $class = $this->dataSetClass;
    return $class::createFromDataBaseArray($database_array);
  }

  public function getStructuredDataFromDataBaseArray(array $database_array) {
    /** @var \Drupal\pw_parliaments_admin\StructuredDataInterface $class */
    $class = $this->structuredDataClass;
    return $class::createFromDataBaseArray($database_array);
  }


  public function getRequiredFieldsForCSV() {
    /** @var \Drupal\pw_parliaments_admin\ImportDataSetInterface $dataSetClass */
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


  public function loadAllDataSetsByImport($import_id, $status = 'all') {
    /** @var \Drupal\pw_parliaments_admin\ImportDataSetInterface $dataSetClass */
    $dataSetClass = $this->getImportDataSetClassName();
    $query = db_select($dataSetClass::getDatabaseTable(), 't');
    $query->fields('t');

    if ($status == DataSetStatus::ERROR) {
      $query->condition('status', DataSetStatus::ERROR);
    }

    if ($status == DataSetStatus::OK) {
      $query->condition('status', DataSetStatus::OK);
    }

    $result = $query->execute();
    return $result->fetchAllAssoc('id');
  }
}