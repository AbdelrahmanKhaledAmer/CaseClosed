#include "headerFiles\Objects\InteractiveObjects\Clues\BrokenGlass.h"

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
BrokenGlass::BrokenGlass(Vector3f location, Vector3f orientation,
                         Vector3f scale, Vector3f dimensions)
    : Clue(location, orientation, scale, dimensions) {}

/**
Destructor for the Body object.
Deletes the pointer for the Body object.
*/
BrokenGlass::~BrokenGlass() {}

void BrokenGlass::setModel() {
  this->image_ = loadImage("assets/images/broken_glass.png");
}

void BrokenGlass::draw() {
  float minX = location_.x();
  float maxX = location_.x() + dimensions_.x();
  float minY = location_.z();
  float maxY = location_.z() + dimensions_.z();

  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(scale_.x(), scale_.y(), scale_.z());
    drawImageHorizontal(minX, maxX, minY, maxY, this->image_);
  }
  glPopMatrix();
}