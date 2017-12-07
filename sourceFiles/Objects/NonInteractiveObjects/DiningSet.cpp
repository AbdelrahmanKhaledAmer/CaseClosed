#include "headerFiles/Objects/NonInteractiveObjects/DiningSet.h"

/*
Constructor for the DiningSet object.
Returns a pointer for a DiningSet.

@param (location) The current location of the DiningSet with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

DiningSet::DiningSet(Vector3f location, Vector3f orientation, Vector3f scale,
                     Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {

}

/**
Destructor for the DiningSet object.
Deletes the pointer for the DiningSet object.
*/
DiningSet::~DiningSet() {

}