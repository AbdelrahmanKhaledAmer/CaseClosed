#ifndef BED_H
#define BED_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class Bed : public NonInteractiveObject {
public:
  // Main functions
  Bed(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Bed();                   // Destructor
  void draw();
  void drawBoundries();   // Draw Object Boundries
};

#endif