<?php

/**
 * Preprocessor for theme_lat_langnav_languages_overview().
 */
function latlangnav_preprocess_lat_language_generic_menu(&$vars) {
  drupal_set_breadcrumb(array(l('Home', NULL), l('Languages', $_REQUEST['q'])));
  $vars['active_languages'] = theme('lat_language_list', 'item_list');
}

/**
 * Preprocessor for theme_lat_langnav_language().
 */
function latlangnav_preprocess_lat_language_content_summary(&$vars) {

  // Added by Chris Martian
  // $user = $GLOBALS['user'];
  // variable_set($user->uid.'_lat_term', $vars['language_term']); // USER-DEFINED LANGUAGE
  
  $language_name = $vars['language']; // Uncapitalized language name, passed in from the menu path
  $language = reset(taxonomy_get_term_by_name($language_name));
  if ($language) {
  
    // Set page breadcrumb and title
    drupal_set_breadcrumb(array(l('Home', NULL), l('Languages', 'language'), l($language->name, $_REQUEST['q'])));
    drupal_set_title($language->name);
    
    // Added by Chris Martian
    //$vars['language'] = $vars['language_term']->name;
    //$vars['language_id'] = $vars['language_term']->tid;
    
    $vars['language'] = $language->name; // Capitalized language name
    $vars['language_lower'] = drupal_strtolower($language->name);
    $vars['recent_content'] = views_embed_view('new_content_by_language', 'default', $language->name);
    $vars['authors'] = views_embed_view('authors_by_lang', 'default', $language->name);
    $vars['content_type_list_by_language'] = theme('lat_language_nodetype_list_by_language', $language, 'table');

  }
}

/**
 * Return the row count of a view
 */
function _latlangnav_views_row_count($view_name, $display = 'default', $args = array()) {
  $view = views_get_view($view_name);
  $view->get_total_rows = true;
  $view->set_display($display);
  $view->set_arguments($args);
  $view->execute();
  return $view->total_rows;
}

/**
 * Implementation of theme_latlanguage_list().
 * 
 * Theme a list of languages variable, with counts
 * Format: 'table', or 'item_list'
 */
function theme_lat_language_list($format = 'table') {
  
  $language_vocabulary_id = variable_get('latlangnav_vid', null);
  $language_terms = taxonomy_get_tree($language_vocabulary_id); // Get terms for Language vocabulary
  $is_content_found = false;

  foreach ($language_terms as $language_term) {
    
    // Skip the "Any" term
    if ($language_term->name == 'Any') { 
      continue; 
    }

    // Get content count per language
    $view = views_get_view('public_content_by_language'); // Should be named "lat_language_content_by_language"; the "public" part is omitted by definition.
    $view->preview('default', array($language_term->tid));
    $count = count($view->result);

    // Prepare language list variables  
    if ($count > 0) {
      $is_content_found = true;
      $lang_names  []= $language_term->name;
      $lang_urls   []= url();
      $lang_counts []= $count;
    }
    
  }

  // Break early if content is nonexistant
  if (!$is_content_found) {
    return '';
  }

  // Sort by count decreasing
  array_multisort($lang_counts, SORT_DESC, $lang_names, $lang_urls);
  
  switch($format) {
  
    case 'table':
      foreach ($lang_names as $index => $language_name) {
        $lang_count = $lang_counts[$index];        
        $language_link = l($language_name, 'language/'.drupal_strtolower($language_name));        
        $lang_table []= array($language_link, $lang_count); 
      }
      $lat_language_list = theme('table', array('Languages', 'Posts'), $lang_table);
      break;
      
    case 'item_list':
      foreach ($lang_names as $index=> $language_name) {
        $lang_count = $lang_counts[$index];
        $lang_item_list []= l("$language_name ($lang_count posts)", 'language/'.drupal_strtolower($language_name));
      }
      $lat_language_list = theme('item_list', $lang_item_list, 'Languages');
      break;
      
  }
  
  $lat_language_list = "<div class='lat-language-listing'>$lat_language_list</div>";
  return $lat_language_list;
  
}

/**
 * Implementation of theme_lat_nodetype_list_by_language().
 * 
 * Links for filtering content per nodetype, per language
 */
function theme_lat_language_nodetype_list_by_language($language_term, $format = 'item_list') {

  $node_types = node_get_types();
  $active_type_names = array(
    'bmm',          //Affixing
    'lesson_plan',  //Lesson plans
    'lnt_album',    //Picture books
    'song',         //Songs
    'mmd'           //Workbooks
  );

  
  foreach ($active_type_names as $active_type_name) {
    // SHOULD BE BASED ON A VIEW OF PUBLIC CONTENT
    $nodetype_term_count = taxonomy_term_count_nodes($language_term->tid, $active_type_name);
    if ($nodetype_term_count > 0) {
      
      // Append the term count to the node type objects, which have nodes of a particular language 
      $node_types[$active_type_name]->nodetype_term_count = $nodetype_term_count;
      
      // Get a list of node type objects, which have nodes of a particular language
      $active_types []= $node_types[$active_type_name];
      
    }
  }

  if ($active_types) {
    switch($format) {
      
      case 'table':
        foreach ($active_types as $active_type) {
          $path = drupal_strtolower($active_type->name).'/'.drupal_strtolower($language_term->name);
          $path = str_replace(' ', '-', $path);
          $type_cell = l($active_type->name, $path);
          $type_count = $active_type->nodetype_term_count;
          $table []= array($type_cell, $count_cell);
        }
        $content = theme('table', array('Types', 'Posts'), $table);
        break;
        
      case 'item_list':
        foreach ($active_types as $active_type) {
          $path = drupal_strtolower($active_type->name).'/'.drupal_strtolower($language_term->name);
          $path = str_replace(' ', '-', $path);
          $type_name = $active_type->name;
          $type_count = $active_type->nodetype_term_count;
          $items []= l("$type_name ($type_count)", $path);
        }
        $content = theme('item_list', $items);
        break;
        
    }
  } else {
    $content = '(None)';
  }
  
  $content = "<div class='lat-nodetype-list-by-language'>$content</div>";
  return $content;
}
