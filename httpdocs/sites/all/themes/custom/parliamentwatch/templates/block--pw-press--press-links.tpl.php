<?php

/**
 * @file
 * Link-list for press-area
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */
?>

<div class="press-links">
  <div class="container-regular">
    <?php print render($title_suffix) ?>
    <?php print render($content) ?>
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
          'class' => 'btn', 'btn--mobile-block'
        ),
        'html' => TRUE
      )); ?>
  </div>
</div>
