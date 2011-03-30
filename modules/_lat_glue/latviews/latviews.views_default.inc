<?php

/**
 * Implementation of hook_views_default_views().
 *
 * Steps:
 *   1. Scans the directory for views
 *   2. Loads the code for each view, and adds the results to an array
 *   3. Returns the array of view data
 */
function latviews_views_default_views() {
  
  // Scan the directory for views
  $path = drupal_get_path('module', 'latviews');
  $views_export_files = file_scan_directory(
    "$path/views", '\.inc$', 
    array('.', '..', 'CVS'), 0, TRUE, 'name'
  );
  
  // Loads each view in turn, and adds the results to the list  
  $view_names = array_keys($views_export_files);
  foreach ($view_names as $view_name) {
    //$view = array();
    include "$path/views/$view_name.inc";
    $views[$view_name] = $view;
  }
  return $views;
}
