<article id="press-release-<?php print $node->nid; ?>" class="<?php print $classes; ?> tile tile--press-release clearfix"<?php print $attributes; ?>>
  <header class="tile__title tile__title--date mh-item">
    <?php print $date ?>
    <h3><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
  </header>
  <?php print render($title_suffix); ?>
  <div class="tile__content" data-mh="link-list">
    <p><?php print render($content['field_press_release_body']); ?></p>
  </div>
  <ul class="tile__links tile__links--2">
    <li class="tile__links__item">
      <?php print l(t('read more'), $node_url, array('attributes' => array('class' => array('tile__links__item__link')))); ?>
    </li>
  </ul>
</article>
