<?php
// $Id: views-view-field.tpl.php,v 1.1 2008/05/16 22:22:32 merlinofchaos Exp $
 /**
  * This template is used to print a single field in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  *
  * When fetching output from the $row, this construct should be used:
  * $data = $row->{$field->field_alias}
  *
  * The above will guarantee that you'll always get the correct data,
  * regardless of any changes in the aliasing that might happen if
  * the view is modified.
  */

$account = $GLOBALS['user'];
$album = node_load($row->nid);
$tags  = node_load($row->node_data_field_latimage_ref_field_latimage_ref_nid);
$image = node_load($tags->field_abstract_image_noderef[0]['nid']);

$content = '';
if (!empty($row->node_data_field_latimage_ref_field_latimage_ref_nid)) {
  
  // Display image
  $image_content = theme('image', $image->lat_media_thumb_url, '', '', NULL, FALSE);
  $content .= $image_content;

  // Option to display tags
  //  if (node_access('view', $tags)) {
  $content .= '<div class="op-view">'.l('view', "node/$tags->nid").'</div>';
  //  }

  // Tag-level operations
  if ($tags->uid == $account->uid) {
  //  if (node_access('update', $tags)) {
    // Add terms link
    $content .= '<div class="op-edit-tags">'.l('edit tags', "node/$tags->nid/add-terms").'</div>';
  }
  
  // Album & Tag-level operations
  if ($album->uid == $account->uid && $tags->uid == $account->uid) {
    
    // Publish/Unpublish link
    if ($tags->status == 1) {
      $content .= '<div class="op-unpublish">'.l('unpublish', "node/$album->nid/tagged-image/$tags->nid/status/toggle").'</div>';
    }
    else {
      $content .= '<div class="op-publish">'.l('publish', "node/$album->nid/tagged-image/$tags->nid/status/toggle").'</div>';
    }
    
  }
  
  // Album-level operations
  if ($album->uid == $account->uid) {
  //  if (node_access('update', $album)) {
    $content .= '<div class="op-move-up">'.l('move up', "node/$album->nid/image/$tags->nid/moveup").'</div>';
    $content .= '<div class="op-move-down">'.l('move down', "node/$album->nid/image/$tags->nid/movedown").'</div>';
    $content .= '<div class="op-detach">'.l('detach', "node/$album->nid/image/$tags->nid/detach").'</div>';
  }
  
}
print $content;
