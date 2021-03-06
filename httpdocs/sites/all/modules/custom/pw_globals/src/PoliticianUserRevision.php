<?php


namespace Drupal\pw_globals;

use Drupal\pw_globals\Exception\PwGlobalsException;


/**
 * Class representing an user revision for a politician. As such it is some kind
 * of pre-step to the datastructure based on Mandate and Candidacy classes.
 */
class PoliticianUserRevision {

  /**
   * Term tids used for the roles deputy and candidate
   */
  const DEPUTY_ROLE_TERM_TID = 7028;
  const CANDIDATE_ROLE_TERM_TID = 7029;

  /**
   * Strings used for the roles deputy and candidate
   */
  const DEPUTY_ROLE_STRING = 'deputy';
  const CANDIDATE_ROLE_STRING = 'candidate';


  /**
   * @var object
   * Drupal user object of the user revision
   */
  protected $userRevision;


  /**
   * @var array|NULL
   * Array of published node nids of questions to the politician. These
   * are just the questions related to the parliament which is connected to the
   * user revision. NULL if no database query run yet, empty array if no questions
   * were found
   */
  protected $questionNids;


  /**
   * PoliticianUserRevision constructor.
   *
   * @param object $user_revision
   * Drupal user object of the user revision
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function __construct($user_revision) {
    if (!is_object($user_revision) || !isset($user_revision->uid)) {
      throw new PwGlobalsException('Invalid argument "account" (value: '.  $user_revision .' for Politician');
    }
    $this->userRevision = $user_revision;
  }


  /**
   * Get a Parliament object of the referenced parliament term
   *
   * @return \Drupal\pw_globals\Parliament
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function getParliament() {
    $userRevisionWrapper = entity_metadata_wrapper('user', $this->userRevision);
    return new Parliament($userRevisionWrapper->field_user_parliament->value());
  }


  /**
   * Get the role of the politician
   *
   * @return string|bool
   * Can be 'candidate' or 'deputy'. If the user revision was not one
   * of a politician it returns FALSE
   */
  public function getPoliticianRole() {
    $userRevisionWrapper = entity_metadata_wrapper('user', $this->userRevision);
    foreach ($userRevisionWrapper->field_user_roles_for_view_mode_s->getIterator() as $delta => $term_wrapper) {
      $tid = $term_wrapper->tid->value();
      if ($tid == self::DEPUTY_ROLE_TERM_TID) {
        return self::DEPUTY_ROLE_STRING;
      }

      if ($tid == self::CANDIDATE_ROLE_TERM_TID) {
        return self::CANDIDATE_ROLE_STRING;
      }
    }

    return FALSE;
  }


  /**
   * Get a Fraction object of the referenced fraction
   *
   * @return \Drupal\pw_globals\Fraction|null
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function getFraction() {
    $userRevisionWrapper = entity_metadata_wrapper('user', $this->userRevision);
    $value = $userRevisionWrapper->field_user_fraction->value();
    if ($value === NULL) {
      return NULL;
    }

    return new Fraction($value);
  }


  /**
   * Helper to load a PoliticianUserRevision from uid and vid
   *
   * @param int|string $uid
   * The Drupal user uid
   *
   * @param int|string $vid
   * The Drupal user revision vid
   *
   * @return \Drupal\pw_globals\PoliticianUserRevision|null
   * NULL if no user revision was loaded or the the loaded user
   * revision was not one of a politician
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public static function loadFromUidAndVid($uid, $vid) {
    $user_revision = user_revision_load($uid, $vid);
    if ($user_revision) {
      $pwUser = new PWUser($user_revision);
      if ($pwUser->isPolitician()) {
        return new PoliticianUserRevision($user_revision);
      }
    }

    return NULL;
  }


  /**
   * Get the value of the joined date field.
   *
   * @return string|NULL
   * The timestamp or NULL
   */
  public function getJoinedDate() {
    $userRevisionWrapper = entity_metadata_wrapper('user', $this->userRevision);
    return $userRevisionWrapper->field_user_joined->value();
  }


  /**
   * Get the value of the retired date field.
   *
   * @return string|NULL
   * The timestamp or NULL
   */
  public function getRetiredDate() {
    $userRevisionWrapper = entity_metadata_wrapper('user', $this->userRevision);
    return $userRevisionWrapper->field_user_retired->value();
  }

  /**
   * Checks if the question form is closed by configuration in user revision
   *
   * @return bool
   */
  public function isQuestionFormClosed() {
    $userRevisionWrapper = entity_metadata_wrapper('user', $this->userRevision);
    return (bool) $userRevisionWrapper->field_user_question_form_closed->value();
  }


  /**
   * Get the node nids of questions asked to the politician during the
   * parliament period
   *
   * @return array
   * Array of Drupal node nids, empty if none found
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function getQuestionsNids() {
    if ($this->questionNids === NULL) {
      $parliament = $this->getParliament();
      $entityFieldQuery = new \EntityFieldQuery();
      $entityFieldQuery->entityCondition('entity_type', 'node')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->entityCondition('bundle', 'dialogue')
        ->fieldCondition('field_dialogue_recipient', 'target_id', $this->getUid())
        ->fieldCondition('field_parliament', 'tid', $parliament->getId());

      if ($this->getPoliticianRole() == self::DEPUTY_ROLE_STRING) {
        $entityFieldQuery->fieldCondition('field_dialogue_before_election', 'value', 0);
      }

      if ($this->getPoliticianRole() == self::CANDIDATE_ROLE_STRING) {
        $entityFieldQuery->fieldCondition('field_dialogue_before_election', 'value', 1);
      }

      $result = $entityFieldQuery->execute();
      if (isset($result['node'])) {
        $this->questionNids = array_keys($result['node']);
      }
      else {
        $this->questionNids = [];
      }
    }

    return $this->questionNids;
  }


  /**
   * Get the answers of the politician to the questions
   *
   * @param string $filter
   * By default the function will return all found and published answered related
   * to the questions connected to this politician and parliament. It
   * can be filtered to get only standard answers ("standard") or not standard
   * answers ("non-standard")
   *
   * @return int
   * The number of answers found
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function getAnswersNumbers($filter = 'all') {
    $comments = $this->getAnswers($filter);
    return count($comments);
  }


  /**
   * Get the number of answered questions
   *
   * @return int
   * The number of questions answered (without standard replies)
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function getNumberOfAnsweredQuestions() {
    $result = 0;
    $comments = $this->getAnswers('non-standard');
    if (!empty($comments)) {
      $comments_objects = comment_load_multiple(array_keys($comments));
      $answered_questions = [];
      foreach ($comments_objects as $comment_object) {
        $answered_questions[$comment_object->nid] = $comment_object->nid;
      }

      $result = count($answered_questions);
    }

    return $result;
  }


  /**
   * @param string $filter
   * Default to all, can be 'standard' or 'non-standard'
   *
   * @return array
   * Each key is the comment cid and holds an array with cid and node_type as
   * key/ values. Empty if none was found
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function getAnswers($filter = 'all') {
    $result = array();
    $question_nids = $this->getQuestionsNids();
    if (!empty($question_nids)) {
      $entityFieldQuery = new \EntityFieldQuery();
      $entityFieldQuery->entityCondition('entity_type', 'comment')
        ->propertyCondition('status', COMMENT_PUBLISHED)
        ->propertyCondition('nid', $question_nids);

      if ($filter == 'standard') {
        $entityFieldQuery->fieldCondition('field_dialogue_is_standard_reply', 'value', 1);
      }
      if ($filter == 'non-standard') {
        $entityFieldQuery->fieldCondition('field_dialogue_is_standard_reply', 'value', 0);
      }

      $query_result = $entityFieldQuery->execute();
      if (isset($query_result['comment'])) {
        $result = $query_result['comment'];
      }
    }

    return $result;
  }


  /**
   * Checks if the user revision represents an active/ valid mandate for the
   * connected parliament
   */
  public function isActiveMandate($time = '') {
    return ($this->getPoliticianRole() == self::DEPUTY_ROLE_STRING && $this->isActiveMember($time));
  }


  /**
   * Checks if the user revision represents an active/ valid candidacy for the
   * parliament
   */
  public function isActiveCandidacy($time = '') {
    return ($this->getPoliticianRole() == self::CANDIDATE_ROLE_STRING && $this->isActiveMember($time));
  }


  /**
   * Checks if the profile is active for a specific time. Which means that
   * the politician did not retire and he joined before the set time (for mandate
   * or candidacy)
   *
   * @param string $check_date
   * The timestamp. If empty the current time
   *
   * @return bool
   *
   */
  public function isActiveMember($check_date = '') {
    if (empty($check_date)) {
      $check_date = REQUEST_TIME;
    }
    $joined_date = $this->getJoinedDate();
    $retired_date = $this->getRetiredDate();

    if ($joined_date !== NULL && $joined_date > $check_date) {
      return FALSE;
    }

    if ($retired_date !== NULL && $retired_date <= $check_date) {
      return FALSE;
    }

    return TRUE;
  }


  /**
   * Checks if the user revision is the standard user revision
   *
   * @return bool
   */
  public function isActualProfile() {
    $query = db_select('users', 'u')
      ->condition('uid', $this->userRevision->uid)
      ->condition('vid', $this->userRevision->vid)
      ->fields('u', ['uid'])
      ->execute();

    $result = $query->fetchAssoc();
    if (!$result || empty($result)) {
      return FALSE;
    }
    else {
      return TRUE;
    }
  }


  /**
   * Get the user uid
   *
   * @return int|string
   */
  public function getUid() {
    return $this->userRevision->uid;
  }



  /**
   * Get the user revision vid
   *
   * @return int|string
   */
  public function getVid() {
    return $this->userRevision->vid;
  }

  /**
   * Get the Drupal user name
   *
   * @return string
   */
  public function getUserName() {
    return $this->userRevision->name;
  }
}