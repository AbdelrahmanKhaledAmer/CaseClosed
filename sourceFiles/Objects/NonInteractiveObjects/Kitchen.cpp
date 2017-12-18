#include "headerFiles/Objects/NonInteractiveObjects/Kitchen.h"

/*
Constructor for the Kitchen object.
Returns a pointer for a Kitchen.

@param (location) The current location of the Kitchen with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Kitchen::Kitchen(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(3, 1.9, 2.1)) {
  this->part1_ = new NonInteractiveObject(location, orientation, scale,
                                          Vector3f(3, 1.9, 0.5));
  // printf("%.3f\n", (*this->part1_).location().z());
  (*this->part1_)
      .setLocation(Vector3f((*this->part1_).location().x(),
                            (*this->part1_).location().y(),
                            (*this->part1_).location().z() - 0.7));
  // printf("%.3f\n", (*this->part1_).location().z());

  this->part2_ = new NonInteractiveObject(location, orientation, scale,
                                          Vector3f(0.5, 1.9, 1.64));
  (*this->part2_)
      .setLocation(Vector3f((*this->part2_).location().x() - 1,
                            (*this->part2_).location().y(),
                            (*this->part2_).location().z()));
}

/**
Destructor for the Kitchen object.
Deletes the pointer for the Kitchen object.
*/
Kitchen::~Kitchen() {}

void Kitchen::draw() {
  locscale_ = 0.018;

  glPushMatrix();
  {
    glTranslatef(0, 0, 0);

    __super::draw();
  }
  glPopMatrix();
}

void Kitchen::drawBoundries() {
  this->part1_->drawBoundries(3, 1.9, 0.5);
  this->part2_->drawBoundries(0.5, 1.9, 1.64);
}

void Kitchen::setModel(char *modelPath)  {
  __super::setModel("assets/models/furniture/Kitchen/Kitchen N100714.3DS");
}

bool Kitchen::intersects(Object object) {
  return (*this->part1_).intersects(object) || (*this->part2_).intersects(object);
}