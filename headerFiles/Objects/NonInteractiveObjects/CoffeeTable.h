#ifndef COFFEETABLE_H
#define COFFEETABLE_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class CoffeeTable : public NonInteractiveObject {
public:
  // Main functions
  CoffeeTable(Vector3f location, Vector3f orientation, Vector3f scale,
              Vector3f dimensions); // Constructor
  ~CoffeeTable();                   // Destructor
};

#endif