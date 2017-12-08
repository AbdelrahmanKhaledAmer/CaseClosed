#include "headerFiles/Objects/NonInteractiveObjects/CellingLight.h"

/*
Constructor for the CellingLight object.
Returns a pointer for a CellingLight.

@param (location) The current location of the CellingLight with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

CellingLight::CellingLight(Vector3f location, Vector3f orientation,
                           Vector3f scale, Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {}

/**
Destructor for the CellingLight object.
Deletes the pointer for the CellingLight object.
*/
CellingLight::~CellingLight() {}