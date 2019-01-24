<?php


namespace Drupal\pw_parliaments_admin\Status;


use Drupal\pw_globals\OptionsInterface;

class ImportStatus implements OptionsInterface {

  const CREATED = 'created';
  const OK = 'ok';
  const FAILED = 'failed';
  const DATA_STRUCTURED_FAILED = 'structure_failed';
  const DATA_STRUCTURED_OK = 'structured';
  const IMPORTED = 'imported';
  const IMPORT_FAILED = 'import_failed';


  public static function getPossibleOptions() {
    return [
      self::CREATED => t('Just created'),
      self::OK => t('Data sets validated'),
      self::FAILED => t('Errors appeared - import failed'),
      self::DATA_STRUCTURED_OK => t('Data is structured'),
      self::DATA_STRUCTURED_FAILED => t('Data structuring failed'),
      self::IMPORTED => t('Imported'),
      self::IMPORT_FAILED => t('Import failed')
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