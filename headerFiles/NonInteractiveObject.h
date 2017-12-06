#ifndef NONINTERACTIVEOBJECT_H
#define NONINTERACTIVEOBJECT_H

#include <Eigen/Dense>
#include "headerFiles/Object.h"


using namespace Eigen;

class NonInteractiveObject : public Object
{
public:
	// Main functions
	NonInteractiveObject(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions);    // Constructor
	~NonInteractiveObject();                                                                                              // Destructor

	
};

#endif