#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"

/*
Constructor for the NonInteractiveObject object.
Returns a pointer for a NonInteractiveObject.

@param (location) The current location of the NonInteractiveObject with respect
to the global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to Object Object
*/

NonInteractiveObject::NonInteractiveObject(Vector3f location,
                                           Vector3f orientation, Vector3f scale,
                                           Vector3f dimensions)
    : Object(location, orientation, scale, dimensions) {}

/**
Destructor for the NonInteractiveObject object.
Deletes the pointer for the NonInteractiveObject object.
*/
NonInteractiveObject::~NonInteractiveObject() {}

void NonInteractiveObject::draw(float locScale) { __super::draw(locScale); }
void NonInteractiveObject::drawBoundries(float xLength, float yLength, float zLength) {
  __super::drawBoundries(xLength, yLength, zLength);
}