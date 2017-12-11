#ifndef JOURNAL_H
#define JOURNAL_H

#include <Eigen/Dense>
#include "headerFiles/Objects/Object.h"
#include <stdarg.h>

using namespace std;
using namespace Eigen;

class Journal : public Object
{
public:
	// Main functions
	Journal(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions, std::string words);    // Constructor
	~Journal();                                                                                              // Destructor

	// write function
	void write(string write = "");
	void draw();
protected:
	std::string* notes_;
};

#endif