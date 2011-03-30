<?php

/**
 * @file
 *
 * Allows an admin to create and edit relationships.
 */
 
/**
 * Admin
 * 
 * The admin page for this module.
 * Build and return the appropriate form for add/edit/remove operations.
 */
function relationships_admin($parent_url, $child_url, $op) { 

  // Convert "url-formatted" content type names into
  // "machine-readable" and "human-readable" content types names.
  // For example "my-type" becomes "my_type", and "My Type".
  
  $parent_type = str_replace('-', '_', $parent_url);
  $parent_name = node_get_types('name', $parent_type);
  
  $child_type = str_replace('-', '_', $child_url);
  $child_name = node_get_types('name', $child_type);
  
  if (empty($op)) {
    $op = 'add';
  }
  
  switch($op) {
    case 'add':
      drupal_set_title(t('!parent', array('!parent' => $parent_name)));
      return drupal_get_form('relationships_add_form', $parent_type);
    case 'edit':
      drupal_set_title(t('!parent : %child', array('!parent' => $parent_name, '%child' => $child_name)));
      return drupal_get_form('relationships_edit_form', $parent_type, $child_type);
    case 'remove':
      drupal_set_title(t('!parent : %child', array('!parent' => $parent_name, '%child' => $child_name)));
      return drupal_get_form('relationships_remove_form', $parent_type, $child_type);
    default:
      drupal_set_title(t('Unexpected operation'));
      print t('The operation "!op" is unexpected.', array('!op' => $op));
      break;
  }
}


/**
 * Form Builder.  Builds the 'add' page for Relationships.
 */
function relationships_add_form(&$form_state, $parent_type) {
  
  $parent_name = node_get_types('name', $parent_type ); 
  
  // Construct form  
  $form = array();

  // Display eligible types
  $eligible_types = _relationships_get_eligible_types($parent_type);
  if ($eligible_types) {
    $form['parent_type'] = array(
      '#type' => 'value', 
      '#value' => $parent_type
    );
    $form['child_type'] = array(
      '#title' => t('Eligible Types'),
      '#type' => 'select',
      '#options' => $eligible_types,
      '#description' => t('Unmanaged node types that may be managed by Relationships.'),
    );
    $form['submit'] = array(
      '#type' => 'submit', 
      '#value' => t('Add')
    );
  } else {
    $form['eligible_types_message'] = array(
      '#type' => 'item',
      '#value' => "Either all eligible fields are already managed, or there are no content types that may be managed for $parent_name.",
    );
  }
  
  // Display existing relationships
  $relationships = relationships_load($parent_type);
  if ($relationships) {

    // Construct a table of managed relationships
    $rows = array();
    foreach ($relationships as $relationship) {

      // Prepare operations for this relationship (as links) 
      $parent_url = str_replace('_', '-', $parent_type);
      $child_url = str_replace('_', '-', $relationship->child_type);
      $relationship_admin_url = "admin/content/node-type/$parent_url/relationship/$child_url";
      $edit_link = l('edit', "$relationship_admin_url/edit");
      $remove_link = l('remove', "$relationship_admin_url/remove");
      $operations = "$edit_link | $remove_link";

      // Construct table row
      $child_name = node_get_types('name', $relationship->child_type);
      $field_name = $relationship->field_name;
      $rows[] = array($child_name, $field_name, $operations);
      
    }
    $table_header = array(
      t('Managed Type'), 
      t('Managed Field'), 
      t('Configure')
    );
    $table = theme('table', $table_header, $rows);

    // Add table to the form. 
    $form['managed_types'] = array(
      '#type' => 'item',
      '#description' => t('The content types listed here contain a "node reference" field, which Relationships is managing.'),
      '#value' => $table,
    );
  }
  else {
    $form['relationships_message'] = array(
      '#type' => 'item',
      '#value' => "The are currently no managed relationships for $parent_name.",
    );
  }
    
  return $form;
}


/**
 * Form Validator.  Validates the 'add' page for Relationships.
 */
function relationships_add_form_validate(&$form, &$form_state) {
  
  // Make sure selected type is manageable
  $parent_type = $form_state['values']['parent_type'];
  $child_type = $form_state['values']['child_type'];
  $eligible_child_types = _relationships_get_eligible_types($parent_type);
  if (!in_array($child_type, array_keys($eligible_child_types))) {
    form_set_error('child_type', t('The selected node type is not currently manageable.'));
  }
  
}


/**
 * Form Submitter.  Submits the 'add' page for Relationships.
 */
function relationships_add_form_submit(&$form, &$form_state) {  
  
  // Set redirect
  $parent_type = $form_state['values']['parent_type'];
  $parent_url = str_replace('_', '-', $parent_type);
  $child_type = $form_state['values']['child_type'];
  $child_url = str_replace('_', '-', $child_type);
  $form_state['redirect'] = array("admin/content/node-type/$parent_url/relationship/$child_url/edit");
  
}


/**
 * Form Builder.  Builds the 'edit' page for Relationships.
 */
function relationships_edit_form(&$form_state, $parent_type, $child_type) {  
  
  $form['parent_type'] = array(
    '#type' => 'value', 
    '#value' => $parent_type
  );
  $form['child_type'] = array(
    '#type' => 'value', 
    '#value' => $child_type
  );
  $form['fields'] = array(
    '#type' => 'fieldset', 
    '#title' => 'Fields'
  );
  
  // Add eligible fields to a radio selection
  $fields = array();
  $eligible_fields = _relationships_get_eligible_nodereference_fields($parent_type, $child_type);
  foreach($eligible_fields as $field => $label) {
    $fields[$field] = $field;
  }    
  $relationship = reset(relationships_load($parent_type, $child_type));
  if (isset($relationship->field_name)) {
    $default_field_value = $relationship->field_name;
  } 
  else {
    $default_field_value = reset(array_keys($fields)); 
  }
  $form['fields']['field_name'] = array(
    '#type' => 'radios',
    '#title' => t('Eligible node reference fields'),
    '#description' => t('Choose which field you would like Relationships to manage.'),
    '#options' => $fields,
    '#default_value' => $default_field_value,
  );
  
  // Add the URL argument options
  $args = array(disable => 'disable', 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  $form['fields']['arg'] = array(
    '#type' => 'select',
    '#title' => t('Path argument NID'),
    '#default_value' => isset($relationship->arg) ? $relationship->arg : 3,
    '#options' => $args,
    '#description' => t('Relationships can auto-fill the reference field whenever a new child node is created.  Select the location in the path where the parent node NID will be passed.'),
  );

  // Add "display" options for the nodereference field
  $form['fields']['hide'] = array(
    '#type' => 'radios',
    '#title' => t('Field visibility'),
    '#description' => t('Choose when you would like Relationships to hide the node reference field.'),
    '#options' => array(
      0 => 'Always hide this field.',
      1 => 'Only hide this field when it contains a value.',
      2 => 'Only hide this field when it does not contain a value.',
      3 => 'Never hide this field',
    ),
    '#default_value' => isset($relationship->hide) ? $relationship->hide : 0,
  );

  // Add a fieldset for the "Settings".
  $form['settings'] = array(
    '#type' => 'fieldset', 
    '#title' => 'Rules'
  );

  // Settings for "authorship".
  $callback_elements = relationships_relationship_edit_form_authorship($form_state, $relationship);
  $form['settings']['authorship'] = $callback_elements; 
  
  // Settings for "publishing status".
  $callback_elements = relationships_relationship_edit_form_publish($form_state, $relationship);
  $form['settings']['publish'] = $callback_elements;    
   
  // Settings for "taxonomy".
  $callback_elements = relationships_relationship_edit_form_vocabs($form_state, $relationship);
  $form['settings']['vocabs'] = $callback_elements;
  
  // Settings for "groups".
  $callback_elements = relationships_relationship_edit_form_groups($form_state, $relationship);
  $form['settings']['groups'] = $callback_elements;

  // Add the Submit button.
  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save')
  );
  
  // Add the Delete link if this relationship already exists.
  if (!empty($relationship)) {  
    $parent_url = str_replace('_', '-', $parent_type);
    $child_url = str_replace('_', '-', $child_type);
    $form['delete'] = array(
      '#type' => 'markup', 
      '#value' => l(t('Delete'), "admin/content/node-type/$parent_url/relationship/$child_url/remove", array('attributes' => array('class' => 'link-button')))
    );
  }
  
  return $form;
}

// Add the "authorship" options
function relationships_relationship_edit_form_authorship(&$form_state, $relationship) {
  $form = array(
    '#type' => 'checkbox',
    '#title' => t('Propagate authorship.'),
    '#description' => t('Check to propagate changes in authorship.'),
    '#default_value' => isset($relationship->propagation_rules['authorship']) ? $relationship->propagation_rules['authorship'] : 1,
  );
  return $form;
}

// Add the "publish" options
function relationships_relationship_edit_form_publish(&$form_state, $relationship) {
  $form = array(
    '#type' => 'checkbox',
    '#title' => t('Propagate published status.'),
    '#description' => t('Check to propagate changes in published status from parent to children.'),
    '#default_value' => isset($relationship->propagation_rules['publish']) ? $relationship->propagation_rules['publish'] : 1,
  );
  return $form;
}

// Add the "group" options
function relationships_relationship_edit_form_groups(&$form_state, $relationship) {
  // TODO: Needs to check if child node is a group post.
  $form = array(
    '#type' => 'checkbox',
    '#title' => t('Propagate group membership.'),
    '#description' => t('Check to propagate changes in group audience from parent to children. The child content type must also be a "Standard group post" or "Wiki group post".'),
    '#default_value' => isset($relationship->propagation_rules['groups']) ? $relationship->propagation_rules['groups'] : 0,
  );
  return $form;
}

// Add the the "taxonomy" options
// Only list the vocabularies for the parent node type.
// THIS IMPLEMENTATION IS PROPOGATING DOWNWARDS (MISSING UPWARDS VERSION).
function relationships_relationship_edit_form_vocabs(&$form_state, $relationship) {

  // Prepare a vocabulary array
  $vocabs = array();
  $parent_vocabs = taxonomy_get_vocabularies($relationship->parent_type);
  foreach($parent_vocabs as $vocab) {
    $vocabs[$vocab->vid] = $vocab->name;
  }

  // Add checkboxes for each vocabulary, from the parent type
  if (!empty($vocabs)) {
    $form = array(
      '#type' => 'checkboxes',
      '#title' => t('Propagate changes in taxonomy'),
      '#default_value' => isset($relationship->propagation_rules['vocabs']) ? $relationship->propagation_rules['vocabs'] : array(),
      '#options' => $vocabs,
      '#description' => t('Check which taxonomy vocabularies you would like propagated from parent to children.'),
    );
    return $form;
  }
  else {
    return FALSE;
  }
  
}

/**
 * Form Validator.  Validates the 'edit' page for Relationships.
 */
function relationships_edit_form_validate(&$form, &$form_state) {
  
  // Make sure selected node reference field is manageable
  $field_name = $form_state['values']['field_name'];
  $parent_type = $form_state['values']['parent_type'];
  $child_type = $form_state['values']['child_type'];
  $eligible_fields = _relationships_get_eligible_nodereference_fields($parent_type, $child_type);
  if (!in_array($field_name, array_keys($eligible_fields))) {
    form_set_error('field_name', t('Please select a field for Relationships to manage.'));
  }
  
  // Make sure 'argument' position is either 'disable' or set between 1 and 10
  $settings_arg = $form_state['values']['arg'];
  if ($settings_arg != 'disable' && ((int)$settings_arg < 1 || (int)$settings_arg > 10)) {
    form_set_error('arg', t('Please select an argument number between 1 and 10, or "disable" to disable this feature.'));
  }
  
  // Make sure 'hide' (node reference field) option is between 0 and 3
  $settings_hide = $form_state['values']['hide'];
  if ($settings_hide < 0 || $settings_hide > 3) {
    form_set_error('hide', t('Please select when you would like Relationships to hide the node reference field.'));
  }
  
  // TODO: Run through the validation for each 'rule'
  // i.e. HOOK_relationship_edit_form_validate_RULE()
  
}


/**
 * Form Submitter.  Submits the 'edit' page for Relationships.
 */
function relationships_edit_form_submit(&$form, &$form_state) {  
  
  $settings = array(
    'arg' => $form_state['values']['arg'],
    'hide' => $form_state['values']['hide'],
    'propagation_rules' => array(

      // AUTOMATICALLY IDENTIFIED BASED ON THE RULE NAME...
      // SHOULD WE PREPEND 'SETTINGS_', BEFORE ADDING TO FORM?
      // TO BETTER-ENSURE THE VALUE NAME WOULD NOT BE TAKEN.
      // FOR EXAMPLE, "PUBLISH" BECOMES "HOOK_RULE_PUBLISH".

      // Save propogation rule, for authorship.
      'authorship' => $form_state['values']['authorship'],
  
      // Save propagation rule, for publish status.
      'publish' => $form_state['values']['publish'],
  
      // Save propagation rule, for vocabulary.
      'vocabs' => $form_state['values']['vocabs'],
  
      // Save propagation rule, for groups. 
      'groups' => $form_state['values']['groups'],
  
    ),
  );

  // Save relationship
  $parent_type = $form_state['values']['parent_type'];
  $child_type = $form_state['values']['child_type'];
  $field_name = $form_state['values']['field_name'];
  $status = relationships_save($parent_type, $child_type, $field_name, $settings);
  
  // Set message
  $parent_name = node_get_types('name', $parent_type);
  $child_name = node_get_types('name', $child_type);
  switch($status) {
    case SAVED_NEW:
      drupal_set_message(t('Relationship %parent : %child created.', array('%parent' => $parent_name, '%child' => $child_name)));
      break;
    case SAVED_UPDATED:
      drupal_set_message(t('Relationship %parent : %child updated.', array('%parent' => $parent_name, '%child' => $child_name)));
      break;
    default:
      watchdog('LAT Relationships', 'Unexpected return value when saving relationship %parent : %child.', array('%parent' => $parent_name, '%child' => $child_name), WATCHDOG_ERROR);
      drupal_set_message(t('Unexpected return value for relationship %parent : %child.', array('%parent' => $parent_name, '%child' => $child_name)), 'error');
      break;
  }
  
  // Set redirect
  $parent_url = str_replace('_', '-', $parent_type);
  $form_state['redirect'] = array("admin/content/node-type/$parent_url/relationship");
}


function relationships_remove_form(&$form_state, $parent_type, $child_type) {
  
  // Set form values
  $form['parent_type'] = array('#type' => 'value', '#value' => $parent_type);
  $form['child_type'] = array('#type' => 'value', '#value' => $child_type);

  $parent_name = node_get_types('name', $parent_type);
  $parent_url = str_replace('_', '-', $parent_type);
  $child_name = node_get_types('name', $child_type);
  
  if (!_relationships_is_managed($parent_type, $child_type)) {
    form_set_error('', t('Cannot delete relationship %parent : %child.  That relationship is not currently being mananged.', array('%parent' => $parent_name, '%child' => $child_name)));
    drupal_goto('admin/content/node-type/'.$parent_url.'/relationship');
  }
  
  // Return standard Drupal confirmation form
  return confirm_form($form,
                  t('Are you sure you want to delete the relationship %parent : %child?',
                  array('%parent' => $parent_name, '%child' => $child_name)),
                  'admin/content/node-type/'.$parent_url.'/relationship',
                  t('If you delete this relationship, changes made to nodes of type !parent will no longer be propagated to nodes of type !child.', array('!parent' => $parent_name, '!child' => $child_name)),
                  t('Delete'),
                  t('Cancel'));  
}


function relationships_remove_form_submit(&$form, &$form_state) {
  
  $parent_type = $form_state['values']['parent_type'];
  $parent_name = node_get_types('name', $parent_type);
  $child_type = $form_state['values']['child_type'];
  $child_name = node_get_types('name', $child_type);

  // Delete the relationship
  relationships_delete($parent_type, $child_type);
  
  // Set message
  drupal_set_message(t('Relationship %parent : %child deleted.', array('%parent' => $parent_name, '%child' => $child_name)));

  // Set redirect
  $parent_url = str_replace('_', '-', $parent_type);
  $form_state['redirect'] = array("admin/content/node-type/$parent_url/relationship");
  
}

