#ifndef WALL_H
#define WALL_H

#include <Eigen/Dense>
#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"

using namespace Eigen;

class Wall : public NonInteractiveObject
{
public:
	// Main functions
	Wall(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions);    // Constructor
	~Wall();                                                                     		   // Destructor

    // Game Logic Functions
    void draw();
};

#endif