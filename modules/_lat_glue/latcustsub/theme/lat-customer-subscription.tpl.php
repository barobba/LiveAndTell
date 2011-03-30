<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes ?>">
  <table id="lat-page-layout-table">
    <tr>
      <td class="left">
        <?php print $picture ?>
        <?php if (!$page): ?>
          <h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
        <?php endif; ?>
        <?php print $field_subscrip_image_rendered ?>
        <?php print $field_subscrip_desc_rendered ?>
      </td>
      <td class="middle">
        <div class="content">
          HERE
        </div>
        <?php print $lat_cust_subscrip_content ?>
      </td>
    </tr>
  </table>
</div>
