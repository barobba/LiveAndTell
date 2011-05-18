<?php
$view = new view;
$view->name = 'latalbum_entries';
$view->description = 'LAT Album content';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'field_lnt_image_noderef_nid' => array(
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
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_lnt_image_noderef_nid',
    'table' => 'node_data_field_lnt_image_noderef',
    'field' => 'field_lnt_image_noderef_nid',
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'field_delta_value' => array(
    'order' => 'ASC',
    'delta' => -1,
    'id' => 'field_delta_value',
    'table' => 'node_data_field_delta',
    'field' => 'field_delta_value',
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'field_lnt_album_noderef_nid' => array(
    'default_action' => 'not found',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'field_lnt_album_noderef_nid',
    'table' => 'node_data_field_lnt_album_noderef',
    'field' => 'field_lnt_album_noderef_nid',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
      '7' => 0,
      '5' => 0,
      '4' => 0,
      '6' => 0,
      '3' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'blog' => 0,
      'forum' => 0,
      'panel' => 0,
      'alphabet' => 0,
      'app' => 0,
      'app_function' => 0,
      'bmm' => 0,
      'bmm_affix' => 0,
      'book' => 0,
      'developer_blog_entry' => 0,
      'general_entry' => 0,
      'image' => 0,
      'image_embedded' => 0,
      'jarobba_dictionary' => 0,
      'latapp' => 0,
      'lat_admin_bookmark' => 0,
      'lat_channel' => 0,
      'lat_customer_subscription' => 0,
      'lesson_plan' => 0,
      'lnt_album' => 0,
      'lnt_album_entry' => 0,
      'lnt_image' => 0,
      'lnt_phrase' => 0,
      'lnt_term' => 0,
      'media_reference' => 0,
      'mmd' => 0,
      'mmde' => 0,
      'og_group' => 0,
      'page' => 0,
      'picture_notebook' => 0,
      'profile' => 0,
      'profile_theme' => 0,
      'song' => 0,
      'story' => 0,
      'storybook' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '3' => 0,
      '1' => 0,
      '9' => 0,
      '5' => 0,
      '6' => 0,
      '4' => 0,
      '8' => 0,
      '7' => 0,
    ),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_is_member' => '0',
    'validate_argument_group_node_type' => array(
      'og_group' => 0,
    ),
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'lnt_album_entry' => 'lnt_album_entry',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  ),
  'status_extra' => array(
    'operator' => '=',
    'value' => '',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status_extra',
    'table' => 'node',
    'field' => 'status_extra',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('items_per_page', 0);
$handler->override_option('style_plugin', 'grid');
$handler->override_option('style_options', array(
  'grouping' => '',
  'columns' => '8',
  'alignment' => 'horizontal',
  'fill_single_line' => 1,
));
