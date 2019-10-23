<?php

/**
 * @file
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 *
 * @ingroup themeable
 */
?>
<div class="question__answer">
  <p class="question__answer__author">
    <?php if (!empty(trim(render($user_picture)))): ?><span class="question__answer__author__image"><?php print render($user_picture); ?></span><?php endif; ?>
    <?php if ($comment->thread === '01/'): ?>
      <?php print t('Response by <strong>@name</strong>', ['@name' => render($content['field_dialogue_sender_fullname'])]); ?>
    <?php else: ?>
      <?php print t('Addition by <strong>@name</strong>', ['@name' => render($content['field_dialogue_sender_fullname'])]); ?>
    <?php endif; ?>
  </p>
  <?php print render($content['field_dialogue_comment_body']); ?>
  <?php if ($content['field_dialogue_is_standard_reply']['#items'][0]['value'] == 1): ?>
    <p class="question__answer__default_hint"><?php print t('This answer is a standardized text, which does not answer the actual question and will not be counted.'); ?></p>
  <?php endif; ?>
  <?php if (!empty($content['field_dialogue_documents'])): ?>
    <div class="question__documents">
      <h3><?php print t('Documents') ?></h3>
      <?php print render($content['field_dialogue_documents']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['field_dialogue_attachments'])): ?>
    <div class="question__attachement">
      <?php print render($content['field_dialogue_attachments']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['field_dialogue_annotation'])): ?>
    <div class="question__annotation">
      <h3><?php print t("Editor's note") ?></h3>
      <?php print render($content['field_dialogue_annotation']); ?>
    </div>
  <?php endif; ?>
</div>
