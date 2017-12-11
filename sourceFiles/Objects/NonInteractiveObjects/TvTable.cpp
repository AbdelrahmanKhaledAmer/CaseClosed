#include "headerFiles/Objects/NonInteractiveObjects/TvTable.h"

/*
Constructor for the TvTable object.
Returns a pointer for a TvTable.

@param (location) The current location of the TvTable with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

TvTable::TvTable(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(1.7, 0.9, 0.975)) {}

/**
Destructor for the TvTable object.
Deletes the pointer for the TvTable object.
*/
TvTable::~TvTable() {

}

void TvTable::draw() {
  float scale = 0.007;

  glPushMatrix();
  {
    glTranslatef(-3, 0, 0);
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void TvTable::drawBoundries() { __super::drawBoundries(0.9 , 1.2, 0.4); }

void TvTable::setModel() {
  __super::setModel("assets/models/furniture/TvTable/Rack 2.3DS");
}