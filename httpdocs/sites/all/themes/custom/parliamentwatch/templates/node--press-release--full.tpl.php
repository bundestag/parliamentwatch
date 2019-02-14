<article id="node-<?php print $node->nid; ?>" class="press-release detail <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="press-release__content" <?php print $content_attributes; ?>>
    <div class="press-release__content__inner">
      <header class="press-release__header">
        <h1><?php print render($title); ?></h1>
        <div class="press-release__header__submitted">
          <?php if ($display_submitted): ?>
            <?php print $submitted; ?>
          <?php endif; ?>
        </div>
      </header>
      <?php print render($content['field_press_release_body']); ?>
    </div>
</article>
