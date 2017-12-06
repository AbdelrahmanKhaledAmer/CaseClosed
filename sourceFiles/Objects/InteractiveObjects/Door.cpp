#include "headerFiles\Objects\InteractiveObjects\Door.h"

/*
Constructor for the Door object.
Returns a pointer for a Door.

@param (location) The current location of the Door with respect to the global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/

Door::Door(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions) :InteractiveObject(location, orientation, scale, dimensions)
{
	this->location_ = location;
	this->orientation_ = orientation;
	this->scale_ = scale;
	this->dimensions_ = Vector3f(dimensions.x() * scale.x(), dimensions.y() * scale.y(), dimensions.z() * scale.z());
	this->model_.Load("assets/models/furniture/Door/Door.3DS");
}

/**
Destructor for the Door object.
Deletes the pointer for the Door object.
*/
Door::~Door()
{

}