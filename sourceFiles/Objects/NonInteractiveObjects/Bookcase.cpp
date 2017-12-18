#include "headerFiles/Objects/NonInteractiveObjects/Bookcase.h"

/*
Constructor for the Bookcase object.
Returns a pointer for a Bookcase.

@param (location) The current location of the Bookcase with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Bookcase::Bookcase(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(0.25f, 1.8f, 1.45f)) {}

/**
Destructor for the Bookcase object.
Deletes the pointer for the Bookcase object.
*/
Bookcase::~Bookcase() {}

void Bookcase::draw() {
  locscale_ = 0.0007;

  glPushMatrix();
  {
    glTranslatef(0, 0.9, 0);

    glTranslatef(location_.x() / locscale_, location_.y() / locscale_, location_.z() / locscale_);
    glScalef(scale_.x(), scale_.y(), scale_.z());
    glRotatef(orientation_.y(), 0, 1, 0);
    glRotatef(-90, 1, 0, 0);
    model_.Draw();
  }
  glPopMatrix();
}
void Bookcase::drawBoundries() { __super::drawBoundries(0.25, 1.8, 1.45); }

void Bookcase::setModel(char *modelPath)  {
  __super::setModel("assets/models/furniture/Bookcase/Bookcase.3DS");
}
