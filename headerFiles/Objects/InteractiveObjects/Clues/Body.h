#ifndef BODY_H
#define BODY_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>

using namespace Eigen;

class Body : public Clue {
public:
  // Main functions
  Body(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Body();                   // Destructor
  void draw();
};

#endif