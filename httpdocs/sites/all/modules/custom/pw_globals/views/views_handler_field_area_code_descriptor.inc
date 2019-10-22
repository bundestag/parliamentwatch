<?php



class views_handler_field_area_code_descriptor extends views_handler_field {
  public function query() {
  }


  public function render($values) {
    $area_code = $this->getOnlyAreaCode($values);
    if ($area_code) {
      $descriptors_array = $this->prepareDescriptorsArray($values);
      if (isset($descriptors_array[$area_code])) {
        return $descriptors_array[$area_code];
      }
    }
    return '';
  }


  /**
   * Get the only one area code - if there are more than one area codes it returns FALSE
   * @param $values
   *
   * @return bool|string
   */
  protected function getOnlyAreaCode($values) {
    if (isset($values->field_field_constituency_area_codes[0]["rendered"]["#markup"]) &&
      count($values->field_field_constituency_area_codes) == 1
    ) {
      return $values->field_field_constituency_area_codes[0]["rendered"]["#markup"];
    }
    return FALSE;
  }


  protected function prepareDescriptorsArray($values) {
    $descriptors_array = [];
    $term = $values->_field_data["tid"]["entity"];
    $wrapper = entity_metadata_wrapper('taxonomy_term', $term);
    $descriptors = $wrapper->field_constituency_ac_descriptor->value();
    if (!empty($descriptors)) {
      $descriptors_working_array = explode(',', $descriptors);
      foreach ($descriptors_working_array as $single_descriptor) {
        $single_descriptor_array = explode(':', $single_descriptor);
        if (!empty($single_descriptor_array) && isset($single_descriptor_array[1])) {
          $descriptors_array[$single_descriptor_array[0]] = $single_descriptor_array[1];
        }
      }
    }

    return $descriptors_array;
  }
}
