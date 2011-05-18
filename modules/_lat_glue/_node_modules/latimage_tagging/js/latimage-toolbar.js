
if (Drupal.jsEnabled) {
  $(document).ready(function () {
	  // Register a click event with the button
    $('.latimage-toolbar-button').click(toggleDropdownEvent);
  });
}

function toggleDropdownEvent(event) {
  // Prevent hyperlink behavior
  event.preventDefault();
  // Store target
	if (typeof toggleDropdownEvent.savedTarget == 'undefined') {
		toggleDropdownEvent.savedTarget = event.target;
	}
	// Get the button
  button = $(event.target);
  panel = $(button.attr('data'));
  panel.hide('slow');
	// Process dropdown 
  dropdown = $('#toolbar-dropdown'); 
  if (dropdown.is(':hidden')) {
  	button.unbind('click', toggleDropdownEvent);
    dropdown.html(panel.html());
  	dropdown.show('slow');
  	button.click(toggleDropdownEvent);
  }
  else if (event.target != toggleDropdownEvent.savedTarget) {
    button = $(event.target); 
    panel = $(button.attr('data'));
    dropdown.html(panel.html());
  }
  else {
  	// CLOSE MODE:
  	dropdown.hide('slow');
  	dropdown.empty();
  	//   Slide $('#toolbar-dropdown') to closed
  	//   Hide $('#toolbar-dropdown')
  }
	toggleDropdownEvent.savedTarget = event.target;
}

function processToolbarDropdownResults(result) {
	
}
