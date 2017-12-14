#ifndef YELLOW_HOODIE_H
#define YELLOW_HOODIE_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include "headerFiles/Image.h"
#include <Eigen/Dense>

using namespace Eigen;

class YellowHoodie : public Clue {
public:
  // Main functions
  YellowHoodie(Vector3f location, Vector3f orientation, Vector3f scale,
               Vector3f dimensions); // Constructor
  ~YellowHoodie();                   // Destructor
  void draw();
  void setModel();

private:
  GLuint image_;
};

#endif