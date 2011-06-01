<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes ?>">

  <!-- NODE CONTENT -->
  <?php print $content ?>
  
<?php
/*
  <table id="lat-page-layout-table">
    <tbody>
      <tr>
        <!--
        <td class="left">
          left
        </td>
        -->
        <td class="center">
        
          <!-- SHOW IMAGES THAT THIS ALBUM REFERENCES -->
          <?php print $field_latimage_ref_rendered ?>
          
          <!-- SHOW IMAGES THAT REFERENCE THIS ALBUM -->
          <?php if (isset($lat_album_images)): ?>
            <?php print $lat_album_images ?>
          <?php endif; ?>
          
        </td>
        <td class="right">
          <h2><?php print $title ?></h2>
          <?php print $field_latalbum_desc_audio_rendered ?>
          <?php print $field_lnt_album_description_rendered ?>
          <?php print $links; ?>
        </td>
      </tr>
    </tbody>
  </table>
  
*/
?>
  
  <div class="meta submitted">
    <?php if (isset($field_credit_rendered)): ?>
      <?php print $field_credit_rendered ?>
    <?php endif; ?>
    Posted by <?php print $lat_node_author ?>, 
    <?php print $lat_node_posted_date ?>
  </div>
</div>

<?php if ($google_ads_link_units): ?>
  <?php print $google_ads_link_units ?>
<?php endif; ?>
