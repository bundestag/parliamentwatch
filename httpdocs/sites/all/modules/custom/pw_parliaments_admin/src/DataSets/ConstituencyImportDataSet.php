<?php

namespace Drupal\pw_parliaments_admin\DataSets;


use Drupal\pw_parliaments_admin\Entity\EntityBase;
use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\ImportDataSetInterface;
use Drupal\pw_parliaments_admin\Status\DataSetStatus;
use EntityFieldQuery;


class ConstituencyImportDataSet  extends EntityBase implements ImportDataSetInterface {

  /**
   * @var int|string|null
   * The unique if the dataset
   */
  protected $id;

  /**
   * @var int|string
   * The parliaments term id
   */
  protected $parliament;

  /**
   * @var string
   * The name of the constituency
   */
  protected $constituency;


  /**
   * @var int|string
   * The number of the constituency
   */
  protected $constituency_nr;


  /**
   * @var string
   * The name of the electoral region
   */
  protected $electoral_region;


  /**
   * @var string
   * The zipcode
   */
  protected $area_code;


  /**
   * @var string
   * The descriptor specifying the constituency/ zipcode combination
   */
  protected $area_code_descriptor;


  /**
   * @var string
   * The street specific for the constituency/ zipcode combination
   */
  protected $street;


  /**
   * @var int|string
   * The import the dataset belongs to
   */
  protected $importId;


  /**
   * @var null|string
   * The status of the dataset
   */
  protected $status;


  /**
   * @var string
   * One string defining all errors which were found during
   * validation or import. Each error is seperated by |
   */
  protected $errors;


  /**
   * @var null|int|string
   * The id of the structured data element connected to the dataset
   */
  protected $structuredDataId;

  /**
   * @var \Drupal\pw_parliaments_admin\Import\Import|FALSE
   */
  protected $importClass;


  /**
   * ConstituencyImportDataSet constructor.
   *
   * @param int|string $parliament
   * @param string $constituency
   * @param int $constituency_nr
   * @param string $area_code
   * @param int|string $import_id
   * @param string $electoral_region
   * @param string $area_code_descriptor
   * @param string $street
   * @param null|int|string $id
   * @param null|string $status
   * @param string $errors
   * @param null|int|string $structuredDataId
   */
  public function __construct($parliament, $constituency, $constituency_nr, $area_code, $import_id, $electoral_region = '', $area_code_descriptor = '', $street = '', $id = NULL, $status = NULL, $errors = '', $structuredDataId = NULL) {
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
    $this->structuredDataId = $structuredDataId;
  }


  /**
   * @param string $descriptor
   */
  public function setAreaCodeDescriptor($descriptor) {
    $this->area_code_descriptor = $descriptor;
  }


  /**
   * @param string $electoral_region
   */
  public function setElectoralRegion($electoral_region) {
    $this->electoral_region = $electoral_region;
  }


  /**
   * @param string $street
   */
  public function setStreet($street) {
    $this->street = $street;
  }


  /**
   * Create the structured data from the dataset
   *
   * @return \Drupal\pw_parliaments_admin\DataSets\ConstituencyStructuredData|\Drupal\pw_parliaments_admin\Entity\EntityInterface
   */
  public function createStructuredData() {
    // first we try to load already defined structuredData
    $table = ConstituencyStructuredData::getDatabaseTable();
    $query = db_select($table, 't');
    $query->condition('field_constituency_nr', $this->constituency_nr);
    $query->condition('name', $this->constituency);
    $query->fields('t');
    $result = $query->execute()->fetchAssoc();

    if (!empty(($result))) {
      $structuredData = ConstituencyStructuredData::createFromDataBaseArray($result);
    }
    else {
      $structuredData = new ConstituencyStructuredData($this->constituency, $this->parliament, $this->constituency_nr, $this->importId, $this->electoral_region);
    }

    $structuredData->addAreaCode($this->area_code);

    if (!empty($this->area_code_descriptor)) {
      $descriptor = $this->area_code .':'. $this->area_code_descriptor;
      $structuredData->addAreaCodeDescriptor($descriptor);
    }
    if (!empty($this->street)) {
      $structuredData->addStreet($this->street);
    }

    $structuredData->validate();
    $structuredData->save();

    return $structuredData;
  }


  /**
   * Validate the dataset. When an error appears $this->setValidationError()
   * should be called
   */
  public function validate() {
    $this->validateRequiredFields();

    // check if parliament is a term
    $parliament = taxonomy_term_load($this->parliament);
    if (!$parliament || !isset($parliament->vocabulary_machine_name) || $parliament->vocabulary_machine_name != 'parliaments') {
      $this->setValidationError('The set parliament can not be found in the system.');
    }

    // check if constituency is a string
    if (!is_string($this->constituency)) {
      $this->setValidationError('The name of the constituency needs to be a string.');
    }

    // check if electoral_region is a term related to the parliament
    if (!empty($this->electoral_region)) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'taxonomy_term')
        ->entityCondition('bundle', 'electoral_region')
        ->fieldCondition('field_parliament', 'tid', $this->parliament)
        ->addMetaData('account', user_load(1));
      $result = $query->execute();
      if (!isset($result['taxonomy_term'])) {
        $this->setValidationError('The set electoral region can not be found in the system.');
      }
    }


    // check if constituency number is a numeric
    if (!is_numeric($this->constituency_nr)) {
      $this->setValidationError('No valid number for the constituency.');
    }

    // check if area code is a valid postal code
    // taken from http://www.pixelenvision.com/1708/zip-postal-code-validation-regex-php-code-for-12-countries/
    if (!preg_match("/\b((?:0[1-46-9]\d{3})|(?:[1-357-9]\d{4})|(?:[4][0-24-9]\d{3})|(?:[6][013-9]\d{3}))\b/i",$this->area_code)) {
      $this->setValidationError('No valid area code found.');
    }

    // avoid comma in descriptor as by now we store each descriptor in a text field
    // selerated by comma
    if( strpos($this->area_code_descriptor, ',') !== false ) {
      $this->setValidationError('There is a comma in the area code descriptor - which needs to be avoided.');
    }

    // check if street is a string if set
    if ($this->street && !is_string($this->street)) {
      $this->setValidationError('Street needs to be a string.');
    }

    if ($this->hasErrors()) {
      $this->setStatus(DataSetStatus::ERROR);
    }
    else {
      $this->setStatus(DataSetStatus::OK);
    }
  }


  /**
   * Set the status of the dataset
   *
   * @param string $new_status
   */
  public function setStatus($new_status) {
    $possibleStatus = DataSetStatus::getPossibleOptions();
    if (array_key_exists($new_status, $possibleStatus)) {
      $this->status = $new_status;
    }
  }


  /**
   * Helper to check if required fields are set
   */
  protected function validateRequiredFields() {
    foreach (self::getFieldsInCSV() as $fieldname => $info) {
      if ($info['required'] && ($this->{$fieldname} === NULL || empty($this->{$fieldname})) ) {
        $this->setValidationError($fieldname. ' is required');
      }
    }
  }


  /**
   * Defines the fields which are used from a CSV
   *
   * @return array
   */
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


  /**
   *
   * Create a Dataset entity from an array fetched from CSV
   *
   * @param array $dataset
   * @param \Drupal\pw_parliaments_admin\Import\Import $import
   *
   * @return \Drupal\pw_parliaments_admin\DataSets\ConstituencyImportDataSet|\Drupal\pw_parliaments_admin\ImportDataSetInterface
   */
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
      'errors' => $this->errors,
      'structured_data_id' => $this->structuredDataId
    ];


    return $values;
  }

  public static function getDatabaseTable() {
    return 'pw_parliaments_admin_imports_constituencies_datasets';
  }

  public static function getStructuredDataClassName() {
    return '\Drupal\pw_parliaments_admin\DataSets\ConstituencyStructuredData';
  }


  public static function load($id) {
    $result = self::loadFromDatabase(self::getDatabaseTable(), array('id' => $id));
    if (!empty($result)) {
      return self::createFromDataBaseArray($result);
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

  public static function createFromDataBaseArray(array $database_data) {
    return new ConstituencyImportDataSet($database_data['parliament'], $database_data['constituency'], $database_data['constituency_nr'], $database_data['area_code'], $database_data['import'], $database_data['electoral_region'], $database_data['area_code_descriptor'], $database_data['street'], $database_data['id'], $database_data['status'], $database_data['errors'], $database_data['structured_data_id']);
  }

  /**
   * Set a validation error on a field
   *
   * @param $error
   */
  public function setValidationError($error) {
    if (empty($this->errors)) {
      $this->errors = $error;
    }
    else {
      $this->errors .= ' | ' . $error;
    }

  }

  public function getValidationErrors() {
    return $this->errors;
  }

  public function hasErrors() {
    return (!empty($this->getValidationErrors()));
  }


  public function delete() {
    $transaction = db_transaction();
    try {
      db_delete(self::getDatabaseTable())
        ->condition('id', $this->id)
        ->execute();

      // delete all related structured data
      $structuredData = self::getStructuredDataClassName()::load($this->structuredDataId);
      if ($structuredData) {
        $structuredData->delete();
      }
    }
    catch (\Exception $e) {
      $transaction->rollback();
      throw $e;
    }
  }

  public function setStructuredDataId($id = NULL) {
    $this->structuredDataId = $id;
  }


  public function getId() {
    return $this->id;
  }
}