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
      <h3 class="sidebar__box__headline">Sicherheitshinweise</h3>
      <p>Zum Schutz Ihrer Daten, erfolgt die Übertragung der Formular-Daten ausschließlich über zertifizierte SSL-Verschlüsselung.</p>
      <p><small><strong>Hinweis für SEPA-Lastschrift:</strong> Wenn Sie bis zum 13. des Monats spenden, dann ziehen wir die Spende am 15. des Monats oder am darauffolgenden Bankarbeitstag ein. Nach dem 13. des Monats ziehen wir Ihre Spende am 25. des Monats oder dem darauffolgenden Bankarbeitstag ein.</small></p>
    </div>
    <div class="sidebar__box">
      <h3 class="sidebar__box__headline"><?php print t('Transparency') ?></h3>
      <p><?php print t('In our annual report, we publish the names of the donors who supported us in the previous year with a total amount of € 1,000 and above.') ?></p>
    </div>
    <div class="sidebar__box">
      <h3 class="sidebar__box__headline">Weitere Spendenmöglichkeiten</h3>
      <div class="sidebar__box__accordion">
        <div class="sidebar__box__accordion__item sidebar__box__accordion__item--open">
          <h4 class="sidebar__box__accordion__item__title">Spendenkonto</h4>
          <div class="sidebar__box__accordion__item__content">
            <p>
              <strong>Parlamentwatch e.V.</strong><br>
              Kto Nr.: 2011 120 000<br>
              BLZ: 430 609 67<br>
              GLS Bank<br>
              IBAN: DE03 4306 0967 2011 1200 00<br>
              BIC: GENODEM1GLS<br>
            </p>
            <p><?php print t('Please provide your full address for bank transfers so that we can send you a donation receipt.') ?></p>
          </div>
        </div>
        <div class="sidebar__box__accordion__item">
          <h4 class="sidebar__box__accordion__item__title">PayPal</h4>
          <div class="sidebar__box__accordion__item__content">
            <p>Zum Spenden können Sie auch PayPal nutzen.</p>
            <form target="_blank" action="https://www.paypal.com/cgi-bin/webscr" method="post">
              <input type="hidden" name="cmd" value="_s-xclick">
              <input type="image" border="0" src="/<?php print drupal_get_path('theme', 'parliamentwatch'); ?>/images/btn_paypal.gif" name="submit" alt="Zahlen Sie mit PayPal - schnell, kostenlos und sicher!">
              <input type="hidden" name="encrypted" value="-----BEGIN PKCS7-----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-----END PKCS7-----">
            </form>
          </div>
        </div>
        <div class="sidebar__box__accordion__item">
          <h4 class="sidebar__box__accordion__item__title">BitCoin</h4>
          <div class="sidebar__box__accordion__item__content">
            <p>Wir akzeptieren auch Bitcoin.</p>
            <form class="bitpay-donate" action="https://bitpay.com/checkout" method="post" target="_blank">
              <input name="action" type="hidden" value="checkout">
              <div class="form__item">
                <input class="bitpay-donate-field-email form__item__control" name="orderID" type="email" placeholder="E-Mail-Adresse (optional)" maxlength="50" autocapitalize="off" autocorrect="off">
              </div>
              <div class="form__item form__item--multi">
                <input class="bitpay-donate-field-price form__item__control" name="price" type="number" value="10.00" placeholder="Amount" maxlength="10" min="0.01" step="0.01"/>
                <div class="bitpay-donate-field-currency--wrapper">
                  <select class="bitpay-donate-field-currency form__item__control" name="currency" value="">
                    <option selected="selected" value="EUR">EUR</option>
                    <option value="BTC">BTC</option>
                  </select>
                </div>
                <input type="hidden" name="data" value="XpHSKMYmf8hIJ0y8nnXP3XQRMZ6Jow2QNMVtQVioiydg/NTfh4MaccKgzCg2pgjV53kPxdn0GhHc45siohgZKavCjksVGGSgZAM06az5q6c67XL0aA/ko2me5XNbGgtUq10Uy6qkwYKfcX32qWIUyeF9PebhftFpCN4KPsp5RPTtA23zzYV1SY3FH7xRbMm6cSwyUS/zRhrQ+m4Om/gCCdZx+0gzPoLWdO3Twhv/gMzyxuI9cPUlhL95EE8jsUE+1aVy3uVYvCGOpKTfqSEqFXNnUDTcfmZJZZRBmI0c8afITghTOJNUnTnkMEYEUSQH7186L39ObaqABqNG4o8Xsg==">
              </div>
              <p><input class="bitpay-donate-button" name="submit" src="https://bitpay.com/img/donate-button.svg" onerror="this.onerror=null; this.src='https://bitpay.com/img/donate-button-md.png'" width="126" height="48" type="image" alt="BitPay, the easy way to donate with bitcoins." border="0"></p>
            </form>
          </div>
        </div>
        <div class="sidebar__box__accordion__item">
          <h4 class="sidebar__box__accordion__item__title">Spenden per Post</h4>
          <div class="sidebar__box__accordion__item__content">
            <p>Alternativ zu einer Online-Spende können Sie auch einen Antrag herunterladen (<a href="/sites/abgeordnetenwatch.de/files/spendenformular_print.pdf" target="_blank">PDF</a>), ausdrucken und uns per Post oder Fax senden.</p>
            <a href="/sites/abgeordnetenwatch.de/files/spendenformular_print.pdf" class="link-icon" target="_blank"><i class="icon icon-arrow-right"></i> Spendenformular herunterladen</a>
          </div>
        </div>
        <div class="sidebar__box__accordion__item">
          <h4 class="sidebar__box__accordion__item__title">Spenden beim Einkaufen</h4>
          <div class="sidebar__box__accordion__item__content">
            <p>Neben unserem Spendenformular gibt es weitere Möglichkeiten abgeordnetenwatch.de zu unterstützen.</p>
            <p>Sie kaufen hin und wieder online ein? Dann können Sie dabei gleichzeitig abgeordnetenwatch.de unterstützen. Wie? Das lesen sie hier:</p>
            <a href="/blog/2014-09-23/wie-sie-abgeordnetenwatchde-finanziell-unterstutzen-ohne-selbst-etwas-zu-zahlen" class="link-icon"><i class="icon icon-arrow-right"></i> <?php print t('More information') ?></a>
          </div>
        </div>
        <div class="sidebar__box__accordion__item">
          <h4 class="sidebar__box__accordion__item__title">Spenden statt Geschenke</h4>
          <div class="sidebar__box__accordion__item__content">
            <p>Sie haben alles was Sie brauchen und möchten zum Geburtstag gerne für einen guten Zweck sammeln?</p>
            <a href="/spenden-statt-geschenke" class="link-icon"><i class="icon icon-arrow-right"></i> <?php print t('More information') ?></a>
          </div>
        </div>
        <div class="sidebar__box__accordion__item">
          <h4 class="sidebar__box__accordion__item__title">Testamentsspende</h4>
          <div class="sidebar__box__accordion__item__content">
            <p>Sie möchten abgeordnetenwatch.de in Ihr Testament aufnehmen? Weitere Informationen finden Sie hier:</p>
            <a href="/testamentsspende" class="link-icon"><i class="icon icon-arrow-right"></i> <?php print t('More information') ?></a>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
