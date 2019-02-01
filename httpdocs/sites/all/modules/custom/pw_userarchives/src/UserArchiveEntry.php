<?php


namespace Drupal\pw_userarchives;


/**
 * A single entry in the user archives table. Please assure that properties which
 * are stored to the user_archive_cache are named in the same way as in the table.
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
  public function __construct($uid, $user_name, $user_role, $vid, $parliament_name, $timestamp, $fraction_name = NULL, $actual_profile = 0, $user_joined = NULL, $user_retired = NULL, $question_form_open = 0, $number_of_questions = 0, $number_of_answers = 0, $number_of_standard_replies = 0, $id = NULL) {
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
    return new UserArchiveEntry($data['uid'], $data['user_name'], $data['user:_ole'], $data['vid'], $data['parliament_name'], $data['timestamp'], $data['fraction_name'], $data['actual_profile'], $data['user_joined'], $data['user_retired'], $data['question_form_open'], $data['number_of_questions'], $data['nummber_of_answers'], $data['number_of_standard_replies'], $data['id']);
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

  public function setId(int $id) {
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
  public function getQuestionFormOpen() {
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


}