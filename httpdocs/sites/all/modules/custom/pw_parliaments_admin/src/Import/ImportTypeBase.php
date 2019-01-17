<?php

namespace Drupal\pw_parliaments_admin\Import;


use Drupal\pw_parliaments_admin\ImportTypeInterface;

abstract class ImportTypeBase implements ImportTypeInterface {

  public function getImportDataSetClass() {
    return $this->dataSetClass;
  }


  public function createNewImportDataSet(array $dataSet, Import $import) {
    return $this->dataSetClass::createFromCSVArray($dataSet, $import);
  }
  
  public function getRequiredFieldsForCSV() {
    $dataSetClass = $this->getImportDataSetClass();
    $fields = $dataSetClass::getFieldsInCSV();
    $required_fields = [];
    foreach ($fields as $name => $info) {
      if ($info['csv_required']) {
        $required_fields[$name] = $name;
      }
    }

    return $required_fields;
  }
}