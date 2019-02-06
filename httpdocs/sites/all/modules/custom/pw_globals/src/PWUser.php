<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 18.12.2018
 * Time: 08:58
 */

namespace Drupal\pw_globals;


/**
 * Class for extending the Drupal user object for methods and properties
 * which are helpful in the context of Abgeordnetenwatch
 */
class PWUser {

  /**
   * Define the role rids as constants
   */
  const ROLE_ADMINISTRATOR = 30037204;
  const ROLE_CONTENT_MANAGER = 51622513;
  const ROLE_POLITICIAN = 181527986;
  const ROLE_CANDIDATE = 185431326;
  const ROLE_DEPUTY = 140336230;
  const ROLE_PREMIUM_USER = 178386088;
  const ROLE_API_USER = 29859578;
  const ROLE_BLOCK_MANAGER = 127500594;
  const ROLE_WEBFORM_MANAGER = 52344559;
  const ROLE_METATAG_MANAGER = 109923392;


  /**
   * @var object
   * The Drupal user object, can be any user revision
   */
  protected $account;


  /**
   * @var int|string
   * The Drupal user uid
   */
  public $uid;


  /**
   * @var string
   * The Drupal account user name
   */
  public $name;


  /**
   * PWUser constructor.
   *
   * @param bool|int|string|object $account
   * If false the currently logged in user will be used. If this is an integer
   * or a numeric string it is the user uid and the user account will be loaded.
   * If it is an object it need to be the Drupal user object. It should be
   * the user revision of the Politician.
   */
  public function __construct($account = FALSE) {
    if (is_object($account) && isset($account->uid)) {
      $this->account = $account;
    }
    else if (is_numeric($account)) {
      $this->account = user_load($account);
    }
    else {
      global $user;
      $this->account = $user;
    }

    $this->uid = $this->account->uid;

    // for uid = 0 there is no name
    if (isset($this->account->name)) {
      $this->name = $this->account->name;
    }
  }


  /**
   * Check if the user has a role.
   *
   * @param int|string $role_id
   * The role id. Use the constants to define which role should be checked.
   *
   * @return bool
   */
  public function hasRole($role_id) {
    $roles = $this->account->roles;
    return array_key_exists($role_id, $roles);
  }


  /**
   * Check if the user is a politician. For politicians it is set in
   * user revisions by the roles taxonomy and cannot be done simply
   * by checking the user's roles
   *
   * @return bool
   */
  public function isPolitician() {
    try {
      $politicianUserRevision = new PoliticianUserRevision($this->account);
      $role = $politicianUserRevision->getPoliticianRole();
      if ($role == PoliticianUserRevision::CANDIDATE_ROLE_STRING || $role == PoliticianUserRevision::DEPUTY_ROLE_STRING) {
        return TRUE;
      }
      return FALSE;
    }
    catch (\Exception $e) {
      $error_message = 'An error appeared when trying to check if '. $this->getFullName() .'/ uid '. $this->getId() .' is a politician: '. $e->getMessage();
      watchdog_exception('pw_globals', $e, $error_message);
      drupal_set_message('An error appeared. Please contact the site administrator', 'warning');
      return FALSE;
    }
  }

  public function getAccount() {
    return $this->account;
  }


  /**
   * Get full name of the user. Taken from _pw_get_fullname
   *
   * @todo Use Entity Meta data Wrapper
   *
   * @return string
   */
  public function getFullName() {
    $fullname = '';

    $account = $this->account;
    if (!empty($account)) {
      $title = field_get_items('user', $account, 'field_user_prefix');
      $first_name = field_get_items('user', $account, 'field_user_fname');
      $last_name = field_get_items('user', $account, 'field_user_lname');

      if ($title) {
        $fullname .= $title[0]['value'] . ' ';
      }

      $fullname .= $first_name[0]['value'] . ' ' . $last_name[0]['value'];
    }

    return trim($fullname);
  }
}