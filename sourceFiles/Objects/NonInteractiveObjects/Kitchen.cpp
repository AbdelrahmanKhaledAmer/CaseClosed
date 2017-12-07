#include "headerFiles/Objects/NonInteractiveObjects/Kitchen.h"

/*
Constructor for the Kitchen object.
Returns a pointer for a Kitchen.

@param (location) The current location of the Kitchen with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Kitchen::Kitchen(Vector3f location, Vector3f orientation, Vector3f scale,
                     Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {

}

/**
Destructor for the Kitchen object.
Deletes the pointer for the Kitchen object.
*/
Kitchen::~Kitchen() {

}