<?php
/*
 * View 'lat_cust_subscrip_content'
 */
$view = new view;
$view->name = 'lat_cust_subscrip_content';
$view->description = 'LAT Customer Subscription Content';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('arguments', array(
  'nid' => array(
    'default_action' => 'empty',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'node',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
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
      'lat_customer_subscription' => 'lat_customer_subscription',
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
      'bmm' => 'bmm',
      'lesson_plan' => 'lesson_plan',
      'lnt_album' => 'lnt_album',
      'mmd' => 'mmd',
      'song' => 'song',
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
$handler->override_option('empty', 'This user has not published any content.');
$handler->override_option('empty_format', '1');
$handler->override_option('items_per_page', 0);
$handler->override_option('row_plugin', 'node');
$handler->override_option('row_options', array(
  'relationship' => 'none',
  'build_mode' => 'teaser',
  'links' => 0,
  'comments' => 0,
));
