<?php


namespace Drupal\pw_datatransfers\Modtool\DrupalEntity;

use Drupal\pw_datatransfers\Modtool\ModtoolMessage;


/**
 * Base class for DataEntity classes. DataEntity classes are the counterparts
 * of ModtoolMessage classes and therefore manage the node/ comment creation and
 * value updating.
 *
 */
abstract class DataEntityBase implements DataEntityInterface {

  /**
   * @var \Drupal\pw_datatransfers\Modtool\ModtoolMessage
   * The class describing the message sent from Modtool
   *
   */
  protected $modtoolMessage = NULL;

  /**
   * @var object|null
   * The Drupal node or comment for the question/ answer
   */
  protected $entity = NULL;


  /**
   * @var bool
   * True when the Drupal node/ comment was just created
   */
  public $isNew = FALSE;


  /**
   * DataEntityBase constructor.
   *
   * @param \Drupal\pw_datatransfers\Modtool\ModtoolMessage $modtool_message
   */
  public function __construct(ModtoolMessage $modtool_message) {
    $this->modtoolMessage = $modtool_message;
  }


  /**
   * Set the Drupal entity (node or comment) related to the given ModtoolMessage
   *
   * @param object $entity
   * The Drupal node/ comment
   */
  public function setEntity($entity) {
    $this->entity = $entity;
  }


  /**
   * Get the Drupal entity (node or comment) related to the given ModtoolMessage
   *
   * @return object|null
   */
  public function getEntity() {
    return $this->entity;
  }


  /**
   * Get the ModtoolMessage class
   *
   * @return \Drupal\pw_datatransfers\Modtool\ModtoolMessage
   */
  public function getModtoolMessage() {
    return $this->modtoolMessage;
  }


  /**
   * Set the documents attached to the question/ answer
   */
  public function setDocuments($entity) {
    $allowed_extensions = $this->getAllowedExtensionsForDocuments();
    $info = field_info_instance('node', 'field_dialogue_attachments', 'dialogue');

    // rest the documents field
    $entity->field_dialogue_attachments = [];

    foreach ($this->modtoolMessage->getDocuments() as $document_url) {
      $file_pathinfo = pathinfo($document_url);
      if (in_array($file_pathinfo['extension'], $allowed_extensions)) {
        $file_temp = $this->modtoolMessage->loadDocument($document_url);
        $directory = 'private://'. $info["settings"]["file_directory"];
        $directory_prepared = file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

        if ($file_temp && $directory_prepared) {

          // get a transliterated file name
          if (function_exists('transliteration_clean_filename')) {
            $filename  = transliteration_clean_filename($file_pathinfo["basename"]);
          }
          else {
            $filename = $file_pathinfo["basename"];
          }

          $drupal_file = file_save_data($file_temp, $directory .'/'. $filename,FILE_EXISTS_RENAME);
          if ($drupal_file) {
            $file = [
              'fid' => $drupal_file->fid,
              'display' => 1,
              'filename' => $drupal_file->filename,
              'filemime' => $drupal_file->filemime,
              'uri' => $drupal_file->uri,
              'status' => 1,
              'uid' => $entity->uid
            ];
            $entity->field_dialogue_attachments[LANGUAGE_NONE][] = $file;
          }
        }
      }
    }

  }


  /**
   * Get the allowed extensions for documents
   *
   * @return array
   */

  protected function getAllowedExtensionsForDocuments() {
    $info = field_info_instance('node', 'field_dialogue_attachments', 'dialogue');
    $allowed_extensions = explode(' ', $info["settings"]["file_extensions"]);

    return $allowed_extensions;
  }


}
