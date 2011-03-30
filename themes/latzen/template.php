<?php
// $Id: template.php,v 1.21 2009/08/12 04:25:15 johnalbin Exp $

/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to latzen_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: latzen_breadcrumb()
 *
 *   where latzen is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */


/**
 * Implementation of HOOK_theme().
 */
function latzen_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);
  // Add your theme hooks like this:
  /*
  $hooks['hook_name_here'] = array( // Details go here );
  */
  // @TODO: Needs detailed comments. Patches welcome!
  return $hooks;
}

/**
 * Override or insert variables into all templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function latzen_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Implementation of theme_preprocess_page().
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */

function latzen_preprocess_page(&$vars) {
  
  if ($vars['is_front']) {
    $vars['title'] = '';
  }

  //Navigation classes  
  $vars['navigation_links']
    = !empty($primary_links)? " withprimary" : ''
    . !empty($secondary_links)? " withsecondary" : '';

  //Rendering of primary and secondary links
  $vars['primary_links_rendered'] = theme('links', $vars['primary_links'], 
    array('class' => 'links primary-links'));
  $vars['secondary_links_rendered'] = theme('links', $vars['secondary_links'], 
    array('class' => 'links secondary-links'));
  
}

/**
 * Implementation of theme_preprocess_node().
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function latzen_preprocess_node(&$vars) {

  // Node variable
  $node = $vars['node'];

  // User variable
  static $user;
  if (!$user || $user->uid != $node->uid) {
    $user = user_load(array('uid' => $node->uid));
  }

  // Configure template files for teaser nodes
  $is_teaser = $vars['teaser'];
  if ($is_teaser) {
    $vars['template_files'][] = 'teaser';
    $vars['template_files'][] = 'teaser-'. $vars['node']->type;  
  } else {
    // Use the default template files
  }  
  
  //
  // Node class values
  //
  // These are more descriptive and semantic namings
  //
  
  $vars['node_classes']  = 'node';
  $vars['node_classes'] .= ' node-type-'.$node->type;
  $vars['node_classes'] .= $vars['sticky']? ' sticky' : '';
  $vars['node_classes'] .= $vars['status']? ' published' : ' un-published';
  $vars['node_classes'] .= $vars['teaser']? ' node-teaser' : '';
  $vars['node_classes'] .= $vars['page']? ' node-page' : '';
  $vars['node_classes'] .= ' clear-block';

  // Node author
  if (property_exists($user, 'profile_firstname')) {
    $vars['lat_node_author'] = l($user->profile_firstname.' '.$user->profile_lastname, 'user/'.$user->uid); 
  }
  else {
    $vars['lat_node_author'] = l($user->name, 'user/'.$user->uid); 
  }  

  // Node posted date 
  $vars['lat_node_posted_date'] = date('n/j/Y g:ia', $vars['created']);
  
  // Node "view more" link
  $vars['lat_node_view_more'] = l('View more', 'node/'.$node->nid);
  
  // Node language
  $language_tid = 1;
  $language_node_terms = array_values(taxonomy_node_get_terms_by_vocabulary($node, $language_tid));
  if ($language_node_terms) {
    $vars['lat_node_language'] = $language_node_terms[0]->name;
  }
  
}
 

/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function latzen_preprocess_comment(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function latzen_preprocess_block(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

function latzen_filter_tips() {
  return ''; 
}

function latzen_filter_tips_more_info() {
  return ''; 
}
