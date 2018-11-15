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
  <header id="header">
    <div class="container">
      <?php if ($logo): ?>
        <a class="header__logo" href="<?php print $front_page; ?>" title="<?php print t('Back to home'); ?>" rel="home">
          <div class="svg-container">
            <svg viewBox="0 0 379.1 53.2"><path fill="#EC663B" d="M359.8 16.8c2.8 3 4.5 6.7 4.8 10.8h5.4c-.3-5.4-2.5-10.5-6.3-14.5-3.8-3.9-8.7-6.3-14-6.9l-.3 5.4c3.9.4 7.6 2.3 10.4 5.2zM347.2 6c-5.9 0-11.5 2.2-15.7 6.3l3.7 3.9c3.2-3.1 7.4-4.8 11.8-4.8l.2-5.4c.1 0 .1 0 0 0zm12.1 35.4l3.7 3.9c2-1.9 3.6-4.1 4.8-6.5l-5.2-1.7c-.9 1.5-2 3-3.3 4.3zM370 29.9h-5.4c-.1 1.7-.5 3.4-1.1 5l5.2 1.7c.7-2.2 1.2-4.4 1.3-6.7z"/><path fill="#EC663B" d="M355.1 24c.7 1.1 1.1 2.3 1.3 3.6h5.4c-.2-2.7-1.2-5.2-2.8-7.4l-3.9 3.8zm-1.5 11.6l3.7 3.9c2.7-2.5 4.2-5.9 4.5-9.6h-5.4c-.3 2.2-1.2 4.2-2.8 5.7zM337 18.2l3.7 3.9c1.6-1.5 3.7-2.4 5.9-2.6l.3-5.4c-3.7.1-7.2 1.6-9.9 4.1zm20.5.2c-2.3-2.2-5.1-3.6-8.2-4.1l-.3 5.4c1.8.3 3.4 1.2 4.7 2.4l3.8-3.7z"/><path fill="#FFF" d="M347.2 28.6l-.2.1h.2"/><path fill="#EC663B" d="M0 18.1V18c0-2.2.8-3.9 2.3-5.2s3.2-2 5-2.1h.8c1 0 2 .3 3 .7s1.7 1.1 2.3 2v-2.5H15v14.3h-1.6v-2.4c-.5.9-1.3 1.5-2.2 2-1 .4-1.9.7-3 .8H6.8c-1.7-.2-3.2-.9-4.7-2.1C.7 22.1 0 20.4 0 18.4V18.1c.1.1.1.1 0 0 .1 0 .1 0 0 0zm2.1-.4v.4c0 1.6.5 2.9 1.5 4s2.5 1.6 4.5 1.6c1.4 0 2.5-.5 3.5-1.5.9-1 1.5-2.2 1.6-3.4v-1.3c-.2-1.4-.7-2.5-1.7-3.4-.9-.9-2.1-1.3-3.7-1.4h-.3c-1.2 0-2.3.4-3.2 1.1-.9.7-1.5 1.6-1.9 2.5-.1.3-.2.5-.2.7s-.1.5-.1.7c0-.1 0-.1 0 0zM18.8 6h1.8v7.1c.6-.8 1.4-1.4 2.5-1.9 1-.5 2.1-.8 3.2-.8.3 0 .7 0 1 .1.3 0 .7.1 1 .2.6.2 1.2.4 1.7.7.6.3 1.1.7 1.6 1.3.6.6 1.1 1.3 1.4 2.2s.5 1.8.6 2.8v.8c0 1.2-.3 2.3-.9 3.4-.6 1.1-1.4 1.9-2.5 2.5-.4.2-.8.4-1.2.5-.4.1-.9.2-1.3.3-.2 0-.4.1-.6.1h-1.2c-1-.1-2-.3-3-.7-1-.4-1.8-1-2.4-1.7v2.4h-1.8V6h.1zm3 15.6c.8 1.2 2.2 1.9 4.3 1.9h.4c1.5-.1 2.8-.7 3.8-1.7s1.5-2.4 1.5-4.2c0-1.4-.6-2.7-1.8-3.8-1.2-1.1-2.5-1.7-3.9-1.7-.3 0-.7.1-1 .2-.4.1-.8.3-1.2.5-.8.4-1.6 1.1-2.2 1.9-.7.8-1 1.8-1 2.9-.1 1.4.3 2.8 1.1 4zm16.6-9c1.3-1.2 2.7-1.8 4.2-2h1c1.1 0 2.2.3 3.2.9 1 .5 1.7 1.2 2.2 2.1V11h2v12.3c0 2.4-.7 4.3-2.2 5.5s-3.1 1.8-4.9 1.8h-.4c-1.4-.1-2.8-.6-4.1-1.5s-2.2-2.2-2.7-3.9h1.8c.4 1.1 1.1 1.9 2 2.4s1.8.9 2.8.9h.6c1.3-.1 2.5-.5 3.6-1.5 1.1-.9 1.6-2.2 1.6-3.9v-.8c-.3.8-1 1.5-2.1 2-1.2.5-2.4.8-3.7.8h-1c-1.5-.2-2.9-.8-4.2-1.9s-1.9-2.8-1.9-5.1v-.4c.2-2.1.9-3.9 2.2-5.1zm0 4.9v.4c0 1.6.4 2.9 1.3 4s2.2 1.6 3.8 1.6c1.4 0 2.7-.4 3.8-1.3s1.7-2.4 1.7-4.6c0-1.3-.5-2.4-1.5-3.3-1-1-2.1-1.5-3.3-1.7h-.7c-1.1.1-2 .4-2.7.9s-1.2 1-1.6 1.6c-.3.5-.6.9-.7 1.4-.1.4-.2.8-.2 1 .1-.1.1-.1.1 0zm17.5-4.9c1.5-1.2 3-1.8 4.8-1.9h.4c1.8 0 3.4.7 4.9 1.9s2.2 3 2.2 5.4v.6H55.6c.2 1.7.8 2.9 1.8 3.6 1 .8 2 1.2 3.1 1.3h.8c1.1-.1 2.1-.4 3-.9.9-.6 1.6-1.3 1.8-2.1h2c-.6 1.6-1.5 2.9-2.7 3.6-1.2.8-2.5 1.2-3.8 1.2h-.5c-1.8 0-3.5-.7-5.1-2-1.5-1.3-2.3-3.1-2.4-5.3.1-2.4.9-4.2 2.3-5.4zm8.6 1.2c-.9-.9-2-1.4-3.4-1.5-1.2.1-2.2.4-2.9.9s-1.3 1-1.7 1.5c-.3.5-.6.9-.7 1.3-.1.4-.2.7-.3.9h10.8c-.3-1.2-1-2.2-1.8-3.1zm8-1.1c1.4-1.4 3.3-2.1 5.6-2.1 2 0 3.7.6 5.1 1.9s2 2.9 2 4.8c0 2.5-.7 4.4-2.1 5.8s-3.1 2.1-5.3 2.1c-2 0-3.8-.6-5.2-1.9-1.4-1.3-2.2-3.1-2.3-5.6.1-1.9.8-3.5 2.2-5zm1.4 9c.9 1 1.9 1.6 3 1.7H78c1.3-.1 2.5-.7 3.6-1.6 1.1-1 1.6-2.5 1.6-4.5 0-1.4-.5-2.5-1.6-3.4s-2.3-1.3-3.7-1.4h-.4c-1.4 0-2.6.5-3.6 1.5-.9 1-1.5 2.2-1.5 3.8.1 1.6.6 3 1.5 3.9zm14-10.9h1.8v1.9c.4-.7 1-1.3 1.6-1.6.7-.3 1.5-.5 2.5-.5v2.1c-.2 0-.4 0-.6.1-.2 0-.4.1-.6.2-.7.2-1.4.6-2 1.2-.6.6-.9 1.3-.9 2.2v8.8h-1.8V10.8zM98 12.4c1.4-1.1 2.9-1.7 4.6-1.8h1.3c.9.1 1.8.4 2.6.8.9.4 1.6 1 2.1 1.8V6h1.6v19.1h-1.6v-2.6c-.6.8-1.3 1.5-2.1 1.9-.8.4-1.7.7-2.6.8h-1c-1.8 0-3.5-.7-5-2s-2.3-3.1-2.3-5.4v-.5c.2-2.1 1-3.8 2.4-4.9zm-.6 4.9v.5c0 1.5.4 2.8 1.3 4s2.3 1.9 4.3 1.9h.5c.2 0 .3 0 .5-.1 1.1-.3 2.1-.9 3.1-1.9.9-1 1.4-2.3 1.4-3.8v-.3c0-.3 0-.6-.1-1s-.3-.8-.5-1.2c-.4-.7-.9-1.4-1.7-1.9-.8-.6-1.8-.9-3.2-.9-.3 0-.7 0-1 .1-.4.1-.8.2-1.2.4-.8.3-1.5.8-2.2 1.5s-1 1.6-1.1 2.6c-.1 0-.1 0-.1.1zm16.5-6.5h1.8v1.9c.4-.6 1-1 1.8-1.4.7-.3 1.5-.6 2.3-.7h.8c1.4 0 2.7.5 3.9 1.4 1.2.9 1.8 2.4 1.8 4.3v8.8h-1.9v-8.8c0-1.3-.4-2.3-1.3-3-.8-.7-1.8-1-2.8-1.1H119.7c-1.1 0-2 .4-2.9 1.1-.9.7-1.3 1.6-1.3 2.9v8.9h-1.8V10.8h.2zm17.5 1.8c1.5-1.2 3-1.8 4.8-1.9h.4c1.8 0 3.4.7 4.9 1.9s2.2 3 2.2 5.4v.6H131c.2 1.7.8 2.9 1.8 3.6 1 .8 2 1.2 3.1 1.3h.8c1.1-.1 2.1-.4 3-.9.9-.6 1.6-1.3 1.8-2.1h2c-.6 1.6-1.5 2.9-2.7 3.6-1.2.8-2.5 1.2-3.8 1.2h-.5c-1.8 0-3.5-.7-5.1-2-1.5-1.3-2.3-3.1-2.4-5.3.1-2.4.9-4.2 2.4-5.4zm8.5 1.2c-.9-.9-2-1.4-3.4-1.5-1.2.1-2.2.4-2.9.9s-1.3 1-1.7 1.5c-.3.5-.6.9-.7 1.3-.1.4-.2.7-.3.9h10.8c-.3-1.2-.9-2.2-1.8-3.1zm5.5-.9V11h2.8V6.2h1.8V11h3.3v1.9H150v12.2h-1.8V12.9h-2.8zm11.9-.3c1.5-1.2 3-1.8 4.8-1.9h.4c1.8 0 3.4.7 4.9 1.9s2.2 3 2.2 5.4v.6H157c.2 1.7.8 2.9 1.8 3.6 1 .8 2 1.2 3.1 1.3h.8c1.1-.1 2.1-.4 3-.9.9-.6 1.6-1.3 1.8-2.1h2c-.6 1.6-1.5 2.9-2.7 3.6-1.2.8-2.5 1.2-3.8 1.2h-.5c-1.8 0-3.5-.7-5.1-2-1.5-1.3-2.3-3.1-2.4-5.3.1-2.4.9-4.2 2.3-5.4zm8.6 1.2c-.9-.9-2-1.4-3.4-1.5-1.2.1-2.2.4-2.9.9s-1.3 1-1.7 1.5c-.3.5-.6.9-.7 1.3-.1.4-.2.7-.3.9h10.8c-.3-1.2-.9-2.2-1.8-3.1zm6.5-3h1.8v1.9c.4-.6 1-1 1.8-1.4.7-.3 1.5-.6 2.3-.7h.8c1.4 0 2.7.5 3.9 1.4s1.8 2.4 1.8 4.3v8.8H183v-8.8c0-1.3-.4-2.3-1.3-3-.8-.7-1.8-1-2.8-1.1h-.6c-1.1 0-2 .4-2.9 1.1-.9.7-1.3 1.6-1.3 2.9v8.9h-1.8V10.8h.1zM374.2 0l-22.4.1-19.3.9s-9.2-1-9.2 4.5-.4 17.7-.4 17.7v16.9c0 1.7-1.2 9.8 2.8 11.4 4 1.6 6.5 1.7 9.3 1.7s19.2-1.1 19.2-1.1h12.5s11.2 1.2 11.2-6.5.7-20.8.7-20.8l.2-14.1c.2 0 1.2-10.3-4.6-10.7zm.3 26.5c-.1 1.6-.5 15.2-.5 18.8s-3.2 3.3-3.2 3.3-7.8-.1-9.2 0c-1.3.1-9.7 0-19.2.2-9.6.2-12.4.1-14.7-1-2.3-1.1-1.3-6.5-1.5-9.4-.1-2.9-.6-10.2-.6-10.2l-.2-8.9v-4.2s.6-3.4.9-7 6-4.2 7.5-4.2 17.4-.6 17.4-.6 16.8-1 20-.9 2.9 3.9 2.9 3.9-.2 3.4-.2 7.8c-.2 4.5.7 10.8.6 12.4z"/><path fill="#575756" d="M194.5 25.1h-2.3L186.8 11h2l4.5 11.6 3.2-9.9h1.6l3.3 9.9 4.4-11.6h2.1l-5.3 14.1h-2.2l-3.1-8.8-2.8 8.8zm15.4-7V18c0-2.2.8-3.9 2.3-5.2s3.2-2 5-2.1h.8c1 0 2 .3 3 .7s1.7 1.1 2.3 2v-2.5h1.6v14.3h-1.6v-2.4c-.5.9-1.3 1.5-2.2 2-1 .4-1.9.7-3 .8h-1.4c-1.7-.2-3.2-.9-4.7-2.1-1.4-1.2-2.1-2.8-2.1-4.8V18.4c.1-.2.1-.2 0-.3.1 0 .1 0 0 0zm2.1-.4v.4c0 1.6.5 2.9 1.5 4s2.5 1.6 4.5 1.6c1.4 0 2.5-.5 3.5-1.5.9-1 1.5-2.2 1.6-3.4v-1.3c-.2-1.4-.7-2.5-1.7-3.4-.9-.9-2.1-1.3-3.7-1.4h-.3c-1.2 0-2.3.4-3.2 1.1-.9.7-1.5 1.6-1.9 2.5-.1.3-.2.5-.2.7s-.1.5-.1.7c0-.1 0-.1 0 0zm15.4-4.8V11h2.8V6.2h1.8V11h3.3v1.9H232v12.2h-1.8V12.9h-2.8zm12.2-.5c1.5-1.3 3.2-2 5.1-2h1c1.2.2 2.3.6 3.4 1.3 1.1.7 2 1.8 2.7 3.2h-2.2c-.4-.9-1.1-1.5-1.9-2-.9-.4-1.8-.6-2.8-.6h-.4c-.9.1-1.9.3-2.7.8-.9.4-1.5 1-1.8 1.8l-.3.6c-.1.2-.1.4-.2.6-.1.3-.2.6-.2.9-.1.3-.1.6-.1.9 0 .7.1 1.4.4 2 .3.6.6 1.2 1 1.6.2.2.5.4.7.6s.5.4.7.5c.5.3 1 .5 1.5.6s1 .2 1.4.2c1 0 2-.3 2.8-.8.9-.5 1.5-1.1 1.9-1.8 0 0 0-.1.1-.1l.1-.1h2.2c-.8 1.3-1.6 2.2-2.6 2.9-1 .7-2 1.2-3 1.4-.3.1-.5.1-.8.1h-.8c-1.9 0-3.7-.7-5.2-2.1s-2.3-3.1-2.3-5.3c0-2 .8-3.8 2.3-5.2zm15-6.4h1.8v6.7c.6-.7 1.2-1.2 1.9-1.5.7-.3 1.4-.5 2.1-.6h.4c1.6 0 3 .6 4.3 1.8s1.9 2.5 1.9 4v8.8h-2v-8.8c-.2-1.2-.7-2.2-1.5-2.8s-1.6-1-2.5-1.1h-.4c-1 0-2 .4-2.9 1.1-.9.7-1.3 1.7-1.3 3.1v8.6h-1.8V6zm16.6 15.7h2v3.4h-2v-3.4zm8.5-9.3c1.4-1.1 2.9-1.7 4.6-1.8h1.3c.9.1 1.8.4 2.6.8.9.4 1.6 1 2.1 1.8V6h1.6v19.1h-1.6v-2.6c-.6.8-1.3 1.5-2.1 1.9-.8.4-1.7.7-2.6.8h-1c-1.8 0-3.5-.7-5-2s-2.3-3.1-2.3-5.4v-.5c.1-2.1 1-3.8 2.4-4.9zm-.7 4.9v.5c0 1.5.4 2.8 1.3 4s2.3 1.9 4.3 1.9h.5c.2 0 .3 0 .5-.1 1.1-.3 2.1-.9 3.1-1.9.9-1 1.4-2.3 1.4-3.8v-.3c0-.3 0-.6-.1-1s-.3-.8-.5-1.2c-.4-.7-.9-1.4-1.7-1.9-.8-.6-1.8-.9-3.2-.9-.3 0-.7 0-1 .1-.4.1-.8.2-1.2.4-.8.3-1.5.8-2.2 1.5s-1 1.6-1.2 2.7c0-.1 0-.1 0 0zm18.3-4.7c1.5-1.2 3.1-1.8 4.8-1.9h.4c1.8 0 3.4.7 4.9 1.9s2.2 3 2.2 5.4v.6H297c.2 1.7.8 2.9 1.8 3.6 1 .8 2 1.2 3.1 1.3h.8c1.1-.1 2.1-.4 3-.9.9-.6 1.6-1.3 1.8-2.1h2c-.6 1.6-1.5 2.9-2.7 3.6-1.2.8-2.5 1.2-3.8 1.2h-.5c-1.8 0-3.5-.7-5.1-2-1.5-1.3-2.3-3.1-2.4-5.3 0-2.4.8-4.2 2.3-5.4zm8.6 1.2c-.9-.9-2-1.4-3.4-1.5-1.2.1-2.2.4-2.9.9-.7.5-1.3 1-1.7 1.5-.3.5-.6.9-.7 1.3-.1.4-.2.7-.3.9h10.8c-.4-1.2-1-2.2-1.8-3.1zM105.1 44l-1.3-4.2c-.1-.3-.2-.8-.5-1.7h-.1c-.2.8-.3 1.3-.5 1.7l-1.3 4.1h-1.2l-1.9-7.1h1.1c.5 1.8.8 3.1 1 4.1.2.9.4 1.6.4 1.9h.1c0-.2.1-.6.2-1s.2-.7.3-.9l1.3-4.1h1.2l1.3 4.1c.2.7.4 1.4.5 1.9h.1c0-.2.1-.4.1-.7.1-.3.5-2.1 1.3-5.2h1.1l-2 7.1h-1.2zm7.5.1c-1 0-1.9-.3-2.5-1-.6-.6-.9-1.5-.9-2.7 0-1.1.3-2 .8-2.7.6-.7 1.3-1 2.3-1 .9 0 1.6.3 2.1.9s.8 1.4.8 2.3v.7h-4.9c0 .8.2 1.5.6 1.9s1 .6 1.7.6c.8 0 1.5-.2 2.3-.5v1c-.4.2-.7.3-1.1.4-.3.1-.7.1-1.2.1zm-.3-6.4c-.6 0-1 .2-1.4.6-.3.4-.5.9-.6 1.5h3.7c0-.7-.2-1.2-.5-1.6s-.6-.5-1.2-.5zM117 35c0-.2.1-.4.2-.5.1-.1.3-.2.5-.2s.3.1.4.2c.1.1.2.3.2.5s-.1.4-.2.5-.3.2-.4.2c-.2 0-.3-.1-.5-.2s-.2-.2-.2-.5zm1.1 9H117v-7.1h1.1V44zm3.4 0h-1.1V34h1.1v10zm8-.7h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.4 0-2.1-.7-2.1-2.2v-4.2h-1v-.5l1-.4.5-1.5h.6V37h2.1v.8h-2.1V42c0 .4.1.8.3 1s.5.3.9.3zm5.6-6.5c.3 0 .6 0 .8.1l-.1 1c-.3-.1-.6-.1-.8-.1-.6 0-1.1.2-1.5.7-.4.5-.6 1-.6 1.7V44h-1.1v-7.1h.9l.1 1.3h.1c.3-.5.6-.8.9-1.1s.9-.3 1.3-.3zm6.5 7.2l-.2-1h-.1c-.4.4-.7.7-1.1.9-.4.2-.8.2-1.3.2-.7 0-1.3-.2-1.7-.5-.4-.4-.6-.9-.6-1.5 0-1.4 1.1-2.2 3.4-2.2h1.2v-.4c0-.6-.1-1-.4-1.2s-.6-.4-1.1-.4c-.6 0-1.3.2-2 .5l-.3-.8c.3-.2.7-.3 1.1-.4.4-.1.8-.2 1.3-.2.8 0 1.5.2 1.9.6.4.4.6 1 .6 1.8V44h-.7zm-2.4-.7c.7 0 1.2-.2 1.6-.5.4-.4.6-.9.6-1.5v-.6h-1.1c-.9 0-1.5.2-1.8.4s-.6.6-.6 1.1c0 .4.1.7.4.9s.5.2.9.2zm10.3.7v-4.6c0-.6-.1-1-.4-1.3-.3-.3-.7-.4-1.2-.4-.7 0-1.3.2-1.6.6-.3.4-.5 1.1-.5 2V44h-1.1v-7.1h.9l.2 1h.1c.2-.3.5-.6.9-.8s.8-.3 1.3-.3c.9 0 1.5.2 1.9.6.4.4.6 1.1.6 2V44h-1.1zm7.8-1.9c0 .7-.2 1.2-.7 1.5-.5.4-1.2.5-2.1.5-.9 0-1.7-.1-2.2-.4v-1c.3.2.7.3 1.1.4.4.1.8.1 1.1.1.6 0 1-.1 1.3-.3.3-.2.5-.5.5-.8 0-.3-.1-.5-.4-.7-.2-.2-.7-.4-1.4-.7-.7-.2-1.1-.5-1.4-.6s-.5-.4-.6-.6c-.1-.2-.2-.5-.2-.8 0-.6.2-1 .7-1.4.5-.3 1.1-.5 1.9-.5.8 0 1.5.2 2.2.5l-.4.9c-.7-.3-1.4-.4-1.9-.4s-.9.1-1.2.2c-.3.2-.4.4-.4.7 0 .2 0 .4.1.5.1.1.3.3.5.4.2.1.6.3 1.2.5.8.3 1.4.6 1.7.9.5.2.6.6.6 1.1zm5.1 2c-.5 0-.9-.1-1.3-.3s-.7-.4-1-.8h-.1c.1.4.1.8.1 1.2v2.9H159V36.9h.9l.1 1h.1c.3-.4.6-.7 1-.8s.8-.3 1.3-.3c.9 0 1.7.3 2.2 1 .5.6.8 1.5.8 2.7 0 1.2-.3 2.1-.8 2.7-.6.6-1.3.9-2.2.9zm-.2-6.4c-.7 0-1.2.2-1.6.6s-.5 1-.5 1.9v.2c0 1 .2 1.7.5 2.1.3.4.9.6 1.6.6.6 0 1.1-.2 1.4-.7s.5-1.2.5-2c0-.9-.2-1.6-.5-2-.3-.5-.8-.7-1.4-.7zm9.3 6.3l-.2-1h-.1c-.4.4-.7.7-1.1.9-.4.2-.8.2-1.3.2-.7 0-1.3-.2-1.7-.5-.4-.4-.6-.9-.6-1.5 0-1.4 1.1-2.2 3.4-2.2h1.2v-.4c0-.6-.1-1-.4-1.2s-.6-.4-1.1-.4c-.6 0-1.3.2-2 .5l-.3-.8c.3-.2.7-.3 1.1-.4.4-.1.8-.2 1.3-.2.8 0 1.5.2 1.9.6.4.4.6 1 .6 1.8V44h-.7zm-2.4-.7c.7 0 1.2-.2 1.6-.5.4-.4.6-.9.6-1.5v-.6h-1.1c-.9 0-1.5.2-1.8.4s-.6.6-.6 1.1c0 .4.1.7.4.9s.5.2.9.2zm8.7-6.5c.3 0 .6 0 .8.1l-.1 1c-.3-.1-.6-.1-.8-.1-.6 0-1.1.2-1.5.7-.4.5-.6 1-.6 1.7V44h-1.1v-7.1h.9l.1 1.3h.1c.3-.5.6-.8.9-1.1s.8-.3 1.3-.3zm5.1 7.3c-1 0-1.9-.3-2.5-1s-.9-1.5-.9-2.7c0-1.1.3-2 .8-2.7.6-.7 1.3-1 2.3-1 .9 0 1.6.3 2.1.9s.8 1.4.8 2.3v.7h-4.9c0 .8.2 1.5.6 1.9.4.4 1 .6 1.7.6.8 0 1.5-.2 2.3-.5v1c-.4.2-.7.3-1.1.4-.3.1-.7.1-1.2.1zm-.3-6.4c-.6 0-1 .2-1.4.6-.3.4-.5.9-.6 1.5h3.7c0-.7-.2-1.2-.5-1.6-.2-.3-.6-.5-1.2-.5zm9.6 6.3v-4.6c0-.6-.1-1-.4-1.3-.3-.3-.7-.4-1.2-.4-.7 0-1.3.2-1.6.6-.3.4-.5 1.1-.5 2V44h-1.1v-7.1h.9l.2 1h.1c.2-.3.5-.6.9-.8s.8-.3 1.3-.3c.9 0 1.5.2 1.9.6s.6 1.1.6 2V44h-1.1zm7.8 0h-5.1v-.7l3.9-5.5h-3.6V37h4.8v.8l-3.8 5.4h3.9v.8zm6.7 0l-2.7-7.1h1.2l1.5 4.2c.3 1 .5 1.6.6 1.9h.1c0-.2.2-.7.4-1.4.3-.7.8-2.3 1.7-4.7h1.2L208 44h-1.3zm8 .1c-1 0-1.9-.3-2.5-1s-.9-1.5-.9-2.7c0-1.1.3-2 .8-2.7s1.3-1 2.3-1c.9 0 1.6.3 2.1.9.5.6.8 1.4.8 2.3v.7h-4.9c0 .8.2 1.5.6 1.9s1 .6 1.7.6c.8 0 1.5-.2 2.3-.5v1c-.4.2-.7.3-1.1.4-.3.1-.7.1-1.2.1zm-.3-6.4c-.6 0-1 .2-1.4.6-.3.4-.5.9-.6 1.5h3.7c0-.7-.2-1.2-.5-1.6-.2-.3-.6-.5-1.2-.5zm8-.9c.3 0 .6 0 .8.1l-.1 1c-.3-.1-.6-.1-.8-.1-.6 0-1.1.2-1.5.7-.4.5-.6 1-.6 1.7V44h-1.1v-7.1h.9l.1 1.3h.1c.3-.5.6-.8.9-1.1s.8-.3 1.3-.3zm4.4 6.5h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.4 0-2.1-.7-2.1-2.2v-4.2h-1v-.5l1-.4.5-1.5h.6V37h2.1v.8h-2.1V42c0 .4.1.8.3 1 .3.1.6.3.9.3zm5.7-6.5c.3 0 .6 0 .8.1l-.1 1c-.3-.1-.6-.1-.8-.1-.6 0-1.1.2-1.5.7-.4.5-.6 1-.6 1.7V44h-1.1v-7.1h.9l.1 1.3h.1c.3-.5.6-.8.9-1.1s.8-.3 1.3-.3zM239 44l-.2-1h-.1c-.4.4-.7.7-1.1.9-.4.2-.8.2-1.3.2-.7 0-1.3-.2-1.7-.5-.4-.4-.6-.9-.6-1.5 0-1.4 1.1-2.2 3.4-2.2h1.2v-.4c0-.6-.1-1-.4-1.2-.2-.3-.6-.4-1.1-.4-.6 0-1.3.2-2 .5l-.3-.8c.3-.2.7-.3 1.1-.4.4-.1.8-.2 1.3-.2.8 0 1.5.2 1.9.6.4.4.6 1 .6 1.8V44h-.7zm-2.4-.7c.7 0 1.2-.2 1.6-.5.4-.4.6-.9.6-1.5v-.6h-1.1c-.9 0-1.5.2-1.8.4s-.6.6-.6 1.1c0 .4.1.7.4.9.1.1.4.2.9.2zm6.4-6.4v4.6c0 .6.1 1 .4 1.3s.7.4 1.2.4c.7 0 1.3-.2 1.6-.6s.5-1.1.5-2v-3.7h1.1V44h-.8l-.2-.9h-.1c-.2.3-.5.6-.9.8-.4.2-.8.3-1.3.3-.9 0-1.5-.2-1.9-.6-.4-.4-.6-1.1-.6-2V37h1zm10.1 7.2c-1 0-1.9-.3-2.5-1-.6-.6-.9-1.5-.9-2.7 0-1.1.3-2 .8-2.7s1.3-1 2.3-1c.9 0 1.6.3 2.1.9s.8 1.4.8 2.3v.7h-4.9c0 .8.2 1.5.6 1.9s1 .6 1.7.6c.8 0 1.5-.2 2.3-.5v1c-.4.2-.7.3-1.1.4-.3.1-.7.1-1.2.1zm-.3-6.4c-.6 0-1 .2-1.4.6-.3.4-.5.9-.6 1.5h3.7c0-.7-.2-1.2-.5-1.6-.2-.3-.6-.5-1.2-.5zm9.6 6.3v-4.6c0-.6-.1-1-.4-1.3-.3-.3-.7-.4-1.2-.4-.7 0-1.3.2-1.6.6s-.5 1.1-.5 2V44h-1.1v-7.1h.9l.2 1h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.3-.3.9 0 1.5.2 1.9.6.4.4.6 1.1.6 2V44h-1.1zm11.3-1.9c0 .7-.2 1.2-.7 1.5-.5.4-1.2.5-2.1.5-.9 0-1.7-.1-2.2-.4v-1c.3.2.7.3 1.1.4.4.1.8.1 1.1.1.6 0 1-.1 1.3-.3.3-.2.5-.5.5-.8 0-.3-.1-.5-.4-.7-.2-.2-.7-.4-1.4-.7-.7-.2-1.1-.5-1.4-.6s-.5-.4-.6-.6c-.1-.2-.2-.5-.2-.8 0-.6.2-1 .7-1.4s1.1-.5 1.9-.5c.8 0 1.5.2 2.2.5l-.4.9c-.7-.3-1.4-.4-1.9-.4s-.9.1-1.2.2c-.3.2-.4.4-.4.7 0 .2 0 .4.1.5.1.1.3.3.5.4s.6.3 1.2.5c.8.3 1.4.6 1.7.9.4.2.6.6.6 1.1zm4.5 2c-1 0-1.8-.3-2.4-.9-.6-.6-.8-1.5-.8-2.7 0-1.2.3-2.1.9-2.7.6-.6 1.4-1 2.4-1 .3 0 .7 0 1 .1.3.1.6.2.8.3l-.3.9c-.2-.1-.5-.2-.8-.2-.3-.1-.5-.1-.7-.1-1.4 0-2.2.9-2.2 2.8 0 .9.2 1.5.5 2 .4.5.9.7 1.6.7.6 0 1.2-.1 1.8-.4v.9c-.4.2-1 .3-1.8.3zm8.4-.1v-4.6c0-.6-.1-1-.4-1.3-.3-.3-.7-.4-1.2-.4-.7 0-1.3.2-1.6.6s-.5 1.1-.5 2V44h-1.1V34h1.1v3c0 .4 0 .7-.1.9h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.3-.3.9 0 1.5.2 1.9.6.4.4.6 1.1.6 2V44h-1zm7.6 0l-.2-1h-.1c-.4.4-.7.7-1.1.9-.4.2-.8.2-1.3.2-.7 0-1.3-.2-1.7-.5-.4-.4-.6-.9-.6-1.5 0-1.4 1.1-2.2 3.4-2.2h1.2v-.4c0-.6-.1-1-.4-1.2-.2-.3-.6-.4-1.1-.4-.6 0-1.3.2-2 .5l-.3-.8c.3-.2.7-.3 1.1-.4.4-.1.8-.2 1.3-.2.8 0 1.5.2 1.9.6.4.4.6 1 .6 1.8V44h-.7zm-2.4-.7c.7 0 1.2-.2 1.6-.5.4-.4.6-.9.6-1.5v-.6h-1.1c-.9 0-1.5.2-1.8.4-.4.2-.6.6-.6 1.1 0 .4.1.7.4.9.1.1.4.2.9.2zm8.6-5.5h-1.8V44h-1.1v-6.2h-1.3v-.5l1.3-.4v-.4c0-1.7.8-2.6 2.3-2.6.4 0 .8.1 1.3.2l-.3.9c-.4-.1-.8-.2-1.1-.2-.4 0-.7.1-.9.4-.2.3-.3.7-.3 1.3v.5h1.8v.8zm4.5 0h-1.8V44H302v-6.2h-1.3v-.5l1.3-.4v-.4c0-1.7.8-2.6 2.3-2.6.4 0 .8.1 1.3.2l-.3.9c-.4-.1-.8-.2-1.1-.2-.4 0-.7.1-.9.4s-.3.7-.3 1.3v.5h1.8v.8zm3.6 5.5h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.4 0-2.1-.7-2.1-2.2v-4.2h-1v-.5l1-.4.5-1.5h.6V37h2.1v.8h-2.1V42c0 .4.1.8.3 1s.5.3.9.3z"/></svg>
          </div>
        </a>
      <?php endif; ?>

      <?php print render($page['header_top']); ?>

    </div>


    <div class="header__bottom">
      <div class="header__bottom__inner">
        <div class="header__subnav__archive dropdown dropdown--hover">
          <span><span class="header__subnav__archive__indicator">Bundestag <span>2013 – 2017</span></span></span>
          <ul class="header__subnav__archive__list dropdown__list">
            <li class="header__subnav__archive__list__item"><a href="#" class="header__subnav__archive__list__item__link">Bundestag 2013 – 2017</a></li>
            <li class="header__subnav__archive__list__item"><a href="#" class="header__subnav__archive__list__item__link">Bundestag 2013 – 2017</a></li>
            <li class="header__subnav__archive__list__item"><a href="#" class="header__subnav__archive__list__item__link">Bundestag 2013 – 2017</a></li>
          </ul>
        </div>
        <nav class="contextual-links-region swiper-container-horizontal">
          <ul class="nav nav--main-menu nav--main-menu--level-3">
            <li class="nav__item"><a href="/bundestag/profile" title="" class="nav__item__link">Abgeordnete</a></li>
            <li class="nav__item"><a href="/bundestag/abstimmungen" title="" class="nav__item__link">Abstimmungen</a></li>
            <li class="nav__item"><a href="/bundestag/wahlprogramme" title="" class="nav__item__link">Wahlprogramme</a></li>
            <li class="nav__item"><a href="/bundestag/wahlrecht-2017" title="" class="nav__item__link">Wahlrecht</a></li>
          </ul>
        </nav>
      </div>
    </div>

  </header>
  <?php print $messages; ?>



  <main id="content">
    <a id="main-content"></a>





    <br><br><br><br><br>

    <div class="lp-header contextual-links-region">
      <div class="lp-header__left">
        <i class="icon icon-de"></i>
      </div>
      <div class="lp-header__right">
        <h2>Finden Sie Ihre <span>Kandidierenden</span></h2>
        <form action="/bundestag/profile" method="get" accept-charset="UTF-8" class="form form--pw-globals-politician-search-form">
          <div class="form__item form__item--textfield form__item--keys">
            <label class="form__item__label sr-only" for="edit-keys">Schlagwörter</label>
            <input data-autosuggest-url="profiles/26909/candidates/autocomplete" placeholder="PLZ oder Namen eingeben" type="text" id="edit-keys" name="keys" value="" size="60" maxlength="128" class="form__item__control" />
            <div class="tt-menu tt-menu--custom">
              <div class="autosuggest__item--separator">
                Für die PLZ <strong>'41238'</strong> konnten Politiker in folgenden Parliamenten gefunden werden:
              </div>
              <div class="autosuggest__item">
                <div class="autosuggest__item__info">
                  <div class="autosuggest__item__name">Bundestag</div>
                </div>
                <a href="https://abgeordnetenwatch.de/profile/holger-hexgen#block-pw-dialogues-profile" class="btn--small">Zu den Politikern</a>
              </div>
              <div class="autosuggest__item">
                <div class="autosuggest__item__info">
                  <div class="autosuggest__item__name">Landtag Nordrhein-Westfalen</div>
                </div>
                <a href="https://abgeordnetenwatch.de/profile/holger-hexgen#block-pw-dialogues-profile" class="btn--small">Zu den Politikern</a>
              </div>
              <div class="autosuggest__item">
                <div class="autosuggest__item__info">
                  <div class="autosuggest__item__name">EU-Parlament</div>
                </div>
                <a href="https://abgeordnetenwatch.de/profile/holger-hexgen#block-pw-dialogues-profile" class="btn--small">Zu den Politikern</a>
              </div>
            </div>
          </div>
          <button type="submit" id="edit-submit" name="op" class="btn"><i class="icon icon-search"></i></button></form>
        <p style="display: none"><a href="#" class="link-icon" data-geolocate><i class="icon icon-map-marker"></i> Use my current location</a></p>
      </div>
      <div class="lp-header__bg"></div>
    </div>

    <!-- Filter: Summary -->

    <div class="intro">
      <h1>Abgeordnete</h1>
    </div>
    <div class="filterbar filterbar--disabled">
      <div class="container">
        <div class="filterbar__pre_swiper">
          <div class="filterbar__item filterbar__item--label">
            <i class="icon icon-investigation"></i> <?php print t('Filter') ?>
          </div>
          <div class="filterbar__item filterbar__item--input">
            <label for="filter_textsearch" class="sr-only"></label>
            <input type="text" id="filter_textsearch" class="form__item__control" placeholder="Volltextsuche">
            <button class="btn"><i class="icon icon-search"></i></button>
          </div>
        </div>
        <div class="filterbar__swiper">
          <div class="filterbar__swiper__inner">
            <div class="filterbar__item filterbar__item--checkbox">
              <div class="form__item--checkbox">
                <input type="checkbox" class="form__item__control" id="filter_vote_behavior_yes"> <label for="filter_vote_behavior_yes">Angenommen</label>
              </div>
              <div class="form__item--checkbox">
                <input type="checkbox" class="form__item__control" id="filter_vote_behavior_no"> <label for="filter_vote_behavior_no">Abgelehnt</label>
              </div>
            </div>
            <div class="filterbar__item filterbar__item--dropdown dropdown">
              <a href="#" class="dropdown__trigger">Politikfeld <i class="icon icon-arrow-down"></i></a>
              <div class="dropdown__list">
                test
              </div>
            </div>
            <div class="filterbar__item filterbar__item--dropdown dropdown">
              <a href="#" class="dropdown__trigger">Zeitraum <i class="icon icon-arrow-down"></i></a>
              <div class="dropdown__list">
                test
              </div>
            </div>
          </div>
          <div class="swiper-button-prev"></div>
          <div class="swiper-button-next"></div>
        </div>
        <ul class="filterbar__view_options">
          <li class="filterbar__view_options__item filterbar__view_options__item--active"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-th"></i></a></li>
          <li class="filterbar__view_options__item"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-th-list"></i></a></li>
        </ul>
      </div>
    </div>

    <div class="tile-wrapper">
      <div class="filter-summary">
        <div class="filter-summary__content">
          <p>Sie sehen 1320 Kandidierende aus 12 Parteien und 184 Wahlkreisen</p>
        </div>
        <p><strong><?php print t('Sorted by'); ?>:</strong> <?php print t('Response behavior descending'); ?></p>
      </div>

      <div class="filter-summary">
        <div class="filter-summary__content">
          <p class="filter-summary__content__mobile"><?php print t('You can see'); ?> 650 <?php print t('candidates after filtering by'); ?>:</p>
          <p><span>Sie sehen 650 </span><a href="#" class="filter-summary__content__link">männliche</a><span> Kandidierende aus 12 Parteien und 184 Wahlkreisen</span></p>
          <a href="#" class="btn"><i class="icon icon-close"></i> <?php print t('Reset filter'); ?></a>
        </div>
        <p><strong><?php print t('Sorted by'); ?>:</strong> <?php print t('Response behavior descending'); ?></p>
      </div>

      <div class="filter-summary">
        <div class="filter-summary__content">
          <p class="filter-summary__content__mobile"><?php print t('You can see'); ?> 650 <?php print t('candidates after filtering by'); ?>:</p>
          <p><span>Sie sehen 650 </span><a href="#" class="filter-summary__content__link">männliche</a><span> Kandidierende aus </span><a href="#" class="filter-summary__content__link">3 Parteien</a><span> und 184 Wahlkreisen</span></p>
          <a href="#" class="btn"><i class="icon icon-close"></i> <?php print t('Reset filter'); ?></a>
        </div>
        <p><strong><?php print t('Sorted by'); ?>:</strong> <?php print t('Response behavior descending'); ?></p>
      </div>

      <div class="filter-summary">
        <div class="filter-summary__content">
          <p class="filter-summary__content__mobile"><?php print t('You can see'); ?> 650 <?php print t('candidates after filtering by'); ?>:</p>
          <p><span>Sie sehen 650 </span><a href="#" class="filter-summary__content__link">männliche</a><span> Kandidierende im Alter zwischen </span><a href="#" class="filter-summary__content__link">30 - 35 Jahre</a><span> aus </span><a href="#" class="filter-summary__content__link">3 Parteien</a><span> und 184 Wahlkreisen</span></p>
          <a href="#" class="btn"><i class="icon icon-close"></i> <?php print t('Reset filter'); ?></a>
        </div>
        <p><strong><?php print t('Sorted by'); ?>:</strong> <?php print t('Response behavior descending'); ?></p>
      </div>

      <div class="filter-summary">
        <div class="filter-summary__content">
          <p class="filter-summary__content__mobile"><?php print t('You can see'); ?> 650 <?php print t('candidates after filtering by'); ?>:</p>
          <p><span>Sie sehen 6 Kandidierende aus 2 Fraktionen, 5 Wahlkreisen, 3 Listenplätze, entsprechend der Suchanfrage:</span> <a href="#" class="filter-summary__content__link">"Katja"</a></p>
          <a href="#" class="btn"><i class="icon icon-close"></i> <?php print t('Reset filter'); ?></a>
        </div>
        <p><strong><?php print t('Sorted by'); ?>:</strong> <?php print t('Response behavior descending'); ?></p>
      </div>

      <div class="tile poll">
        <div class="tile__image">
          <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
        </div>
        <div class="tile__date">10.11.2016</div>
        <div class="tile__pollchart">
          <div class="tile__pollchart__value_left won">351</div>
          <div class="tile__pollchart__statistic">
            <div class='d3 d3--donut'
                 data-d3-donut-icon
                 data-data='[{"name":"Ja","count":63,"color":"#9fd773"},{"name":"Nein","count":24,"color":"#cc6c5b"},{"name":"Enthalten","count":8,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
            </div>
          </div>
          <div class="tile__pollchart__value_right">231</div>
        </div>
        <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
        <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
        <ul class="tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
        </ul>
      </div>
      <div class="tile poll">
        <div class="tile__image">
          <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
        </div>
        <div class="tile__date">10.11.2016</div>
        <div class="tile__pollchart">
          <div class="tile__pollchart__value_left won">351</div>
          <div class="tile__pollchart__statistic">
            <div class='d3 d3--donut'
                 data-d3-donut-icon
                 data-data='[{"name":"Ja","count":24,"color":"#9fd773"},{"name":"Nein","count":63,"color":"#cc6c5b"},{"name":"Enthalten","count":8,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
            </div>
          </div>
          <div class="tile__pollchart__value_right">231</div>
        </div>
        <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
        <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
        <ul class="tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
        </ul>
      </div>
      <div class="tile poll">
        <div class="tile__image">
          <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
        </div>
        <div class="tile__date">10.11.2016</div>
        <div class="tile__pollchart">
          <div class="tile__pollchart__value_left won">351</div>
          <div class="tile__pollchart__statistic">
            <div class='d3 d3--donut'
                 data-d3-donut-icon
                 data-data='[{"name":"Ja","count":8,"color":"#9fd773"},{"name":"Nein","count":24,"color":"#cc6c5b"},{"name":"Enthalten","count":63,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
            </div>
          </div>
          <div class="tile__pollchart__value_right">231</div>
        </div>
        <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
        <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
        <ul class="tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
        </ul>
      </div>
    </div>


    <div class="intro">
      <h1>Abgeordnete</h1>
    </div>
    <div class="filterbar filterbar--disabled">
      <div class="container">
        <div class="filterbar__pre_swiper">
          <div class="filterbar__item filterbar__item--label">
            <i class="icon icon-investigation"></i> <?php print t('Filter') ?>
          </div>
          <div class="filterbar__item filterbar__item--input">
            <label for="filter_textsearch" class="sr-only"></label>
            <input type="text" id="filter_textsearch" class="form__item__control" placeholder="Volltextsuche">
            <button class="btn"><i class="icon icon-search"></i></button>
          </div>
        </div>
        <div class="filterbar__swiper">
          <div class="filterbar__swiper__inner">
            <div class="filterbar__item filterbar__item--checkbox">
              <div class="form__item--checkbox">
                <input type="checkbox" class="form__item__control" id="filter_vote_behavior_yes"> <label for="filter_vote_behavior_yes">Angenommen</label>
              </div>
              <div class="form__item--checkbox">
                <input type="checkbox" class="form__item__control" id="filter_vote_behavior_no"> <label for="filter_vote_behavior_no">Abgelehnt</label>
              </div>
            </div>
            <div class="filterbar__item filterbar__item--dropdown dropdown">
              <a href="#" class="dropdown__trigger">Politikfeld <i class="icon icon-arrow-down"></i></a>
              <div class="dropdown__list">
                test
              </div>
            </div>
            <div class="filterbar__item filterbar__item--dropdown dropdown">
              <a href="#" class="dropdown__trigger">Zeitraum <i class="icon icon-arrow-down"></i></a>
              <div class="dropdown__list">
                test
              </div>
            </div>
          </div>
          <div class="swiper-button-prev"></div>
          <div class="swiper-button-next"></div>
        </div>
        <ul class="filterbar__view_options">
          <li class="filterbar__view_options__item filterbar__view_options__item--active"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-th"></i></a></li>
          <li class="filterbar__view_options__item"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-th-list"></i></a></li>
        </ul>
      </div>
    </div>

    <div class="tile-wrapper">
      <div class="constituency-selection">
        <p><?php print t('The zip-code you searched for, shows candidates from multiple constituencies:') ?></p>
        <div class="tile constituency-selection__item">
          <div class="tile__title mh-item">
            Berlin - Charlottenburg-Wilmersdorf
          </div>
          <a href="#" class="btn btn--small"><?php print t('Select constituency') ?></a>
        </div>
        <div class="tile constituency-selection__item">
          <div class="tile__title mh-item">
            Berlin - Tempelhof-Schöneberg
          </div>
          <a href="#" class="btn btn--small"><?php print t('Select constituency') ?></a>
        </div>
      </div>
    </div>


    <!-- Landingpage: Bundestag -->

    <div class="donate-teaser">
      <p>Unseren <span id="mscount">4000</span> Förderern stehen 6.000 Lobbyisten in Berlin gegenüber. <br> Mit Ihrer Hilfe wollen wir geheimen Lobbyismus stoppen – sind Sie dabei?</p>
      <a href="#" class="btn"><?php print t('Support us') ?></a>
    </div>

    <div class="tile-wrapper">
      <header class="option-title">
        <h2><?php print t('New blog entries') ?></h2>
        <?php print l(t('Blog Overview'), 'bundestag/abstimmungen', ['attributes' => ['class' => ['btn']]]); ?>
      </header>

      <article id="#" class="blog tile mh-item">
        <div class="tile__image">
          <img src="http://localhost:8080/sites/default/files/styles/large/public/bundestag-280px.jpg?itok=6JaX5vum" width="480" height="300">
        </div>
        <header class="tile__title tile__title--date">
          <span class="date"><span class="date__day">22</span><span class="date__month">Jun</span><span class="date__year">2017</span></span>
          <h3><a href="/blog/2017-06-19/der-traum-vom-bundestag">Der Traum vom Bundestag: Was Einzelbewerber antreibt</a></h3>
        </header>
        <ul class="tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">0 Kommentare</a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
        </ul>
      </article>

      <div class="small-tiles mh-item">
        <article id="#" class="blog tile">
          <div class="tile__image">
            <img src="http://localhost:8080/sites/default/files/styles/large/public/bundestag-280px.jpg?itok=6JaX5vum" width="480" height="300">
          </div>
          <header class="tile__title tile__title--date mh-item">
            <span class="date"><span class="date__day">22</span><span class="date__month">Jun</span><span class="date__year">2017</span></span>
            <h3><a href="/blog/2017-06-19/der-traum-vom-bundestag">Der Traum vom Bundestag: Was Einzelbewerber antreibt</a></h3>
          </header>
          <ul class="tile__links tile__links--2">
            <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">0 Kommentare</a></li>
            <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
          </ul>
        </article>
        <article id="#" class="blog tile">
          <div class="tile__image">
            <img src="http://localhost:8080/sites/default/files/styles/large/public/bundestag-280px.jpg?itok=6JaX5vum" width="480" height="300">
          </div>
          <header class="tile__title tile__title--date mh-item">
            <span class="date"><span class="date__day">22</span><span class="date__month">Jun</span><span class="date__year">2017</span></span>
            <h3><a href="/blog/2017-06-19/der-traum-vom-bundestag">Der Traum vom Bundestag: Was Einzelbewerber antreibt</a></h3>
          </header>
          <ul class="tile__links tile__links--2">
            <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">0 Kommentare</a></li>
            <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
          </ul>
        </article>
      </div>

      <header class="option-title">
        <h2><?php print t('New polls') ?></h2>
        <?php print l(t('Poll Overview'), 'bundestag/abstimmungen', ['attributes' => ['class' => ['btn']]]); ?>
      </header>
      <div class="tile poll">
        <div class="tile__image">
          <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
        </div>
        <div class="tile__date">10.11.2016</div>
        <div class="tile__pollchart">
          <div class="tile__pollchart__value_left won">351</div>
          <div class="tile__pollchart__statistic">
            <div class='d3 d3--donut'
                 data-d3-donut-icon
                 data-data='[{"name":"Ja","count":63,"color":"#9fd773"},{"name":"Nein","count":24,"color":"#cc6c5b"},{"name":"Enthalten","count":8,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
            </div>
          </div>
          <div class="tile__pollchart__value_right">231</div>
        </div>
        <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
        <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
        <ul class="tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
        </ul>
      </div>
      <div class="tile poll">
        <div class="tile__image">
          <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
        </div>
        <div class="tile__date">10.11.2016</div>
        <div class="tile__pollchart">
          <div class="tile__pollchart__value_left won">351</div>
          <div class="tile__pollchart__statistic">
            <div class='d3 d3--donut'
                 data-d3-donut-icon
                 data-data='[{"name":"Ja","count":24,"color":"#9fd773"},{"name":"Nein","count":63,"color":"#cc6c5b"},{"name":"Enthalten","count":8,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
            </div>
          </div>
          <div class="tile__pollchart__value_right">231</div>
        </div>
        <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
        <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
        <ul class="tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
        </ul>
      </div>
      <div class="tile poll">
        <div class="tile__image">
          <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
        </div>
        <div class="tile__date">10.11.2016</div>
        <div class="tile__pollchart">
          <div class="tile__pollchart__value_left won">351</div>
          <div class="tile__pollchart__statistic">
            <div class='d3 d3--donut'
                 data-d3-donut-icon
                 data-data='[{"name":"Ja","count":8,"color":"#9fd773"},{"name":"Nein","count":24,"color":"#cc6c5b"},{"name":"Enthalten","count":63,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
            </div>
          </div>
          <div class="tile__pollchart__value_right">231</div>
        </div>
        <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
        <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
        <ul class="tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
        </ul>
      </div>
    </div>

    <div class="question-teaser-pre intro">
      <div class="intro__left">
        <h2><?php print t('Questions & answer') ?></h2>
        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Aliquid architecto beatae consectetur
          exercitationem facilis labore, molestiae nostrum placeat possimus quo reiciendis sequi sint velit veritatis,
          voluptatum. In praesentium provident sed?</p>
      </div>
      <div class="intro__right">
        <a href="#" class="btn btn--mobile-block"><?php print t('Questions overview') ?></a>
      </div>
    </div>
    <div class="tile-wrapper question-teaser">

      <div class="qa-stats">
        <div class="qa-stats__col">
          <div class="hstats__item hstats__item--donut-digit">
            <div class="hstats__item__display mh-item-nr" data-mh="qa_hstats">
        <span class="d3 d3--gauge"
              data-d3-gauge
              data-percentage="<?php print $answer_ratio ?>"
              data-track-width="16"
              data-track-colour="f6997a"
              data-fill-colour="ffffff"
              data-text-colour="ffffff"
              data-stroke-colour="f68a66"
              data-stroke-spacing="2">
          <span>%</span>
        </span>
            </div>
            <div class="hstats__item__label mh-item-nr" data-mh="qa_hstats">
              <?php print t('@answers of total<br>@questions questions answered', ['@answers' => $answers, '@questions' => $questions]); ?>
            </div>
          </div>
          <div class="hstats__item hstats__item--digit">
            <span class="hstats__item__display mh-item-nr" data-mh="qa_hstats">5</span>
            <span class="hstats__item__label mh-item-nr" data-mh="qa_hstats"><?php print t('Questioner per question') ?></span>
          </div>
        </div>
        <div class="qa-stats__col">
          <div class="hstats__item hstats__item--digit">
            <span class="hstats__item__display mh-item-nr" data-mh="qa_hstats"><?php print $average_response_time; ?></span>
            <span class="hstats__item__label mh-item-nr" data-mh="qa_hstats"><?php print t('average time to answer') ?></span>
          </div>
        </div>
        <div class="qa-stats__col--large">
          <strong><?php print t('Questions by category') ?></strong>
          <!-- <span class='d3 d3--bars-vertical'
                data-d3-bars-vert
                data-data='parseDialogues'
                data-height='100'
                data-fill-colour='ffffff'
                data-stroke-colour='f68a66'>
            <span class="tooltip d3__tooltip"></span>
          </span> -->
        </div>
      </div>

      <div class="question tile">
        <div class="question__meta tile__meta">
          <a href="#" class="quesion__meta__tag tile__meta__tag">#lorem</a>
          <span class="question__meta__date tile__meta__date">01.01.2017</span>
        </div>
        <div class="question__question mh-item-tile" data-mh="questionTitle">
          <h3 class="question__question__title">Sind Sie [...] der Überzeugung, daß die "laufende Kamera" seinerzeit [...] die Wahrheitsfindung irgendwie beeinflußt haben könnte?</h3>
          <p class="question__question__author"><?php print t('By'); ?>: Wilfried Meißner</p>
        </div>
        <div class="question__answer mh-item-tile" data-mh="questionAnswer">
          <p class="question__answer__author"><img src="http://via.placeholder.com/100x100" alt="" class="question__answer__author__image"> Antwort von <strong>Max Mustermann</strong></p>
          <p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores ... rebum.</p>
        </div>
        <ul class="question__links tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#fragen">12 <?php print t('questioner'); ?></a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#"><?php print t('details'); ?></a></li>
        </ul>
      </div>
      <div class="question tile">
        <div class="question__meta tile__meta">
          <a href="#" class="quesion__meta__tag tile__meta__tag">#lorem</a>
          <span class="question__meta__date tile__meta__date">01.01.2017</span>
        </div>
        <div class="question__question mh-item-tile" data-mh="questionTitle">
          <h3 class="question__question__title">Sind Sie [...] der Überzeugung, daß die "laufende Kamera" seinerzeit [...] die Wahrheitsfindung irgendwie beeinflußt haben könnte?</h3>
          <p class="question__question__author"><?php print t('By'); ?>: Wilfried Meißner</p>
        </div>
        <div class="question__answer mh-item-tile" data-mh="questionAnswer">
          <p class="question__answer__author"><img src="http://via.placeholder.com/100x100" alt="" class="question__answer__author__image"> Antwort von <strong>Max Mustermann</strong></p>
          <p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores ... rebum.</p>
        </div>
        <ul class="question__links tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#fragen">12 <?php print t('questioner'); ?></a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#"><?php print t('details'); ?></a></li>
        </ul>
      </div>
      <div class="question tile">
        <div class="question__meta tile__meta">
          <a href="#" class="quesion__meta__tag tile__meta__tag">#lorem</a>
          <span class="question__meta__date tile__meta__date">01.01.2017</span>
        </div>
        <div class="question__question mh-item-tile" data-mh="questionTitle">
          <h3 class="question__question__title">Sind Sie [...] der Überzeugung, daß die "laufende Kamera" seinerzeit [...] die Wahrheitsfindung irgendwie beeinflußt haben könnte?</h3>
          <p class="question__question__author"><?php print t('By'); ?>: Wilfried Meißner</p>
        </div>
        <div class="question__answer mh-item-tile" data-mh="questionAnswer">
          <p class="question__answer__author"><img src="http://via.placeholder.com/100x100" alt="" class="question__answer__author__image"> Antwort von <strong>Max Mustermann</strong></p>
          <p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores ... rebum.</p>
        </div>
        <ul class="question__links tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#fragen">12 <?php print t('questioner'); ?></a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#"><?php print t('details'); ?></a></li>
        </ul>
      </div>
      <div class="question tile">
        <div class="question__meta tile__meta">
          <a href="#" class="quesion__meta__tag tile__meta__tag">#lorem</a>
          <span class="question__meta__date tile__meta__date">01.01.2017</span>
        </div>
        <div class="question__question mh-item-tile" data-mh="questionTitle">
          <h3 class="question__question__title">Sind Sie [...] der Überzeugung, daß die "laufende Kamera" seinerzeit [...] die Wahrheitsfindung irgendwie beeinflußt haben könnte?</h3>
          <p class="question__question__author"><?php print t('By'); ?>: Wilfried Meißner</p>
        </div>
        <div class="question__answer mh-item-tile" data-mh="questionAnswer">
          <p class="question__answer__author"><img src="http://via.placeholder.com/100x100" alt="" class="question__answer__author__image"> Antwort von <strong>Max Mustermann</strong></p>
          <p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores ... rebum.</p>
        </div>
        <ul class="question__links tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#fragen">12 <?php print t('questioner'); ?></a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#"><?php print t('details'); ?></a></li>
        </ul>
      </div>
      <ul class="pager">
        <li class="pager__next">
          <a title="Zur nächsten Seite" href="/eu/abstimmungen?page=1">weiter</a></li>
      </ul>
    </div>








    <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>

    <!-- Abstimmung: Detail-Ansicht -->
    <div class="intro">
      <div class="container">
        <div class="row">
          <div class="intro__left">
            <h1>Bundeswehreinsatz in Afghanistan</h1>
            <div class="intro__date">
              <span class="date__day">15</span>
              <span class="date__month">Dez</span>
              <span class="date__year">2016</span>
            </div>
            <p>Der Bundestag hat einem Antrag der Bundesregierung zur Fortsetzung des Bundeswehreinsatzes in Afghanistan zugestimmt. Das Mandat läuft bis zum 31. Dezember 2017.</p>
            <a href="#poll-content" class="link-icon" data-localScroll><i class="icon icon-arrow-right"></i> Weiterlesen</a>
          </div>
          <div class="intro__right">
            <div class="poll_overview">
              <div class="poll_overview__primary">
                <div class="poll_overview__primary__item">
                  <div class="poll_overview__primary__label"><?php print t('Accepeted') ?></div>
                  <div class="poll_overview__primary__value">467</div>
                </div>
                <div class="poll_overview__primary__item">
                  <div class="poll_overview__primary__label"><?php print t('Denied') ?></div>
                  <div class="poll_overview__primary__value">168</div>
                </div>
                <i class="icon icon-ok"></i>
              </div>
              <div class="poll_overview__secondary">
                <div class="row">
                  <div class="poll_overview__secondary__item">
                    <div class="poll_overview__secondary__label"><?php print t('Abstentions') ?></div>
                    <div class="poll_overview__secondary__value">9</div>
                  </div>
                  <div class="poll_overview__secondary__item">
                    <div class="poll_overview__secondary__label"><?php print t('Not matched') ?></div>
                    <div class="poll_overview__secondary__value">53</div>
                  </div>
                  <div class="poll_overview__secondary__item">
                    <div class="poll_overview__secondary__label"><?php print t('Invalid') ?></div>
                    <div class="poll_overview__secondary__value">-</div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="poll_detail poll detail" data-poll-id="123456">
      <div class="filterbar">
        <div class="container">
          <div class="filterbar__pre_swiper">
            <div class="filterbar__item filterbar__item--label">
              <i class="icon icon-investigation"></i> <?php print t('Filter') ?>
            </div>
            <div class="filterbar__item filterbar__item--input">
              <label for="filter_textsearch" class="sr-only"></label>
              <input type="text" id="filter_textsearch" class="form__item__control" placeholder="<?php print t('Zip code or name of politician') ?>">
              <button class="btn"><i class="icon icon-search"></i></button>
            </div>
          </div>
          <div class="filterbar__swiper">
            <div class="filterbar__swiper__inner">
              <div class="filterbar__item filterbar__item--checkbox">
                <div class="form__item--checkbox">
                  <label for="filter_vote_behavior_accepeted"><input type="checkbox" class="form__item__control" id="filter_vote_behavior_accepeted"> <?php print t('Accepeted') ?></label>
                  <label for="filter_vote_behavior_denied"><input type="checkbox" class="form__item__control" id="filter_vote_behavior_denied"> <?php print t('Denied') ?></label>
                  <label for="filter_vote_behavior_abstentions"><input type="checkbox" class="form__item__control" id="filter_vote_behavior_abstentions"> <?php print t('Abstentions') ?></label>
                </div>
              </div>
              <div class="filterbar__item filterbar__item--dropdown dropdown">
                <a href="#" class="dropdown__trigger"><?php print t('Political field') ?> <i class="icon icon-arrow-down"></i></a>
                <div class="dropdown__list">
                  test
                </div>
              </div>
              <div class="filterbar__item filterbar__item--dropdown dropdown">
                <a href="#" class="dropdown__trigger"><?php print t('Politician age') ?> <i class="icon icon-arrow-down"></i></a>
                <div class="dropdown__list">
                  test
                </div>
              </div>
            </div>
            <div class="swiper-button-prev"></div>
            <div class="swiper-button-next"></div>
          </div>
          <ul class="filterbar__view_options">
            <li class="filterbar__view_options__item filterbar__view_options__item--active"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-th-list"></i></a></li>
            <!-- <li class="filterbar__view_options__item"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-plenum"></i></a></li> -->
            <li class="filterbar__view_options__item"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-bar-chart"></i></a></li>
            <!-- <li class="filterbar__view_options__item"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-de"></i></a></li> -->
          </ul>
        </div>
      </div>
      <div class="container">
        <!-- <div class="poll_detail__chart">

          <div class="poll_detail__chart__total">
            <span class='d3 d3--bars-poll-total' data-d3-poll-total></span>
          </div>
          <div class="poll_detail__chart__party"></div>

        </div> -->
        <div class="poll_detail__table">
          <table cellpadding="0" cellspacing="0" class="table table--sortable table--poll-votes">
            <thead>
            <tr>
              <th class="poll_detail__table__item__picture"></th>
              <th class="poll_detail__table__item__name" data-sort="string"><?php print t('Customer') ?></th>
              <th class="poll_detail__table__item__fraction" data-sort="string"><?php print t('Fraction') ?></th>
              <th class="poll_detail__table__item__constituency" data-sort="string"><?php print t('Constituency') ?></th>
              <th class="poll_detail__table__item__voting_behavior" data-sort="int"><?php print t('Voting behavior') ?></th>
            </tr>
            </thead>
            <tbody>
              <tr>
                <td class="poll_detail__table__item__picture"><span><img src="http://via.placeholder.com/150x150" alt=""></span></td>
                <td class="poll_detail__table__item__name">Dr. Gregor Gysi (63)</td>
                <td class="poll_detail__table__item__fraction"><span class="party-indicator">DIE LINKE</span></td>
                <td class="poll_detail__table__item__constituency">Berlin <i class="icon icon-arrow-right"></i> Berlin-Treptow-Köpenick</td>
                <td class="poll_detail__table__item__voting_behavior">Mit ‚Ja‘ abgestimmt <i class="icon icon-ok"></i></td>
              </tr>
              <tr>
                <td class="poll_detail__table__item__picture"><span><img src="http://via.placeholder.com/150x150" alt=""></span></td>
                <td class="poll_detail__table__item__name">Dr. Gregor Gysi (63)</td>
                <td class="poll_detail__table__item__fraction"><span class="party-indicator">DIE LINKE</span></td>
                <td class="poll_detail__table__item__constituency">Berlin <i class="icon icon-arrow-right"></i> Berlin-Treptow-Köpenick</td>
                <td class="poll_detail__table__item__voting_behavior">Mit ‚Ja‘ abgestimmt <i class="icon icon-ok"></i></td>
              </tr>
              <tr>
                <td class="poll_detail__table__item__picture"><span><img src="http://via.placeholder.com/150x150" alt=""></span></td>
                <td class="poll_detail__table__item__name">Dr. Gregor Gysi (63)</td>
                <td class="poll_detail__table__item__fraction"><span class="party-indicator">DIE LINKE</span></td>
                <td class="poll_detail__table__item__constituency">Berlin <i class="icon icon-arrow-right"></i> Berlin-Treptow-Köpenick</td>
                <td class="poll_detail__table__item__voting_behavior">Mit ‚Ja‘ abgestimmt <i class="icon icon-ok"></i></td>
              </tr>
              <tr>
                <td class="poll_detail__table__item__picture"><span><img src="http://via.placeholder.com/150x150" alt=""></span></td>
                <td class="poll_detail__table__item__name">Dr. Gregor Gysi (63)</td>
                <td class="poll_detail__table__item__fraction"><span class="party-indicator">DIE LINKE</span></td>
                <td class="poll_detail__table__item__constituency">Berlin <i class="icon icon-arrow-right"></i> Berlin-Treptow-Köpenick</td>
                <td class="poll_detail__table__item__voting_behavior">Mit ‚Ja‘ abgestimmt <i class="icon icon-ok"></i></td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
    </div>


    <div class="poll__timeline__container">
      <div class="poll__timeline">
        <h2>Die Abstimmung auf dem Zeitstrahl</h2>
        <div class="poll__timeline__inner">
          <div class="poll__timeline__item">
            <div class="poll__timeline__item__date">15.12.2016</div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
          </div>
          <div class="poll__timeline__item">
            <div class="poll__timeline__item__date">15.12.2016</div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
          </div>
          <div class="poll__timeline__item">
            <div class="poll__timeline__item__date">15.12.2016</div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="123456">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
          </div>
          <div class="poll__timeline__item">
            <div class="poll__timeline__item__date">15.12.2016</div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
            <div class="poll__timeline__item__poll" data-poll-id="#node->id">
              <span class="poll__timeline__item__poll__title">
                <i class="icon icon-ok"></i> Bekämpfung der Schwarzarbeit
              </span>
              <span class="poll__timeline__item__poll__result">
                <span class="poll__timeline__item__poll__result__accepted">Ja <strong>467</strong></span>
                <span class="poll__timeline__item__poll__result__denied">Nein <strong>467</strong></span>
                <i class="icon icon-ok"></i>
              </span>
            </div>
          </div>
        </div>
      </div>
    </div>

    <div id="poll-content" class="poll__content container">
      <div class="row">
        <div class="poll__content__left">
          <p>Mit den Stimmen der Unionsfraktion sowie von Abgeordneten der SPD und der Grünen hat sich der Bundestag mehrheitlich für einen
            <a href="">Regierungsantrag</a> zur Verlängerung des Bundeswehreinsatzes in Afghanistan ausgesprochen. Die Linksfraktion stimmte geschlossen gegen die Mandatsverlängerung.</p>
          <p>Oberstes Ziel des Bundeswehreinsatzes ist laut Bundesregierung die Stabilisierung der Sicherheitslage in Afghanistan. Bis zu 980 Soldatinnen und Soldaten sollen nach Afghanistan entsandt werden. Die einsatzbedingten Zusatzausgaben belaufen sich auf rund 269,2 Mio. Euro.</p>
          <p>Konkret ergeben sich aus dem Mandat die folgenden Aufgaben:</p>
          <ul>
            <li>Mitwirkung an der Führung der Mission Resolute Support in Afghanistan</li>
            <li>Ausbildung, Beratung und Unterstützung der afghanischen nationalen Verteidigungs- und Sicherheitskräfte</li>
            <li>Sicherung, Schutz und ggf. Evakuierung und Bergung militärischer und ziviler Kräfte</li>
            <li>taktischer Lufttransport und Verwundetenlufttransport</li>
            <li>Beitrag zur zivil-militärischen Zusammenarbeit.</li>
          </ul>
          <p>Die Linksfraktion kritisierte, dass der Bundeswehreinsatz in Afghanistan bisher nicht zum Frieden beigetragen habe und den Terror nicht bekämpfen könne. Vielmehr sei die Nato-Mission gescheitert und die militärische Lage derzeit von Anschlägen, Kämpfen und steigenden Opferzahlen geprägt. Der mit Nein-stimmende Teil der Fraktion B90/Die Grünen teilte diese Kritik und merkte zudem die Diskrepanz zwischen der Rückführung abgelehnter Asylbewerber und gleichzeitiger Fortsetzung der Nato-Mission an.</p>
        </div>
        <div class="poll__content__right">
          <div class="sidebar-box">
            <h3 class="sidebar-box__headline">Politikfeld <i class="icon icon-info" data-tooltip-content="<?php print t('tooltip-poll-political-field') ?>"></i></h3>
            <ul class="sidebar-box__tag_list">
              <li><a href="#" class="tag">Verteidigung</a></li>
              <li><a href="#" class="tag">Auswärtiges</a></li>
            </ul>
          </div>
          <div class="sidebar-box">
            <h3 class="sidebar-box__headline">Tags <i class="icon icon-info" data-tooltip-content="<?php print t('tooltip-poll-tags') ?>"></i></h3>
            <ul class="sidebar-box__tag_list">
              <li><a href="#" class="tag">Bundeswehreinsatz</a></li>
              <li><a href="#" class="tag">Afghanistan</a></li>
              <li><a href="#" class="tag">Nato-Einsatz</a></li>
            </ul>
          </div>
          <div class="sidebar-box">
            <h3 class="sidebar-box__headline">Drucksachen <i class="icon icon-info" data-tooltip-content="<?php print t('tooltip-poll-prints') ?>"></i></h3>
            <dl class="sidebar-box__link_list">
              <dt class="sidebar-box__link_list__title"><a href="#" target="_blank">Drucksache 18/10347 <i class="icon icon-external"></i></a></dt>
              <dd class="sidebar-box__link_list__description">Bundesregierung > Antrag</dd>
              <dt class="sidebar-box__link_list__title"><a href="#" target="_blank">Drucksache 18/10346 <i class="icon icon-external"></i></a></dt>
              <dd class="sidebar-box__link_list__description">Auswärtiger Ausschuss > Bericht, Beschlussempfehlung</dd>
            </dl>
          </div>
        </div>
      </div>

    </div>

    <div class="share">
      <div class="container">
        <h3><?php print t('Share this poll with your friends') ?></h3>
        <ul class="share__links">
          <li class="share__links__item share__links__item--facebook"><a class="share__links__item__link" href="#"><i class="icon icon-facebook"></i> <span>teilen</span></a></li>
          <li class="share__links__item share__links__item--twitter"><a class="share__links__item__link" href="#"><i class="icon icon-twitter"></i> <span>tweet</span></a></li>
          <li class="share__links__item share__links__item--whatsapp"><a class="share__links__item__link" href="#"><i class="icon icon-whatsapp"></i> <span>WhatsApp</span></a></li>
          <li class="share__links__item share__links__item--mail"><a class="share__links__item__link" href="#"><i class="icon icon-mail"></i> <span>e-mail</span></a></li>
        </ul>
      </div>
    </div>

    <div class="tile-wrapper poll__related">
      <div class="container">
        <h2><?php print t('Related polls') ?></h2>
        <div class="row">
          <div class="tile poll">
            <div class="tile__image">
              <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
            </div>
            <div class="tile__date">10.11.2016</div>
            <div class="tile__pollchart">
              <div class="tile__pollchart__value_left won">351</div>
              <div class="tile__pollchart__statistic">
                <div class='d3 d3--donut'
                     data-d3-donut-icon
                     data-data='[{"name":"Ja","count":63,"color":"#9fd773"},{"name":"Nein","count":24,"color":"#cc6c5b"},{"name":"Enthalten","count":8,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
                </div>
              </div>
              <div class="tile__pollchart__value_right">231</div>
            </div>
            <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
            <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
            <ul class="tile__links tile__links--2">
              <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
              <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
            </ul>
          </div>
          <div class="tile poll">
            <div class="tile__image">
              <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
            </div>
            <div class="tile__date">10.11.2016</div>
            <div class="tile__pollchart">
              <div class="tile__pollchart__value_left won">351</div>
              <div class="tile__pollchart__statistic">
                <div class='d3 d3--donut'
                     data-d3-donut-icon
                     data-data='[{"name":"Ja","count":24,"color":"#9fd773"},{"name":"Nein","count":63,"color":"#cc6c5b"},{"name":"Enthalten","count":8,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
                </div>
              </div>
              <div class="tile__pollchart__value_right">231</div>
            </div>
            <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
            <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
            <ul class="tile__links tile__links--2">
              <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
              <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
            </ul>
          </div>
          <div class="tile poll">
            <div class="tile__image">
              <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
            </div>
            <div class="tile__date">10.11.2016</div>
            <div class="tile__pollchart">
              <div class="tile__pollchart__value_left won">351</div>
              <div class="tile__pollchart__statistic">
                <div class='d3 d3--donut'
                     data-d3-donut-icon
                     data-data='[{"name":"Ja","count":8,"color":"#9fd773"},{"name":"Nein","count":24,"color":"#cc6c5b"},{"name":"Enthalten","count":63,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
                </div>
              </div>
              <div class="tile__pollchart__value_right">231</div>
            </div>
            <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
            <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
            <ul class="tile__links tile__links--2">
              <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
              <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
            </ul>
          </div>
        </div>
      </div>
    </div>

    <div class="poll__question_teaser">
      <div class="container">
        <div class="poll__question_teaser__content">
          <h2><?php print t('Your Voice') ?></h2>
          <p><?php print t('Questions & Answers by topic') ?> Verteidigung und Auswärtiges</p>
          <a class="btn btn--mobile-block"><?php print t('Question overview') ?></a>
        </div>
      </div>
    </div>
    <div class="tile-wrapper question-teaser">
      <div class="question tile">
        <div class="question__meta tile__meta">
          <a href="#" class="quesion__meta__tag tile__meta__tag">#lorem</a>
          <span class="question__meta__date tile__meta__date">01.01.2017</span>
        </div>
        <div class="question__question mh-item-tile" data-mh="questionTitle">
          <h3 class="question__question__title">Sind Sie [...] der Überzeugung, daß die "laufende Kamera" seinerzeit [...] die Wahrheitsfindung irgendwie beeinflußt haben könnte?</h3>
          <p class="question__question__author"><?php print t('By'); ?>: Wilfried Meißner</p>
        </div>
        <div class="question__answer mh-item-tile" data-mh="questionAnswer">
          <p class="question__answer__author">Antwort von <strong>Max Mustermann</strong></p>
          <p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores ... rebum.</p>
        </div>
        <ul class="question__links tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#fragen">12 <?php print t('questioner'); ?></a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#"><?php print t('details'); ?></a></li>
        </ul>
      </div>
      <div class="question tile">
        <div class="question__meta tile__meta">
          <a href="#" class="quesion__meta__tag tile__meta__tag">#lorem</a>
          <span class="question__meta__date tile__meta__date">01.01.2017</span>
        </div>
        <div class="question__question mh-item-tile" data-mh="questionTitle">
          <h3 class="question__question__title">Sind Sie [...] der Überzeugung, daß die "laufende Kamera" seinerzeit [...] die Wahrheitsfindung irgendwie beeinflußt haben könnte?</h3>
          <p class="question__question__author"><?php print t('By'); ?>: Wilfried Meißner</p>
        </div>
        <div class="question__answer mh-item-tile" data-mh="questionAnswer">
          <p class="question__answer__author">Antwort von <strong>Max Mustermann</strong></p>
          <p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores ... rebum.</p>
        </div>
        <ul class="question__links tile__links tile__links--2">
          <li class="tile__links__item"><a class="tile__links__item__link" href="#fragen">12 <?php print t('questioner'); ?></a></li>
          <li class="tile__links__item"><a class="tile__links__item__link" href="#"><?php print t('details'); ?></a></li>
        </ul>
      </div>
    </div>






    <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>

    <!-- Abstimmung: Kachel-Ansicht -->


    <div class="intro">
      <div class="container">
        <h1>Namentliche Abstimmungen im Bundestag</h1>
      </div>
    </div>
    <div class="tile-wrapper">
      <div class="filterbar">
        <div class="container">
          <div class="filterbar__pre_swiper">
            <div class="filterbar__item filterbar__item--label">
              <i class="icon icon-investigation"></i> <?php print t('Filter') ?>
            </div>
            <div class="filterbar__item filterbar__item--input">
              <label for="filter_textsearch" class="sr-only"></label>
              <input type="text" id="filter_textsearch" class="form__item__control" placeholder="Volltextsuche">
              <button class="btn"><i class="icon icon-search"></i></button>
            </div>
          </div>
          <div class="filterbar__swiper">
            <div class="filterbar__swiper__inner">
              <div class="filterbar__item filterbar__item--checkbox">
                <div class="form__item--checkbox">
                  <label for="filter_vote_behavior_yes"><input type="checkbox" class="form__item__control" id="filter_vote_behavior_yes"> Angenommen</label>
                  <label for="filter_vote_behavior_no"><input type="checkbox" class="form__item__control" id="filter_vote_behavior_no"> Abgelehnt</label>
                </div>
              </div>
              <div class="filterbar__item filterbar__item--dropdown dropdown">
                <a href="#" class="dropdown__trigger">Politikfeld <i class="icon icon-arrow-down"></i></a>
                <div class="dropdown__list">
                  test
                </div>
              </div>
              <div class="filterbar__item filterbar__item--dropdown dropdown">
                <a href="#" class="dropdown__trigger">Zeitraum <i class="icon icon-arrow-down"></i></a>
                <div class="dropdown__list">
                  test
                </div>
              </div>
            </div>
            <div class="swiper-button-prev"></div>
            <div class="swiper-button-next"></div>
          </div>
          <ul class="filterbar__view_options">
            <li class="filterbar__view_options__item filterbar__view_options__item--active"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-th"></i></a></li>
            <li class="filterbar__view_options__item"><a href="#" class="filterbar__view_options__item__link"><i class="icon icon-th-list"></i></a></li>
          </ul>
        </div>
      </div>

      <div class="container">
        <div class="row">
          <div class="tile poll">
            <div class="tile__image">
              <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
            </div>
            <div class="tile__date">10.11.2016</div>
            <div class="tile__pollchart">
              <div class="tile__pollchart__value_left won">351</div>
              <div class="tile__pollchart__statistic">
                <div class='d3 d3--donut'
                     data-d3-donut-icon
                     data-data='[{"name":"Ja","count":63,"color":"#9fd773"},{"name":"Nein","count":24,"color":"#cc6c5b"},{"name":"Enthalten","count":8,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
                </div>
              </div>
              <div class="tile__pollchart__value_right">231</div>
            </div>
            <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
            <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
            <ul class="tile__links tile__links--2">
              <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
              <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
            </ul>
          </div>
          <div class="tile poll">
            <div class="tile__image">
              <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
            </div>
            <div class="tile__date">10.11.2016</div>
            <div class="tile__pollchart">
              <div class="tile__pollchart__value_left won">351</div>
              <div class="tile__pollchart__statistic">
                <div class='d3 d3--donut'
                     data-d3-donut-icon
                     data-data='[{"name":"Ja","count":24,"color":"#9fd773"},{"name":"Nein","count":63,"color":"#cc6c5b"},{"name":"Enthalten","count":8,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
                </div>
              </div>
              <div class="tile__pollchart__value_right">231</div>
            </div>
            <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
            <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
            <ul class="tile__links tile__links--2">
              <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
              <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
            </ul>
          </div>
          <div class="tile poll">
            <div class="tile__image">
              <img typeof="foaf:Image" src="/sites/default/files/styles/large/public/bankenviertel_frankfurt.jpg" width="280" height="187" alt="#" title="#">
            </div>
            <div class="tile__date">10.11.2016</div>
            <div class="tile__pollchart">
              <div class="tile__pollchart__value_left won">351</div>
              <div class="tile__pollchart__statistic">
                <div class='d3 d3--donut'
                     data-d3-donut-icon
                     data-data='[{"name":"Ja","count":8,"color":"#9fd773"},{"name":"Nein","count":24,"color":"#cc6c5b"},{"name":"Enthalten","count":63,"color":"#e2e2e2"},{"name":"Nicht abgestimmt","count":2,"color":"#a6a6a6" }]'>
                </div>
              </div>
              <div class="tile__pollchart__value_right">231</div>
            </div>
            <h2 class="tile__title"><a href="#">Bundeswehreinsatzin Afghanistan</a></h2>
            <p class="tile__summary">Mit den Stimmen der Regierungskoalition hat der Bundestag ein Fortsetzung des Bundeswehreinsatzes gegen die Terrormiliz IS beschlossen.</p>
            <ul class="tile__links tile__links--2">
              <li class="tile__links__item"><a class="tile__links__item__link" href="#kommentare">12 Kommentare</a></li>
              <li class="tile__links__item"><a class="tile__links__item__link" href="#">Mehr anzeigen</a></li>
            </ul>
          </div>
        </div>
      </div>
    </div>




    <!-- Documentation -->

    <div class="container">
      <h1>Lorem ipsum dolor sit amet, consectetur adipisicing elit.</h1>
      <h2>Lorem ipsum dolor sit amet, consectetur adipisicing elit.</h2>
      <h3>Lorem ipsum dolor sit amet, consectetur adipisicing elit.</h3>
      <h4>Lorem ipsum dolor sit amet, consectetur adipisicing elit.</h4>
      <h5>Lorem ipsum dolor sit amet, consectetur adipisicing elit.</h5>
      <h6>Lorem ipsum dolor sit amet, consectetur adipisicing elit.</h6>
      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Adipisci aliquid debitis dolore doloremque earum
        eligendi est, fuga inventore minus nesciunt non omnis quas <strong>quia quis quos</strong> reiciendis sapiente tempore vel?</p>
      <p>Animi asperiores autem beatae corporis est ex incidunt libero maxime, natus nobis provident quas reprehenderit
        saepe tempora unde. At cum dolorum enim ipsum laudantium nostrum optio quae quod sapiente! Consectetur?</p>
      <p>Accusantium aliquid architecto <a href="#">autem earum enim</a> harum, nostrum perspiciatis placeat reprehenderit, ut veniam
        voluptas. Ab, animi assumenda dignissimos illum iure laudantium pariatur provident repellendus reprehenderit
        saepe sed soluta tempora voluptatibus.</p>
      <ul>
        <li>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Aperiam architecto autem culpa dignissimos dolor
          enim, eum exercitationem expedita illum incidunt laboriosam minima neque, nobis possimus quas repudiandae
          rerum sequi voluptates.
        </li>
        <li>Beatae, commodi debitis, explicabo fugiat fugit harum impedit in iure iusto laborum quidem quod sapiente
          sint, suscipit vel veniam voluptatibus. Aut cum esse et excepturi itaque maxime reiciendis sint veniam?
        </li>
        <li>Ad architecto aspernatur aut consectetur distinctio dolore dolorum est ex expedita facere laboriosam
          molestias nesciunt quis rem suscipit, voluptas voluptatem? Ad aperiam consequuntur minima quaerat quam
          quisquam reiciendis! Deserunt, ut?
        </li>
        <li>Aliquam atque dolorum ducimus eligendi error est ex harum, illo obcaecati praesentium suscipit vero. Alias
          consequatur consequuntur cupiditate earum esse minus, modi natus nobis porro praesentium qui quibusdam quidem
          similique.
        </li>
      </ul>


      <h1>Formulare</h1>
      <form action="" class="form">
        <div class="form__item">
          <input type="text" class="form__item__control" placeholder="Lorem ipsum">
        </div>
        <div class="form__item form__item--select">
          <select name="#" id="#" class="form__item__control" multiple="multiple" data-placeholder="Tags auswählen" data-width="100%">
            <option value="#">Tag 1</option>
            <option value="#">Tag 2</option>
            <option value="#">Tag 3</option>
            <option value="#">Tag 4</option>
            <option value="#">Tag 5</option>
          </select>
        </div>
        <div class="form__item form__item--select">
          <select name="#" id="#" class="form__item__control" data-placeholder="Tags auswählen" data-width="100%">
            <option value="#">Tag 1</option>
            <option value="#">Tag 2</option>
            <option value="#">Tag 3</option>
            <option value="#">Tag 4</option>
            <option value="#">Tag 5</option>
          </select>
        </div>
        <div class="form__item form__item--checkbox">
          <label for="filter_show_only_answered">
            <input name="filter_show_only_answered" id="filter_show_only_answered" class="form__item__control" type="checkbox">
            <?php print t('Nur beantwortete anzeigen') ?>
          </label>
        </div>
      </form>
    </div>

    <div class="container">
      <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    </div>
    <?php print render($page['content']); ?>




    <?php print $feed_icons; ?>
  </main>

  <footer id="footer">
    <div class="container">
      <div class="footer__maincol">
        <div class="footer__maincol__col">
          <strong><i class="icon icon-bundestag"></i> Bundestag</strong>
          <ul class="footer__maincol__col__nav">
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Abstimmungen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Abgeordnete</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Petitionen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Ausschüsse</a></li>
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Suffrage'), 'node/7752', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
          </ul>
        </div>
        <div class="footer__maincol__col">
          <strong><i class="icon icon-de"></i> Landtag</strong>
          <ul class="footer__maincol__col__nav">
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Baden-Württemberg</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Bayern</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Berlin</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Brandenburg</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Bremen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Hamburg</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Hessen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Mecklenburg-Vorpommern</a></li>
          </ul>
        </div>
        <div class="footer__maincol__col">
          <strong>&nbsp;</strong>
          <ul class="footer__maincol__col__nav">
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Niedersachsen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Nordrhein-Westfalen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Rheinland-Pfalz</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Saarland</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Sachsen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Sachsen-Anhalt</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Schleswig-Holstein</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Thüringen</a></li>
          </ul>
        </div>
        <div class="footer__maincol__col">
          <strong><i class="icon icon-de"></i> EU-Parlament</strong>
          <ul class="footer__maincol__col__nav">
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Abstimmungen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Abgeordnete</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Petitionen</a></li>
            <li class="footer__maincol__col__nav__item"><a href="#" class="footer__maincol__col__nav__item__link">Ausschüsse</a></li>
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Suffrage'), 'node/7754', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
          </ul>
        </div>
        <div class="footer__maincol__col">
          <strong><i class="icon icon-logo-aw"></i> Über das Projekt</strong>
          <ul class="footer__maincol__col__nav">
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('About us'), 'node/7760', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Board of Trustees'), 'node/7735', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Moderation Codex'), 'node/7734', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Financing'), 'node/7757', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Imprint'), 'node/7732', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
          </ul>
        </div>
        <div class="footer__maincol__col">
          <strong>&nbsp;</strong>
          <ul class="footer__maincol__col__nav">
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Support the project'), 'node/10508', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Get info material'), 'node/7747', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
            <li class="footer__maincol__col__nav__item">
              <?php print l( t('Privacy'), 'node/10006', array('attributes' => array('class' => array('footer__maincol__col__nav__item__link'))) ); ?>
            </li>
          </ul>
        </div>
      </div>
    </div>
    <div class="footer__mediapartner">
      <div class="container">
        <h3 class="footer__mediapartner__title">Medienpartner</h3>
        <a href="#" class="footer__mediapartner__link" title="Go to website of Spiegel Online"><img src="<?php print base_path() . path_to_theme(); ?>/images/medienpartner/logo_spon.png" alt="<?php print t('Logo of Spiegel Online'); ?>"></a>
        <a href="#" class="footer__mediapartner__link" title="Go to website of Süddeutsche"><img src="<?php print base_path() . path_to_theme(); ?>/images/medienpartner/logo_sueddeutsche.png" alt="<?php print t('Logo of Süddeutsche'); ?>"></a>
        <a href="#" class="footer__mediapartner__link" title="Go to website of WELT-Online"><img src="<?php print base_path() . path_to_theme(); ?>/images/medienpartner/logo_welt.png" alt="<?php print t('Logo of Welt-Online'); ?>"></a>
        <a href="#" class="footer__mediapartner__link" title="Go to website of Süddeutsche"><img src="<?php print base_path() . path_to_theme(); ?>/images/medienpartner/logo_t_online.png" alt="<?php print t('Logo of T-Online'); ?>"></a>
      </div>
    </div>
    <?php if ($logo): ?>
    <a class="footer__logo" href="<?php print $front_page; ?>" title="<?php print t('Back to home'); ?>" rel="home">
      <div class="svg-container">
        <svg viewBox="0 0 379.1 53.2"><path fill="#EC663B" d="M359.8 16.8c2.8 3 4.5 6.7 4.8 10.8h5.4c-.3-5.4-2.5-10.5-6.3-14.5-3.8-3.9-8.7-6.3-14-6.9l-.3 5.4c3.9.4 7.6 2.3 10.4 5.2zM347.2 6c-5.9 0-11.5 2.2-15.7 6.3l3.7 3.9c3.2-3.1 7.4-4.8 11.8-4.8l.2-5.4c.1 0 .1 0 0 0zm12.1 35.4l3.7 3.9c2-1.9 3.6-4.1 4.8-6.5l-5.2-1.7c-.9 1.5-2 3-3.3 4.3zM370 29.9h-5.4c-.1 1.7-.5 3.4-1.1 5l5.2 1.7c.7-2.2 1.2-4.4 1.3-6.7z"/><path fill="#EC663B" d="M355.1 24c.7 1.1 1.1 2.3 1.3 3.6h5.4c-.2-2.7-1.2-5.2-2.8-7.4l-3.9 3.8zm-1.5 11.6l3.7 3.9c2.7-2.5 4.2-5.9 4.5-9.6h-5.4c-.3 2.2-1.2 4.2-2.8 5.7zM337 18.2l3.7 3.9c1.6-1.5 3.7-2.4 5.9-2.6l.3-5.4c-3.7.1-7.2 1.6-9.9 4.1zm20.5.2c-2.3-2.2-5.1-3.6-8.2-4.1l-.3 5.4c1.8.3 3.4 1.2 4.7 2.4l3.8-3.7z"/><path fill="#FFF" d="M347.2 28.6l-.2.1h.2"/><path fill="#EC663B" d="M0 18.1V18c0-2.2.8-3.9 2.3-5.2s3.2-2 5-2.1h.8c1 0 2 .3 3 .7s1.7 1.1 2.3 2v-2.5H15v14.3h-1.6v-2.4c-.5.9-1.3 1.5-2.2 2-1 .4-1.9.7-3 .8H6.8c-1.7-.2-3.2-.9-4.7-2.1C.7 22.1 0 20.4 0 18.4V18.1c.1.1.1.1 0 0 .1 0 .1 0 0 0zm2.1-.4v.4c0 1.6.5 2.9 1.5 4s2.5 1.6 4.5 1.6c1.4 0 2.5-.5 3.5-1.5.9-1 1.5-2.2 1.6-3.4v-1.3c-.2-1.4-.7-2.5-1.7-3.4-.9-.9-2.1-1.3-3.7-1.4h-.3c-1.2 0-2.3.4-3.2 1.1-.9.7-1.5 1.6-1.9 2.5-.1.3-.2.5-.2.7s-.1.5-.1.7c0-.1 0-.1 0 0zM18.8 6h1.8v7.1c.6-.8 1.4-1.4 2.5-1.9 1-.5 2.1-.8 3.2-.8.3 0 .7 0 1 .1.3 0 .7.1 1 .2.6.2 1.2.4 1.7.7.6.3 1.1.7 1.6 1.3.6.6 1.1 1.3 1.4 2.2s.5 1.8.6 2.8v.8c0 1.2-.3 2.3-.9 3.4-.6 1.1-1.4 1.9-2.5 2.5-.4.2-.8.4-1.2.5-.4.1-.9.2-1.3.3-.2 0-.4.1-.6.1h-1.2c-1-.1-2-.3-3-.7-1-.4-1.8-1-2.4-1.7v2.4h-1.8V6h.1zm3 15.6c.8 1.2 2.2 1.9 4.3 1.9h.4c1.5-.1 2.8-.7 3.8-1.7s1.5-2.4 1.5-4.2c0-1.4-.6-2.7-1.8-3.8-1.2-1.1-2.5-1.7-3.9-1.7-.3 0-.7.1-1 .2-.4.1-.8.3-1.2.5-.8.4-1.6 1.1-2.2 1.9-.7.8-1 1.8-1 2.9-.1 1.4.3 2.8 1.1 4zm16.6-9c1.3-1.2 2.7-1.8 4.2-2h1c1.1 0 2.2.3 3.2.9 1 .5 1.7 1.2 2.2 2.1V11h2v12.3c0 2.4-.7 4.3-2.2 5.5s-3.1 1.8-4.9 1.8h-.4c-1.4-.1-2.8-.6-4.1-1.5s-2.2-2.2-2.7-3.9h1.8c.4 1.1 1.1 1.9 2 2.4s1.8.9 2.8.9h.6c1.3-.1 2.5-.5 3.6-1.5 1.1-.9 1.6-2.2 1.6-3.9v-.8c-.3.8-1 1.5-2.1 2-1.2.5-2.4.8-3.7.8h-1c-1.5-.2-2.9-.8-4.2-1.9s-1.9-2.8-1.9-5.1v-.4c.2-2.1.9-3.9 2.2-5.1zm0 4.9v.4c0 1.6.4 2.9 1.3 4s2.2 1.6 3.8 1.6c1.4 0 2.7-.4 3.8-1.3s1.7-2.4 1.7-4.6c0-1.3-.5-2.4-1.5-3.3-1-1-2.1-1.5-3.3-1.7h-.7c-1.1.1-2 .4-2.7.9s-1.2 1-1.6 1.6c-.3.5-.6.9-.7 1.4-.1.4-.2.8-.2 1 .1-.1.1-.1.1 0zm17.5-4.9c1.5-1.2 3-1.8 4.8-1.9h.4c1.8 0 3.4.7 4.9 1.9s2.2 3 2.2 5.4v.6H55.6c.2 1.7.8 2.9 1.8 3.6 1 .8 2 1.2 3.1 1.3h.8c1.1-.1 2.1-.4 3-.9.9-.6 1.6-1.3 1.8-2.1h2c-.6 1.6-1.5 2.9-2.7 3.6-1.2.8-2.5 1.2-3.8 1.2h-.5c-1.8 0-3.5-.7-5.1-2-1.5-1.3-2.3-3.1-2.4-5.3.1-2.4.9-4.2 2.3-5.4zm8.6 1.2c-.9-.9-2-1.4-3.4-1.5-1.2.1-2.2.4-2.9.9s-1.3 1-1.7 1.5c-.3.5-.6.9-.7 1.3-.1.4-.2.7-.3.9h10.8c-.3-1.2-1-2.2-1.8-3.1zm8-1.1c1.4-1.4 3.3-2.1 5.6-2.1 2 0 3.7.6 5.1 1.9s2 2.9 2 4.8c0 2.5-.7 4.4-2.1 5.8s-3.1 2.1-5.3 2.1c-2 0-3.8-.6-5.2-1.9-1.4-1.3-2.2-3.1-2.3-5.6.1-1.9.8-3.5 2.2-5zm1.4 9c.9 1 1.9 1.6 3 1.7H78c1.3-.1 2.5-.7 3.6-1.6 1.1-1 1.6-2.5 1.6-4.5 0-1.4-.5-2.5-1.6-3.4s-2.3-1.3-3.7-1.4h-.4c-1.4 0-2.6.5-3.6 1.5-.9 1-1.5 2.2-1.5 3.8.1 1.6.6 3 1.5 3.9zm14-10.9h1.8v1.9c.4-.7 1-1.3 1.6-1.6.7-.3 1.5-.5 2.5-.5v2.1c-.2 0-.4 0-.6.1-.2 0-.4.1-.6.2-.7.2-1.4.6-2 1.2-.6.6-.9 1.3-.9 2.2v8.8h-1.8V10.8zM98 12.4c1.4-1.1 2.9-1.7 4.6-1.8h1.3c.9.1 1.8.4 2.6.8.9.4 1.6 1 2.1 1.8V6h1.6v19.1h-1.6v-2.6c-.6.8-1.3 1.5-2.1 1.9-.8.4-1.7.7-2.6.8h-1c-1.8 0-3.5-.7-5-2s-2.3-3.1-2.3-5.4v-.5c.2-2.1 1-3.8 2.4-4.9zm-.6 4.9v.5c0 1.5.4 2.8 1.3 4s2.3 1.9 4.3 1.9h.5c.2 0 .3 0 .5-.1 1.1-.3 2.1-.9 3.1-1.9.9-1 1.4-2.3 1.4-3.8v-.3c0-.3 0-.6-.1-1s-.3-.8-.5-1.2c-.4-.7-.9-1.4-1.7-1.9-.8-.6-1.8-.9-3.2-.9-.3 0-.7 0-1 .1-.4.1-.8.2-1.2.4-.8.3-1.5.8-2.2 1.5s-1 1.6-1.1 2.6c-.1 0-.1 0-.1.1zm16.5-6.5h1.8v1.9c.4-.6 1-1 1.8-1.4.7-.3 1.5-.6 2.3-.7h.8c1.4 0 2.7.5 3.9 1.4 1.2.9 1.8 2.4 1.8 4.3v8.8h-1.9v-8.8c0-1.3-.4-2.3-1.3-3-.8-.7-1.8-1-2.8-1.1H119.7c-1.1 0-2 .4-2.9 1.1-.9.7-1.3 1.6-1.3 2.9v8.9h-1.8V10.8h.2zm17.5 1.8c1.5-1.2 3-1.8 4.8-1.9h.4c1.8 0 3.4.7 4.9 1.9s2.2 3 2.2 5.4v.6H131c.2 1.7.8 2.9 1.8 3.6 1 .8 2 1.2 3.1 1.3h.8c1.1-.1 2.1-.4 3-.9.9-.6 1.6-1.3 1.8-2.1h2c-.6 1.6-1.5 2.9-2.7 3.6-1.2.8-2.5 1.2-3.8 1.2h-.5c-1.8 0-3.5-.7-5.1-2-1.5-1.3-2.3-3.1-2.4-5.3.1-2.4.9-4.2 2.4-5.4zm8.5 1.2c-.9-.9-2-1.4-3.4-1.5-1.2.1-2.2.4-2.9.9s-1.3 1-1.7 1.5c-.3.5-.6.9-.7 1.3-.1.4-.2.7-.3.9h10.8c-.3-1.2-.9-2.2-1.8-3.1zm5.5-.9V11h2.8V6.2h1.8V11h3.3v1.9H150v12.2h-1.8V12.9h-2.8zm11.9-.3c1.5-1.2 3-1.8 4.8-1.9h.4c1.8 0 3.4.7 4.9 1.9s2.2 3 2.2 5.4v.6H157c.2 1.7.8 2.9 1.8 3.6 1 .8 2 1.2 3.1 1.3h.8c1.1-.1 2.1-.4 3-.9.9-.6 1.6-1.3 1.8-2.1h2c-.6 1.6-1.5 2.9-2.7 3.6-1.2.8-2.5 1.2-3.8 1.2h-.5c-1.8 0-3.5-.7-5.1-2-1.5-1.3-2.3-3.1-2.4-5.3.1-2.4.9-4.2 2.3-5.4zm8.6 1.2c-.9-.9-2-1.4-3.4-1.5-1.2.1-2.2.4-2.9.9s-1.3 1-1.7 1.5c-.3.5-.6.9-.7 1.3-.1.4-.2.7-.3.9h10.8c-.3-1.2-.9-2.2-1.8-3.1zm6.5-3h1.8v1.9c.4-.6 1-1 1.8-1.4.7-.3 1.5-.6 2.3-.7h.8c1.4 0 2.7.5 3.9 1.4s1.8 2.4 1.8 4.3v8.8H183v-8.8c0-1.3-.4-2.3-1.3-3-.8-.7-1.8-1-2.8-1.1h-.6c-1.1 0-2 .4-2.9 1.1-.9.7-1.3 1.6-1.3 2.9v8.9h-1.8V10.8h.1zM374.2 0l-22.4.1-19.3.9s-9.2-1-9.2 4.5-.4 17.7-.4 17.7v16.9c0 1.7-1.2 9.8 2.8 11.4 4 1.6 6.5 1.7 9.3 1.7s19.2-1.1 19.2-1.1h12.5s11.2 1.2 11.2-6.5.7-20.8.7-20.8l.2-14.1c.2 0 1.2-10.3-4.6-10.7zm.3 26.5c-.1 1.6-.5 15.2-.5 18.8s-3.2 3.3-3.2 3.3-7.8-.1-9.2 0c-1.3.1-9.7 0-19.2.2-9.6.2-12.4.1-14.7-1-2.3-1.1-1.3-6.5-1.5-9.4-.1-2.9-.6-10.2-.6-10.2l-.2-8.9v-4.2s.6-3.4.9-7 6-4.2 7.5-4.2 17.4-.6 17.4-.6 16.8-1 20-.9 2.9 3.9 2.9 3.9-.2 3.4-.2 7.8c-.2 4.5.7 10.8.6 12.4z"/><path fill="#575756" d="M194.5 25.1h-2.3L186.8 11h2l4.5 11.6 3.2-9.9h1.6l3.3 9.9 4.4-11.6h2.1l-5.3 14.1h-2.2l-3.1-8.8-2.8 8.8zm15.4-7V18c0-2.2.8-3.9 2.3-5.2s3.2-2 5-2.1h.8c1 0 2 .3 3 .7s1.7 1.1 2.3 2v-2.5h1.6v14.3h-1.6v-2.4c-.5.9-1.3 1.5-2.2 2-1 .4-1.9.7-3 .8h-1.4c-1.7-.2-3.2-.9-4.7-2.1-1.4-1.2-2.1-2.8-2.1-4.8V18.4c.1-.2.1-.2 0-.3.1 0 .1 0 0 0zm2.1-.4v.4c0 1.6.5 2.9 1.5 4s2.5 1.6 4.5 1.6c1.4 0 2.5-.5 3.5-1.5.9-1 1.5-2.2 1.6-3.4v-1.3c-.2-1.4-.7-2.5-1.7-3.4-.9-.9-2.1-1.3-3.7-1.4h-.3c-1.2 0-2.3.4-3.2 1.1-.9.7-1.5 1.6-1.9 2.5-.1.3-.2.5-.2.7s-.1.5-.1.7c0-.1 0-.1 0 0zm15.4-4.8V11h2.8V6.2h1.8V11h3.3v1.9H232v12.2h-1.8V12.9h-2.8zm12.2-.5c1.5-1.3 3.2-2 5.1-2h1c1.2.2 2.3.6 3.4 1.3 1.1.7 2 1.8 2.7 3.2h-2.2c-.4-.9-1.1-1.5-1.9-2-.9-.4-1.8-.6-2.8-.6h-.4c-.9.1-1.9.3-2.7.8-.9.4-1.5 1-1.8 1.8l-.3.6c-.1.2-.1.4-.2.6-.1.3-.2.6-.2.9-.1.3-.1.6-.1.9 0 .7.1 1.4.4 2 .3.6.6 1.2 1 1.6.2.2.5.4.7.6s.5.4.7.5c.5.3 1 .5 1.5.6s1 .2 1.4.2c1 0 2-.3 2.8-.8.9-.5 1.5-1.1 1.9-1.8 0 0 0-.1.1-.1l.1-.1h2.2c-.8 1.3-1.6 2.2-2.6 2.9-1 .7-2 1.2-3 1.4-.3.1-.5.1-.8.1h-.8c-1.9 0-3.7-.7-5.2-2.1s-2.3-3.1-2.3-5.3c0-2 .8-3.8 2.3-5.2zm15-6.4h1.8v6.7c.6-.7 1.2-1.2 1.9-1.5.7-.3 1.4-.5 2.1-.6h.4c1.6 0 3 .6 4.3 1.8s1.9 2.5 1.9 4v8.8h-2v-8.8c-.2-1.2-.7-2.2-1.5-2.8s-1.6-1-2.5-1.1h-.4c-1 0-2 .4-2.9 1.1-.9.7-1.3 1.7-1.3 3.1v8.6h-1.8V6zm16.6 15.7h2v3.4h-2v-3.4zm8.5-9.3c1.4-1.1 2.9-1.7 4.6-1.8h1.3c.9.1 1.8.4 2.6.8.9.4 1.6 1 2.1 1.8V6h1.6v19.1h-1.6v-2.6c-.6.8-1.3 1.5-2.1 1.9-.8.4-1.7.7-2.6.8h-1c-1.8 0-3.5-.7-5-2s-2.3-3.1-2.3-5.4v-.5c.1-2.1 1-3.8 2.4-4.9zm-.7 4.9v.5c0 1.5.4 2.8 1.3 4s2.3 1.9 4.3 1.9h.5c.2 0 .3 0 .5-.1 1.1-.3 2.1-.9 3.1-1.9.9-1 1.4-2.3 1.4-3.8v-.3c0-.3 0-.6-.1-1s-.3-.8-.5-1.2c-.4-.7-.9-1.4-1.7-1.9-.8-.6-1.8-.9-3.2-.9-.3 0-.7 0-1 .1-.4.1-.8.2-1.2.4-.8.3-1.5.8-2.2 1.5s-1 1.6-1.2 2.7c0-.1 0-.1 0 0zm18.3-4.7c1.5-1.2 3.1-1.8 4.8-1.9h.4c1.8 0 3.4.7 4.9 1.9s2.2 3 2.2 5.4v.6H297c.2 1.7.8 2.9 1.8 3.6 1 .8 2 1.2 3.1 1.3h.8c1.1-.1 2.1-.4 3-.9.9-.6 1.6-1.3 1.8-2.1h2c-.6 1.6-1.5 2.9-2.7 3.6-1.2.8-2.5 1.2-3.8 1.2h-.5c-1.8 0-3.5-.7-5.1-2-1.5-1.3-2.3-3.1-2.4-5.3 0-2.4.8-4.2 2.3-5.4zm8.6 1.2c-.9-.9-2-1.4-3.4-1.5-1.2.1-2.2.4-2.9.9-.7.5-1.3 1-1.7 1.5-.3.5-.6.9-.7 1.3-.1.4-.2.7-.3.9h10.8c-.4-1.2-1-2.2-1.8-3.1zM105.1 44l-1.3-4.2c-.1-.3-.2-.8-.5-1.7h-.1c-.2.8-.3 1.3-.5 1.7l-1.3 4.1h-1.2l-1.9-7.1h1.1c.5 1.8.8 3.1 1 4.1.2.9.4 1.6.4 1.9h.1c0-.2.1-.6.2-1s.2-.7.3-.9l1.3-4.1h1.2l1.3 4.1c.2.7.4 1.4.5 1.9h.1c0-.2.1-.4.1-.7.1-.3.5-2.1 1.3-5.2h1.1l-2 7.1h-1.2zm7.5.1c-1 0-1.9-.3-2.5-1-.6-.6-.9-1.5-.9-2.7 0-1.1.3-2 .8-2.7.6-.7 1.3-1 2.3-1 .9 0 1.6.3 2.1.9s.8 1.4.8 2.3v.7h-4.9c0 .8.2 1.5.6 1.9s1 .6 1.7.6c.8 0 1.5-.2 2.3-.5v1c-.4.2-.7.3-1.1.4-.3.1-.7.1-1.2.1zm-.3-6.4c-.6 0-1 .2-1.4.6-.3.4-.5.9-.6 1.5h3.7c0-.7-.2-1.2-.5-1.6s-.6-.5-1.2-.5zM117 35c0-.2.1-.4.2-.5.1-.1.3-.2.5-.2s.3.1.4.2c.1.1.2.3.2.5s-.1.4-.2.5-.3.2-.4.2c-.2 0-.3-.1-.5-.2s-.2-.2-.2-.5zm1.1 9H117v-7.1h1.1V44zm3.4 0h-1.1V34h1.1v10zm8-.7h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.4 0-2.1-.7-2.1-2.2v-4.2h-1v-.5l1-.4.5-1.5h.6V37h2.1v.8h-2.1V42c0 .4.1.8.3 1s.5.3.9.3zm5.6-6.5c.3 0 .6 0 .8.1l-.1 1c-.3-.1-.6-.1-.8-.1-.6 0-1.1.2-1.5.7-.4.5-.6 1-.6 1.7V44h-1.1v-7.1h.9l.1 1.3h.1c.3-.5.6-.8.9-1.1s.9-.3 1.3-.3zm6.5 7.2l-.2-1h-.1c-.4.4-.7.7-1.1.9-.4.2-.8.2-1.3.2-.7 0-1.3-.2-1.7-.5-.4-.4-.6-.9-.6-1.5 0-1.4 1.1-2.2 3.4-2.2h1.2v-.4c0-.6-.1-1-.4-1.2s-.6-.4-1.1-.4c-.6 0-1.3.2-2 .5l-.3-.8c.3-.2.7-.3 1.1-.4.4-.1.8-.2 1.3-.2.8 0 1.5.2 1.9.6.4.4.6 1 .6 1.8V44h-.7zm-2.4-.7c.7 0 1.2-.2 1.6-.5.4-.4.6-.9.6-1.5v-.6h-1.1c-.9 0-1.5.2-1.8.4s-.6.6-.6 1.1c0 .4.1.7.4.9s.5.2.9.2zm10.3.7v-4.6c0-.6-.1-1-.4-1.3-.3-.3-.7-.4-1.2-.4-.7 0-1.3.2-1.6.6-.3.4-.5 1.1-.5 2V44h-1.1v-7.1h.9l.2 1h.1c.2-.3.5-.6.9-.8s.8-.3 1.3-.3c.9 0 1.5.2 1.9.6.4.4.6 1.1.6 2V44h-1.1zm7.8-1.9c0 .7-.2 1.2-.7 1.5-.5.4-1.2.5-2.1.5-.9 0-1.7-.1-2.2-.4v-1c.3.2.7.3 1.1.4.4.1.8.1 1.1.1.6 0 1-.1 1.3-.3.3-.2.5-.5.5-.8 0-.3-.1-.5-.4-.7-.2-.2-.7-.4-1.4-.7-.7-.2-1.1-.5-1.4-.6s-.5-.4-.6-.6c-.1-.2-.2-.5-.2-.8 0-.6.2-1 .7-1.4.5-.3 1.1-.5 1.9-.5.8 0 1.5.2 2.2.5l-.4.9c-.7-.3-1.4-.4-1.9-.4s-.9.1-1.2.2c-.3.2-.4.4-.4.7 0 .2 0 .4.1.5.1.1.3.3.5.4.2.1.6.3 1.2.5.8.3 1.4.6 1.7.9.5.2.6.6.6 1.1zm5.1 2c-.5 0-.9-.1-1.3-.3s-.7-.4-1-.8h-.1c.1.4.1.8.1 1.2v2.9H159V36.9h.9l.1 1h.1c.3-.4.6-.7 1-.8s.8-.3 1.3-.3c.9 0 1.7.3 2.2 1 .5.6.8 1.5.8 2.7 0 1.2-.3 2.1-.8 2.7-.6.6-1.3.9-2.2.9zm-.2-6.4c-.7 0-1.2.2-1.6.6s-.5 1-.5 1.9v.2c0 1 .2 1.7.5 2.1.3.4.9.6 1.6.6.6 0 1.1-.2 1.4-.7s.5-1.2.5-2c0-.9-.2-1.6-.5-2-.3-.5-.8-.7-1.4-.7zm9.3 6.3l-.2-1h-.1c-.4.4-.7.7-1.1.9-.4.2-.8.2-1.3.2-.7 0-1.3-.2-1.7-.5-.4-.4-.6-.9-.6-1.5 0-1.4 1.1-2.2 3.4-2.2h1.2v-.4c0-.6-.1-1-.4-1.2s-.6-.4-1.1-.4c-.6 0-1.3.2-2 .5l-.3-.8c.3-.2.7-.3 1.1-.4.4-.1.8-.2 1.3-.2.8 0 1.5.2 1.9.6.4.4.6 1 .6 1.8V44h-.7zm-2.4-.7c.7 0 1.2-.2 1.6-.5.4-.4.6-.9.6-1.5v-.6h-1.1c-.9 0-1.5.2-1.8.4s-.6.6-.6 1.1c0 .4.1.7.4.9s.5.2.9.2zm8.7-6.5c.3 0 .6 0 .8.1l-.1 1c-.3-.1-.6-.1-.8-.1-.6 0-1.1.2-1.5.7-.4.5-.6 1-.6 1.7V44h-1.1v-7.1h.9l.1 1.3h.1c.3-.5.6-.8.9-1.1s.8-.3 1.3-.3zm5.1 7.3c-1 0-1.9-.3-2.5-1s-.9-1.5-.9-2.7c0-1.1.3-2 .8-2.7.6-.7 1.3-1 2.3-1 .9 0 1.6.3 2.1.9s.8 1.4.8 2.3v.7h-4.9c0 .8.2 1.5.6 1.9.4.4 1 .6 1.7.6.8 0 1.5-.2 2.3-.5v1c-.4.2-.7.3-1.1.4-.3.1-.7.1-1.2.1zm-.3-6.4c-.6 0-1 .2-1.4.6-.3.4-.5.9-.6 1.5h3.7c0-.7-.2-1.2-.5-1.6-.2-.3-.6-.5-1.2-.5zm9.6 6.3v-4.6c0-.6-.1-1-.4-1.3-.3-.3-.7-.4-1.2-.4-.7 0-1.3.2-1.6.6-.3.4-.5 1.1-.5 2V44h-1.1v-7.1h.9l.2 1h.1c.2-.3.5-.6.9-.8s.8-.3 1.3-.3c.9 0 1.5.2 1.9.6s.6 1.1.6 2V44h-1.1zm7.8 0h-5.1v-.7l3.9-5.5h-3.6V37h4.8v.8l-3.8 5.4h3.9v.8zm6.7 0l-2.7-7.1h1.2l1.5 4.2c.3 1 .5 1.6.6 1.9h.1c0-.2.2-.7.4-1.4.3-.7.8-2.3 1.7-4.7h1.2L208 44h-1.3zm8 .1c-1 0-1.9-.3-2.5-1s-.9-1.5-.9-2.7c0-1.1.3-2 .8-2.7s1.3-1 2.3-1c.9 0 1.6.3 2.1.9.5.6.8 1.4.8 2.3v.7h-4.9c0 .8.2 1.5.6 1.9s1 .6 1.7.6c.8 0 1.5-.2 2.3-.5v1c-.4.2-.7.3-1.1.4-.3.1-.7.1-1.2.1zm-.3-6.4c-.6 0-1 .2-1.4.6-.3.4-.5.9-.6 1.5h3.7c0-.7-.2-1.2-.5-1.6-.2-.3-.6-.5-1.2-.5zm8-.9c.3 0 .6 0 .8.1l-.1 1c-.3-.1-.6-.1-.8-.1-.6 0-1.1.2-1.5.7-.4.5-.6 1-.6 1.7V44h-1.1v-7.1h.9l.1 1.3h.1c.3-.5.6-.8.9-1.1s.8-.3 1.3-.3zm4.4 6.5h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.4 0-2.1-.7-2.1-2.2v-4.2h-1v-.5l1-.4.5-1.5h.6V37h2.1v.8h-2.1V42c0 .4.1.8.3 1 .3.1.6.3.9.3zm5.7-6.5c.3 0 .6 0 .8.1l-.1 1c-.3-.1-.6-.1-.8-.1-.6 0-1.1.2-1.5.7-.4.5-.6 1-.6 1.7V44h-1.1v-7.1h.9l.1 1.3h.1c.3-.5.6-.8.9-1.1s.8-.3 1.3-.3zM239 44l-.2-1h-.1c-.4.4-.7.7-1.1.9-.4.2-.8.2-1.3.2-.7 0-1.3-.2-1.7-.5-.4-.4-.6-.9-.6-1.5 0-1.4 1.1-2.2 3.4-2.2h1.2v-.4c0-.6-.1-1-.4-1.2-.2-.3-.6-.4-1.1-.4-.6 0-1.3.2-2 .5l-.3-.8c.3-.2.7-.3 1.1-.4.4-.1.8-.2 1.3-.2.8 0 1.5.2 1.9.6.4.4.6 1 .6 1.8V44h-.7zm-2.4-.7c.7 0 1.2-.2 1.6-.5.4-.4.6-.9.6-1.5v-.6h-1.1c-.9 0-1.5.2-1.8.4s-.6.6-.6 1.1c0 .4.1.7.4.9.1.1.4.2.9.2zm6.4-6.4v4.6c0 .6.1 1 .4 1.3s.7.4 1.2.4c.7 0 1.3-.2 1.6-.6s.5-1.1.5-2v-3.7h1.1V44h-.8l-.2-.9h-.1c-.2.3-.5.6-.9.8-.4.2-.8.3-1.3.3-.9 0-1.5-.2-1.9-.6-.4-.4-.6-1.1-.6-2V37h1zm10.1 7.2c-1 0-1.9-.3-2.5-1-.6-.6-.9-1.5-.9-2.7 0-1.1.3-2 .8-2.7s1.3-1 2.3-1c.9 0 1.6.3 2.1.9s.8 1.4.8 2.3v.7h-4.9c0 .8.2 1.5.6 1.9s1 .6 1.7.6c.8 0 1.5-.2 2.3-.5v1c-.4.2-.7.3-1.1.4-.3.1-.7.1-1.2.1zm-.3-6.4c-.6 0-1 .2-1.4.6-.3.4-.5.9-.6 1.5h3.7c0-.7-.2-1.2-.5-1.6-.2-.3-.6-.5-1.2-.5zm9.6 6.3v-4.6c0-.6-.1-1-.4-1.3-.3-.3-.7-.4-1.2-.4-.7 0-1.3.2-1.6.6s-.5 1.1-.5 2V44h-1.1v-7.1h.9l.2 1h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.3-.3.9 0 1.5.2 1.9.6.4.4.6 1.1.6 2V44h-1.1zm11.3-1.9c0 .7-.2 1.2-.7 1.5-.5.4-1.2.5-2.1.5-.9 0-1.7-.1-2.2-.4v-1c.3.2.7.3 1.1.4.4.1.8.1 1.1.1.6 0 1-.1 1.3-.3.3-.2.5-.5.5-.8 0-.3-.1-.5-.4-.7-.2-.2-.7-.4-1.4-.7-.7-.2-1.1-.5-1.4-.6s-.5-.4-.6-.6c-.1-.2-.2-.5-.2-.8 0-.6.2-1 .7-1.4s1.1-.5 1.9-.5c.8 0 1.5.2 2.2.5l-.4.9c-.7-.3-1.4-.4-1.9-.4s-.9.1-1.2.2c-.3.2-.4.4-.4.7 0 .2 0 .4.1.5.1.1.3.3.5.4s.6.3 1.2.5c.8.3 1.4.6 1.7.9.4.2.6.6.6 1.1zm4.5 2c-1 0-1.8-.3-2.4-.9-.6-.6-.8-1.5-.8-2.7 0-1.2.3-2.1.9-2.7.6-.6 1.4-1 2.4-1 .3 0 .7 0 1 .1.3.1.6.2.8.3l-.3.9c-.2-.1-.5-.2-.8-.2-.3-.1-.5-.1-.7-.1-1.4 0-2.2.9-2.2 2.8 0 .9.2 1.5.5 2 .4.5.9.7 1.6.7.6 0 1.2-.1 1.8-.4v.9c-.4.2-1 .3-1.8.3zm8.4-.1v-4.6c0-.6-.1-1-.4-1.3-.3-.3-.7-.4-1.2-.4-.7 0-1.3.2-1.6.6s-.5 1.1-.5 2V44h-1.1V34h1.1v3c0 .4 0 .7-.1.9h.1c.2-.3.5-.6.9-.8.4-.2.8-.3 1.3-.3.9 0 1.5.2 1.9.6.4.4.6 1.1.6 2V44h-1zm7.6 0l-.2-1h-.1c-.4.4-.7.7-1.1.9-.4.2-.8.2-1.3.2-.7 0-1.3-.2-1.7-.5-.4-.4-.6-.9-.6-1.5 0-1.4 1.1-2.2 3.4-2.2h1.2v-.4c0-.6-.1-1-.4-1.2-.2-.3-.6-.4-1.1-.4-.6 0-1.3.2-2 .5l-.3-.8c.3-.2.7-.3 1.1-.4.4-.1.8-.2 1.3-.2.8 0 1.5.2 1.9.6.4.4.6 1 .6 1.8V44h-.7zm-2.4-.7c.7 0 1.2-.2 1.6-.5.4-.4.6-.9.6-1.5v-.6h-1.1c-.9 0-1.5.2-1.8.4-.4.2-.6.6-.6 1.1 0 .4.1.7.4.9.1.1.4.2.9.2zm8.6-5.5h-1.8V44h-1.1v-6.2h-1.3v-.5l1.3-.4v-.4c0-1.7.8-2.6 2.3-2.6.4 0 .8.1 1.3.2l-.3.9c-.4-.1-.8-.2-1.1-.2-.4 0-.7.1-.9.4-.2.3-.3.7-.3 1.3v.5h1.8v.8zm4.5 0h-1.8V44H302v-6.2h-1.3v-.5l1.3-.4v-.4c0-1.7.8-2.6 2.3-2.6.4 0 .8.1 1.3.2l-.3.9c-.4-.1-.8-.2-1.1-.2-.4 0-.7.1-.9.4s-.3.7-.3 1.3v.5h1.8v.8zm3.6 5.5h.5s.3-.1.4-.1v.8c-.1.1-.3.1-.5.1s-.4.1-.6.1c-1.4 0-2.1-.7-2.1-2.2v-4.2h-1v-.5l1-.4.5-1.5h.6V37h2.1v.8h-2.1V42c0 .4.1.8.3 1s.5.3.9.3z"/></svg>
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
