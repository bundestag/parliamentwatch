<?php

use Drupal\pw_datatransfers\Exception\DatatransfersException;
use Drupal\pw_datatransfers\Exception\ImportCheckFailed;
use Drupal\pw_datatransfers\Exception\SourceNotFoundException;
use Drupal\pw_datatransfers\Modtool\DialogueImport;
use Drupal\pw_datatransfers\Modtool\DialogueImportCheck;

/**
 * @file
 * Page callbacks defined in PW Datatransfers module
 */


/**
 * Page callback for the old Modtool. It just prints some strings
 * directly.
 *
 * @param int|string $dialogue_id
 * The id of the dialogue in modtool
 *
 * @return void - directly prints "OK" or "FAILED"
 *
 */
function pw_datatransfers_dialogue_import_old($dialogue_id) {
  $return_value = 'FAILED';

  try {
    if (!is_numeric($dialogue_id)) {
      throw new InvalidArgumentException('The dialogue id ' . $dialogue_id . ' is not numeric');
    }

    $source_path = variable_get('pw_dialogues_importer_source');
    $source_path .= $dialogue_id;
    $source_path .= '?unreleased=1';
    $source_document = new DOMDocument('1.0');
    $isLoaded = $source_document->load($source_path);
    if (!$isLoaded) {
      throw new SourceNotFoundException('The source document for dialogue ' . $dialogue_id . ' could not be loaded by calling the path ' . $source_path);
    }

    $importDialogue = new DialogueImport($source_document);
    $importFinished = $importDialogue->import();
    $return_value = 'OK';

    // after the import was finished we check if really the whole
    // dialogue was imported
    if ($importFinished) {
      $importCheck = new DialogueImportCheck($importDialogue);
      if (!$importCheck->checkForQuestion()) {
        throw new ImportCheckFailed('The question for dialogue id '. $importDialogue->getDialogueId() .' were not found in Drupal');
      }
      if (!$importCheck->checkForAnswer()) {
        throw new ImportCheckFailed('The answer for dialogue id '. $importDialogue->getDialogueId() .' were not found in Drupal');
      }
    }
  }
  catch (Exception $e) {
    $return_value = 'FAILED';
  }

  print $return_value;
}

/**
 * Page callback: creates or updates a dialogue node and its comments.
 */
function pw_datatransfers_dialogue_import() {
  if (!empty($_SERVER['REDIRECT_HTTP_AUTHORIZATION'])) {
    $credentials = base64_decode(substr($_SERVER['REDIRECT_HTTP_AUTHORIZATION'], 6));
    list($_SERVER['PHP_AUTH_USER'], $_SERVER['PHP_AUTH_PW']) = explode(':', $credentials, 2);
  }

  if (!isset($_SERVER['PHP_AUTH_USER']) || !isset($_SERVER['PHP_AUTH_PW'])) {
    drupal_add_http_header('Status', '401 Unauthorized');
    return;
  }

  $uid = user_authenticate($_SERVER['PHP_AUTH_USER'], $_SERVER['PHP_AUTH_PW']);

  if (!$uid) {
    drupal_add_http_header('Status', '401 Unauthorized');
    return;
  }

  $account = user_load($uid);

  if (!in_array(user_role_load_by_name('API User')->rid, array_keys($account->roles))) {
    drupal_add_http_header('Status', '403 Forbidden');
    return;
  }

  if ($_SERVER['REQUEST_METHOD'] != 'POST') {
    drupal_add_http_header('Status', '405 Method Not Allowed');
    drupal_add_http_header('Allow', 'POST');
    return;
  }

  if (strpos($_SERVER['CONTENT_TYPE'] , 'text/xml') !== 0) {
    drupal_add_http_header('Status', '415 Unsupported Media Type');
    return;
  }

  try {

    // load the DomDocument of the dialogue XML
    $doc = new DOMDocument('1.0');
    if (!$doc->load('php://input')) {
      throw new SourceNotFoundException('The source document for dialogue ' . $dialogue_id . ' could not be loaded by calling the path ' . $this->sourcePath);
    }


    // do the import
    $importDialogue = new DialogueImport($doc);
    $importFinished = $importDialogue->import();


    // after the import was finished we check if really the whole
    // dialogue was imported
    if ($importFinished) {
      $importCheck = new DialogueImportCheck($importDialogue);
      if (!$importCheck->checkForQuestion()) {
        throw new ImportCheckFailed('The question for dialogue id '. $importDialogue->getDialogueId() .' were not found in Drupal');
      }
      if (!$importCheck->checkForAnswer()) {
        throw new ImportCheckFailed('The answer for dialogue id '. $importDialogue->getDialogueId() .' were not found in Drupal');
      }
    }
  }
  catch (SourceNotFoundException $sourceNotFoundException) {
    drupal_add_http_header('Status', '400 Bad Request');
    return;
  }
  catch (DatatransfersException $datatransfersException) {
    drupal_add_http_header('Status', '500 Internal Server Error');
    return;
  }
  catch (Exception $e) {
    watchdog_exception('pw_dialogues', $e);
    drupal_add_http_header('Status', '422 Unprocessable Entity');
    return;
  }



  $node_path = 'node/'. $importDialogue->getSavedQuestionNode();
  if ($importDialogue->questionIsNew) {
    drupal_add_http_header('Status', '201 Created');
    drupal_add_http_header('Location', url($node_path, ['absolute' => TRUE]));
  }
  else {
    drupal_add_http_header('Status', '303 See Other');
    drupal_add_http_header('Location', url($node_path, ['absolute' => TRUE]));
  }
}