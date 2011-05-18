<table id="lat-page-layout-table" class="profile-content" >
  <tr>
  
    <td class="column profile-content-left">
      <?php if ($profile['user_picture']): ?>
        <?php print $profile['user_picture'] ?>
      <?php endif ?>
  	  <?php if ($account->profile_about_me): ?>
	  	  <?php print $account->profile_about_me ?>
	    <?php endif; ?>
    </td>
    
    <td class="column profile-content-middle">
      <?php print $lat_profile_content ?>
    </td>
    
  </tr>
</table>
