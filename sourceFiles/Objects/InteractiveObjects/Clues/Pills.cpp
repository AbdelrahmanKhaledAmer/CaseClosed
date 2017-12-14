#include "headerFiles\Objects\InteractiveObjects\Clues\Pills.h"

/*
Constructor for the Pills object.
Returns a pointer for a Pills.

@param (location) The current location of the Pills with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Pills::Pills(Vector3f location, Vector3f orientation, Vector3f scale)
    : Clue(location, orientation, scale, Vector3f(0, 0, 0)) {}

/**
Destructor for the Pills object.
Deletes the pointer for the Pills object.
*/
Pills::~Pills() {}

void Pills::draw() {
  float scale = 0.001;

  glPushMatrix();
  {
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Pills::setModel() {
  __super::setModel("assets/models/clues/Pills/Bottle 2.3DS");
}
