#ifndef BLOODTRAIL_H
#define BLOODTRAIL_H

#include "headerFiles/Objects/InteractiveObjects/Clues/ClueImage.h"
#include <Eigen/Dense>

using namespace Eigen;

class Bloodtrail : public ClueImage {
public:
  // Main functions
  Bloodtrail(Vector3f location, Vector3f orientation, Vector3f scale,
             Vector3f dimensions); // Constructor
  ~Bloodtrail();                   // Destructor
  void virtual setModel(char *modelPath = ""); // Set Model
};

#endif