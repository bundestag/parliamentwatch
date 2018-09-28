<?php
/**
 * @file
 * pw_gdpr.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pw_gdpr_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance';
  $strongarm->value = array(
    'popup_enabled' => 1,
    'popup_clicking_confirmation' => 0,
    'popup_info' => array(
      'value' => '<p>
	Um abgeordnetenwatch.de für Sie optimal zu gestalten und fortlaufend verbessern zu können, verwenden wir Cookies. Die in diesem Zusammenhang erhobenen Daten werden anonymisiert und nach spätestens 30 Tagen gelöscht. Daher bitten wir Sie um Ihre Einwilligung. Diese können Sie jederzeit widerrufen.
</p>

<p>
	Weitere Informationen zu den Cookies erhalten Sie in unserer Datenschutzerklärung&nbsp;
</p>
',
      'format' => 'managed_content',
    ),
    'use_mobile_message' => 0,
    'mobile_popup_info' => array(
      'value' => '',
      'format' => 'managed_content',
    ),
    'mobile_breakpoint' => '768',
    'popup_agree_button_message' => 'Ich stimme zu',
    'show_disagree_button' => 1,
    'popup_disagree_button_message' => 'Datenschutzerklärung',
    'popup_agreed_enabled' => 0,
    'popup_hide_agreed' => 0,
    'popup_agreed' => array(
      'value' => '<h2>
	Thank you for accepting cookies
</h2>

<p>
	You can now hide this message or find out more about cookies.
</p>
',
      'format' => 'managed_content',
    ),
    'popup_find_more_button_message' => 'More info',
    'popup_hide_button_message' => 'Ausblenden',
    'popup_link' => 'https://www.abgeordnetenwatch.de/datenschutzerklarung#tracking',
    'popup_link_new_window' => 1,
    'popup_position' => FALSE,
    'use_bare_css' => 1,
    'popup_text_hex' => '',
    'popup_bg_hex' => '',
    'popup_height' => '',
    'popup_width' => '',
    'fixed_top_position' => 1,
    'popup_delay' => '1000',
    'disagree_do_not_show_popup' => 0,
    'reload_page' => 0,
    'popup_scrolling_confirmation' => 0,
    'cookie_name' => '',
    'domains_option' => '1',
    'domains_list' => '',
    'exclude_paths' => 'datenschutzerklaerung',
    'exclude_admin_pages' => 1,
    'exclude_uid_1' => 0,
    'script_scope' => 'footer',
    'better_support_for_screen_readers' => 0,
  );
  $export['eu_cookie_compliance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance_cookie_lifetime';
  $strongarm->value = '365';
  $export['eu_cookie_compliance_cookie_lifetime'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance_domain';
  $strongarm->value = '';
  $export['eu_cookie_compliance_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'piwik_codesnippet_before';
  $strongarm->value = '_paq.push([\'disableCookies\']);';
  $export['piwik_codesnippet_before'] = $strongarm;

  return $export;
}
