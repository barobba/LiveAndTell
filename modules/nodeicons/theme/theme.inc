<?php

// TODO: THE ICONS SHOULD BE STORED WITH NODE, TO PREVENT LOOKUPS HERE.
function theme_lat_nodetype_icon($nodetype, $preset = '') {

  static $path;
  if (!$path) {
    $path = drupal_get_path('module', 'nodeicons');
  }

  // TODO PLACE CONSTANTS IN ADMIN FORM
  static $nodetype_icons = array(
    'lnt_album', 
    'lnt_image',
    'lesson_plan', 
    'lat_workbook',
    'song',
  );  
  
  if (!$preset) {
    if (in_array($nodetype, $nodetype_icons)) {
      $image = theme('image', "$path/theme/images/icon-type-$nodetype.png");
    } else {
      $image = theme('image', "$path/theme/images/icon-type-default.png");
    }
  } else {
    if (in_array($nodetype, $nodetype_icons)) {
      $image = theme('imagecache', $preset, "$path/theme/images/icon-type-$nodetype.png");
    } else {
      $image = theme('imagecache', $preset, "$path/theme/images/icon-type-default.png");
    }
  }
  
  return $image;
  
}
