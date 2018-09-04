<h1><?php print t('Login'); ?></h1>
<p><?php print t('If you are a politician you can log in and edit your profile.'); ?></p>
<?php print drupal_render_children($form); ?>
<div class="form__item form__item--request-password">
  <a href="/user/password" class="link-icon"><i class="icon icon-arrow-right"></i> <?php print t('Reset password'); ?></a>
</div>
