#include "headerFiles/Objects/NonInteractiveObjects/CellingLight1.h"

/*
Constructor for the CellingLight1 object.
Returns a pointer for a CellingLight1.

@param (location) The current location of the CellingLight1 with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

CellingLight1::CellingLight1(Vector3f location, Vector3f orientation,
                           Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                         Vector3f(0, 0, 0)) {}

/**
Destructor for the CellingLight1 object.
Deletes the pointer for the CellingLight1 object.
*/
CellingLight1::~CellingLight1() {}

void CellingLight1::draw() {
  locscale_ = 0.002;

  glPushMatrix();
  {
    // glTranslatef(0, 0.35, 0);

    __super::draw();
  }
  glPopMatrix();
}

void CellingLight1::setModel(char *modelPath)  {
  __super::setModel("assets/models/furniture/CellingLight1/Lamp 2.3DS");
}