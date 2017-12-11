#ifndef SOFA_H
#define SOFA_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class Sofa : public NonInteractiveObject {
public:
  // Main functions
  Sofa(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Sofa();                                                       // Destructor
  void draw();
  void drawBoundries(); // Draw Object Boundries
  void setModel();
};
#endif