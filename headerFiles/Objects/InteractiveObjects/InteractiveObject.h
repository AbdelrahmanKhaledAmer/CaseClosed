#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H

#include "headerFiles/Objects/Object.h"
#include <Eigen/Dense>

using namespace Eigen;

class InteractiveObject : public Object {
public:
  // Main functions
  InteractiveObject(Vector3f location, Vector3f orientation, Vector3f scale,
                    Vector3f dimensions); // Constructor
  ~InteractiveObject();                   // Destructor

  virtual std::string Interact();
  void rotate();

  void draw(float locScale = 1);
  void drawBoundries(float xLength, float yLength, float zLength);   // Draw Object Boundries
  void setModel(char *modelPath);
};

#endif