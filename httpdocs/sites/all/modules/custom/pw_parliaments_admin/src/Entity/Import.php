<?php


namespace Drupal\pw_parliaments_admin\Entity;

use Drupal\pw_parliaments_admin\CsvParser;
use Drupal\pw_parliaments_admin\ImportInterface;

/**
 * Base class for Import type classes.
 */

class Import implements ImportInterface {

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
   * @var string|null
   * The status of the import
   */
  protected $status;


  public function __construct($id = NULL, $label = NULL, $parliamentId = NULL, $fileId = NULL, $type = NULL, $status = NULL) {
    $this->id = $id;
    $this->label = $label;
    $this->parliamentId = $parliamentId;
    $this->fileId = $fileId;
    $this->status = $status;
    $this->type = $type;
  }

  /**
   * @return \Drupal\pw_parliaments_admin\Import\CsvParser
   */
  public function getCSVParser() {
    return new CsvParser($this);
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


  /**
   * Save the Import entity and update the CSV file
   *
   * @throws \Exception
   */
  public function save() {
    $transaction = db_transaction();
    try {
      // set the default status
      if ($this->getStatus() === NULL) {
        $this->setStatus('default');
      }
      if (is_numeric($this->getId())) {
        db_update('pw_parliaments_admin_imports')
          ->condition('id', $this->getId())
          ->fields([
            'parliament' => $this->getParliamentId(),
            'label' => $this->getLabel(),
            'type' => $this->getType(),
            'status' => $this->getStatus(),
            'file' => $this->getFileId()
          ])
          ->execute();
      }
      else {
        $id = db_insert('pw_parliaments_admin_imports')
          ->fields([
            'parliament' => $this->getParliamentId(),
            'label' => $this->getLabel(),
            'type' => $this->getType(),
            'status' => $this->getStatus(),
            'file' => $this->getFileId()
          ])
          ->execute();
        $this->id = $id;
      }
      $this->updateFile();
    }
    catch (\Exception $e) {
      $transaction->rollback();
      watchdog_exception('pw_parliaments_admin', $e);
      throw $e;
    }
  }


  /**
   * Update the CSV file related to the Import entity
   */
  protected function updateFile() {
    if (is_numeric($this->getFileId())) {
      $originalImport = self::load($this->getId());
      // update file when the file id is set and no original Import already exists
      // or when the file id differs between old and new import version
      if (!$originalImport || $originalImport->getFileId() != $this->getFileId() ) {
        $csv = $this->getFile();
        // If the csv is a temporary file move it to its final location and
        // make it permanent.
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
        // Delete the previous csv if it was deleted or replaced.
        if ($originalImport && is_numeric($originalImport->getFileId())) {
          file_usage_delete($originalImport->getLoadFile(), 'pw_parliaments_admin', 'import', $originalImport->getId());
          file_delete($originalImport->getLoadFile());
        }
      }
    }

  }

  /**
   * Static helper to load an Import entity from database
   *
   * @param int|string $id
   * The id of the import
   *
   * @return \Drupal\pw_parliaments_admin\Entity\Import|FALSE
   * False if no import found for the id
   */
  public static function load($id) {
    $query = db_select('pw_parliaments_admin_imports', 'i')
      ->condition('id', $id)
      ->fields('i')
      ->execute();

    $result = $query->fetchAssoc();

    if (!empty($result)) {
      return new Import($result['id'], $result['label'], $result['parliament'], $result['file'], $result['type'], $result['status']);
    }

    return FALSE;
  }


  /**
   * Renders the information on the pre check like a preview of the
   * CSV and information about the fields required and used on import.
   *
   * Use ImportDataSet::getFields() to get the information about the fields
   * used for the actual type of import
   *
   * @return string
   */
  public function renderPreCheck() {
    // TODO: Implement renderPreCheck() method.
  }

  /**
   * Depending on the chosen type of import another ImportDataSet class
   * will be needed.
   */
  public function createNewImportDataSet() {
    // TODO: Implement createNewImportDataSet() method.
  }

  /**
   * Get the autoloading path for the actual ImportDataSet class used for the
   * type of import.
   *
   * @return string
   */
  public function getImportDataSetClass() {
    // TODO: Implement getImportDataSetClass() method.
  }


  public static function getPossibleImportsOptions() {
    return [
      'constituency' => t('Constituencies'),
      'candidates' => t('Candidacies'),
      'election_results' => t('Election results')
    ];
  }
}