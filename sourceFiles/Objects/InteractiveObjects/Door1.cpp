#include "headerFiles\Objects\InteractiveObjects\Door1.h"

/*
Constructor for the Door1 object.
Returns a pointer for a Door1.

@param (location) The current location of the Door1 with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Door1::Door1(Vector3f location, Vector3f orientation, Vector3f scale)
    : InteractiveObject(location, orientation, scale,
                           Vector3f(0.15, 1.7, 0.15)) {}

/**
Destructor for the Door1 object.
Deletes the pointer for the Door1 object.
*/
Door1::~Door1() {}

std::string Door1::Interact() { return ""; }

void Door1::draw() {
  float scale = 0.0235;

  glPushMatrix();
  {
    // glTranslatef(0, 0.35, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Door1::drawBoundries() { __super::drawBoundries(0.15, 1.7, 0.15); }

void Door1::setModel() {
  __super::setModel("assets/models/furniture/Door1/Door ROMAGNOLI Senso Fly N040717.3DS");
}