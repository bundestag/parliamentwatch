<?php

namespace Drupal\pw_parliaments_admin;

/**
 * Defines functions needed for Import classes. An Import class describes
 * the settings for an import like the parliament for which the
 * data will be imported, stores the CSV file and an import check status. For each
 * type of import (for example import of constituencies, profiles and election
 * results are each a type of import) a seperate Import class needs to be defined
 * which needs to implement this interface.
 */
interface ImportInterface {

  /**
   * Renders the information on the pre check like a preview of the
   * CSV and information about the fields required and used on import.
   *
   * Use ImportDataSet::getFields() to get the information about the fields
   * used for the actual type of import
   *
   * @return string
   */
  public function renderPreCheck();


  /**
   * Depending on the chosen type of import another ImportDataSet class
   * will be needed.
   */
  public function createNewImportDataSet();


  /**
   * Get the CSV parser class for the CSV uploaded for this import.
   *
   * @return \Drupal\pw_parliaments_admin\CsvParser
   */
  public function getCSVParser();


  /**
   * Get the autoloading path for the actual ImportDataSet class used for the
   * type of import.
   *
   * @return string
   */
  public function getImportDataSetClass();


  /**
   * Get the id of the parliament for which the import should run
   *
   * @return int|string
   */
  public function getParliamentId();


  /**
   * Return a loaded file or try to load the file when it was not already loaded.
   * @return object|FALSE
   * An Drupal file entity or FALSE
   */
  public function getLoadFile();
}