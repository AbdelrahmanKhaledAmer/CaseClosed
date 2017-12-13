#ifndef JOURNAL_H
#define JOURNAL_H

#include <Eigen/Dense>
#include "headerFiles/Objects/Object.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include "headerFiles/Image.h"
#include "SOIL/src/SOIL.h"

using namespace Eigen;

class Journal : public Object
{
public:
	// Main functions
	Journal(Vector3f location, Vector3f orientation, Vector3f scale);    // Constructor
	~Journal();                                                                                              // Destructor

	// write function
	void write(int clueIndex, int property = 0);
	void draw();
	void setModel();
private:
	bool clues_[10];
	int cluesState_[10];
	GLuint clueImages_[10][3];
	GLuint journalImage_;
};

#endif