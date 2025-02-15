#ifndef DININGSET_H
#define DININGSET_H

#include <Eigen/Dense>
#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"

using namespace Eigen;

class DiningSet : public NonInteractiveObject
{
public:
	// Main functions
	DiningSet(Vector3f location, Vector3f orientation, Vector3f scale);    // Constructor
	~DiningSet();
	void draw();
	void drawBoundries();           // Draw Object Boundries                                                       		   // Destructor
	void setModel();
};

#endif