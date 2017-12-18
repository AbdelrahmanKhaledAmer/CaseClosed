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
  void virtual draw();
  void drawBoundries(float xLength, float yLength, float zLength);   // Draw Object Boundries
  void virtual setModel(char* modelPath);
};

#endif