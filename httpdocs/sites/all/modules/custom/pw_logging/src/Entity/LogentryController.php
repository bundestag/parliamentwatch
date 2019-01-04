<?php


namespace Drupal\pw_datatransfers\Entity;


use DatabaseTransaction;
use EntityAPIController;

class LogentryController extends EntityAPIController  {


  /**
   * For performance reasons it might be better to overwrite the parent's
   * load() method to use the cache mechanism of the entity API. By now we
   * always load our custom related data after the entities are loaded and cached
   * without any caching
   *
   * @param array $ids
   * @param array $conditions
   *
   * @return array|null
   */
  public function load($ids = [], $conditions = []) {
    $entities = parent::load($ids, $conditions);
    $entities = $this->loadReferencedDrupalEntities($entities);
    $entities = $this->loadReferencedModtoolMessages($entities);

    return $entities;
  }


  protected function loadReferencedDrupalEntities($entities) {
    $logentry_ids = array_keys($entities);

    $query = db_select('pw_datatransfers_logs_entity_refs', 'ref')
      ->condition('log_entry', $logentry_ids, 'IN')
      ->fields('ref')
      ->execute();

    while  ($record = $query->fetchAssoc()) {
      if ($record['entity_type'] == 'comment') {
        $logentry_id = $record['log_entry'];
        $entities[$logentry_id]->addCommentCid($record['entity_id']);
      }

      if ($record['entity_type'] == 'node') {
        $logentry_id = $record['log_entry'];
        $entities[$logentry_id]->addDialogueNid($record['entity_id']);
      }
    }
    return $entities;
  }


  protected function loadReferencedModtoolMessages($entities) {
    $logentry_ids = array_keys($entities);

    $query = db_select('pw_datatransfers_logs_dialogue_modtool_refs', 'ref')
      ->condition('log_entry', $logentry_ids, 'IN')
      ->fields('ref')
      ->execute();

    while  ($record = $query->fetchAssoc()) {
      if ($record['message_type'] == 'question') {
        $logentry_id = $record['log_entry'];
        $entities[$logentry_id]->addMessageIdQuestion($record['message_id']);
      }

      if ($record['message_type'] == 'answer') {
        $logentry_id = $record['log_entry'];
        $entities[$logentry_id]->addMessageIdAnswer($record['message_id']);
      }
    }
    return $entities;
  }

  /**
   * Mostly a copy of the parent's method. We just add calls to saveDrupalEntityReferences()
   * and saveModtoolReferences() as these data is stored in seperate tables
   *
   * @param $entity
   * The dialogue import log entry
   *
   * @param \DatabaseTransaction|NULL $transaction
   *
   * @return bool|int
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $transaction = isset($transaction) ? $transaction : db_transaction();
    try {
      // Load the stored entity, if any.
      if (!empty($entity->{$this->idKey}) && !isset($entity->original)) {
        // In order to properly work in case of name changes, load the original
        // entity using the id key if it is available.
        $entity->original = entity_load_unchanged($this->entityType, $entity->{$this->idKey});
      }
      $entity->is_new = !empty($entity->is_new) || empty($entity->{$this->idKey});
      $this->invoke('presave', $entity);

      if ($entity->is_new) {
        $return = drupal_write_record($this->entityInfo['base table'], $entity);
        $this->saveDrupalEntityReferences($entity);
        $this->saveModtoolReferences($entity);
        if ($this->revisionKey) {
          $this->saveRevision($entity);
        }
        $this->invoke('insert', $entity);
      }
      else {
        // Update the base table if the entity doesn't have revisions or
        // we are updating the default revision.
        if (!$this->revisionKey || !empty($entity->{$this->defaultRevisionKey})) {
          $return = drupal_write_record($this->entityInfo['base table'], $entity, $this->idKey);
        }
        if ($this->revisionKey) {
          $return = $this->saveRevision($entity);
        }
        $this->resetCache(array($entity->{$this->idKey}));
        $this->invoke('update', $entity);

        // Field API always saves as default revision, so if the revision saved
        // is not default we have to restore the field values of the default
        // revision now by invoking field_attach_update() once again.
        if ($this->revisionKey && !$entity->{$this->defaultRevisionKey} && !empty($this->entityInfo['fieldable'])) {
          field_attach_update($this->entityType, $entity->original);
        }
      }

      // Ignore slave server temporarily.
      db_ignore_slave();
      unset($entity->is_new);
      unset($entity->is_new_revision);
      unset($entity->original);

      return $return;
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception($this->entityType, $e);
      throw $e;
    }
  }


  protected function saveDrupalEntityReferences($entity) {
    $dialogue_nids = $entity->getDialogueNids();
    if (!empty($dialogue_nids) && $entity->is_new) {
      foreach ($dialogue_nids as $dialogue_nid) {
        db_insert('pw_datatransfers_logs_entity_refs')
          ->fields([
            'log_entry' => $entity->id,
            'entity_id' => $dialogue_nid,
            'entity_type' => 'node'
        ])
          ->execute();
      }

    }

    $comment_cids = $entity->getCommentCids();
    if (!empty($comment_cids) && $entity->is_new) {
      foreach ($comment_cids as $comment_cid) {
        db_insert('pw_datatransfers_logs_entity_refs')
          ->fields([
            'log_entry' => $entity->id,
            'entity_id' => $comment_cid,
            'entity_type' => 'comment'
          ])
          ->execute();
      }
    }
  }

  protected function saveModtoolReferences($entity) {
    $question_message_ids = $entity->getQuestionMessageIds();

    if (!empty($question_message_ids) && $entity->is_new) {
      foreach ($question_message_ids as $question_message_id) {
        db_insert('pw_datatransfers_logs_dialogue_modtool_refs')
          ->fields([
            'log_entry' => $entity->id,
            'message_id' => $question_message_id,
            'message_type' => 'question'
          ])
          ->execute();
      }

    }

    $answer_message_ids = $entity->addMessageIdAnswer();
    if (!empty($answer_message_ids) && $entity->is_new) {
      foreach ($answer_message_ids as $answer_message_id) {
        db_insert('pw_datatransfers_logs_entity_refs')
          ->fields([
            'log_entry' => $entity->id,
            'message_id' => $answer_message_id,
            'message_type' => 'answer'
          ])
          ->execute();
      }
    }
  }
}