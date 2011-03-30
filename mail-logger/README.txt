For the mail-logger to work, the settings.php file will need to contain the
following line:

$conf['smtp_library'] = 'DRUPAL_URI/sites/WEBSITE/mail-logger/mail-logger.inc';

Where DRUPAL_URI is the URI to the Drupal installation, and WEBSITE is the 
path to the mail-logger folder.
