<?php


namespace Drupal\pw_imports;

class CsvParser {

  /**
   * @var \Drupal\pw_imports\ImportInterface
   */
  protected $pwImport;


  /**
   * CsvParser constructor.
   *
   * @param \Drupal\pw_imports\ImportInterface $pw_import
   */
  public function __construct(ImportInterface $pw_import) {
    $this->pwImport = $pw_import;
  }


  /**
   *
   * Get the datasets from the file uploaded with the PwImport.
   *
   * @param string $delimiter
   * @param int $offset
   * @param int $limit
   *
   * @return array
   * An array containing an header sub array with all headers and a result
   * subarray containing associative arrays for each row in the CSV. Empty
   * if none was found
   */
  public function getDatasets($limit = 5, $offset = 0, $delimiter = ';') {
    $datasets = [];
    $file = $this->pwImport->getLoadFile();
    if ($file) {
      $file_uri = $file->uri;

      $csv = Reader::createFromPath($file_uri, 'r');
      $csv->setDelimiter($delimiter);
      $csv->setHeaderOffset(0);

      $statement = (new Statement())
        ->limit($limit)
        ->offset($offset);

      $records = $statement->process($csv);

      if ($records->count()) {
        $datasets['header'] = [];
        foreach ($records->getHeader() as $heading) {
          $datasets['header'][] = $heading;
        }

        $datasets['result'] = [];
        foreach ($records as $record) {
          $datasets['result'][] = $record;
        }
      }
    }

    return $datasets;
  }


  public function getImport() {
    return $this->pwImport;
  }
}