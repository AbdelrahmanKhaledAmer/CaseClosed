#ifndef CELLINGLIGHT1_H
#define CELLINGLIGHT1_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class CellingLight1 : public NonInteractiveObject {
public:
  // Main functions
  CellingLight1(Vector3f location, Vector3f orientation,
               Vector3f scale); // Constructor
  ~CellingLight1();              // Destructor
  void draw();
  void setModel();
};

#endif