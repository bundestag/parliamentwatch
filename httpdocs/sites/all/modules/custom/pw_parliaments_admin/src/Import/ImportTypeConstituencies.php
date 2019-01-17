<?php


namespace Drupal\pw_parliaments_admin\Import;


use Drupal\pw_parliaments_admin\CsvParser;


class ImportTypeConstituencies extends ImportTypeBase {

  /**
   * @var \Drupal\pw_parliaments_admin\ImportDataSetInterface
   */
  protected $dataSetClass = '\Drupal\pw_parliaments_admin\DataSets\ConstituencyImportDataSet';

  public function renderPreCheck(CsvParser $csvparser) {
    return 'Pre check for constituency';
  }


}