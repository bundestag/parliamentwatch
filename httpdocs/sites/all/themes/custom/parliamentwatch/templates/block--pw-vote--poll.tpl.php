<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>

<section id="<?php print $block_html_id; ?>" class="poll__table view-mode view-mode--has-filters <?php print $classes; ?>" <?php print $attributes; ?>>
  <div class="container">
    <?php print render($title_suffix) ?>
    <div class="poll_detail__table">
      <div class="poll_detail__table__sorting">
        <div class="form__item form__item--horizontal">
          <label for="poll_detail_table_sorting" class="form__item__label">Sortieren nach</label>
          <select name="poll_detail_table_sorting" id="poll_detail_table_sorting" class="form__item__control form__item__control--special">
            <option value="politician_full_name_asc" data-sort-value="politician_full_name" data-sort-order="1">Name aufsteigend</option>
            <option value="politician_full_name_dsc" data-sort-value="politician_full_name" data-sort-order="0">Name absteigend</option>
            <option value="politician_political_faction_asc" data-sort-value="politician_political_faction" data-sort-order="1">Fraktion aufsteigend</option>
            <option value="politician_political_faction_dsc" data-sort-value="politician_political_faction" data-sort-order="0">Fraktion absteigend</option>
            <option value="politician_constituency_name_asc" data-sort-value="politician_constituency_name" data-sort-order="1">Wahlkreis aufsteigend</option>
            <option value="politician_constituency_name_dsc" data-sort-value="politician_constituency_name" data-sort-order="0">Wahlkreis absteigend</option>
            <option value="field_vote_display_asc" data-sort-value="field_vote_display" data-sort-order="1">Stimmverhalten aufsteigend</option>
            <option value="field_vote_display_dsc" data-sort-value="field_vote_display" data-sort-order="0">Stimmverhalten absteigend</option>
          </select>
        </div>
      </div>
      <?php print $content; ?>
    </div>
  </div>
</section>
