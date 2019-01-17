<?php


namespace Drupal\pw_parliaments_admin;

use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\Status\ImportStatus;

class BatchCreatePreEntity  {


  public static function importData(Import $pw_import, &$context) {
    if (empty($context['sandbox'])) {
      $csvParser = $pw_import->getCSVParser();
      $context['sandbox']['progress'] = 0;
      $context['sandbox']['max'] = $csvParser->countDataSets();
      $context['sandbox']['csvparser'] = $csvParser;
      $context['sandbox']['errors'] = [];
    }

    $limit = 30;
    /** @var \Drupal\pw_parliaments_admin\CsvParser $csvParser */
    $csvParser = $context['sandbox']['csvparser'];
    $offset= $context['sandbox']['progress'];
    $datasets_to_import_by_batch = $csvParser->getDatasets($limit, $offset);

    if (!empty($datasets_to_import_by_batch)) {
      foreach ($datasets_to_import_by_batch['result'] as $single_dataset) {
        $importDataSet = $pw_import->createNewImportDataSet($single_dataset);
        $importDataSet->validate();

        if ($importDataSet->hasErrors()) {
          $importDataSet->preEntity();
          $message =' importiert';
        }
        else {
          $errors = $importDataSet->getValidationErrors();
          $error_messages = implode(', ', $errors);
          $message = 'Errors appeared: '. $error_messages;
          $error_item = $context['sandbox']['progress'];
          $context['sandbox']['errors'][$error_item] = $error_messages;
          $csvParser->logError($error_item, $error_messages);
        }

        $context['results'][] = $message;
        $context['sandbox']['progress']++;
        $context['message'] = $message;
      }
    }

    if ($context['sandbox']['progress'] != $context['sandbox']['max'] && $context['sandbox']['progress'] < $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
    else {
      $context['finished'] = 1;
      $pw_import->setStatus(ImportStatus::NEEDS_REVIEW);
      $pw_import->save();

    }
  }


  public static function finished($success, $results, $operations) {
    $count_results = count($results);
    drupal_set_message($count_results .' Datensätze wurden importiert');
  }

  public static function logErrorOnCSV($item, $errors) {

  }
}