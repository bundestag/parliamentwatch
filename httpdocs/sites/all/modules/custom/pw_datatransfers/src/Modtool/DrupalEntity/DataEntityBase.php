<?php


namespace Drupal\pw_datatransfers\Modtool\DrupalEntity;

use Drupal\pw_datatransfers\Modtool\ModtoolMessage;


/**
 * Base class for DataEntity classes. DataEntity classes are the counterparts
 * of ModtoolMessage classes and therefore manage the node/ comment creation and
 * value updating.
 *
 */
abstract class DataEntityBase implements DataEntityInterface {

  /**
   * @var \Drupal\pw_datatransfers\Modtool\ModtoolMessage
   * The class describing the message sent from Modtool
   *
   */
  protected $modtoolMessage = NULL;

  /**
   * @var object|null
   * The Drupal node or comment for the question/ answer
   */
  protected $entity = NULL;


  /**
   * @var bool
   * True when the Drupal node/ comment was just created
   */
  public $isNew = FALSE;


  /**
   * DataEntityBase constructor.
   *
   * @param \Drupal\pw_datatransfers\Modtool\ModtoolMessage $modtool_message
   */
  public function __construct(ModtoolMessage $modtool_message) {
    $this->modtoolMessage = $modtool_message;
  }


  /**
   * Set the Drupal entity (node or comment) related to the given ModtoolMessage
   *
   * @param object $entity
   * The Drupal node/ comment
   */
  public function setEntity($entity) {
    $this->entity = $entity;
  }


  /**
   * Get the Drupal entity (node or comment) related to the given ModtoolMessage
   *
   * @return object|null
   */
  public function getEntity() {
    return $this->entity;
  }


  /**
   * Get the ModtoolMessage class
   *
   * @return \Drupal\pw_datatransfers\Modtool\ModtoolMessage
   */
  public function getModtoolMessage() {
    return $this->modtoolMessage;
  }


}