<?php


/**
 * Field showing the overall income for a sidejob
 */
class views_handler_filter_sidejobs_income extends views_handler_field_entity {

  public function render($values) {
    $output = '';
    $node = $this->get_value($values);
    $income_range = pw_sidejobs_income_range($node);

    if (!empty($income_range)) {
      $min = number_format($income_range[0], '0', ',', '.');
      $max = number_format($income_range[1], '0', ',', '.');
      $output = $min . '–' . $max . ' €';
    }

    return $output;
  }
}