#include "headerFiles/Objects/NonInteractiveObjects/Sofa.h"

/*
Constructor for the Sofa object.
Returns a pointer for a Sofa.

@param (location) The current location of the Sofa with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Sofa::Sofa(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(1.7, 0.9, 0.975)) {}

/**
Destructor for the Sofa object.
Deletes the pointer for the Sofa object.
*/
Sofa::~Sofa() {

}

void Sofa::draw() {
  float scale = 0.0009;

  glPushMatrix();
  {
    glTranslatef(0, 0.42, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Sofa::drawBoundries() { __super::drawBoundries(1.7, 0.9, 0.975); }

void Sofa::setModel(){
    char* modelPath = "assets/models/furniture/Sofa/Sofa 1.3DS";
    model_.Load(modelPath);
}