<?php

// CTools plugin variable
// Scope limited to CTools plugin system

$plugin = array(
  'title' => t('"Create Notebook" form'),
  'description' => t('A form for creating new notebooks'),
  'single' => TRUE,                                         // No subtypes
  'content_types' => array('notebookform_content_type'),    // Content constructor (same as plugin file name)
  'render callback' => 'latnb_notebookform_pctfactory',     // Block object factory
  'defaults' => array(),                                    // Default contexts
  'edit form' => 'latnb_notebookform_pctform',              // Content settings form [return array()?]
  'icon' => 'icon_node_form.png',                           // Icon
  'category' => array(t('LiveAndTell'), 0),                 // Category
);

function latnb_notebookform_pctfactory($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = "Notebook Form";
  $block->content = drupal_get_form('latnb_activityform');
  return $block;
}

function latnb_notebooksform_pctform() {
  return array();
}
