<article id="press-release-<?php print $node->nid; ?>" class="<?php print $classes; ?> press-release tile clearfix"<?php print $attributes; ?>>
  <header class="tile__title tile__title--date mh-item">
    <span class="date">
      <span class="date__day"><?php print format_date(strtotime($content['field_press_release_date']['#items'][0]['value']), 'custom', 'd'); ?></span>
      <span class="date__month"><?php print format_date(strtotime($content['field_press_release_date']['#items'][0]['value']), 'custom', 'M'); ?></span>
      <span class="date__year"><?php print format_date(strtotime($content['field_press_release_date']['#items'][0]['value']), 'custom', 'Y'); ?></span>
    </span>
    <h3><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
  </header>
  <?php print render($title_suffix); ?>
  <div class="tile__content" data-mh="link-list">
    <p><?php print render($content['field_press_release_body']); ?></p>
  </div>
  <ul class="tile__links tile__links--2">
    <li class="tile__links__item"><a class="tile__links__item__link" href="<?php print $node_url ?>"><?php print t('read more'); ?></a></li>
  </ul>
</article>
