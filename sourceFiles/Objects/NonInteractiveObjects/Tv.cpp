#include "headerFiles/Objects/NonInteractiveObjects/Tv.h"

/*
Constructor for the Tv object.
Returns a pointer for a Tv.

@param (location) The current location of the Tv with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Tv::Tv(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(1.7, 0.9, 0.975)) {}

/**
Destructor for the Tv object.
Deletes the pointer for the Tv object.
*/
Tv::~Tv() {

}

void Tv::draw() {
  locscale_ = 0.024;

  glPushMatrix();
  {
    glTranslatef(0.05, 0.5, 0);

    __super::draw();
  }
  glPopMatrix();
}

void Tv::drawBoundries() { __super::drawBoundries(1 , 1.1, 0.5); }

void Tv::setModel(char *modelPath)  {
  __super::setModel("assets/models/furniture/Tv/TV set Ergo E32C20 LCD N200314.3DS");
}