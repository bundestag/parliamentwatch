<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<?php if (!empty($content['field_pg_content_link'])): ?>
  <?php $node_url=url($field_pg_content_link[0]['url'], array('absolute' => TRUE)); ?>
<?php endif; ?>

<div class="archive_<?php print $field_show[0]['value'] ?>">
  <div class="<?php print trim(render($content['field_pg_donate_targetgroup'])); ?>">

    <table cellpadding="0" cellspacing="0" border="0" bgcolor="#ffffff" width="600" align="center" class="deviceWidth">
      <?php if (!empty($field_pg_content_title) && !empty($field_pg_content_link)): ?>
        <tr>
          <td colspan="3" width="100%" style="height: 15px; font-size: 1px;">&nbsp;</td>
        </tr>
        <tr>
          <td colspan="3" width="100%">
            <table cellpadding="0" cellspacing="0" border="0" bgcolor="#ffffff" width="100%" align="center">
              <tr>
                <td width="80%">
                  <?php if (!empty($content['field_pg_content_title'])): ?>
                    <h3 style="font-family: 'Times New Roman', Times, serif; font-weight: normal; font-size: 24px; margin: 0;">
                      <?php if (!empty($content['field_pg_content_link'])): ?><a target="_blank" href="<?php print $field_pg_content_link[0]['url'] ?>" style="color: #333; text-decoration: none;"><?php endif; ?>
                        <?php print render($content['field_pg_content_title']); ?>
                        <?php if (!empty($content['field_pg_content_link'])): ?></a><?php endif; ?>
                    </h3>
                  <?php endif; ?>
                </td>
                <td width="20%" style="text-align: right;">
                  <?php if (!empty($field_pg_content_link)): ?>
                    <a href="https://twitter.com/intent/tweet?text=<?php print $field_pg_content_title[0]['safe_value']; ?>&url=<?php print $node_url; ?>" class="twitter" target="_blank"><img src="<?php print $GLOBALS['base_url'] ?>/sites/all/themes/custom/parliamentwatch/images/newsletter/social-twitter.png" alt="Twitter" border="0" style="display: inline-block;"></a>
                    <a href="https://www.facebook.com/sharer/sharer.php?u=<?php print $node_url; ?>" class="facebook" target="_blank"><img src="<?php print $GLOBALS['base_url'] ?>/sites/all/themes/custom/parliamentwatch/images/newsletter/social-facebook.png" alt="Facebook" border="0" style="display: inline-block;"></a>
                  <?php endif; ?>
                </td>
              </tr>
            </table>
          </td>
        </tr>
      <?php endif; ?>
      <?php if (!empty($field_pg_content_title) && empty($field_pg_content_link)): ?>
        <tr>
          <td colspan="3" width="100%" style="height: 15px; font-size: 1px;">&nbsp;</td>
        </tr>
        <tr>
          <td colspan="3" width="100%">
            <?php if (!empty($content['field_pg_content_title'])): ?>
              <h3 style="font-family: 'Times New Roman', Times, serif; font-weight: normal; font-size: 24px; margin: 0;">
                <?php if (!empty($content['field_pg_content_link'])): ?><a target="_blank" href="<?php print $field_pg_content_link[0]['url'] ?>" style="color: #333; text-decoration: none;"><?php endif; ?>
                  <?php print render($content['field_pg_content_title']); ?>
                  <?php if (!empty($content['field_pg_content_link'])): ?></a><?php endif; ?>
              </h3>
            <?php endif; ?>
          </td>
        </tr>
      <?php endif; ?>
      <?php if (empty($field_pg_content_title) && !empty($field_pg_content_link)): ?>
        <tr>
          <td colspan="3" width="100%" style="height: 10px;">&nbsp;</td>
        </tr>
        <tr>
          <td colspan="3" width="100%">
            <table cellpadding="0" cellspacing="0" border="0" bgcolor="#ffffff" width="100%" align="center">
              <tr>
                <td width="80%">
                </td>
                <td width="20%" style="text-align: right;">
                  <?php if (!empty($field_pg_content_link)): ?>
                    <a href="https://twitter.com/intent/tweet?text=<?php print $field_pg_content_title[0]['safe_value']; ?>&url=<?php print $node_url; ?>" class="twitter" target="_blank"><img src="<?php print $GLOBALS['base_url'] ?>/sites/all/themes/custom/parliamentwatch/images/newsletter/social-twitter.png" alt="Twitter" border="0" style="display: inline-block;"></a>
                    <a href="https://www.facebook.com/sharer/sharer.php?u=<?php print $node_url; ?>" class="facebook" target="_blank"><img src="<?php print $GLOBALS['base_url'] ?>/sites/all/themes/custom/parliamentwatch/images/newsletter/social-facebook.png" alt="Facebook" border="0" style="display: inline-block;"></a>
                  <?php endif; ?>
                </td>
              </tr>
            </table>
          </td>
        </tr>
      <?php endif; ?>
      <tr>
        <td colspan="3" width="100%" style="height: 10px; font-size: 1px;">&nbsp;</td>
      </tr>
      <tr>
        <?php if (empty($content['field_pg_content_img'][0])): ?>
          <td colspan="3" width="100%">
            <?php print render($content['field_pg_content_body']); ?>
            <?php if (!empty($field_pg_content_link)): ?>
              <?php foreach ($field_pg_content_link as $delta => $item): ?>
              <p style="margin: 0; padding: 0;"><a target="_blank" href="<?php print $item['url'] ?>" style="font-family: Arial, Helvetica, Sans-Serif; color: #f63; text-decoration: none; font-weight: bold; font-size: 15px; line-height: 21px;"><img src="<?php print $GLOBALS['base_url'] ?>/sites/all/themes/custom/parliamentwatch/images/newsletter/link-icon.png" width="12" height="12" border="0" style="display:inline-block;"> <?php print $item['title'] ?></a></p>
              <?php endforeach; ?>
            <?php endif; ?>
          </td>
        <?php else: ?>
          <td width="240" class="block_td pic_td" style="width: 240px; vertical-align: top;">
            <?php print render($content['field_pg_content_img']); ?>
          </td>
          <td width="20" class="block_td pic_td" style="vertical-align: top;">&nbsp;</td>
          <td width="340" class="block_td percent_td" style="vertical-align: top;">
            <?php print render($content['field_pg_content_body']); ?>
            <?php if (!empty($field_pg_content_link)): ?>
              <?php foreach ($field_pg_content_link as $delta => $item): ?>
                <p style="margin: 0; padding: 0;"><a target="_blank" href="<?php print $item['url'] ?>" style="font-family: Arial, Helvetica, Sans-Serif; color: #f63; text-decoration: none; font-weight: bold; font-size: 15px; line-height: 21px;"><img src="<?php print $GLOBALS['base_url'] ?>/sites/all/themes/custom/parliamentwatch/images/newsletter/link-icon.png" width="12" height="12" border="0" style="display:inline-block;"> <?php print $item['title'] ?></a></p>
              <?php endforeach; ?>
            <?php endif; ?>
          </td>
        <?php endif; ?>
      </tr>
      <tr>
        <td colspan="3" width="100%" style="height: 15px; font-size: 1px;">&nbsp;</td>
      </tr>
    </table>
  </div>
</div>

