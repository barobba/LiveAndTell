<?php
/*
 * View 'authors_by_lang'
 */
$view = new view;
$view->name = 'authors_by_lang';
$view->description = 'Authors of content by language';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'uid' => array(
    'label' => 'Uid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_user' => 0,
    'exclude' => 1,
    'id' => 'uid',
    'table' => 'users',
    'field' => 'uid',
    'relationship' => 'none',
  ),
  'picture' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '<a href="/user/[uid]">[picture]</a>',
      'make_link' => 1,
      'path' => 'user/[uid]',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'imagecache_preset' => 'square_55',
    'exclude' => 0,
    'id' => 'picture',
    'table' => 'users',
    'field' => 'picture',
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'name' => array(
    'order' => 'ASC',
    'id' => 'name',
    'table' => 'users',
    'field' => 'name',
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'tid' => array(
    'default_action' => 'empty',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'taxonomy_term',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'add_table' => 0,
    'require_value' => 0,
    'reduce_duplicates' => 1,
    'set_breadcrumb' => 0,
    'id' => 'tid',
    'table' => 'term_node',
    'field' => 'tid',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
      '4' => 0,
      '3' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'app_function' => 0,
      'bmm' => 0,
      'bmm_affix' => 0,
      'book' => 0,
      'image_annotation' => 0,
      'lesson_plan' => 0,
      'lnt_album' => 0,
      'lnt_image' => 0,
      'lnt_phrase' => 0,
      'lnt_term' => 0,
      'mmd' => 0,
      'mmde' => 0,
      'page' => 0,
      'story' => 0,
      'test_container' => 0,
      'test_item' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '1' => 1,
      '2' => 0,
    ),
    'validate_argument_type' => 'convert',
    'validate_argument_transform' => 1,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('empty', '(None)');
$handler->override_option('empty_format', '1');
$handler->override_option('items_per_page', 0);
$handler->override_option('distinct', 1);
$handler->override_option('style_options', array(
  'grouping' => '',
));
$handler->override_option('row_options', array(
  'inline' => array(
    'uid' => 'uid',
    'picture' => 'picture',
  ),
  'separator' => '',
  'hide_empty' => 0,
));
