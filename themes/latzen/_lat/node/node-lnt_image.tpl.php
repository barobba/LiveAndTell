<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes ?>">
  <?php print $picture ?>
  <div class="content">
  
    <!-- ############# -->
    <!-- IMAGE & TERMS -->      
    <!-- ############# -->
  
    <table class="node-content-wrapper-layout-table">
      <tr>
        <td class="lat-image-left column">
        
          <!-- IMAGE -->
          <?php print $lat_image_embed_code ?>
          <?php print $node->field_abstract_image_noderef[0]['credit'] ?>  
          
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
        
        <td class="lat-image-right column">
          <?php print $lat_image_tags ?>
        </td>
      </tr>
    </table>        
  </div>

  <!-- ############# -->
  <!-- USER INFO -->
  <!-- ############# -->
  
  <div class="meta">
    <?php if (isset($field_credit_rendered)): ?>
      <?php print $field_credit_rendered ?>
    <?php endif; ?>
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

  <?php //print theme('nodetoolbar', $node) ?>
  
  <div id="toolbar-dropdown">
    <?php /* Default value */ ?>
    <?php //print $lat_image_tags ?>
  </div>

  <?php print $google_ads_link_units ?>
  
  <?php /* TODO: CREATE PATH FOR RETURNING DROP-DOWN CONTENT */ ?>
  <?php print $cp_embed_code ?>
  <?php print $cp_embed_code_hideboxes ?>
  
</div>

<?php

/*
<hr />

<!-- ########## -->  
<!--  CONTENT   -->
<!-- ########## -->  
<?php print $content ?>

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
*/
