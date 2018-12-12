<?php


namespace Drupal\pw_datatransfers\Entity;


use Entity;

/**
 *
 */
class LogDialogueImport extends Entity {


  /**
   * Constructor as a helper to the parent constructor.
   *
   * @param array $values
   * @param string $entity_type
   *
   * @throws \Exception
   */
  public function __construct(array $values = array(), $entity_type = 'dialogue_import_log') {
    parent::__construct($values, $entity_type);
  }
}