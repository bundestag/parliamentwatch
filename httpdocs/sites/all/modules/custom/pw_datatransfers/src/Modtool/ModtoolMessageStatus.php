<?php


namespace Drupal\pw_datatransfers\Modtool;


/**
 * Define the status which are possible for messages in Modtool
 */
class ModtoolMessageStatus {

  const UNRELEASED = 0;
  const RELEASED = 1;
  const DELETED = 2;
  const MODERATED = 3;
  const HOLD = 4;
  const REQUESTED = 5;


  public static function getPossibleStatus() {
    return [
      self::UNRELEASED => t('Unreleased'),
      self::RELEASED => t('Released'),
      self::DELETED => t('Deleted'),
      self::MODERATED => t('Moderated'),
      self::HOLD => t('Hold'),
      self::REQUESTED => t('Requested')
    ];
  }


  public static function getStatusLabel($status) {
    $possibleStatus = self::getPossibleStatus();
    if (isset($possibleStatus[$status])) {
      return $possibleStatus[$status];
    }

    return '';
  }
}