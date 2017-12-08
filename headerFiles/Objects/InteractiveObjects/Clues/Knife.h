#ifndef KNIFE_H
#define KNIFE_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>

using namespace Eigen;

class Knife : public Clue {
public:
  // Main functions
  Knife(Vector3f location, Vector3f orientation, Vector3f scale,
        Vector3f dimensions); // Constructor
  ~Knife();                   // Destructor
};

#endif