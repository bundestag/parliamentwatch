<?php

/**
 * @file
 * Theme implementation to display node-type landingpage in view-mode 'full'
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php print render($content['field_landingpage_paragraphs']); ?>
    <?php if ($content['body']): ?>
    <div class="container">
      <div class="landingpage__text">
        <?php print render($content['body']); ?>
      </div>
    </div>
    <?php endif; ?>
  </div>
  <?php print render($content['comments']); ?>
</div>
