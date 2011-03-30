<?php

function template_preprocess_lat_user_nextsteps(&$vars) {
  drupal_set_title('');
  //profile_load_profile($vars['user']);
  $links = array(
    'Browse - View site content' => '<front>',
    'Create a workbook - To keep track of new words and phrases' => 'node/add/lat-workbook',
    'View your stuff - View all of your content' => 'lat/user/workspace',
  );
  foreach ($links as $title => $url) {
    $items []= l($title, $url);
  }
  $vars['lat_user_nextsteps_menu'] = theme('item_list', $items);
}
