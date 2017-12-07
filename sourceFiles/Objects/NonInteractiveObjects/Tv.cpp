#include "headerFiles/Objects/NonInteractiveObjects/Tv.h"

/*
Constructor for the Tv object.
Returns a pointer for a Tv.

@param (location) The current location of the Tv with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Tv::Tv(Vector3f location, Vector3f orientation, Vector3f scale,
                     Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {

}

/**
Destructor for the Tv object.
Deletes the pointer for the Tv object.
*/
Tv::~Tv() {

}