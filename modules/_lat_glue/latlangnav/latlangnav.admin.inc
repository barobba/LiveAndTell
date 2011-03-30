<?php

function taxonomy_get_vocabulary_names() {
  $result_set = db_query("select v.vid, v.name from {vocabulary} v");
  while ($vocab = db_fetch_object($result_set)) {
    $vocab_names[$vocab->vid] = $vocab->name;
  }
  return $vocab_names;
}

function latlangnav_settings($form_state) {
  
  $vocabulary_names = taxonomy_get_vocabulary_names();
  $form = array(
   'vid' => array(
     '#type' => 'select',
     '#description' => 'The vocabulary of the target language',
     '#title' => t('Pick the vocabulary used for the target language'),
     '#options' => $vocabulary_names,
     '#default_value' => variable_get('latlangnav_vid', null),
   ),
   'submit' => array(
     '#type' => 'submit',
     '#value' => t('Save'),
   ),
  );
  return $form;
}

function latlangnav_settings_submit($form, &$form_state) {
  variable_set('latlangnav_vid', $form_state['values']['vid']);
  drupal_set_message('The LiveAndTell Language Navigation settings have been updated.');
}
