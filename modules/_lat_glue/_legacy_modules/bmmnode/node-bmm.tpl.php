<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">

  <?php if ($page == 0): ?>
  <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  <?php endif; ?>

  <div class="meta">
    <?php if ($submitted): ?>
    <span class="submitted"><?php print $submitted ?></span>
    <?php endif; ?>
  </div>

  <div class="content">

    <?php print $content ?>
    <?php if ($bmm_toolbar ): ?>
      <p>&nbsp;</p>
      <?php print $bmm_toolbar ?>
    <?php endif; ?>
    <?php if ($bmm_affix_table ): ?>
      <?php print $bmm_affix_table ?>
    <?php endif; ?>

    <p>&nbsp;</p>
    <h2>For instructors</h2>
    <p>Instructors use this animation for demonstration purposes.</p>
    <p>Instructions: Press the green play button to step through the entire animation.</p>
    <div style="border:solid thin black; width: 400px">
      <?php print $bmm_animation ?>
    </div>

    <p>&nbsp;</p>
    <h2>For students</h2>
    <p>This game requires critical thinking.</p>
    <p>Instructions: Students pick the letters on the top of play area that will make up the translation on the bottom of the play area.</p>
    <div style="border:solid thin black; width: 400px">
      <?php print $bmm_game ?>
    </div>
  </div>

  <!--
  <?php if ($terms): ?>
  <div class="terms">
    <?php print $terms; ?>
  </div>
  <?php endif;?>
  -->

  <?php if ($links): ?>
  <div class="links">
    <?php print $links; ?>
  </div>
  <?php endif; ?>

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom">
    <?php print $node_bottom; ?>
  </div>
  <?php endif; ?>
</div>
<!-- /#node-<?php print $node->nid; ?> -->
