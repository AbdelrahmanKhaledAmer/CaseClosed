#ifndef TV_H
#define TV_H

#include <Eigen/Dense>
#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"

using namespace Eigen;

class Tv : public NonInteractiveObject
{
public:
	// Main functions
	Tv(Vector3f location, Vector3f orientation, Vector3f scale);    // Constructor
	~Tv();                                                                     		   // Destructor
	void draw();
	void drawBoundries();           // Draw Object Boundries
	void setModel();
};
#endif