<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>

<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
<div id="skip-link">
  <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
</div>
<?php print $page_top; ?>

<div class="page-container" data-sidebar-container>
  <header id="header">
    <div class="header__inner">
      <?php if ($logo): ?>
        <a class="header__logo" href="<?php print $front_page; ?>" title="<?php print t('Back to home'); ?>" rel="home">
          <div class="svg-container">
            <svg viewBox="0 0 391.2 53.2"><path fill="#EC663B" d="M0 18.2v-.1c0-2.3.8-4.1 2.4-5.5s3.4-2.1 5.3-2.2h.8c1.1 0 2.1.3 3.2.7s1.8 1.2 2.4 2.1v-2.6h1.7v15h-1.7v-2.5c-.5.9-1.4 1.6-2.3 2.1-1.1.4-2 .7-3.2.8H7.2c-1.8-.2-3.4-.9-4.9-2.2C.7 22.4 0 20.6 0 18.5v-.3c.1.1.1.1 0 0 .1 0 .1 0 0 0zm2.2-.4v.4c0 1.7.5 3.1 1.6 4.2 1.1 1.2 2.6 1.7 4.7 1.7 1.5 0 2.6-.5 3.7-1.6.9-1.1 1.6-2.3 1.7-3.6v-1.4c-.2-1.5-.7-2.6-1.8-3.6-.9-.9-2.2-1.4-3.9-1.5h-.3c-1.3 0-2.4.4-3.4 1.2-.9.7-1.6 1.7-2 2.6-.1.3-.2.5-.2.7 0 .4-.1.7-.1.9 0-.1 0-.1 0 0zM19.8 5.5h1.9V13c.6-.8 1.5-1.5 2.6-2s2.2-.8 3.4-.8c.3 0 .7 0 1.1.1.3 0 .7.1 1.1.2.6.2 1.3.4 1.8.7.6.3 1.2.7 1.7 1.4.6.6 1.2 1.4 1.5 2.3.3.9.5 1.9.6 2.9v.8c0 1.3-.3 2.4-.9 3.6-.6 1.2-1.5 2-2.6 2.6-.4.2-.8.4-1.3.5-.4.1-.9.2-1.4.3-.2 0-.4.1-.6.1h-1.3c-1.1-.1-2.1-.3-3.2-.7-1.1-.4-1.9-1.1-2.5-1.8v2.5h-1.9V5.5c-.1 0 0 0 0 0zm3.1 16.4c.8 1.3 2.3 2 4.5 2h.4c1.6-.1 2.9-.7 4-1.8s1.6-2.5 1.6-4.4c0-1.5-.6-2.8-1.9-4s-2.6-1.8-4.1-1.8c-.3 0-.7.1-1.1.2-.4.1-.8.3-1.3.5-.8.4-1.7 1.2-2.3 2-.7.8-1.1 1.9-1.1 3.1.1 1.4.5 2.9 1.3 4.2zm17.5-9.5c1.4-1.3 2.8-1.9 4.4-2.1h1.1c1.2 0 2.3.3 3.4.9 1.1.5 1.8 1.3 2.3 2.2v-2.7h2.1v12.9c0 2.5-.7 4.5-2.3 5.8-1.6 1.3-3.3 1.9-5.2 1.9h-.4c-1.5-.1-2.9-.6-4.3-1.6-1.4-.9-2.3-2.3-2.8-4.1h1.9c.4 1.2 1.2 2 2.1 2.5.9.5 1.9.9 2.9.9h.6c1.4-.1 2.6-.5 3.8-1.6 1.2-.9 1.7-2.3 1.7-4.1v-.8c-.3.8-1.1 1.6-2.2 2.1-1.3.5-2.5.8-3.9.8h-1.1c-1.6-.2-3.1-.8-4.4-2-1.4-1.2-2-2.9-2-5.4v-.4c.2-2 .9-3.9 2.3-5.2zm0 5.2v.4c0 1.7.4 3.1 1.4 4.2s2.3 1.7 4 1.7c1.5 0 2.8-.4 4-1.4s1.8-2.5 1.8-4.8c0-1.4-.5-2.5-1.6-3.5-1.1-1.1-2.2-1.6-3.5-1.8h-.7c-1.2.1-2.1.4-2.8.9-.7.5-1.3 1.1-1.7 1.7-.3.5-.6.9-.7 1.5-.1.4-.2.8-.2 1.1 0-.1 0-.1 0 0zm18.4-5.2c1.6-1.3 3.2-1.9 5.1-2h.4c1.9 0 3.6.7 5.2 2s2.3 3.2 2.3 5.7v.6H58.5c.2 1.8.8 3.1 1.9 3.8 1.1.8 2.1 1.3 3.3 1.4h.8c1.2-.1 2.2-.4 3.2-.9.9-.6 1.7-1.4 1.9-2.2h2.1c-.6 1.7-1.6 3.1-2.8 3.8-1.3.8-2.6 1.3-4 1.3h-.5c-1.9 0-3.7-.7-5.4-2.1-1.6-1.4-2.4-3.3-2.5-5.6 0-2.6.8-4.5 2.3-5.8zm9.1 1.3c-.9-.9-2.1-1.5-3.6-1.6-1.3.1-2.3.4-3.1.9-.7.5-1.4 1.1-1.8 1.6-.3.5-.6.9-.7 1.4-.1.4-.2.7-.3.9h11.4c-.4-1.2-1.1-2.3-1.9-3.2zm8.4-1.2c1.5-1.5 3.5-2.2 5.9-2.2 2.1 0 3.9.6 5.4 2s2.1 3.1 2.1 5.1c0 2.6-.7 4.6-2.2 6.1-1.5 1.5-3.3 2.2-5.6 2.2-2.1 0-4-.6-5.5-2s-2.3-3.3-2.4-5.9c.1-2 .8-3.7 2.3-5.3zm1.5 9.5c.9 1.1 2 1.7 3.2 1.8h1.2c1.4-.1 2.6-.7 3.8-1.7 1.2-1.1 1.7-2.6 1.7-4.7 0-1.5-.5-2.6-1.7-3.6-1.2-.9-2.4-1.4-3.9-1.5h-.4c-1.5 0-2.7.5-3.8 1.6-.9 1.1-1.6 2.3-1.6 4 0 1.7.5 3.1 1.5 4.1zm14.7-11.5h1.9v2c.4-.7 1.1-1.4 1.7-1.7.7-.3 1.6-.5 2.6-.5v2.2c-.2 0-.4 0-.6.1-.2 0-.4.1-.6.2-.7.2-1.5.6-2.1 1.3-.6.6-.9 1.4-.9 2.3v9.3h-1.9c-.1 0-.1-15.2-.1-15.2zm10.6 1.7c1.5-1.2 3.1-1.8 4.8-1.9h1.4c.9.1 1.9.4 2.7.8.9.4 1.7 1.1 2.2 1.9V5.5h1.7v20.1h-1.7v-2.7c-.6.8-1.4 1.6-2.2 2-.8.4-1.8.7-2.7.8h-1.1c-1.9 0-3.7-.7-5.3-2.1-1.6-1.4-2.4-3.3-2.4-5.7v-.5c.3-2.3 1.1-4 2.6-5.2zm-.6 5.2v.5c0 1.6.4 2.9 1.4 4.2s2.4 2 4.5 2h.5c.2 0 .3 0 .5-.1 1.2-.3 2.2-.9 3.3-2 .9-1.1 1.5-2.4 1.5-4v-.3c0-.3 0-.6-.1-1.1s-.3-.8-.5-1.3c-.4-.7-.9-1.5-1.8-2-.8-.6-1.9-.9-3.4-.9-.3 0-.7 0-1.1.1-.4.1-.8.2-1.3.4-.8.3-1.6.8-2.3 1.6-.7.7-1.1 1.7-1.2 2.7v.2zm17.4-6.9h1.9v2c.4-.6 1.1-1.1 1.9-1.5.7-.3 1.6-.6 2.4-.7h.8c1.5 0 2.8.5 4.1 1.5 1.3.9 1.9 2.5 1.9 4.5v9.3h-2v-9.3c0-1.4-.4-2.4-1.4-3.2-.8-.7-1.9-1.1-2.9-1.2h-.6c-1.2 0-2.1.4-3.1 1.2-.9.7-1.4 1.7-1.4 3.1v9.4h-1.9v-15l.3-.1zm18.4 1.9c1.6-1.3 3.2-1.9 5.1-2h.4c1.9 0 3.6.7 5.2 2s2.3 3.2 2.3 5.7v.6h-13.4c.2 1.8.8 3.1 1.9 3.8 1.1.8 2.1 1.3 3.3 1.4h.8c1.2-.1 2.2-.4 3.2-.9.9-.6 1.7-1.4 1.9-2.2h2.1c-.6 1.7-1.6 3.1-2.8 3.8-1.3.8-2.6 1.3-4 1.3h-.5c-1.9 0-3.7-.7-5.4-2.1-1.6-1.4-2.4-3.3-2.5-5.6-.1-2.6.8-4.5 2.4-5.8zm8.9 1.3c-.9-.9-2.1-1.5-3.6-1.6-1.3.1-2.3.4-3.1.9-.7.5-1.4 1.1-1.8 1.6-.3.5-.6.9-.7 1.4-.1.4-.2.7-.3.9h11.4c-.3-1.2-.9-2.3-1.9-3.2zm5.8-1v-2h2.9v-5h1.9v5.1h3.5v2h-3.5v12.8h-1.9V12.7H153zm12.5-.3c1.6-1.3 3.2-1.9 5.1-2h.4c1.9 0 3.6.7 5.2 2s2.3 3.2 2.3 5.7v.6h-13.3c.2 1.8.8 3.1 1.9 3.8 1.1.8 2.1 1.3 3.3 1.4h.8c1.2-.1 2.2-.4 3.2-.9.9-.6 1.7-1.4 1.9-2.2h2.1c-.6 1.7-1.6 3.1-2.8 3.8-1.3.8-2.6 1.3-4 1.3h-.6c-1.9 0-3.7-.7-5.4-2.1-1.6-1.4-2.4-3.3-2.5-5.6.1-2.6.9-4.5 2.4-5.8zm9.1 1.3c-.9-.9-2.1-1.5-3.6-1.6-1.3.1-2.3.4-3.1.9-.7.5-1.4 1.1-1.8 1.6-.3.5-.6.9-.7 1.4-.1.4-.2.7-.3.9h11.4c-.4-1.2-1-2.3-1.9-3.2zm6.8-3.2h1.9v2c.4-.6 1.1-1.1 1.9-1.5.7-.3 1.6-.6 2.4-.7h.8c1.5 0 2.8.5 4.1 1.5 1.3.9 1.9 2.5 1.9 4.5v9.3h-1.9v-9.3c0-1.4-.4-2.4-1.4-3.2-.8-.7-1.9-1.1-2.9-1.2h-.6c-1.2 0-2.1.4-3.1 1.2-.9.7-1.4 1.7-1.4 3.1v9.4h-1.9v-15c.1-.1.2-.1.2-.1z"/><path fill="#575756" d="M204.7 25.6h-2.4l-5.7-14.8h2.1l4.7 12.2 3.4-10.4h1.7L212 23l4.6-12.2h2.2l-5.6 14.8h-2.3l-3.3-9.3-2.9 9.3zm16.2-7.4v-.1c0-2.3.8-4.1 2.4-5.5s3.4-2.1 5.3-2.2h.8c1.1 0 2.1.3 3.2.7s1.8 1.2 2.4 2.1v-2.6h1.7v15H235v-2.5c-.5.9-1.4 1.6-2.3 2.1-1.1.4-2 .7-3.2.8H228c-1.8-.2-3.4-.9-4.9-2.2-1.5-1.3-2.2-2.9-2.2-5.1v-.3c.1-.1.1-.1 0-.2.1 0 .1 0 0 0zm2.2-.4v.4c0 1.7.5 3.1 1.6 4.2 1.1 1.2 2.6 1.7 4.7 1.7 1.5 0 2.6-.5 3.7-1.6.9-1.1 1.6-2.3 1.7-3.6v-1.4c-.2-1.5-.7-2.6-1.8-3.6-.9-.9-2.2-1.4-3.9-1.5h-.3c-1.3 0-2.4.4-3.4 1.2-.9.7-1.6 1.7-2 2.6-.1.3-.2.5-.2.7 0 .4-.1.7-.1.9 0-.1 0-.1 0 0zm16.2-5.1v-2h2.9v-5h1.9v5.1h3.5v2h-3.5v12.8h-1.9V12.7h-2.9zm12.8-.5c1.6-1.4 3.4-2.1 5.4-2.1h1.1c1.3.2 2.4.6 3.6 1.4 1.2.7 2.1 1.9 2.8 3.4h-2.3c-.4-.9-1.2-1.6-2-2.1-.9-.4-1.9-.6-2.9-.6h-.4c-.9.1-2 .3-2.8.8-.9.4-1.6 1.1-1.9 1.9l-.3.6c-.1.2-.1.4-.2.6-.1.3-.2.6-.2.9-.1.3-.1.6-.1.9 0 .7.1 1.5.4 2.1.3.6.6 1.3 1.1 1.7.2.2.5.4.7.6.2.2.5.4.7.5.5.3 1.1.5 1.6.6.5.1 1.1.2 1.5.2 1.1 0 2.1-.3 2.9-.8.9-.5 1.6-1.2 2-1.9 0 0 0-.1.1-.1l.1-.1h2.3c-.8 1.4-1.7 2.3-2.7 3.1-1.1.7-2.1 1.3-3.2 1.5-.3.1-.5.1-.8.1h-.8c-2 0-3.9-.7-5.5-2.2-1.6-1.5-2.4-3.3-2.4-5.6-.2-2 .6-3.9 2.2-5.4zm15.8-6.7h1.9v7.1c.6-.7 1.3-1.3 2-1.6.7-.3 1.5-.5 2.2-.6h.4c1.7 0 3.2.6 4.5 1.9 1.4 1.3 2 2.6 2 4.2v9.3h-2.1v-9.3c-.2-1.3-.7-2.3-1.6-2.9s-1.7-1.1-2.6-1.2h-.4c-1.1 0-2.1.4-3.1 1.2-.9.7-1.4 1.8-1.4 3.3v9h-1.9c.1-.1.1-20.4.1-20.4zM285.4 22h2.1v3.6h-2.1V22zm8.9-9.8c1.5-1.2 3.1-1.8 4.8-1.9h1.4c.9.1 1.9.4 2.7.8.9.4 1.7 1.1 2.2 1.9V5.5h1.7v20.1h-1.7v-2.7c-.6.8-1.4 1.6-2.2 2-.8.4-1.8.7-2.7.8h-1.1c-1.9 0-3.7-.7-5.3-2.1-1.6-1.4-2.4-3.3-2.4-5.7v-.5c.2-2.3 1.1-4 2.6-5.2zm-.7 5.2v.5c0 1.6.4 2.9 1.4 4.2s2.4 2 4.5 2h.5c.2 0 .3 0 .5-.1 1.2-.3 2.2-.9 3.3-2 .9-1.1 1.5-2.4 1.5-4v-.3c0-.3 0-.6-.1-1.1s-.3-.8-.5-1.3c-.4-.7-.9-1.5-1.8-2-.8-.6-1.9-.9-3.4-.9-.3 0-.7 0-1.1.1-.4.1-.8.2-1.3.4-.8.3-1.6.8-2.3 1.6-.7.8-1 1.7-1.2 2.9 0-.1 0-.1 0 0zm19.2-5c1.6-1.3 3.3-1.9 5.1-2h.4c1.9 0 3.6.7 5.2 2s2.3 3.2 2.3 5.7v.6h-13.3c.2 1.8.8 3.1 1.9 3.8 1.1.8 2.1 1.3 3.3 1.4h.8c1.2-.1 2.2-.4 3.2-.9.9-.6 1.7-1.4 1.9-2.2h2.1c-.6 1.7-1.6 3.1-2.8 3.8-1.3.8-2.6 1.3-4 1.3h-.5c-1.9 0-3.7-.7-5.4-2.1-1.6-1.4-2.4-3.3-2.5-5.6-.1-2.6.8-4.5 2.3-5.8zm9.1 1.3c-.9-.9-2.1-1.5-3.6-1.6-1.3.1-2.3.4-3.1.9-.7.5-1.4 1.1-1.8 1.6-.3.5-.6.9-.7 1.4-.1.4-.2.7-.3.9h11.4c-.4-1.2-1.1-2.3-1.9-3.2zM110.6 45.5l-1.4-4.4c-.1-.3-.2-.8-.5-1.8h-.1c-.2.8-.3 1.4-.5 1.8l-1.4 4.3h-1.3l-2-7.5h1.2c.5 1.9.8 3.3 1.1 4.3.2.9.4 1.7.4 2h.1c0-.2.1-.6.2-1.1.1-.4.2-.7.3-.9l1.4-4.3h1.3l1.4 4.3c.2.7.4 1.5.5 2h.1c0-.2.1-.4.1-.7.1-.3.5-2.2 1.4-5.5h1.2l-2.1 7.5h-1.4zm7.9.1c-1.1 0-2-.3-2.6-1.1-.6-.6-.9-1.6-.9-2.8 0-1.2.3-2.1.8-2.8.6-.7 1.4-1.1 2.4-1.1.9 0 1.7.3 2.2.9.5.6.8 1.5.8 2.4v.7H116c0 .8.2 1.6.6 2 .4.4 1.1.6 1.8.6.8 0 1.6-.2 2.4-.5V45c-.4.2-.7.3-1.2.4-.2.2-.6.2-1.1.2zm-.3-6.8c-.6 0-1.1.2-1.5.6-.3.4-.5.9-.6 1.6h3.9c0-.7-.2-1.3-.5-1.7-.4-.4-.7-.5-1.3-.5zm4.9-2.8c0-.2.1-.4.2-.5.1-.1.3-.2.5-.2s.3.1.4.2c.1.1.2.3.2.5s-.1.4-.2.5c-.1.1-.3.2-.4.2-.2 0-.3-.1-.5-.2s-.2-.2-.2-.5zm1.2 9.5h-1.2V38h1.2v7.5zm3.5 0h-1.2V34.9h1.2v10.6zm8.5-.8h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.5 0-2.2-.7-2.2-2.3v-4.4h-1.1v-.5l1.1-.4.5-1.6h.6v1.7h2.2v.8H135v4.4c0 .4.1.8.3 1.1.2.2.5.3 1 .3zm5.9-6.8c.3 0 .6 0 .8.1l-.1 1.1c-.3-.1-.6-.1-.8-.1-.6 0-1.2.2-1.6.7-.4.5-.6 1.1-.6 1.8v4h-1.2V38h.9l.1 1.4h.1c.3-.5.6-.8.9-1.2.4-.3 1-.3 1.5-.3zm6.8 7.6l-.2-1.1h-.1c-.4.4-.7.7-1.2.9-.4.2-.8.2-1.4.2-.7 0-1.4-.2-1.8-.5-.4-.4-.6-.9-.6-1.6 0-1.5 1.2-2.3 3.6-2.3h1.3v-.4c0-.6-.1-1.1-.4-1.3s-.7-.4-1.2-.4c-.6 0-1.4.2-2.1.5l-.3-.8c.3-.2.7-.3 1.2-.4.4-.1.8-.2 1.4-.2.8 0 1.6.2 2 .6.4.4.6 1.1.6 1.9v4.8h-.8v.1zm-2.5-.8c.7 0 1.3-.2 1.7-.5.4-.4.6-.9.6-1.6V42h-1.2c-.9 0-1.6.2-1.9.4-.3.2-.6.6-.6 1.2 0 .4.1.7.4.9s.6.2 1 .2zm10.8.8v-4.8c0-.6-.1-1.1-.4-1.4-.3-.3-.7-.4-1.3-.4-.7 0-1.4.2-1.7.6-.3.4-.5 1.2-.5 2.1v3.9h-1.2V38h.9l.2 1.1h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.4-.3.9 0 1.6.2 2 .6.4.4.6 1.2.6 2.1v4.8h-1zm8.2-2c0 .7-.2 1.3-.7 1.6-.5.4-1.3.5-2.2.5s-1.8-.1-2.3-.4v-1.1c.3.2.7.3 1.2.4.4.1.8.1 1.2.1.6 0 1.1-.1 1.4-.3.3-.2.5-.5.5-.8s-.1-.5-.4-.7c-.2-.2-.7-.4-1.5-.7-.7-.2-1.2-.5-1.5-.6-.3-.1-.5-.4-.6-.6-.1-.2-.2-.5-.2-.8 0-.6.2-1.1.7-1.5.5-.3 1.2-.5 2-.5s1.6.2 2.3.5l-.4.9c-.7-.3-1.5-.4-2-.4s-.9.1-1.3.2c-.3.2-.4.4-.4.7 0 .2 0 .4.1.5.1.1.3.3.5.4.2.1.6.3 1.3.5.8.3 1.5.6 1.8.9.4.2.5.6.5 1.2zm5.4 2.1c-.5 0-.9-.1-1.4-.3-.4-.2-.7-.4-1.1-.8h-.1c.1.4.1.8.1 1.3v3.1h-1.2V38h.9l.1 1.1h.1c.3-.4.6-.7 1.1-.8.4-.1.8-.3 1.4-.3.9 0 1.8.3 2.3 1.1.5.6.8 1.6.8 2.8 0 1.3-.3 2.2-.8 2.8-.5.5-1.3.9-2.2.9zm-.2-6.8c-.7 0-1.3.2-1.7.6-.4.4-.5 1.1-.5 2v.2c0 1.1.2 1.8.5 2.2.3.4.9.6 1.7.6.6 0 1.2-.2 1.5-.7.3-.5.5-1.3.5-2.1 0-.9-.2-1.7-.5-2.1-.4-.5-.9-.7-1.5-.7zm9.8 6.7l-.2-1.1h-.1c-.4.4-.7.7-1.2.9-.4.2-.8.2-1.4.2-.7 0-1.4-.2-1.8-.5-.4-.4-.6-.9-.6-1.6 0-1.5 1.2-2.3 3.6-2.3h1.3v-.4c0-.6-.1-1.1-.4-1.3-.3-.2-.6-.4-1.2-.4s-1.4.2-2.1.5l-.3-.8c.3-.2.7-.3 1.2-.4.4-.1.8-.2 1.4-.2.8 0 1.6.2 2 .6.4.4.6 1.1.6 1.9v4.8l-.8.1zm-2.6-.8c.7 0 1.3-.2 1.7-.5.4-.4.6-.9.6-1.6V42H179c-.9 0-1.6.2-1.9.4-.3.2-.6.6-.6 1.2 0 .4.1.7.4.9.4.2.6.2 1 .2zm9.2-6.8c.3 0 .6 0 .8.1l-.1 1.1c-.3-.1-.6-.1-.8-.1-.6 0-1.2.2-1.6.7s-.6 1.1-.6 1.8v4h-1.2V38h.9l.1 1.4h.1c.3-.5.6-.8.9-1.2.4-.3 1-.3 1.5-.3zm5.4 7.7c-1.1 0-2-.3-2.6-1.1-.6-.7-.9-1.6-.9-2.8 0-1.2.3-2.1.8-2.8.6-.7 1.4-1.1 2.4-1.1.9 0 1.7.3 2.2.9.5.6.8 1.5.8 2.4v.7H190c0 .8.2 1.6.6 2 .4.4 1.1.6 1.8.6.8 0 1.6-.2 2.4-.5V45c-.4.2-.7.3-1.2.4-.2.2-.6.2-1.1.2zm-.4-6.8c-.6 0-1.1.2-1.5.6-.3.4-.5.9-.6 1.6h3.9c0-.7-.2-1.3-.5-1.7-.2-.3-.6-.5-1.3-.5zm10.1 6.7v-4.8c0-.6-.1-1.1-.4-1.4-.3-.3-.7-.4-1.3-.4-.7 0-1.4.2-1.7.6s-.5 1.2-.5 2.1v3.9h-1.2V38h.9l.2 1.1h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.4-.3.9 0 1.6.2 2 .6.4.4.6 1.2.6 2.1v4.8h-1zm8.2 0H205v-.7l4.1-5.8h-3.8v-.8h5.1v.8l-4 5.7h4.1v.8h-.1zm7.1 0l-2.8-7.5h1.3l1.6 4.4c.3 1.1.5 1.7.6 2h.1c0-.2.2-.7.4-1.5.3-.7.8-2.4 1.8-4.9h1.3l-2.8 7.5h-1.5zm8.4.1c-1.1 0-2-.3-2.6-1.1-.6-.7-.9-1.6-.9-2.8 0-1.2.3-2.1.8-2.8s1.4-1.1 2.4-1.1c.9 0 1.7.3 2.2.9s.8 1.5.8 2.4v.7h-5.2c0 .8.2 1.6.6 2 .4.4 1.1.6 1.8.6.8 0 1.6-.2 2.4-.5V45c-.4.2-.7.3-1.2.4-.1.2-.6.2-1.1.2zm-.3-6.8c-.6 0-1.1.2-1.5.6-.3.4-.5.9-.6 1.6h3.9c0-.7-.2-1.3-.5-1.7-.2-.3-.7-.5-1.3-.5zm8.4-.9c.3 0 .6 0 .8.1l-.1 1.1c-.3-.1-.6-.1-.8-.1-.6 0-1.2.2-1.6.7-.4.5-.6 1.1-.6 1.8v4h-1.2V38h.9l.1 1.4h.1c.3-.5.6-.8.9-1.2.5-.3 1-.3 1.5-.3zm4.6 6.8h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.5 0-2.2-.7-2.2-2.3v-4.4h-1.1v-.5l1.1-.4.5-1.6h.6v1.7h2.2v.8h-2.2v4.4c0 .4.1.8.3 1.1.4.1.7.3 1 .3zm6-6.8c.3 0 .6 0 .8.1l-.1 1.1c-.3-.1-.6-.1-.8-.1-.6 0-1.2.2-1.6.7-.4.5-.6 1.1-.6 1.8v4h-1.2V38h.9l.1 1.4h.1c.3-.5.6-.8.9-1.2.5-.3 1-.3 1.5-.3zm6.9 7.6l-.2-1.1h-.1c-.4.4-.7.7-1.2.9s-.8.2-1.4.2c-.7 0-1.4-.2-1.8-.5-.4-.4-.6-.9-.6-1.6 0-1.5 1.2-2.3 3.6-2.3h1.3v-.4c0-.6-.1-1.1-.4-1.3-.2-.3-.6-.4-1.2-.4s-1.4.2-2.1.5l-.3-.8c.3-.2.7-.3 1.2-.4.4-.1.8-.2 1.4-.2.8 0 1.6.2 2 .6.4.4.6 1.1.6 1.9v4.8h-.8v.1zm-2.5-.8c.7 0 1.3-.2 1.7-.5.4-.4.6-.9.6-1.6V42h-1.2c-.9 0-1.6.2-1.9.4-.3.2-.6.6-.6 1.2 0 .4.1.7.4.9.1.1.4.2 1 .2zm6.7-6.7v4.8c0 .6.1 1.1.4 1.4.3.3.7.4 1.3.4.7 0 1.4-.2 1.7-.6.3-.4.5-1.2.5-2.1V38h1.2v7.5h-.8l-.2-.9h-.1c-.2.3-.5.6-.9.8-.4.2-.8.3-1.4.3-.9 0-1.6-.2-2-.6s-.6-1.2-.6-2.1v-4.8h1.1V38zm10.6 7.6c-1.1 0-2-.3-2.6-1.1-.6-.6-.9-1.6-.9-2.8 0-1.2.3-2.1.8-2.8.5-.7 1.4-1.1 2.4-1.1.9 0 1.7.3 2.2.9.5.6.8 1.5.8 2.4v.7h-5.2c0 .8.2 1.6.6 2 .4.4 1.1.6 1.8.6.8 0 1.6-.2 2.4-.5V45c-.4.2-.7.3-1.2.4-.1.2-.6.2-1.1.2zm-.3-6.8c-.6 0-1.1.2-1.5.6-.3.4-.5.9-.6 1.6h3.9c0-.7-.2-1.3-.5-1.7-.2-.3-.7-.5-1.3-.5zm10.1 6.7v-4.8c0-.6-.1-1.1-.4-1.4s-.7-.4-1.3-.4c-.7 0-1.4.2-1.7.6-.3.4-.5 1.2-.5 2.1v3.9H271V38h.9l.2 1.1h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.4-.3.9 0 1.6.2 2 .6.4.4.6 1.2.6 2.1v4.8h-1zm11.9-2c0 .7-.2 1.3-.7 1.6-.5.4-1.3.5-2.2.5s-1.8-.1-2.3-.4v-1.1c.3.2.7.3 1.2.4.4.1.8.1 1.2.1.6 0 1.1-.1 1.4-.3.3-.2.5-.5.5-.8s-.1-.5-.4-.7c-.2-.2-.7-.4-1.5-.7-.7-.2-1.2-.5-1.5-.6-.3-.1-.5-.4-.6-.6s-.2-.5-.2-.8c0-.6.2-1.1.7-1.5.5-.4 1.2-.5 2-.5s1.6.2 2.3.5l-.4.9c-.7-.3-1.5-.4-2-.4s-.9.1-1.3.2c-.3.2-.4.4-.4.7 0 .2 0 .4.1.5.1.1.3.3.5.4.2.1.6.3 1.3.5.8.3 1.5.6 1.8.9.3.2.5.6.5 1.2zm4.7 2.1c-1.1 0-1.9-.3-2.5-.9s-.8-1.6-.8-2.8c0-1.3.3-2.2.9-2.8s1.5-1.1 2.5-1.1c.3 0 .7 0 1.1.1.3.1.6.2.8.3l-.3.9c-.2-.1-.5-.2-.8-.2-.3-.1-.5-.1-.7-.1-1.5 0-2.3.9-2.3 2.9 0 .9.2 1.6.5 2.1.4.5.9.7 1.7.7.6 0 1.3-.1 1.9-.4v.9c-.5.3-1.1.4-2 .4zm8.9-.1v-4.8c0-.6-.1-1.1-.4-1.4-.3-.3-.7-.4-1.3-.4-.7 0-1.4.2-1.7.6-.3.4-.5 1.2-.5 2.1v3.9h-1.2V34.9h1.2v3.2c0 .4 0 .7-.1.9h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.4-.3.9 0 1.6.2 2 .6.4.4.6 1.2.6 2.1v4.8l-1 .1zm8 0l-.2-1.1h-.1c-.4.4-.7.7-1.2.9-.4.2-.8.2-1.4.2-.7 0-1.4-.2-1.8-.5-.4-.4-.6-.9-.6-1.6 0-1.5 1.2-2.3 3.6-2.3h1.3v-.4c0-.6-.1-1.1-.4-1.3-.2-.3-.6-.4-1.2-.4s-1.4.2-2.1.5l-.3-.8c.3-.2.7-.3 1.2-.4.4-.1.8-.2 1.4-.2.8 0 1.6.2 2 .6.4.4.6 1.1.6 1.9v4.8l-.8.1zm-2.6-.8c.7 0 1.3-.2 1.7-.5.4-.4.6-.9.6-1.6V42h-1.2c-.9 0-1.6.2-1.9.4-.4.2-.6.6-.6 1.2 0 .4.1.7.4.9.2.1.5.2 1 .2zm9.1-5.8h-1.9v6.5H313v-6.5h-1.4v-.5l1.4-.4v-.4c0-1.8.8-2.7 2.4-2.7.4 0 .8.1 1.4.2l-.3.9c-.4-.1-.8-.2-1.2-.2-.4 0-.7.1-.9.4-.2.3-.3.7-.3 1.4v.5h1.9v.8h.1zm4.7 0h-1.9v6.5h-1.2v-6.5h-1.4v-.5l1.4-.4v-.4c0-1.8.8-2.7 2.4-2.7.4 0 .8.1 1.4.2l-.3.9c-.4-.1-.8-.2-1.2-.2-.4 0-.7.1-.9.4-.2.3-.3.7-.3 1.4v.5h1.9v.8h.1zm3.8 5.8h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.5 0-2.2-.7-2.2-2.3v-4.4h-1.1v-.5l1.1-.4.5-1.6h.6v1.7h2.2v.8h-2.2v4.4c0 .4.1.8.3 1.1.3.2.6.3 1 .3z"/><path fill="#EC663B" d="M383.4 53h-37.3c-4.3 0-7.8-3.5-7.8-7.8V8c0-4.3 3.5-7.8 7.8-7.8h37.3c4.3 0 7.8 3.5 7.8 7.8v37.3c0 4.3-3.5 7.7-7.8 7.7zM346.1 3c-2.8 0-5 2.2-5 5v37.2c0 2.8 2.2 5 5 5h37.3c2.8 0 5-2.2 5-5V8c0-2.8-2.2-5-5-5h-37.3zm29.8 13c2.6 2.7 4.1 6.2 4.4 9.8h5c-.3-5-2.3-9.6-5.7-13.2s-7.9-5.8-12.8-6.3l-.3 4.9c3.5.4 6.9 2.1 9.4 4.8zm-11.5-9.9c-5.4 0-10.5 2-14.4 5.8l3.4 3.6c2.9-2.8 6.7-4.4 10.8-4.4l.2-5c.1 0 .1 0 0 0zm11 32.3l3.4 3.6c1.8-1.7 3.3-3.8 4.4-6l-4.8-1.5c-.7 1.4-1.7 2.8-3 3.9zm9.9-10.5h-5c-.1 1.6-.4 3.1-1 4.5l4.7 1.5c.8-1.8 1.2-3.9 1.3-6zm-13.6-5.3c.6 1 1 2.1 1.2 3.3h5c-.2-2.5-1.1-4.8-2.6-6.8l-3.6 3.5zm-1.4 10.6l3.4 3.6c2.4-2.3 3.9-5.4 4.1-8.7h-5c-.2 1.9-1.1 3.7-2.5 5.1zm-15.2-15.9l3.4 3.6c1.5-1.4 3.3-2.2 5.4-2.3l.3-5c-3.5 0-6.7 1.3-9.1 3.7zm18.7.1c-2.1-2-4.7-3.3-7.5-3.7l-.3 5c1.6.3 3.1 1.1 4.3 2.2l3.5-3.5zm-9.4 9.4l-.1.1h.1v-.1z"/></svg>
          </div>
        </a>
      <?php endif; ?>
    </div>
  </header>

  <main id="content">
    <a id="main-content"></a>
    <?php print $messages; ?>

    <?php if ($tabs): ?><div class="tabs tabs--admin"><?php print render($tabs); ?></div><?php endif; ?>
    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    <?php if ($page['intro_primary']): ?>
    <div class="intro">
      <?php if ($page['intro_secondary']): ?>
      <div class="intro__left"><?php print render($page['intro_primary']); ?></div>
      <div class="intro__right"><?php print render($page['intro_secondary']); ?></div>
      <?php else: ?>
      <?php print render($page['intro_primary']); ?>
      <?php endif; ?>
    </div>
    <?php endif; ?>
    <div class="container">
      <div class="maintenance-message">
        <?php print $content; ?>
      </div>

      <?php print render($page['content']); ?>
    </div>
    <?php print render($page['content_tabs']); ?>
    <?php print render($page['content_extra']); ?>
  </main>


  <footer id="footer">
    <div class="footer__mediapartner">
      <h3 class="footer__mediapartner__title">Medienpartner</h3>
      <a href="http://www.spiegel.de" class="footer__mediapartner__link" title="Go to website of Spiegel Online"><img src="<?php print base_path() . path_to_theme(); ?>/images/medienpartner/logo_spon.png" alt="<?php print t('Logo of Spiegel Online'); ?>"></a>
      <a href="http://www.sueddeutsche.de" class="footer__mediapartner__link" title="Go to website of Süddeutsche"><img src="<?php print base_path() . path_to_theme(); ?>/images/medienpartner/logo_sueddeutsche.png" alt="<?php print t('Logo of Süddeutsche'); ?>"></a>
      <a href="https://www.welt.de" class="footer__mediapartner__link" title="Go to website of WELT-Online"><img src="<?php print base_path() . path_to_theme(); ?>/images/medienpartner/logo_welt.png" alt="<?php print t('Logo of Welt-Online'); ?>"></a>
      <a href="http://www.t-online.de" class="footer__mediapartner__link" title="Go to website of Süddeutsche"><img src="<?php print base_path() . path_to_theme(); ?>/images/medienpartner/logo_t_online.png" alt="<?php print t('Logo of T-Online'); ?>"></a>
    </div>
    <?php if ($logo): ?>
    <a class="footer__logo" href="<?php print $front_page; ?>" title="<?php print t('Back to home'); ?>" rel="home">
      <div class="svg-container">
        <svg viewBox="0 0 391.2 53.2"><path fill="#EC663B" d="M0 18.2v-.1c0-2.3.8-4.1 2.4-5.5s3.4-2.1 5.3-2.2h.8c1.1 0 2.1.3 3.2.7s1.8 1.2 2.4 2.1v-2.6h1.7v15h-1.7v-2.5c-.5.9-1.4 1.6-2.3 2.1-1.1.4-2 .7-3.2.8H7.2c-1.8-.2-3.4-.9-4.9-2.2C.7 22.4 0 20.6 0 18.5v-.3c.1.1.1.1 0 0 .1 0 .1 0 0 0zm2.2-.4v.4c0 1.7.5 3.1 1.6 4.2 1.1 1.2 2.6 1.7 4.7 1.7 1.5 0 2.6-.5 3.7-1.6.9-1.1 1.6-2.3 1.7-3.6v-1.4c-.2-1.5-.7-2.6-1.8-3.6-.9-.9-2.2-1.4-3.9-1.5h-.3c-1.3 0-2.4.4-3.4 1.2-.9.7-1.6 1.7-2 2.6-.1.3-.2.5-.2.7 0 .4-.1.7-.1.9 0-.1 0-.1 0 0zM19.8 5.5h1.9V13c.6-.8 1.5-1.5 2.6-2s2.2-.8 3.4-.8c.3 0 .7 0 1.1.1.3 0 .7.1 1.1.2.6.2 1.3.4 1.8.7.6.3 1.2.7 1.7 1.4.6.6 1.2 1.4 1.5 2.3.3.9.5 1.9.6 2.9v.8c0 1.3-.3 2.4-.9 3.6-.6 1.2-1.5 2-2.6 2.6-.4.2-.8.4-1.3.5-.4.1-.9.2-1.4.3-.2 0-.4.1-.6.1h-1.3c-1.1-.1-2.1-.3-3.2-.7-1.1-.4-1.9-1.1-2.5-1.8v2.5h-1.9V5.5c-.1 0 0 0 0 0zm3.1 16.4c.8 1.3 2.3 2 4.5 2h.4c1.6-.1 2.9-.7 4-1.8s1.6-2.5 1.6-4.4c0-1.5-.6-2.8-1.9-4s-2.6-1.8-4.1-1.8c-.3 0-.7.1-1.1.2-.4.1-.8.3-1.3.5-.8.4-1.7 1.2-2.3 2-.7.8-1.1 1.9-1.1 3.1.1 1.4.5 2.9 1.3 4.2zm17.5-9.5c1.4-1.3 2.8-1.9 4.4-2.1h1.1c1.2 0 2.3.3 3.4.9 1.1.5 1.8 1.3 2.3 2.2v-2.7h2.1v12.9c0 2.5-.7 4.5-2.3 5.8-1.6 1.3-3.3 1.9-5.2 1.9h-.4c-1.5-.1-2.9-.6-4.3-1.6-1.4-.9-2.3-2.3-2.8-4.1h1.9c.4 1.2 1.2 2 2.1 2.5.9.5 1.9.9 2.9.9h.6c1.4-.1 2.6-.5 3.8-1.6 1.2-.9 1.7-2.3 1.7-4.1v-.8c-.3.8-1.1 1.6-2.2 2.1-1.3.5-2.5.8-3.9.8h-1.1c-1.6-.2-3.1-.8-4.4-2-1.4-1.2-2-2.9-2-5.4v-.4c.2-2 .9-3.9 2.3-5.2zm0 5.2v.4c0 1.7.4 3.1 1.4 4.2s2.3 1.7 4 1.7c1.5 0 2.8-.4 4-1.4s1.8-2.5 1.8-4.8c0-1.4-.5-2.5-1.6-3.5-1.1-1.1-2.2-1.6-3.5-1.8h-.7c-1.2.1-2.1.4-2.8.9-.7.5-1.3 1.1-1.7 1.7-.3.5-.6.9-.7 1.5-.1.4-.2.8-.2 1.1 0-.1 0-.1 0 0zm18.4-5.2c1.6-1.3 3.2-1.9 5.1-2h.4c1.9 0 3.6.7 5.2 2s2.3 3.2 2.3 5.7v.6H58.5c.2 1.8.8 3.1 1.9 3.8 1.1.8 2.1 1.3 3.3 1.4h.8c1.2-.1 2.2-.4 3.2-.9.9-.6 1.7-1.4 1.9-2.2h2.1c-.6 1.7-1.6 3.1-2.8 3.8-1.3.8-2.6 1.3-4 1.3h-.5c-1.9 0-3.7-.7-5.4-2.1-1.6-1.4-2.4-3.3-2.5-5.6 0-2.6.8-4.5 2.3-5.8zm9.1 1.3c-.9-.9-2.1-1.5-3.6-1.6-1.3.1-2.3.4-3.1.9-.7.5-1.4 1.1-1.8 1.6-.3.5-.6.9-.7 1.4-.1.4-.2.7-.3.9h11.4c-.4-1.2-1.1-2.3-1.9-3.2zm8.4-1.2c1.5-1.5 3.5-2.2 5.9-2.2 2.1 0 3.9.6 5.4 2s2.1 3.1 2.1 5.1c0 2.6-.7 4.6-2.2 6.1-1.5 1.5-3.3 2.2-5.6 2.2-2.1 0-4-.6-5.5-2s-2.3-3.3-2.4-5.9c.1-2 .8-3.7 2.3-5.3zm1.5 9.5c.9 1.1 2 1.7 3.2 1.8h1.2c1.4-.1 2.6-.7 3.8-1.7 1.2-1.1 1.7-2.6 1.7-4.7 0-1.5-.5-2.6-1.7-3.6-1.2-.9-2.4-1.4-3.9-1.5h-.4c-1.5 0-2.7.5-3.8 1.6-.9 1.1-1.6 2.3-1.6 4 0 1.7.5 3.1 1.5 4.1zm14.7-11.5h1.9v2c.4-.7 1.1-1.4 1.7-1.7.7-.3 1.6-.5 2.6-.5v2.2c-.2 0-.4 0-.6.1-.2 0-.4.1-.6.2-.7.2-1.5.6-2.1 1.3-.6.6-.9 1.4-.9 2.3v9.3h-1.9c-.1 0-.1-15.2-.1-15.2zm10.6 1.7c1.5-1.2 3.1-1.8 4.8-1.9h1.4c.9.1 1.9.4 2.7.8.9.4 1.7 1.1 2.2 1.9V5.5h1.7v20.1h-1.7v-2.7c-.6.8-1.4 1.6-2.2 2-.8.4-1.8.7-2.7.8h-1.1c-1.9 0-3.7-.7-5.3-2.1-1.6-1.4-2.4-3.3-2.4-5.7v-.5c.3-2.3 1.1-4 2.6-5.2zm-.6 5.2v.5c0 1.6.4 2.9 1.4 4.2s2.4 2 4.5 2h.5c.2 0 .3 0 .5-.1 1.2-.3 2.2-.9 3.3-2 .9-1.1 1.5-2.4 1.5-4v-.3c0-.3 0-.6-.1-1.1s-.3-.8-.5-1.3c-.4-.7-.9-1.5-1.8-2-.8-.6-1.9-.9-3.4-.9-.3 0-.7 0-1.1.1-.4.1-.8.2-1.3.4-.8.3-1.6.8-2.3 1.6-.7.7-1.1 1.7-1.2 2.7v.2zm17.4-6.9h1.9v2c.4-.6 1.1-1.1 1.9-1.5.7-.3 1.6-.6 2.4-.7h.8c1.5 0 2.8.5 4.1 1.5 1.3.9 1.9 2.5 1.9 4.5v9.3h-2v-9.3c0-1.4-.4-2.4-1.4-3.2-.8-.7-1.9-1.1-2.9-1.2h-.6c-1.2 0-2.1.4-3.1 1.2-.9.7-1.4 1.7-1.4 3.1v9.4h-1.9v-15l.3-.1zm18.4 1.9c1.6-1.3 3.2-1.9 5.1-2h.4c1.9 0 3.6.7 5.2 2s2.3 3.2 2.3 5.7v.6h-13.4c.2 1.8.8 3.1 1.9 3.8 1.1.8 2.1 1.3 3.3 1.4h.8c1.2-.1 2.2-.4 3.2-.9.9-.6 1.7-1.4 1.9-2.2h2.1c-.6 1.7-1.6 3.1-2.8 3.8-1.3.8-2.6 1.3-4 1.3h-.5c-1.9 0-3.7-.7-5.4-2.1-1.6-1.4-2.4-3.3-2.5-5.6-.1-2.6.8-4.5 2.4-5.8zm8.9 1.3c-.9-.9-2.1-1.5-3.6-1.6-1.3.1-2.3.4-3.1.9-.7.5-1.4 1.1-1.8 1.6-.3.5-.6.9-.7 1.4-.1.4-.2.7-.3.9h11.4c-.3-1.2-.9-2.3-1.9-3.2zm5.8-1v-2h2.9v-5h1.9v5.1h3.5v2h-3.5v12.8h-1.9V12.7H153zm12.5-.3c1.6-1.3 3.2-1.9 5.1-2h.4c1.9 0 3.6.7 5.2 2s2.3 3.2 2.3 5.7v.6h-13.3c.2 1.8.8 3.1 1.9 3.8 1.1.8 2.1 1.3 3.3 1.4h.8c1.2-.1 2.2-.4 3.2-.9.9-.6 1.7-1.4 1.9-2.2h2.1c-.6 1.7-1.6 3.1-2.8 3.8-1.3.8-2.6 1.3-4 1.3h-.6c-1.9 0-3.7-.7-5.4-2.1-1.6-1.4-2.4-3.3-2.5-5.6.1-2.6.9-4.5 2.4-5.8zm9.1 1.3c-.9-.9-2.1-1.5-3.6-1.6-1.3.1-2.3.4-3.1.9-.7.5-1.4 1.1-1.8 1.6-.3.5-.6.9-.7 1.4-.1.4-.2.7-.3.9h11.4c-.4-1.2-1-2.3-1.9-3.2zm6.8-3.2h1.9v2c.4-.6 1.1-1.1 1.9-1.5.7-.3 1.6-.6 2.4-.7h.8c1.5 0 2.8.5 4.1 1.5 1.3.9 1.9 2.5 1.9 4.5v9.3h-1.9v-9.3c0-1.4-.4-2.4-1.4-3.2-.8-.7-1.9-1.1-2.9-1.2h-.6c-1.2 0-2.1.4-3.1 1.2-.9.7-1.4 1.7-1.4 3.1v9.4h-1.9v-15c.1-.1.2-.1.2-.1z"/><path fill="#575756" d="M204.7 25.6h-2.4l-5.7-14.8h2.1l4.7 12.2 3.4-10.4h1.7L212 23l4.6-12.2h2.2l-5.6 14.8h-2.3l-3.3-9.3-2.9 9.3zm16.2-7.4v-.1c0-2.3.8-4.1 2.4-5.5s3.4-2.1 5.3-2.2h.8c1.1 0 2.1.3 3.2.7s1.8 1.2 2.4 2.1v-2.6h1.7v15H235v-2.5c-.5.9-1.4 1.6-2.3 2.1-1.1.4-2 .7-3.2.8H228c-1.8-.2-3.4-.9-4.9-2.2-1.5-1.3-2.2-2.9-2.2-5.1v-.3c.1-.1.1-.1 0-.2.1 0 .1 0 0 0zm2.2-.4v.4c0 1.7.5 3.1 1.6 4.2 1.1 1.2 2.6 1.7 4.7 1.7 1.5 0 2.6-.5 3.7-1.6.9-1.1 1.6-2.3 1.7-3.6v-1.4c-.2-1.5-.7-2.6-1.8-3.6-.9-.9-2.2-1.4-3.9-1.5h-.3c-1.3 0-2.4.4-3.4 1.2-.9.7-1.6 1.7-2 2.6-.1.3-.2.5-.2.7 0 .4-.1.7-.1.9 0-.1 0-.1 0 0zm16.2-5.1v-2h2.9v-5h1.9v5.1h3.5v2h-3.5v12.8h-1.9V12.7h-2.9zm12.8-.5c1.6-1.4 3.4-2.1 5.4-2.1h1.1c1.3.2 2.4.6 3.6 1.4 1.2.7 2.1 1.9 2.8 3.4h-2.3c-.4-.9-1.2-1.6-2-2.1-.9-.4-1.9-.6-2.9-.6h-.4c-.9.1-2 .3-2.8.8-.9.4-1.6 1.1-1.9 1.9l-.3.6c-.1.2-.1.4-.2.6-.1.3-.2.6-.2.9-.1.3-.1.6-.1.9 0 .7.1 1.5.4 2.1.3.6.6 1.3 1.1 1.7.2.2.5.4.7.6.2.2.5.4.7.5.5.3 1.1.5 1.6.6.5.1 1.1.2 1.5.2 1.1 0 2.1-.3 2.9-.8.9-.5 1.6-1.2 2-1.9 0 0 0-.1.1-.1l.1-.1h2.3c-.8 1.4-1.7 2.3-2.7 3.1-1.1.7-2.1 1.3-3.2 1.5-.3.1-.5.1-.8.1h-.8c-2 0-3.9-.7-5.5-2.2-1.6-1.5-2.4-3.3-2.4-5.6-.2-2 .6-3.9 2.2-5.4zm15.8-6.7h1.9v7.1c.6-.7 1.3-1.3 2-1.6.7-.3 1.5-.5 2.2-.6h.4c1.7 0 3.2.6 4.5 1.9 1.4 1.3 2 2.6 2 4.2v9.3h-2.1v-9.3c-.2-1.3-.7-2.3-1.6-2.9s-1.7-1.1-2.6-1.2h-.4c-1.1 0-2.1.4-3.1 1.2-.9.7-1.4 1.8-1.4 3.3v9h-1.9c.1-.1.1-20.4.1-20.4zM285.4 22h2.1v3.6h-2.1V22zm8.9-9.8c1.5-1.2 3.1-1.8 4.8-1.9h1.4c.9.1 1.9.4 2.7.8.9.4 1.7 1.1 2.2 1.9V5.5h1.7v20.1h-1.7v-2.7c-.6.8-1.4 1.6-2.2 2-.8.4-1.8.7-2.7.8h-1.1c-1.9 0-3.7-.7-5.3-2.1-1.6-1.4-2.4-3.3-2.4-5.7v-.5c.2-2.3 1.1-4 2.6-5.2zm-.7 5.2v.5c0 1.6.4 2.9 1.4 4.2s2.4 2 4.5 2h.5c.2 0 .3 0 .5-.1 1.2-.3 2.2-.9 3.3-2 .9-1.1 1.5-2.4 1.5-4v-.3c0-.3 0-.6-.1-1.1s-.3-.8-.5-1.3c-.4-.7-.9-1.5-1.8-2-.8-.6-1.9-.9-3.4-.9-.3 0-.7 0-1.1.1-.4.1-.8.2-1.3.4-.8.3-1.6.8-2.3 1.6-.7.8-1 1.7-1.2 2.9 0-.1 0-.1 0 0zm19.2-5c1.6-1.3 3.3-1.9 5.1-2h.4c1.9 0 3.6.7 5.2 2s2.3 3.2 2.3 5.7v.6h-13.3c.2 1.8.8 3.1 1.9 3.8 1.1.8 2.1 1.3 3.3 1.4h.8c1.2-.1 2.2-.4 3.2-.9.9-.6 1.7-1.4 1.9-2.2h2.1c-.6 1.7-1.6 3.1-2.8 3.8-1.3.8-2.6 1.3-4 1.3h-.5c-1.9 0-3.7-.7-5.4-2.1-1.6-1.4-2.4-3.3-2.5-5.6-.1-2.6.8-4.5 2.3-5.8zm9.1 1.3c-.9-.9-2.1-1.5-3.6-1.6-1.3.1-2.3.4-3.1.9-.7.5-1.4 1.1-1.8 1.6-.3.5-.6.9-.7 1.4-.1.4-.2.7-.3.9h11.4c-.4-1.2-1.1-2.3-1.9-3.2zM110.6 45.5l-1.4-4.4c-.1-.3-.2-.8-.5-1.8h-.1c-.2.8-.3 1.4-.5 1.8l-1.4 4.3h-1.3l-2-7.5h1.2c.5 1.9.8 3.3 1.1 4.3.2.9.4 1.7.4 2h.1c0-.2.1-.6.2-1.1.1-.4.2-.7.3-.9l1.4-4.3h1.3l1.4 4.3c.2.7.4 1.5.5 2h.1c0-.2.1-.4.1-.7.1-.3.5-2.2 1.4-5.5h1.2l-2.1 7.5h-1.4zm7.9.1c-1.1 0-2-.3-2.6-1.1-.6-.6-.9-1.6-.9-2.8 0-1.2.3-2.1.8-2.8.6-.7 1.4-1.1 2.4-1.1.9 0 1.7.3 2.2.9.5.6.8 1.5.8 2.4v.7H116c0 .8.2 1.6.6 2 .4.4 1.1.6 1.8.6.8 0 1.6-.2 2.4-.5V45c-.4.2-.7.3-1.2.4-.2.2-.6.2-1.1.2zm-.3-6.8c-.6 0-1.1.2-1.5.6-.3.4-.5.9-.6 1.6h3.9c0-.7-.2-1.3-.5-1.7-.4-.4-.7-.5-1.3-.5zm4.9-2.8c0-.2.1-.4.2-.5.1-.1.3-.2.5-.2s.3.1.4.2c.1.1.2.3.2.5s-.1.4-.2.5c-.1.1-.3.2-.4.2-.2 0-.3-.1-.5-.2s-.2-.2-.2-.5zm1.2 9.5h-1.2V38h1.2v7.5zm3.5 0h-1.2V34.9h1.2v10.6zm8.5-.8h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.5 0-2.2-.7-2.2-2.3v-4.4h-1.1v-.5l1.1-.4.5-1.6h.6v1.7h2.2v.8H135v4.4c0 .4.1.8.3 1.1.2.2.5.3 1 .3zm5.9-6.8c.3 0 .6 0 .8.1l-.1 1.1c-.3-.1-.6-.1-.8-.1-.6 0-1.2.2-1.6.7-.4.5-.6 1.1-.6 1.8v4h-1.2V38h.9l.1 1.4h.1c.3-.5.6-.8.9-1.2.4-.3 1-.3 1.5-.3zm6.8 7.6l-.2-1.1h-.1c-.4.4-.7.7-1.2.9-.4.2-.8.2-1.4.2-.7 0-1.4-.2-1.8-.5-.4-.4-.6-.9-.6-1.6 0-1.5 1.2-2.3 3.6-2.3h1.3v-.4c0-.6-.1-1.1-.4-1.3s-.7-.4-1.2-.4c-.6 0-1.4.2-2.1.5l-.3-.8c.3-.2.7-.3 1.2-.4.4-.1.8-.2 1.4-.2.8 0 1.6.2 2 .6.4.4.6 1.1.6 1.9v4.8h-.8v.1zm-2.5-.8c.7 0 1.3-.2 1.7-.5.4-.4.6-.9.6-1.6V42h-1.2c-.9 0-1.6.2-1.9.4-.3.2-.6.6-.6 1.2 0 .4.1.7.4.9s.6.2 1 .2zm10.8.8v-4.8c0-.6-.1-1.1-.4-1.4-.3-.3-.7-.4-1.3-.4-.7 0-1.4.2-1.7.6-.3.4-.5 1.2-.5 2.1v3.9h-1.2V38h.9l.2 1.1h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.4-.3.9 0 1.6.2 2 .6.4.4.6 1.2.6 2.1v4.8h-1zm8.2-2c0 .7-.2 1.3-.7 1.6-.5.4-1.3.5-2.2.5s-1.8-.1-2.3-.4v-1.1c.3.2.7.3 1.2.4.4.1.8.1 1.2.1.6 0 1.1-.1 1.4-.3.3-.2.5-.5.5-.8s-.1-.5-.4-.7c-.2-.2-.7-.4-1.5-.7-.7-.2-1.2-.5-1.5-.6-.3-.1-.5-.4-.6-.6-.1-.2-.2-.5-.2-.8 0-.6.2-1.1.7-1.5.5-.3 1.2-.5 2-.5s1.6.2 2.3.5l-.4.9c-.7-.3-1.5-.4-2-.4s-.9.1-1.3.2c-.3.2-.4.4-.4.7 0 .2 0 .4.1.5.1.1.3.3.5.4.2.1.6.3 1.3.5.8.3 1.5.6 1.8.9.4.2.5.6.5 1.2zm5.4 2.1c-.5 0-.9-.1-1.4-.3-.4-.2-.7-.4-1.1-.8h-.1c.1.4.1.8.1 1.3v3.1h-1.2V38h.9l.1 1.1h.1c.3-.4.6-.7 1.1-.8.4-.1.8-.3 1.4-.3.9 0 1.8.3 2.3 1.1.5.6.8 1.6.8 2.8 0 1.3-.3 2.2-.8 2.8-.5.5-1.3.9-2.2.9zm-.2-6.8c-.7 0-1.3.2-1.7.6-.4.4-.5 1.1-.5 2v.2c0 1.1.2 1.8.5 2.2.3.4.9.6 1.7.6.6 0 1.2-.2 1.5-.7.3-.5.5-1.3.5-2.1 0-.9-.2-1.7-.5-2.1-.4-.5-.9-.7-1.5-.7zm9.8 6.7l-.2-1.1h-.1c-.4.4-.7.7-1.2.9-.4.2-.8.2-1.4.2-.7 0-1.4-.2-1.8-.5-.4-.4-.6-.9-.6-1.6 0-1.5 1.2-2.3 3.6-2.3h1.3v-.4c0-.6-.1-1.1-.4-1.3-.3-.2-.6-.4-1.2-.4s-1.4.2-2.1.5l-.3-.8c.3-.2.7-.3 1.2-.4.4-.1.8-.2 1.4-.2.8 0 1.6.2 2 .6.4.4.6 1.1.6 1.9v4.8l-.8.1zm-2.6-.8c.7 0 1.3-.2 1.7-.5.4-.4.6-.9.6-1.6V42H179c-.9 0-1.6.2-1.9.4-.3.2-.6.6-.6 1.2 0 .4.1.7.4.9.4.2.6.2 1 .2zm9.2-6.8c.3 0 .6 0 .8.1l-.1 1.1c-.3-.1-.6-.1-.8-.1-.6 0-1.2.2-1.6.7s-.6 1.1-.6 1.8v4h-1.2V38h.9l.1 1.4h.1c.3-.5.6-.8.9-1.2.4-.3 1-.3 1.5-.3zm5.4 7.7c-1.1 0-2-.3-2.6-1.1-.6-.7-.9-1.6-.9-2.8 0-1.2.3-2.1.8-2.8.6-.7 1.4-1.1 2.4-1.1.9 0 1.7.3 2.2.9.5.6.8 1.5.8 2.4v.7H190c0 .8.2 1.6.6 2 .4.4 1.1.6 1.8.6.8 0 1.6-.2 2.4-.5V45c-.4.2-.7.3-1.2.4-.2.2-.6.2-1.1.2zm-.4-6.8c-.6 0-1.1.2-1.5.6-.3.4-.5.9-.6 1.6h3.9c0-.7-.2-1.3-.5-1.7-.2-.3-.6-.5-1.3-.5zm10.1 6.7v-4.8c0-.6-.1-1.1-.4-1.4-.3-.3-.7-.4-1.3-.4-.7 0-1.4.2-1.7.6s-.5 1.2-.5 2.1v3.9h-1.2V38h.9l.2 1.1h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.4-.3.9 0 1.6.2 2 .6.4.4.6 1.2.6 2.1v4.8h-1zm8.2 0H205v-.7l4.1-5.8h-3.8v-.8h5.1v.8l-4 5.7h4.1v.8h-.1zm7.1 0l-2.8-7.5h1.3l1.6 4.4c.3 1.1.5 1.7.6 2h.1c0-.2.2-.7.4-1.5.3-.7.8-2.4 1.8-4.9h1.3l-2.8 7.5h-1.5zm8.4.1c-1.1 0-2-.3-2.6-1.1-.6-.7-.9-1.6-.9-2.8 0-1.2.3-2.1.8-2.8s1.4-1.1 2.4-1.1c.9 0 1.7.3 2.2.9s.8 1.5.8 2.4v.7h-5.2c0 .8.2 1.6.6 2 .4.4 1.1.6 1.8.6.8 0 1.6-.2 2.4-.5V45c-.4.2-.7.3-1.2.4-.1.2-.6.2-1.1.2zm-.3-6.8c-.6 0-1.1.2-1.5.6-.3.4-.5.9-.6 1.6h3.9c0-.7-.2-1.3-.5-1.7-.2-.3-.7-.5-1.3-.5zm8.4-.9c.3 0 .6 0 .8.1l-.1 1.1c-.3-.1-.6-.1-.8-.1-.6 0-1.2.2-1.6.7-.4.5-.6 1.1-.6 1.8v4h-1.2V38h.9l.1 1.4h.1c.3-.5.6-.8.9-1.2.5-.3 1-.3 1.5-.3zm4.6 6.8h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.5 0-2.2-.7-2.2-2.3v-4.4h-1.1v-.5l1.1-.4.5-1.6h.6v1.7h2.2v.8h-2.2v4.4c0 .4.1.8.3 1.1.4.1.7.3 1 .3zm6-6.8c.3 0 .6 0 .8.1l-.1 1.1c-.3-.1-.6-.1-.8-.1-.6 0-1.2.2-1.6.7-.4.5-.6 1.1-.6 1.8v4h-1.2V38h.9l.1 1.4h.1c.3-.5.6-.8.9-1.2.5-.3 1-.3 1.5-.3zm6.9 7.6l-.2-1.1h-.1c-.4.4-.7.7-1.2.9s-.8.2-1.4.2c-.7 0-1.4-.2-1.8-.5-.4-.4-.6-.9-.6-1.6 0-1.5 1.2-2.3 3.6-2.3h1.3v-.4c0-.6-.1-1.1-.4-1.3-.2-.3-.6-.4-1.2-.4s-1.4.2-2.1.5l-.3-.8c.3-.2.7-.3 1.2-.4.4-.1.8-.2 1.4-.2.8 0 1.6.2 2 .6.4.4.6 1.1.6 1.9v4.8h-.8v.1zm-2.5-.8c.7 0 1.3-.2 1.7-.5.4-.4.6-.9.6-1.6V42h-1.2c-.9 0-1.6.2-1.9.4-.3.2-.6.6-.6 1.2 0 .4.1.7.4.9.1.1.4.2 1 .2zm6.7-6.7v4.8c0 .6.1 1.1.4 1.4.3.3.7.4 1.3.4.7 0 1.4-.2 1.7-.6.3-.4.5-1.2.5-2.1V38h1.2v7.5h-.8l-.2-.9h-.1c-.2.3-.5.6-.9.8-.4.2-.8.3-1.4.3-.9 0-1.6-.2-2-.6s-.6-1.2-.6-2.1v-4.8h1.1V38zm10.6 7.6c-1.1 0-2-.3-2.6-1.1-.6-.6-.9-1.6-.9-2.8 0-1.2.3-2.1.8-2.8.5-.7 1.4-1.1 2.4-1.1.9 0 1.7.3 2.2.9.5.6.8 1.5.8 2.4v.7h-5.2c0 .8.2 1.6.6 2 .4.4 1.1.6 1.8.6.8 0 1.6-.2 2.4-.5V45c-.4.2-.7.3-1.2.4-.1.2-.6.2-1.1.2zm-.3-6.8c-.6 0-1.1.2-1.5.6-.3.4-.5.9-.6 1.6h3.9c0-.7-.2-1.3-.5-1.7-.2-.3-.7-.5-1.3-.5zm10.1 6.7v-4.8c0-.6-.1-1.1-.4-1.4s-.7-.4-1.3-.4c-.7 0-1.4.2-1.7.6-.3.4-.5 1.2-.5 2.1v3.9H271V38h.9l.2 1.1h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.4-.3.9 0 1.6.2 2 .6.4.4.6 1.2.6 2.1v4.8h-1zm11.9-2c0 .7-.2 1.3-.7 1.6-.5.4-1.3.5-2.2.5s-1.8-.1-2.3-.4v-1.1c.3.2.7.3 1.2.4.4.1.8.1 1.2.1.6 0 1.1-.1 1.4-.3.3-.2.5-.5.5-.8s-.1-.5-.4-.7c-.2-.2-.7-.4-1.5-.7-.7-.2-1.2-.5-1.5-.6-.3-.1-.5-.4-.6-.6s-.2-.5-.2-.8c0-.6.2-1.1.7-1.5.5-.4 1.2-.5 2-.5s1.6.2 2.3.5l-.4.9c-.7-.3-1.5-.4-2-.4s-.9.1-1.3.2c-.3.2-.4.4-.4.7 0 .2 0 .4.1.5.1.1.3.3.5.4.2.1.6.3 1.3.5.8.3 1.5.6 1.8.9.3.2.5.6.5 1.2zm4.7 2.1c-1.1 0-1.9-.3-2.5-.9s-.8-1.6-.8-2.8c0-1.3.3-2.2.9-2.8s1.5-1.1 2.5-1.1c.3 0 .7 0 1.1.1.3.1.6.2.8.3l-.3.9c-.2-.1-.5-.2-.8-.2-.3-.1-.5-.1-.7-.1-1.5 0-2.3.9-2.3 2.9 0 .9.2 1.6.5 2.1.4.5.9.7 1.7.7.6 0 1.3-.1 1.9-.4v.9c-.5.3-1.1.4-2 .4zm8.9-.1v-4.8c0-.6-.1-1.1-.4-1.4-.3-.3-.7-.4-1.3-.4-.7 0-1.4.2-1.7.6-.3.4-.5 1.2-.5 2.1v3.9h-1.2V34.9h1.2v3.2c0 .4 0 .7-.1.9h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.4-.3.9 0 1.6.2 2 .6.4.4.6 1.2.6 2.1v4.8l-1 .1zm8 0l-.2-1.1h-.1c-.4.4-.7.7-1.2.9-.4.2-.8.2-1.4.2-.7 0-1.4-.2-1.8-.5-.4-.4-.6-.9-.6-1.6 0-1.5 1.2-2.3 3.6-2.3h1.3v-.4c0-.6-.1-1.1-.4-1.3-.2-.3-.6-.4-1.2-.4s-1.4.2-2.1.5l-.3-.8c.3-.2.7-.3 1.2-.4.4-.1.8-.2 1.4-.2.8 0 1.6.2 2 .6.4.4.6 1.1.6 1.9v4.8l-.8.1zm-2.6-.8c.7 0 1.3-.2 1.7-.5.4-.4.6-.9.6-1.6V42h-1.2c-.9 0-1.6.2-1.9.4-.4.2-.6.6-.6 1.2 0 .4.1.7.4.9.2.1.5.2 1 .2zm9.1-5.8h-1.9v6.5H313v-6.5h-1.4v-.5l1.4-.4v-.4c0-1.8.8-2.7 2.4-2.7.4 0 .8.1 1.4.2l-.3.9c-.4-.1-.8-.2-1.2-.2-.4 0-.7.1-.9.4-.2.3-.3.7-.3 1.4v.5h1.9v.8h.1zm4.7 0h-1.9v6.5h-1.2v-6.5h-1.4v-.5l1.4-.4v-.4c0-1.8.8-2.7 2.4-2.7.4 0 .8.1 1.4.2l-.3.9c-.4-.1-.8-.2-1.2-.2-.4 0-.7.1-.9.4-.2.3-.3.7-.3 1.4v.5h1.9v.8h.1zm3.8 5.8h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.5 0-2.2-.7-2.2-2.3v-4.4h-1.1v-.5l1.1-.4.5-1.6h.6v1.7h2.2v.8h-2.2v4.4c0 .4.1.8.3 1.1.3.2.6.3 1 .3z"/><path fill="#EC663B" d="M383.4 53h-37.3c-4.3 0-7.8-3.5-7.8-7.8V8c0-4.3 3.5-7.8 7.8-7.8h37.3c4.3 0 7.8 3.5 7.8 7.8v37.3c0 4.3-3.5 7.7-7.8 7.7zM346.1 3c-2.8 0-5 2.2-5 5v37.2c0 2.8 2.2 5 5 5h37.3c2.8 0 5-2.2 5-5V8c0-2.8-2.2-5-5-5h-37.3zm29.8 13c2.6 2.7 4.1 6.2 4.4 9.8h5c-.3-5-2.3-9.6-5.7-13.2s-7.9-5.8-12.8-6.3l-.3 4.9c3.5.4 6.9 2.1 9.4 4.8zm-11.5-9.9c-5.4 0-10.5 2-14.4 5.8l3.4 3.6c2.9-2.8 6.7-4.4 10.8-4.4l.2-5c.1 0 .1 0 0 0zm11 32.3l3.4 3.6c1.8-1.7 3.3-3.8 4.4-6l-4.8-1.5c-.7 1.4-1.7 2.8-3 3.9zm9.9-10.5h-5c-.1 1.6-.4 3.1-1 4.5l4.7 1.5c.8-1.8 1.2-3.9 1.3-6zm-13.6-5.3c.6 1 1 2.1 1.2 3.3h5c-.2-2.5-1.1-4.8-2.6-6.8l-3.6 3.5zm-1.4 10.6l3.4 3.6c2.4-2.3 3.9-5.4 4.1-8.7h-5c-.2 1.9-1.1 3.7-2.5 5.1zm-15.2-15.9l3.4 3.6c1.5-1.4 3.3-2.2 5.4-2.3l.3-5c-3.5 0-6.7 1.3-9.1 3.7zm18.7.1c-2.1-2-4.7-3.3-7.5-3.7l-.3 5c1.6.3 3.1 1.1 4.3 2.2l3.5-3.5zm-9.4 9.4l-.1.1h.1v-.1z"/></svg>
      </div>
    </a>
    <?php endif; ?>
    <?php if ($page['footer']): ?>
    <div class="container">
      <?php print render($page['footer']); ?>
    </div>
    <?php endif; ?>
  </footer>
</div>
<?php print $page_bottom; ?>
</body>
</html>