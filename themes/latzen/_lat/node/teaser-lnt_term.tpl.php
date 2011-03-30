<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes ?>">
  <div style="padding-bottom: 4px">

    <!--   term   -->
    <?php if(node_access('update', $node)): ?>
      <?php print l($title, "node/$node->nid/edit",array('html' => true,'query'=>array('destination' => $_GET['q']))) ?>
    <?php else: ?>
      <?php print $title; ?>
    <?php endif; ?>
    
    <!--   audio   -->
    <?php if ($lat_term_audio): ?>
      <?php print $lat_term_audio ?>
    <?php endif; ?>
    
    <!-- translation -->
    <?php if ($node->field_lnt_term_translation[0]['value']): ?>
      - <?php print $node->field_lnt_term_translation[0]['value'] ?>
    <?php endif; ?>
    
  </div>
</div>
