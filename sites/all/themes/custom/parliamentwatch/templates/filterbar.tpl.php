<?php

/**
 * @file
 * Default theme implementation to display a filter bar.
 *
 * Available variables:
 * - $form: The form.
 *
 * * Helper variables:
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
<div class="filterbar">
  <div class="container">
    <div class="filterbar__pre_swiper">
      <div class="form__item form__item--label">
        <i class="icon icon-investigation"></i> Filter
      </div>
      <?php
        $children = element_children($form);
        print render($form[$children[0]]);
        print render($form['submit']);
      ?>
    </div>
    <div class="filterbar__swiper">
      <div class="filterbar__swiper__inner">
        <?php
          for ($i = 1; $i < count($children); $i++) {
            if ($children[$i] != 'submit') {
              print render($form[$children[$i]]);
            }
          }
        ?>
      </div>
    </div>
  </div>
</div>