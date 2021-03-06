<?php
/*
 * View 'lat_picturebook_teaser_thumbs'
 */
$view = new view;
$view->name = 'lat_picturebook_teaser_thumbs';
$view->description = 'LAT Picture Book Teaser Thumbs';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'field_lnt_image_fid' => array(
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
    'label_type' => 'none',
    'format' => 'square_50_linked',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_lnt_image_fid',
    'table' => 'node_data_field_lnt_image',
    'field' => 'field_lnt_image_fid',
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'field_weight_value' => array(
    'order' => 'ASC',
    'delta' => -1,
    'id' => 'field_weight_value',
    'table' => 'node_data_field_weight',
    'field' => 'field_weight_value',
    'relationship' => 'none',
  ),
  'created' => array(
    'order' => 'ASC',
    'granularity' => 'day',
    'id' => 'created',
    'table' => 'node',
    'field' => 'created',
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'field_lnt_album_noderef_nid' => array(
    'default_action' => 'empty',
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
      '5' => 0,
      '4' => 0,
      '6' => 0,
      '3' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'blog' => 0,
      'forum' => 0,
      'alphabet' => 0,
      'app_function' => 0,
      'bmm' => 0,
      'bmm_affix' => 0,
      'book' => 0,
      'developer_blog_entry' => 0,
      'general_entry' => 0,
      'jarobba_dictionary' => 0,
      'lat_admin_bookmark' => 0,
      'lat_channel' => 0,
      'lat_customer_subscription' => 0,
      'lesson_plan' => 0,
      'lnt_album' => 0,
      'lnt_image' => 0,
      'lnt_phrase' => 0,
      'lnt_term' => 0,
      'mmd' => 0,
      'mmde' => 0,
      'og_group' => 0,
      'page' => 0,
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
      '5' => 0,
      '6' => 0,
      '4' => 0,
      '8' => 0,
      '7' => 0,
    ),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_is_member' => 'OG_VIEWS_DO_NOT_VALIDATE_MEMBERSHIP',
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
      'lnt_image' => 'lnt_image',
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
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('items_per_page', 7);
