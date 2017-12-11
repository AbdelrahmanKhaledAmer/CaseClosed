#ifndef BROKENGLASS_H
#define BROKENGLASS_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include "SOIL/src/SOIL.h"
#include <Eigen/Dense>

using namespace Eigen;

class BrokenGlass : public Clue {
public:
  // Main functions
  BrokenGlass(Vector3f location, Vector3f orientation, Vector3f scale,
              Vector3f dimensions); // Constructor
  ~BrokenGlass();                   // Destructor
  void draw();
  void setImage(GLuint image);
protected:
  GLuint image_;
};

#endif