
// Main Driver
$(document).ready(function() {
  $('.ui-widget-content').click(function(event){
    $(this).toggleClass('ui-selected');
    var isSelected = $(this).hasClass('ui-selected');
    $(this).find('input.form-checkbox').attr('checked', isSelected);
  });
});





// Flickr Query
// Hide the image checkboxes
//$('#latimage-search-button')
//  .click(latFlickrQuery);
function latFlickrQuery(event) {
  event.preventDefault();
  var flickrUrl = "http://api.flickr.com/services/feeds/photos_public.gne?jsoncallback=?";
  var flickrTags = { 
    tags: $('#latimage-search-keywords').val(),
    tagmode: 'any',
    format: 'json'
  };
  var imageHandler = function(results) {
    $("#latimage-search-results").empty();
    $.each(results.items, function(i,item){
      $("<img/>").attr("src", item.media.m).appendTo("#latimage-search-results");
    });
  };
  $.getJSON(flickrUrl, flickrTags, imageHandler);
}
