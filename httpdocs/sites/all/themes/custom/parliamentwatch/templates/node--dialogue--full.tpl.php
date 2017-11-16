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
<div class="question full <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="question__profile_teaser" href="<?php print $user_url; ?>">
    <div class="question__profile_teaser__inner">
      <div class="question__profile_teaser__inner__image">
        <?php print render($user_picture); ?>
      </div>
      <div class="question__profile_teaser__inner__content">
        <span class="question__profile_teaser__inner__content__name"><?php print render($user_display_name); ?></span>
        <?php print render($user_party); ?>
        <a href="<?php print render($user_url); ?>" class="btn btn--small btn--mobile-block"><?php print t('Open profile'); ?></a>
      </div>
    </div>
    <h1><?php print t('Question from'); ?> <span class="robots-nocontent"><!--noindex--><!--googleoff: index--><?php print render($content['field_dialogue_sender_name']); ?><!--googleon: index--><!--/noindex--></span> <?php print t('to'); ?> <?php print render($user_display_name); ?><?php if (!empty($content['field_dialogue_topic'])): ?> <?php print t('regarding'); ?> <?php print render($content['field_dialogue_topic']); ?><?php endif; ?></h1>
    <div class="question__meta tile__meta">
      <a href="#" class="quesion__meta__tag tile__meta__tag">#<?php print render($content['field_dialogue_topic']); ?></a>
      <span class="question__meta__date tile__meta__date"><?php print format_date($node->created, $type = 'custom', $format = 'd. M. Y - H:i'); ?></span>
    </div>
  </div>
  <div class="container-small">
    <div class="question__question mh-item-tile" data-mh="questionTitle">
      <div class="question__question__title"><?php print render($content['body']); ?></div>
      <?php print render($title_suffix); ?>
      <p class="question__question__author"><?php print t('By'); ?>: <span class="robots-nocontent"><!--noindex--><!--googleoff: index--><?php print render($content['field_dialogue_sender_name']); ?><!--googleon: index--><!--/noindex--></span></p>
      <?php if (!empty($content['field_dialogue_annotation'])): ?>
        <div class="question__annotation">
          <h3><?php print t("Editor's note") ?></h3>
          <?php print render($content['field_dialogue_annotation']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
  <div class="share share--small">
    <h3><?php print t('Share this question') ?></h3>
    <ul class="share__links">
      <li class="share__links__item share__links__item--facebook">
        <a class="share__links__item__link" href="https://www.facebook.com/sharer/sharer.php?u=<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>" target="_blank">
          <i class="icon icon-facebook"></i> <span>teilen</span>
        </a>
      </li>
      <li class="share__links__item share__links__item--twitter">
        <a class="share__links__item__link" href="https://twitter.com/home?status=<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>" target="_blank">
          <i class="icon icon-twitter"></i> <span>tweet</span>
        </a>
      </li>
      <li class="share__links__item share__links__item--google">
        <a class="share__links__item__link" href="https://plus.google.com/share?url=<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>" target="_blank">
          <i class="icon icon-google-plus"></i> <span>+1</span>
        </a>
      </li>
      <li class="share__links__item share__links__item--whatsapp">
        <a class="share__links__item__link" href="whatsapp://send" target="_blank" data-text="<?php print t('Take a look at this question:');?>" data-href="<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>">
          <i class="icon icon-whatsapp"></i> <span>WhatsApp</span>
        </a>
      </li>
      <li class="share__links__item share__links__item--mail">
        <a class="share__links__item__link" href="mailto:?&subject=abgeordnetenwatch.de&body=<?php print drupal_encode_path(url($node_url,array('absolute'=>TRUE))); ?>" target="_blank">
          <i class="icon icon-mail"></i> <span>e-mail</span>
        </a>
      </li>
    </ul>
  </div>
  <div class="question__answer-wrapper">
    <?php if (empty($content['answers'])): ?>
      <div class="question__answer">
        <p><?php print t('The question has not yet been answered. Become a <a href="%">questioner</a> and increase the pressure on the politician to answer that question. '); ?></p>
      </div>
    <?php else: ?>
      <?php print render($content['answers']); ?>
    <?php endif; ?>
  </div>
</div>