// $Id$

/**
 * @file
 * JavaScript function for audio module
 */

/**
 * Finds the DOM object by id and changes
 * its 'value' attribute to 'filename'
 */
function setFilename( id, filename ) {
  $('#' + id).attr('value', filename);
}

/**
 * Finds the DOM object by id and changes
 * its height to 'height'
 */
function setHeight( id, height ) {
  // Cannot search just by #id, because
  // jQuery will find the <object> with that
  // id, but will miss the <embed> that has
  // the same id.
  
  // Search all <object> tags first
  $('object').each( function (i)  {
    if( this.id == id ) {
      this.height = height;
    }
  });
  
  // Search all <embed> tags second
  $('embed').each( function (i)  {
    if( this.id == id ) {
      this.height = height;
    }
  });  
}