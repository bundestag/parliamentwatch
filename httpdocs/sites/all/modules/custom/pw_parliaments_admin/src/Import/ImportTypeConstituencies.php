<?php


namespace Drupal\pw_parliaments_admin\Import;


use Drupal\pw_parliaments_admin\CsvParser;


class ImportTypeConstituencies extends ImportTypeBase {

  /**
   * @var string
   * The full namespaced name of the class of the datasets
   */
  protected $dataSetClass = '\Drupal\pw_parliaments_admin\DataSets\ConstituencyImportDataSet';

  protected $structuredDataClass = '\Drupal\pw_parliaments_admin\DataSets\ConstituencyStructuredData';

  public function renderPreCheck(CsvParser $csvparser) {
    return 'Pre check for constituency';
  }


}