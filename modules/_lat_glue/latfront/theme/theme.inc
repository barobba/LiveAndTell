<?php

/**
 * HOOK_PREPROCESS_[LAT_FRONTPAGE]
 */
function latfront_preprocess_lat_frontpage(&$vars) {
  if (!user_is_logged_in()) {
    $vars['lat_signup_notice'] = theme('lat_signup_notice');
  }
  $vars['lat_language_list'] = theme('lat_language_list', 'table');
  $vars['lat_frontpage_users'] = views_embed_view('lat_frontpage_users');
  $vars['lat_frontpage_content'] = views_embed_view('lat_frontpage_content');
}
