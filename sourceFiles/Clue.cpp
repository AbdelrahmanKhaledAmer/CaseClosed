#include "headerFiles\Clue.h"

/*
Constructor for the Clue object.
Returns a pointer for a Clue.

@param (location) The current location of the Clue with respect to the global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/

Clue::Clue(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions) :InteractiveObject(location, orientation, scale, dimensions)
{
	this->location_ = location;
	this->orientation_ = orientation;
	this->scale_ = scale;
	this->dimensions_ = Vector3f(dimensions.x() * scale.x(), dimensions.y() * scale.y(), dimensions.z() * scale.z());
}

/**
Destructor for the Clue object.
Deletes the pointer for the Clue object.
*/
Clue::~Clue()
{

}