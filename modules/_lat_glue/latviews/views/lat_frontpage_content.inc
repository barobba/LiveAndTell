<?php
/*
 * View 'lat_frontpage_content'
 */
$view = new view;
$view->name = 'lat_frontpage_content';
$view->description = 'LAT Frontpage Content';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'field_admin_bookmark_noderef_nid' => array(
    'label' => 'Bookmarked',
    'required' => 1,
    'delta' => -1,
    'id' => 'field_admin_bookmark_noderef_nid',
    'table' => 'node_data_field_admin_bookmark_noderef',
    'field' => 'field_admin_bookmark_noderef_nid',
    'relationship' => 'none',
  ),
));
$handler->override_option('fields', array(
  'title' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
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
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'field_admin_bookmark_noderef_nid',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('style_options', NULL);
$handler->override_option('row_plugin', 'node');
$handler->override_option('row_options', array(
  'relationship' => 'field_admin_bookmark_noderef_nid',
  'build_mode' => 'teaser',
  'links' => 0,
  'comments' => 0,
));
