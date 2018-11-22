<?php

/**
 * @file
 * Provides VoteSearchAlterCallback.
 */

/**
 * Adds user revision fields.
 */
class VoteSearchAlterCallback extends SearchApiAbstractAlterCallback {

  /**
   * Returns TRUE for the vote index, FALSE otherwise.
   *
   * @param SearchApiIndex $index
   *   The index.
   *
   * @return boolean
   *   TRUE for the vote index, FALSE otherwise.
   */
  public function supportsIndex(SearchApiIndex $index) {
    return $index->machine_name == 'vote_index';
  }

  /**
   * Declares additional fields.
   *
   * @return array
   *   The info array for the additional fields.
   */
  public function propertyInfo() {
    return [
      'politician_fname' => [
        'label' => t('First name'),
        'type' => 'string',
        'description' => t("The politician's first name"),
      ],
      'politician_lname' => [
        'label' => t('Last name'),
        'type' => 'string',
        'description' => t("The politician's last name"),
      ],
      'politician_full_name' => [
        'label' => t('Full name'),
        'type' => 'text',
        'description' => t("The politician's full name"),
      ],
      'politician_uri' => [
        'label' => t('URL'),
        'type' => 'uri',
        'description' => t("The politician's URL"),
      ],
      'politician_picture_uri' => [
        'label' => t('Profile picture'),
        'type' => 'uri',
        'description' => t("The politician's profile picture"),
      ],
      'politician_constituency_name' => [
        'label' => t("Constituency"),
        'type' => 'string',
        'description' => t("The politician's constituency"),
      ],
      'politician_constituency_area_codes' => [
        'label' => t("Area codes"),
        'type' => 'list<text>',
        'description' => t("The area codes of the politician's constituency"),
      ],
      'politician_political_faction' => [
        'label' => t('Political faction'),
        'type' => 'string',
        'description' => t("The politician's political faction"),
      ],
    ];
  }

  /**
   * Adds user revision fields.
   *
   * @param array $items
   *   The items to be indexed.
   */
  public function alterItems(array &$items) {
    foreach ($items as &$item) {
      $politician = $this->loadPolitician($item);
      $item->politician_fname = $politician->field_user_fname[LANGUAGE_NONE][0]['value'];
      $item->politician_lname = $politician->field_user_lname[LANGUAGE_NONE][0]['value'];
      $item->politician_full_name = _pw_get_fullname($politician);
      $item->politician_uri = entity_uri('user', $politician)['path'];
      if (isset($politician->field_user_picture[LANGUAGE_NONE][0]['uri'])) {
        $item->politician_picture_uri = $politician->field_user_picture[LANGUAGE_NONE][0]['uri'];
      }
      if (isset($politician->field_user_constituency[LANGUAGE_NONE][0]['tid'])) {
        $constituency = taxonomy_term_load($politician->field_user_constituency[LANGUAGE_NONE][0]['tid']);
        $item->politician_constituency_name = $constituency->name;
        if (isset($constituency->field_constituency_area_codes[LANGUAGE_NONE][0]['tid'])) {
          $area_codes = taxonomy_term_load_multiple(array_column($constituency->field_constituency_area_codes[LANGUAGE_NONE], 'tid'));
          $item->politician_constituency_area_codes = array_values(array_map(function ($term) { return $term->name; }, $area_codes));
        }
      }
      if (isset($politician->field_user_fraction[LANGUAGE_NONE][0]['tid'])) {
        $political_faction = taxonomy_term_load($politician->field_user_fraction[LANGUAGE_NONE][0]['tid']);
        $item->politician_political_faction = $political_faction->name;
      }
    }
  }

  /**
   * Returns the user revision object associated with the given vote.
   *
   * @param object $item
   *   The vote to be indexed.
   *
   * @return object
   *   The user revision object.
   */
  protected function loadPolitician($item) {
    $poll = node_load($item->field_vote_node[LANGUAGE_NONE][0]['target_id']);
    $parliament = pw_globals_parliament($item);
    $uid = $item->field_vote_user[LANGUAGE_NONE][0]['target_id'];
    $poll_date = strtotime($poll->field_poll_date[LANGUAGE_NONE][0]['value']);

    $q = db_select('user_archive_cache', 'uac');
    $q->fields('uac', ['vid'])
      ->orderBy('uac.timestamp', 'DESC')
      ->condition('uac.uid', $uid)
      ->condition('uac.user_role', 'deputy')
      ->condition('uac.parliament_name', $parliament->name);
    $or_user_joined = db_or();
    $or_user_joined->condition('uac.user_joined', $poll_date, '<');
    $or_user_joined->condition('uac.user_joined', NULL);
    $q->condition($or_user_joined);
    $or_user_retired = db_or();
    $or_user_retired->condition('uac.user_retired', $poll_date, '>');
    $or_user_retired->condition('uac.user_retired', NULL);
    $q->condition($or_user_retired);

    return user_revision_load($uid, $q->execute()->fetchField());
  }

}
