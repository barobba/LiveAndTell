<?php

/**
 * LATMobile User Form
 * 
 * Returns the form for adding mobile number 
 * 
 * @param $form_state
 */
function latmobile_user_form($form_state, $user) {
  $form['account'] = array(
    '#type' => 'value',
    '#value' => $user,
    '#required' => TRUE,
  );
  $form['mobile_number'] = array(
    '#title' => t('Mobile number'),
    '#type' => 'textfield',
    '#size' => 60,
    '#maxlength' => 60,
    '#default_value' => isset($user->latmobile_mobile_number) ? $user->latmobile_mobile_number : '',
    '#description' => t('Enter the mobile number you will use to send pictures to the website.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

function latmobile_user_form_validate ($form, &$form_state) {
  $mobile = trim($form_state['values']['mobile_number']);
  $account = $form_stat['values']['account'];
  if ($mobile != '') {
    // check mobile number format
    if (latmobile_mobile_number_check_format($mobile) == false) {
      form_set_error('mobile_number', t('Invalid mobile number format'));
    }
    // check number isn't already used
    if (latmobile_mobile_number_check($mobile)) {
      $account2 = latmobile_account_load_mobile($mobile); 
      // check that both accounts are the same
      if ($account->uid != $account2->uid) {
        form_set_error('mobile_number', t('This number is already registered with another user.'));
      }
    }
  } else {
    // No need to validate mobile number if it is missing
  }
}

/**
 * Implementation of hook_[form]_submit
 * 
 * @param $form
 * @param $form_state
 */
function latmobile_user_form_submit($form, &$form_state) {
  $account = $form_state['values']['account'];
  $mobile_number = $form_state['values']['mobile_number'];
  if (latmobile_mobile_number_check($account->uid) == false) {
    latmobile_mobile_number_insert($account->uid, $mobile_number);
  } 
  else {
    latmobile_mobile_number_update($account->uid, $mobile_number);
  }
  drupal_set_message('Mobile information saved');
}
