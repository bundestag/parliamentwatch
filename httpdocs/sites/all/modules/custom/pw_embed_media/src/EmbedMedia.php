<?php


namespace Drupal\pw_embed_media;

/**
 * This class handles the JavaScript and HTML markup generation
 * when some markup should be protected be the embed media widget.
 *
 * The class takes the HTML markup which should be protected, adds it to the
 * Drupal.settings JavaScript object and returns the
 */
class EmbedMedia {

  protected $embedCode;

  protected $id;


  public function __construct($embed_code) {
    $this->embedCode = $embed_code;
    $this->generateId();
  }


  protected function generateId() {
    $this->id = 'dasjdgsdgjdgfd';
  }


  public function getId() {
    return $this->id;
  }

  public function addJavaScript() {
    drupal_add_js(drupal_get_path('module', 'pw_embed_media') .'/scripts/pw-embed-media.js');


    $settings = array(
      'pw_embed_media' => array(
        'widgets' => array(
          $this->getId() => $this->embedCode
        )
      )
    );
    drupal_add_js($settings, 'setting');
  }

  public function addCss() {
    drupal_add_css(drupal_get_path('module', 'pw_embed_media') .'/css/pw-embed-media.css');
  }


  public function getEmbedCode() {
    return $this->embedCode;
  }
}