<?php

/**
 * hook_preprocess_{lat_frontpage}
 */
function latfront_preprocess_lat_frontpage(&$vars) {
  drupal_set_title('');
  $vars['lat_signup_notice'] = user_is_logged_in() ? '' : theme('lat_signup_notice');
  $vars['lat_language_list'] = theme('lat_language_list', 'table');
  $vars['lat_frontpage_users'] = views_embed_view('lat_frontpage_users');
  $vars['lat_frontpage_content'] = views_embed_view('lat_frontpage_content');
}
