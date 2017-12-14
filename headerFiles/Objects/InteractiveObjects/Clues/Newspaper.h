#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include "headerFiles/Image.h"
#include <Eigen/Dense>

using namespace Eigen;

class Newspaper : public Clue {
public:
  // Main functions
  Newspaper(Vector3f location, Vector3f orientation, Vector3f scale,
               Vector3f dimensions); // Constructor
  ~Newspaper();                   // Destructor
  void draw();
  void setModel();

private:
  GLuint image_;
};

#endif