#ifndef WARDROBE_H
#define WARDROBE_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class Wardrobe : public NonInteractiveObject {
public:
  // Main functions
  Wardrobe(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Wardrobe();                   // Destructor
  void draw();
  void drawBoundries();   // Draw Object Boundries
	void setModel();
};

#endif