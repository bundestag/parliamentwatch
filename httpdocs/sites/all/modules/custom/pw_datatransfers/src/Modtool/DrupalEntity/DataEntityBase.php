<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 20.12.2018
 * Time: 11:36
 */

namespace Drupal\pw_datatransfers\Modtool\DrupalEntity;


abstract class DataEntityBase implements DataEntityInterface {

  protected $modtoolMessage = NULL;

  protected $entity = NULL;

  public $isNew = FALSE;


  public function __construct(ModtoolMessage $modtool_message) {
    $this->modtoolMessage = $modtool_message;
  }


  public function setEntity($entity) {
    $this->entity = $entity;
  }

  public function getEntity() {
    return $this->entity;
  }

  public function getModtoolMessage() {
    return $this->modtoolMessage;
  }


}