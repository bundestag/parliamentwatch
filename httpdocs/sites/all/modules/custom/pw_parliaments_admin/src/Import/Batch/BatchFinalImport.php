<?php


namespace Drupal\pw_parliaments_admin\Import\Batch;

use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\Status\DataSetStatus;
use Drupal\pw_parliaments_admin\Status\ImportStatus;
use Drupal\pw_parliaments_admin\Status\StructuredDataStatus;

class BatchFinalImport  {


  public static function importData(Import $pw_import, &$context) {
    if (empty($context['sandbox'])) {
      $query = db_select($pw_import->getDatabaseTableForStructuredData(), 't');
      $query->addField('t', 'id');
      $query->condition('import', $pw_import->getId());
      $query->condition('status', [StructuredDataStatus::OK, StructuredDataStatus::ERROR]);
      $result = $query->execute()->fetchAllAssoc('id');

      $context['sandbox']['progress'] = 0;
      $context['sandbox']['max'] = count($result);
      $context['sandbox']['last_id'] = 0;
      $context['sandbox']['errors'] = [];
    }

    $limit = 30;
    $query = db_select($pw_import->getDatabaseTableForStructuredData(), 't');
    $query->addField('t', 'id');
    $query->condition('import', $pw_import->getId());
    $query->condition('status', [StructuredDataStatus::OK, StructuredDataStatus::ERROR]);
    $query->condition('id', $context['sandbox']['last_id'] , '>');
    $query->fields('t');
    $query->range(0, $limit);
    $query->orderBy('id');
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $transaction = db_transaction();
      try {
        $importType = $pw_import->getImportTypeClass();

        /** @var \Drupal\pw_parliaments_admin\Import\Interfaces\StructuredDataInterface $structuredData */
        $structuredData = $importType->getStructuredDataFromDataBaseArray($record);
        $structuredData->resetStatus();
        $structuredData->import();
      }
      catch (\Exception $e) {
        $transaction->rollback();
        $structuredData->setValidationError($e->getMessage());
        $structuredData->setStatus(StructuredDataStatus::ERROR);
        $structuredData->save();
      }


      if ($structuredData->hasErrors()) {
        $error_item = $context['sandbox']['progress'];
        $context['sandbox']['errors'][] = $error_item;
        $message = 'Fehler beim Import von '. $structuredData->getLabel();
      }
      else {
        $message = $structuredData->getLabel() .' erfolgreich importiert';
      }
      $context['results'][] = $message;
      $context['sandbox']['progress']++;
      $context['message'] = $message;
      $context['sandbox']['last_id'] = $structuredData->getId();
    }


    if ($context['sandbox']['progress'] != $context['sandbox']['max'] && $context['sandbox']['progress'] < $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
    else {
      $context['finished'] = 1;

      $hasErrors = !empty( $context['sandbox']['errors']);
      if ($hasErrors) {
        $pw_import->setStatus(ImportStatus::IMPORT_FAILED);
        $pw_import->save();
      }
      else {
        $pw_import->setStatus(ImportStatus::IMPORTED);
        $pw_import->save();
      }
    }
  }


  public static function finished($success, $results, $operations) {
    $count_results = count($results);
    if ($success) {
      drupal_set_message('Es wurden '. $count_results .' Datensätze import.');
    }
    else {
      drupal_set_message('Es wurden '. $count_results .' Datensätze verarbeitet. Etwas lief schief.', 'warning');
    }

  }


}