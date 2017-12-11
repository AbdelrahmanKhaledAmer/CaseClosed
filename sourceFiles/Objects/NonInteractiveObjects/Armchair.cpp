#include "headerFiles/Objects/NonInteractiveObjects/Armchair.h"

/*
Constructor for the Armchair object.
Returns a pointer for a Armchair.

@param (location) The current location of the Armchair with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Armchair::Armchair(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(0.975, 0.9, 0.975)) {}

/**
Destructor for the Armchair object.
Deletes the pointer for the Armchair object.
*/
Armchair::~Armchair() {

}

void Armchair::draw() {
  float scale = 0.0009;

  glPushMatrix();
  {
    glTranslatef(0, 0.42, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Armchair::drawBoundries() { __super::drawBoundries(0.975, 0.9, 0.975); }

void Armchair::setModel() {
  __super::setModel("assets/models/furniture/Armchair/Armchair.3DS");
}