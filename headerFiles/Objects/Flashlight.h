#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

#include "headerFiles/Objects/Object.h"
#include <Eigen/Dense>

using namespace Eigen;

class Flashlight : public Object {
public:
  // Main functions
  Flashlight(Vector3f location, Vector3f orientation, Vector3f scale,
             Vector3f dimensions); // Constructor
  ~Flashlight();                   // Destructor

  bool isOn();
  void turnOn();
  void turnOff();

  void draw(float yAngle);
  void setModel();

protected:
  bool on_ = false;
};

#endif