#ifndef DOOR1_H
#define DOOR1_H

#include <Eigen/Dense>
#include "headerFiles/Objects/InteractiveObjects/InteractiveObject.h"

using namespace Eigen;

class Door1 : public InteractiveObject {
public:
  // Main functions
  Door1(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Door1();
  std::string Interact();
  void draw();
  void drawBoundries(); // Draw Object Boundries // Destructor
  void setModel();      // Destructor
};

#endif