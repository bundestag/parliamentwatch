<?php


namespace Drupal\pw_globals;

/**
 * Interface for defining classes which can be used to define a set of options.
 *
 * Define the key for each status as a constant of this class. In this way you can
 * avoid magic numbers by using the key elsewhere in the code by calling
 * OptionsInterface::CONSTANT_NAME.
 */
interface OptionsInterface {

  /**
   * Get all possible status. Define them in an array with the following structure:
   *
   * self::CONSTANT_NAME => t('Label for the status'),
   *
   * @return array
   */
  public static function getPossibleOptions();


  /**
   * Get the label for specific status by calling this function
   * OptionsInterface::getStatusLabel(OptionsInterface::CONSTANT_NAME)
   *
   * @param string|int $status
   *
   * @return string
   * Should be empty if no status was found
   */
  public static function getOptionLabel($status);
}