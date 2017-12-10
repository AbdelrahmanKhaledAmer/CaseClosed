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
                           Vector3f(1.7f, 0.5f, 1.7f)) {}

/**
Destructor for the DiningSet object.
Deletes the pointer for the DiningSet object.
*/
DiningSet::~DiningSet() {

}

void DiningSet::draw() {
  float scale = 0.001;

  glPushMatrix();
  {
    glTranslatef(0, 0.35, 0);
    glScalef(scale, scale, scale);
    __super::draw();
  }
  glPopMatrix();
}

void DiningSet::drawBoundries() {
  glPushMatrix();
  {
    glScalef(1.5, 0.9, 1.25);
    glTranslatef(0, 0.5, 0);
    glutWireCube(1);
    // glutSolidCube(1);
  }
  glPopMatrix();
}
