#include "headerFiles\Objects\InteractiveObjects\Clues\Body.h"

/*
Constructor for the Body object.
Returns a pointer for a Body.

@param (location) The current location of the Body with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Body::Body(Vector3f location, Vector3f orientation, Vector3f scale)
    : Clue(location, orientation, scale,
                           Vector3f(0, 0, 0)) {}

/**
Destructor for the Body object.
Deletes the pointer for the Body object.
*/
Body::~Body() {}

void Body::draw() {
  float scale = 1;

  glPushMatrix();
  {
    glTranslatef(-0.8, 0.5, -1);
    glTranslatef(location_.x() / scale, location_.y() / scale, location_.z() / scale);
    glScalef(scale_.x(), scale_.y(), scale_.z());
    glRotatef(90, 1, 0, 0);
    model_.Draw();
  }
  glPopMatrix();
}

void Body::setModel() {
  __super::setModel("assets/models/clues/Body/Man N050214.3DS");
}
