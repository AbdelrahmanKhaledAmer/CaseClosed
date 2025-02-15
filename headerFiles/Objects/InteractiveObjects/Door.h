#ifndef DOOR_H
#define DOOR_H

#include <Eigen/Dense>
#include "headerFiles/Objects/InteractiveObjects/InteractiveObject.h"

using namespace Eigen;

class Door : public InteractiveObject
{
public:
  // Main functions
  Door(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Door();
  std::string Interact();
  void draw();
  void drawBoundries(); // Draw Object Boundries
  void setModel();
  void openDoor(float scale = 1);
  void closeDoor(float scale = 1);
  bool isOpen();
private:
  float initialAngle_;
  bool isOpen_ = false;
};

#endif