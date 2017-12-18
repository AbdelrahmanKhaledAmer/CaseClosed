#ifndef FOOTPRINTS_H
#define FOOTPRINTS_H

#include "headerFiles/Objects/InteractiveObjects/Clues/ClueImage.h"
#include <Eigen/Dense>

using namespace Eigen;

class Footprints : public ClueImage {
public:
  // Main functions
  Footprints(Vector3f location, Vector3f orientation, Vector3f scale,
              Vector3f dimensions); // Constructor
  ~Footprints();                   // Destructor
  void virtual setModel(char *modelPath = "");
};

#endif