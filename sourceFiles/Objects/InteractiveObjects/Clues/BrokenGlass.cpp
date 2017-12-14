#include "headerFiles\Objects\InteractiveObjects\Clues\BrokenGlass.h"

/*
Constructor for the BrokenGlass object.
Returns a pointer for a BrokenGlass.

@param (location) The current location of the BrokenGlass with respect to the global
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
Destructor for the BrokenGlass object.
Deletes the pointer for the BrokenGlass object.
*/
BrokenGlass::~BrokenGlass() {}

void BrokenGlass::setModel() {
  this->image_ = loadImage("assets/images/broken_glass.png");
}

void BrokenGlass::draw() {
  float minX = -dimensions_.x();
  float maxX = dimensions_.x();
  float minY = -dimensions_.z();
  float maxY = dimensions_.z();

  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(scale_.x(), scale_.y(), scale_.z());
    drawImageHorizontal(minX, maxX, minY, maxY, this->image_);
  }
  glPopMatrix();
}