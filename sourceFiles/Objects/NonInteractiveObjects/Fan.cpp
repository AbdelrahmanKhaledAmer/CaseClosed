#include "headerFiles/Objects/NonInteractiveObjects/Fan.h"

/*
Constructor for the Fan object.
Returns a pointer for a Fan.

@param (location) The current location of the Fan with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Fan::Fan(Vector3f location, Vector3f orientation, Vector3f scale,
         Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {}

/**
Destructor for the Fan object.
Deletes the pointer for the Fan object.
*/
Fan::~Fan() {}