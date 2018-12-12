<?php


namespace Drupal\pw_datatransfers\Modtool;


use DateTime;
use DOMDocument;
use DOMXPath;
use Drupal\pw_datatransfers\Exception\DatatransfersException;
use stdClass;


class DialogueImport {

  /**
   * @var int|string|null
   * The dialogue id from Modtool
   */
  protected $dialogueId = NULL;

  /**
   * @var \DOMDocument|null
   * The loaded and initialised DOM document
   */
  protected $sourceDocument = NULL;


  protected $savedQuestionNode = NULL;

  /**
   * @var null|bool
   * Indicating if the question is created new
   */
  public $questionIsNew = NULL;


  public function __construct(DOMDocument $source_document) {
    $this->sourceDocument = $source_document;
    $this->dialogueId = self::getDialogueIdFromDOMDocument($this->getSourceDocument());
  }


  public static function getDialogueIdFromDOMDocument(DOMDocument $dom_document) {
    $xpath = new DOMXPath($dom_document);
    return $xpath->evaluate('string(//dialogue/@id)');
  }


  /**
   * Start the import of the question and answer
   */
  public function import() {
    $question = $this->createQuestionNode();

    $transaction = db_transaction();
    try {
      node_save($question);
      $this->savedQuestionNode = $question;
      $comments = $this->createComments($question);
      foreach ($comments as $comment) {
        comment_save($comment);
      }
      return TRUE;
    }
    catch (\Exception $e) {
      $transaction->rollback();
      throw $e;
    }
  }


  /**
   * @param object $question
   * The node object of the question
   *
   * @return array
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  protected function createComments($question) {
    $xpath = new DOMXPath($this->getSourceDocument());
    $answers = [];

    foreach ($xpath->query('//message[type="answer"]') as $answer_from_modtool) {
      $sender_uuid = $xpath->evaluate('string(sender.external_id)', $answer_from_modtool);
      $sender_uid = array_values(entity_get_id_by_uuid('user', $sender_uuid));
      if (empty($sender_uid)) {
        throw new DatatransfersException('Sender\'s user account cannot be loaded by the given uuid '. $sender_uuid .'; dialogue id: '. $this->dialogueId);
      }

      $date = new DateTime($xpath->evaluate('string(inserted_date)', $answer_from_modtool));
      $message_id = $xpath->evaluate('string(id)', $answer_from_modtool);

      $comment = $this->loadOrCreateAnswer($message_id, $question);
      $comment->created = $date->format('U');
      $comment->status = $xpath->evaluate('string(status)', $answer_from_modtool);
      $comment->subject = 'Antwort von ' . $xpath->evaluate('string(sender)', $answer_from_modtool);
      $comment->uid = $sender_uid;
      $comment->field_dialogue_comment_body = [LANGUAGE_NONE => [0 => [
        'value' => html_entity_decode($xpath->evaluate('string(text)', $answer_from_modtool)),
        'summary' => html_entity_decode($xpath->evaluate('string(keyworded_text)', $answer_from_modtool)),
        'format' => 'managed_content',
      ]]];
      $comment->field_dialogue_id = [LANGUAGE_NONE => [0 => [
        'value' => $xpath->evaluate('string(//dialogue/@id)'),
      ]]];
      $comment->field_dialogue_message_id = [LANGUAGE_NONE => [0 => [
        'value' => $message_id,
      ]]];
      $comment->field_dialogue_message_type = [LANGUAGE_NONE => [0 => [
        'value' => $xpath->evaluate('string(type)', $answer_from_modtool),
      ]]];
      $comment->field_dialogue_sender_fullname = [LANGUAGE_NONE => [0 => [
        'value' => $xpath->evaluate('string(sender)', $answer_from_modtool),
      ]]];
      $comment->field_dialogue_documents[LANGUAGE_NONE] = [];
      foreach ($xpath->query('documents/documents_item', $answer_from_modtool) as $item) {
        $comment->field_dialogue_documents[LANGUAGE_NONE][] = ['url' => trim($item->textContent)];
      }
      $comment->field_dialogue_tags[LANGUAGE_NONE] = [];
      foreach ($xpath->query('tags/tags_item', $answer_from_modtool) as $item) {
        $term = array_values(taxonomy_get_term_by_name(trim($item->textContent), 'dialogue_tags'));
        if (!empty($term)) {
          $comment->field_dialogue_tags[LANGUAGE_NONE][] = ['tid' => $term[0]->tid];
        }
      };
      $annotation = $xpath->evaluate('string(annotation.text)', $answer_from_modtool);
      if (!empty($annotation)) {
        $comment->field_dialogue_annotation = [LANGUAGE_NONE => [0 => [
          'value' => $annotation,
        ]]];
      }
      $topic = array_values(taxonomy_get_term_by_name($xpath->evaluate('string(topic)', $answer_from_modtool), 'dialogue_topics'));
      if (!empty($topic)) {
        $comment->field_dialogue_topic = [LANGUAGE_NONE => [0 => [
          'tid' => $topic[0]->tid,
        ]]];
      }
      $answers[] = $comment;
    }

    return $answers;
  }


  /**
   * Creates a dialogue (question) node object from the DOM object. When a question
   * already exists in Drupal it loads this node to update the node.
   *
   * @return object
   * The node object set with the data from the DOM object
   *
   * @throws \Drupal\pw_datatransfers\Exception\DatatransfersException
   */
  protected function createQuestionNode() {
    $xpath = new DOMXPath($this->getSourceDocument());
    $question_from_modtool = $xpath->query('//message[type="question"]')
      ->item(0);

    if (is_null($question_from_modtool)) {
      throw new DatatransfersException('No question found in the XML document, dialogue id: ' . $this->getDialogueId());
    }

    $parliament = array_values(taxonomy_get_term_by_name($xpath->evaluate('string(context)', $question_from_modtool), 'parliaments'));
    if (empty($parliament)) {
      throw new DatatransfersException('It was not possible to load parliaments for dialogue id: ' . $this->getDialogueId());
    }

    $recipient_uid = array_values(entity_get_id_by_uuid('user', [$xpath->evaluate('string(recipient.external_id)', $question_from_modtool)]));
    if (empty($recipient_uid)) {
      throw new DatatransfersException('No user account found for recipient in dialogue id: ' . $this->getDialogueId());
    }


    $date = new DateTime($xpath->evaluate('string(inserted_date)', $question_from_modtool));
    $message_id = $xpath->evaluate('string(id)', $question_from_modtool);

    $node = $this->loadOrCreateQuestion($message_id);
    $node->created = $date->format('U');
    $node->status = $xpath->evaluate('string(status)', $question_from_modtool);
    $node->title = 'Frage von ' . $xpath->evaluate('string(sender)', $question_from_modtool);
    $node->uid = 0;
    $node->body = [
      LANGUAGE_NONE => [
        0 => [
          'value' => html_entity_decode($xpath->evaluate('string(text)', $question_from_modtool)),
          'summary' => html_entity_decode($xpath->evaluate('string(keyworded_text)', $question_from_modtool)),
          'format' => 'managed_content',
        ],
      ],
    ];
    $node->field_dialogue_before_election = [
      LANGUAGE_NONE => [
        0 => [
          'value' => (int) ($date < pw_parliaments_election_date($parliament[0])),
        ],
      ],
    ];
    $node->field_dialogue_id = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $xpath->evaluate('string(//dialogue/@id)'),
        ],
      ],
    ];
    $node->field_dialogue_message_id = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $message_id,
        ],
      ],
    ];
    $node->field_dialogue_message_type = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $xpath->evaluate('string(type)', $question_from_modtool),
        ],
      ],
    ];
    $node->field_dialogue_recipient = [
      LANGUAGE_NONE => [
        0 => [
          'target_id' => $recipient_uid[0],
        ],
      ],
    ];
    $node->field_dialogue_sender_name = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $xpath->evaluate('string(sender)', $question_from_modtool),
        ],
      ],
    ];
    $node->field_parliament = [
      LANGUAGE_NONE => [
        0 => [
          'tid' => $parliament[0]->tid,
        ],
      ],
    ];
    $node->field_dialogue_documents[LANGUAGE_NONE] = [];
    foreach ($xpath->query('documents/documents_item', $question_from_modtool) as $item) {
      $node->field_dialogue_documents[LANGUAGE_NONE][] = ['url' => trim($item->textContent)];
    }
    $node->field_dialogue_tags[LANGUAGE_NONE] = [];
    foreach ($xpath->query('tags/tags_item', $question_from_modtool) as $item) {
      $term = array_values(taxonomy_get_term_by_name(trim($item->textContent), 'dialogue_tags'));
      if (!empty($term)) {
        $node->field_dialogue_tags[LANGUAGE_NONE][] = ['tid' => $term[0]->tid];
      }
    };
    $annotation = $xpath->evaluate('string(annotation.text)', $question_from_modtool);
    if (!empty($annotation)) {
      $node->field_dialogue_annotation = [
        LANGUAGE_NONE => [
          0 => [
            'value' => $annotation,
          ],
        ],
      ];
    }
    $topic = array_values(taxonomy_get_term_by_name($xpath->evaluate('string(topic)', $question_from_modtool), 'dialogue_topics'));
    if (!empty($topic)) {
      $node->field_dialogue_topic = [
        LANGUAGE_NONE => [
          0 => [
            'tid' => $topic[0]->tid,
          ],
        ],
      ];
    }

    return $node;


  }



  /**
   * @return \DOMDocument|null
   * The DOM document object
   */
  public function getSourceDocument() {
    return $this->sourceDocument;
  }


  /**
   * @return int|string|null
   * The dialogue id which is imported in the moment
   */
  public function getDialogueId() {
    return $this->dialogueId;
  }


  /**
   * @return string|null
   * The path to the XML document for the current dialogue
   */
  public function getSourcePath() {
    return $this->sourcePath;
  }


  /**
   * Create the sourcepath from the given dialogue id
   *
   * @return string
   */
  public static function createSourcePath($dialogue_id) {
    $source_path = variable_get('pw_dialogues_importer_source');
    $source_path .= $dialogue_id;
    $source_path .= '?unreleased=1';
    return $source_path;
  }

  /**
   * Load the question by it's message id set in modtool - if none found
   * create a new empty node object
   *
   * @param $message_id
   * The message id of the question in Modtool
   *
   * @return object
   * A Drupal node object representing a question/ dialogue
   */
  protected function loadOrCreateQuestion($message_id) {
    $question = load_question_by_message_id($message_id);

    if($question == NULL) {
      $question = new stdClass();
      $question->language = LANGUAGE_NONE;
      $question->type = 'dialogue';
      $this->questionIsNew = TRUE;
      node_object_prepare($question);
    }
    else {
      $this->questionIsNew = FALSE;
    }

    return $question;
  }


  /**
   * Load the answer by it's message id set in modtool - if none found
   * create a new empty node object
   *
   * @param int|string $message_id
   * The message id of the answer in Modtool
   *
   * @param object $question
   * The Drupal node object of the related question
   *
   * @return bool|\stdClass|null
   */
  protected function loadOrCreateAnswer($message_id, $question) {
    $answer = load_answer_by_message_id($message_id);

    if ($answer) {
      $answer->changed = REQUEST_TIME;
    }
    else {
      $answer = new stdClass();
      $answer->nid = $question->nid;
    }


    return $answer;
  }


  public function getMessageIdOfQuestion() {
    $xpath = new DOMXPath($this->getSourceDocument());
    $question_from_modtool = $xpath->query('//message[type="question"]')
      ->item(0);
    $message_id = $xpath->evaluate('string(id)', $question_from_modtool);

    return $message_id;
  }


  public function getMessageIdsOfAnswers() {
    $xpath = new DOMXPath($this->getSourceDocument());
    $answers_message_ids = [];

    foreach ($xpath->query('//message[type="answer"]') as $answer_from_modtool) {
      $answers_message_ids[] = $xpath->evaluate('string(id)', $answer_from_modtool);
    }

    return $answers_message_ids;
  }


  public function getSavedQuestionNode() {
    return $this->savedQuestionNode;
  }
}