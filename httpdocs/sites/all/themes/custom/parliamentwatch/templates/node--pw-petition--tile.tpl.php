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
<article id="node-<?php print $node->nid; ?>" class="petition tile <?php print $classes; ?>"<?php print $attributes; ?>>
  <figure class="tile__image">
    <a href="<?php print $node_url; ?>"><?php print render($content['field_teaser_image']); ?></a>
    <?php if (isset($content['field_teaser_image_copyright'])): ?>
      <figcaption class="figcaption-overlay"><span>©&nbsp;<?php print render($content['field_teaser_image_copyright']); ?></span></figcaption>
    <?php endif; ?>
  </figure>

  <?php if ($field_petition_partner): ?>
  <div class="tile__flag"><?php print render($field_petition_partner[0]['value']); ?></div>
  <?php endif; ?>
  <div class="tile__content">
    <h3 class="tile__title mh-item" <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
    <?php print render($title_suffix); ?>

    <div class="petition__result_outer mh-item-nr">
      <div class="petition__result">
        <?php if ($field_petition_status[0]['value'] == 'open_for_signings'): ?>
          <span class="d3 d3--bar-horizontal"
                data-bar-horizontal
                data-value="<?php print $field_petition_signings[0]['value']; ?>"
                data-value_max="<?php print $field_petition_required[0]['value']; ?>">
            <span class="bar"></span>
          </span>
          <p><?php print render($content['field_petition_signings']); ?><br>
            <small><?php print render($content['field_petition_required']); ?> <?php print t('signings are required')?></small>
          </p>
        <?php endif; ?>

        <?php if ($field_petition_status[0]['value'] == 'collecting_donations'): ?>
          <span class="d3 d3--bar-horizontal"
                data-bar-horizontal
                data-value="<?php print $field_donation_amount[0]['value']; ?>"
                data-value_max="<?php print $field_donation_required[0]['value']; ?>"><span class="bar"></span></span>
          <p><?php print $field_donation_amount[0]['value']; ?> € <?php print t('of')?> <?php print render($content['field_donation_required']); ?> € <?php print t('gathered'); ?></p>
        <?php endif; ?>

        <?php if ($field_petition_status[0]['value'] == 'survey_in_progress'): ?>
          <p class="petition__result_asked">
        <span class="petition__result_asked__inner">
          <i class="icon icon-microphone"></i>
          <strong><?php print t('The survey is in progress now.') ?></strong>
          <?php print t('The survey is in progress now.') ?>
        </span>
          </p>
        <?php endif; ?>

        <?php if ($field_petition_status[0]['value'] == 'asking_parliament'): ?>
          <p class="petition__result_asked">
        <span class="petition__result_asked__inner">
          <i class="icon icon-microphone"></i>
          <strong><?php print t('Politicians are now giving their statements.') ?></strong>
        </span>
          </p>
        <?php endif; ?>

        <?php if ($field_petition_status[0]['value'] == 'passed_parliament'): ?>
          <p class="petition__result_asked">
        <span class="petition__result_asked__inner">
          <i class="icon icon-ok"></i>
          <strong><?php print t('The petition passed parliament.') ?></strong><br>
          <?php print format_plural($node->votes, '1 politician gave a statement.', '@count politicians gave a statement.'); ?>
        </span>
          </p>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <ul class="tile__links tile__links--2">
    <li class="tile__links__item"><a class="tile__links__item__link" href="<?php print $node_url ?>"><?php print t('read more'); ?></a></li>
  </ul>
</article>
