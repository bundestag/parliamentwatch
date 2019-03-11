<?php

/**
 * @file
 * Add headline format to landingpage-headlines in paragraph-item
 */
?>

<?php if ($content['field_landingpage_headline']): ?>
  <h2><?php print render($content['field_landingpage_headline']); ?></h2>
<?php endif; ?>
<?php print render($content['field_landingpage_contributor']); ?>
