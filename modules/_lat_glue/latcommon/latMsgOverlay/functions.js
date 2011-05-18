function latAlert($msg) {
  // Dialog
  $('html').addClass('lat-msgbox-overlay-shown');
  $('body')
  .append(
    $('<div id="lat-msgbox-overlay" style="opacity: 0"></div>')
    .append(
      $('<table id="lat-msgbox-container"></table>')
      .append('<tr><td id="lat-msgbox-contents"></td></tr>')
      .append('<tr><td id="lat-msgbox-controls"></td></tr>')
    )
  );
  $('#lat-msgbox-overlay').attr('style', 'background-image: url("/sites/liveandtell.com/modules/_lat_glue/latcommon/latMsgOverlay/background.png")');
  // Contents
  $('#lat-msgbox-contents').append($msg);
  // Controls
  $('<a href="#">Close</a>').click(function(event){
    $('#lat-msgbox-overlay').fadeTo('fast', 0, function() {
      $('html').removeClass('lat-msgbox-overlay-shown');
      $('#lat-msgbox-overlay').remove();
    });
  }).appendTo($('#lat-msgbox-controls'));
}
