<?php

namespace Drupal\pw_parliaments_admin\DataSets;


use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\ImportDataSetBase;
use Drupal\pw_parliaments_admin\Status\DataSetStatus;


class ConstituencyImportDataSet extends ImportDataSetBase {

  protected $id;

  protected $parliament;

  protected $constituency;

  protected $constituency_nr;

  protected $electoral_region;

  protected $area_code;

  protected $area_code_descriptor;

  protected $street;

  protected $importId;

  protected $status;

  protected $errors;

  /**
   * @var \Drupal\pw_parliaments_admin\Import\Import|FALSE
   */
  protected $importClass;

  public function __construct($parliament, $constituency, $constituency_nr, $area_code, $import_id, $electoral_region = '', $area_code_descriptor = '', $street = '', $id = NULL, $status = NULL, $errors = '') {
    $this->id = $id;
    $this->parliament = $parliament;
    $this->constituency = $constituency;
    $this->constituency_nr = $constituency_nr;
    $this->electoral_region = $electoral_region;
    $this->area_code = $area_code;
    $this->area_code_descriptor = $area_code_descriptor;
    $this->street = $street;
    $this->importId = $import_id;
    $this->importClass = Import::load($this->importId);
    $this->errors = $errors;
    $this->status = $status;
  }

  public function setAreaCodeDescriptor($descriptor) {
    $this->area_code_descriptor = $descriptor;
  }

  public function setElectoralRegion($electoral_region) {
    $this->electoral_region = $electoral_region;
  }

  public function setStreet($street) {
    $this->street = $street;
  }

  public function preEntity() {
    // first we try to load already defined PreEntity
    $conditions = [
      'field_constituency_nr' => $this->constituency_nr
    ];
    $preEntity = ConstituencyPreEntity::load($conditions);

    if (!$preEntity) {
      $preEntity = new ConstituencyPreEntity($this->constituency, $this->parliament, $this->constituency_nr, $this->electoral_region);
    }

    $preEntity->addAreaCode($this->area_code);

    if (!empty($this->area_code_descriptor)) {
      $descriptor = $this->area_code .':'. $this->area_code_descriptor;
      $preEntity->addAreaCodeDescriptor($descriptor);
    }
    if (!empty($this->street)) {
      $preEntity->addStreet($this->street);
    }

    $preEntity->validate();
    $preEntity->save();
  }

  public function validate() {
    $this->validateRequiredFields();

    // check if parliament is a term
    $parliament = taxonomy_term_load($this->parliament);
    if (!$parliament || !isset($parliament->vocabulary_machine_name) || $parliament->vocabulary_machine_name != 'parliaments') {
      $this->setValidationError('parliament', 'The set parliament can not be found in the system.');
    }

    // check if constituency is a string
    if (!is_string($this->constituency)) {
      $this->setValidationError('constituency', 'The name of the constituency needs to be a string.');
    }

    // check if electoral_region is a term
    $electoral_region = taxonomy_term_load($this->electoral_region);
    if (!$electoral_region || !isset($electoral_region->vocabulary_machine_name) || $electoral_region->vocabulary_machine_name != 'electoral_region') {
      $this->setValidationError('electoral_region', 'The set electoral region can not be found in the system.');
    }

    // check if constituency number is a numeric
    if (!is_numeric($this->constituency_nr)) {
      $this->setValidationError('constituency_nr', 'No valid number for the constituency.');
    }

    // check if area code is a valid postal code
    // taken from http://www.pixelenvision.com/1708/zip-postal-code-validation-regex-php-code-for-12-countries/
    if (!preg_match("/\b((?:0[1-46-9]\d{3})|(?:[1-357-9]\d{4})|(?:[4][0-24-9]\d{3})|(?:[6][013-9]\d{3}))\b/i",$this->area_code)) {
      $this->setValidationError('area_code', 'No valid area code found.');
    }

    // avoid comma in descriptor as by now we store each descriptor in a text field
    // selerated by comma
    if( strpos($this->area_code_descriptor, ',') !== false ) {
      $this->setValidationError('area_code_descriptor', 'There is a comma in the area code descriptor - which needs to be avoided.');
    }

    // check if street is a string if set
    if ($this->street && !is_string($this->street)) {
      $this->setValidationError('street', 'Street needs to be a string.');
    }
  }

  protected function validateRequiredFields() {
    foreach (self::getFieldsInCSV() as $fieldname => $info) {
      if ($info['required'] && ($this->{$fieldname} === NULL || empty($this->{$fieldname})) ) {
        $this->setValidationError($fieldname, $fieldname. ' is required');
      }
    }
  }

  public static function getFieldsInCSV() {
    return [
      'constituency' => [
        'required' => TRUE,
        'csv' => TRUE,
        'csv_required' => TRUE
      ],
      'constituency_nr' => [
        'required' => TRUE,
        'csv' => TRUE,
        'csv_required' => TRUE
      ],
      'parliament' => [
        'required' => TRUE,
        'csv' => FALSE,
        'csv_required' => FALSE
      ],
      'electoral_region' => [
        'required' => FALSE,
        'csv' => TRUE,
        'csv_required' => FALSE
      ],
      'area_code' => [
        'required' => TRUE,
        'csv' => TRUE,
        'csv_required' => TRUE
      ],
      'area_code_descriptor' => [
        'required' => FALSE,
        'csv' => TRUE,
        'csv_required' => FALSE
      ],
      'street' => [
        'required' => FALSE,
        'csv' => TRUE,
        'csv_required' => FALSE
      ]
    ];
  }


  public static function createFromCSVArray(array $dataset, Import $import) {
    $importDataSet = new ConstituencyImportDataSet($import->getParliamentId(), $dataset['constituency'], $dataset['constituency_nr'], $dataset['area_code'], $import->getId());

    if (isset($dataset['street']) && !empty($dataset['street'])) {
      $importDataSet->setStreet($dataset['street']);
    }

    if (isset($dataset['area_code_descriptor']) && !empty($dataset['area_code_descriptor'])) {
      $importDataSet->setAreaCodeDescriptor($dataset['area_code_descriptor']);
    }

    if (isset($dataset['electoral_region']) && !empty($dataset['electoral_region'])) {
      $importDataSet->setElectoralRegion($dataset['electoral_region']);
    }

    return $importDataSet;
  }


  protected function toArrayForSaving() {
    $values = [
     'parliament' => $this->parliament,
      'constituency' => $this->constituency,
      'constituency_nr' => $this->constituency_nr,
      'area_code' => $this->area_code,
      'electoral_region' => $this->electoral_region,
      'area_code_descriptor' => $this->area_code_descriptor,
      'street' => $this->street,
      'id' => $this->id,
      'import' => $this->importId,
      'status' => $this->status,
      'errors' => json_encode($this->errors)
    ];

    return $values;
  }

  public static function getDatabaseTable() {
    return 'pw_parliaments_admin_imports_constituencies_datasets';
  }


  public static function load($id) {
    $result = self::loadFromDatabase(self::getDatabaseTable(), array('id' => $id));
    if (!empty($result)) {
      $errors = json_decode($result['errors']);
      return new ConstituencyImportDataSet($result['parliament'], $result['constituency'], $result['constituency_nr'], $result['area_code'], $result['electoral_region'], $result['area_code_descriptor'], $result['street'], $result['id'], $result['iimport'], $result['status'], $errors);
    }
    else {
      return NULL;
    }
  }

  public function save($table = NULL) {
    $this->saveToDatabase(self::getDatabaseTable());
  }

  public function getLabel() {
    return $this->constituency;
  }
}