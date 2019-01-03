<?php

/**
 * @file
 * Checks if field fraction is empty and set it to name of party.
 */
$plugin = array(
  'form' => 'set_fraction_to_party_form',
  'callback' => 'set_fraction_to_party',
  'name' => 'Set Fraction To Party If Empty',
  'multi' => 'loop',
  'category' => 'Custom',
  );

function set_fraction_to_party_form($importer, $element_key, $settings) {
  $form = array();
  $form['help']['#value'] = t('My plugin can do awesome things like setting fraction name to party name.');
  return $form;
}

function set_fraction_to_party($source, $item_key, $element_key, &$field, $settings) {

  $party = trim($source->current_item['xpathparser:24']);
  $parliament = trim($source->current_item['xpathparser:25']);
  $roles = $source->current_item['xpathparser:4'];
  if(in_array('Deputy', $roles) && empty($field)){
    $field = $party;

    // overwrite default for EU and Bundestag
    if(strpos($parliament, 'EU') !== FALSE){
      if(in_array($party, array('CDU', 'CSU'))){
        $field = 'CDU/CSU (EVP)';
      }
      elseif(in_array($party, array('SPD'))){
        $field = 'SPD (S&D)';
      }
      elseif(in_array($party, array('AfD', 'ALFA', 'FAMILIEN-PARTEI'))){
        $field = 'AfD/ALFA/FAMILIEN-PARTEI (EKR)';
      }
      elseif(in_array($party, array('FDP', 'FREIE WÄHLER'))){
        $field = 'DIE LINKE (GUE/NGL)';
      }
      elseif(in_array($party, array('DIE GRÜNEN', 'PIRATEN', 'ÖDP'))){
        $field = 'DIE GRÜNEN/PIRATEN/ÖDP (Grüne/EFA)';
      }
    }
    elseif(strpos($parliament, 'Bundestag') !== FALSE){
      if(in_array($party, array('CDU', 'CSU'))){
        $field = 'CDU/CSU';
      }
    }
  }
}
