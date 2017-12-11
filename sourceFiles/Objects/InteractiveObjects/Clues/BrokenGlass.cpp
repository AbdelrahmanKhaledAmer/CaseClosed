#include "headerFiles\Objects\InteractiveObjects\Clues\BrokenGlass.h"

/*
Constructor for the Body object.
Returns a pointer for a Body.

@param (location) The current location of the Body with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
BrokenGlass::BrokenGlass(Vector3f location, Vector3f orientation,
                         Vector3f scale, Vector3f dimensions)
    : ClueImage(location, orientation, scale, dimensions) {}

/**
Destructor for the Body object.
Deletes the pointer for the Body object.
*/
BrokenGlass::~BrokenGlass() {}

void BrokenGlass::setImage() {
	__super::setImage("assets/images/broken_glass.png");
}