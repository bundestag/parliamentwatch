<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="question tile <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="question__meta tile__meta">
    <?php if (!empty($content['field_dialogue_topic'])): ?>
    <a href="#" class="quesion__meta__tag tile__meta__tag">#<?php print render($content['field_dialogue_topic']); ?></a>
    <?php endif; ?>
    <span class="question__meta__date tile__meta__date"><?php print $date; ?></span>
  </div>
  <div class="question__question mh-item-tile" data-mh="questionTitle">
    <header class="question__question__title"><?php print render($content['body']); ?></header>
    <?php print render($title_suffix); ?>
    <p class="question__question__author"><?php print t('By'); ?>: <?php print render($content['field_dialogue_sender_name']); ?></p>
  </div>
  <div class="question__share tile__share">
    <div class="tile__share__trigger"><i class="icon icon-share"></i> <?php print t('share') ?></div>
    <ul class="tile__share__list">
      <li class="tile__share__list__item tile__share__list__item--facebook"><a href="https://www.facebook.com/sharer/sharer.php?u=<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>" target="_blank"><i class="icon icon-facebook"></i> <?php print t('facebook') ?></a></li>
      <li class="tile__share__list__item tile__share__list__item--twitter"><a href="https://twitter.com/home?status=<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>" target="_blank"><i class="icon icon-twitter"></i> <?php print t('twitter') ?></a></li>
      <li class="tile__share__list__item tile__share__list__item--whatsapp"><a href="whatsapp://send" target="_blank" data-text="<?php print t('Take a look at this question:');?>" data-href="<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>" target="_blank"><i class="icon icon-whatsapp"></i> <?php print t('whatsapp') ?></a></li>
      <li class="tile__share__list__item tile__share__list__item--mail"><a href="mailto:?&subject=abgeordnetenwatch.de&body=<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>" target="_blank"><i class="icon icon-mail"></i> <?php print t('E-Mail') ?></a></li>
    </ul>
  </div>

  <div class="question__answer mh-item-tile" data-mh="questionAnswer">
    <div class="question__answer__author">
      <?php if ($view_mode == 'embedded'): ?>
        Antwort von <strong><?php print render($content['user_display_name']); ?></strong> <?php print render($content['user_party']); ?>
      <?php else: ?>
        <span class="question__answer__author__label"><?php print t('To') ?>:</span>
        <?php if (!empty(trim(render($content['user_picture'])))): ?><span class="question__answer__author__image"><?php print render($content['user_picture']); ?></span><?php endif; ?>
        <div class="question__answer__author_text" title="<?php print t('Go to profile of') ?> <?php print render($content['user_display_name']); ?>">
          <a href="<?php print render($content['user_url']); ?>"><?php print render($content['user_display_name']); ?></a>
          <?php print render($content['user_party']); ?>
        </div>
      <?php endif; ?>
    </div>
    <?php if (empty($content['answers'])): ?>
      <p><?php print t('The question has not yet been answered. Become a <a href="%">questioner</a> and increase the pressure on the politician to answer that question. '); ?></p>
    <?php endif; ?>
    <?php print render($content['answers']); ?>
  </div>
  <ul class="question__links tile__links tile__links--2">
    <li class="tile__links__item"><a class="tile__links__item__link" href="<?php print $node_url ?>"><?php print t('details'); ?></a></li>
  </ul>
</div>
