<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['field_user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - $user_url: The URL to the detail page of the profile.
 *   - $display_name: The display name.
 *   - $field_user_picture: The profile picture.
 *   - $field_user_picture_copyright: The profile picture's copyright.
 *   - $field_user_constituency: The constituency.
 *   - $field_user_party: The party.
 *   - $questions: The number of questions the user has received.
 *   - $answers: The number of questions the user has answered.
 *   - $answer_ratio: The percentage of answered questions.
 *   - $questions_and_answers: The questions and answers section.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
$is_eu_2019 = FALSE;
if (isset($user_profile["field_user_parliament"]["#items"][0]["tid"])) {
  $is_eu_2019 = ($user_profile["field_user_parliament"]["#items"][0]["tid"]== 30438);
}

?>
<script type="application/ld+json">
    {
        "@context": "http://schema.org",
        "@type": "Person",
        "name": "<?php print $field_user_fname[0]['value']; ?> <?php print $field_user_lname[0]['value']; ?>",
        "image": "<?php print file_create_url($field_user_picture[0]['uri']); ?>",
        "url": "<?php print url($user_url, ['absolute' => TRUE]); ?>",
        "affiliation": {
          "@type": "Organization",
          "name": "<?php print $field_user_party[0]['taxonomy_term']->name ?>"
        },
        <?php if (isset($field_user_birthday[0]['iso_8601'])) { print '"birthDate": "' . $field_user_birthday[0]['iso_8601'] . "\",\n"; } ?>
        "gender": "<?php print $field_user_gender[0]['value']; ?>",
        "homeLocation": {
          "@type": "Place",
          "name": "<?php print $field_user_address[0]['locality']; ?>"
        }
    }
</script>
<article class="deputy detail"<?php print $attributes; ?>>
  <div class="deputy__intro">
    <div class="deputy__intro__sidebar">
      <header>
        <h1 class="deputy__title"><?php print render($display_name); ?></h1>
        <div class="deputy__subtitle">
          <?php print render($user_profile['field_user_party']); ?> | <span><?php print $role; ?> <?php print render($user_profile['field_user_parliament']); ?></span>
        </div>
        <?php if (!empty($user_profile['revisions'])) { print render($user_profile['revisions']); } ?>
      </header>
      <figure class="deputy__image">
        <div class="deputy__image__inner">
          <?php print render($user_profile['field_user_picture']); ?>
        </div>
        <?php if (!empty(trim(render($user_profile['field_user_picture_copyright'])))): ?>
        <figcaption class="figcaption-overlay" data-popover-placement="right"><span>©&nbsp;<?php print render($user_profile['field_user_picture_copyright']['#items'][0]['value']);?></span></figcaption>
        <?php endif; ?>
      </figure>
      <?php if ($is_consultable): ?>
        <a href="#question-form-anchor" class="btn btn--block" data-localScroll>Frage stellen</a>
      <?php else: ?>
        <a href="#question-form-anchor" class="btn btn--block btn--disabled" data-localScroll>Frage stellen</a>

        <?php if (isset($user_profile['field_user_question_form_closed']) || isset($user_profile['field_user_retired'])): ?>
          <div class="deputy__intro__sidebar__hint">
            <i class="icon icon-info"></i>
            <?php if (isset($field_user_died[0]['value']) && $field_user_died[0]['value'] == '1'): ?>
              <?php print t('This person died'); ?>
            <?php elseif (isset($field_user_retired)): ?>
              <?php if (isset($field_user_retired_reason) && is_string($field_user_retired_reason) && !empty($field_user_retired_reason)) : ?>
                <?php print t('Reason for withdrawal:') .' '. $field_user_retired_reason; ?>
              <?php else : ?>
                <?php print t('This person left this parliament'); ?>
              <?php endif; ?>
            <?php endif; ?>
            <?php if (isset($user_profile['field_user_question_form_closed'])): ?>
              <?php print render($user_profile['field_user_question_form_closed']); ?>
            <?php endif; ?>
          </div>
        <?php endif; ?>

      <?php endif; ?>
    </div>
    <div class="deputy__intro__content">
      <div class="hstats">
        <a href="#block-pw-dialogues-profile" class="hstats__item hstats__item--donut-digit" data-localScroll>
          <div class="hstats__item__display mh-item-nr" data-mh="hstats">
            <span class="d3 d3--gauge"
                  data-d3-gauge
                  data-percentage="<?php print $answer_ratio ?>"
                  data-track-width="10"
                  data-track-colour="ccc"
                  data-fill-colour="f26a3b"
                  data-text-colour="444"
                  data-stroke-colour="FFFFFF"
                  data-stroke-spacing="2">
              <span><?php print $answer_ratio; ?>%</span>
            </span>
          </div>
          <div class="hstats__item__label mh-item-nr" data-mh="hstats">
            <div class="hstats__item__label__value">
              <?php print $answers; ?>&thinsp;/&thinsp;<?php print $questions; ?>
            </div>
            <?php print format_plural($questions, 'Answered question', 'Answered questions') ?>&nbsp;<i class="icon icon-info" data-tooltip-placement="top" data-tooltip-content="<?php print t('tooltip-profil-answered-questions') ?>"></i>
          </div>
        </a>
        <?php if (isset($user_profile['votes_total'])): ?>
        <a href="#block-pw-vote-profile" class="hstats__item hstats__item--donut-digit" data-localScroll>
          <div class="hstats__item__display mh-item-nr" data-mh="hstats">
            <span class="d3 d3--gauge"
                  data-d3-gauge
                  data-percentage="<?php print $voting_ratio; ?>"
                  data-track-width="10"
                  data-track-colour="ccc"
                  data-fill-colour="f26a3b"
                  data-text-colour="444"
                  data-stroke-colour="FFFFFF"
                  data-stroke-spacing="2">
              <span><?php print $voting_ratio; ?>%</span>
            </span>
          </div>
          <div class="hstats__item__label mh-item-nr" data-mh="hstats">
            <div class="hstats__item__label__value">
              <?php print $user_profile['votes_attended']; ?>&thinsp;/&thinsp;<?php print $user_profile['votes_total']; ?>
            </div>
            <?php print format_plural($user_profile['votes_attended'], 'Vote by name', 'Votes by name') ?>&nbsp;<i class="icon icon-info" data-tooltip-placement="top" data-tooltip-content="<?php print t('tooltip-profil-votes-by-name') ?>"></i>
          </div>
        </a>
        <?php endif; ?>
      </div>
      <dl class="dl">
        <?php if (!empty($user_profile['field_user_birthday'])): ?>
          <dt class="dl__dt"><?php print t('Year of birth') ?></dt>
          <dd class="dl__dd"><?php print $user_profile['field_user_birthday'][0]['#markup']; ?></dd>
        <?php endif; ?>
        <?php if (isset($field_user_died[0]['value']) && $field_user_died[0]['value'] == '1' && !empty($user_profile['field_user_retired'])): ?>
          <dt class="dl__dt"><?php print $user_profile['field_user_died']['#title']; ?></dt>
          <dd class="dl__dd"><?php print $user_profile['field_user_retired'][0]['#markup']; ?>
          </dd>
        <?php endif; ?>
        <?php if (!empty($user_profile['field_user_address']['#items'][0]['locality'])): ?>
          <dt class="dl__dt"><?php print t('Wohnort') ?></dt>
          <dd class="dl__dd"><?php print $user_profile['field_user_address']['#items'][0]['locality']; ?></dd>
        <?php endif; ?>
        <?php if (!empty($user_profile['field_user_education'])): ?>
          <dt class="dl__dt"><?php print $user_profile['field_user_education']['#title']; ?></dt>
          <dd class="dl__dd"><?php print $user_profile['field_user_education'][0]['#markup']; ?></dd>
        <?php endif; ?>
        <?php if (!empty($user_profile['field_user_job_skills'])): ?>
          <dt class="dl__dt"><?php print $user_profile['field_user_job_skills']['#title']; ?></dt>
          <dd class="dl__dd"><?php print $user_profile['field_user_job_skills'][0]['#markup']; ?></dd>
        <?php endif; ?>
        <?php if (!empty($user_profile['field_user_constituency']) && !$is_eu_2019): ?>
          <dt class="dl__dt"><?php print $user_profile['field_user_constituency']['#title']; ?></dt>
          <dd class="dl__dd">
            <p>
              <?php print $user_profile['field_user_constituency'][0]['#markup']; ?>
            </p>
            <?php if (isset($field_user_election_result)): ?>
              <p>
                <small>
                  <?php print $user_profile['field_user_election_result'][0]['#title']; ?>:
                  <?php print number_format(floatval(str_replace(',', '.', $user_profile['field_user_election_result'][0]['#markup'])), 1, ',', '.'); ?>&thinsp;%
                </small>
              </p>
            <?php endif; ?>
          </dd>
        <?php endif; ?>
        <?php if (!empty($user_profile['field_user_list'])): ?>
          <dt class="dl__dt"><?php print $user_profile['field_user_list']['#title']; ?></dt>
          <dd class="dl__dd">
            <?php print $user_profile['field_user_list'][0]['#markup']; ?><?php if ($user_profile['field_user_list_position']): ?>, Platz <?php print $user_profile['field_user_list_position'][0]['#markup']; ?><?php endif; ?>
              <?php if ($user_profile['field_user_list_won']['#items'][0]['value'] == 1): ?>
                <p>
                  <small>
                    <?php print t('drafted via list'); ?>
                  </small>
                </p>
              <?php endif; ?>
          </dd>
        <?php endif; ?>
        <?php if (!empty($user_profile['field_user_parliament'])): ?>
          <dt class="dl__dt"><?php print $user_profile['field_user_parliament']['#title']; ?></dt>
          <dd class="dl__dd">
            <?php print $user_profile['field_user_parliament'][0]['#markup']; ?>
            <?php if (!empty($user_profile['field_user_retired']) && (!isset($field_user_died[0]['value']) || $field_user_died[0]['value'] == '0')): ?>
              <p><small><?php print t('Retired on %date', array('%date' => drupal_html_to_text($user_profile['field_user_retired'][0]['#markup']))); ?></small>
                <?php if (isset($field_user_retired_reason) && is_string($field_user_retired_reason) && !empty($field_user_retired_reason)) : ?>
                    <small>. Grund: <?php print $field_user_retired_reason; ?></small>
                <?php endif; ?></p>
            <?php endif; ?>
          </dd>
        <?php endif; ?>
        <?php if (!empty($user_profile['field_user_joined'])): ?>
          <dt class="dl__dt"><?php print $user_profile['field_user_joined']['#title']; ?></dt>
          <dd class="dl__dd"><?php print $user_profile['field_user_joined'][0]['#markup']; ?></dd>
        <?php endif; ?>
      </dl>
    </div>

    <div class="deputy__intro__blocks">
      <?php if (!empty($user_profile['candidate_match'])): ?>
        <div class="deputy__candidate_check">
          <div class="deputy__candidate_check__header">
            <div class="deputy__candidate_check__header__logo">
              <div class="svg-container">
                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 181.6 52.8"><path d="M.8 3c0-.2.1-.4.2-.5s.3-.2.5-.2.4 0 .5.2.2.3.2.5v6l7.1-6.5c.1-.1.3-.2.5-.2s.4.1.5.2.2.3.2.5-.1.4-.2.5L5.5 8l4.9 7.8c.1.1.1.2.1.4s-.1.3-.2.5-.3.2-.5.2c-.3 0-.5-.1-.6-.3L4.4 8.9l-2.2 2v5.2c0 .2-.1.4-.2.5s-.3.2-.5.2-.3 0-.5-.2-.2-.3-.2-.5V3zm18.4-.2c0-.1.1-.2.3-.4.1-.1.3-.2.4-.2s.3.1.4.2c.1.1.2.2.3.4l5.6 13.1v.3c0 .2-.1.3-.2.5s-.3.2-.5.2c-.3 0-.5-.1-.7-.4L23 12.2h-6.4l-1.8 4.2-.3.3c-.1.1-.3.1-.4.1-.2 0-.4-.1-.5-.2-.1-.1-.2-.3-.2-.5 0-.1 0-.2.1-.3l5.7-13zm.6 2.1l-2.6 5.9h5.2l-2.6-5.9zM29.1 3c0-.2.1-.4.2-.5s.3-.2.5-.2.3 0 .4.1l.3.3 7.8 11.1V3c0-.2.1-.4.2-.5s.3-.2.5-.2.4.1.5.2.2.3.2.5v13.2c0 .2-.1.4-.2.5s-.3.2-.5.2-.3 0-.4-.1l-.3-.3-7.8-11v10.8c0 .2-.1.4-.2.5s-.3.2-.5.2-.4-.1-.5-.2-.2-.3-.2-.5V3zm13.6 0c0-.2.1-.4.2-.5s.3-.2.5-.2h3.9c1 0 1.9.2 2.8.6.9.4 1.7.9 2.3 1.6s1.2 1.4 1.6 2.3c.4.9.6 1.8.6 2.8 0 1-.2 1.9-.6 2.8-.4.9-.9 1.7-1.6 2.3-.7.7-1.4 1.2-2.3 1.6-.9.4-1.8.6-2.8.6h-3.9c-.2 0-.4-.1-.5-.2s-.2-.3-.2-.5V3zm1.5.7v11.7h3.2c.8 0 1.6-.2 2.3-.5.7-.3 1.3-.7 1.9-1.3.5-.5.9-1.2 1.3-1.9.3-.7.5-1.5.5-2.3 0-.8-.2-1.6-.5-2.3-.3-.7-.7-1.3-1.3-1.9s-1.2-.9-1.9-1.3c-.7-.3-1.5-.5-2.3-.5h-3.2zM57 3c0-.2.1-.4.2-.5.1-.1.3-.2.5-.2s.4.1.5.2.2.3.2.5v13.2c0 .2-.1.4-.2.5s-.3.2-.5.2-.4-.1-.5-.2c-.1-.1-.2-.3-.2-.5V3zm4.5 0c0-.2.1-.4.2-.5s.3-.2.5-.2h3.9c1 0 1.9.2 2.8.6.9.4 1.7.9 2.3 1.6s1.2 1.4 1.6 2.3c.4.9.6 1.8.6 2.8 0 1-.2 1.9-.6 2.8-.4.9-.9 1.7-1.6 2.3-.7.7-1.4 1.2-2.3 1.6-.9.4-1.8.6-2.8.6h-3.9c-.2 0-.4-.1-.5-.2s-.2-.3-.2-.5V3zm1.4.7v11.7h3.2c.8 0 1.6-.2 2.3-.5.7-.3 1.3-.7 1.9-1.3.5-.5.9-1.2 1.3-1.9.3-.7.5-1.5.5-2.3 0-.8-.2-1.6-.5-2.3-.3-.7-.7-1.3-1.3-1.9s-1.2-.9-1.9-1.3c-.7-.3-1.5-.5-2.3-.5h-3.2zM80 2.8c0-.1.1-.2.3-.4.1-.1.3-.2.4-.2s.3.1.4.2c.1.1.2.2.3.4L87 15.9v.3c0 .2-.1.3-.2.5s-.3.2-.5.2c-.3 0-.5-.1-.7-.4l-1.8-4.2h-6.4l-1.8 4.2-.3.3c-.1.1-.3.1-.4.1-.2 0-.4-.1-.5-.2-.1-.1-.2-.3-.2-.5 0-.1 0-.2.1-.3L80 2.8zm.6 2.1L78 10.8h5.2l-2.6-5.9zm6.1-1.2c-.2 0-.4-.1-.5-.2S86 3.2 86 3s.1-.4.2-.5.3-.2.5-.2h7.9c.2 0 .4.1.5.2s.2.3.2.5-.1.4-.2.5-.3.2-.5.2h-3.2v12.4c0 .2-.1.4-.2.5s-.3.2-.5.2-.4-.1-.5-.2c-.2-.1-.2-.3-.2-.5V3.7h-3.3zm11-.7c0-.2.1-.4.2-.5s.3-.2.5-.2h6.9c.2 0 .4.1.5.2s.2.3.2.5-.1.4-.2.5-.3.2-.5.2h-6.2v5.1h4.1c.2 0 .4.1.5.2.1.1.2.3.2.5s-.1.4-.2.5-.3.2-.5.2h-4.1v5.2h6.2c.2 0 .4.1.5.2s.2.3.2.5-.1.4-.2.5-.3.2-.5.2h-6.9c-.2 0-.4-.1-.5-.2s-.2-.3-.2-.5V3zm11.4 0c0-.2.1-.4.2-.5s.3-.2.5-.2.3 0 .4.1l.3.3 7.8 11.1V3c0-.2.1-.4.2-.5s.3-.2.5-.2.4.1.5.2.2.3.2.5v13.2c0 .2-.1.4-.2.5s-.3.2-.5.2-.3 0-.4-.1l-.3-.3-7.8-11v10.8c0 .2-.1.4-.2.5s-.3.2-.5.2-.4-.1-.5-.2-.2-.3-.2-.5V3z"></path><path fill="#999999" d="M22.2 29.1c-1.1-.9-2.3-1.7-3.7-2.5-1.4-.7-2.9-1.1-4.5-1.1s-3 .3-4.4.9C8.2 27 7 27.8 6 28.8S4.2 31 3.6 32.4c-.6 1.4-.9 2.8-.9 4.4 0 1.6.3 3 .9 4.4.6 1.4 1.4 2.6 2.4 3.6s2.2 1.8 3.6 2.4c1.4.6 2.8.9 4.4.9 1.6 0 3.2-.3 4.6-.9 1.4-.6 2.6-1.5 3.7-2.6.1-.2.3-.3.5-.4.2-.2.5-.2.7-.2.4 0 .7.1.9.4.2.3.3.6.3.9 0 .5-.1.8-.4 1.1-1.3 1.4-2.8 2.5-4.6 3.3-1.8.8-3.7 1.2-5.7 1.2-1.9 0-3.8-.4-5.5-1.1-1.7-.7-3.2-1.7-4.4-3-1.3-1.3-2.3-2.7-3-4.4C.4 40.6 0 38.8 0 36.8c0-1.9.4-3.8 1.1-5.5.7-1.7 1.7-3.2 3-4.5 1.3-1.3 2.7-2.3 4.4-3 1.7-.7 3.5-1.1 5.5-1.1s3.8.4 5.5 1.1 3.2 1.8 4.5 3.1c.1.1.3.3.4.6.1.2.2.5.2.7 0 .4-.1.7-.4.9s-.6.3-.9.3c-.5.1-.8 0-1.1-.3zm7.7-5c0-.4.1-.7.4-1 .3-.3.6-.4 1-.4s.7.1 1 .4c.3.3.4.6.4 1v12.4h14V24.1c0-.4.1-.7.4-1 .3-.3.6-.4 1-.4s.7.1 1 .4c.3.3.4.6.4 1v25.4c0 .4-.1.7-.4 1-.3.3-.6.4-1 .4s-.7-.1-1-.4c-.3-.3-.4-.6-.4-1V39.2h-14v10.3c0 .4-.1.7-.4 1-.3.3-.6.4-1 .4s-.7-.1-1-.4c-.3-.3-.4-.6-.4-1V24.1zm24.6 0c0-.4.1-.7.4-1 .3-.3.6-.4 1-.4h13.4c.4 0 .7.1 1 .4.3.3.4.6.4 1s-.1.7-.4 1c-.3.3-.6.4-1 .4h-12v9.8h8c.4 0 .7.1 1 .4.3.3.4.6.4 1s-.1.7-.4 1-.6.4-1 .4h-8v10.1h12c.4 0 .7.1 1 .4s.4.6.4 1-.1.7-.4 1c-.3.3-.6.4-1 .4H55.9c-.4 0-.7-.1-1-.4-.3-.3-.4-.6-.4-1V24.1zm39 5c-1.1-.9-2.3-1.7-3.7-2.5-1.4-.7-2.9-1.1-4.5-1.1s-3 .3-4.4.9c-1.4.6-2.6 1.4-3.6 2.4s-1.8 2.2-2.4 3.6c-.6 1.4-.9 2.8-.9 4.4 0 1.6.3 3 .9 4.4.6 1.4 1.4 2.6 2.4 3.6s2.2 1.8 3.6 2.4c1.4.6 2.8.9 4.4.9 1.6 0 3.2-.3 4.6-.9 1.4-.6 2.6-1.5 3.7-2.6.1-.2.3-.3.5-.4.2-.1.4-.1.7-.1.4 0 .7.1.9.4.2.3.3.6.3.9 0 .5-.1.8-.4 1.1-1.3 1.4-2.8 2.5-4.6 3.3-1.8.8-3.7 1.2-5.7 1.2-1.9 0-3.8-.4-5.5-1.1-1.7-.7-3.2-1.7-4.4-3-1.3-1.3-2.3-2.7-3-4.4-.7-1.7-1.1-3.5-1.1-5.5 0-1.9.4-3.8 1.1-5.5.7-1.7 1.7-3.2 3-4.5 1.3-1.3 2.7-2.3 4.4-3 1.7-.7 3.5-1.1 5.5-1.1s3.8.4 5.5 1.1c1.7.8 3.2 1.8 4.5 3.1.1.1.3.3.4.6.1.2.2.5.2.7 0 .4-.1.7-.4.9s-.6.3-.9.3c-.5-.1-.9-.2-1.1-.5zm7.6-5c0-.4.1-.7.4-1 .3-.3.6-.4 1-.4s.7.1 1 .4c.3.3.4.6.4 1v11.7l13.8-12.6c.3-.3.6-.4 1-.4s.7.1 1 .4c.3.3.4.6.4 1s-.1.7-.4 1l-9.5 8.7 9.5 15c.1.2.2.5.2.7 0 .3-.1.6-.4.9-.2.3-.6.4-1 .4-.5 0-.9-.2-1.1-.7L108 35.6l-4.2 3.9v10c0 .4-.1.7-.4 1-.3.3-.6.4-1 .4s-.7-.1-1-.4c-.3-.3-.4-.6-.4-1V24.1z"></path><path fill="#EC663B" d="M173.8 52.8h-37.3c-4.3 0-7.8-3.5-7.8-7.8V7.8c0-4.3 3.5-7.8 7.8-7.8h37.3c4.3 0 7.8 3.5 7.8 7.8v37.3c0 4.3-3.5 7.7-7.8 7.7zM136.5 2.7c-2.8 0-5 2.2-5 5V45c0 2.8 2.2 5 5 5h37.3c2.8 0 5-2.2 5-5V7.8c0-2.8-2.2-5-5-5h-37.3zm29.8 13.1c2.6 2.7 4.1 6.2 4.4 9.8h5c-.3-5-2.3-9.6-5.7-13.2-3.4-3.6-7.9-5.8-12.8-6.3l-.3 4.9c3.5.4 6.9 2.1 9.4 4.8zm-11.5-9.9c-5.4 0-10.5 2-14.4 5.8l3.4 3.6c2.9-2.8 6.7-4.4 10.8-4.4l.2-5c.1 0 .1 0 0 0zm11 32.3l3.4 3.6c1.8-1.7 3.3-3.8 4.4-6l-4.8-1.5c-.7 1.4-1.7 2.8-3 3.9zm9.9-10.5h-5c-.1 1.6-.4 3.1-1 4.5l4.7 1.5c.8-1.8 1.2-3.9 1.3-6zm-13.6-5.3c.6 1 1 2.1 1.2 3.3h5c-.2-2.5-1.1-4.8-2.6-6.8l-3.6 3.5zM160.7 33l3.4 3.6c2.4-2.3 3.9-5.4 4.1-8.7h-5c-.2 1.9-1.1 3.7-2.5 5.1zm-15.2-15.9l3.4 3.6c1.5-1.4 3.3-2.2 5.4-2.3l.3-5c-3.5 0-6.7 1.3-9.1 3.7zm18.7.1c-2.1-2-4.7-3.3-7.5-3.7l-.3 5c1.6.3 3.1 1.1 4.3 2.2l3.5-3.5zm-9.4 9.4l-.1.1h.1v-.1z"></path></svg>
              </div>
            </div>
            <h3 class="deputy__candidate_check__header__parliament"><?php print $user_profile['field_user_parliament'][0]['#markup']; ?></h3>
            <span class="deputy__candidate_check__header__info" data-tooltip-placement="right" data-tooltip-content="<?php print t('At the Kandidaten-Check all candidates can take position on relevant topics and justify them. Make the candidate check and check which of your direct candidates are closest to you!'); ?>">
              <i class="icon icon-info"></i>
            </span>
          </div>
          <div class="swiper-container">
            <div class="deputy__candidate_check__inner swiper-wrapper">
              <?php print render($user_profile['candidate_match']); ?>
            </div>
          </div>
          <div class="swiper-pagination"></div>
          <div class="swiper-button-prev"></div>
          <div class="swiper-button-next"></div>
          <?php if ($user_profile['field_user_parliament']['#items'][0]['tid'] != '30438'): ?>
            <div class="deputy__candidate_check__footer">
              <a href="https://kandidatencheck.abgeordnetenwatch.de/<?php print drupal_html_class(transliteration_get($user_profile['field_user_parliament'][0]['#markup'])); ?>" class="btn btn--mobile-block" target="_blank"><?php print t('Go to candidate check'); ?></a>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($user_profile['field_user_political_goals'])): ?>
        <div class="deputy__goal readmore">
          <h3>
            <?php print t('Political goals of @full_name', ['@full_name' => render($display_name)]); ?>
          </h3>
          <?php if ($user_profile['field_user_political_goals']): ?>
            <?php print render($user_profile['field_user_political_goals']); ?>
            <div class="deputy__goal__read_more readmore__trigger">
              <a href="#" class="btn btn--small readmore__trigger__more"><?php print t('Read more'); ?></a>
              <a href="#" class="btn btn--small readmore__trigger__less"><?php print t('Show less'); ?></a>
            </div>
          <?php else: ?>
            <div class="deputy__goal__empty">
              <p><?php print render($user_profile['field_user_fname']); ?> <?php print render($user_profile['field_user_lname']); ?> <?php print t('did not saved a political goal yet.'); ?></p>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($user_profile['field_user_about'])): ?>
        <div class="deputy__about readmore">
          <h3>
            <?php print t('About @full_name', ['@full_name' => render($display_name)]); ?>
          </h3>
          <?php print render($user_profile['field_user_about']); ?>
          <div class="deputy__aboput__read_more readmore__trigger">
            <a href="#" class="btn btn--small readmore__trigger__more"><?php print t('Read more'); ?></a>
            <a href="#" class="btn btn--small readmore__trigger__less"><?php print t('Show less'); ?></a>
          </div>
        </div>
      <?php endif; ?>

      <?php if (!empty($user_profile['field_user_links_more'])): ?>
        <div class="deputy__custom-links">
          <h2><?php print t('Links of @full_name', ['@full_name' => render($user_profile['field_user_fname']) . ' ' . render($user_profile['field_user_lname'])]); ?></h2>
          <?php print render($user_profile['field_user_links_more']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($user_profile['field_user_image_gallery'])): ?>
        <div class="deputy__gallery readmore readmore--mobile">
          <h2><?php print t('Image gallery of @full_name', ['@full_name' => render($user_profile['field_user_fname']) . ' ' . render($user_profile['field_user_lname'])]); ?></h2>
          <div class="deputy__gallery__inner">
            <?php print render($user_profile['field_user_image_gallery']); ?>
          </div>
          <div class="deputy__aboput__read_more readmore__trigger">
            <a href="#" class="btn btn--small readmore__trigger__more"><?php print t('Show all'); ?></a>
            <a href="#" class="btn btn--small readmore__trigger__less"><?php print t('Show less'); ?></a>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </div>
  <div class="share">
    <h3><?php print t('Share this deputy') ?></h3>
    <ul class="share__links">
      <li class="share__links__item share__links__item--facebook">
        <a class="share__links__item__link" href="https://www.facebook.com/sharer/sharer.php?u=<?php print drupal_encode_path(url($user_url,array('absolute'=>TRUE))); ?>" target="_blank">
          <i class="icon icon-facebook"></i> <span>teilen</span>
        </a>
      </li>
      <li class="share__links__item share__links__item--twitter">
        <a class="share__links__item__link" href="https://twitter.com/home?status=<?php print drupal_encode_path(url($user_url,array('absolute'=>TRUE))); ?>" target="_blank">
          <i class="icon icon-twitter"></i> <span>tweet</span>
        </a>
      </li>
      <li class="share__links__item share__links__item--whatsapp">
        <a class="share__links__item__link" href="whatsapp://send" target="_blank" data-text="<?php print t('Take a look at this deputy:');?>" data-href="<?php print drupal_encode_path(url($user_url,array('absolute'=>TRUE))); ?>">
          <i class="icon icon-whatsapp"></i> <span>WhatsApp</span>
        </a>
      </li>
      <li class="share__links__item share__links__item--mail">
        <a class="share__links__item__link" href="mailto:?&subject=abgeordnetenwatch.de&body=<?php print drupal_encode_path(url($user_url,array('absolute'=>TRUE))); ?>" target="_blank">
          <i class="icon icon-mail"></i> <span>e-mail</span>
        </a>
      </li>
    </ul>
  </div>
</article>
