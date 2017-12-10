#include "headerFiles/Objects/NonInteractiveObjects/Wardrobe.h"

/*
Constructor for the Wardrobe object.
Returns a pointer for a Wardrobe.

@param (location) The current location of the Wardrobe with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Wardrobe::Wardrobe(Vector3f location, Vector3f orientation, Vector3f scale,
                   Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {}

/**
Destructor for the Wardrobe object.
Deletes the pointer for the Wardrobe object.
*/
Wardrobe::~Wardrobe() {}