<?php


namespace Drupal\pw_userarchives;

/**
 * To avoid confusion between user revision/ user archive and search api
 * tables we do a check for each single user revision vid if it is already
 * indexed and then call the appropriate search api handler.
 *
 */
class UserArchiveSearchAPI {

  /**
   * @var array
   * Array of user revision vids which should be inserted, updated or
   * deleted from search index
   */
  protected $vidsGiven;

  /**
   * @var string
   * Can be 'change' or 'delete'. Use 'change' for either updating or inserting
   * new items to the index. As the search API handler does not really check
   * appropriately if items exist
   */
  protected $action;


  /**
   * @var array
   * The class will check against $this->vidsGiven which items (user revisions)
   * are already indexed and collect their user revision vids in this array.
   */
  protected $vidsIndexed;


  /**
   * @var array
   * The class will check against $this->vidsGiven which items (user revisions)
   * are not indexed yet and collect their user revision vids in this array.
   */
  protected $vidsNotIndexed;


  /**
   * The interal id of the Search API index to use
   */
  const SEARCH_API_INDEX_ID = 160;


  /**
   * UserArchiveSearchAPI constructor.
   *
   * @param array $vids
   * The user revision vids which should be indexec, changed in index or deleted
   * from index.
   *
   * @param string $action
   * Use "change" for updating or insertig the user revisions in(to) the index or
   * "delete" when the given user revisions should be deleted from search index
   */
  public function __construct(array $vids, $action) {
    $this->vidsGiven = $vids;
    $this->action = $action;
  }


  /**
   * Call this to start the search index update. It checks if the user revisions
   * are indexed and calls the appropriate search api callbacks.
   */
  public function updateSearchIndex() {
    $transaction = db_transaction();
    try {
      $this->checkVidsIndexed();
      switch($this->action) {
        case 'change':
          if (!empty($this->vidsNotIndexed)) {
            search_api_track_item_insert('user_revision', $this->vidsNotIndexed);
          }

          if (!empty($this->vidsIndexed)) {
            search_api_track_item_change('user_revision', $this->vidsIndexed);
          }
          break;
        case 'delete':
          search_api_track_item_delete('user_revision', $this->vidsIndexed);
      }
      // depending on the action choose the search api handler
    }
    catch (\Exception $e) {
      $transaction->rollback();
      $error_message = 'An error appeared while trying to manage search index after updating user archive entry.';
      watchdog_exception('pw_userarchives', $e, $error_message .': '. $e->getMessage());
      drupal_set_message($error_message, 'warning');
    }
  }


  /**
   * Check which of the given user revision vids are indexed and which are not.
   *
   */
  protected function checkVidsIndexed() {
    $query = db_select('search_api_item', 'i')
      ->condition('index_id', self::SEARCH_API_INDEX_ID)
      ->condition('item_id', $this->vidsGiven)
      ->fields('i');
    $result = $query->execute();
    $records = $result->fetchAllAssoc('item_id');

    $this->vidsIndexed = array_keys($records);
    $this->vidsNotIndexed = array_diff($this->vidsGiven, $this->vidsIndexed);
  }
}