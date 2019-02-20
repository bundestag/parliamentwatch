<?php

/**
 * @file field.tpl.php
 * Override field output for committees on the full poll view-mode.
 */
?>
<?php if (sizeof($items) > 0): ?>
  <ul id="committee-tags" class="tag-list tag-list--committee">
    <?php foreach ($items as $delta => $item): ?>
      <li>
        <?php print l(render($item), 'node/' . $item['#item']['entity']->nid) ?>
      </li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
