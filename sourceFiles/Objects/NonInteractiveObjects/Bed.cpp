#include "headerFiles/Objects/NonInteractiveObjects/Bed.h"

/*
Constructor for the Bed object.
Returns a pointer for a Bed.

@param (location) The current location of the Bed with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Bed::Bed(Vector3f location, Vector3f orientation, Vector3f scale,
         Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {}

/**
Destructor for the Bed object.
Deletes the pointer for the Bed object.
*/
Bed::~Bed() {}