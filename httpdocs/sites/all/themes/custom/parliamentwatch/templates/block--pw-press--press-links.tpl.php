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
      <li class="press-links__list__item press-links__list__item--1">
        <?php print l(
          '<i class="press-links__list__item__icon icon icon-folders"></i>' . t('Press Review'),
          'ueber-uns/presse/pressespiegel',
          array(
            'attributes' => array('class' => array('press-links__list__item__link')),
            'html' => TRUE
          )); ?>
      </li>
      <li class="press-links__list__item press-links__list__item--2">
        <?php print l(
          '<i class="press-links__list__item__icon icon icon-folders"></i>' . t('Press releases'),
          'ueber-uns/presse/pressemitteilungen',
          array(
            'attributes' => array('class' => array('press-links__list__item__link')),
            'html' => TRUE
          )); ?>
      </li>
      <li class="press-links__list__item press-links__list__item--3">
        <?php print l(
          '<i class="press-links__list__item__icon icon icon-thesis"></i>' . t('Press newsletter'),
          'node/972122',
          array(
            'attributes' => array('class' => array('press-links__list__item__link')),
            'html' => TRUE
          )); ?>
      </li>
      <li class="press-links__list__item press-links__list__item--4">
        <?php print l(
          '<i class="press-links__list__item__icon icon icon-download"></i>' . t('Press package'),
          'node/39911',
          array(
            'attributes' => array('class' => array('press-links__list__item__link')),
            'html' => TRUE
          )); ?>
      </li>
      <li class="press-links__list__item press-links__list__item--5">
        <?php print l(
          '<i class="press-links__list__item__icon icon icon-group"></i>' . t('Contributors'),
          'node/7751',
          array(
            'attributes' => array('class' => array('press-links__list__item__link')),
            'html' => TRUE
          )); ?>
      </li>
      <li class="press-links__list__item press-links__list__item--6">
        <?php print l(
          '<i class="press-links__list__item__icon icon icon-mail"></i>' . t('Contact'),
          'node/6578',
          array(
            'attributes' => array('class' => array('press-links__list__item__link')),
            'html' => TRUE
          )); ?>
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
          'class' => 'btn', 'btn--mobile-block'
        ),
        'html' => TRUE
      )); ?>
  </div>
</div>
