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
  void draw();
  void drawBoundries();
  void setModel();
};

#endif