#ifndef NONINTERACTIVEOBJECT_H
#define NONINTERACTIVEOBJECT_H

#include "headerFiles/Objects/Object.h"
#include <Eigen/Dense>

using namespace Eigen;

class NonInteractiveObject : public Object {
public:
  // Main functions
  NonInteractiveObject(Vector3f location, Vector3f orientation, Vector3f scale,
                       Vector3f dimensions); // Constructor
  ~NonInteractiveObject();              // Destructor
  void draw(float locScale = 1);
  void drawBoundries();           // Draw Object Boundries
};

#endif