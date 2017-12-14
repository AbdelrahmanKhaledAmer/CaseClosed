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
  float scale = 0.018;

  glPushMatrix();
  {
    glTranslatef(0, 0, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void Kitchen::drawBoundries() {
  (*this->part1_).drawBoundries(3, 1.9, 0.5);
  (*this->part2_).drawBoundries(0.5, 1.9, 1.64);
}

void Kitchen::setModel() {
  __super::setModel("assets/models/furniture/Kitchen/Kitchen N100714.3DS");
}

bool Kitchen::intersects(Object object) {
  return (*this->part1_).intersects(object) || (*this->part2_).intersects(object);
  //   float obj11XMin = this->location().x() - this->dimensions1_.x() / 2;
  //   float obj11XMax = this->location().x() + this->dimensions1_.x() / 2;
  //   float obj11YMin = this->location().y() - this->dimensions1_.y() / 2;
  //   float obj11YMax = this->location().y() + this->dimensions1_.y() / 2;
  //   float obj11ZMin = this->location().z() - this->dimensions1_.z() / 2;
  //   float obj11ZMax = this->location().z() + this->dimensions1_.z() / 2;
  //   float obj12XMin = object.location().x() - object.dimensions().x() / 2;
  //   float obj12XMax = object.location().x() + object.dimensions().x() / 2;
  //   float obj12YMin = object.location().y() - object.dimensions().y() / 2;
  //   float obj12YMax = object.location().y() + object.dimensions().y() / 2;
  //   float obj12ZMin = object.location().z() - object.dimensions().z() / 2;
  //   float obj12ZMax = object.location().z() + object.dimensions().z() / 2;
  //   bool intersects1X = (obj11XMin >= obj12XMin && obj11XMin <= obj12XMax) ||
  //                       (obj11XMax >= obj12XMin && obj11XMax <= obj12XMax) ||
  //                       (obj12XMin >= obj11XMin && obj12XMin <= obj11XMax) ||
  //                       (obj12XMax >= obj11XMin && obj12XMax <= obj11XMax);
  //   bool intersects1Y = (obj11YMin >= obj12YMin && obj11YMin <= obj12YMax) ||
  //                       (obj11YMax >= obj12YMin && obj11YMax <= obj12YMax) ||
  //                       (obj12YMin >= obj11YMin && obj12YMin <= obj11YMax) ||
  //                       (obj12YMax >= obj11YMin && obj12YMax <= obj11YMax);
  //   bool intersects1Z = (obj11ZMin >= obj12ZMin && obj11ZMin <= obj12ZMax) ||
  //                       (obj11ZMax >= obj12ZMin && obj11ZMax <= obj12ZMax) ||
  //                       (obj12ZMin >= obj11ZMin && obj12ZMin <= obj11ZMax) ||
  //                       (obj12ZMax >= obj11ZMin && obj12ZMax <= obj11ZMax);
  //   bool intersect1 = intersects1X && intersects1Y && intersects1Z;

  //   float obj21XMin = this->location().x() - this->dimensions2_.x() / 2;
  //   float obj21XMax = this->location().x() + this->dimensions2_.x() / 2;
  //   float obj21YMin = this->location().y() - this->dimensions2_.y() / 2;
  //   float obj21YMax = this->location().y() + this->dimensions2_.y() / 2;
  //   float obj21ZMin = this->location().z() - this->dimensions2_.z() / 2;
  //   float obj21ZMax = this->location().z() + this->dimensions2_.z() / 2;
  //   float obj22XMin = object.location().x() - object.dimensions().x() / 2;
  //   float obj22XMax = object.location().x() + object.dimensions().x() / 2;
  //   float obj22YMin = object.location().y() - object.dimensions().y() / 2;
  //   float obj22YMax = object.location().y() + object.dimensions().y() / 2;
  //   float obj22ZMin = object.location().z() - object.dimensions().z() / 2;
  //   float obj22ZMax = object.location().z() + object.dimensions().z() / 2;
  //   bool intersects2X = (obj21XMin >= obj22XMin && obj21XMin <= obj22XMax) ||
  //                       (obj21XMax >= obj22XMin && obj21XMax <= obj22XMax) ||
  //                       (obj22XMin >= obj21XMin && obj22XMin <= obj21XMax) ||
  //                       (obj22XMax >= obj21XMin && obj22XMax <= obj21XMax);
  //   bool intersects2Y = (obj21YMin >= obj22YMin && obj21YMin <= obj22YMax) ||
  //                       (obj21YMax >= obj22YMin && obj21YMax <= obj22YMax) ||
  //                       (obj22YMin >= obj21YMin && obj22YMin <= obj21YMax) ||
  //                       (obj22YMax >= obj21YMin && obj22YMax <= obj21YMax);
  //   bool intersects2Z = (obj21ZMin >= obj22ZMin && obj21ZMin <= obj22ZMax) ||
  //                       (obj21ZMax >= obj22ZMin && obj21ZMax <= obj22ZMax) ||
  //                       (obj22ZMin >= obj21ZMin && obj22ZMin <= obj21ZMax) ||
  //                       (obj22ZMax >= obj21ZMin && obj22ZMax <= obj21ZMax);
  //   bool intersect2 = intersects2X && intersects2Y && intersects2Z;

  //   return intersect1 || intersect2;
}