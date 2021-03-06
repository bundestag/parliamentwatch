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
<?php $content_link_url = $content['field_pg_content_link'][0]['#element']['url']; ?>
<div class="archive_<?php print $field_show[0]['value'] ?>">

  <div class="relative entity-paragraphs-item <?php print render($content['field_pg_donate_targetgroup']); ?>">
    <table cellpadding="0" cellspacing="0" border="0" bgcolor="#ffffff" width="600" align="center" class="deviceWidth" style="border-bottom: 1px solid #f63;">
      <tr>
        <td colspan="3" width="100%" style="height: 20px;">&nbsp;</td>
      </tr>
      <tr>
        <td colspan="3" width="100%">
          <table cellpadding="0" cellspacing="0" border="0" bgcolor="#ffffff" width="100%" align="center" class="deviceWidth">
            <tr>
              <td width="80%">
                <h3 style="font-family: 'Times New Roman', Times, serif; font-weight: normal; font-size: 24px; margin: 0;"><a target="_blank" href="<?php print $content_link_url; ?>" style="color: #333; text-decoration: none;"><?php print render($content['field_pg_content_title']); ?></a></h3>
              </td>
              <td width="20%" style="text-align: right;">
                <a href="https://twitter.com/intent/tweet?text=Jetzt für abgeordnetenwatch.de spenden&url=<?php print $content_link_url; ?>" class="twitter" target="_blank"><img src="<?php print $GLOBALS['base_url'] ?>/sites/all/themes/custom/parliamentwatch/images/newsletter/social-twitter.png" alt="Twitter" border="0" style="display: inline-block;"></a>
                <a href="https://www.facebook.com/sharer/sharer.php?u=<?php print $content_link_url; ?>" class="facebook" target="_blank"><img src="<?php print $GLOBALS['base_url'] ?>/sites/all/themes/custom/parliamentwatch/images/newsletter/social-facebook.png" alt="Facebook" border="0" style="display: inline-block;"></a>
              </td>
            </tr>
          </table>
        </td>
      </tr>
      <tr>
        <td colspan="3" width="100%" style="height: 10px;">&nbsp;</td>
      </tr>
      <tr>
        <?php if (empty($content['field_pg_content_img'][0])): ?>
          <td colspan="3" width="100%">
            <?php print render($content['field_pg_content_body']); ?>

          </td>
        <?php else: ?>
          <td width="240" class="block_td pic_td" style="width: 240px; vertical-align: top;">
            <?php print render($content['field_pg_content_img']); ?>
          </td>
          <td width="20" class="block_td pic_td" style="vertical-align: top;">&nbsp;</td>
          <td width="340" class="block_td percent_td" style="vertical-align: top;">
            <?php print render($content['field_pg_content_body']); ?>
          </td>
        <?php endif; ?>
      </tr>
      <tr>
        <td colspan="3" width="100%" style="height: 20px;">&nbsp;</td>
      </tr>
    </table>


    <?php if ($field_pg_content_last_element[0]['value'] == '0'): ?>
    <table cellpadding="0" cellspacing="0" border="0" bgcolor="#ffffff" width="600" align="center" class="deviceWidth" style="border-bottom: 1px solid #f63;">
    <?php endif; ?>

    <?php if ($field_pg_content_last_element[0]['value'] == '1'): ?>
    <table cellpadding="0" cellspacing="0" border="0" bgcolor="#ffffff" width="600" align="center" class="deviceWidth">
    <?php endif; ?>
      <tr>
        <td colspan="3" width="100%" style="height: 20px;">&nbsp;</td>
      </tr>
      <tr>
        <td width="180">&nbsp;</td>
        <td width="240" style="text-align: center;">
          <table width="100%" border="0" cellspacing="0" cellpadding="0">
            <tr>
              <td>
                <?php foreach ($field_pg_content_link as $delta => $item): ?>
                <table border="0" cellspacing="0" cellpadding="0" align="center" class="deviceWidth">
                  <tr>
                    <td>
                      <a href="<?php print $item['url']; ?>" target="_blank" style="font-size: 16px; font-family: Helvetica, Arial, sans-serif; color: #ffffff; text-decoration: none; background-color: #f63; border-top: 12px solid #f63; border-bottom: 12px solid #f63; border-right: 18px solid #f63; border-left: 18px solid #f63; display: inline-block; white-space: nowrap;"><?php print $item['title']; ?></a>
                    </td>
                  </tr>
                  <tr>
                    <td width="100%" style="height: 20px;">&nbsp;</td>
                  </tr>
                </table>
                <?php endforeach; ?>
              </td>
            </tr>
          </table>
        </td>
        <td width="180">&nbsp;</td>
      </tr>
    </table>
    <?php if ($field_pg_content_last_element[0]['value'] == '0'): ?>
    <table cellpadding="0" cellspacing="0" border="0" bgcolor="#ffffff" width="600" align="center" class="deviceWidth">
      <tr>
        <td colspan="3" width="100%" style="height: 20px;">&nbsp;</td>
      </tr>
    </table>
    <?php endif; ?>
  </div>
</div>
