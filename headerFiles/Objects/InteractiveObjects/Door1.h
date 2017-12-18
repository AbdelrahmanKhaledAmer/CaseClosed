#ifndef DOOR1_H
#define DOOR1_H

#include <Eigen/Dense>
#include "headerFiles/Objects/InteractiveObjects/InteractiveObject.h"

using namespace Eigen;

class Door1 : public InteractiveObject
{
public:
  // Main functions
  Door1(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Door1();
  std::string Interact();
  void virtual draw();
  void virtual drawBoundries(); // Draw Object Boundries
  void virtual setModel(char *modelPath = ""); // Set Model
  void openDoor(float scale = 1);
  void closeDoor(float scale = 1);
  bool isOpen();
private:
  float initialAngle_;
  bool isOpen_ = false;
};

#endif