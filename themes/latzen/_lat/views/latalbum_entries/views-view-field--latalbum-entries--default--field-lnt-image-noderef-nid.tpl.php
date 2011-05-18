<?php
// $Id: views-view-field.tpl.php,v 1.1 2008/05/16 22:22:32 merlinofchaos Exp $
 /**
  * 
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  * 
  * Use format: $data = $row->{$field->field_alias}
  * 
  */

$content = '';

$picture_frame = node_load($row->nid);
if ($picture_frame) {
  
  $album = node_load($picture_frame->field_lnt_album_noderef[0]['nid']);
  if ($album) {
    
    $tags  = node_load($picture_frame->field_lnt_image_noderef[0]['nid']);
    if ($tags) {
      
      $image = node_load($tags->field_abstract_image_noderef[0]['nid']);
      if ($image) {

        $account = $GLOBALS['user'];
      
        //
        // Display image
        // Option to view tags
        //
        
        $image_content = theme('image', $image->lat_media_thumb_url, '', '', NULL, FALSE);
        if (node_access('view', $tags)) {
          $content .= l($image_content, "node/$tags->nid", array('html' => TRUE, 'attributes' => array('target' => '_blank')));
          $content .= '<div class="op op-view">'.l('view', "node/$tags->nid", array('attributes' => array('target' => '_blank'))).'</div>';
        }
        else {
          $content .= $image_content;
          $content .= '<div>&nbsp;</div>';
        }
      
        //
        // Option to edit tags
        //
        
        if (node_access('update', $tags)) {
          
          // Add terms link
          $content .= '<div class="op op-edit-tags">'.l('tag image', "node/$tags->nid/add-terms", array('attributes' => array('target' => '_blank'))).'</div>';

          // Option to publish/unpublish tag group
          if ($tags->status == 1) {
            $content .= 
              '<div class="op op-unpublish">'
              . l('unpublish', "node/$tags->nid/status/toggle", 
                  array('query'=>array('destination'=> $_REQUEST['q'])))
              . '</div>';
          }
          else {
            $content .= 
              '<div class="op op-publish">'
              . l('publish', "node/$tags->nid/status/toggle",
                  array('query'=>array('destination'=> $_REQUEST['q'])))
              . '</div>';
          }
          
        } // END OF TAG GROUP LEVEL OPERATIONS
        
        // Picture frame level operations
        if (node_access('update', $picture_frame)) {
          
          //
          // Option to show/hide
          //
          if ($picture_frame->status == 1) {
            $content .= 
              '<div class="op op-hide">'
              . l('hide', "node/$picture_frame->nid/status/toggle", 
                  array('query'=>array('destination'=> $_REQUEST['q'])))
              . '</div>';
          }
          else {
            $content .= 
              '<div class="op op-show">'
              . l('show', "node/$picture_frame->nid/status/toggle",
                  array('query'=>array('destination'=> $_REQUEST['q'])))
              . '</div>';
          }
          
          if (node_access('update', $album)) {
            $content .= '<div class="op op-move-up">'.l('move up', "node/$album->nid/image/$picture_frame->nid/moveup").'</div>';
            $content .= '<div class="op op-move-down">'.l('move down', "node/$album->nid/image/$picture_frame->nid/movedown").'</div>';
          }

          $content .= 
            '<div class="op op-remove">'
            . l('remove', "node/$picture_frame->nid/delete",
              array('query'=>array('destination'=> $_REQUEST['q'])))
            .'</div>';
        }
        
      }
    }
  }
} 


print $content;

