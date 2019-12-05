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
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> webform-wrapper sidebar-container"<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <div class="webform">
    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>
    <div class="content"<?php print $content_attributes; ?>>
      <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
      ?>
    </div>
    <?php print render($content['links']); ?>
    <?php print render($content['comments']); ?>
  </div>
  <div class="sidebar">
    <div class="sidebar__box">
      <h3 class="sidebar__box__headline">Wie mache ich mit?</h3>
      <p>Teilen Sie uns <b>bis zum 8. Januar 2020</b> mit, warum Sie unseren Verein unterstützen und vor allem, was Sie abgeordnetenwatch.de für die nächsten 15. Jahre wünschen. Wo sollen wir stehen? Was sollen wir bis dahin erreicht haben? Was wünschen SIE sich als Förderin oder Förderer?</p>
      <p>Als Text, Handyvideo, Sprachnachricht, Collage, Zeichnung... <b>fast alle Formate sind möglich!</b></p>
    </div>
    <div class="sidebar__box">
      <h3 class="sidebar__box__headline">Unser Dankeschön</h3>
      <p>Unter allen Beiträgen verlosen wir <b>zehn unserer beliebten abgeordnetenwatch.de-Transparenztassen</b> - unser kleines Dankeschön für Ihre tolle Unterstützung. Außerdem würden wir uns sehr freuen, wenn Sie uns Ihr Einverständnis geben, Ihre Beiträge und Ideen auch auf unseren Social Media-Kanälen, auf unserer Website und in unserem Newsletter teilen zu dürfen.</p>
    </div>
    <div class="sidebar__box">
      <h3 class="sidebar__box__headline">Warum Sie?</h3>
      <p>SIE sind diejenigen, die unsere Arbeit jeden Tag ermöglichen. Sie kennen abgeordnetenwatch.de und deswegen ist es für uns sehr wichtig, von Ihnen zu hören, was Sie sich wünschen. So können wir unsere Arbeit zukünftig noch besser machen: Wo sollen wir unsere Schwerpunkte setzen, was sollten wir vielleicht mehr beachten ... Außerdem sind Ihre Aussagen und Standpunkte die besten Botschaften, um weitere Unterstützer:innen zu gewinnen.</p>
    </div>
    <div class="sidebar__box">
      <h3 class="sidebar__box__headline">Fragen?</h3>
      <p>Bei Fragen melden Sie sich gerne unter <a href="mailto:info@abgeordnetenwatch.de">info@abgeordnetenwatch.de</a> oder rufen Sie uns an! 040 317 691 0 26</p>
    </div>
    <div class="sidebar__box">
      <h3 class="sidebar__box__headline">Per E-Mail?</h3>
      <p>Wenn Sie uns die Geburtstagswünsche lieber per E-Mail schicken wollen: <a href="mailto:info@abgeordnetenwatch.de?subject=15. Geburtstag">info@abgeordnetenwatch.de</a></p>
    </div>
    <div class="sidebar__box">
      <h3 class="sidebar__box__headline">Sie wollen mehr?</h3>
      <p>Schauen Sie sich <a href="https://www.abgeordnetenwatch.de/abgeordnetenwatchde-feiert-15-jahre">unsere Chronik an</a>. da Lassen Sie sich überraschen, wie die abgeordnetenwatch.de-Plattform sich über die Jahre entwickelt hat und was wir erreicht haben!</p>
    </div>
      </div>
    </div>
  </div>
</div>
