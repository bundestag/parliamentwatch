<?php

namespace Drupal\pw_datatransfers\Modtool\DrupalEntity;

use Drupal\pw_datatransfers\Exception\DatatransfersException;
use stdClass;


/**
 * Class for managing questions in Drupal context. This class transfers the data
 * stored in ModtoolMessage class to a Drupal node of type "dialogue".
 *
 */
class DataQuestion extends DataEntityBase {

  /**
   * Load the Drupal node object of the question
   *
   * @return object|null
   */
  public function loadDrupalEntity() {
    $modtoolQuestion = $this->modtoolMessage;
    $question = NULL;

    if ($message_id = $modtoolQuestion->getMessageId()) {
      $question = load_question_by_message_id($message_id);
    }

    return $question;
  }


  /**
   * Update the node by the values sent from Modtool. The values are received
   * from the ModtoolMessage class
   *
   * @param object $node
   * Drupal node object of the question which should be updated. Can be a newly
   * created node object with no values or a node object of an existing question.
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  public function setDrupalEntityValuesFromJson($node) {
    $modtoolMessage = $this->modtoolMessage;
    $dialogue_id = $modtoolMessage->getDialogueId();

    $timezone = new \DateTimeZone('UTC');
    $date_created = new \DateTime($modtoolMessage->getInsertedDate());
    $date_created->setTimezone($timezone);
    $node->created = $date_created->format('U');

    $date_updated = new \DateTime($modtoolMessage->getUpdatedDate());
    $date_updated->setTimezone($timezone);
    $node->changed = $date_updated->format('U');

    // set the parliament
    $parliament = array_values(taxonomy_get_term_by_name($modtoolMessage->getParliament(), 'parliaments'));
    if (empty($parliament)) {
      throw new DatatransfersException('It was not possible to load a parliament for dialogue id: ' . $dialogue_id);
    }
    $node->field_parliament = [
      LANGUAGE_NONE => [
        0 => [
          'tid' => $parliament[0]->tid,
        ],
      ],
    ];

    // set the field_dialogue_before_election
    $node->field_dialogue_before_election = [
      LANGUAGE_NONE => [
        0 => [
          'value' => (int) ($date_created < pw_parliaments_election_date($parliament[0])),
        ],
      ],
    ];

    // set the politician
    $politician_uuid = $modtoolMessage->getPoliticianUUID();
    $recipient_uid = array_values(entity_get_id_by_uuid('user', [$politician_uuid]));
    if (empty($recipient_uid)) {
      throw new DatatransfersException('No user account found for recipient of the question.');
    }
    $node->field_dialogue_recipient = [
      LANGUAGE_NONE => [
        0 => [
          'target_id' => $recipient_uid[0],
        ],
      ],
    ];

    // set the question/ body text
    $node->body = [
      LANGUAGE_NONE => [
        0 => [
          'value' => htmlspecialchars(json_decode($modtoolMessage->getText())),
          'summary' => htmlspecialchars(json_decode($modtoolMessage->getSummary())),
          'format' => 'filtered_html',
        ],
      ],
    ];

    // set the dialogue id
    $node->field_dialogue_id = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $modtoolMessage->getDialogueId(),
        ],
      ],
    ];

    // set the message id
    $node->field_dialogue_message_id = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $modtoolMessage->getMessageId(),
        ],
      ],
    ];

    // set the message type
    $node->field_dialogue_message_type = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $modtoolMessage->getType(),
        ],
      ],
    ];

    // set the sender name
    $node->field_dialogue_sender_name = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $modtoolMessage->getSenderName(),
        ],
      ],
    ];

    // add documents
    // @todo - documents import implementation
    $node->field_dialogue_documents[LANGUAGE_NONE] = [];
    foreach ($modtoolMessage->getDocuments() as $document) {
      // $node->field_dialogue_documents[LANGUAGE_NONE][] = ['url' => trim($item->textContent)];
    }

    // add tags
    // @todo - tags import implementation
    $node->field_dialogue_tags[LANGUAGE_NONE] = [];
    foreach ($modtoolMessage->getTags() as $tag) {
//      $term = array_values(taxonomy_get_term_by_name(trim($tag->textContent), 'dialogue_tags'));
//      if (!empty($term)) {
//        $node->field_dialogue_tags[LANGUAGE_NONE][] = ['tid' => $term[0]->tid];
//      }
    };

    $topic = array_values(taxonomy_get_term_by_name($modtoolMessage->getTopic()));
    if (!empty($topic)) {
      $node->field_dialogue_topic = [
        LANGUAGE_NONE => [
          0 => [
            'tid' => $topic[0]->tid,
          ],
        ],
      ];
    }
    else {
      throw new DatatransfersException('The given topic was not found in Drupal.');
    }

    // add annotation
    $annotation = $modtoolMessage->getAnnotation();
    if (!empty($annotation)) {
      $node->field_dialogue_annotation = [
        LANGUAGE_NONE => [
          0 => [
            'value' => $annotation,
          ],
        ],
      ];
    }

  }


  /**
   * Create a new Drupal node object for a question
   *
   * @return object|\stdClass
   */
  public function createDrupalEntity() {
    $modtoolMessage = $this->modtoolMessage;
    $question = new stdClass();
    $question->language = LANGUAGE_NONE;
    $question->type = 'dialogue';
    $this->isNew = TRUE;
    $question->title = 'Frage von ' . $modtoolMessage->getSenderName();
    node_object_prepare($question);

    $question->uid = 0;
    return $question;
  }



  /**
   * @inheritdoc
   */
  public function getDrupalQuestionId() {
    return $this->getEntity()->nid;
  }


  /**
   * @inheritdoc
   */
  public function getDrupalAnswerId() {
    return NULL;
  }


  /**
   * @inheritdoc
   */
  public static function loadDrupalEntityById($id) {
    $node = node_load($id);

    if (!$node) {
      return FALSE;
    }

    if (!isset($node->type) || $node->type != 'dialogue') {
      return FALSE;
    }

    return $node;
  }
}