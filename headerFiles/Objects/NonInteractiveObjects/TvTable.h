#ifndef TVTABLE_H
#define TVTABLE_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>

using namespace Eigen;

class TvTable : public NonInteractiveObject {
public:
  // Main functions
  TvTable(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~TvTable();                   // Destructor
  void virtual draw();
  void virtual drawBoundries();
  void virtual setModel(char *modelPath = "");
};

#endif