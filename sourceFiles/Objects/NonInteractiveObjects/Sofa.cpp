#include "headerFiles/Objects/NonInteractiveObjects/Sofa.h"

/*
Constructor for the Sofa object.
Returns a pointer for a Sofa.

@param (location) The current location of the Sofa with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Sofa::Sofa(Vector3f location, Vector3f orientation, Vector3f scale,
                     Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {

}

/**
Destructor for the Sofa object.
Deletes the pointer for the Sofa object.
*/
Sofa::~Sofa() {

}