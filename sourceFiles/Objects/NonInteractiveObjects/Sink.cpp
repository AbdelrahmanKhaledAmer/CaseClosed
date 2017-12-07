#include "headerFiles/Objects/NonInteractiveObjects/Sink.h"

/*
Constructor for the Sink object.
Returns a pointer for a Sink.

@param (location) The current location of the Sink with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Sink::Sink(Vector3f location, Vector3f orientation, Vector3f scale,
           Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {}

/**
Destructor for the Sink object.
Deletes the pointer for the Sink object.
*/
Sink::~Sink() {}