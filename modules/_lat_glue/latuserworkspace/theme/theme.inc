<?php
/**
 * GO THROUGH THE LIST OF CONTENT-TYPES, AND ADD IT TO AN ARRAY IF THE USER HAS ACCESS TO IT.
 * THEN, THEME THE LIST AND RETURN THE RESULTS
 */
 
function latuserworkspace_preprocess_lat_user_workspace(&$vars) {

  $user = $GLOBALS['user'];
  $path = drupal_get_path('module', 'latuserworkspace');
  
  // Add javascript for this page
  drupal_add_js("$path/theme/js/latuserworkspace-user-workspace.js");
  
  // Hide title
  drupal_set_title('');

  // TODO Move this constant to an admin form
  // Prepare content menu
  $types = node_get_types();
  $use_types = array(
    'bmm',             //Affixing
    'lesson_plan',     //Lesson plan
    'lnt_album',       //Picture book
    'song',            //Song
    'mmd',             //Workbook
  ); 
  foreach ($types as $type) {
    if (in_array($type->type, $use_types) && node_access('create', $type->type, $user)) {
      $image = theme('lat_nodetype_icon', $type->type);
      $link = l($type->name, 'node/add/'.str_replace('_', '-', $type->type), array('query' => array('destination' => 'user/redirect/workspace')));
      $link = l($type->name, 'lat/user/workspace/add/'.str_replace('_', '-', $type->type));
      $items []= "$image $link";      
    }
  }

  // Variables  
  $vars['lat_create_content_menu'] = theme('item_list', $items);
  $vars['lat_content_table'] = views_embed_view('lat_user_workspace_content', 'default', $user->uid);
  
}
