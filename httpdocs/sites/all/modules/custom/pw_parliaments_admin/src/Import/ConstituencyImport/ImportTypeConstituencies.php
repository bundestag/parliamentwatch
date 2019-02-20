<?php


namespace Drupal\pw_parliaments_admin\Import\ConstituencyImport;


use Drupal\pw_parliaments_admin\CsvParser;
use Drupal\pw_parliaments_admin\Import\ImportTypeBase;


class ImportTypeConstituencies extends ImportTypeBase {

  /**
   * @var string
   * The full namespaced name of the class of the datasets
   */
  protected $dataSetClass = '\Drupal\pw_parliaments_admin\Import\ConstituencyImport\ConstituencyImportDataSet';

  protected $structuredDataClass = '\Drupal\pw_parliaments_admin\Import\ConstituencyImport\ConstituencyStructuredData';

  protected $needsDataStructuring = TRUE;

  public function renderPreCheck(CsvParser $csvparser) {
    return 'Pre check for constituency';
  }

  public function getViewName($entity_type = 'dataset') {
    switch ($entity_type) {
      case 'dataset':
        return 'pw_administration_imports_constituency_datasets';
      case 'structured_data':
        return 'pw_administration_imports_constituency_structured_data';
    }

    return '';
  }

}