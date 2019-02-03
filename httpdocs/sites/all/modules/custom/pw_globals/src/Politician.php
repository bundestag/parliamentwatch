<?php


namespace Drupal\pw_globals;

use Drupal\pw_globals\Exception\PwGlobalsException;
use Drupal\pw_userarchives\UserArchiveManager;

/**
 * Representing a single politican
 */
class Politician {


  /**
   * @var object
   * The DRupal user object
   */
  protected $account;


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
      throw new PwGlobalsException('Invalid argument "account" (value: '.  $account .' for Politician');
    }
    $this->account = $account;
  }


  /**
   * Get the id of the politician
   *
   * @return int
   * The Drupal user uid
   */
  public function getId() {
    return $this->account->uid;
  }


  /**
   * Get the Drupal user object for the politician
   *
   * @return object
   */
  public function getAccount() {
    return $this->account;
  }


  /**
   * Get full name of the politician. Taken from _pw_get_fullname
   *
   * @todo Use Entity Meta data Wrapper
   *
   * @return string
   */
  public function getFullName() {
    $fullname = '';

    if (!empty($user)) {
      $title = field_get_items('user', $user, 'field_user_prefix');
      $first_name = field_get_items('user', $user, 'field_user_fname');
      $last_name = field_get_items('user', $user, 'field_user_lname');

      if ($title) {
        $fullname .= $title[0]['value'] . ' ';
      }

      $fullname .= $first_name[0]['value'] . ' ' . $last_name[0]['value'];
    }

    return trim($fullname);
  }
}