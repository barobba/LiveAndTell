<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes ?>">
  <?php print $picture ?>
  <?php if (!$page): ?>
    <h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  <?php endif; ?>
  <div class="meta">
  <?php if ($submitted): ?>
    <span class="submitted"><?php print $submitted ?></span>
  <?php endif; ?>
  <?php if ($terms): ?>
    <div class="terms terms-inline"><?php print $terms ?></div>
  <?php endif;?>
  </div>
  <div class="content">
    HERE
  </div>
  <?php print $links; ?>
</div>
