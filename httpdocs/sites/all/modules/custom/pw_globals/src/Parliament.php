<?php


namespace Drupal\pw_globals;


use Drupal\pw_globals\Exception\PwGlobalsException;

/**
 * Wraps a parliament term into a helper class. Use this for any properties and
 * methods related to parliaments.
 */
class Parliament {

  /**
   * @var object
   * The Drupal term object for a parliament
   */
  protected $parliamentTerm;

  /**
   * Parliament constructor.
   *
   * @param $term
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function __construct($term) {
    if (!is_object($term) || !isset($term->tid)) {
      throw new PwGlobalsException('Invalid argument "account" (value: '.  $term .' for Politician');
    }

    $this->parliamentTerm = $term;
  }


  /**
   * Get the time period now named "Valid date 1" -> describes the election
   * period
   *
   * @return array
   * If none found empty otherwise an array with two keys: "start" and "end",
   * both dates as timestamps of the days the periods start (at 00:00:00 am) or
   * ends (23:59:59 pm at the day) in UTC
   *
   * @throws \Exception
   */
  public function getElectionValidTimePeriod($timezone = '') {
    $parliament_wrapper = entity_metadata_wrapper('taxonomy_term', $this->parliamentTerm);
    $date = $parliament_wrapper->field_parliament_valid->value();
    $election_valid_period = [];

    if (isset($date[0]) && isset($date[0]["value"]) && isset($date[0]["value2"])) {
      if (empty($timezone)) {
        $timezone = date_default_timezone_get();
      }
      $election_valid_period['timezone'] = $timezone;

      $startDateTime = new \DateTime($date[0]["value"], new \DateTimeZone($date[0]["timezone"]));
      $startDateTime->setTimezone(new \DateTimeZone($timezone));
      $startDateTime->setTime(0, 0, 0);
      $election_valid_period['start'] = $startDateTime->getTimestamp();

      $endDateTime = new \DateTime($date[0]["value2"], new \DateTimeZone($date[0]["timezone"]));
      $endDateTime->setTimezone(new \DateTimeZone($timezone));
      $endDateTime->setTime(0, 0, 0);
      $election_valid_period['end'] = $endDateTime->getTimestamp();
    }

    return $election_valid_period;
  }


  /**
   * Get the time period now named "Valid date 2" -> describes the legislation
   * period
   *
   * @return array
   * If none found empty otherwise an array with two keys: "start" and "end",
   * both dates as timestamps of the days the periods start (at 12:00 am) or
   * ends (23:59:59 pm at the day) in UTC
   *
   * @throws \Exception
   */
  public function getLegislatureValidTimePeriod($timezone = '') {
    $parliament_wrapper = entity_metadata_wrapper('taxonomy_term', $this->parliamentTerm);
    $date = $parliament_wrapper->field_parliament_valid->value();
    $legislature_valid_period = [];

    if (isset($date[1]) && isset($date[1]["value"]) && isset($date[1]["value2"])) {
      if (empty($timezone)) {
        $timezone = date_default_timezone_get();
      }
      $legislature_valid_period['timezone'] = $timezone;

      $startDateTime = new \DateTime($date[1]["value"], new \DateTimeZone($date[1]["timezone"]));
      $startDateTime->setTimezone(new \DateTimeZone($timezone));
      $startDateTime->setTime(0, 0, 0);
      $legislature_valid_period['start'] = $startDateTime->getTimestamp();

      $endDateTime = new \DateTime($date[1]["value2"], new \DateTimeZone($date[1]["timezone"]));
      $endDateTime->setTimezone(new \DateTimeZone($timezone));
      $endDateTime->setTime(23, 59, 50);
      $legislature_valid_period['end'] = $endDateTime->getTimestamp();
    }

    return $legislature_valid_period;
  }


  /**
   * The name of the parliament
   * @return string
   */
  public function getName() {
    $parliament_wrapper = entity_metadata_wrapper('taxonomy_term', $this->parliamentTerm);
    return $parliament_wrapper->name->value();
  }


  /**
   * Get the election date
   *
   * @return string
   * The date as timestamp
   */
  public function getElectionDate() {
    $parliament_wrapper = entity_metadata_wrapper('taxonomy_term', $this->parliamentTerm);
    return $parliament_wrapper->field_parliament_election->value();
  }


  /**
   * Get the id of the parliament
   *
   * @return int
   * The Drupal term tid
   */
  public function getId() {
    return $this->parliamentTerm->tid;
  }


  /**
   * Check if the parliament is a currently active/ valid election project
   *
   * @return bool
   */
  public function isActiveElectionProject() {
    $time = REQUEST_TIME;
    $lection_time_period = $this->getElectionValidTimePeriod();
    if (!empty($lection_time_period) && $time >= $lection_time_period['start'] && $time < $lection_time_period['end'] ) {
      return TRUE;
    }

    return FALSE;
  }


  /**
   * Check if the parliament is a currently active/ valid parliament/ legislature project
   *
   * @return bool
   */
  public function isActiveLegislatureProject() {
    $time = REQUEST_TIME;
    $lection_time_period = $this->getLegislatureValidTimePeriod();
    if (!empty($lection_time_period)  && $time >= $lection_time_period['start'] && $time < $lection_time_period['end'] ) {
      return TRUE;
    }

    return FALSE;
  }


  /**
   *
   * @param string $role
   * Can be "Deputy" or "Candidate". Optional, if empty all candidacies and mandates will
   * be loaded
   *
   * @return array
   * An array of uid and vids
   *
   * @deprecated maybe better use UserArchiveDatabase::loadUserRevisionVidsForArchive()
   * as it is quite the same query
   */
  public function getRelatedPoliticianUserRevisions($role = '') {
    $records = [];

    if (empty($role)) {
      $role = ['Deputy', 'Candidate'];
    }
    // db_select: user revision
    $query = db_select('user_revision', 'ur');
    $query->addExpression('MAX(ur.vid)', 'vid');
    $query->addField('ur', 'uid');

    // join taxonomy terms for parliament names
    $query->join('field_revision_field_user_parliament', 'u_parl', "u_parl.entity_type = 'user' AND ur.vid = u_parl.revision_id");
    $query->join('taxonomy_term_data', 'parliament', 'parliament.tid = u_parl.field_user_parliament_tid');

    $query->leftJoin('field_revision_field_user_fraction', 'fraction_tid', "fraction_tid.entity_type = 'user' AND fraction_tid.revision_id = ur.vid");
    $query->leftJoin('taxonomy_term_data', 'fraction', 'fraction.tid = fraction_tid.field_user_fraction_tid');

    // join revisionable roles for user_roles
    $query->join('field_revision_field_user_roles_for_view_mode_s', 'role_tid', "role_tid.entity_type = 'user' AND role_tid.revision_id = ur.vid");
    $query->join('taxonomy_term_data', 'role', 'role.tid = role_tid.field_user_roles_for_view_mode_s_tid');

    $query->condition('ur.status', '1');
    $query->condition('u_parl.field_user_parliament_tid', $this->getId());
    $query->condition('role.name', $role);
    $query->groupBy('ur.uid, u_parl.field_user_parliament_tid, role_tid.field_user_roles_for_view_mode_s_tid, fraction_tid.field_user_fraction_tid');

    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $records[] = $record;
    }

    return $records;
  }



}