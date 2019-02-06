<?php


namespace Drupal\pw_globals;


use Drupal\pw_globals\Exception\PwGlobalsException;


/**
 * Wraps a fraction term into a helper class. Use this for any properties and
 * methods related to fractions.
 */
class Fraction {

  /**
   * @var object
   * The Drupal term object of the fraction
   */
  protected $fractionTerm;

  /**
   * Fraction constructor.
   *
   * @param $term
   *
   * @throws \Drupal\pw_globals\Exception\PwGlobalsException
   */
  public function __construct($term) {
    if (!is_object($term) || !isset($term->tid)) {
      throw new PwGlobalsException('Invalid argument "account" (value: '.  $term .' for Politician');
    }

    $this->fractionTerm = $term;
  }


  /**
   * Get the fraction name
   *
   * @return string
   */
  public function getName() {
    $fraction_wrapper = entity_metadata_wrapper('taxonomy_term', $this->fractionTerm);
    return $fraction_wrapper->name->value();
  }

}