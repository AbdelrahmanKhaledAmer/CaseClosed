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
                           Vector3f(1.7f, 0.5f, 1.7f)) {}

/**
Destructor for the CoffeeTable object.
Deletes the pointer for the CoffeeTable object.
*/
CoffeeTable::~CoffeeTable() {}

void CoffeeTable::draw() {
  float scale = 0.0005;

  glPushMatrix();
  {
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void CoffeeTable::drawBoundries() { __super::drawBoundries(1.2, 0.4, 1.2); }
