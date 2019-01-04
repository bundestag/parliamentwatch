<?php


namespace Drupal\pw_logging\Entity\Details;


use Drupal\pw_logging\Entity\Logentry;
use Entity;


/**
 * Details which should be given to PWLog
 *
 *  log_id
 *  dialogue_id
 *  message_id
 *  drupal_question_id (can be NULL),
 *  drupal_answer_id (can be NULL),
 *  action_on_message
 */
class ModtoolLogDetails extends Entity {


  public static function createFromLogDetails(Logentry $logentry, $details) {
    $details_entity = entity_create('pwlogentry_modtool', [
      'log_id' => $logentry->identifier(),
      'dialogue_id' => $details['dialogue_id'],
      'message_id' => $details['message_id'],
      'drupal_question_id' => $details['drupal_question_id'],
      'drupal_answer_id' => $details['drupal_answer_id'],
      'action_on_message' => $details['action_on_message']
    ]);

    return $details_entity;
  }
}