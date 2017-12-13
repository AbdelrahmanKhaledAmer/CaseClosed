#include "headerFiles\Objects\InteractiveObjects\InteractiveObject.h"
#include <iostream>

/*
Constructor for the InteractiveObject object.
Returns a pointer for a InteractiveObject.

@param (location) The current location of the InteractiveObject with respect to
the global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to Object object
*/
InteractiveObject::InteractiveObject(Vector3f location, Vector3f orientation,
                                     Vector3f scale, Vector3f dimensions)
    : Object(location, orientation, scale, dimensions) {}

/**
Destructor for the InteractiveObject object.
Deletes the pointer for the InteractiveObject object.
*/
InteractiveObject::~InteractiveObject() {}

std::string InteractiveObject::Interact() {
  // TODO
  return "";
}

void InteractiveObject::rotate() { orientation_.y() -= 1; }

void InteractiveObject::draw(float locScale) { __super::draw(locScale); }

void InteractiveObject::drawBoundries(float xLength, float yLength, float zLength) {
  __super::drawBoundries(xLength, yLength, zLength);
}

void InteractiveObject::setModel(char *modelPath) { __super::setModel(modelPath); }