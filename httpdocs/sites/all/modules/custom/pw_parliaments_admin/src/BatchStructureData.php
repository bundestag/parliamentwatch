<?php


namespace Drupal\pw_parliaments_admin;

use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\Status\DataSetStatus;
use Drupal\pw_parliaments_admin\Status\ImportStatus;

class BatchStructureData  {


  public static function importData(Import $pw_import, &$context) {
    if (empty($context['sandbox'])) {
      $query = db_select($pw_import->getDatabaseTableForDataSets(), 't');
      $query->addField('t', 'id');
      $query->condition('status', DataSetStatus::OK);
      $query->condition('import', $pw_import->getId());
      $result = $query->execute()->fetchAllAssoc('id');

      $context['sandbox']['progress'] = 0;
      $context['sandbox']['max'] = count($result);
      $context['sandbox']['last_id'] = 0;
      $context['sandbox']['errors'] = [];
    }

    $limit = 30;
    $query = db_select($pw_import->getDatabaseTableForDataSets(), 't');
    $query->addField('t', 'id');
    $query->condition('status', DataSetStatus::OK);
    $query->condition('import', $pw_import->getId());
    $query->condition('id', $context['sandbox']['last_id'] , '>');
    $query->fields('t');
    $query->range(0, $limit);
    $query->orderBy('id');
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $importType = $pw_import->getImportTypeClass();
      /** @var \Drupal\pw_parliaments_admin\DataSets\ConstituencyImportDataSet $dataSet */
      $dataSet = $importType->getImportDataSetFromDataBaseArray($record);

      $structuredDataSaved = $dataSet->structuredData();
      $message = $structuredDataSaved->getLabel() .' verarbeitet';


      if ($structuredDataSaved->hasErrors()) {
        $error_item = $context['sandbox']['progress'];
        $context['sandbox']['errors'][] = $error_item;
        $dataset_error = 'Error during structuring: '. $structuredDataSaved->getValidationErrors();
        $dataSet->setValidationError($dataset_error);
        $dataSet->setStatus(DataSetStatus::ERROR);
        $dataSet->save();
        $structuredDataSaved->delete();
      }
      else {
        $dataSet->setStructuredDataId($structuredDataSaved->getId());
        $dataSet->setStatus(DataSetStatus::STRUCTURED);
        $dataSet->save();
      }
      $context['results'][] = $message;
      $context['sandbox']['progress']++;
      $context['message'] = $message;
      $context['sandbox']['last_id'] = $dataSet->getId();
    }


    if ($context['sandbox']['progress'] != $context['sandbox']['max'] && $context['sandbox']['progress'] < $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
    else {
      $context['finished'] = 1;

      $hasErrors = !empty( $context['sandbox']['errors']);
      if ($hasErrors) {
        $pw_import->setStatus(ImportStatus::DATA_STRUCTURED_FAILED);
        $pw_import->save();
      }
      else {
        $pw_import->setStatus(ImportStatus::DATA_STRUCTURED_OK);
        $pw_import->save();
      }
    }
  }


  public static function finished($success, $results, $operations) {
    $count_results = count($results);
    if ($success) {
      drupal_set_message('Es wurden '. $count_results .' Datensätze verarbeitet.');
    }
    else {
      drupal_set_message('Es wurden '. $count_results .' Datensätze verarbeitet, allerdings lief etwas schief.', 'warning');
    }

  }


}