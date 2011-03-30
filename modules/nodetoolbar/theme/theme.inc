<?php

function nodetoolbar_preprocess_nodetoolbar(&$vars) {
  $toolbar_name = $vars['toolbar_name'];
  $node = $vars['node'];
  if (isset($node->toolbar[$toolbar_name])) {
    $items = $node->toolbar[$toolbar_name];
    $items = array_map('nodetoolbar_render_item', $items);
    $vars['nodetoolbar_items'] = $items;
    $vars['nodetoolbar_items_rendered'] = implode(' ', $items);
  }
}

function nodetoolbar_render_item($item) {
  switch($item) {
    case '|':
      return theme('nodetoolbar_separator');
      break;
    default:
      return $item;
      break;
  }
}
