<?php

function lattheme_filter_tips() {
  return ''; 
}

function lattheme_filter_tips_more_info() {
  return ''; 
}

/**
 * HOOK_PREPROCESS_PAGE
 */
function lattheme_preprocess_page(&$vars) {

  //HTML xml:lang, lang, direction
  $vars['page_language'] = $vars['language']->language;
  $vars['page_language_dir'] = $vars['language']->dir;
  $vars['site_name_linked_to_front'] = l(variable_get('site_name', '(Site Name Undefined)'), '<front>');

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

function lattheme_preprocess_node(&$vars) {

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
  if ($user->profile_firstname) {
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
  $vars['lat_node_language'] = $language_node_terms[0]->name;
  
}
