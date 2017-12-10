#include "headerFiles/Objects/NonInteractiveObjects/Bed.h"

/*
Constructor for the Bed object.
Returns a pointer for a Bed.

@param (location) The current location of the Bed with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Bed::Bed(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(2.5f, 0.5f, 2.8f)) {}

/**
Destructor for the Bed object.
Deletes the pointer for the Bed object.
*/
Bed::~Bed() {}

void Bed::draw() {
  float scale = 0.0026;

  glPushMatrix();
  {
    glTranslatef(-0.1, 0, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}