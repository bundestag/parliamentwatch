<article id="node-<?php print $node->nid; ?>" class="press-release--detail <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="press-release__content" <?php print $content_attributes; ?>>
    <div class="press-release__content__inner">
      <header class="press-release__header">
        <h1 class="press-release__header__headline"><?php print render($title); ?></h1>
        <div class="press-release__header__submitted">
          <?php if ($display_submitted): ?>
            <?php print $submitted; ?>
          <?php endif; ?>
        </div>
      </header>
      <?php print render($content['field_press_release_body']); ?>
    </div>
  </div>
</article>

<div class="container-small">
  <aside class="press-contact">
    <div class="press-contact__image">
      <img src="/<?php print drupal_get_path('theme', 'parliamentwatch'); ?>/images/lea_briand.jpg" alt="Léa Briand">
    </div>

    <div class="press-contact__content">
      <h1 class="press-contact__title h3"><?php print t('Contact person for press inquiries'); ?></h1>
      <p class="press-contact__subtitle">Léa Briand, <?php print t('Press spokeswoman'); ?></p>

      <div class="press-contact__details">
        <div class="press-contact__detail"><?php print t('Phone'); ?>: 040 / 3176910 23</div>
        <div class="press-contact__detail"><?php print t('Email'); ?>: <a href="mailto:briand@abgeordnetenwatch.de">briand@abgeordnetenwatch.de</a></div>
      </div>
    </div>
  </aside>
</div>
