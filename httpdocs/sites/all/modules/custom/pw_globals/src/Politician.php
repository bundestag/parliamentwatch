<?php


namespace Drupal\pw_globals;

use Drupal\pw_globals\Exception\PwGlobalsException;

/**
 * Representing a single politican
 */
class Politician {


  /**
   * @var \Drupal\pw_globals\PWUser
   * The PWUser object for the Drupal user account
   */
  protected $pwUser;


  /**
   * Politician constructor.
   *
   * @param object $account
   * The Drupal user account of the politician or an user revision
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function __construct($account) {
    if (!is_object($account) || !isset($account->uid)) {
      throw new PwGlobalsException('Invalid argument "account" (value: '.  $account .' for Politician)');
    }

    $pwUser = new PWUser($account);
    if (!$pwUser->isPolitician()) {
      throw new PwGlobalsException('The user with id '.  $account->uid .' is not a politician');
    }
    $this->pwUser = $pwUser;
  }


  /**
   * Get the id of the politician
   *
   * @return int
   * The Drupal user uid
   */
  public function getId() {
    return $this->pwUser->uid;
  }


  /**
   * Get the Drupal user object for the politician
   *
   * @return object
   */
  public function getPwUser() {
    return $this->pwUser;
  }


  /**
   * Get full name of the politician. Taken from _pw_get_fullname
   *
   * @todo Use Entity Meta data Wrapper
   *
   * @return string
   */
  public function getFullName() {
    return $this->pwUser->getFullName();
  }


  /**
   * Load a Politician by uid and optionally by vid
   *
   * @param int|string $uid
   * The Drupal user uid
   *
   * @param bool|int|string $vid
   * The user revision vid
   *
   * @return \Drupal\pw_globals\Politician|null
   * Null if it was not possible to load the user object or if
   * the user is not a politician
   */
  public static function loadFromUid($uid, $vid = FALSE) {
    try {
      if (!$vid) {
        $account = user_load($uid);
      }
      else {
        $account = user_revision_load($uid, $vid);
      }

      if ($account) {
        return new Politician($account);
      }
      else {
        return NULL;
      }
    }
    catch (\Exception $e) {
      watchdog_exception('pw_globals', $e, $e->getMessage());
      return NULL;
    }
  }

}