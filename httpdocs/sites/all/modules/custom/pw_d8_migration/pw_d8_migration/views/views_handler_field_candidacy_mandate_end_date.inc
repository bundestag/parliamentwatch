<?php


use Drupal\pw_globals\PoliticianUserRevision;

class views_handler_field_candidacy_mandate_end_date extends views_handler_field {
  public function query() {
  }


  public function render($values) {
    // load the user revision
    $politicianUserRevision = PoliticianUserRevision::loadFromUidAndVid($values->user_archive_cache_uid, $values->vid);
    $end_date = $politicianUserRevision->getRetiredDate();
    if (!$end_date) {
      return NULL;
    }

    if (!$this->hasFollowingCandidacyMandate($politicianUserRevision)) {
      return date('Y-m-d', $end_date);
    }

    return NULL;
  }

  protected function hasFollowingCandidacyMandate(PoliticianUserRevision $politicianUserRevision) {
    $fraction = $politicianUserRevision->getFraction();
    $parliament = $politicianUserRevision->getParliament();
    $end_date = date('Y-m-d', $politicianUserRevision->getJoinedDate());
    if ($fraction && $parliament) {
      $query = db_select('user_archive_cache', 'uac')
        ->condition('uid', $politicianUserRevision->getUid())
        ->condition('user_joined', $end_date, '>=')
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
