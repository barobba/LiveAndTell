<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes ?>">
  <?php print $picture ?>
  <div class="content">
  
    <!-- ########################## -->
    <!-- PREVIOUS, UP, NEXT BUTTONS -->
    <!-- ########################## -->

    <div class="lat-image-album-nav">
      <?php if ($lat_image_album_previous): ?>
        <div class="lat-image-album-previous">
          <?php print $lat_image_album_previous ?>
        </div>
      <?php endif; ?>
      <?php if ($lat_image_album_next): ?>
        <div class="lat-image-album-next">
          <?php print $lat_image_album_next ?>
        </div>
      <?php endif; ?>
      <div class="lat-image-album-up">
        <?php print l('Back to album', 'node/'.$node->field_lnt_album_noderef[0]['nid']) ?>
      </div>
    </div>
  
    <!-- ############# -->
    <!-- IMAGE & TERMS -->      
    <!-- ############# -->
    
    <table class="node-content-wrapper-layout-table">
      <tr>
        <td class="lat-image-left">
        
          <!-- IMAGE -->
          <?php print $lat_image_embed_code ?>
          
          <!-- CAPTION -->
          <?php if( $field_lnt_image_caption_rendered || $field_lnt_image_caption_audio_rendered || $field_lnt_image_trans_rendered || $field_lnt_image_trans_audio_rendered): ?>
            <div class="lat-image-caption">
              <?php if($field_lnt_image_caption_rendered || $field_lnt_image_caption_audio_rendered): ?>
                <div class="caption">
                <?php print $field_lnt_image_caption_rendered ?>
                <?php print $field_lnt_image_caption_audio_rendered ?>
                </div>
              <?php endif; ?>
              <?php if($field_lnt_image_trans_rendered || $field_lnt_image_trans_audio_rendered): ?>
                <div class="translation">
                  <?php print $field_lnt_image_trans_rendered ?>
                  <?php print $field_lnt_image_trans_audio_rendered ?>
                </div>
              <?php endif; ?>
            </div>
          <?php endif; ?>
          
          <!-- TEXT EXAMPLES -->
          <?php print $field_lnt_image_text_examples_rendered ?>
  
        </td>
      </tr>
    </table>        
  </div>

  <!-- ############# -->
  <!-- USER INFO -->
  <!-- ############# -->
  
  <div class="meta">
    <?php print $field_credit_rendered ?>
    <?php if ($submitted): ?>
      <span class="submitted"><?php print $submitted ?></span>
    <?php endif; ?>
    <?php if ($terms): ?>
      <div class="terms terms-inline"><?php print $terms ?></div>
    <?php endif;?>
  </div>
  
  <!-- ##### -->
  <!-- LINKS -->
  <!-- ##### -->
  
  <?php print $links; ?>

  <!-- ########## -->  
  <!-- EMBED CODE -->
  <!-- ########## -->  
  
  <?php print theme('nodetoolbar', $node) ?>
  <div id="toolbar-dropdown">
    <?php /* Default value */ ?>
    <?php print $lat_image_tags ?>
  </div>
  
  <?php /* TODO CREATE PATH FOR RETURNING DROP-DOWN CONTENT */ ?>
  <?php print $copyandpaste_embed_code ?>
  <?php print $copyandpaste_embed_code_hideboxes ?>


  <!-- ########## -->  
  <!--  CONTENT   -->
  <!-- ########## -->  
  <hr />
  <?php print $content ?>
  
</div>

<!-- ############# -->
<!-- TOOLBAR DATA  -->
<!-- ############# -->
<div class="toolbar-dropdown-panels" style="display: none">
  <div class="toolbar-dropdown-panel toolbar-dropdown-panel-tags">
    <?php print $lat_image_tags ?>
  </div>
  <div class="toolbar-dropdown-panel toolbar-dropdown-panel-embed-code">
    <?php print $lat_image_embed_code_copy ?>
    <?php print $lat_image_embed_code_hideboxes ?>
  </div>
</div>


