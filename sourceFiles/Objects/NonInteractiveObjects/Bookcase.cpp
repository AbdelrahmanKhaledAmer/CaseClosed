#include "headerFiles/Objects/NonInteractiveObjects/Bookcase.h"

/*
Constructor for the Bookcase object.
Returns a pointer for a Bookcase.

@param (location) The current location of the Bookcase with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Bookcase::Bookcase(Vector3f location, Vector3f orientation, Vector3f scale,
                   Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {}

/**
Destructor for the Bookcase object.
Deletes the pointer for the Bookcase object.
*/
Bookcase::~Bookcase() {}