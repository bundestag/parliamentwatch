<?php


namespace Drupal\pw_administration\Controller;




use Drupal\pw_globals\Politician;

/**
 * A controller class for the zeugnisnoten admin page
 */
class Zeugnisnoten {

  protected $parliament;

  protected $DateQuestion;

  protected $DateAnswer;

  protected $bundesland;

  protected $outputChecks;

  protected $politicians = [];

  protected $questions = [];

  protected $answers = [];

  protected $questionsByPolitician = [];

  protected $answersByPoliticians = [];

  public function __construct($parliament = FALSE, $DateQuestion = FALSE, $DateAnswer = FALSE, $bundesland = FALSE, $output_checks = 0) {
    $this->parliament = $parliament;
    $this->DateAnswer = $DateAnswer;
    $this->DateQuestion = $DateQuestion;
    $this->bundesland = $bundesland;
    $this->outputChecks = $output_checks;
  }


  public function build() {
    $output = '';



    if ($this->parliament && $this->DateQuestion && $this->DateAnswer) {
      $this->loadData();
      $output .= '<b>Ergebnis: '. count($this->politicians) .' Politiker</b>';
      $output .= $this->buildTable();
    }

    return $output;
  }





  protected function buildTable() {
    if ( $this->outputChecks ) {
      $header = [
        'Name',
        'Profil',
        'Vorname',
        'Nachname',
        'Wahlkreis',
        'Partei',
        'Fragen',
        'Check',
        'Beantwortete Fragen',
        'Check',
        'Antworten insgesamt',
        'Check',
        'Standard-Antworten',
        'Check',
        'Quote',
        [
          'data' => 'Note',
          'colspan' => 2
        ]
      ];
    }
    else {
      $header = [
        'Name',
        'Wahlkreis',
        'Partei',
        'Fragen',
        'Antworten',
        'Quote',
        [
          'data' => 'Note',
          'colspan' => 2
        ]
      ];
    }


    $rows = $this->getRows();
    return theme('table', ['header' => $header, 'rows' => $rows]);
  }

  protected function getRows() {
    $rows = [];

    $data = $this->prepareData();
    $this->sortData($data);
    foreach ($data as $info) {
      $row = [];
      // name
      $cell_name['data'] = $info['fullname'];
      $row[] = $cell_name;

      if ( $this->outputChecks ) {
        $cell_profile['data'] = $info['profile'];
        $row[] = $cell_profile;

        $cell_firstname['data'] = $info['first_name'];
        $row[] = $cell_firstname;

        $cell_lastname['data'] = $info['last_name'];
        $row[] = $cell_lastname;
      }

      $cell_constituency['data'] = $info['constituency'];
      $row[] = $cell_constituency;

      $cell_party['data'] = $info['party'];
      $row[] = $cell_party;

      // fragen
      $count_questions = $info['questions'];
      // if no question was received connect the cells and just place a sentence
      if (!$count_questions) {
        $cell_question_count = [];
        $cell_question_count['data']  = 'Noch keine Fragen erhalten';
        $cell_question_count['colspan'] = $this->outputChecks ? 9 : 3;
        $row[] = $cell_question_count;

        $cell_rate = [];
        $cell_rate['data']  = 'k.W.';
        $cell_rate['colspan'] = 2;
        $row[] = $cell_rate;
      }
      else {
        $cell_question_count = [];
        $cell_question_count['data']  = $info['questions'];
        $row[] = $cell_question_count;

        if ( $this->outputChecks) {
          $cell_question_count_check['data']  = $info['questions_check'];
          $row[] = $cell_question_count_check;
        }

        $cell_answered['data']  = $info['answered_questions'];
        $row[] = $cell_answered;

        if( $this->outputChecks) {
          $cell_answered_check['data']  = $info['answered_questions_check'];
          $row[] = $cell_answered_check;

          $cell_answers_count['data']  = $info['answers'];
          $row[] = $cell_answers_count;

          $cell_answers_count_check['data']  = $info['answers_check'];
          $row[] = $cell_answers_count_check;

          $cell_answers_standard['data']  = $info['standard'];
          $row[] = $cell_answers_standard;

          $cell_answers_standard_check['data']  = $info['standard_check'];
          $row[] = $cell_answers_standard_check;
        }


        $cell_rate = [];
        $cell_rate['data']  = $info['rate'] .' %';
        $row[] = $cell_rate;

        $cell_grade['data'] = $info['grade'];
        $cell_grade['style'] = 'background-color: '. $info['grade_color'];
        $row[] = $cell_grade;

        $cell_gradename['data'] = $info['grade_name'];
        $cell_gradename['style'] = 'background-color: '.  $info['grade_color'];
        $row[] = $cell_gradename;
      }

      $rows[] = $row;
    }

    return $rows;
  }


  protected function sortData(&$data) {
    // first we separate the items with 0 questions and create groups of grades
    $no_questions = [];
    $grade_arrays = [];
    foreach ($data as $key => $data_item) {
      if ($data_item['questions'] == 0) {
        $no_questions[$key] = $data_item;
        unset($data[$key]);
      }
      else {
        $grade = $data_item['grade'];
        $grade_arrays[$grade][$key] = $data_item;
      }
    }


    // sort the grade arrays by number of answered questions
    //
    // - for all grades 1 - 4:
    //   - sorting by rate DESC
    //   - if rate is equal: sorting by answered questions DESC
    //   - if answered question is equal: sorting by last name DESC
    //
    // - for all grade 5 - 6:
    //   - sorting by rate DESC
    //   - if rate is equal: sorting by questions DESC
    //   - if questions is equal: sorting by last name DESC
    foreach ($grade_arrays as $grade => $grade_array) {
      if ($grade < 5 ) {
        uasort($grade_arrays[$grade], function ($a, $b) {
          if ( $a['rate'] == $b['rate']) {
            if ($a['answered_questions'] == $b['answered_questions']) {
              return $b['last_name'] - $a['last_name'];
            }
            return $b['answered_questions'] - $a['answered_questions'];
          }
          return $b['rate'] - $a['rate'];
        });
      }
      else {
        uasort($grade_arrays[$grade], function ($a, $b) {
          if ( $a['rate'] == $b['rate']) {
            if ($a['questions'] == $b['questions']) {
              return $b['last_name'] - $a['last_name'];
            }
            return $a['questions'] - $b['questions'];
          }
            return $b['rate'] - $a['rate'];
        });
      }

    }

    // sort the grade array by grade
    ksort($grade_arrays);

    // put all together again in $data
    $data = [];
    foreach ($grade_arrays as $grade_array) {
      foreach ($grade_array as $key => $item) {
        $data[$key] = $item;
      }
    }


    // add politicians with no questions again
    $data += $no_questions;
  }


  /**
   * This function create a table cell for each
   */
  protected function prepareData() {
    $info = [];

    foreach ($this->politicians as $uid => $politiciandata) {
      $politician = new Politician($politiciandata);
      $politician_wrapper = entity_metadata_wrapper('user', $politiciandata);
      $info[$politician->getId()] = [];
      // name
      $info[$politician->getId()]['fullname'] = $politician->getFullName();

      // profile link
      if (!$politiciandata->actual_profile) {
        $path = 'profile/' . $politiciandata->name . '/archive/' . $politiciandata->vid;
      }
      else {
        $path = 'user/' . $politiciandata->uid;
      }
      $info[$politician->getId()]['profile'] = l('Link', $path, ['attributes' => ['target' => '_blank']]);

      // first name
      $info[$politician->getId()]['first_name'] = $politician_wrapper->field_user_fname->value();
      // name
      $info[$politician->getId()]['last_name'] = $politician_wrapper->field_user_lname->value();

      // constituency
      $constituency_nr_name = 'ohne fester Wahlkreis';
      $constituency = $politician_wrapper->field_user_constituency->value();
      if ($constituency) {
        $constituency_wrapper = entity_metadata_wrapper('taxonomy_term', $constituency[0]);
        $constituency_nr_name = $constituency_wrapper->field_constituency_nr->value() .': '. $constituency_wrapper->name->value();
      }
      $info[$politician->getId()]['constituency'] = $constituency_nr_name;

      // party
      $party_name = '';
      $party = $politician_wrapper->field_user_party->value();
      if ($party && isset($party->name)) {
        $party_name = $party->name;
      }
      $info[$politician->getId()]['party'] = $party_name;


      // fragen
      $info[$politician->getId()]['questions'] = $this->getQuestionCount($politician->getId());
      // fragen check
      $info[$politician->getId()]['questions_check'] = l('Link', 'admin/abgeordnetenwatch/fragen', ['query' =>
        ['field_dialogue_before_election_value' => 0,
          'field_user_lname_value' => $politician_wrapper->field_user_lname->value(),
          'field_user_fname_value' => $politician_wrapper->field_user_fname->value(),
          'field_parliament_tid' => $this->getParliamentTid(),
          'status' => 1
        ],
        'attributes' => ['target' => '_blank']
      ]);

      // beantwortete fragen
      $info[$politician->getId()]['answered_questions']  = $this->getAnswerCount($politician->getId(), 'answered_questions');

      // beantwortete fragen check
      $info[$politician->getId()]['answered_questions_check'] = l('Link', 'admin/abgeordnetenwatch/fragen', ['query' =>
        ['field_dialogue_before_election_value' => 0,
          'field_user_lname_value' => $politician_wrapper->field_user_lname->value(),
          'field_user_fname_value' => $politician_wrapper->field_user_fname->value(),
          'field_parliament_tid' => $this->getParliamentTid(),
          'status' => 1,
          'has_comment' => 1
        ],
        'attributes' => ['target' => '_blank']
      ]);

      // antworten insgesamt
      $info[$politician->getId()]['answers'] = $this->getAnswerCount($politician->getId(), 'answers');

      // antworten insgesamt check
      $info[$politician->getId()]['answers_check'] = l('Link', 'admin/abgeordnetenwatch/fragen/antworten', ['query' =>
        [ 'field_user_lname_value' => $politician_wrapper->field_user_lname->value(),
          'field_user_fname_value' => $politician_wrapper->field_user_fname->value(),
          'field_parliament_tid' => $this->getParliamentTid(),
          'field_dialogue_before_election_value' => 0
        ],
        'attributes' => ['target' => '_blank']
      ]);

      // standard answers
      $info[$politician->getId()]['standard'] = $this->getAnswerCount($politician->getId(), 'standard');

      // standard answers check
      $info[$politician->getId()]['standard_check'] = l('Link', 'admin/abgeordnetenwatch/fragen/antworten', ['query' =>
        ['field_dialogue_is_standard_reply_value' => 1,
          'field_user_lname_value' => $politician_wrapper->field_user_lname->value(),
          'field_user_fname_value' => $politician_wrapper->field_user_fname->value(),
          'field_parliament_tid' => $this->getParliamentTid(),
          'field_dialogue_before_election_value' => 0
        ],
        'attributes' => ['target' => '_blank']
      ]);

      // quote
      $info[$politician->getId()]['rate'] = $this->calculateRate($politician->getId());

      // note
      $info[$politician->getId()]['grade'] = $this->getGrade($info[$politician->getId()]['rate']);
      $info[$politician->getId()]['grade_color'] = $this->getGradeColor($info[$politician->getId()]['grade']);

      // grade name
      $info[$politician->getId()]['grade_name'] = $this->getGradeName($info[$politician->getId()]['grade']);

    }

    return $info;
  }


  protected function getQuestionCount($user_uid) {
    if (isset($this->questionsByPolitician[$user_uid])) {
      return $this->questionsByPolitician[$user_uid];
    }
    return 0;
  }


  /**
   * Get the count of answered questions, answers or standard answers
   *
   * @param int|string $user_uid
   * The Drupal user uid of the politician
   *
   * @param string $value
   * Which value should be delivered
   *  - 'answered_questions' =  answered questions
   *  - 'answers' = answers
   *  - 'standard' = standard answers
   *
   * @return int
   */
  protected function getAnswerCount($user_uid, $value) {
    if (isset($this->answersByPoliticians[$user_uid][$value])) {
      return count($this->answersByPoliticians[$user_uid][$value]);
    }
    return 0;
  }


  protected function countQuestionsByPolitician() {
    foreach ($this->questions as $question) {
      if (isset($this->questionsByPolitician[$question->field_dialogue_recipient_target_id])) {
        $this->questionsByPolitician[$question->field_dialogue_recipient_target_id] += 1;
      }
      else {
        $this->questionsByPolitician[$question->field_dialogue_recipient_target_id] = 1;
      }
    }
  }

  /**
   *
   */
  protected function countAnswersByPolitician() {
    foreach ($this->answers as $answer) {
      if ($answer->field_dialogue_is_standard_reply_value) {
        $this->answersByPoliticians[$answer->uid]['standard'][$answer->cid] = $answer;
      }
      else {
        $this->answersByPoliticians[$answer->uid]['answers'][$answer->cid] = $answer;

        // additionally add the question to the array of answered questions
        $this->answersByPoliticians[$answer->uid]['answered_questions'][$answer->nid]= $answer;
      }
    }
  }


  protected function loadData() {
    $this->loadPoliticians();
    $this->loadQuestions();
    $this->loadAnswers();

    $this->countQuestionsByPolitician();
    $this->countAnswersByPolitician();
  }

  protected function loadAnswers() {
    $query = db_select('comment', 'c');
    $query->condition('c.nid', $this->getQuestionNids(), 'IN')
      ->fields('c', ['cid', 'uid', 'nid']);

    $query->join('field_data_field_dialogue_is_standard_reply', 'standard', 'standard.entity_id = c.cid');
    $query->condition('standard.bundle', 'comment_node_dialogue');
    $query->fields('standard', ['field_dialogue_is_standard_reply_value']);

    $result = $query->execute();
    $this->answers = $result->fetchAllAssoc('cid');
  }


  protected function loadQuestions() {
    $query = db_select('node', 'n');
    $query->condition('n.type', 'dialogue');
    $query->condition('n.status', NODE_PUBLISHED);
    $query->condition('n.created', $this->getQuestionDateTimestamp(), '<');

    // assure just questions are counted which were asked for the legislature
    $query->join('field_data_field_dialogue_before_election', 'beforeelection', 'n.nid = beforeelection.entity_id');
    $query->condition('beforeelection.bundle', 'dialogue');
    $query->condition('beforeelection.field_dialogue_before_election_value', 0);

    // just count questions asked related to the parliament
    $query->join('field_data_field_parliament', 'parliament', 'parliament.entity_id = n.nid');
    $query->condition('parliament.bundle', 'dialogue');
    $query->condition('parliament.field_parliament_tid', $this->getParliamentTid());

    // get just the questions for the politicians
    $query->join('field_data_field_dialogue_recipient', 'recipient', 'recipient.entity_id = n.nid');
    $query->condition('recipient.bundle', 'dialogue');
    $query->condition('recipient.field_dialogue_recipient_target_id', $this->getPoliticianIds(), 'IN');
    $query->fields('recipient', ['field_dialogue_recipient_target_id']);

    $query->fields('n', ['nid']);


    $result = $query->execute();
    $this->questions = $result->fetchAllAssoc('nid');
  }

  protected function loadPoliticians() {
    $query = db_select('user_archive_cache', 'uac');
    $query->fields('uac', array('uid', 'vid'));
    _pw_uac_add_conditions($query, array('parliament' => $this->getParliamentName(), 'roles' => 'deputy'));

    // add filter by bundesland
    $query->join('field_revision_field_bundesland', 'bundesland', 'uac.uid = bundesland.entity_id AND uac.vid = bundesland.revision_id');
    $query->condition('bundesland.field_bundesland_value', $this->getBundeslandKey());

    $query->addExpression('MAX(vid)', 'max_vid');
    $query->groupBy('uac.uid');
    $result = $query->execute()->fetchCol(2);
    $this->politicians = pw_userarchives_politician_load_multiple($result);
  }

  protected function getParliamentTid() {
    return $this->parliament;
  }

  protected function getParliamentName() {
    $term = taxonomy_term_load($this->getParliamentTid());
    if ($term && isset($term->name)) {
      return $term->name;
    }

    return '';
  }

  protected function getBundeslandKey() {
    return $this->bundesland;
  }


  protected function getAnswerDateTimestamp() {
    if ($this->DateAnswer) {
      $dateTime = new \DateTime($this->DateAnswer, new \DateTimeZone('UTC'));
      $dateTime->setTime(0,0,1);
      return $dateTime->getTimestamp();
    }
    else {
      return time();
    }
  }


  protected function getQuestionDateTimestamp() {
    if ($this->DateQuestion) {
      $dateTime = new \DateTime($this->DateQuestion, new \DateTimeZone('UTC'));
      $dateTime->setTime(0,0,1);
      return $dateTime->getTimestamp();
    }
    else {
      return time();
    }
  }

  protected function getPoliticianIds() {
    $user_uids = [];
    foreach ($this->politicians as $politician) {
      $user_uids[] = $politician->uid;
    }
    return $user_uids;
  }

  protected function getQuestionNids() {
    return array_keys($this->questions);
  }


  protected function calculateRate($user_id) {
    $rate = 0;
    $questions = $this->getQuestionCount($user_id);
    $answers = $this->getAnswerCount($user_id, 'answered_questions');
    if ($questions > 0 && $answers > 0) {
      $rate = round($answers / $questions * 100, 0);
    }
    return $rate;
  }

  protected function getGrade($rate) {
    if ($rate >= 96) {
      return 1;
    }
    if ($rate >= 80) {
      return 2;
    }
    if ($rate >= 60) {
      return 3;
    }
    if ($rate >= 45) {
      return 4;
    }
    if ($rate >= 16) {
      return 5;
    }

    return 6;
  }

  protected function getGradeName($grade) {
    $grade_names = [
      '1' => 'sehr gut',
      '2'=> 'gut',
      '3' => 'befriedigend',
      '4' => 'ausreichend',
      '5' => 'mangelhaft',
      '6' => 'ungenügend'
    ];

    if (isset($grade_names[$grade])) {
      return $grade_names[$grade];
    }

    return '';
  }

  protected function getGradeColor($grade) {
    $grade_names = [
      '1' => '#5cc565',
      '2'=> '#71ef7b',
      '3' => '#f9d978',
      '4' => '#ecb476',
      '5' => '#db773d',
      '6' => '#c92a1d'
    ];

    if (isset($grade_names[$grade])) {
      return $grade_names[$grade];
    }

    return 'white';
  }
}
