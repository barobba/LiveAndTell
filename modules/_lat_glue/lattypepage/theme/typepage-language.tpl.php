<table id="lat-page-layout-table" class="lesson-content">

  <tr valign="top">
    
    <td class="content-left">    
      <div id="lessons-by-author">
        <?php print $content_authors; ?>
      </div>
    </td>
    
    <td class="content-middle">
      <div id="new-lessons" >
        <?php print $content_new; ?>
      </div>
    </td>
    
    <td class="content-right">
      <div class="create"><p><?php print $create_link ?></p></div>
      <div class="language-page-link"><p><?php print l("Back to the $language page", "language/$language_lower") ?></p></div>
    </td>
    
  </tr>
</table>
