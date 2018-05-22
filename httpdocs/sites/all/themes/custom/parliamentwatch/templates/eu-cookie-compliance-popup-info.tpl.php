<?php

/**
 * @file
 * This is a template file for a pop-up prompting user to give their consent for
 * the website to set cookies.
 *
 * When overriding this template it is important to note that jQuery will use
 * the following classes to assign actions to buttons:
 *
 * agree-button      - agree to setting cookies
 * find-more-button  - link to an information page
 *
 * Variables available:
 * - $message:  Contains the text that will be display within the pop-up
 * - $agree_button: Contains agree button title
 * - $disagree_button: Contains Cookie policy button title
 */
?>
<div>
  <div class ="popup-content info">
    <div id="popup-text">
      <?php print $message ?>
    </div>
    <div id="popup-buttons">
      <button type="button" class="btn btn--white agree-button"><?php print $agree_button; ?></button>
      <?php if ($disagree_button) : ?>
        <button type="button" class="btn btn--white find-more-button"><?php print $disagree_button; ?></button>
      <?php endif; ?>
    </div>
  </div>
</div>
