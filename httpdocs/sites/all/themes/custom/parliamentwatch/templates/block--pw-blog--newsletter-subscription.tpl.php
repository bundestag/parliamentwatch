<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="well__left">
  <h3><?php print t('Do not miss any information!') ?></h3>
  <p><?php print t('Exciting stories and research on additional income, party donations and lobbying - stay up to date!') ?></p>
</div>
<form id="newsletter-widget" action="" class="form">
  <div id="newsletter-widget-message" class="form__item form__item--alert"></div>
  <div class="form__item">
    <label class="form__item__label sr-only">
      <?php print t('Email address') ?>
    </label>
    <input type="text" id="newsletter-widget-mail" class="form__item__control" placeholder="<?php print t('Email address') ?>">
    <div class="form__item__loader"><i class="icon icon-spinner"></i></div>
  </div>
  <div class="form__item">
    <button type="submit" id="newsletter-widget-button" class="btn btn--mobile-block"><?php print t('Request') ?></button>
  </div>
</form>

