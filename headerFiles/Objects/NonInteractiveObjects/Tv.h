#ifndef TV_H
#define TV_H

#include <Eigen/Dense>
#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"

using namespace Eigen;

class Tv : public NonInteractiveObject
{
public:
	// Main functions
	Tv(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions);    // Constructor
	~Tv();                                                                     		   // Destructor
};

#endif