<?php
// $Id: template.php,v 1.21 2009/08/12 04:25:15 johnalbin Exp $

/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
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

  //watchdog('latzen', $_REQUEST['q'] . "\n" . dpr($vars, TRUE), NULL, WATCHDOG_INFO);
  
  $vars['classes_array'] = array_merge(
    $vars['template_files'],
    $vars['classes_array']
  );
  
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
