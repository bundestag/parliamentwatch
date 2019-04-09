<?php

/**
 * @file
 * Default theme implementation to display a filter bar.
 *
 * Available variables:
 * - $form: The form.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_filterbar()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="filterbar__trigger">
  <button class="btn" type="button" role="button" data-filterbar-toggle>
    <i class="icon icon-investigation"></i> <?php print t('Show filters'); ?>
  </button>
</div>

<div class="filterbar__content">
  <div class="filterbar__heading">
    <div class="option-title">
      <h2><?php print t('Filter results'); ?></h2>
      <a class="btn" href="#" data-filterbar-submit><?php print t('Apply'); ?></a>
      <a class="btn btn--transparent" href="#" data-filterbar-toggle><?php print t('Close'); ?></a>
    </div>
  </div>

  <?php if ($form['#id'] === 'pw-profiles-filters-form'): ?>
    <?php
      $params = drupal_get_query_parameters();
      if (!array_key_exists('sort_by', $params)) {
        $params['sort_by'] = 'answers';
        $params['sort_order'] = 'desc';
      }
    ?>
    <div class="filterbar__sorting filterbar__sorting--deputies">
      <div class="form__item form__item--horizontal">
        <label for="deputies_sorting" class="form__item__label form__item__label--static"><?php print t('Sorted by:'); ?></label>
        <select name="deputies_sorting" id="deputies_sorting" class="form__item__control form__item__control--special" data-width="100%">
          <option value="answers_asc"<?php if ($params['sort_by'] === 'answers' && $params['sort_order'] === 'asc'): ?> selected<?php endif; ?>><?php print t('Answers'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="answers_desc"<?php if ($params['sort_by'] === 'answers' && $params['sort_order'] === 'desc'): ?> selected<?php endif; ?>><?php print t('Answers'); ?> (<?php print t('descending'); ?>)</option>
          <option value="questions_asc"<?php if ($params['sort_by'] === 'questions' && $params['sort_order'] === 'asc'): ?> selected<?php endif; ?>><?php print t('Questions'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="questions_desc"<?php if ($params['sort_by'] === 'questions' && $params['sort_order'] === 'desc'): ?> selected<?php endif; ?>><?php print t('Questions'); ?> (<?php print t('descending'); ?>)</option>
          <option value="party_asc"<?php if ($params['sort_by'] === 'party' && $params['sort_order'] === 'asc'): ?> selected<?php endif; ?>><?php print t('Party'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="party_desc"<?php if ($params['sort_by'] === 'party' && $params['sort_order'] === 'desc'): ?> selected<?php endif; ?>><?php print t('Party'); ?> (<?php print t('descending'); ?>)</option>
          <option value="name_asc"<?php if ($params['sort_by'] === 'name' && $params['sort_order'] === 'asc'): ?> selected<?php endif; ?>><?php print t('Name'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="name_desc"<?php if ($params['sort_by'] === 'name' && $params['sort_order'] === 'desc'): ?> selected<?php endif; ?>><?php print t('Name'); ?> (<?php print t('descending'); ?>)</option>
        </select>
      </div>
    </div>
  <?php elseif ($form['#id'] === 'pw-vote-poll-filters'): ?>
    <div class="filterbar__sorting filterbar__sorting--poll">
      <div class="form__item form__item--horizontal">
        <label for="poll_detail_table_sorting" class="form__item__label form__item__label--static"><?php print t('Sorted by:'); ?></label>
        <select name="poll_detail_table_sorting" id="poll_detail_table_sorting" class="form__item__control form__item__control--special" data-width="100%">
          <option value="politician_full_name_asc" data-sort-value="politician_full_name" data-sort-order="1"><?php print t('Name'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="politician_full_name_dsc" data-sort-value="politician_full_name" data-sort-order="0"><?php print t('Name'); ?> (<?php print t('descending'); ?>)</option>
          <option value="politician_political_faction_asc" data-sort-value="politician_political_faction" data-sort-order="1"><?php print t('Fraction'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="politician_political_faction_dsc" data-sort-value="politician_political_faction" data-sort-order="0"><?php print t('Fraction'); ?> (<?php print t('descending'); ?>)</option>
          <option value="politician_constituency_name_asc" data-sort-value="politician_constituency_name" data-sort-order="1"><?php print t('Wahlkreis'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="politician_constituency_name_dsc" data-sort-value="politician_constituency_name" data-sort-order="0"><?php print t('Wahlkreis'); ?> (<?php print t('descending'); ?>)</option>
          <option value="field_vote_display_asc" data-sort-value="field_vote_display" data-sort-order="1" selected><?php print t('Voting behavior'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="field_vote_display_dsc" data-sort-value="field_vote_display" data-sort-order="0"><?php print t('Voting behavior'); ?> (<?php print t('descending'); ?>)</option>
        </select>
      </div>
    </div>
  <?php endif; ?>

  <div class="filterbar__primary">
    <div class="filterbar__item filterbar__item--input">
      <?php
        $children = element_children($form);
        print render($form[$children[0]]);
        print render($form['submit']);
      ?>
    </div>
  </div>

  <div class="filterbar__secondary">
    <div class="filterbar__secondary__inner">
      <?php for ($i = 1; $i < count($children); $i++): ?>
        <?php if (!in_array($children[$i], ['submit', 'form_id', 'form_build_id', 'form_token'])): ?>
          <?php
            if (!empty($form[$children[$i]]['#dropdown'])) {
              $classes = 'filterbar__item--dropdown dropdown';
            }
            elseif ($form[$children[$i]]['#type'] == 'select') {
              $classes = 'filterbar__item--select';
            }
            elseif (strpos($form[$children[$i]]['#type'], 'checkbox') == 0) {
              $classes = 'filterbar__item--checkbox';
            }

            if (!empty($form[$children[$i]]['#default_value'])) {
              $classes .= ' swiper-slide-active';
            }
          ?>

          <div class="filterbar__item <?php print $classes; ?>">
            <?php if (!empty($form[$children[$i]]['#dropdown'])): ?>
              <div class="dropdown__trigger">
                <?php print $form[$children[$i]]['#title'] ?>

                <?php if (!empty($form[$children[$i]]['#options']) && !empty($form[$children[$i]]['#default_value'])): ?>
                  <span class="badge"><?php print count($form[$children[$i]]['#default_value']); ?></span>
                <?php endif; ?>
                <i class="icon icon-arrow-down"></i>
              </div>

              <div class="dropdown__list">
                <?php print render($form[$children[$i]]); ?>
              </div>
            <?php else: ?>
              <?php print render($form[$children[$i]]); ?>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      <?php endfor; ?>
    </div>

    <div class="swiper-button-next"></div>
    <div class="swiper-button-prev"></div>
  </div>
</div>
