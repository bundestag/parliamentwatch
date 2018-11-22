<?php

use Drupal\pw_embed_media\EmbedMedia;


/**
 * Preprocessor and other theme functions for PW Media Embed module
 */

function template_preprocess_pw_embed_media_widget(&$vars) {
  $embedMedia = new EmbedMedia($vars['embed_code']);
  $embedMedia->addJavaScript();
  $embedMedia->addCss();
  $vars['embed_media_widget_id'] = $embedMedia->getId();
}