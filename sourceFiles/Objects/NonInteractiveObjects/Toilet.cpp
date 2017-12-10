#include "headerFiles/Objects/NonInteractiveObjects/Toilet.h"

/*
Constructor for the Toilet object.
Returns a pointer for a Toilet.

@param (location) The current location of the Toilet with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Toilet::Toilet(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(0.6f, 0.9f, 0.5f)) {}

/**
Destructor for the Toilet object.
Deletes the pointer for the Toilet object.
*/
Toilet::~Toilet() {}

void Toilet::draw() {
  float scale = 0.0026;

  glPushMatrix();
  {
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Toilet::drawBoundries() { __super::drawBoundries(0.6f, 0.9f, 0.5f); }
