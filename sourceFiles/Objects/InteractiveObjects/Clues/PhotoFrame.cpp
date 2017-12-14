#include "headerFiles\Objects\InteractiveObjects\Clues\PhotoFrame.h"

/*
Constructor for the PhotoFrame object.
Returns a pointer for a PhotoFrame.

@param (location) The current location of the PhotoFrame with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
PhotoFrame::PhotoFrame(Vector3f location, Vector3f orientation, Vector3f scale)
    : Clue(location, orientation, scale, Vector3f(0, 0, 0)) {}

/**
Destructor for the PhotoFrame object.
Deletes the pointer for the PhotoFrame object.
*/
PhotoFrame::~PhotoFrame() {}

void PhotoFrame::draw() {
  float scale = 0.003;

  glPushMatrix();
  {
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void PhotoFrame::setModel() {
  __super::setModel(
      "assets/models/clues/PhotoFrame/Picture.3DS");
}

std::string PhotoFrame::Interact()
{
  return "0";
}