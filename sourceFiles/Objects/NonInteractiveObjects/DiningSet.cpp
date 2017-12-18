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
DiningSet::DiningSet(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(1.25, 0.9, 1.5)) {}

/**
Destructor for the DiningSet object.
Deletes the pointer for the DiningSet object.
*/
DiningSet::~DiningSet() {

}

void DiningSet::draw() {
  locscale_ = 0.001;

  glPushMatrix();
  {
    glTranslatef(0, 0.35, 0);

    __super::draw();
  }
  glPopMatrix();
}

void DiningSet::drawBoundries() { __super::drawBoundries(1.25, 0.9, 1.5); }

void DiningSet::setModel(char *modelPath)  {
  __super::setModel("assets/models/furniture/DiningSet/4 Chair 2 Tone.3ds");
}