<?php


namespace Drupal\pw_parliaments_admin;


use Drupal\pw_parliaments_admin\Exception\ImportException;
use League\Csv\Reader;
use League\Csv\Statement;

class CsvParser {

  /**
   * @var object
   * The Drupal file entity
   */
  protected $file;


  protected $dataSetsNumber;


  protected $headers = [];

  /**
   * CsvParser constructor.
   *
   * @param object
   * The Drupal file entity
   *
   * @throws \Drupal\pw_parliaments_admin\Exception\ImportException
   */
  public function __construct($file) {
    if (is_object($file) && isset($file->fid)) {
      $this->file = $file;
    }
    else {
      throw new ImportException('No valid file was defined.');
    }

    $elements = $this->getDatasets(1);
    $this->headers = $elements['header'];
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
   * if no dataset was found or an Exception was thrown
   *
   */
  public function getDatasets($limit = 5, $offset = 0, $delimiter = ',') {
    $datasets = [];

    try {
      $file_uri = $this->file->uri;

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
    catch (\Exception $e) {
      watchdog_exception('pw_parliaments_admin', $e);
      drupal_set_message('An error appeared while trying to fetch the datasets from the CSV.', 'error');
    }


    return $datasets;
  }


  /**
   * Count all datasets in the CSV
   *
   * @return int
   */
  public function countDataSets() {
    if ($this->dataSetsNumber !== NULL) {
      return $this->dataSetsNumber;
    }

    $datasets = $this->getDatasets(-1);
    $this->dataSetsNumber = count($datasets['result']);
    return $this->dataSetsNumber;
  }


  /**
   * Get the heading of the CSV
   * @return array
   */
  public function getHeader() {
    return $this->headers;
  }

}