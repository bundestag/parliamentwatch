<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 20.12.2018
 * Time: 11:34
 */

namespace Drupal\pw_datatransfers\Modtool\DrupalEntity;


interface DataEntityInterface {

  /**
   * @param $json
   *
   * @return object
   * The Drupal node/ comment of the question/ dialogue
   */
  public function createDrupalEntity();


  public function loadDrupalEntity();


  public function setDrupalEntityValuesFromJson($entity);

}