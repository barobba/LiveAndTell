<?php
  if (!$query_string) {
    $flash_url = url("e/$node->nid", array('absolute' => true));
  } else {
    $flash_url = url("e/$node->nid", array('query' => $query_string, 'absolute' => true));
  }
?>

<object width="<?php print $width ?>" height="<?php print $height ?>">
  <param name="movie" value="<?php print $flash_url ?>"></param>
  <param name="allowFullScreen" value="true"></param>
  <param name="wmode" value="transparent"></param>
  <embed
    src="<?php print $flash_url ?>" 
    type="application/x-shockwave-flash" 
    allowfullscreen="true"
    wmode="transparent"
    width="<?php print $width ?>"
    height="<?php print $height ?>"
  ></embed>
</object>
