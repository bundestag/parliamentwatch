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
    <div class="filterbar__sorting filterbar__sorting--deputies">
      <div class="form__item form__item--horizontal">
        <label for="deputies_sorting" class="form__item__label form__item__label--static"><?php print t('Sorted by:'); ?></label>
        <select name="deputies_sorting" id="deputies_sorting" class="form__item__control form__item__control--special" data-width="100%">
          <option value="answers_asc" data-sort-value="answers" data-sort-order="asc"><?php print t('Answers'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="answers_desc" data-sort-value="answers" data-sort-order="desc" selected><?php print t('Answers'); ?> (<?php print t('descending'); ?>)</option>
          <option value="questions_asc" data-sort-value="questions" data-sort-order="asc"><?php print t('Questions'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="questions_desc" data-sort-value="questions" data-sort-order="desc"><?php print t('Questions'); ?> (<?php print t('descending'); ?>)</option>
          <option value="party_asc" data-sort-value="party" data-sort-order="asc"><?php print t('Party'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="party_desc" data-sort-value="party" data-sort-order="desc"><?php print t('Party'); ?> (<?php print t('descending'); ?>)</option>
          <option value="name_asc" data-sort-value="name" data-sort-order="asc"><?php print t('Name'); ?> (<?php print t('ascending'); ?>)</option>
          <option value="name_desc" data-sort-value="name" data-sort-order="desc"><?php print t('Name'); ?> (<?php print t('descending'); ?>)</option>
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
