#include "headerFiles/Objects/NonInteractiveObjects/Sink.h"

/*
Constructor for the Sink object.
Returns a pointer for a Sink.

@param (location) The current location of the Sink with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Sink::Sink(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(1.1f, 0.8f, 0.6f)) {}
/**
Destructor for the Sink object.
Deletes the pointer for the Sink object.
*/
Sink::~Sink() {}

void Sink::draw() {
  float scale = 0.028;

  glPushMatrix();
  {
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Sink::drawBoundries() { __super::drawBoundries(1.1f, 0.8f, 0.6f); }

void Sink::setModel() {
  __super::setModel("assets/models/furniture/Sink/Wash-basin Ravak SDZU praktik S N080317.3DS");
}