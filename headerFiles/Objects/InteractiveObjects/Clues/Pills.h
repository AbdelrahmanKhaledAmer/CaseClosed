#ifndef Pills_H
#define Pills_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>

using namespace Eigen;

class Pills : public Clue {
public:
  // Main functions
  Pills(Vector3f location, Vector3f orientation,
        Vector3f scale); // Constructor
  ~Pills();              // Destructor
  void draw();
  void setModel();
};

#endif