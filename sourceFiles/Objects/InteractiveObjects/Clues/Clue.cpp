#include "headerFiles\Objects\InteractiveObjects\Clues\Clue.h"

/*
Constructor for the Clue object.
Returns a pointer for a Clue.

@param (location) The current location of the Clue with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/

Clue::Clue(Vector3f location, Vector3f orientation, Vector3f scale,
           Vector3f dimensions)
    : InteractiveObject(location, orientation, scale, dimensions) {}

/**
Destructor for the Clue object.
Deletes the pointer for the Clue object.
*/
Clue::~Clue() {}

void Clue::draw(float locScale) { __super::draw(locScale); }

bool Clue::isFound() { return this->isFound_; }

void Clue::find(bool state) { this->isFound_ = state; }
void Clue::setState(int val){this->state=val;}
int Clue::getState(){return this->state;}
void Clue::setModel(char *modelPath) { __super::setModel(modelPath); }