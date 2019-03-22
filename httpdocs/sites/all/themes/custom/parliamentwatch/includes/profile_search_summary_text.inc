<?php

/**
 * Here we create the profile search summary text. We have the default case
 * where constituencies can be filtered and where cosntituencies should
 * be mentioned in the search summary text. For EU 2019 we do not want
 * to mention constituency in search summary text.
 */


/**
 * Create the search summary text mentioning constituencies in result
 *
 * @param array $variables
 * The variables array sent to theme_profile_search_summary
 */
function profile_search_summaray_with_constituency($variables, $link_options, $constituency_context, &$options) {
  $facets = $variables['response']['search_api_facets'];

  if (!empty($variables['filters']['constituency'])) {
    $constituency = taxonomy_term_load((int) $variables['filters']['constituency']);
    $url = url(current_path(), $link_options + ['query' => _pw_profiles_reject_filter($variables['filters'], 'constituency')]);
    $constituencies_text = t('<span>in</span> <a href="@url" class="filter-summary__content__link">constituency @name</a>', ['@name' => $constituency->name, '@url' => $url], ['context' => $constituency_context]);
    $options['!constituencies'] = $constituencies_text;
  }
  else {
    $facet_values = _pw_profiles_facet_values($facets['field_user_constituency']);
    $constituencies_count = count($facet_values);
    $constituencies = taxonomy_term_load_multiple($facet_values);
    $constituencies_text = format_plural($constituencies_count, 'in constituency @name', 'and @count constituencies', ['@name' => reset($constituencies)->name], ['context' => $constituency_context]);
    $options['!constituencies'] = "<span>$constituencies_text</span>";
  }

  if (empty($variables['filters']['gender'])) {
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1 candidate from</span> !parties !constituencies', '<span>Found @count candidates from</span> !parties !constituencies', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1 deputy from</span> !parties !constituencies', '<span>Found @count deputies from</span> !parties !constituencies', $options);
    }
  }
  elseif ($variables['filters']['gender'] == ['male' => 'male', 'female' => 'female']) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female or male</a> <span>candidate from </span> !parties !constituencies','<span>Found @count <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female and male</a> <span>candidates from </span> !parties !constituencies', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female or male</a> <span>deputy from </span> !parties !constituencies','<span>Found @count <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female and male</a> <span>deputies from </span> !parties !constituencies', $options);
    }
  }
  elseif (!empty($variables['filters']['gender']['male'])) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>candidate from</span> !parties !constituencies', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>candidates from</span> !parties !constituencies', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>deputy from</span> !parties !constituencies', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>deputies from</span> !parties !constituencies', $options);
    }
  }
  elseif (!empty($variables['filters']['gender']['female'])) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>candidate from </span> !parties !constituencies', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>candidates from </span> !parties !constituencies', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>deputy from </span> !parties !constituencies', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>deputies from </span> !parties !constituencies', $options);
    }
  }


  return $summary;
}


/**
 * Create the search summary text without mentioning constituencies in result
 *
 * @param array $variables
 * The variables array sent to theme_profile_search_summary
 */
function profile_search_summaray_without_constituency($variables, &$options) {
  if (empty($variables['filters']['gender'])) {
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1 candidate from</span> !parties', '<span>Found @count candidates from</span> !parties', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1 deputy from</span> !parties', '<span>Found @count deputies from</span> !parties', $options);
    }
  }
  elseif ($variables['filters']['gender'] == ['male' => 'male', 'female' => 'female']) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female or male</a> <span>candidate from </span> !parties','<span>Found @count <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female and male</a> <span>candidates from </span> !parties', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female or male</a> <span>deputy from </span> !parties','<span>Found @count <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female and male</a> <span>deputies from </span> !parties', $options);
    }
  }
  elseif (!empty($variables['filters']['gender']['male'])) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>candidate from</span> !parties', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>candidates from</span> !parties', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>deputy from</span> !parties', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">male</a> <span>deputies from</span> !parties', $options);
    }
  }
  elseif (!empty($variables['filters']['gender']['female'])) {
    $options['@url'] = url(current_path(), ['query' => _pw_profiles_reject_filter($variables['filters'], 'gender')]);
    if ($variables['role_name'] == 'candidates') {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>candidate from </span> !parties', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>candidates from </span> !parties', $options);
    }
    else {
      $summary = format_plural($variables['response']['result count'], '<span>Found 1</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>deputy from </span> !parties', '<span>Found @count</span> <a href="@url" class="@class" data-ajax-target="@data-ajax-target">female</a> <span>deputies from </span> !parties', $options);
    }
  }


  return $summary;
}
