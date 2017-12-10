#include "headerFiles/Objects/NonInteractiveObjects/Bath.h"

/*
Constructor for the Bath object.
Returns a pointer for a Bath.

@param (location) The current location of the Bath with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Bath::Bath(Vector3f location, Vector3f orientation,
                         Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(0.9, 0.7, 1.9)) {}

/**
Destructor for the Bath object.
Deletes the pointer for the Bath object.
*/
Bath::~Bath() {}

void Bath::draw() {
  float scale = 0.0001;

  glPushMatrix();
  {
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Bath::drawBoundries() { __super::drawBoundries(0.9, 0.7, 1.9); }
