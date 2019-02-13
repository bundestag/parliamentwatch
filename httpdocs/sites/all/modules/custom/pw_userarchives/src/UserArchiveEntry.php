<?php


namespace Drupal\pw_userarchives;


use Drupal\pw_globals\PoliticianUserRevision;

/**
 * A single entry in the user archive cache table. Please assure that properties which
 * are stored to the user_archive_cache table are named in the same way as
 * the column in the table. See UserArchiveEntry->save() where the class properties
 * are turned to an array used for the insert/ update query
 */
class UserArchiveEntry {

  /**
   * @var null|int|string
   * The unique id of the user archive entry
   */
  protected $id;

  /**
   * @var int|string
   * The Drupal user uid
   */
  protected $uid;

  /**
   * @var string
   * The Drupal account user name
   */
  protected $user_name;


  /**
   * @var string
   * The role defined for the politician in the user revision.
   * @see \Drupal\pw_globals\PoliticianUserRevision::DEPUTY_ROLE_STRING
   * @see \Drupal\pw_globals\PoliticianUserRevision::CANDIDATE_ROLE_STRING
   */
  protected $user_role;


  /**
   * @var int
   * The revision vid of the user revision
   */
  protected $vid;


  /**
   * @var string
   * The parliament term name
   */
  protected $parliament_name;


  /**
   * @var string
   * This value is difficult - all the time the parliament election time
   * was stored here but in queries it was assumed that this timestamp is the
   * timestamp of the user revision. For know we do not change anything about this.
   *
   * Stored if the timestamp of the parliament election - but in queries this value
   * is misued.
   */
  protected $timestamp;


  /**
   * @var null|string
   * The fraction term name. Can be null.
   */
  protected $fraction_name;


  /**
   * @var int
   * Indicating if the user revision is the current user revision
   * of the Drupal user. Can be 0 and 1
   */
  protected $actual_profile;


  /**
   * @var string|null
   * The date the politician joined the parliament. Format Y-m-d
   */
  protected $user_joined;


  /**
   * @var string|null
   * The date the politician left the parliament. Format Y-m-d
   */
  protected $user_retired;


  /**
   * @var int
   * Indicating if the question form is open for the user revision. Can be 0
   * or 1. Attention: On frontend this value may not be used so a value of 1
   * is not a proof that the question form is open on the politician archive
   * profile and vice visa.
   */
  protected $question_form_open;


  /**
   * @var int
   * Timestamp which indicated when the $question_form_open value needs to
   * be revalidated
   */
  protected $question_form_open_change;

  /**
   * @var int
   * Number is answers flagged as standard reply
   */
  protected $number_of_standard_replies;

  /**
   * @var int
   * Number of questions, published and connected to the politician and
   * the parliament
   */
  protected $number_of_questions;

  /**
   * @var int
   * Number of answers not flagged as standard reply
   */
  protected $number_of_answers;


  /**
   * @var PoliticianUserRevision
   * The politicianUserRevision instance for the user archive entry
   */
  protected $politicianUserRevision;

  /**
   * UserArchiveEntry constructor.
   *
   * @param $uid
   * @param $user_name
   * @param $user_role
   * @param $vid
   * @param $parliament_name
   * @param $timestamp
   *
   *
   * @param null $fraction_name
   * @param int $actual_profile
   *
   * @param null|string $user_joined
   * The date in format Y-m-d
   *
   * @param null|string $user_retired
   * The date in format Y-m-d
   *
   * @param int $question_form_open
   * Can be 0 if form is closed for any reason or 1 when it is open
   *
   * @param null $question_form_open_change
   * @param int $number_of_questions
   *
   * @param int $number_of_answers
   * The number of answers which are not flagged with "is standard reply"
   *
   * @param int $number_of_standard_replies
   * The number of answers flagged with "is standard reply"
   *
   * @param null $id
   */
  public function __construct($uid, $user_name, $user_role, $vid, $parliament_name, $timestamp, $fraction_name = NULL, $actual_profile = 0, $user_joined = NULL, $user_retired = NULL, $question_form_open = 0, $question_form_open_change = NULL, $number_of_questions = 0, $number_of_answers = 0, $number_of_standard_replies = 0, $id = NULL) {
    $this->id = $id;
    $this->uid = $uid;
    $this->user_name = $user_name;
    $this->user_role = $user_role;
    $this->vid = $vid;
    $this->parliament_name = $parliament_name;
    $this->timestamp = $timestamp;
    $this->fraction_name = $fraction_name;
    $this->actual_profile = $actual_profile;
    $this->user_joined = $user_joined;
    $this->user_retired = $user_retired;
    $this->question_form_open = $question_form_open;
    $this->question_form_open_change = $question_form_open_change;
    $this->number_of_questions = $number_of_questions;
    $this->number_of_standard_replies = $number_of_standard_replies;
    $this->number_of_answers = $number_of_answers;
  }


  /**
   * Helper to create a class from an array of field values received from database
   *
   * @param array $data
   *
   * @return \Drupal\pw_userarchives\UserArchiveEntry
   */
  public static function createFromDataBaseArray(array $data) {
    return new UserArchiveEntry($data['uid'], $data['user_name'], $data['user_role'], $data['vid'], $data['parliament_name'], $data['timestamp'], $data['fraction_name'], $data['actual_profile'], $data['user_joined'], $data['user_retired'], $data['question_form_open'], $data['question_form_open_change'], $data['number_of_questions'], $data['number_of_answers'], $data['number_of_standard_replies'], $data['id']);
  }


  /**
   * Delete the user archive entry
   */
  public function delete() {
    db_delete('user_archive_cache')
      ->condition('id', $this->id)
      ->execute();
  }


  /**
   * Update or insert the user archive entry
   *
   * @throws \Exception
   */
  public function save() {
    $transaction = db_transaction();
    try {
      $isNew = FALSE;
      if ($this->id == NULL) {
        $isNew = TRUE;
        $query = db_insert('user_archive_cache');
      }
      else {
        $query = db_update('user_archive_cache');
        $query->condition('id', $this->getId());
      }

      // turn the object into an associative array and assure
      // that the properties of the object exist in table
      $fields = get_object_vars($this);
      foreach ($fields as $key => $value) {
        if (!db_field_exists('user_archive_cache', $key)) {
          unset($fields[$key]);
        }
      }
      unset($fields['id']);
      $query->fields($fields);

      if ($isNew) {
        $id = $query->execute();
        $this->setId($id);
      }
      else {
        $query->execute();
      }
    }
    catch (\Exception $e) {
      $transaction->rollback();
      throw $e;
    }
  }

  /**
   * @return mixed
   */
  public function getId() {
    return $this->id;
  }

  public function setId($id) {
    $this->id = $id;
  }

  /**
   * @return mixed
   */
  public function getUid() {
    return $this->uid;
  }

  /**
   * @param mixed $uid
   */
  public function setUid($uid) {
    $this->uid = $uid;
  }

  /**
   * @return mixed
   */
  public function getUserName() {
    return $this->user_name;
  }

  /**
   * @param mixed $user_name
   */
  public function setUserName($user_name) {
    $this->user_name = $user_name;
  }

  /**
   * @return mixed
   */
  public function getUserRole() {
    return $this->user_role;
  }

  /**
   * @param mixed $user_role
   */
  public function setUserRole($user_role) {
    $this->user_role = $user_role;
  }

  /**
   * @return mixed
   */
  public function getVid() {
    return $this->vid;
  }

  /**
   * @param mixed $vid
   */
  public function setVid($vid) {
    $this->vid = $vid;
  }

  /**
   * @return mixed
   */
  public function getParliamentName() {
    return $this->parliament_name;
  }

  /**
   * @param mixed $parliament_name
   */
  public function setParliamentName($parliament_name) {
    $this->parliament_name = $parliament_name;
  }

  /**
   * @return mixed
   */
  public function getNumberOfQuestions() {
    return $this->number_of_questions;
  }

  /**
   * @param mixed $number_of_questions
   */
  public function setNumberOfQuestions($number_of_questions) {
    $this->number_of_questions = $number_of_questions;
  }

  /**
   * @return mixed
   */
  public function getTimestamp() {
    return $this->timestamp;
  }

  /**
   * @param mixed $timestamp
   */
  public function setTimestamp($timestamp) {
    $this->timestamp = $timestamp;
  }

  /**
   * @return mixed
   */
  public function getFractionName() {
    return $this->fraction_name;
  }

  /**
   * @param mixed $fraction_name
   */
  public function setFractionName($fraction_name) {
    $this->fraction_name = $fraction_name;
  }

  /**
   * @return mixed
   */
  public function getActualProfile() {
    return $this->actual_profile;
  }

  /**
   * @param mixed $actual_profile
   */
  public function setActualProfile($actual_profile) {
    $this->actual_profile = $actual_profile;
  }

  /**
   * @return mixed
   */
  public function getUserJoined() {
    return $this->user_joined;
  }

  /**
   * @param mixed $user_joined
   */
  public function setUserJoined($user_joined) {
    $this->user_joined = $user_joined;
  }

  /**
   * @return mixed
   */
  public function getUserRetired() {
    return $this->user_retired;
  }

  /**
   * @param mixed $user_retired
   */
  public function setUserRetired($user_retired) {
    $this->user_retired = $user_retired;
  }

  /**
   * @return mixed
   */
  public function isQuestionFormOpen() {
    return $this->question_form_open;
  }

  /**
   * @param mixed $question_form_open
   */
  public function setQuestionFormOpen($question_form_open) {
    $this->question_form_open = $question_form_open;
  }

  /**
   * @return mixed
   */
  public function getNumberOfStandardReplies() {
    return $this->number_of_standard_replies;
  }

  /**
   * @param mixed $number_of_standard_replies
   */
  public function setNumberOfStandardReplies($number_of_standard_replies) {
    $this->number_of_standard_replies = $number_of_standard_replies;
  }


  /**
   * @param string $timezone
   * Optional parameter to set the timezone. If none defined the timestamp
   * in the default timezone will be returned. @see date_default_timezone_get()
   *
   * @return int
   * The timestamp in the default timezone or in the set timezone
   *
   * @throws \Exception
   */
  public function getQuestionFormOpenChange($timezone = '') {
    $change_date = NULL;
    if (is_numeric($this->question_form_open_change)) {
      if (empty($timezone)) {
        $timezone = date_default_timezone_get();
      }
      $dateTime = new \DateTime(date('Y-m-d\TH:i:s', $this->question_form_open_change), new \DateTimeZone('UTC'));
      if ($timezone != 'UTC') {
        $dateTime->setTimezone(new \DateTimeZone($timezone));
      }

      return $dateTime->getTimestamp();
    }

    return $change_date;
  }


  /**
   * @param int|NULL $question_form_open_change
   * The timestamp of the date in UTC
   *
   * @param string $timezone
   * The timezone in which the given timestamp is defined. If nothing is defined
   * and $question_form_open_change has a value the default page timezone will be used
   *
   * @throws \Exception
   */
  public function setQuestionFormOpenChange($question_form_open_change = NULL, $timezone = '') {
    if ($question_form_open_change !== NULL && is_int($question_form_open_change)) {
      if (empty($timezone)) {
        $timezone = date_default_timezone_get();
      }
      $dateTime = new \DateTime(date('Y-m-d\TH:i:s', $question_form_open_change), new \DateTimeZone($timezone));
      if ($timezone != 'UTC') {
        $dateTime->setTimezone(new \DateTimeZone('UTC'));
      }

      $this->question_form_open_change = $dateTime->getTimestamp();
    }
    else {
      $this->question_form_open_change = $question_form_open_change;
    }
  }


  /**
   * @return int
   */
  public function getNumberOfAnswers() {
    return $this->number_of_answers;
  }


  /**
   * @param int $number_of_answers
   */
  public function setNumberOfAnswers($number_of_answers) {
    $this->number_of_answers = $number_of_answers;
  }


  /**
   * @return \Drupal\pw_globals\PoliticianUserRevision|FALSE
   * FALSE if none was found
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function getPoliticianUserRevision() {
    if ($this->politicianUserRevision === NULL) {
      $this->politicianUserRevision = PoliticianUserRevision::loadFromUidAndVid($this->getUid(), $this->getVid());
    }
    return $this->politicianUserRevision;
  }


  /**
   * @param \Drupal\pw_globals\PoliticianUserRevision $politicianUserRevision
   */
  public function setPoliticianUserRevision(PoliticianUserRevision $politicianUserRevision) {
    $this->politicianUserRevision = $politicianUserRevision;
  }


  public function updateQuestionFormSettings() {
    $politicianUserRevision = $this->getPoliticianUserRevision();
    $question_form_open = (int) UserArchiveManager::checkIfQuestionFormOpen($politicianUserRevision);
    $question_form_open_change = UserArchiveManager::calcQuestionFormOpenChange($politicianUserRevision);
    if ($question_form_open_change !== NULL) {
      $timezone = 'UTC';
    }
    else {
      $timezone = '';
    }
    $this->setQuestionFormOpen($question_form_open);
    $this->setQuestionFormOpenChange($question_form_open_change, $timezone);
  }


  /**
   * Helper to get a new UserArchiveEntry instance from a PoliticianUserRevision
   *
   * @param \Drupal\pw_globals\PoliticianUserRevision $politicianUserRevision
   *
   * @return \Drupal\pw_userarchives\UserArchiveEntry|NULL
   * NULL if it was not possible to collect all data
   *
   */
  public static function createFromPolicitianUserRevision(PoliticianUserRevision $politicianUserRevision) {
    try {
      $user_role = $politicianUserRevision->getPoliticianRole();

      $fraction_name = NULL;
      $fraction = $politicianUserRevision->getFraction();
      if ($fraction !== NULL) {
        $fraction_name = $fraction->getName();
      }

      $question_form_open = (int) UserArchiveManager::checkIfQuestionFormOpen($politicianUserRevision);
      $question_form_open_change = UserArchiveManager::calcQuestionFormOpenChange($politicianUserRevision);

      $uid = $politicianUserRevision->getUid();
      $vid = $politicianUserRevision->getVid();
      $user_name = $politicianUserRevision->getUserName();

      $parliament = $politicianUserRevision->getParliament();
      $parliament_name = $parliament->getName();
      $timestamp = $parliament->getElectionDate();
      $number_of_questions = count($politicianUserRevision->getQuestionsNids());
      $number_of_answers = $politicianUserRevision->getAnswersNumbers('non-standard');
      $number_of_standard_replies = $politicianUserRevision->getAnswersNumbers('standard');

      $user_joined = $politicianUserRevision->getJoinedDate();
      if ($user_joined !== NULL) {
        $user_joined = date('Y-m-d', $user_joined);
      }
      $user_retired = $politicianUserRevision->getRetiredDate();
      if ($user_retired !== NULL) {
        $user_retired = date('Y-m-d', $user_retired);
      }

      $actual_profile = (int) $politicianUserRevision->isActualProfile();

      return new UserArchiveEntry($uid, $user_name, $user_role, $vid, $parliament_name, $timestamp, $fraction_name, $actual_profile , $user_joined, $user_retired, $question_form_open, $question_form_open_change, $number_of_questions, $number_of_answers, $number_of_standard_replies );
    }
    catch (\Exception $e) {
      watchdog_exception('pw_userarchives', $e, $e->getMessage());
      return NULL;
    }
  }


  /**
   * @param \Drupal\pw_globals\PoliticianUserRevision $politicianUserRevision
   *
   * @return bool|\Drupal\pw_userarchives\UserArchiveEntry
   * FALSE if it was not possible to load one
   */
  public static function loadForPoliticianUserRevision(PoliticianUserRevision $politicianUserRevision) {
    try {
      $query = db_select('user_archive_cache', 'uac')
        ->condition('uid', $politicianUserRevision->getUid())
        ->condition('vid', $politicianUserRevision->getVid())
        ->fields('uac')
        ->execute();
      $result = $query->fetchAssoc();

      if (!empty($result)) {
        $userArchiveCache = self::createFromDataBaseArray($result);
        $userArchiveCache->setPoliticianUserRevision($politicianUserRevision);
        return $userArchiveCache;
      }
      else {
        return FALSE;
      }
    }
    catch (\Exception $e) {
      watchdog_exception('pw_userarchives', $e, $e->getMessage());
      return FALSE;
    }
  }
}