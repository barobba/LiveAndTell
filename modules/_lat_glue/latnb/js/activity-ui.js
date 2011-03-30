
$(document).ready(function() {
  // Make images clickable
  $('.ui-widget-content').click(function() {
    $(this).toggleClass('ui-selected');
  });
  // Make notebooks clickable
  $('.add-to-activity-button').click(function (event) {
    // Prevent default link action
    event.preventDefault();
    // Find my NID
    var notebookNID = $(this).attr('data');
    // Add the selected items to the notebook at NID.
    var endPointURL = '/lat/process/notebook/add/image-nodes';
    var imageNIDs = $('.ui-widget-content.ui-selected .views-field-nid .field-content .node-nid')
                       .map(function(index, element){
                         return $(this).html();
                       }).get().join(':');
    $.getJSON(endPointURL, { notebook: notebookNID, images: imageNIDs }, function(json) {
      alert(json.result_string);
      $('.ui-widget-content.ui-selected').toggleClass('ui-selected');
    });
  });
});

// TAGGED LAT IMAGE SELECTION
// Find "#activity-ui-selectable-NID" elements.
// Attach special "click" events handlers to the events.
// Toggles #activity-ui.selected|(nothing)
//
// COLLECT LAT IMAGE TAGS 
// Collect all elements with "#activity-ui.selected" path.
// Retrieve the NID of each term.
// 
// SUBMIT CONTENT
// Get the "activiy" oject.
// Point the activity to each of these IDs to the LAT Album.
