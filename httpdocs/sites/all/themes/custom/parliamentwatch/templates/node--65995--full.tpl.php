<?php

/**
 * @file
 * Add container-small to sticker-webform
 */
?>
<div class="container-small">
  <div id="node-<?php print $node->nid; ?>" class="webform-container clearfix <?php print $classes; ?>"<?php print $attributes; ?>>
    <div class="intro">
      <?php print render($title_prefix); ?>
      <h1><?php print $title; ?></h1>
      <?php print render($title_suffix); ?>
    </div>

    <?php if ($display_submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>

    <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
    ?>

    <?php print render($content['links']); ?>

    <?php print render($content['comments']); ?>

  </div>
</div>
