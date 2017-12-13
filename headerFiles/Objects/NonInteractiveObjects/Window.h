#ifndef WINDOW_H
#define WINDOW_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>
#include "SOIL/src/SOIL.h"

using namespace Eigen;

class Window : public NonInteractiveObject {
public:
  // Main functions
  Window(Vector3f location, Vector3f orientation,
         Vector3f scale); // Constructor
  ~Window();              // Destructor
  void draw();
  void setModel();

protected:
	GLuint image_;
};

#endif