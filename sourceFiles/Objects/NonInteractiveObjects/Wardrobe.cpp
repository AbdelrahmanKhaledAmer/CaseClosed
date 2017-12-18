#include "headerFiles/Objects/NonInteractiveObjects/Wardrobe.h"

/*
Constructor for the Wardrobe object.
Returns a pointer for a Wardrobe.

@param (location) The current location of the Wardrobe with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Wardrobe::Wardrobe(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(0.4f, 1.8f, 0.95f)) {}
/**
Destructor for the Wardrobe object.
Deletes the pointer for the Wardrobe object.
*/
Wardrobe::~Wardrobe() {}

void Wardrobe::draw() {
  locscale_ = 0.0025;

  glPushMatrix();
  {
    glTranslatef(0.21, 0, 0.36);

    __super::draw();
  }
  glPopMatrix();
}

void Wardrobe::drawBoundries() {
  __super::drawBoundries(0.4f, 1.8f, 0.95f);
}

void Wardrobe::setModel(char *modelPath)  {
  __super::setModel("assets/models/furniture/Wardrobe/Wardrobe.3DS");
}