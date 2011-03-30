// JAVASCRIPT 

// 1. When workbook is clicked (add an event handler to the link)
// 1.1. Access URL via AJAX
// 1.2. Replace results on the page

if (Drupal.jsEnabled) {
  $(document).ready(function () {

    //Register click handler for the user content menu  
    $("div#user-content-menu li a").click(function(event) {    

      //Prevent user from following link    
      event.preventDefault();
      
      //Call the "ajax version" of adding content
      $url = $(this).attr('href')+'?ajax';
      $.post($url, function(result) {

        if ($('.view-lat-user-workspace-content table.views-table tbody').length == 0) {
        
          $('table#user-content-layout td.col-right').empty();
          
          $('table#user-content-layout td.col-right').prepend('\
            <div class="view view-lat-user-workspace-content view-id-lat_user_workspace_content view-display-id-default view-dom-id-1">\
              <div class="view-content">\
                <table class="views-table">\
                  <thead>\
                    <tr>\
                      <th class="views-field views-field-title">Workspace</th>\
                      <th class="views-field views-field-type">Type</th>\
                      <th class="views-field views-field-changed">Last modified</th>\
                      <th class="views-field views-field-status">Published</th>\
                      <th class="views-field views-field-delete-node">Delete</th>\
                    </tr>\
                  </thead>\
                  <tbody>\
                  </tbody>\
                </table>\
              </div>\
            </div>\
          ');
        
        
        }
        
        $('.view-lat-user-workspace-content table.views-table tbody').prepend(result);
        $('.view-lat-user-workspace-content table.views-table tbody tr:first').hide();
        $('.view-lat-user-workspace-content table.views-table tbody tr:first').fadeIn("slow");
        //attr('style', 'border: solid 2px red');
        
      });       
      
    });
    
  });
}
