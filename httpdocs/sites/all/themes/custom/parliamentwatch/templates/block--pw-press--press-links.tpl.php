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
