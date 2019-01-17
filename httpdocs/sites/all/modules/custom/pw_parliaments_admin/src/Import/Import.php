<?php


namespace Drupal\pw_parliaments_admin\Import;

use Drupal\pw_parliaments_admin\CsvParser;
use Drupal\pw_parliaments_admin\Entity\EntityBase;
use Drupal\pw_parliaments_admin\ImportTypes;
use Drupal\pw_parliaments_admin\Status\ImportStatus;

/**
 * Base class for Import type classes.
 */

class Import extends EntityBase {

  /**
   * @var int
   * The unique id of the import
   */
  protected $id;


  /**
   * @var null|string
   * A label for the import
   */
  protected $label = NULL;


  /**
   * @var int|string
   * The term id of the parliament
   */
  protected $parliamentId;


  /**
   * @var int|string
   * The Drupal file id of the CSV
   */
  protected $fileId;


  /**
   * @var object|NULl|FALSE
   * The loaded Drupal file entity for the CSV. If the file was not
   * loaded yet the value is NULL. If we tried to load the file with
   * no success it is FALSE.
   */
  protected $file = NULL;

  /**
   * @var null|string
   * The type of import - describes what kind of data will be imported
   */
  protected $type = NULL;

  /**
   * @var string
   * The status of the import
   */
  protected $status = ImportStatus::NOT_IMPORTED;


  /**
   * @var null|\Drupal\pw_parliaments_admin\ImportTypeInterface
   */
  protected $importTypeClass = NULL;


  public function __construct($label, $parliamentId, $fileId , $type, $status = NULL, $id = NULL) {
    $this->id = $id;
    $this->label = $label;
    $this->parliamentId = $parliamentId;
    $this->fileId = $fileId;
    if ($status !== NULL) {
      $this->status = $status;
    }
    $this->type = $type;

    if (is_string($this->type)) {
      $this->importTypeClass = ImportTypes::getClass($this->type);
    }
  }

  /**
   * @return \Drupal\pw_parliaments_admin\CsvParser
   */
  public function getCSVParser() {
    try {
      return new CsvParser($this->getLoadFile());
    }
    catch (\Exception $e) {
      drupal_set_message('It was not possible to get the CSV parser', 'error');
      watchdog_exception('pw_parliaments_admin', $e);
    }
  }


  /**
   * @return FALSE|object
   */
  public function getLoadFile() {
    if (!is_null($this->file)) {
      return $this->file;
    }
    elseif (is_numeric($this->fileId)) {
      $this->file = file_load($this->fileId);
      return $this->file;
    }

    $this->file = FALSE;
    return FALSE;
  }


  public function getFileId() {
    if (is_numeric($this->fileId)) {
      return $this->fileId;
    }
    return '';
  }

  public function setFileId($file_id) {
    $this->fileId = $file_id;
  }

  /**
   * @return mixed
   */
  public function getParliamentId() {
    return $this->parliamentId;
  }

  /**
   * @param mixed $parliamentId
   */
  public function setParliamentId($parliamentId) {
    $this->parliamentId = $parliamentId;
  }

  /**
   * @return FALSE|NULl|object
   */
  public function getFile() {
    return $this->file;
  }

  /**
   * @param object $file
   */
  public function setFile( $file) {
    if (!is_object($file) && !isset($file->fid)) {
      return;
    }
    $this->file = $file;
    $this->setFileId($file->fid);
  }

  /**
   * @return string|null
   */
  public function getLabel() {
    return $this->label;
  }

  /**
   * @param string $label
   */
  public function setLabel(string $label) {
    $this->label = $label;
  }


  /**
   * @return string|null
   */
  public function getType() {
    return $this->type;
  }

  /**
   * @param string|null $type
   */
  public function setType(string $type) {
    $this->type = $type;
  }


  /**
   * @return \Drupal\pw_parliaments_admin\ImportTypeInterface|null
   */
  public function getImportTypeClass() {
    if ($this->importTypeClass != NULL) {
      return $this->importTypeClass;
    }

    if(is_string($this->type)) {
      $this->importTypeClass = ImportTypes::getClass($this->type);
    }

    return $this->importTypeClass;
  }

  /**
   * @return mixed
   */
  public function getId() {
    return $this->id;
  }


  /**
   * @return string|null
   */
  public function getStatus() {
    return $this->status;
  }

  public static function possibleStatus() {
    return [
      'created' => t('Created'),
      'review' => t('Needs review'),
      'ok' => t('Can be imported'),
      'imported' => t('Imported')
    ];
  }

  /**
   * @param string $status
   */
  public function setStatus($status) {
    $this->status = $status;
  }


  public static function load($id) {
    $result = self::loadFromDatabase(self::getDatabaseTable(), array('id' => $id));
    if (!empty($result)) {
      return new Import($result['label'], $result['parliament'], $result['file'], $result['type'], $result['status'], $result['id']);
    }
    else {
      return NULL;
    }
  }


  /**
   * Save the Import entity and update the CSV file
   *
   * @throws \Exception
   */
  public function save() {
    $transaction = db_transaction();
    try {
      $this->saveToDatabase(self::getDatabaseTable());
      $this->updateFile();
    }
    catch (\Exception $e) {
      $transaction->rollback();
      watchdog_exception('pw_parliaments_admin', $e);
      drupal_set_message('An error appeared during saving an Import: '. $e->getMessage());
      throw $e;
    }
  }


  /**
   * Update the CSV file related to the Import entity
   */
  protected function updateFile() {
    if (is_numeric($this->getFileId())) {
      $csv = $this->getFile();

      // if the file was not saved permanently yet we change that here
      if (!$csv->status) {
        $picture_directory =  'private://pw-import';

        // Prepare the pictures directory.
        file_prepare_directory($picture_directory, FILE_CREATE_DIRECTORY);
        $destination = file_stream_wrapper_uri_normalize($picture_directory . '/'.$csv->filename);

        // Move the temporary file into the final location.
        if ($csv = file_move($csv, $destination, FILE_EXISTS_RENAME)) {
          $csv->status = FILE_STATUS_PERMANENT;
          file_save($csv);
          $this->setFile($csv);
          file_usage_add($csv, 'pw_parliaments_admin', 'import', $this->getId());
        }
      }
    }

  }


  /**
   * @return array
   * An array of field names which need to be found in import
   */
  public function getRequiredFieldsForCSV() {
    return $this->getImportTypeClass()->getRequiredFieldsForCSV();
  }


  /**
   * Create a new ImportDataSet from an array parsed from the CSV.
   *
   * As we do not know anything here about the actual dataset we simply
   * call createNewDataSet() on the ImportTypeClass which manages the
   * ImportDataSet classes.
   *
   * @param array $dataSet
   *
   *
   */
  public function createNewImportDataSet(array $dataSet) {
    $importType = $this->getImportTypeClass();
    return $importType->createNewImportDataSet($dataSet, $this);
  }



  protected function toArrayForSaving() {
    return [
      'label' => $this->label,
      'parliament' => $this->parliamentId,
      'file' => $this->fileId,
      'type' => $this->type,
      'status' => $this->status,
      'id' => $this->id
    ];
  }


  /**
   * Check if all required fields for the import are set in CSV
   *
   * @return bool
   */
  public function AllRequiredFieldsExist() {
    $required_fields = $this->getRequiredFieldsForCSV();
    $csvHeader = $this->getCSVParser()->getHeader();
    foreach ($required_fields as $required_field) {
      if (!in_array($required_field, $csvHeader)) {
        return FALSE;
      }
    }

    return TRUE;
  }

  public static function getDatabaseTable() {
    return 'pw_parliaments_admin_imports';
  }
}