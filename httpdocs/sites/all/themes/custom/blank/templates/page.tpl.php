<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header_top']: Items for the header-top region.
 * - $page['header_bottom']: Items for the header-bottom region.
 * - $page['intro_primary']: Items for the intro-primary region.
 * - $page['intro_secondary']: Items for the intro-secondary region.
 * - $page['content']: The main content of the current page.
 * - $page['content_tabs']: Items for the content-tabs region.
 * - $page['content_extra']: Items for the content-extra region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>
<div class="page-container" data-sidebar-container>
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
    <?php print render($page['content']); ?>
    <?php print render($page['content_tabs']); ?>
    <?php print render($page['content_extra']); ?>
  </main>

  <footer id="footer">
    <div class="footer__presented">
      <?php print t('Presented by'); ?>
    </div>
    <?php if ($logo): ?>
      <a class="footer__logo" href="https://www.abgeordnetenwatch.de/" title="<?php print t('Abgeordnetenwatch'); ?>" rel="home" target="_blank">
        <div class="svg-container">
          <svg x="0px" y="0px" viewBox="0 0 476.2 61.2">
            <path fill="#1D1D1B" d="M256.8,16.9l-4,13.3h-2L244,10.5h3.8l4,12.9l4-12.9h2.2l3.9,12.9l4-12.9h3.7l-6.8,19.6h-2L256.8,16.9z M291.3,30.1V10.5h-3.6v2.4c-0.9-1-2-1.7-3.1-2.2c-1.1-0.5-2.4-0.7-3.7-0.7c-1.5,0-2.8,0.2-4,0.7c-1.2,0.5-2.2,1.3-3.2,2.3 c-0.9,0.9-1.6,2-2.1,3.3c-0.5,1.2-0.7,2.5-0.7,3.9c0,3,1,5.4,2.9,7.4c1.9,2,4.4,2.9,7.3,2.9c1.3,0,2.4-0.2,3.6-0.7 c1.1-0.5,2.1-1.2,3-2.1v2.4H291.3z M274.5,20.2c0-1.9,0.7-3.5,2-4.8c1.3-1.3,2.9-2,4.7-2c1.8,0,3.4,0.7,4.7,2.1c1.3,1.4,2,3,2,4.9 c0,1.8-0.7,3.4-2,4.7c-1.3,1.3-2.9,2-4.6,2c-1.9,0-3.5-0.7-4.8-2C275.2,23.9,274.5,22.2,274.5,20.2 M300.1,30.1V13.7h2.8v-3.2h-2.8 V4.2h-3.5v6.3h-2.8v3.2h2.8v16.4H300.1z M320.1,23.4c-0.6,1.2-1.3,2.1-2.3,2.8c-1,0.6-2.1,1-3.3,1c-1.8,0-3.4-0.7-4.6-2 c-1.2-1.3-1.9-2.9-1.9-4.9c0-1.9,0.6-3.6,1.8-4.9c1.2-1.3,2.7-2,4.4-2c1.4,0,2.5,0.3,3.5,0.9c1,0.6,1.8,1.5,2.4,2.7h3.9 c-0.7-2.2-1.9-4-3.6-5.2c-1.7-1.2-3.6-1.9-5.8-1.9c-1.4,0-2.8,0.3-4,0.8c-1.3,0.6-2.4,1.4-3.4,2.5c-0.9,1-1.6,2.1-2.1,3.3 c-0.5,1.2-0.7,2.5-0.7,3.8c0,1.3,0.3,2.6,0.8,3.9c0.5,1.3,1.2,2.4,2.1,3.4c1,1,2,1.8,3.2,2.3c1.2,0.5,2.5,0.8,4,0.8 c2.3,0,4.3-0.6,5.9-1.8c1.6-1.2,2.8-3,3.6-5.4H320.1z M331,21.2c0-1.5,0.1-2.6,0.2-3.3c0.1-0.7,0.3-1.3,0.6-1.8 c0.4-0.8,1-1.4,1.7-1.9c0.7-0.4,1.5-0.6,2.5-0.6c1.5,0,2.6,0.5,3.4,1.6c0.7,1.1,1.1,2.7,1.1,4.8v10.1h3.5V18.9c0-2.7-0.7-4.9-2-6.4 c-1.3-1.5-3.2-2.3-5.5-2.3c-1.2,0-2.3,0.2-3.2,0.6c-0.9,0.4-1.6,1.1-2.2,1.9V4.2h-3.5v25.9h3.5V21.2z M353,25.7h-3.6v4.4h3.6V25.7z M377.9,30.1V4.2h-3.5v8.7c-0.9-1-2-1.7-3.1-2.2c-1.1-0.5-2.4-0.7-3.7-0.7c-1.5,0-2.8,0.2-4,0.7c-1.2,0.5-2.2,1.3-3.2,2.3 c-0.9,0.9-1.6,2-2.1,3.3c-0.5,1.2-0.7,2.5-0.7,3.9c0,3,1,5.4,2.9,7.4c1.9,2,4.4,2.9,7.3,2.9c1.3,0,2.4-0.2,3.6-0.7 c1.1-0.5,2.1-1.2,3-2.1v2.4H377.9z M361.1,20.2c0-1.9,0.7-3.5,2-4.8c1.3-1.3,2.9-2,4.7-2c1.8,0,3.4,0.7,4.7,2.1c1.3,1.4,2,3,2,4.9 c0,1.8-0.7,3.4-2,4.7c-1.3,1.3-2.9,2-4.6,2c-1.9,0-3.5-0.7-4.8-2C361.8,23.9,361.1,22.2,361.1,20.2 M401.1,21.6v-0.6 c0-1.4-0.1-2.6-0.4-3.6c-0.3-1.1-0.7-2-1.3-2.9c-1-1.4-2.2-2.6-3.7-3.4c-1.5-0.8-3.1-1.2-4.8-1.2c-1.4,0-2.8,0.3-4,0.8 c-1.2,0.5-2.3,1.3-3.3,2.4c-0.9,1-1.6,2.1-2.1,3.3c-0.5,1.2-0.7,2.5-0.7,3.9c0,1.3,0.3,2.6,0.8,3.9c0.5,1.3,1.2,2.4,2.1,3.4 c1,1,2.1,1.8,3.3,2.3c1.2,0.5,2.5,0.8,4,0.8c2.1,0,4-0.6,5.7-1.7c1.6-1.2,2.9-2.8,3.8-5h-4c-0.6,1-1.3,1.8-2.3,2.4 c-1,0.6-2,0.8-3.2,0.8c-1.6,0-3-0.5-4.2-1.5c-1.2-1-1.9-2.3-2.2-4H401.1z M384.7,18.5c0.4-1.6,1.2-2.8,2.3-3.7 c1.1-0.9,2.5-1.4,4-1.4c1.5,0,2.8,0.4,3.9,1.3c1.1,0.9,1.8,2.1,2.3,3.7H384.7z"/>
            <path fill="#1D1D1B" d="M130.8,54.6l-1.7-5.4c-0.1-0.3-0.3-1.1-0.6-2.3h-0.1c-0.2,1-0.4,1.7-0.6,2.3l-1.8,5.4h-1.6l-2.5-9.3h1.5 c0.6,2.3,1.1,4.1,1.4,5.3c0.3,1.2,0.5,2,0.5,2.5h0.1c0.1-0.3,0.2-0.7,0.3-1.2c0.1-0.5,0.3-0.9,0.4-1.2l1.7-5.3h1.5l1.7,5.3 c0.3,1,0.5,1.8,0.6,2.4h0.1c0-0.2,0.1-0.5,0.2-0.9c0.1-0.4,0.7-2.7,1.8-6.8h1.5l-2.6,9.3H130.8z M140.7,54.8c-1.4,0-2.5-0.4-3.2-1.3 c-0.8-0.8-1.2-2-1.2-3.5c0-1.5,0.4-2.7,1.1-3.6c0.7-0.9,1.7-1.3,3-1.3c1.2,0,2.1,0.4,2.8,1.1c0.7,0.8,1,1.8,1,3v0.9h-6.4 c0,1.1,0.3,1.9,0.8,2.5c0.5,0.6,1.3,0.8,2.2,0.8c1,0,2-0.2,3-0.6v1.3c-0.5,0.2-1,0.4-1.4,0.5C141.9,54.7,141.3,54.8,140.7,54.8z M140.3,46.4c-0.7,0-1.3,0.2-1.8,0.7c-0.4,0.5-0.7,1.2-0.8,2h4.8c0-0.9-0.2-1.6-0.6-2C141.6,46.6,141,46.4,140.3,46.4z M146.5,42.8 c0-0.3,0.1-0.6,0.2-0.7c0.2-0.1,0.4-0.2,0.6-0.2c0.2,0,0.4,0.1,0.6,0.2c0.2,0.2,0.2,0.4,0.2,0.7c0,0.3-0.1,0.6-0.2,0.7 c-0.2,0.2-0.4,0.2-0.6,0.2c-0.2,0-0.4-0.1-0.6-0.2C146.5,43.4,146.5,43.2,146.5,42.8z M148,54.6h-1.4v-9.3h1.4V54.6z M152.5,54.6 H151V41.5h1.4V54.6z M163.1,53.6c0.2,0,0.5,0,0.7-0.1c0.2,0,0.4-0.1,0.5-0.1v1.1c-0.2,0.1-0.4,0.1-0.7,0.2c-0.3,0-0.6,0.1-0.8,0.1 c-1.8,0-2.7-0.9-2.7-2.8v-5.5h-1.3v-0.7l1.3-0.6l0.6-2h0.8v2.1h2.7v1.1h-2.7v5.5c0,0.6,0.1,1,0.4,1.3 C162.3,53.5,162.6,53.6,163.1,53.6z M170.5,45.2c0.4,0,0.8,0,1.1,0.1l-0.2,1.3c-0.4-0.1-0.7-0.1-1-0.1c-0.8,0-1.4,0.3-1.9,0.9 c-0.5,0.6-0.8,1.4-0.8,2.3v5h-1.4v-9.3h1.2l0.2,1.7h0.1c0.3-0.6,0.8-1.1,1.2-1.4C169.4,45.3,169.9,45.2,170.5,45.2z M179.1,54.6 l-0.3-1.3h-0.1c-0.5,0.6-0.9,1-1.4,1.2c-0.5,0.2-1,0.3-1.7,0.3c-0.9,0-1.6-0.2-2.2-0.7c-0.5-0.5-0.8-1.1-0.8-2 c0-1.9,1.5-2.9,4.5-2.9l1.6-0.1v-0.6c0-0.7-0.2-1.3-0.5-1.6c-0.3-0.3-0.8-0.5-1.5-0.5c-0.8,0-1.6,0.2-2.6,0.7l-0.4-1.1 c0.5-0.2,1-0.4,1.5-0.6c0.5-0.1,1.1-0.2,1.6-0.2c1.1,0,1.9,0.2,2.5,0.7c0.5,0.5,0.8,1.3,0.8,2.4v6.3H179.1z M176,53.6 c0.9,0,1.6-0.2,2.1-0.7c0.5-0.5,0.7-1.2,0.7-2v-0.8l-1.4,0.1c-1.1,0-1.9,0.2-2.4,0.5c-0.5,0.3-0.7,0.8-0.7,1.4 c0,0.5,0.2,0.9,0.5,1.2C175,53.5,175.4,53.6,176,53.6z M189.5,54.6v-6c0-0.8-0.2-1.3-0.5-1.7c-0.3-0.4-0.9-0.6-1.6-0.6 c-1,0-1.7,0.3-2.1,0.8c-0.5,0.5-0.7,1.4-0.7,2.6v4.9h-1.4v-9.3h1.1l0.2,1.3h0.1c0.3-0.5,0.7-0.8,1.2-1.1c0.5-0.3,1.1-0.4,1.7-0.4 c1.1,0,2,0.3,2.5,0.8c0.6,0.5,0.8,1.4,0.8,2.6v6H189.5z M199.9,52.1c0,0.9-0.3,1.5-1,2c-0.6,0.5-1.5,0.7-2.7,0.7 c-1.2,0-2.2-0.2-2.9-0.6v-1.3c0.4,0.2,0.9,0.4,1.4,0.5c0.5,0.1,1,0.2,1.5,0.2c0.7,0,1.3-0.1,1.7-0.4c0.4-0.2,0.6-0.6,0.6-1.1 c0-0.4-0.2-0.7-0.5-0.9c-0.3-0.3-0.9-0.6-1.8-0.9c-0.9-0.3-1.5-0.6-1.8-0.8c-0.4-0.2-0.6-0.5-0.8-0.8c-0.2-0.3-0.3-0.7-0.3-1.1 c0-0.8,0.3-1.4,0.9-1.8c0.6-0.4,1.5-0.7,2.5-0.7c1,0,2,0.2,2.9,0.6l-0.5,1.1c-0.9-0.4-1.8-0.6-2.5-0.6c-0.7,0-1.2,0.1-1.5,0.3 c-0.3,0.2-0.5,0.5-0.5,0.9c0,0.2,0.1,0.5,0.2,0.6c0.1,0.2,0.3,0.3,0.6,0.5c0.3,0.2,0.8,0.4,1.6,0.7c1.1,0.4,1.8,0.8,2.2,1.2 C199.7,51,199.9,51.5,199.9,52.1z M206.5,54.8c-0.6,0-1.2-0.1-1.7-0.3c-0.5-0.2-0.9-0.6-1.3-1h-0.1c0.1,0.5,0.1,1.1,0.1,1.5v3.8 h-1.4V45.4h1.1l0.2,1.3h0.1c0.4-0.5,0.8-0.9,1.3-1.1c0.5-0.2,1-0.3,1.6-0.3c1.2,0,2.2,0.4,2.8,1.3c0.7,0.8,1,2,1,3.5 c0,1.5-0.3,2.7-1,3.5C208.7,54.4,207.7,54.8,206.5,54.8z M206.3,46.4c-0.9,0-1.6,0.3-2.1,0.8c-0.4,0.5-0.6,1.4-0.7,2.5V50 c0,1.3,0.2,2.2,0.7,2.8c0.4,0.6,1.1,0.8,2.1,0.8c0.8,0,1.4-0.3,1.9-1c0.5-0.6,0.7-1.5,0.7-2.7c0-1.2-0.2-2-0.7-2.7 C207.8,46.7,207.2,46.4,206.3,46.4z M218.6,54.6l-0.3-1.3h-0.1c-0.5,0.6-0.9,1-1.4,1.2c-0.5,0.2-1,0.3-1.7,0.3 c-0.9,0-1.6-0.2-2.2-0.7c-0.5-0.5-0.8-1.1-0.8-2c0-1.9,1.5-2.9,4.5-2.9l1.6-0.1v-0.6c0-0.7-0.2-1.3-0.5-1.6 c-0.3-0.3-0.8-0.5-1.5-0.5c-0.8,0-1.6,0.2-2.6,0.7l-0.4-1.1c0.5-0.2,1-0.4,1.5-0.6c0.5-0.1,1.1-0.2,1.6-0.2c1.1,0,1.9,0.2,2.5,0.7 c0.5,0.5,0.8,1.3,0.8,2.4v6.3H218.6z M215.5,53.6c0.9,0,1.6-0.2,2.1-0.7c0.5-0.5,0.7-1.2,0.7-2v-0.8l-1.4,0.1 c-1.1,0-1.9,0.2-2.4,0.5c-0.5,0.3-0.7,0.8-0.7,1.4c0,0.5,0.2,0.9,0.5,1.2C214.5,53.5,214.9,53.6,215.5,53.6z M226.9,45.2 c0.4,0,0.8,0,1.1,0.1l-0.2,1.3c-0.4-0.1-0.7-0.1-1-0.1c-0.7,0-1.4,0.3-1.9,0.9c-0.5,0.6-0.8,1.4-0.8,2.3v5h-1.4v-9.3h1.2l0.2,1.7 h0.1c0.3-0.6,0.8-1.1,1.2-1.4C225.8,45.3,226.3,45.2,226.9,45.2z M233.7,54.8c-1.4,0-2.5-0.4-3.2-1.3c-0.8-0.8-1.2-2-1.2-3.5 c0-1.5,0.4-2.7,1.1-3.6c0.7-0.9,1.7-1.3,3-1.3c1.2,0,2.1,0.4,2.8,1.1c0.7,0.8,1,1.8,1,3v0.9h-6.4c0,1.1,0.3,1.9,0.8,2.5 c0.5,0.6,1.3,0.8,2.2,0.8c1,0,2-0.2,3-0.6v1.3c-0.5,0.2-1,0.4-1.4,0.5C234.9,54.7,234.3,54.8,233.7,54.8z M233.3,46.4 c-0.7,0-1.3,0.2-1.8,0.7c-0.4,0.5-0.7,1.2-0.8,2h4.8c0-0.9-0.2-1.6-0.6-2C234.6,46.6,234.1,46.4,233.3,46.4z M245.9,54.6v-6 c0-0.8-0.2-1.3-0.5-1.7c-0.3-0.4-0.9-0.6-1.6-0.6c-1,0-1.7,0.3-2.1,0.8c-0.5,0.5-0.7,1.4-0.7,2.6v4.9h-1.4v-9.3h1.1l0.2,1.3h0.1 c0.3-0.5,0.7-0.8,1.2-1.1c0.5-0.3,1.1-0.4,1.7-0.4c1.1,0,2,0.3,2.5,0.8c0.6,0.5,0.8,1.4,0.8,2.6v6H245.9z M256.2,54.6h-6.7v-1 l5.1-7.2h-4.7v-1.1h6.3v1.1l-5,7.1h5.1V54.6z M265.1,54.6l-3.5-9.3h1.5l2,5.5c0.4,1.3,0.7,2.1,0.8,2.5h0.1c0.1-0.3,0.3-0.9,0.6-1.9 c0.3-0.9,1.1-3,2.2-6.1h1.5l-3.5,9.3H265.1z M275.8,54.8c-1.4,0-2.5-0.4-3.2-1.3c-0.8-0.8-1.2-2-1.2-3.5c0-1.5,0.4-2.7,1.1-3.6 c0.7-0.9,1.7-1.3,3-1.3c1.2,0,2.1,0.4,2.8,1.1c0.7,0.8,1,1.8,1,3v0.9h-6.4c0,1.1,0.3,1.9,0.8,2.5c0.5,0.6,1.3,0.8,2.2,0.8 c1,0,2-0.2,3-0.6v1.3c-0.5,0.2-1,0.4-1.4,0.5C276.9,54.7,276.4,54.8,275.8,54.8z M275.4,46.4c-0.7,0-1.3,0.2-1.8,0.7 c-0.4,0.5-0.7,1.2-0.8,2h4.8c0-0.9-0.2-1.6-0.6-2C276.7,46.6,276.1,46.4,275.4,46.4z M285.9,45.2c0.4,0,0.8,0,1.1,0.1l-0.2,1.3 c-0.4-0.1-0.7-0.1-1-0.1c-0.7,0-1.4,0.3-1.9,0.9c-0.5,0.6-0.8,1.4-0.8,2.3v5h-1.4v-9.3h1.2l0.2,1.7h0.1c0.3-0.6,0.8-1.1,1.2-1.4 C284.8,45.3,285.3,45.2,285.9,45.2z M291.8,53.6c0.2,0,0.5,0,0.7-0.1c0.2,0,0.4-0.1,0.5-0.1v1.1c-0.2,0.1-0.4,0.1-0.7,0.2 c-0.3,0-0.6,0.1-0.8,0.1c-1.8,0-2.7-0.9-2.7-2.8v-5.5h-1.3v-0.7l1.3-0.6l0.6-2h0.8v2.1h2.7v1.1h-2.7v5.5c0,0.6,0.1,1,0.4,1.3 C291,53.5,291.3,53.6,291.8,53.6z M299.2,45.2c0.4,0,0.8,0,1.1,0.1l-0.2,1.3c-0.4-0.1-0.7-0.1-1-0.1c-0.7,0-1.4,0.3-1.9,0.9 c-0.5,0.6-0.8,1.4-0.8,2.3v5H295v-9.3h1.2l0.2,1.7h0.1c0.3-0.6,0.8-1.1,1.2-1.4C298.1,45.3,298.6,45.2,299.2,45.2z M307.8,54.6 l-0.3-1.3h-0.1c-0.5,0.6-0.9,1-1.4,1.2c-0.5,0.2-1,0.3-1.7,0.3c-0.9,0-1.6-0.2-2.2-0.7c-0.5-0.5-0.8-1.1-0.8-2 c0-1.9,1.5-2.9,4.5-2.9l1.6-0.1v-0.6c0-0.7-0.2-1.3-0.5-1.6c-0.3-0.3-0.8-0.5-1.5-0.5c-0.8,0-1.6,0.2-2.6,0.7l-0.4-1.1 c0.5-0.2,1-0.4,1.5-0.6c0.5-0.1,1.1-0.2,1.6-0.2c1.1,0,1.9,0.2,2.5,0.7c0.5,0.5,0.8,1.3,0.8,2.4v6.3H307.8z M304.7,53.6 c0.9,0,1.6-0.2,2.1-0.7c0.5-0.5,0.7-1.2,0.7-2v-0.8l-1.4,0.1c-1.1,0-1.9,0.2-2.4,0.5c-0.5,0.3-0.7,0.8-0.7,1.4 c0,0.5,0.2,0.9,0.5,1.2C303.7,53.5,304.1,53.6,304.7,53.6z M313.2,45.4v6c0,0.8,0.2,1.3,0.5,1.7c0.3,0.4,0.9,0.6,1.6,0.6 c1,0,1.7-0.3,2.1-0.8c0.4-0.5,0.7-1.4,0.7-2.6v-4.9h1.4v9.3h-1.2l-0.2-1.2h-0.1c-0.3,0.5-0.7,0.8-1.2,1c-0.5,0.2-1.1,0.4-1.7,0.4 c-1.1,0-2-0.3-2.5-0.8c-0.6-0.5-0.8-1.4-0.8-2.6v-6.1H313.2z M326.5,54.8c-1.4,0-2.5-0.4-3.2-1.3c-0.8-0.8-1.2-2-1.2-3.5 c0-1.5,0.4-2.7,1.1-3.6c0.7-0.9,1.7-1.3,3-1.3c1.2,0,2.1,0.4,2.8,1.1c0.7,0.8,1,1.8,1,3v0.9h-6.4c0,1.1,0.3,1.9,0.8,2.5 c0.5,0.6,1.3,0.8,2.2,0.8c1,0,2-0.2,3-0.6v1.3c-0.5,0.2-1,0.4-1.4,0.5C327.7,54.7,327.1,54.8,326.5,54.8z M326.1,46.4 c-0.7,0-1.3,0.2-1.8,0.7c-0.4,0.5-0.7,1.2-0.8,2h4.8c0-0.9-0.2-1.6-0.6-2C327.4,46.6,326.8,46.4,326.1,46.4z M338.7,54.6v-6 c0-0.8-0.2-1.3-0.5-1.7c-0.3-0.4-0.9-0.6-1.6-0.6c-1,0-1.7,0.3-2.1,0.8c-0.5,0.5-0.7,1.4-0.7,2.6v4.9h-1.4v-9.3h1.1l0.2,1.3h0.1 c0.3-0.5,0.7-0.8,1.2-1.1c0.5-0.3,1.1-0.4,1.7-0.4c1.1,0,2,0.3,2.5,0.8c0.6,0.5,0.8,1.4,0.8,2.6v6H338.7z M353.7,52.1 c0,0.9-0.3,1.5-1,2c-0.6,0.5-1.5,0.7-2.7,0.7c-1.2,0-2.2-0.2-2.9-0.6v-1.3c0.4,0.2,0.9,0.4,1.4,0.5c0.5,0.1,1,0.2,1.5,0.2 c0.7,0,1.3-0.1,1.7-0.4c0.4-0.2,0.6-0.6,0.6-1.1c0-0.4-0.2-0.7-0.5-0.9c-0.3-0.3-0.9-0.6-1.8-0.9c-0.9-0.3-1.5-0.6-1.8-0.8 c-0.4-0.2-0.6-0.5-0.8-0.8c-0.2-0.3-0.3-0.7-0.3-1.1c0-0.8,0.3-1.4,0.9-1.8c0.6-0.4,1.5-0.7,2.5-0.7c1,0,2,0.2,2.9,0.6l-0.5,1.1 c-0.9-0.4-1.8-0.6-2.5-0.6c-0.7,0-1.2,0.1-1.5,0.3c-0.3,0.2-0.5,0.5-0.5,0.9c0,0.2,0.1,0.5,0.2,0.6c0.1,0.2,0.3,0.3,0.6,0.5 c0.3,0.2,0.8,0.4,1.6,0.7c1.1,0.4,1.8,0.8,2.2,1.2C353.5,51,353.7,51.5,353.7,52.1z M359.7,54.8c-1.3,0-2.4-0.4-3.1-1.2 c-0.7-0.8-1.1-2-1.1-3.5c0-1.5,0.4-2.7,1.1-3.6c0.7-0.8,1.8-1.3,3.2-1.3c0.4,0,0.9,0,1.3,0.1c0.4,0.1,0.8,0.2,1,0.3l-0.4,1.2 c-0.3-0.1-0.6-0.2-1-0.3c-0.4-0.1-0.7-0.1-1-0.1c-1.9,0-2.8,1.2-2.8,3.6c0,1.1,0.2,2,0.7,2.6c0.5,0.6,1.1,0.9,2,0.9 c0.8,0,1.6-0.2,2.4-0.5v1.2C361.4,54.6,360.7,54.8,359.7,54.8z M370.7,54.6v-6c0-0.8-0.2-1.3-0.5-1.7c-0.3-0.4-0.9-0.6-1.6-0.6 c-1,0-1.7,0.3-2.1,0.8c-0.4,0.5-0.7,1.4-0.7,2.6v4.8h-1.4V41.5h1.4v4c0,0.5,0,0.9-0.1,1.2h0.1c0.3-0.4,0.7-0.8,1.2-1.1 c0.5-0.3,1.1-0.4,1.7-0.4c1.1,0,2,0.3,2.5,0.8c0.6,0.5,0.8,1.4,0.8,2.6v6H370.7z M380.8,54.6l-0.3-1.3h-0.1c-0.5,0.6-0.9,1-1.4,1.2 c-0.5,0.2-1,0.3-1.7,0.3c-0.9,0-1.6-0.2-2.2-0.7s-0.8-1.1-0.8-2c0-1.9,1.5-2.9,4.5-2.9l1.6-0.1v-0.6c0-0.7-0.2-1.3-0.5-1.6 c-0.3-0.3-0.8-0.5-1.5-0.5c-0.8,0-1.6,0.2-2.6,0.7l-0.4-1.1c0.5-0.2,1-0.4,1.5-0.6c0.5-0.1,1.1-0.2,1.6-0.2c1.1,0,1.9,0.2,2.5,0.7 c0.5,0.5,0.8,1.3,0.8,2.4v6.3H380.8z M377.6,53.6c0.9,0,1.6-0.2,2.1-0.7c0.5-0.5,0.7-1.2,0.7-2v-0.8l-1.4,0.1 c-1.1,0-1.9,0.2-2.4,0.5c-0.5,0.3-0.7,0.8-0.7,1.4c0,0.5,0.2,0.9,0.5,1.2C376.6,53.5,377,53.6,377.6,53.6z M389,46.4h-2.4v8.2h-1.4 v-8.2h-1.7v-0.6l1.7-0.5v-0.5c0-2.3,1-3.4,3-3.4c0.5,0,1.1,0.1,1.7,0.3l-0.4,1.1c-0.5-0.2-1-0.3-1.4-0.3c-0.5,0-0.9,0.2-1.2,0.5 c-0.3,0.4-0.4,0.9-0.4,1.7v0.6h2.4V46.4z M394.8,46.4h-2.4v8.2h-1.4v-8.2h-1.7v-0.6l1.7-0.5v-0.5c0-2.3,1-3.4,3-3.4 c0.5,0,1.1,0.1,1.7,0.3l-0.4,1.1c-0.5-0.2-1-0.3-1.4-0.3c-0.5,0-0.9,0.2-1.2,0.5c-0.3,0.4-0.4,0.9-0.4,1.7v0.6h2.4V46.4z M399.6,53.6c0.2,0,0.5,0,0.7-0.1c0.2,0,0.4-0.1,0.5-0.1v1.1c-0.2,0.1-0.4,0.1-0.7,0.2c-0.3,0-0.6,0.1-0.8,0.1 c-1.8,0-2.7-0.9-2.7-2.8v-5.5h-1.3v-0.7l1.3-0.6l0.6-2h0.8v2.1h2.7v1.1h-2.7v5.5c0,0.6,0.1,1,0.4,1.3 C398.8,53.5,399.1,53.6,399.6,53.6z"/>
            <path fill="#FF6C36" d="M16.8,30.1v-2.4c-0.9,0.9-1.9,1.6-3,2.1c-1.1,0.5-2.3,0.7-3.6,0.7c-2.9,0-5.4-1-7.3-2.9 C1,25.7,0,23.2,0,20.2c0-1.4,0.2-2.7,0.7-3.9c0.5-1.2,1.2-2.3,2.1-3.3c1-1,2.1-1.8,3.2-2.3c1.2-0.5,2.5-0.7,4-0.7 c1.3,0,2.6,0.2,3.7,0.7c1.1,0.5,2.2,1.2,3.1,2.2v-2.4h3.6v19.6H16.8z M3.6,20.2c0,2,0.7,3.6,2,5c1.3,1.3,2.9,2,4.8,2 c1.7,0,3.3-0.7,4.6-2c1.3-1.3,2-2.9,2-4.7c0-1.9-0.7-3.6-2-4.9c-1.3-1.4-2.9-2.1-4.7-2.1c-1.8,0-3.4,0.7-4.7,2 C4.3,16.7,3.6,18.3,3.6,20.2 M27.9,27.7v2.4h-3.6V4.2h3.5v8.7c0.9-1,2-1.7,3.1-2.2c1.1-0.5,2.4-0.7,3.7-0.7c1.5,0,2.8,0.2,4,0.7 c1.2,0.5,2.2,1.3,3.2,2.3c0.9,0.9,1.6,2,2.1,3.3c0.5,1.2,0.7,2.5,0.7,3.9c0,3-1,5.4-2.9,7.4c-1.9,2-4.4,2.9-7.4,2.9 c-1.3,0-2.4-0.2-3.6-0.7C29.8,29.4,28.8,28.7,27.9,27.7 M27.8,20.5c0,1.8,0.7,3.4,2,4.7c1.3,1.3,2.9,2,4.6,2c1.9,0,3.5-0.7,4.8-2 c1.3-1.3,2-3,2-5c0-1.9-0.7-3.5-2-4.8c-1.3-1.3-2.9-2-4.7-2c-1.8,0-3.4,0.7-4.7,2C28.4,16.9,27.8,18.5,27.8,20.5 M48.2,31.7H52 c0.5,0.9,1.3,1.6,2.1,2.1c0.9,0.5,1.9,0.7,3,0.7c2,0,3.6-0.6,4.8-1.8c1.2-1.2,1.8-2.8,1.8-4.7v-0.2c-0.9,0.9-1.9,1.6-3,2.1 c-1.1,0.5-2.3,0.7-3.6,0.7c-2.9,0-5.4-1-7.3-2.9c-1.9-2-2.9-4.4-2.9-7.4c0-1.4,0.2-2.7,0.7-3.9c0.5-1.2,1.2-2.3,2.1-3.3 c1-1,2.1-1.8,3.2-2.3c1.2-0.5,2.5-0.7,4-0.7c1.3,0,2.6,0.2,3.7,0.7c1.1,0.5,2.2,1.2,3.1,2.2v-2.4h3.5v16.3c0,3.4-0.9,6.1-2.7,8 c-1.8,1.9-4.2,2.9-7.3,2.9c-2.2,0-4.2-0.5-5.7-1.6C50,35.1,48.9,33.6,48.2,31.7 M50.6,20.2c0,2,0.7,3.6,2,5c1.3,1.3,2.9,2,4.8,2 c1.7,0,3.3-0.7,4.6-2c1.3-1.3,2-2.9,2-4.7c0-1.9-0.7-3.6-2-4.9c-1.3-1.4-2.9-2.1-4.7-2.1c-1.8,0-3.4,0.7-4.7,2 C51.3,16.7,50.6,18.3,50.6,20.2 M74,21.6c0.3,1.6,1,3,2.2,4c1.2,1,2.6,1.5,4.2,1.5c1.2,0,2.2-0.3,3.2-0.8c1-0.6,1.7-1.3,2.3-2.4h4 c-0.9,2.2-2.2,3.8-3.8,5c-1.6,1.2-3.5,1.7-5.7,1.7c-1.4,0-2.8-0.3-4-0.8c-1.2-0.5-2.3-1.3-3.3-2.3c-0.9-1-1.6-2.1-2.1-3.4 c-0.5-1.3-0.8-2.6-0.8-3.9c0-1.4,0.2-2.7,0.7-3.9c0.5-1.2,1.2-2.3,2.1-3.3c1-1.1,2.1-1.9,3.3-2.4c1.2-0.5,2.6-0.8,4-0.8 c1.7,0,3.3,0.4,4.8,1.2c1.5,0.8,2.7,1.9,3.7,3.4c0.6,0.9,1,1.9,1.3,2.9c0.3,1.1,0.4,2.3,0.4,3.6v0.6H74z M86.7,18.5 c-0.4-1.6-1.2-2.9-2.3-3.7c-1.1-0.9-2.4-1.3-3.9-1.3c-1.5,0-2.9,0.5-4,1.4c-1.1,0.9-1.9,2.1-2.3,3.7H86.7z M92.4,20.4 c0-1.4,0.2-2.7,0.7-3.9c0.5-1.2,1.2-2.3,2.1-3.2c1-1.1,2.1-1.9,3.3-2.4c1.2-0.6,2.5-0.9,3.8-0.9c1.4,0,2.7,0.3,4,0.8 c1.2,0.5,2.3,1.3,3.3,2.3c1,1,1.7,2.1,2.2,3.3c0.5,1.2,0.8,2.5,0.8,3.8c0,1.3-0.2,2.6-0.7,3.9c-0.5,1.3-1.2,2.4-2,3.3 c-1,1.1-2.1,1.9-3.4,2.5c-1.2,0.6-2.6,0.8-4,0.8c-1.4,0-2.8-0.3-4-0.8c-1.2-0.5-2.3-1.3-3.3-2.3c-0.9-1-1.6-2.1-2.1-3.4 C92.7,23,92.4,21.7,92.4,20.4 M96.1,20.3c0,2,0.6,3.6,1.9,4.9c1.2,1.3,2.8,2,4.6,2c1.8,0,3.3-0.7,4.6-2c1.2-1.3,1.8-3,1.8-4.9 c0-2-0.6-3.6-1.8-4.9c-1.2-1.3-2.8-1.9-4.6-1.9c-1.8,0-3.4,0.7-4.6,2C96.7,16.7,96.1,18.3,96.1,20.3 M119.2,19.2 c0-1.8,0.3-3.1,1-3.9c0.7-0.8,1.8-1.3,3.4-1.4v-3.7c-1,0-1.9,0.2-2.6,0.6c-0.8,0.4-1.4,1.1-2,1.9v-2.3h-3.3v19.6h3.5V19.2z M142,30.1v-2.4c-0.9,0.9-1.9,1.6-3,2.1c-1.1,0.5-2.3,0.7-3.6,0.7c-2.9,0-5.4-1-7.3-2.9c-1.9-2-2.9-4.4-2.9-7.4 c0-1.4,0.2-2.7,0.7-3.9c0.5-1.2,1.2-2.3,2.1-3.3c1-1,2.1-1.8,3.2-2.3c1.2-0.5,2.5-0.7,4-0.7c1.3,0,2.6,0.2,3.7,0.7 c1.1,0.5,2.2,1.2,3.1,2.2V4.2h3.5v25.9H142z M128.9,20.2c0,2,0.7,3.6,2,5c1.3,1.3,2.9,2,4.8,2c1.7,0,3.3-0.7,4.6-2 c1.3-1.3,2-2.9,2-4.7c0-1.9-0.7-3.6-2-4.9c-1.3-1.4-2.9-2.1-4.7-2.1c-1.8,0-3.4,0.7-4.7,2C129.5,16.7,128.9,18.3,128.9,20.2 M153.2,21.2c0-2.7,0.4-4.7,1.2-5.8c0.8-1.2,2.1-1.8,3.8-1.8c1.6,0,2.8,0.5,3.6,1.5c0.8,1,1.2,2.5,1.2,4.6v10.4h3.5V19 c0-2.8-0.7-5-2.1-6.5c-1.4-1.5-3.3-2.3-5.9-2.3c-1.1,0-2.2,0.2-3,0.6c-0.9,0.4-1.7,1.1-2.4,1.9v-2.2h-3.4v19.6h3.5V21.2z M173.2,21.6c0.3,1.6,1,3,2.2,4c1.2,1,2.6,1.5,4.2,1.5c1.2,0,2.2-0.3,3.2-0.8c1-0.6,1.7-1.3,2.3-2.4h4c-0.9,2.2-2.2,3.8-3.8,5 c-1.6,1.2-3.5,1.7-5.7,1.7c-1.4,0-2.8-0.3-4-0.8c-1.2-0.5-2.3-1.3-3.3-2.3c-0.9-1-1.6-2.1-2.1-3.4c-0.5-1.3-0.8-2.6-0.8-3.9 c0-1.4,0.2-2.7,0.7-3.9c0.5-1.2,1.2-2.3,2.1-3.3c1-1.1,2.1-1.9,3.3-2.4c1.2-0.5,2.6-0.8,4-0.8c1.7,0,3.3,0.4,4.8,1.2 c1.5,0.8,2.7,1.9,3.7,3.4c0.6,0.9,1,1.9,1.3,2.9c0.3,1.1,0.4,2.3,0.4,3.6v0.6H173.2z M185.9,18.5c-0.4-1.6-1.2-2.9-2.3-3.7 c-1.1-0.9-2.4-1.3-3.9-1.3c-1.5,0-2.9,0.5-4,1.4c-1.1,0.9-1.9,2.1-2.3,3.7H185.9z M197.5,30.1V13.7h2.8v-3.2h-2.8V4.2H194v6.3h-2.8 v3.2h2.8v16.4H197.5z M205.4,21.6c0.3,1.6,1,3,2.2,4c1.2,1,2.6,1.5,4.2,1.5c1.2,0,2.2-0.3,3.2-0.8c1-0.6,1.7-1.3,2.3-2.4h4 c-0.9,2.2-2.2,3.8-3.8,5c-1.6,1.2-3.5,1.7-5.6,1.7c-1.4,0-2.8-0.3-4-0.8c-1.2-0.5-2.3-1.3-3.3-2.3c-0.9-1-1.6-2.1-2.1-3.4 c-0.5-1.3-0.8-2.6-0.8-3.9c0-1.4,0.2-2.7,0.7-3.9c0.5-1.2,1.2-2.3,2.1-3.3c1-1.1,2.1-1.9,3.3-2.4c1.2-0.5,2.6-0.8,4-0.8 c1.7,0,3.3,0.4,4.8,1.2c1.5,0.8,2.7,1.9,3.7,3.4c0.6,0.9,1,1.9,1.3,2.9c0.3,1.1,0.4,2.3,0.4,3.6v0.6H205.4z M218,18.5 c-0.4-1.6-1.2-2.9-2.3-3.7c-1.1-0.9-2.4-1.3-3.9-1.3c-1.5,0-2.9,0.5-4,1.4c-1.1,0.9-1.9,2.1-2.3,3.7H218z M228.5,21.2 c0-2.7,0.4-4.7,1.2-5.8c0.8-1.2,2.1-1.8,3.8-1.8c1.6,0,2.8,0.5,3.6,1.5c0.8,1,1.2,2.5,1.2,4.6v10.4h3.5V19c0-2.8-0.7-5-2.1-6.5 c-1.4-1.5-3.3-2.3-5.9-2.3c-1.1,0-2.2,0.2-3,0.6c-0.9,0.4-1.7,1.1-2.4,1.9v-2.2H225v19.6h3.5V21.2z"/>
            <path fill="#FF6C36" d="M467.2,0h-43.3c-5,0-9,4.1-9,9v43.1c0,5,4.1,9,9,9h43.3c5,0,9-3.9,9-8.9V9C476.2,4.1,472.2,0,467.2,0z M471.6,51.1c0,3.1-2.4,5.5-5.5,5.5H425c-3.1,0-5.5-2.4-5.5-5.5v-41c0-3.1,2.4-5.5,5.5-5.5h41.1c3.1,0,5.5,2.4,5.5,5.5V51.1z M457.9,18.9c-2.8-3-6.5-4.9-10.4-5.3l0.3-5.4c5.4,0.6,10.4,3,14.1,6.9c3.8,4,6,9,6.3,14.6h-5.5C462.4,25.8,460.7,21.9,457.9,18.9 L457.9,18.9z M445.2,8l-0.2,5.5c-4.5,0-8.7,1.8-11.9,4.9l-3.7-4C433.6,10.2,439.2,8,445.2,8C445.3,8,445.3,8,445.2,8z M457.3,43.6 c1.4-1.2,2.5-2.8,3.3-4.3l5.3,1.7c-1.2,2.4-2.9,4.7-4.9,6.6L457.3,43.6L457.3,43.6z M466.8,38.7l-5.2-1.7c0.7-1.5,1-3.2,1.1-5h5.5 C468.1,34.4,467.7,36.7,466.8,38.7z M453.2,26.2l4-3.9c1.7,2.2,2.6,4.7,2.9,7.5h-5.5C454.3,28.5,453.9,27.3,453.2,26.2L453.2,26.2z M454.4,32.3h5.5c-0.2,3.6-1.9,7.1-4.5,9.6l-3.7-4C453.2,36.4,454.2,34.4,454.4,32.3z M434.9,20.4c2.6-2.6,6.2-4.1,10-4.1l-0.3,5.5 c-2.3,0.1-4.3,1-6,2.5L434.9,20.4L434.9,20.4z M451.7,24.3c-1.3-1.2-3-2.1-4.7-2.4l0.3-5.5c3.1,0.4,6,1.9,8.3,4.1L451.7,24.3zM445.2,31H445l0.1-0.1V31z"/>
          </svg>
        </div>
      </a>
    <?php endif; ?>
  </footer>
</div>
