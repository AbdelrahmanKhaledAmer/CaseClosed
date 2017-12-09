#ifndef BOOKCASE_H
#define BOOKCASE_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class Bookcase : public NonInteractiveObject {
public:
  // Main functions
  Bookcase(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Bookcase();                   // Destructor
  void Bookcase::draw();
};

#endif