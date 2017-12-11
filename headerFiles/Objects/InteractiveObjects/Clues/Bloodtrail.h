#ifndef BLOODTRAIL_H
#define BLOODTRAIL_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>

using namespace Eigen;

class Bloodtrail : public Clue {
public:
  // Main functions
  Bloodtrail(Vector3f location, Vector3f orientation, Vector3f scale,
              Vector3f dimensions); // Constructor
  ~Bloodtrail();                   // Destructor
  void draw();
  void setImage(GLuint image);
protected:
  GLuint image_;
};

#endif