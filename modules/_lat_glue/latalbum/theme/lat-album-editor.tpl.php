<div id="album-editor">
<?php print l('Back to workspace', 'lat/user/workspace' ) ?>
 / <?php print l('View album', "node/$album_nid" ) ?>

<h3><?php print $lat_album_title ?></h3>
<?php
  print l(
    'Add a picture', 
    "node/add/lnt-image/$album_nid", 
    array(
      'query' => array('destination' => "lat/user/type/album/$album_nid"),
      'attributes' => array('class' => 'link-button'),
    )
  ) 
?>
&nbsp; <?php print l('Edit album settings', "node/$album_nid/edit", array('query' => array('destination' => "lat/user/type/album/$album_nid"))) ?>

<table id="lat-page-layout-table">
  <tbody>
    <tr>
      <td class="page-layout-left">
        <?php print $lat_album_editor_images ?>
      </td>
      <?php if ($lat_album_description): ?>
        <td class="page-layout-right">
          <div><?php print $lat_album_description ?></div>
        </td>
      <?php endif; ?>
    </tr>
  </tbody>
</table>
</div>
