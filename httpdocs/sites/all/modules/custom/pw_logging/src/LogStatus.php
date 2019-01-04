<?php


namespace Drupal\pw_logging;

/**
 * Define the status which are possible for logentries
 */
class LogStatus {

  const SUCCESS = 'success';
  const ERROR = 'error';


  public static function getPossibleStatus() {
    return [
      self::SUCCESS => t('Success'),
      self::ERROR => t('Error')
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