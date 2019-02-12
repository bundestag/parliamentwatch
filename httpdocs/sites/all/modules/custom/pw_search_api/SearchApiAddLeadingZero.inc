<?php

/**
 * @file
 * Provides SearchApiAddLeadingZero.
 */

/**
 * Processor for zero-padding area codes.
 */
class SearchApiAddLeadingZero extends SearchApiAbstractProcessor {

  public function preprocessIndexItems(array &$items) {
    $zero_pad = function ($input) {
      return str_pad($input, 5, '0', STR_PAD_LEFT);
    };

    foreach ($items as &$item) {
      foreach (array_keys($this->options['fields']) as $field) {
        if (search_api_list_nesting_level($item[$field]['type']) == 1 && is_array($item[$field]['value'])) {
          $item[$field]['value'] = array_unique(array_merge($item[$field]['value'], array_map($zero_pad, $item[$field]['value'])));
        }
        elseif (search_api_list_nesting_level($item[$field]['type']) == 2 && isset($item[$field]['value'][0]) && is_array($item[$field]['value'][0])) {
          $item[$field]['value'][0] = array_unique(array_merge($item[$field]['value'][0], array_map($zero_pad, $item[$field]['value'][0])));
        }
      }
    }
  }
}
