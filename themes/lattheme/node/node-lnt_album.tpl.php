<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes ?>">
  <table id="lat-page-layout-table">
    <tbody>
      <tr>
        <!--
        <td class="left">
          left
        </td>
        -->
        <td class="center">
          <?php print $lat_album_images ?>
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
  
  <hr />
  <?php print $content ?>
  
  <div class="meta submitted"><?php print $field_credit_rendered ?>Posted by <?php print $lat_node_author ?>, <?php print $lat_node_posted_date ?></div>
</div>
