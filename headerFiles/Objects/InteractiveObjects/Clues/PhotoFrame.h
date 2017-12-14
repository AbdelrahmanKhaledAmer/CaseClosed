#ifndef PhotoFrame_H
#define PhotoFrame_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>

using namespace Eigen;

class PhotoFrame : public Clue {
public:
  // Main functions
  PhotoFrame(Vector3f location, Vector3f orientation,
             Vector3f scale); // Constructor
  ~PhotoFrame();              // Destructor
  void draw();
  void setModel();
  std::string Interact();
};

#endif