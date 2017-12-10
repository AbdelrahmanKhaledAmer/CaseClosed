#ifndef COFFEETABLE_H
#define COFFEETABLE_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class CoffeeTable : public NonInteractiveObject {
public:
  // Main functions
  CoffeeTable(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~CoffeeTable();                   // Destructor
  void draw();
  void drawBoundries();           // Draw Object Boundries
};

#endif