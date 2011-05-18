<?php

/**
 * LATMobile Configure Form
 * 
 * Returns the form for configuring mobile uploads. 
 * 
 * @param $form_state
 */
function latmobile_configure_form($form_state) {
  $form['carrier_domains'] = array(
    '#title' => t('Valid carrier domains'),
    '#type' => 'textarea',
    '#cols' => 60,
    '#rows' => 10,
    '#default_value' => variable_get('latmobile_carrier_domains', ''),
    '#description' => t('Enter a list of carrier domains, separated by a newline.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Implementation of hook_[form]_submit
 * 
 * @param $form
 * @param $form_state
 */
function latmobile_configure_form_submit($form, &$form_state) {
  $carrier_domains = $form_state['values']['carrier_domains'];
  $carrier_domains = trim($carrier_domains);
  variable_set('latmobile_carrier_domains', $carrier_domains);
  drupal_set_message('Configuration saved');
}

function _latmobile_sender_verify_page() {
  header('Content-Type: text/plain');
  if (array_key_exists('sender_address', $_REQUEST) == true) {
    // Parse sender address
    $sender_address = $_REQUEST['sender_address'];
    $account = latmobile_account_load($sender_address);
    if ($account != FALSE) {
      print "Sender address is OK\n";
    } else {
      print "Sender address $sender_address could not be verified\n"; 
    }

    /*
    $email = explode('@', $sender_address);
    $mobile_part = $email[0];
    $carrier_domain = $email[1];
    // Check mobile number is registered with a user
    if (latmobile_mobile_number_check($mobile_part)) {
      // Check domain is valid carrier domain
      if (latmobile_carrier_domain_check($carrier_domain)) {
        // Return success message
        print "Sender address is OK\n";
      } else {
        print "Domain name [$carrier_domain] is not a recognized carrier domain.\n";
      }
    } else {
      print "Mobile number [$mobile_part] has not been registered.\n";
    }
    */
    
  } else {
    print "Invalid input: sender address is missing.\n";
  }
  module_invoke_all('exit');
}

function _latmobile_submit_page() {
  header('Content-Type: text/plain');
  if (isset($_REQUEST['latmobile_data'])) {
    
    $data = unserialize($_REQUEST['latmobile_data']);
    $sender = $data['sender'];
    $files = $data['files'];
    $text = trim($data['text']);
    
    // Get account
    $account = latmobile_account_load($sender);
    if ($account) {
      
      // Check that picture book exists (called Mobile Uploads) for this user
      // If not then create Mobile Uploads picture book
      $picture_book_node = array(
        'type' => 'lnt_album',
        'uid' => $account->uid,
        'title' => 'Mobile Uploads',
      );
      $picture_book_node = node_load($picture_book_node);
      if ($picture_book_node == FALSE) {
        print "Picture book 'Mobile Uploads' does not exist\n";
        $picture_book_node = new stdClass();
        $picture_book_node->type = 'lnt_album';
        $picture_book_node->uid = $account->uid;
        $picture_book_node->title = t('Mobile Uploads');
        $picture_book_node->status = FALSE;
        $picture_book_node = node_submit($picture_book_node);
        node_save($picture_book_node);
      }
             
      // Create image nodes
      // Reference the "Mobile Uploads" picture book
      foreach($files as $filename) {

        // Prepare image field
        $field_lnt_image = content_fields('field_image', 'image');
        $field_lnt_image_tmp = file_directory_temp().'/'.$filename;
        $field_lnt_image_validators = array_merge(
          filefield_widget_upload_validators($field_lnt_image), 
          imagefield_widget_upload_validators($field_lnt_image)
        );
        $field_lnt_image_path = filefield_widget_file_path($field_lnt_image); 

        // Generate image field data
        $field_lnt_image_data = field_file_save_file(
          $field_lnt_image_tmp,
          array(), //$field_lnt_image_validators, 
          $field_lnt_image_path,
          $account
        );
        
        if ($field_lnt_image_data != 0) {

          // Save image node
          $image_node = new stdClass();
          $image_node->type = 'image';
          $image_node->title = 'Image, mobile upload';
          $image_node->uid = $account->uid;
          $image_node->status = FALSE;
          $image_node->active = TRUE;
          $image_node->field_image []= $field_lnt_image_data;
          node_save($image_node);
          print "Posting completed";

          // Save tagging node
          $latimage = _lat_node_initialize('lnt_image');
          $latimage->uid = $account->uid;
          $latimage->title = 'Tagging node';
          $latimage->field_abstract_image_noderef[0]['nid'] = $image_node->nid;
          $latimage->field_lnt_image_caption[0]['value'] = $text;
          node_save($latimage); 
          print "Image attached to tagging node.";

          // Save picture book entry
          $max_weight = latnb_entry_weights_max($picture_book_node);
          $new_weight = $max_weight->delta + 1;
          $picture_book_entry = _lat_node_initialize('lnt_album_entry');
          $picture_book_entry->uid = $account->uid;
          $picture_book_entry->title = 'Picture book entry';
          $picture_book_entry->field_lnt_album_noderef[0]['nid'] = $picture_book_node->nid;
          $picture_book_entry->field_delta[0]['value'] = $new_weight;
          $picture_book_entry->field_lnt_image_noderef[0]['nid'] = $latimage->nid;
          node_save($picture_book_entry);
          print "Tagging node attached to album.";
          
          // Remove temporary file
          unlink($field_lnt_image_tmp);          
        
        } else {
          print "Could not save image file.\n";
        }
        
      } // end foreach
    }
    else {
      print "Account not found\n";
    }
  } else {
    print "Data not found.\n";
  }
  module_invoke_all('exit');
}
