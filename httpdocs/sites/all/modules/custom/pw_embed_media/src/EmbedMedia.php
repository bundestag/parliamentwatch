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

  /**
   * @var string
   * The HTML which should be embedded
   */
  protected $rawEmbedCode = '';


  /**
   * @var string
   * The HTML which can savely be embedded into JavaScript
   */
  protected $preparedEmbedCode = NULL;

  protected $id;


  public function __construct($raw_embed_code) {
    $this->rawEmbedCode = $raw_embed_code;
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
          $this->getId() => $this->getPrepapredEmbedCode()
        )
      )
    );
    drupal_add_js($settings, 'setting');
  }

  public function addCss() {
    drupal_add_css(drupal_get_path('module', 'pw_embed_media') .'/css/pw-embed-media.css');
  }


  public function getRawEmbedCode() {
    return $this->rawEmbedCode;
  }


  /**
   * @return string
   *
   */
  public function getPrepapredEmbedCode() {
    if ($this->preparedEmbedCode === NULL) {
      $this->preparedEmbedCode = $this->prepareEmbdeCode($this->getRawEmbedCode());
    }

    return $this->preparedEmbedCode;
  }


  /**
   * Prepares a string with HTML for use in JavaScript. There it can be dedcode by
   * decodeURIComponent()
   *
   * @see https://stackoverflow.com/a/442949/1636688
   *
   * @param $string
   *
   * @return string
   */
  public function prepareEmbdeCode($string) {
    return rawurlencode($this->getRawEmbedCode());
  }
}