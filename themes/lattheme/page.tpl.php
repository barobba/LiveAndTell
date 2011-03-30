<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html
  xmlns    = "http://www.w3.org/1999/xhtml" 
  xml:lang = "<?php print $page_language ?>" 
  lang     = "<?php print $page_language ?>" 
  dir      = "<?php print $page_language_dir ?>"
>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script type="text/javascript"><?php /* Needed to avoid Flash of Unstyled Content in IE */ ?> </script>
</head>

<body class="<?php print $body_classes; ?>">
<div id="page-wrapper">
  <div id="page-header">
  
    <h1 id="site-name"><?php print $site_name_linked_to_front ?></h1>
    
    <div id="page-navigation" class="menu <?php print $navigation_links ?>">
      <?php if (!empty($primary_links)): ?>
        <div id="page-navigation-upper" class="primary-links clear-block"><?php print $primary_links_rendered; ?></div>
      <?php endif; ?>
      <?php if (!empty($secondary_links)): ?>
        <div id="page-navigation-lower" class="secondary-links clear-block"><?php print $secondary_links_rendered; ?></div>
      <?php endif; ?>        
    </div> <!-- /page-navigation -->
    
    <?php if($logged_in): ?>
    <div id="user-toolbar">
	  <?php 
	    $user_options_links = menu_navigation_links('menu-user-options');
	    print theme('links', $user_options_links, array('id' => 'user-options', 'class' => 'links'));
	  ?>
	  <div id="user-information">
    
      <?php
        if ($user->profile_firstname) {
          $lat_username = $user->profile_firstname.' '.$user->profile_lastname;
        } else {
          $lat_username = $user->name;
        }
      ?>
      <?php print $lat_username ?> (<?php print l('Log out', 'logout') ?>)
	  </div>
    </div>
    <?php endif; ?>
    
  </div><!-- /page-header -->
  
  <div id="page-content">
    <!-- <?php if (!empty($breadcrumb)): ?><div id="breadcrumb"><?php print $breadcrumb; ?></div><?php endif; ?> -->
    
  <?php if (!empty($tabs)): ?>
    <div id="tab-bar" class="tabs sticky-header"><?php print $tabs; ?></div>
  <?php endif; ?>
    <?php if (!empty($messages)): print $messages; endif; ?>
    <?php if (!empty($help)): print $help; endif; ?>
    <div id="content-content" class="clear-block">
      <?php if (!empty($title) && !$is_front ): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>    
      <?php print $content; ?>
    </div>
    <?php print $feed_icons; ?>
  </div>
  
  <?php if ($footer): ?>
    <?php print $footer ?>
  <?php endif; ?>
    
</div>
<?php print $closure ?>
</body>
</html>
