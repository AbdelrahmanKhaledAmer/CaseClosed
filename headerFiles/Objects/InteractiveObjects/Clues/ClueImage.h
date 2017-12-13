#ifndef CLUEIMAGE_H
#define CLUEIMAGE_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>
#include "SOIL/src/SOIL.h"

using namespace Eigen;

class ClueImage : public Clue {
public:
  // Main functions
  ClueImage(Vector3f location, Vector3f orientation, Vector3f scale,
              Vector3f dimensions); // Constructor
  ~ClueImage();                   // Destructor
  void draw();
  void setImage(char* imagePath);
protected:
  GLuint image_;
};

#endif