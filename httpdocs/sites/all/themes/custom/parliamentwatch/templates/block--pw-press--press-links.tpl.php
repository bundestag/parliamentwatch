<?php

/**
 * @file
 * Link-list for press-area
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */
?>

<div class="press-links">
  <div class="container-regular">
    <?php print render($title_suffix) ?>
    <?php print render($content) ?>
  </div>
</div>