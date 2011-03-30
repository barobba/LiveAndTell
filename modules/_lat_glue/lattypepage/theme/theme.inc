<?php

/**
 * Implementation of hook_preprocess_typepage().
 */
function typepage_preprocess_typepage(&$vars) {

  $type = $vars['type'];
  //$lat_types = variable_get('typepage_types', array());
  $lat_types = array(
    'lesson_plan' => array(
      'type' => 'lesson_plan', 
      'path label' => 'Lesson plan',
      'path name' => 'lesson',
      'new content view' => 'lessons_by_date',
      'author view' => 'authors_by_type_lang',
    ),
    'song' => array(
      'type' => 'song', 
      'path label' => 'Song',
      'path name' => 'song',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'blog' => array(
      'type' => 'blog', 
      'path label' => 'Blog',
      'path name' => 'blog',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'general_entry' => array(
      'type' => 'general_entry', 
      'path label' => 'General entry',
      'path name' => 'general-entry',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'bmm' => array(
      'type' => 'bmm', 
      'path label' => 'Affixing',
      'path name' => 'affixing',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'lnt_album' => array(
      'type' => 'lnt_album', 
      'path label' => 'Album',
      'path name' => 'album',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'mmd' => array(
      'type' => 'mmd', 
      'path label' => 'Dictionary',
      'path name' => 'dictionary',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
  );

  $node_types = node_get_types();

  // Create two lists of languages: used, and unused.
  // Used languages have lesson plans made for them.
  // Unused languages do not
  $vocabulary = taxonomy_vocabulary_load(1);
  $terms = taxonomy_get_tree($vocabulary->vid);
  foreach ($terms as $term) {
    // Skip the 'Any' term
    if ($term->name == 'Any') {
      continue;
    }

    // Get the node count
    $count = taxonomy_term_count_nodes($term->tid, $type);

    // Format term name for url
    $term_lower = drupal_strtolower($term->name);
    $type_path_name = $lat_types[$type]['path name'];
    $term_url = "$type_path_name/$term_lower";
    
    // If greater than 0, add to language list
    if ($count > 0) {
      $count_name = ($count == 1) ? "book" : "books";
      $items[] = l("$term->name ($count $count_name)", $term_url);
    }
    else {
      $items_unused[] = l("$term->name", $term_url);
    }
  }

  // Add to template vars
  $vars['languages_used'] = $items ? theme('item_list', $items) : "(None)";
  $vars['languages_unused'] = $items_unused ? theme('item_list', $items_unused) : "(None)";
  $vars['language_form'] = drupal_get_form('_typepage_form');
}

/**
 * Implementation of lesson_preprocess_typepage_by_language().
 */
function typepage_preprocess_typepage_by_language(&$vars) {

  //$lat_types = variable_get('typepage_types', array());
  $lat_types = array(
    'lesson_plan' => array(
      'type' => 'lesson_plan', 
      'path label' => 'Lesson plan',
      'path name' => 'lesson',
      'new content view' => 'lessons_by_date',
      'author view' => 'authors_by_type_lang',
    ),
    'song' => array(
      'type' => 'song', 
      'path label' => 'Song',
      'path name' => 'song',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'blog' => array(
      'type' => 'blog', 
      'path label' => 'Blog',
      'path name' => 'blog',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'general_entry' => array(
      'type' => 'general_entry', 
      'path label' => 'General entry',
      'path name' => 'general-entry',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'bmm' => array(
      'type' => 'bmm', 
      'path label' => 'Affixing',
      'path name' => 'affixing',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'lnt_album' => array(
      'type' => 'lnt_album', 
      'path label' => 'Album',
      'path name' => 'album',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
    'mmd' => array(
      'type' => 'mmd', 
      'path label' => 'Dictionary',
      'path name' => 'dictionary',
      'new content view' => 'new_content_by_type_and_language',
      'author view' => 'authors_by_type_lang',
    ),
  );

  $node_types = node_get_types();
 
  $type = $vars['type'];
  $type_as_path = str_replace('_', '-', $type);
  $type_name = $node_types[$type]->name;
  $type_path_label = $lat_types[$type]['path label'];
  $type_path_name = $lat_types[$type]['path name'];
  $type_new_content_view = $lat_types[$type]['new content view'];
  $type_author_view = $lat_types[$type]['author view'];

  // Check for valid language
  if ($language = reset(taxonomy_get_term_by_name($vars['language']))) {
  
    // Set title
    //drupal_set_title(t("@language", array('@language' => $language->name)));
    drupal_set_title($language->name.' - '.$type_name);
    
    // Construct breadcrumb
    $breadcrumb[] = l(t('Home'), NULL);
    $breadcrumb[] = l($type_path_label, $type_path_name);
    $breadcrumb[] = l($language->name, $_REQUEST['q']);
    drupal_set_breadcrumb($breadcrumb);
    
    $vars['language'] = $language->name;
    $vars['language_lower'] = drupal_strtolower($language->name);

    // Set redirect destination
    $destination = 'destination='. drupal_urlencode($_GET['q']);

    if (!$GLOBALS['user']->uid) {
      if (variable_get('user_register', 1)) {
        // Users can register themselves.
        $vars['create_link'] = t('<a href="@login">Login</a> or <a href="@register">register</a> to create pages', array('@login' => url('user/login', array('query' => $destination)), '@register' => url('user/register', array('query' => $destination))));
      }
      else {
        // Only admins can add new users, no public registration.
        $vars['create_link'] = t('<a href="@login">Login</a> to create pages', array('@login' => url('user/login', array('query' => $destination))));
      }
    }
    else {
      //$vars['create_link'] = l("Create $type_name", 'node/add/'.$type_as_path.'/language/'.$language->tid, array('attributes' => array('class' => 'link-button')));
      $vars['create_link']  = l("Create page", 'node/add/'.$type_as_path.'/language/'.$language->tid, array('attributes' => array('class' => 'link-button')));
      $vars['create_link'] .= '<div class="description">Use this button to add a new '.$type_name.'</div>';
    }

    // Provide views (popular, author, new)
    $vars['type_name'] = $type_name;
    $vars['content_new'] = views_embed_view($type_new_content_view, 'default', $language->name, $type);
    $vars['content_authors'] = views_embed_view($type_author_view, 'default', $language->name, $type);
  }
  // If not a valid language, redirect
  else {
    drupal_goto($type_path_name);
  }
}

/**
 * Implementation of lesson_preprocess_lesson_language_author().
 */
function typepage_preprocess_typepage_by_language_and_author(&$vars) {

  // Check for valid language and account
  $language = reset(taxonomy_get_term_by_name($vars['language']));
  $account = user_load($vars['author_id']);  

  // Check for valid account and language   
  if ($account && $language) {
  
    // Set title
    drupal_set_title(t("@author's Lesson Plans for @language", array('@author' => $account->name, '@language' => $language->name)));

    // Construct breadcrumb
    $home = l(t('Home'), NULL);
    $lessons = l(t('Lesson Plans'), 'lessons');
    $lang = l(t('%language', array('%language' => $language->name)), 'lessons/'.$language->name);
    drupal_set_breadcrumb(array($home, $lessons, $lang));
    
    // Provide views (popular, author, new)
    //$vars['lesson_popular'] = views_embed_view('lessons_by_popularity', 'default', $language->name);
    //$vars['lesson_authors'] = views_embed_view('lesson_authors_by_language', 'default', $language->name);    
    //$vars['lesson_new'] = views_embed_view('lessons_by_date', 'default', $language->name);
  }
  else {
    drupal_goto('lessons');
  }
}
