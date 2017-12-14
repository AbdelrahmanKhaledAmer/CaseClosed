#include "headerFiles\Objects\NonInteractiveObjects\OutsideImage.h"

/*
Constructor for the OutsideImage object.
Returns a pointer for a OutsideImage.

@param (location) The current location of the Body with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
OutsideImage::OutsideImage(Vector3f location, Vector3f orientation,
                           Vector3f scale, Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {}

/**
Destructor for the OutsideImage object.
Deletes the pointer for the OutsideImage object.
*/
OutsideImage::~OutsideImage() {}

void OutsideImage::draw() {
  float minX = -dimensions_.x();
  float maxX = dimensions_.x();
  float minY = -dimensions_.z();
  float maxY = dimensions_.z();

  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(scale_.x(), scale_.y(), scale_.z());
    glRotated(90, 0, 1, 0);
    drawImage(minX, maxX, minY, maxY, this->image_);
  }
  glPopMatrix();
}

void OutsideImage::setImage(char *imagePath) {
  this->image_ = loadImage(imagePath);
}