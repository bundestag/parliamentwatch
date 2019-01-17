<?php


namespace Drupal\pw_parliaments_admin\Status;


use Drupal\pw_globals\OptionsInterface;

class ImportStatus implements OptionsInterface {

  const NOT_IMPORTED = 'not_imported';
  const PRE_CHECK = 'pre_check';
  const OK = 'ok';
  const NEEDS_REVIEW = 'needs_review';
  const IMPORTED = 'imported';


  public static function getPossibleOptions() {
    return [
      self::NOT_IMPORTED => t('Not imported'),
      self::PRE_CHECK => t('Pre check'),
      self::OK => t('Can be imported'),
      self::NEEDS_REVIEW => t('Needs review'),
      self::IMPORTED => t('Imported')
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