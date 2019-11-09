<?php


use Drupal\pw_globals\PoliticianUserRevision;

class views_handler_field_candidacy_mandate_start_date extends views_handler_field {
  public function query() {
  }


  public function render($values) {
    // load the user revision
    $politicianUserRevision = PoliticianUserRevision::loadFromUidAndVid($values->user_archive_cache_uid, $values->vid);
    $start_date = $politicianUserRevision->getJoinedDate();
    if (!$start_date) {
      return NULL;
    }

    if (!$this->hasPreviousCandidacyMandate($politicianUserRevision)) {
      return date('Y-m-d', $start_date);
    }

    return NULL;
  }

  protected function hasPreviousCandidacyMandate(PoliticianUserRevision $politicianUserRevision) {
    $fraction = $politicianUserRevision->getFraction();
    $parliament = $politicianUserRevision->getParliament();
    $joined_date = date('Y-m-d', $politicianUserRevision->getJoinedDate());
    if ($fraction && $parliament) {
      $query = db_select('user_archive_cache', 'uac')
        ->condition('uid', $politicianUserRevision->getUid())
        ->condition('user_retired', $joined_date, '<=')
        ->condition('user_role', $politicianUserRevision->getPoliticianRole())
        ->condition('parliament_name', $parliament->getName())
        ->condition('fraction_name', $fraction->getName(), '!=')
        ->fields('uac')
        ->execute();
      $result = $query->fetchAssoc();
      if (!empty($result)) {
        return TRUE;
      }
    }

    return FALSE;
  }
}
