<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
  <?php print $head; ?>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <?php print render($assets); ?>
</head>
<body class="<?php print $classes; ?> blank-theme" <?php print $attributes;?>>
  <?php print render($tracking); ?>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <script language="javascript">
    var pymChild = new pym.Child({ id: 'awpym' });
    var searchKeys = document.getElementById('edit-keys');
    var submitButton = document.getElementById('edit-submit');
    if (searchKeys && submitButton) {
      document.getElementById('edit-submit').addEventListener('click', function(e){
        var keys = searchKeys.value;
        pymChild.sendMessage('awSearchSubmit', '?keys=' + keys + '?op=');
      }, false);
    };
  </script>
</body>
</html>
