#include "headerFiles\Objects\InteractiveObjects\Clues\Bloodtrail.h"

/*
Constructor for the Bloodtrail object.
Returns a pointer for a Bloodtrail.

@param (location) The current location of the Bloodtrail with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Bloodtrail::Bloodtrail(Vector3f location, Vector3f orientation, Vector3f scale,
                       Vector3f dimensions)
    : ClueImage(location, orientation, scale, dimensions) {}

/**
Destructor for the Bloodtrail object.
Deletes the pointer for the Bloodtrail object.
*/
Bloodtrail::~Bloodtrail() {}

void Bloodtrail::setModel() {
	__super::setModel("assets/images/blood_trail.png");
}
