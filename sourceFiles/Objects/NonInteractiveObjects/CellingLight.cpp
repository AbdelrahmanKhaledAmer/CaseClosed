#include "headerFiles/Objects/NonInteractiveObjects/CellingLight.h"

/*
Constructor for the CellingLight object.
Returns a pointer for a CellingLight.

@param (location) The current location of the CellingLight with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

CellingLight::CellingLight(Vector3f location, Vector3f orientation,
                           Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                         Vector3f(0, 0, 0)) {}

/**
Destructor for the CellingLight object.
Deletes the pointer for the CellingLight object.
*/
CellingLight::~CellingLight() {}

void CellingLight::draw() {
  float scale = 0.009;

  glPushMatrix();
  {
    // glTranslatef(0, 0.35, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void CellingLight::setModel() {
  __super::setModel("assets/models/furniture/CellingLight/Luster Donolux S111000-3 white N010917.3DS");
}