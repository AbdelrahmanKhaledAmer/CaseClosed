#include "headerFiles\InteractiveObject.h"
#include <iostream>

/*
Constructor for the InteractiveObject object.
Returns a pointer for a InteractiveObject.

@param (location) The current location of the InteractiveObject with respect to the global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to Object object
*/

InteractiveObject::InteractiveObject(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions) :Object(location, orientation, scale, dimensions)
{
	this->location_ = location;
	this->orientation_ = orientation;
	this->scale_ = scale;
	this->dimensions_ = Vector3f(dimensions.x() * scale.x(), dimensions.y() * scale.y(), dimensions.z() * scale.z());
}

/**
Destructor for the InteractiveObject object.
Deletes the pointer for the InteractiveObject object.
*/
InteractiveObject::~InteractiveObject()
{

}

std::string Interact()
{
	return "";
}