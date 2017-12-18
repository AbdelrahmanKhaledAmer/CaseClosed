#include "headerFiles\Objects\InteractiveObjects\Clues\Footprints.h"

/*
Constructor for the Footprints object.
Returns a pointer for a Footprints.

@param (location) The current location of the Body with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Footprints::Footprints(Vector3f location, Vector3f orientation,
                         Vector3f scale, Vector3f dimensions)
    : ClueImage(location, orientation, scale, dimensions) {}

/**
Destructor for the Footprints object.
Deletes the pointer for the Footprints object.
*/
Footprints::~Footprints() {}

void Footprints::setModel() {
	__super::setModel("assets/images/foot_prints.png");
}
