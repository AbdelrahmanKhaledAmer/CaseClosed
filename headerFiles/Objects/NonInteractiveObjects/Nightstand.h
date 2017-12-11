#ifndef NIGHTSTAND_H
#define NIGHTSTAND_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class Nightstand : public NonInteractiveObject {
public:
  // Main functions
  Nightstand(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Nightstand();                   // Destructor
  void draw();
  void drawBoundries();   // Draw Object Boundries
	void setModel();
};

#endif