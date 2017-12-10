#ifndef KITCHEN_H
#define KITCHEN_H

#include <Eigen/Dense>
#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"

using namespace Eigen;

class Kitchen : public NonInteractiveObject
{
public:
	// Main functions
	Kitchen(Vector3f location, Vector3f orientation, Vector3f scale);    // Constructor
	~Kitchen();                                                                     		   // Destructor
	void draw();
	void drawBoundries();           // Draw Object Boundries                                                       		   // Destructor
};


#endif