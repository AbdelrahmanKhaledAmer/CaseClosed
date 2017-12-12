#include "headerFiles\Objects\InteractiveObjects\Door.h"

/*
Constructor for the Door object.
Returns a pointer for a Door.

@param (location) The current location of the Door with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Door::Door(Vector3f location, Vector3f orientation, Vector3f scale)
    : InteractiveObject(location, orientation, scale,
                           Vector3f(0.7, 1.7, 0.15)) {}

/**
Destructor for the Door object.
Deletes the pointer for the Door object.
*/
Door::~Door() {}

std::string Door::Interact() { return ""; }

void Door::draw() {
  float scale = 0.009;

  glPushMatrix();
  {
    // glTranslatef(0, 0.35, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Door::drawBoundries() { __super::drawBoundries(0.7, 1.7, 0.15); }

void Door::setModel() {
  __super::setModel("assets/models/furniture/Door/Door Endless Boiserie Sliding Door Longhi N291216.3DS");
}