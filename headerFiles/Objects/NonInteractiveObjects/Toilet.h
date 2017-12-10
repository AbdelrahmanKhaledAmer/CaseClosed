#ifndef TOILET_H
#define TOILET_H

#include <Eigen/Dense>
#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"

using namespace Eigen;

class Toilet : public NonInteractiveObject
{
public:
	// Main functions
	Toilet(Vector3f location, Vector3f orientation, Vector3f scale);    // Constructor
	~Toilet();   
	void draw();
  	void drawBoundries();   // Draw Object Boundries                                                                  		   // Destructor
};

#endif