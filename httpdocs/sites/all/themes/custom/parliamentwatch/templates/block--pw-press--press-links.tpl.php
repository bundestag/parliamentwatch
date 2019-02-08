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

<div class="press-links">
  <div class="container-regular">
    <?php print render($title_suffix) ?>
    <ul class="press-links__list">
      <li class="press-links__list__item">
        <?php print l('<i class="icon icon-news"></i>' . t('Press Review'),'ueber-uns/presse/pressespiegel', array('html' => TRUE)) ?>
      </li>
      <li class="press-links__list__item">
        <?php print l('<i class="icon icon-folders"></i>' . t('Press releases'),'ueber-uns/presse/pressemitteilungen', array('html' => TRUE)) ?>
      </li>
      <li class="press-links__list__item">
        <?php print l('<i class="icon icon-thesis"></i>' . t('Press newsletter'),'node/972122', array('html' => TRUE)) ?>
      </li>
      <li class="press-links__list__item">
        <?php print l('<i class="icon icon-download"></i>' . t('Press package'),'node/39911', array('html' => TRUE)) ?>
      </li>
      <li class="press-links__list__item">
        <?php print l('<i class="icon icon-group"></i>' . t('Contributors'),'node/7751', array('html' => TRUE)) ?>
      </li>
      <li class="press-links__list__item">
        <?php print l('<i class="icon icon-mail"></i>' . t('Contact'),'node/6578', array('html' => TRUE)) ?>
      </li>
    </ul>
  </div>
</div>

<div class="press-contact">
  <div class="container-regular">
    <h2><?php print t('You have a question about Parliamentwatch e.V.?'); ?></h2>
    <p><?php print t('We are happy to answer for you - just contact us.'); ?></p>
    <?php print l(
      t('contact now'),
      'node/6578',
      array(
        'attributes' => array(
          'class' => 'btn btn--mobile-block'
        ),
        'html' => TRUE
      )); ?>
  </div>
</div>
