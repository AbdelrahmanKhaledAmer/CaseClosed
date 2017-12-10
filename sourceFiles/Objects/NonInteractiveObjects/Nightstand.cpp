#include "headerFiles/Objects/NonInteractiveObjects/Nightstand.h"

/*
Constructor for the Nightstand object.
Returns a pointer for a Nightstand.

@param (location) The current location of the Nightstand with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Nightstand::Nightstand(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(1.7f, 0.5f, 1.7f)) {}

/**
Destructor for the Nightstand object.
Deletes the pointer for the Nightstand object.
*/
Nightstand::~Nightstand() {}