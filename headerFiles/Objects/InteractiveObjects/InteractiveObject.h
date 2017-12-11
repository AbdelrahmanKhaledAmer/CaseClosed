#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H

#include <Eigen/Dense>
#include "headerFiles/Objects/Object.h"


using namespace Eigen;

class InteractiveObject : public Object
{
public:
	// Main functions
	InteractiveObject(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions);    // Constructor
	~InteractiveObject();                                                                                              // Destructor

	void setLocation(Vector3f location);

	std::string Interact();

	void draw();
	void rotate();
	void setModel(char* modelPath);
};

#endif