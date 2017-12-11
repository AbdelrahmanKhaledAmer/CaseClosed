#ifndef FOOTPRINTS_H
#define FOOTPRINTS_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>

using namespace Eigen;

class Footprints : public Clue {
public:
  // Main functions
  Footprints(Vector3f location, Vector3f orientation, Vector3f scale,
              Vector3f dimensions); // Constructor
  ~Footprints();                   // Destructor
  void draw();
  void setImage(GLuint image);
protected:
  GLuint image_;
};

#endif