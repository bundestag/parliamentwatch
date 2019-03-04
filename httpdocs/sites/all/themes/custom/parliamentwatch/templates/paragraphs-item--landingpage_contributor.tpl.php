<?php

/**
 * @file
 * Add tile markup for contributor paragraph-item
 */
?>
<div class="tile tile--contributor"<?php print $attributes; ?> data-modal-trigger data-modal-name="modal_contributor-<?php print $id; ?>">
  <figure class="tile--contributor__image">
    <span class="tile--contributor__image__inner">
      <?php print render($content['field_contributor_image']); ?>
      <?php print render($content['field_contributor_image_hover']); ?>
    </span>
  </figure>
  <h3 class="text-center">
    <?php print render($content['field_contributor_name']); ?>
  </h3>
  <p class="text-center">
    <?php print render($content['field_contributor_job_title']); ?>
  </p>
</div>

<div class="modal modal--contributor" data-modal-name="modal_contributor-<?php print $id; ?>">
  <div class="modal__container">
    <div class="modal__content">
      <button class="modal__close" data-modal-close><i class="icon icon-close"></i></button>
      <figure class="modal--contributor__image">
        <div class="modal--contributor__image__inner">
          <?php print render($content['field_contributor_image']); ?>
          <?php print render($content['field_contributor_image_hover']); ?>
        </div>
      </figure>
      <div class="modal--contributor__content">
        <p class="h2"><?php print render($content['field_contributor_name']); ?></p>
        <p><?php print render($content['field_contributor_job_title']); ?></p>
        <?php print render($content['field_contributor_description']); ?>
        <?php if ($content['field_contributor_email']): ?>
          <p class="modal--contributor__content__link"><i class="icon icon-mail"></i> <a href="<?php print str_rot13('mailto: ' . ltrim(render($content['field_contributor_email']))); ?>" class="encrypt-rot13"><?php print str_rot13(ltrim(render($content['field_contributor_email']))); ?></a></p>
        <?php endif; ?>
        <?php if ($content['field_contributor_telephone']): ?>
          <p class="modal--contributor__content__link"><i class="icon icon-phone"></i> <?php print render($content['field_contributor_telephone']); ?></p>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
<div class="modal-overlay" data-modal-close data-modal-name="modal_contributor-<?php print $id; ?>"></div>