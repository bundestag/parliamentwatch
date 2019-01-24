<?php


namespace Drupal\pw_parliaments_admin\DataSets;


use Drupal\pw_parliaments_admin\Entity\EntityBase;
use Drupal\pw_parliaments_admin\Exception\ImportException;
use Drupal\pw_parliaments_admin\Status\DataSetStatus;
use Drupal\pw_parliaments_admin\StructuredDataInterface;
use EntityFieldQuery;

class ConstituencyStructuredData extends EntityBase implements StructuredDataInterface {

  protected $id;

  protected $name;

  protected $field_parliament;

  protected $field_constituency_nr;

  protected $field_constituency_area_codes = [];

  protected $field_constituency_ac_descriptor = [];

  protected $field_constituency_street = [];

  protected $field_electoral_region;

  protected $entityId;

  protected $import;

  protected $errors;

  protected $status;

  public function __construct($name, $field_parliament, $field_constituency_nr, $import, $field_electoral_region = '', array $field_constituency_area_codes = array(), array $field_constituency_ac_descriptors = array(), array $field_constituency_streets = array(), $id = NULL, $erros = '', $status = '') {
    $this->id = $id;
    $this->name = $name;
    $this->field_parliament = $field_parliament;
    $this->field_constituency_nr = $field_constituency_nr;
    $this->field_constituency_area_codes = $field_constituency_area_codes;
    $this->field_constituency_ac_descriptor = $field_constituency_ac_descriptors;
    $this->field_constituency_street = $field_constituency_streets;
    $this->field_electoral_region = $field_electoral_region;
    $this->import = $import;
    $this->errors = $erros;
    $this->status = $status;
  }



  protected function toArrayForSaving() {
    return [
      'name' => $this->name,
      'field_parliament' => $this->field_parliament,
      'field_constituency_nr' => $this->field_constituency_nr,
      'field_constituency_area_codes' => implode(',', $this->field_constituency_area_codes),
      'field_constituency_ac_descriptor' => implode(',', $this->field_constituency_ac_descriptor),
      'field_constituency_street' => implode(',', $this->field_constituency_street),
      'field_electoral_region' => $this->field_electoral_region,
      'import' => $this->import,
      'errors' => $this->errors,
      'status' => $this->status
    ];
  }

  public function addAreaCode($area_code) {
    if (!in_array($area_code, $this->field_constituency_area_codes)) {
      $this->field_constituency_area_codes[] = $area_code;
    }
  }

  public function addStreet($street) {
    if (!in_array($street, $this->field_constituency_street)) {
      $this->field_constituency_street[] = $street;
    }
  }

  public function addAreaCodeDescriptor($descriptor) {
    if (!in_array($descriptor, $this->field_constituency_ac_descriptor)) {
      $this->field_constituency_ac_descriptor[] = $descriptor;
    }
  }

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

  public static function getDatabaseTable() {
    return 'pw_parliaments_admin_imports_constituencies_structured';
  }

  public static function getDataSetClassName() {
    return '\Drupal\pw_parliaments_admin\DataSets\ConstituencyImportDataSet';
  }

  public static function load($id) {
    $result = self::loadFromDatabase(self::getDatabaseTable(), ['id' => $id]);
    if (!empty($result)) {
      return self::createFromDataBaseArray($result);
    }

    return NULL;
  }

  public function getLabel() {
    return $this->name;
  }




  public static function createFromDataBaseArray(array $database_data) {
    if (!empty($database_data["field_constituency_area_codes"])) {
      $database_data["field_constituency_area_codes"] = explode(',', $database_data["field_constituency_area_codes"]);
    }
    else {
      $database_data["field_constituency_area_codes"] = [];
    }
    if (!empty($database_data["field_constituency_ac_descriptor"])) {
      $database_data["field_constituency_ac_descriptor"] = explode(',', $database_data["field_constituency_ac_descriptor"]);
    }
    else {
      $database_data["field_constituency_ac_descriptor"] = [];
    }

    if (!empty($database_data["field_constituency_street"])) {
      $database_data["field_constituency_street"] = explode(',', $database_data["field_constituency_street"]);
    }
    else {
      $database_data["field_constituency_street"] = [];
    }

    return new ConstituencyStructuredData($database_data["name"], $database_data["field_parliament"], $database_data["field_constituency_nr"], $database_data["import"], $database_data["field_electoral_region"], $database_data["field_constituency_area_codes"], $database_data["field_constituency_ac_descriptor"], $database_data["field_constituency_street"], $database_data["id"], $database_data["errors"], $database_data["status"]);
  }

  public function save() {
    $this->saveToDatabase(self::getDatabaseTable());
  }

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

  public function getRelatedDataSets() {
    $datasets = [];

    /** @var \Drupal\pw_parliaments_admin\DataSets\ConstituencyImportDataSet $datasetClass */
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


  public function getId() {
    return $this->id;
  }

  public function setEntityId($id) {
   $this->entityId = $id;
  }

  public function setEntityRevisionVid($vid) {
  }


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
      $newConstituency->field_constituency_area_codes[LANGUAGE_NONE][]['tid'] = $areaCodeTerm->tid;
    }

    $newConstituency->field_constituency_ac_descriptor[LANGUAGE_NONE][0]['value'] = $this->field_constituency_ac_descriptor;

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


    $parliament = taxonomy_get_term_by_name($this->field_parliament, 'parliaments');
    if (!$parliament) {
      throw new ImportException('No parliament found for '. $this->field_parliament);
    }
    $newConstituency->field_parliament[LANGUAGE_NONE][0]['tid'] = $parliament->tid;

    taxonomy_term_save($newConstituency);

    $this->setEntityId($newConstituency->tid);
    $this->save();
    $datasets = $this->getRelatedDataSets();
    foreach ($datasets as $dataSet) {
      $dataSet->setStatus(DataSetStatus::IMPORTED);
      $datasets->save();
    }
  }
}