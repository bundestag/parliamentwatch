<?php

/**
 * @file
 * Add tile-wrapper to contributor group paragraph-item
 */
?>
<div class="tile-wrapper tile-wrapper--contributor"<?php print $attributes; ?>>
  <?php if ($content['field_landingpage_headline']): ?>
    <h2><?php print render($content['field_landingpage_headline']); ?></h2>
  <?php endif; ?>
  <?php print render($content['field_landingpage_contributor']); ?>
</div>
