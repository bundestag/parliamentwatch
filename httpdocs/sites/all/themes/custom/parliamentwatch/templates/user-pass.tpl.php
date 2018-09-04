<h1><?php print t('Reset password'); ?></h1>
<p><?php print t('Please enter your e-mail address. We will send you a link. If you do not receive the e-mail, please contact <a href="mailto: service@abgeordnetenwatch.de">service@abgeordnetenwatch.de</a> or 030-2574 2081.'); ?></p>
<?php print drupal_render_children($form) ?>
<div class="form__item form__item--back-link">
  <a href="/user" class="link-icon"><i class="icon icon-arrow-left"></i> <?php print t('Back'); ?></a>
</div>
