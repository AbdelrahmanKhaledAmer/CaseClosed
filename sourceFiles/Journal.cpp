#include "headerFiles\Journal.h"
#include <iostream>

/*
Constructor for the Journal object.
Returns a pointer for a Journal.

@param (location) The current location of the Journal with respect to the global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to Object Object
*/

Journal::Journal(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions, std::string words):Object(location, orientation, scale, dimensions)
{
	this->notes_ = &words;
}

/**
Destructor for the Journal object.
Deletes the pointer for the Journal object.
*/
Journal::~Journal()
{

}