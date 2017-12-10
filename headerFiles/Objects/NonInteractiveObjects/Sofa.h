#ifndef SOFA_H
#define SOFA_H

#include <Eigen/Dense>
#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"

using namespace Eigen;

class Sofa : public NonInteractiveObject
{
public:
	// Main functions
	Sofa(Vector3f location, Vector3f orientation, Vector3f scale);    // Constructor
~Sofa();                                                              // Destructor
	void draw();
	void drawBoundries();           // Draw Object Boundries
};
#endif