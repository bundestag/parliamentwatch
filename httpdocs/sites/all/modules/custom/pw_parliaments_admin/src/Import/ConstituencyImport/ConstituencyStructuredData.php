<?php


namespace Drupal\pw_parliaments_admin\Import\ConstituencyImport;


use Drupal\pw_globals\Parliament;
use Drupal\pw_parliaments_admin\PWEntity\EntityBase;
use Drupal\pw_parliaments_admin\Exception\ImportException;
use Drupal\pw_parliaments_admin\Status\DataSetStatus;
use Drupal\pw_parliaments_admin\Import\Interfaces\StructuredDataInterface;
use Drupal\pw_parliaments_admin\Status\StructuredDataStatus;
use EntityFieldQuery;


/**
 * This class represents the step just before the constituency is imported as a
 * term into Drupal. It has the same fields as the later term
 */
class ConstituencyStructuredData extends EntityBase implements StructuredDataInterface {

  /**
   * @var null|int|string
   * The unique id of the structured data
   */
  protected $id;


  /**
   * @var string
   * The constituency name
   */
  protected $name;


  /**
   * @var int|string
   * The parliament term id
   */
  protected $field_parliament;

  /**
   * @var int|string
   * The constituency number
   */
  protected $field_constituency_nr;

  /**
   * @var array
   * An array of zip codes
   */
  protected $field_constituency_area_codes = [];

  /**
   * @var array 
   * An array of zipcode descriptors
   * 
   */
  protected $field_constituency_ac_descriptor = [];


  /**
   * @var array
   * an array of street names
   */
  protected $field_constituency_street = [];


  /**
   * @var string 
   * The electoral region name connected to the constituency
   */
  protected $field_electoral_region;


  /**
   * @var int|string|\Psr\Log\Null 
   * The term tid of the term created on import
   */
  protected $entityId;


  /**
   * @var int|string
   * The import id
   */
  protected $import;


  /**
   * @var string 
   * Errors which appeared during import, delimited by |
   */
  protected $errors;


  /**
   * @var string 
   * The status of the structured data
   */
  protected $status;


  /**
   * ConstituencyStructuredData constructor.
   */
  public function __construct($name, $field_parliament, $field_constituency_nr, $import, $field_electoral_region = '', array $field_constituency_area_codes = array(), array $field_constituency_ac_descriptors = array(), array $field_constituency_streets = array(), $id = NULL, $errors = '', $status = '') {
    $this->id = $id;
    $this->name = $name;
    $this->field_parliament = $field_parliament;
    $this->field_constituency_nr = $field_constituency_nr;
    $this->field_constituency_area_codes = $field_constituency_area_codes;
    $this->field_constituency_ac_descriptor = $field_constituency_ac_descriptors;
    $this->field_constituency_street = $field_constituency_streets;
    $this->field_electoral_region = $field_electoral_region;
    $this->import = $import;
    $this->errors = $errors;
    if (empty($status)) {
      $this->status = StructuredDataStatus::OK;
    }
    else {
      $this->status = $status;
    }
  }


  /**
   * Turn the class into an array suitbale for saving to database
   * 
   * @return array
   */
  protected function toArrayForSaving() {
    return [
      'name' => $this->name,
      'field_parliament' => $this->field_parliament,
      'field_constituency_nr' => $this->field_constituency_nr,
      'field_constituency_area_codes' => implode(', ', $this->field_constituency_area_codes),
      'field_constituency_ac_descriptor' => implode(', ', $this->field_constituency_ac_descriptor),
      'field_constituency_street' => implode(', ', $this->field_constituency_street),
      'field_electoral_region' => $this->field_electoral_region,
      'import' => $this->import,
      'errors' => $this->errors,
      'status' => $this->status
    ];
  }


  /**
   * Add an area code
   * 
   * @param string $area_code
   */
  public function addAreaCode($area_code) {
    if (!in_array($area_code, $this->field_constituency_area_codes)) {
      $this->field_constituency_area_codes[] = $area_code;
    }
  }


  /**
   * Add a street name
   * 
   * @param string $street
   */
  public function addStreet($street) {
    if (!in_array($street, $this->field_constituency_street)) {
      $this->field_constituency_street[] = $street;
    }
  }


  /**
   * Add an area code descriptor in the form '12345 - downtown'
   * @param string $descriptor
   */
  public function addAreaCodeDescriptor($descriptor) {
    if (!in_array($descriptor, $this->field_constituency_ac_descriptor)) {
      $this->field_constituency_ac_descriptor[] = $descriptor;
    }
  }


  /**
   * Validate the structured data
   */
  public function validate() {
    // check if parliament is a term
    $parliament = taxonomy_term_load($this->field_parliament);
    if (!$parliament || !isset($parliament->vocabulary_machine_name) || $parliament->vocabulary_machine_name != 'parliaments') {
      $this->setValidationError('The set parliament can not be found in the system.');
    }

    // check if name is a string
    if (!is_string($this->name)) {
      $this->setValidationError('The name of the constituency needs to be a string.');
    }


    // check if electoral_region is a term related to the parliament
    if (!empty($this->field_electoral_region)) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'taxonomy_term')
        ->entityCondition('bundle', 'electoral_region')
        ->fieldCondition('field_parliament', 'tid', $this->field_parliament)
        ->addMetaData('account', user_load(1));
      $result = $query->execute();
      if (!isset($result['taxonomy_term'])) {
        $this->setValidationError('The set electoral region can not be found in the system.');
      }
    }

    // check if constituency number is a numeric
    if (!is_numeric($this->field_constituency_nr)) {
      $this->setValidationError('No valid number for the constituency.');
    }

  }


  /**
   * Set a validation error
   * 
   * @param string $error
   */
  public function setValidationError($error) {
    if (empty($this->errors)) {
      $this->errors = $error;
    }
    else {
      $this->errors .= ' | ' . $error;
    }

  }


  /**
   * @return string
   * All errors delimited by |
   */
  public function getValidationErrors() {
    return $this->errors;
  }


  /**
   * Checks if error appeared during validation
   * 
   * @return bool
   */
  public function hasErrors() {
    return (!empty($this->getValidationErrors()));
  }


  /**
   * Get the name of the database table where structured data is stored
   * 
   * @return string
   */
  public static function getDatabaseTable() {
    return 'pw_parliaments_admin_imports_constituencies_structured';
  }


  /**
   * Get the fully PSR-4 class name of tghe corresponding dataset class
   * 
   * @return string
   */
  public static function getDataSetClassName() {
    return '\Drupal\pw_parliaments_admin\Import\ConstituencyImport\ConstituencyImportDataSet';
  }


  /**
   * Load structured data by it's unique id
   * 
   * @param int|string $id
   *
   * @return \Drupal\pw_parliaments_admin\Import\ConstituencyImport\ConstituencyStructuredData|NULL
   */
  public static function load($id) {
    $result = self::loadFromDatabase(self::getDatabaseTable(), ['id' => $id]);
    if (!empty($result)) {
      return self::createFromDataBaseArray($result);
    }

    return NULL;
  }


  /**
   * Get the label
   * 
   * @return string
   */
  public function getLabel() {
    return $this->name;
  }


  /**
   * Create a new structured data instance from a db_select result array
   * 
   * @param array $database_data
   *
   * @return \Drupal\pw_parliaments_admin\Import\ConstituencyImport\ConstituencyStructuredData
   * 
   */
  public static function createFromDataBaseArray(array $database_data) {
    if (!empty($database_data["field_constituency_area_codes"])) {
      $database_data["field_constituency_area_codes"] = explode(', ', $database_data["field_constituency_area_codes"]);
    }
    else {
      $database_data["field_constituency_area_codes"] = [];
    }
    if (!empty($database_data["field_constituency_ac_descriptor"])) {
      $database_data["field_constituency_ac_descriptor"] = explode(', ', $database_data["field_constituency_ac_descriptor"]);
    }
    else {
      $database_data["field_constituency_ac_descriptor"] = [];
    }

    if (!empty($database_data["field_constituency_street"])) {
      $database_data["field_constituency_street"] = explode(', ', $database_data["field_constituency_street"]);
    }
    else {
      $database_data["field_constituency_street"] = [];
    }

    return new ConstituencyStructuredData($database_data["name"], $database_data["field_parliament"], $database_data["field_constituency_nr"], $database_data["import"], $database_data["field_electoral_region"], $database_data["field_constituency_area_codes"], $database_data["field_constituency_ac_descriptor"], $database_data["field_constituency_street"], $database_data["id"], $database_data["errors"], $database_data["status"]);
  }


  /**
   * Save the current object to the database
   * 
   * @throws \Exception
   */
  public function save() {
    $this->saveToDatabase(self::getDatabaseTable());
  }


  /**
   * Delete the data for the current object from database
   * 
   * @throws \Exception
   */
  public function delete() {
    $transaction = db_transaction();
    try {
      db_delete(self::getDatabaseTable())
        ->condition('id', $this->id)
        ->execute();

      // delete the id from dataset table
      $datasets = $this->getRelatedDataSets();
      foreach ($datasets as $dataset) {
        $dataset->setStructuredDataId();
        $dataset->save();
      }
    }
    catch (\Exception $e) {
      $transaction->rollback();
      throw $e;
    }
  }


  /**
   * Get the related datasets for the current structured data
   * 
   * @return array|\Drupal\pw_parliaments_admin\Import\Interfaces\ImportDataSetInterface[]
   */
  public function getRelatedDataSets() {
    $datasets = [];

    /** @var \Drupal\pw_parliaments_admin\Import\ConstituencyImport\ConstituencyImportDataSet $datasetClass */
    $datasetClass = self::getDataSetClassName();
    $query = db_select($datasetClass::getDatabaseTable(), 't')
      ->condition('structured_data_id', $this->getId())
      ->fields('t');
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $datasets[] = $datasetClass::createFromDataBaseArray($record);
    }

    return $datasets;
  }


  /**
   * Get the unique id
   * 
   * @return int|string|null
   */
  public function getId() {
    return $this->id;
  }


  /**
   * set the term tid of the term created on import
   * @param int|string $id
   */
  public function setEntityId($id) {
   $this->entityId = $id;
  }


  /**
   * set the revision vid - not needed for constituency imports
   * @param $vid
   */
  public function setEntityRevisionVid($vid) {
  }


  /**
   * Set the status of the dataset
   *
   * @param string $new_status
   */
  public function setStatus($new_status) {
    $possibleStatus = StructuredDataStatus::getPossibleOptions();
    if (array_key_exists($new_status, $possibleStatus)) {
      $this->status = $new_status;
    }
  }


  /**
   * Reset the status when an import starts
   */
  public function resetStatus() {
    $this->status = StructuredDataStatus::OK;
  }


  /**
   * Actually import the structured data for the constituency into
   * a Drupal term
   * 
   * @throws \Drupal\pw_parliaments_admin\Exception\ImportException
   */
  public function import() {
    $vid = 17;   // vid of vocabulary "constituencies"
    $newConstituency = new \stdClass();
    $newConstituency->name = $this->name;
    $newConstituency->vid = $vid;
    $newConstituency->field_constituency_nr[LANGUAGE_NONE][0]['value'] = $this->field_constituency_nr;

    // add the area codes as terms
    foreach ($this->field_constituency_area_codes as $area_code) {
      $areaCodeTerm = taxonomy_get_term_by_name($area_code, 'area_codex');
      if (!$areaCodeTerm) {
        $vid_area_codes = 14;   // vid of vocabulary "area_codex"
        $areaCodeTerm = new \stdClass();
        $areaCodeTerm->name = $area_code;
        $areaCodeTerm->vid = $vid_area_codes;
        taxonomy_term_save($areaCodeTerm);
      }
      else {
        $areaCodeTerm = reset($areaCodeTerm);
      }
      $newConstituency->field_constituency_area_codes[LANGUAGE_NONE][]['tid'] = $areaCodeTerm->tid;
    }

    if (!empty($this->field_constituency_ac_descriptor)) {
      $newConstituency->field_constituency_ac_descriptor[LANGUAGE_NONE][0]['value'] = implode(', ', $this->field_constituency_ac_descriptor);
    }

    foreach ($this->field_constituency_street as $street) {
      $newConstituency->field_constituency_street[LANGUAGE_NONE][]['value'] = $street;
    }

    if (!empty($this->field_electoral_region)) {
      $electoralRegion = taxonomy_get_term_by_name($this->field_electoral_region, 'electoral_region');
      if (!$electoralRegion) {
        throw new ImportException('No electoral region found for '. $this->field_electoral_region);
      }
      $newConstituency->field_electoral_region[LANGUAGE_NONE][0]['tid'] = $electoralRegion->tid;
    }


    $parliament = taxonomy_term_load($this->field_parliament);
    if (!$parliament || !isset($parliament->tid) || $parliament->vid != Parliament::VOCABULARY_VID) {
      throw new ImportException('No parliament found for '. $this->field_parliament);
    }
    $newConstituency->field_parliament[LANGUAGE_NONE][0]['tid'] = $parliament->tid;

    taxonomy_term_save($newConstituency);

    $this->setEntityId($newConstituency->tid);
    $this->setStatus(StructuredDataStatus::IMPORTED);
    $this->save();
    $datasets = $this->getRelatedDataSets();
    if (!empty($datasets)) {
      foreach ($datasets as $dataSet) {
        $dataSet->setStatus(DataSetStatus::IMPORTED);
        $dataSet->save();
      }
    }

  }
}