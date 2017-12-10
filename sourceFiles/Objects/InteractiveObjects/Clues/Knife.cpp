#include "headerFiles\Objects\InteractiveObjects\Clues\Knife.h"

/*
Constructor for the Knife object.
Returns a pointer for a Knife.

@param (location) The current location of the Knife with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Knife::Knife(Vector3f location, Vector3f orientation, Vector3f scale,
             Vector3f dimensions)
    : Clue(location, orientation, scale, dimensions) {}

/**
Destructor for the Knife object.
Deletes the pointer for the Knife object.
*/
Knife::~Knife() {}

void Knife::draw()
{
    __super::draw();
}

std::string Knife::Interact()
{
	return "Clue: This is a knife used in the murder.";
}