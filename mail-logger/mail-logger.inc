<?php

/**
 * Logs email message to a file.
 */
function drupal_mail_wrapper($message) {
  
  // Prepare message filename "message-TIMESTAMP.txt"
  //$timestamp = time();
  $message_id = uniqid();
  $filename = "message-$message_id.txt";
  $filepath = "sites/liveandtell.com/mail-logger/sent-mail/$filename";
  
  // Write message
  $FILE = fopen($filepath, 'x');
  if ($FILE) {
    fwrite($FILE, print_r($message, TRUE));
    fclose($FILE);
  }
  else {
    drupal_set_message('Cannot send email...mail-logger file already exists.');
  }
  
}
