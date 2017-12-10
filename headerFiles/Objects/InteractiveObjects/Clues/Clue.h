#ifndef CLUE_H
#define CLUE_H

#include <Eigen/Dense>
#include "headerFiles\Objects\InteractiveObjects\InteractiveObject.h"



using namespace Eigen;

class Clue : public InteractiveObject
{
public:
	// Main functions
	Clue(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions);    // Constructor
	~Clue();                                                                                              // Destructor

	void draw();
	bool isFound();
	void find(bool state);
	protected:
		bool isFound_=false;

};

#endif