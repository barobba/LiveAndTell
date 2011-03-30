
$(document).ready(function() {
  var windowHeight = $(window).height();
  $('.view-id-image_thumbnails .view-content').attr('style', 'border: 1px solid black; overflow-y: scroll; height: ' + windowHeight * .6 + 'px');
});

