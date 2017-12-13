#include "headerFiles/Objects/NonInteractiveObjects/CoffeeTable.h"

/*
Constructor for the CoffeeTable object.
Returns a pointer for a CoffeeTable.

@param (location) The current location of the CoffeeTable with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

CoffeeTable::CoffeeTable(Vector3f location, Vector3f orientation,
                         Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(1.05, 0.3, 0.4)) {}

/**
Destructor for the CoffeeTable object.
Deletes the pointer for the CoffeeTable object.
*/
CoffeeTable::~CoffeeTable() {}

void CoffeeTable::draw() {
  float scale = 0.02;

  glPushMatrix();
  {
    glRotatef(orientation_.y(), 0, 1, 0);
    glTranslatef(0.42, -0.3, 0.48);
    glRotatef(orientation_.y() * -1, 0, 1, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void CoffeeTable::drawBoundries() { __super::drawBoundries(1.05, 0.6, 0.4); }

void CoffeeTable::setModel() {
  __super::setModel("assets/models/furniture/CoffeeTable/Table.3DS");
}