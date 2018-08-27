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
<div class="filterbar__primary">
  <div class="filterbar__item filterbar__item--label">
    <i class="icon icon-investigation"></i> Filter
  </div>
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
      if ($form[$children[$i]]['#dropdown']) {
        $classes = 'filterbar__item--dropdown dropdown';
      }
      elseif ($form[$children[$i]]['#type'] == 'select') {
        $classes = 'filterbar__item--select';
      }
      elseif ($form[$children[$i]]['#type'] == 'checkboxes') {
        $classes = 'filterbar__item--checkbox';
      }

      if (!empty($form[$children[$i]]['#default_value'])) {
        $classes .= ' swiper-slide-active';
      }
    ?>
    <div class="filterbar__item <?php print $classes; ?>">
      <?php if ($form[$children[$i]]['#dropdown']): ?>
      <div class="dropdown__trigger">
        <?php print $form[$children[$i]]['#title'] ?>
        <?php if (!empty($form[$children[$i]]['#default_value'])): ?>
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
