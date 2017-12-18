#ifndef CLUE_H
#define CLUE_H

#include <Eigen/Dense>
#include "headerFiles\Objects\InteractiveObjects\InteractiveObject.h"

#define RELEVANT 1
#define IRRELEVANT -1
#define  NOT_STATED 0

using namespace Eigen;

class Clue : public InteractiveObject
{
public:
	// Main functions
	Clue(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions);    // Constructor
	~Clue();                                                                                              // Destructor

  	void virtual draw();
  	void virtual setModel(char* modelPath);
	bool isFound();
	void find(bool state);
	void setState(int val);
	int getState();
	virtual std::string Interact();
protected:
	bool isFound_=false;
	int state=NOT_STATED;
};

#endif