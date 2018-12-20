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
 * Enhanced page callback for the new Modtool. The XML document is sent by POST
 * and the page callbacks defines some HTTP header depending on the result. it also
 * does the access check which we might move to an access callback later
 *
 *
 */
function pw_datatransfers_dialogue_import($dialogue_id, $message_type, $message_id, $action) {
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

    // get the JSON from the POST
    $json = '';
    if (isset($_POST['message'])) {
      $json = json_decode($_POST['message']);
    }

    if (empty($json)) {
      throw new SourceNotFoundException('It was not possible to receive a JSON');
    }

    switch ($message_type) {
      case 'question':
        $dataClass = new \Drupal\pw_datatransfers\Modtool\DataQuestion($json);
        $dataClass->action($action);
        break;
      case 'answer':
        $dataClass = new \Drupal\pw_datatransfers\Modtool\DataQuestion($json);
        $dataClass->action($action);
        break;
      default:
        throw new DatatransfersException('No valid action was defined: "'. $action .'"');
    }

    // do the import
    $importDialogue = new DialogueImport($json);
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