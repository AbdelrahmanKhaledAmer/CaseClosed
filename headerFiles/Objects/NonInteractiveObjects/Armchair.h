#ifndef ARMCHAIR_H
#define ARMCHAIR_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class Armchair : public NonInteractiveObject {
public:
  // Main functions
  Armchair(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Armchair();                                                       // Destructor
  void draw();
  void drawBoundries(); // Draw Object Boundries
  void setModel();
};
#endif