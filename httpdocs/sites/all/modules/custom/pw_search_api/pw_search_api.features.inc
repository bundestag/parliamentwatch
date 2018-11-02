<?php
/**
 * @file
 * pw_search_api.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function pw_search_api_default_search_api_index() {
  $items = array();
  $items['dialogue_index'] = entity_import('search_api_index', '{
    "name" : "Dialogue index",
    "machine_name" : "dialogue_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "dialogue" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "comments" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "comment" },
        "comments:field_dialogue_comment_body:summary" : { "type" : "list\\u003Ctext\\u003E" },
        "comments:field_dialogue_comment_body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "comments:field_dialogue_is_standard_reply" : { "type" : "list\\u003Cboolean\\u003E" },
        "created" : { "type" : "date" },
        "field_dialogue_before_election" : { "type" : "boolean" },
        "field_dialogue_id" : { "type" : "integer" },
        "field_dialogue_message_id" : { "type" : "integer" },
        "field_dialogue_message_type" : { "type" : "string" },
        "field_dialogue_recipient:field_user_fname" : { "type" : "text" },
        "field_dialogue_recipient:field_user_lname" : { "type" : "text" },
        "field_dialogue_recipient:field_user_prefix" : { "type" : "string" },
        "field_dialogue_recipient:uid" : { "type" : "integer" },
        "field_dialogue_recipient:url" : { "type" : "uri" },
        "field_dialogue_sender_name" : { "type" : "text" },
        "field_dialogue_topic" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_dialogue_topic:name" : { "type" : "string" },
        "field_dialogue_topic:url" : { "type" : "uri" },
        "field_parliament" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "url" : { "type" : "uri" },
        "uuid" : { "type" : "string" },
        "vid" : { "type" : "integer" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['node_index'] = entity_import('search_api_index', '{
    "name" : "Node Index",
    "machine_name" : "node_index",
    "description" : "Index for nodes",
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [
          "announcement",
          "article",
          "blogpost",
          "dialogue",
          "page",
          "pw_petition",
          "press_release",
          "press_article",
          "speech",
          "vote"
        ]
      },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "author:field_user_party" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "author:name" : { "type" : "text" },
        "body:format" : { "type" : "string" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comment" : { "type" : "integer" },
        "comment_count" : { "type" : "integer" },
        "comment_count_new" : { "type" : "integer" },
        "comments" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "comment" },
        "comments:field_dialogue_comment_body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "created" : { "type" : "date" },
        "edit_url" : { "type" : "uri" },
        "feed_nid" : { "type" : "integer" },
        "field_blogpost_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dialogue_before_election" : { "type" : "boolean" },
        "field_dialogue_id" : { "type" : "integer" },
        "field_dialogue_message_id" : { "type" : "integer" },
        "field_dialogue_message_type" : { "type" : "string" },
        "field_dialogue_recipient" : { "type" : "integer", "entity_type" : "user" },
        "field_dialogue_sender_name" : { "type" : "text" },
        "field_dialogue_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dialogue_topic" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_donation_amount" : { "type" : "integer" },
        "field_donation_progress" : { "type" : "text" },
        "field_donation_required" : { "type" : "integer" },
        "field_job" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_parliament" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_parliament:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_petition_end_date" : { "type" : "date" },
        "field_petition_partner" : { "type" : "text" },
        "field_petition_recipient" : { "type" : "text" },
        "field_petition_required" : { "type" : "integer" },
        "field_petition_signings" : { "type" : "integer" },
        "field_petition_starter" : { "type" : "text" },
        "field_petition_status" : { "type" : "string" },
        "field_politician" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_politician:created" : { "type" : "list\\u003Cdate\\u003E" },
        "field_politician:field_user_age" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_politician:field_user_birthday" : { "type" : "list\\u003Cdate\\u003E" },
        "field_politician:field_user_childs" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_politician:field_user_constituency" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:description" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_politician:field_user_constituency:feed_nid" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_ac_descriptor" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:field_constituency_area_codes:description" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:feed_nid" : { "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_ac_descriptor" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_area_codes" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_nr" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_electoral_region" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_int_list_postiion" : { "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_election" : { "type" : "list\\u003Clist\\u003Clist\\u003Cdate\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_filter_disabled" : { "type" : "list\\u003Clist\\u003Clist\\u003Clist\\u003Cstring\\u003E\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_premium_profile_price" : { "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_pw_kc_votes_classname" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:field_votes_label" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:name" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:node_count" : { "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:parent" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:field_constituency_area_codes:parents_all" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:field_constituency_area_codes:tid" : { "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:url" : { "type" : "list\\u003Clist\\u003Clist\\u003Curi\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:uuid" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_area_codes:vocabulary" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_vocabulary"
        },
        "field_politician:field_user_constituency:field_constituency_area_codes:weight" : { "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_constituency_nr" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_electoral_region" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:field_int_list_postiion" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_parliament" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:field_parliament_election" : { "type" : "list\\u003Clist\\u003Cdate\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_parliament_filter_disabled" : { "type" : "list\\u003Clist\\u003Clist\\u003Cstring\\u003E\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_premium_profile_price" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_pw_kc_votes_classname" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_politician:field_user_constituency:field_votes_label" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_politician:field_user_constituency:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_politician:field_user_constituency:node_count" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_politician:field_user_constituency:parent" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:parents_all" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_constituency:tid" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_politician:field_user_constituency:url" : { "type" : "list\\u003Clist\\u003Curi\\u003E\\u003E" },
        "field_politician:field_user_constituency:uuid" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_politician:field_user_constituency:vocabulary" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_vocabulary"
        },
        "field_politician:field_user_constituency:weight" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_politician:field_user_constituency_won" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_politician:field_user_education" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_election_result" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_fname" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_fraction" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_politician:field_user_gender" : { "type" : "list\\u003Cstring\\u003E" },
        "field_politician:field_user_job_skills" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_list" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_politician:field_user_list_position" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_politician:field_user_list_won" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_politician:field_user_lname" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_marriage_status" : { "type" : "list\\u003Cstring\\u003E" },
        "field_politician:field_user_parliament" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_politician:field_user_party" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_phone" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_picture_copyright" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_political_roles" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:field_user_pseudonym" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_public_mail" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:field_user_qanda_ratio" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_politician:field_user_roles_for_view_mode_s" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_politician:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:roles" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_politician:status" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_politician:theme" : { "type" : "list\\u003Ctext\\u003E" },
        "field_politician:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_politician:uuid" : { "type" : "list\\u003Ctext\\u003E" },
        "field_press_article_date" : { "type" : "date" },
        "field_press_article_publisher" : { "type" : "text" },
        "field_press_release_date" : { "type" : "date" },
        "field_pw_kc_thesis_reference" : { "type" : "integer", "entity_type" : "node" },
        "field_pw_kc_user_reference" : { "type" : "integer", "entity_type" : "user" },
        "field_pw_kc_vote_reference" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_sectors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_share_sum" : { "type" : "integer" },
        "field_sidejob_classification" : { "type" : "text" },
        "field_sidejob_income_interval" : { "type" : "integer" },
        "field_sidejob_organization" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_taxonomy_party" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_vote" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_vote:field_constituency_ac_descriptor" : { "type" : "list\\u003Ctext\\u003E" },
        "field_vote:field_constituency_area_codes" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_vote:field_parliament" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_vote:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_vote:parent" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_vote:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_vote:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_vote_node" : { "type" : "integer", "entity_type" : "node" },
        "field_vote_node:title" : { "type" : "text" },
        "field_vote_user" : { "type" : "integer", "entity_type" : "user" },
        "field_vote_user:created" : { "type" : "date" },
        "field_vote_user:edit_url" : { "type" : "uri" },
        "field_vote_user:feed_nid" : { "type" : "integer" },
        "field_vote_user:field_user_age" : { "type" : "integer" },
        "field_vote_user:field_user_birthday" : { "type" : "date" },
        "field_vote_user:field_user_childs" : { "type" : "integer" },
        "field_vote_user:field_user_constituency" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_vote_user:field_user_constituency:field_constituency_area_codes:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_vote_user:field_user_constituency_won" : { "type" : "boolean" },
        "field_vote_user:field_user_education" : { "type" : "text" },
        "field_vote_user:field_user_election_result" : { "type" : "text" },
        "field_vote_user:field_user_fname" : { "type" : "text" },
        "field_vote_user:field_user_fraction" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_vote_user:field_user_fraction:name" : { "type" : "text" },
        "field_vote_user:field_user_gender" : { "type" : "string" },
        "field_vote_user:field_user_job_skills" : { "type" : "text" },
        "field_vote_user:field_user_list" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_vote_user:field_user_list_position" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_vote_user:field_user_list_won" : { "type" : "boolean" },
        "field_vote_user:field_user_lname" : { "type" : "text" },
        "field_vote_user:field_user_marriage_status" : { "type" : "string" },
        "field_vote_user:field_user_parliament" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_vote_user:field_user_party" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_vote_user:field_user_party:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_vote_user:field_user_phone" : { "type" : "text" },
        "field_vote_user:field_user_picture_copyright" : { "type" : "text" },
        "field_vote_user:field_user_political_roles" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_vote_user:field_user_pseudonym" : { "type" : "text" },
        "field_vote_user:field_user_public_mail" : { "type" : "text" },
        "field_vote_user:field_user_qanda_ratio" : { "type" : "integer" },
        "field_vote_user:field_user_question_form_closed" : { "type" : "text" },
        "field_vote_user:field_user_roles_for_view_mode_s" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_vote_user:ip" : { "type" : "text" },
        "field_vote_user:language" : { "type" : "string" },
        "field_vote_user:last_access" : { "type" : "date" },
        "field_vote_user:last_login" : { "type" : "date" },
        "field_vote_user:mail" : { "type" : "text" },
        "field_vote_user:name" : { "type" : "text" },
        "field_vote_user:roles" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_vote_user:status" : { "type" : "integer" },
        "field_vote_user:theme" : { "type" : "text" },
        "field_vote_user:uid" : { "type" : "integer" },
        "field_vote_user:url" : { "type" : "uri" },
        "field_vote_user:uuid" : { "type" : "text" },
        "field_vote_user:vid" : { "type" : "integer" },
        "is_new" : { "type" : "boolean" },
        "language" : { "type" : "string" },
        "log" : { "type" : "text" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "revision" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "source" : { "type" : "integer", "entity_type" : "node" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" },
        "uuid" : { "type" : "text" },
        "vid" : { "type" : "integer" },
        "vuuid" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_pw_kc_vote_reference:parent" : "field_pw_kc_vote_reference:parent",
              "field_pw_kc_vote_reference:parents_all" : "field_pw_kc_vote_reference:parents_all",
              "field_pw_kc_vote_reference:field_parliament" : "field_pw_kc_vote_reference:field_parliament",
              "field_pw_kc_vote_reference:field_constituency_area_codes" : "field_pw_kc_vote_reference:field_constituency_area_codes",
              "field_vote:parent" : "field_vote:parent",
              "field_vote:parents_all" : "field_vote:parents_all",
              "field_vote:field_parliament" : "field_vote:field_parliament",
              "field_vote:field_constituency_area_codes" : "field_vote:field_constituency_area_codes"
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "log" : true,
              "uuid" : true,
              "vuuid" : true,
              "field_dialogue_sender_name" : true,
              "field_petition_recipient" : true,
              "field_donation_progress" : true,
              "field_petition_partner" : true,
              "field_petition_starter" : true,
              "field_sidejob_classification" : true,
              "field_press_article_publisher" : true,
              "field_announce_tab_title" : true,
              "author:name" : true,
              "field_politician:name" : true,
              "field_politician:theme" : true,
              "field_politician:uuid" : true,
              "field_politician:field_user_fname" : true,
              "field_politician:field_user_job_skills" : true,
              "field_politician:field_user_lname" : true,
              "field_politician:field_user_pseudonym" : true,
              "field_politician:field_user_education" : true,
              "field_politician:field_user_first_letter_lname" : true,
              "field_politician:field_user_election_result" : true,
              "field_politician:field_user_phone" : true,
              "field_politician:field_user_picture_copyright" : true,
              "field_politician:field_user_public_mail" : true,
              "field_politician:field_user_prefix" : true,
              "field_politician:field_user_constituency:name" : true,
              "field_politician:field_user_constituency:description" : true,
              "field_politician:field_user_constituency:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_votes_label" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:name" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:description" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_votes_label" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "log" : true,
              "uuid" : true,
              "vuuid" : true,
              "field_dialogue_sender_name" : true,
              "field_petition_recipient" : true,
              "field_donation_progress" : true,
              "field_petition_partner" : true,
              "field_petition_starter" : true,
              "field_sidejob_classification" : true,
              "field_press_article_publisher" : true,
              "field_announce_tab_title" : true,
              "author:name" : true,
              "field_politician:name" : true,
              "field_politician:theme" : true,
              "field_politician:uuid" : true,
              "field_politician:field_user_fname" : true,
              "field_politician:field_user_job_skills" : true,
              "field_politician:field_user_lname" : true,
              "field_politician:field_user_pseudonym" : true,
              "field_politician:field_user_education" : true,
              "field_politician:field_user_first_letter_lname" : true,
              "field_politician:field_user_election_result" : true,
              "field_politician:field_user_phone" : true,
              "field_politician:field_user_picture_copyright" : true,
              "field_politician:field_user_public_mail" : true,
              "field_politician:field_user_prefix" : true,
              "field_politician:field_user_constituency:name" : true,
              "field_politician:field_user_constituency:description" : true,
              "field_politician:field_user_constituency:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_votes_label" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:name" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:description" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_votes_label" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "log" : true,
              "uuid" : true,
              "vuuid" : true,
              "field_dialogue_sender_name" : true,
              "field_petition_recipient" : true,
              "field_donation_progress" : true,
              "field_petition_partner" : true,
              "field_petition_starter" : true,
              "field_sidejob_classification" : true,
              "field_press_article_publisher" : true,
              "field_announce_tab_title" : true,
              "author:name" : true,
              "field_politician:name" : true,
              "field_politician:theme" : true,
              "field_politician:uuid" : true,
              "field_politician:field_user_fname" : true,
              "field_politician:field_user_job_skills" : true,
              "field_politician:field_user_lname" : true,
              "field_politician:field_user_pseudonym" : true,
              "field_politician:field_user_education" : true,
              "field_politician:field_user_first_letter_lname" : true,
              "field_politician:field_user_election_result" : true,
              "field_politician:field_user_phone" : true,
              "field_politician:field_user_picture_copyright" : true,
              "field_politician:field_user_public_mail" : true,
              "field_politician:field_user_prefix" : true,
              "field_politician:field_user_constituency:name" : true,
              "field_politician:field_user_constituency:description" : true,
              "field_politician:field_user_constituency:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_votes_label" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:name" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:description" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_votes_label" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "log" : true,
              "uuid" : true,
              "vuuid" : true,
              "field_dialogue_sender_name" : true,
              "field_petition_recipient" : true,
              "field_donation_progress" : true,
              "field_petition_partner" : true,
              "field_petition_starter" : true,
              "field_sidejob_classification" : true,
              "field_press_article_publisher" : true,
              "field_announce_tab_title" : true,
              "author:name" : true,
              "field_politician:name" : true,
              "field_politician:theme" : true,
              "field_politician:uuid" : true,
              "field_politician:field_user_fname" : true,
              "field_politician:field_user_job_skills" : true,
              "field_politician:field_user_lname" : true,
              "field_politician:field_user_pseudonym" : true,
              "field_politician:field_user_education" : true,
              "field_politician:field_user_first_letter_lname" : true,
              "field_politician:field_user_election_result" : true,
              "field_politician:field_user_phone" : true,
              "field_politician:field_user_picture_copyright" : true,
              "field_politician:field_user_public_mail" : true,
              "field_politician:field_user_prefix" : true,
              "field_politician:field_user_constituency:name" : true,
              "field_politician:field_user_constituency:description" : true,
              "field_politician:field_user_constituency:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_votes_label" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:name" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:description" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_votes_label" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "log" : true,
              "uuid" : true,
              "vuuid" : true,
              "field_dialogue_sender_name" : true,
              "field_petition_recipient" : true,
              "field_donation_progress" : true,
              "field_petition_partner" : true,
              "field_petition_starter" : true,
              "field_sidejob_classification" : true,
              "field_press_article_publisher" : true,
              "field_announce_tab_title" : true,
              "author:name" : true,
              "field_politician:name" : true,
              "field_politician:theme" : true,
              "field_politician:uuid" : true,
              "field_politician:field_user_fname" : true,
              "field_politician:field_user_job_skills" : true,
              "field_politician:field_user_lname" : true,
              "field_politician:field_user_pseudonym" : true,
              "field_politician:field_user_education" : true,
              "field_politician:field_user_first_letter_lname" : true,
              "field_politician:field_user_election_result" : true,
              "field_politician:field_user_phone" : true,
              "field_politician:field_user_picture_copyright" : true,
              "field_politician:field_user_public_mail" : true,
              "field_politician:field_user_prefix" : true,
              "field_politician:field_user_constituency:name" : true,
              "field_politician:field_user_constituency:description" : true,
              "field_politician:field_user_constituency:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_votes_label" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:name" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:description" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:uuid" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_nr" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_ac_descriptor" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_constit_rename" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_pw_kc_votes_classname" : true,
              "field_politician:field_user_constituency:field_constituency_area_codes:field_votes_label" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "",
            "suffix" : "",
            "excerpt" : 0,
            "excerpt_length" : "256",
            "exclude_fields" : {
              "author:name" : "author:name",
              "field_announce_tab_title" : "field_announce_tab_title",
              "field_dialogue_sender_name" : "field_dialogue_sender_name",
              "field_donation_progress" : "field_donation_progress",
              "field_parliament:name" : "field_parliament:name",
              "field_petition_partner" : "field_petition_partner",
              "field_petition_recipient" : "field_petition_recipient",
              "field_petition_starter" : "field_petition_starter",
              "field_politician:field_user_constituency:description" : "field_politician:field_user_constituency:description",
              "field_politician:field_user_constituency:field_constituency_ac_descriptor" : "field_politician:field_user_constituency:field_constituency_ac_descriptor",
              "field_politician:field_user_constituency:field_constituency_area_codes:description" : "field_politician:field_user_constituency:field_constituency_area_codes:description",
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_ac_descriptor" : "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_ac_descriptor",
              "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_nr" : "field_politician:field_user_constituency:field_constituency_area_codes:field_constituency_nr",
              "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_constit_rename" : "field_politician:field_user_constituency:field_constituency_area_codes:field_parliament_constit_rename",
              "field_politician:field_user_constituency:field_constituency_area_codes:field_pw_kc_votes_classname" : "field_politician:field_user_constituency:field_constituency_area_codes:field_pw_kc_votes_classname",
              "field_politician:field_user_constituency:field_constituency_area_codes:field_votes_label" : "field_politician:field_user_constituency:field_constituency_area_codes:field_votes_label",
              "field_politician:field_user_constituency:field_constituency_area_codes:name" : "field_politician:field_user_constituency:field_constituency_area_codes:name",
              "field_politician:field_user_constituency:field_constituency_area_codes:uuid" : "field_politician:field_user_constituency:field_constituency_area_codes:uuid",
              "field_politician:field_user_constituency:field_constituency_nr" : "field_politician:field_user_constituency:field_constituency_nr",
              "field_politician:field_user_constituency:field_parliament_constit_rename" : "field_politician:field_user_constituency:field_parliament_constit_rename",
              "field_politician:field_user_constituency:field_pw_kc_votes_classname" : "field_politician:field_user_constituency:field_pw_kc_votes_classname",
              "field_politician:field_user_constituency:field_votes_label" : "field_politician:field_user_constituency:field_votes_label",
              "field_politician:field_user_constituency:name" : "field_politician:field_user_constituency:name",
              "field_politician:field_user_constituency:uuid" : "field_politician:field_user_constituency:uuid",
              "field_politician:field_user_education" : "field_politician:field_user_education",
              "field_politician:field_user_election_result" : "field_politician:field_user_election_result",
              "field_politician:field_user_first_letter_lname" : "field_politician:field_user_first_letter_lname",
              "field_politician:field_user_fname" : "field_politician:field_user_fname",
              "field_politician:field_user_job_skills" : "field_politician:field_user_job_skills",
              "field_politician:field_user_lname" : "field_politician:field_user_lname",
              "field_politician:field_user_phone" : "field_politician:field_user_phone",
              "field_politician:field_user_picture_copyright" : "field_politician:field_user_picture_copyright",
              "field_politician:field_user_pseudonym" : "field_politician:field_user_pseudonym",
              "field_politician:field_user_public_mail" : "field_politician:field_user_public_mail",
              "field_politician:field_user_prefix" : "field_politician:field_user_prefix",
              "field_politician:name" : "field_politician:name",
              "field_politician:theme" : "field_politician:theme",
              "field_politician:uuid" : "field_politician:uuid",
              "field_press_article_publisher" : "field_press_article_publisher",
              "field_sidejob_classification" : "field_sidejob_classification",
              "field_vote:field_constituency_ac_descriptor" : "field_vote:field_constituency_ac_descriptor",
              "field_vote:name" : "field_vote:name",
              "field_vote_node:title" : "field_vote_node:title",
              "field_vote_user:field_user_constituency:field_constituency_area_codes:name" : "field_vote_user:field_user_constituency:field_constituency_area_codes:name",
              "field_vote_user:field_user_education" : "field_vote_user:field_user_education",
              "field_vote_user:field_user_election_result" : "field_vote_user:field_user_election_result",
              "field_vote_user:field_user_first_letter_lname" : "field_vote_user:field_user_first_letter_lname",
              "field_vote_user:field_user_fname" : "field_vote_user:field_user_fname",
              "field_vote_user:field_user_fraction:name" : "field_vote_user:field_user_fraction:name",
              "field_vote_user:field_user_job_skills" : "field_vote_user:field_user_job_skills",
              "field_vote_user:field_user_lname" : "field_vote_user:field_user_lname",
              "field_vote_user:field_user_party:name" : "field_vote_user:field_user_party:name",
              "field_vote_user:field_user_phone" : "field_vote_user:field_user_phone",
              "field_vote_user:field_user_picture_copyright" : "field_vote_user:field_user_picture_copyright",
              "field_vote_user:field_user_pseudonym" : "field_vote_user:field_user_pseudonym",
              "field_vote_user:field_user_public_mail" : "field_vote_user:field_user_public_mail",
              "field_vote_user:field_user_question_form_closed" : "field_vote_user:field_user_question_form_closed",
              "field_vote_user:field_user_prefix" : "field_vote_user:field_user_prefix",
              "field_vote_user:ip" : "field_vote_user:ip",
              "field_vote_user:mail" : "field_vote_user:mail",
              "field_vote_user:name" : "field_vote_user:name",
              "field_vote_user:theme" : "field_vote_user:theme",
              "field_vote_user:uuid" : "field_vote_user:uuid",
              "log" : "log",
              "title" : "title",
              "uuid" : "uuid",
              "vuuid" : "vuuid"
            },
            "highlight" : "never"
          }
        }
      },
      "additional fields" : {
        "comments" : "comments",
        "comments:field_dialogue_comment_body" : "comments:field_dialogue_comment_body"
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['politician_archive_index'] = entity_import('search_api_index', '{
    "name" : "Politician archive index",
    "machine_name" : "politician_archive_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "user_revision",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_user_age" : { "type" : "integer" },
        "field_user_constituency" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_user_constituency:field_constituency_ac_descriptor" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_constituency:field_constituency_area_codes:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_user_constituency:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_fname" : { "type" : "string" },
        "field_user_fraction" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_user_gender" : { "type" : "string" },
        "field_user_list" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_user_list_position" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_user_lname" : { "type" : "string", "boost" : "2.0" },
        "field_user_parliament" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_user_party" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_user_party:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_user_retired" : { "type" : "date" },
        "field_user_roles_for_view_mode_s" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "has_picture" : { "type" : "boolean" },
        "number_of_answers" : { "type" : "integer" },
        "number_of_questions" : { "type" : "integer" },
        "picture_uri" : { "type" : "uri" },
        "search_api_aggregation_1" : { "type" : "text", "boost" : "3.0" },
        "search_api_language" : { "type" : "string" },
        "uid" : { "type" : "integer" },
        "url" : { "type" : "uri" },
        "uuid" : { "type" : "string" },
        "vid" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "user_archive_alter" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_alter_role_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "roles" : { "140336230" : "140336230", "185431326" : "185431326" }
          }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Full name",
                "type" : "fulltext",
                "separator" : "\\n\\n",
                "fields" : [ "field_user_fname", "field_user_lname" ],
                "description" : "A Fulltext aggregation of the following fields: First Name, Last name."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_user_content" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_user_status" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "add_leading_zero" : {
          "status" : 1,
          "weight" : "-1",
          "settings" : { "fields" : { "field_user_constituency:field_constituency_area_codes:name" : true } }
        },
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "uuid" : true,
              "field_user_fname" : true,
              "field_user_lname" : true,
              "field_user_constituency:field_constituency_area_codes:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "uuid" : true,
              "field_user_fname" : true,
              "field_user_lname" : true,
              "field_user_constituency:field_constituency_area_codes:name" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "field_user_fname" : true,
              "field_user_lname" : true,
              "search_api_aggregation_1" : true,
              "field_user_constituency:name" : true,
              "field_user_constituency:field_constituency_area_codes:name" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "field_user_constituency:field_constituency_area_codes:name" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "uuid" : true,
              "field_user_fname" : true,
              "field_user_lname" : true,
              "field_user_constituency:field_constituency_area_codes:name" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "search_api_aggregation_1" : true,
              "field_user_constituency:name" : true,
              "field_user_constituency:field_constituency_ac_descriptor" : true,
              "field_user_constituency:field_constituency_area_codes:name" : true
            },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['vote_index'] = entity_import('search_api_index', '{
    "name" : "Vote index",
    "machine_name" : "vote_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "vote" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_deviant_vote" : { "type" : "boolean" },
        "field_vote" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_vote_node" : { "type" : "integer", "entity_type" : "node" },
        "field_vote_user" : { "type" : "integer", "entity_type" : "user" },
        "field_voted" : { "type" : "boolean" },
        "nid" : { "type" : "integer" },
        "politician_constituency_area_codes" : { "type" : "list\\u003Ctext\\u003E" },
        "politician_constituency_name" : { "type" : "string" },
        "politician_fname" : { "type" : "string" },
        "politician_full_name" : { "type" : "text" },
        "politician_lname" : { "type" : "string" },
        "politician_picture_uri" : { "type" : "uri" },
        "politician_political_faction" : { "type" : "string" },
        "politician_uri" : { "type" : "uri" },
        "search_api_language" : { "type" : "string" },
        "uuid" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "-49", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-47", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-46", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "vote_search_alter_callback" : { "status" : 1, "weight" : "-44", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-43", "settings" : [] },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "-42", "settings" : [] }
      },
      "processors" : {
        "add_leading_zero" : {
          "status" : 1,
          "weight" : "-1",
          "settings" : { "fields" : { "politician_constituency_area_codes" : true } }
        },
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "uuid" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "uuid" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "uuid" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "uuid" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : { "fields" : { "uuid" : true }, "exceptions" : "texan=texa" }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
