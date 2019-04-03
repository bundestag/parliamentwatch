<?php

/**
 * @file
 * Add markup for attachments
 */
?>
<div class="attachment">
  <?php foreach ($items as $delta => $item): ?>
    <?php print l('<span class="attachment__item__text"><span class="attachment__item__text__suffix">' . pathinfo($item['#file']->uri, PATHINFO_EXTENSION) . '</span>-' . t('Attachment') . '<span class="attachment__item__text__filesize">' . format_size($item['#file']->filesize) . '</span></span>', file_create_url($item['#file']->uri), array('attributes' => array('class' => array('attachment__item'), 'target'=>'_blank'), 'html' => TRUE)); ?>
  <?php endforeach; ?>
</div>