#include "headerFiles\Objects\InteractiveObjects\InteractiveObject.h"
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

InteractiveObject::InteractiveObject(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions) 
	:Object(location, orientation, scale, dimensions)
{

}

/**
Destructor for the InteractiveObject object.
Deletes the pointer for the InteractiveObject object.
*/
InteractiveObject::~InteractiveObject()
{

}

void InteractiveObject::setLocation(Vector3f location)
{
	this->location_ = location;
}

void InteractiveObject::draw()
{
	//__super::draw();
	glPushMatrix();
	{
		glTranslatef(location_.x(), location_.y(), location_.z());
		glRotatef(orientation_.y(), 0, 1, 0);
		glutSolidCube(0.5);
	}
	glPopMatrix();
}

void InteractiveObject::rotate()
{
	orientation_.y() -= 1;
}