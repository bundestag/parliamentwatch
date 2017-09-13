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
<div class="container">
  <?php print $content ?>
</div>
<div class="share">
  <h3><?php print t('Share this petition') ?></h3>
  <ul class="share__links">
    <li class="share__links__item share__links__item--facebook">
      <a class="share__links__item__link" href="https://www.facebook.com/sharer/sharer.php?u=<?php print drupal_encode_path(url($_GET['q'],array('absolute'=>TRUE))); ?>" target="_blank">
        <i class="icon icon-facebook"></i> <span>teilen</span>
      </a>
    </li>
    <li class="share__links__item share__links__item--twitter">
      <a class="share__links__item__link" href="https://twitter.com/home?status=<?php print drupal_encode_path(url($_GET['q'],array('absolute'=>TRUE))); ?>" target="_blank">
        <i class="icon icon-twitter"></i> <span>tweet</span>
      </a>
    </li>
    <li class="share__links__item share__links__item--google">
      <a class="share__links__item__link" href="https://plus.google.com/share?url=<?php print drupal_encode_path(url($_GET['q'],array('absolute'=>TRUE))); ?>" target="_blank">
        <i class="icon icon-google-plus"></i> <span>+1</span>
      </a>
    </li>
    <li class="share__links__item share__links__item--whatsapp">
      <a class="share__links__item__link" href="whatsapp://send" target="_blank" data-text="<?php print t('Take a look at this petition:');?>" data-href="<?php print drupal_encode_path(url($_GET['q'],array('absolute'=>TRUE))); ?>">
        <i class="icon icon-whatsapp"></i> <span>WhatsApp</span>
      </a>
    </li>
    <li class="share__links__item share__links__item--mail">
      <a class="share__links__item__link" href="mailto:?&subject=abgeordnetenwatch.de&body=<?php print drupal_encode_path(url($_GET['q'],array('absolute'=>TRUE))); ?>" target="_blank">
        <i class="icon icon-mail"></i> <span>e-mail</span>
      </a>
    </li>
  </ul>
</div>
