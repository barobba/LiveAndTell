<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes ?>">
  <b class="rounded-corners top">
    <b class="rnd1"></b>
    <b class="rnd2"></b>
    <b class="rnd3"></b>
  </b>
  <div class="node-content-wrapper rounded-corners-container">
    <table class="node-content-wrapper-layout-table">
      <tr>
        <td class="node-teaser-left">
          <div class="node-icon"><?php print $node_icon ?></div>
        </td>
        <td class="node-teaser-right">
          <div class="node-content">

            <!-- Language -->          
            <div class="language">
              <?php print $lat_node_language ?>
              <!-- <?php print $node_icon_small ?> -->
            </div>
            
            <!-- Title -->          
            <h3><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h3>
            
            <!-- Authorship -->          
            <div class="meta submitted">Posted by <?php print $lat_node_author ?>, <?php print $lat_node_posted_date ?></div>
            
            <!-- Content -->          
            <?php print $content ?>
                        
            <!-- More -->          
            <div class="view-more"><?php print $lat_node_view_more ?></div>
            
          </div>
        </td>
      </tr>
    </table>
  </div>    
  <b class="rounded-corners bottom">
    <b class="rnd3"></b>
    <b class="rnd2"></b>
    <b class="rnd1"></b>
  </b>
</div>
