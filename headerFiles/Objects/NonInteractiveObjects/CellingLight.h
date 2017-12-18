#ifndef CELLINGLIGHT_H
#define CELLINGLIGHT_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class CellingLight : public NonInteractiveObject {
public:
  // Main functions
  CellingLight(Vector3f location, Vector3f orientation,
               Vector3f scale); // Constructor
  ~CellingLight();              // Destructor
  void virtual draw();
  void virtual setModel(char *modelPath = "");
};

#endif