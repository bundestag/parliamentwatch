<?php


namespace Drupal\pw_imports;

/**
 * Base class for Import type classes.
 */
abstract class ImportBase implements ImportInterface {

  /**
   * @var array
   * The settings for the import
   */
  protected $settings = array();


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
   * @var int
   * The status of the import check
   */
  protected $checkStatus;


  /**
   * @return \Drupal\pw_imports\CsvParser
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
}