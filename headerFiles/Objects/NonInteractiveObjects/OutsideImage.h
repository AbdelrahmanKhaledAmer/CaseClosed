#ifndef OUTSIDEIMAGE_H
#define OUTSIDEIMAGE_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>
#include "SOIL/src/SOIL.h"

using namespace Eigen;

class OutsideImage : public NonInteractiveObject {
public:
  // Main functions
  OutsideImage(Vector3f location, Vector3f orientation, Vector3f scale); // Constructor
  ~OutsideImage();                   // Destructor
  void draw();
  void setImage(char* imagePath);
protected:
  GLuint image_;
};

#endif