#ifndef KNIFE_H
#define KNIFE_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>

using namespace Eigen;

class Knife : public Clue {
public:
  // Main functions
  Knife(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Knife();                                                       // Destructor

  std::string Interact();
  void draw();
  void setModel();
};

#endif