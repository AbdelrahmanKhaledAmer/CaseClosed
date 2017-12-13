#include "headerFiles/Objects/Flashlight.h"

/*
Constructor for the Flashlight object.
Returns a pointer for a Flashlight.

@param (location) The current location of the Flashlight with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to Flashlight Object
*/

Flashlight::Flashlight(Vector3f location, Vector3f orientation, Vector3f scale,
                       Vector3f dimensions)
    : Object(location, orientation, scale, dimensions) {}

/**
Destructor for the Flashlight object.
Deletes the pointer for the Flashlight object.
*/
Flashlight::~Flashlight() {}

void Flashlight::turnOn() { this->on_ = true; }
void Flashlight::turnOff() { this->on_ = false; }

bool Flashlight::isOn() { return this->on_; }

void Flashlight::draw(float yAngle) {
  float scale = 0.005;

  glPushMatrix();
  {
    glScalef(scale, scale, scale);
    glPushMatrix();
    {
      glTranslatef(location_.x() / scale, location_.y() / scale, location_.z() / scale);
      glScalef(scale_.x(), scale_.y(), scale_.z());
      glRotatef(yAngle, 0, 1, 0);
      model_.Draw();
    }
    glPopMatrix();
  }
  glPopMatrix();
}

void Flashlight::setModel() {
  __super::setModel("assets/models/Flashlight/fonarik_low_3ds.3DS");
}