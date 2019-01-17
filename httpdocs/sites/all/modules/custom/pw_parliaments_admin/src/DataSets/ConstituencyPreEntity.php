<?php


namespace Drupal\pw_parliaments_admin\DataSets;


use Drupal\pw_parliaments_admin\Entity\EntityBase;
use Drupal\pw_parliaments_admin\PreEntityInterface;

class ConstituencyPreEntity extends EntityBase implements PreEntityInterface {

  protected $id;

  protected $name;

  protected $field_parliament;

  protected $field_constituency_nr;

  protected $field_constituency_area_codes;

  protected $field_constituency_ac_descriptor;

  protected $field_constituency_street;

  protected $field_electoral_region;


  public function __construct($name ='', $field_parliament ='', $field_constituency_nr ='', $field_electoral_region = '', $field_constituency_area_codes = array(), $field_constituency_ac_descriptor = array(), $field_constituency_street = array(), $id = NULL) {
    $this->id = $id;
    $this->name = $name;
    $this->field_parliament = $field_parliament;
    $this->field_constituency_nr = $field_constituency_nr;
    $this->field_constituency_area_codes = $field_constituency_area_codes;
    $this->field_constituency_ac_descriptor = $field_constituency_ac_descriptor;
    $this->field_constituency_street = $field_constituency_street;
    $this->field_electoral_region = $field_electoral_region;
  }



  protected function toArrayForSaving() {
    return [
      'name' => $this->name,
      'field_parliament' => $this->field_parliament,
      'field_constituency_nr' => $this->field_constituency_nr,
      'field_constituency_area_codes' => implode(',', $this->field_constituency_area_codes),
      'field_constituency_ac_descriptor' => implode(',', $this->field_constituency_ac_descriptor),
      'field_constituency_street' => implode(',', $this->field_constituency_street),
      'field_electoral_region' => $this->field_electoral_region
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

  public function validate($revalidate = FALSE) {
    // TODO: Implement validate() method.
  }

  public function getValidationErrors() {
    // TODO: Implement getValidationErrors() method.
  }

  public static function getDatabaseTable() {
    return 'pw_parliaments_admin_imports_constituencies_preentities';
  }



  public static function load($id) {
    $result = self::loadFromDatabase(self::getDatabaseTable(), array('id' => $id));
    if (!empty($result)) {
      $area_codes = [];
      if (!empty($data_array["field_constituency_area_codes"])) {
        $area_codes = explode(',', $data_array["field_constituency_area_codes"]);
      }

      $descriptors = [];
      if (!empty($data_array["field_constituency_ac_descriptor"])) {
        $descriptors = explode(',', $data_array["field_constituency_ac_descriptor"]);
      }

      $streets = [];
      if (!empty($data_array["field_constituency_street"])) {
        $streets = explode(',', $data_array["field_constituency_street"]);
      }

      return new ConstituencyPreEntity($data_array["name"], $data_array["field_parliament"], $data_array["field_constituency_nr"], $data_array["field_electoral_region"], $area_codes, $descriptors, $streets, $data_array["id"]);
    }
    else {
      return NULL;
    }
  }

  public function save($table = NULL) {
    $this->saveToDatabase(self::getDatabaseTable());
  }
}