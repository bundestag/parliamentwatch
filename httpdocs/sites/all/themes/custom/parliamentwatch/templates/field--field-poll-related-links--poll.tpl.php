<?php

/**
 * @file field.tpl.php
 * Override field output for related links on node-type poll.
 */
?>
<?php if (sizeof($items) > 0): ?>
  <ul class="link-list">
    <?php foreach ($items as $delta => $item): ?>
      <li class="link-list__item link-list__item--full">
        <?php print render($item) ?>
      </li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
