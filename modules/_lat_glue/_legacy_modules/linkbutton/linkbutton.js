// $Id$

/**
 * @file
 *
 * Javascript to change links into buttons
 */

/**
 * Attach 'button' behavior to links
 */
Drupal.behaviors.linkbuttonBehavior = function ( context ) {

  // Find each link that has .mmd-link class
  $( '.link-button:not(.link-button-processed)', context ).addClass( 'link-button-processed').each(function() {
  
    // Store the url
    var url = $( this ).attr( 'href' );
    
    // Store previous class info
    var classes = $( this ).attr( 'class' );
  
    // Replace this with a new button, handle this button's click event
    $('<input type="button" value="' + $( this ).text() + '"/>')
      .replaceAll( $( this )                 )      // Replace link with a button
      .addClass( classes + ' form-submit' )         // Add 'processed' class
      .click(function( event ) {                    // Handle click event
        if (url) {
          // Goto location
          window.location = url;
        
          // Prevent any default action
          return false;
        }
      });

  });
};