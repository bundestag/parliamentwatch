<?php


namespace Drupal\pw_parliaments_admin\Status;


use Drupal\pw_globals\OptionsInterface;

class DataSetStatus implements OptionsInterface {

  const OK = 'ok';              // validation found no errors
  const ERROR = 'error';        // validation found errors
  const IMPORTED = 'imported';  // imported to Drupal
  const STRUCTURED = 'structured'; // was successfully structured


  public static function getPossibleOptions() {
    return [
      self::OK => t('No errors'),
      self::ERROR => t('Errors found'),
      self::IMPORTED => t('Imported'),
      self::STRUCTURED => t('Structured')
    ];
  }

  public static function getOptionLabel($status) {
    $possibleStatus = self::getPossibleOptions();
    if (isset($possibleStatus[$status])) {
      return $possibleStatus[$status];
    }

    return '';
  }
}