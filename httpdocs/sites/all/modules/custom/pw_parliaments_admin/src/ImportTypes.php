<?php


namespace Drupal\pw_parliaments_admin;


use Drupal\pw_globals\OptionsInterface;


/**
 * Defines the available import types as an Options clas
 */
class ImportTypes implements OptionsInterface {

  const CONSTITUENCIES = 'constituencies';
  const CANDIDACIES = 'candidacies';
  const ELECTION_RESULTS = 'election_results';


  public static function getPossibleOptions() {
    return [
      self::CONSTITUENCIES => t('Constituencies'),
      self::CANDIDACIES => t('Candidacies'),
      self::ELECTION_RESULTS => t('Election results')
    ];
  }


  /**
   * @param $import_type
   *
   * @return ImportTypeInterface|null
   */
  public static function getClass($import_type) {
    $classes = [
      self::CONSTITUENCIES => '\Drupal\pw_parliaments_admin\Import\ImportTypeConstituencies',
      self::CANDIDACIES => '\Drupal\pw_parliaments_admin\Import\ImportTypeCandidacies',
      self::ELECTION_RESULTS => '\Drupal\pw_parliaments_admin\Import\ImportTypeElectionResults'
    ];

    if(isset($classes[$import_type])) {
      return new $classes[$import_type]();
    }

    return NULL;
  }


  public static function getOptionLabel($status) {
    $possibleStatus = self::getPossibleOptions();
    if (isset($possibleStatus[$status])) {
      return $possibleStatus[$status];
    }

    return '';
  }
}