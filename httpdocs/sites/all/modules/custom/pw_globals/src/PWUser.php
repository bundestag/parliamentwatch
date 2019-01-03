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
   * The Drupal user object
   */
  protected $account;


  /**
   * @var int|string
   * The Drupal user uid
   */
  public $uid;


  /**
   * PWUser constructor.
   *
   * @param bool $account
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

}