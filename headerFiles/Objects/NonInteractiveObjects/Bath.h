#ifndef BATH_H
#define BATH_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class Bath : public NonInteractiveObject {
public:
  // Main functions
  Bath(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Bath();                                                       // Destructor
  void virtual draw();
  void virtual drawBoundries(); // Draw Object Boundries
  void virtual setModel(char *modelPath = "");
};

#endif