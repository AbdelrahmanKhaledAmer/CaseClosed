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

    bool intersects(Object object); // Check overlapping objects
	void virtual draw();
	void virtual drawBoundries();           // Draw Object Boundries                                                       		   // Destructor
	void virtual setModel(char *modelPath = "");

protected:
  NonInteractiveObject *part1_ , *part2_;
};

#endif