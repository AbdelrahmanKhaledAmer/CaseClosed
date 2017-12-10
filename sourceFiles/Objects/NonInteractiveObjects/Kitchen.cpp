#include "headerFiles/Objects/NonInteractiveObjects/Kitchen.h"

/*
Constructor for the Kitchen object.
Returns a pointer for a Kitchen.

@param (location) The current location of the Kitchen with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Kitchen::Kitchen(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(2.1, 1.9, 3)) {}

/**
Destructor for the Kitchen object.
Deletes the pointer for the Kitchen object.
*/
Kitchen::~Kitchen() {

}

void Kitchen::draw() {
  float scale = 0.018;

  glPushMatrix();
  {
    glTranslatef(0, 0, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Kitchen::drawBoundries() { __super::drawBoundries(2.1, 1.9, 3); }

