<?php


use Drupal\pw_datatransfers\Controller\ModtoolActionsController;


/**
 * @file
 * Page callbacks defined in PW Datatransfers module
 */


/**
 * Enhanced page callback for the new Modtool. The XML document is sent by POST
 * and the page callbacks defines some HTTP header depending on the result. it also
 * does the access check which we might move to an access callback later
 *
 */

function pw_datatransfers_dialogue_import($dialogue_id, $message_type, $message_id, $action) {
  $modtoolActionsController = new ModtoolActionsController($dialogue_id, $message_type, $message_id, $action);
  $response = $modtoolActionsController->start();
  return $response;

}