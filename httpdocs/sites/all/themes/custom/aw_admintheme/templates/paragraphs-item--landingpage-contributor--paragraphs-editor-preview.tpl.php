<?php

/**
 * @file
 * Add markup for paragraph-items rendering a person
 */
?>

<div class="paragraph-item paragraph-item--person">
  <?php if ($content['field_contributor_image']): ?>
  <div class="paragraph-item--person__image">
    <?php print render($content['field_contributor_image']); ?>
  </div>
  <?php endif; ?>
  <div class="paragraph-item--person__info">
    <?php print render($content['field_contributor_name']); ?>
    <?php print render($content['field_contributor_job_title']); ?>
  </div>
</div>
