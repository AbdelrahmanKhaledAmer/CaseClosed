#ifndef FAN_H
#define FAN_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class Fan : public NonInteractiveObject {
public:
  // Main functions
  Fan(Vector3f location, Vector3f orientation,
               Vector3f scale); // Constructor
  ~Fan();              // Destructor
  void virtual draw();
  void virtual setModel(char *modelPath = "");
};

#endif