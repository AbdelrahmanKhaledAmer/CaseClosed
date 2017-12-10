#ifndef CELLINGLIGHT_H
#define CELLINGLIGHT_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class CellingLight : public NonInteractiveObject {
public:
  // Main functions
  CellingLight(Vector3f location, Vector3f orientation, Vector3f scale,
               Vector3f dimensions); // Constructor
  ~CellingLight();                   // Destructor
};

#endif