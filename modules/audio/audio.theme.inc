<?php
  // $Id$

/*
 * @file
 */

/*
 * Widget theme
 * Here, $element is the widget defined $element array
 */
function theme_audio($element) {

  // JavaScript needed for flash player to alter hidden field
  drupal_add_js(drupal_get_path('module', 'audio') .'/audio.js');
 
  // Construct parameters array for embed code
  $parameters = array(
    'type' => 'recorder',
    'id' => 'recorder-' . $element['#id'],
    'name' => 'recorder_' . $element['#name'],
    'field' => $element['#id'],
    'filename' => $element['#value'],
    'width' => 214,
    'height' => 137,
    'path' => drupal_get_path('module', 'audio'),
  );

  // Theme the widget as a hidden field
  // and concat with the flash embed code
  $output = _audio_embed_code($parameters) . theme('hidden', $element);

  // Theme them together as one form element and return
  return theme('form_element', $element, $output);
}

/**
* Theme function for 'default' formatter.
*/
function theme_audio_formatter_default($element) {
  if (!$element['#item']['value'])
    return;

  // Construct parameters array
  $parameters = array(
    'type' => 'player',
    'id' => 'player',
    'name' => 'player',
    'width' => 23,
    'height' => 12,
    'path' => drupal_get_path('module', 'audio'),
    'filename' => $element['#item']['value'],
  );
  
  // Return raw embed code
  return _audio_embed_code($parameters);
}

/*
 * Formatter teaser theme
 */
function theme_audio_formatter_teaser($element) {
  if (!$element['#item']['value'])
    return;

  // Construct parameters array
  $parameters = array(
    'type' => 'mini',
    'id' => 'mini',
    'name' => 'mini',
    'width' => 23,
    'height' => 12,
    'path' => drupal_get_path('module', 'audio'),
    'filename' => $element['#item']['value'],
  );
  
  // Return raw embed code
  return _audio_embed_code($parameters);
}

function _audio_embed_code($parameters) {
  // Get values from $parameter array
  $type     = $parameters['type'];
  $id       = $parameters['id'];
  $name     = $parameters['name'];
  $width    = $parameters['width'];
  $height   = $parameters['height'];
  $path     = $parameters['path'];
  if (array_key_exists('field', $parameters)) {
    $field    = $parameters['field'];
  }
  $filename = $parameters['filename'];

  // Construct path to swf object with flashvars as query string
  $query = array();
  $query['filename'] = $filename;
  if (array_key_exists('field', $parameters)) {
    $query['field'] = $field;
  }
  $url_settings = array();
  $url_settings = array('query' => $query);
  $src = url("$path/$type.swf", $url_settings);

  // Construct embed code
  $code = "
    <object id='$id' name='$name' width='$width' height='$height'>
      <param name='movie' value='$src'></param>
      <param name='wmode' value='transparent'></param>
      <embed 
        id     = '$id' 
        name   = '$name' 
        width  = '$width' 
        height = '$height'
        type   = 'application/x-shockwave-flash'
        wmode  = 'transparent'
        src    = '$src'
      ></embed>
    </object>
  ";

  // Return embed code
  return $code;
}
