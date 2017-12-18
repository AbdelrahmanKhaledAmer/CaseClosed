#ifndef SINK_H
#define SINK_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>


using namespace Eigen;

class Sink : public NonInteractiveObject {
public:
  // Main functions
  Sink(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~Sink();                   // Destructor
  void virtual draw();
  void virtual drawBoundries();   // Draw Object Boundries
	void virtual setModel(char *modelPath = "");
};

#endif