#ifndef OUTSIDEIMAGE_H
#define OUTSIDEIMAGE_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include "headerFiles/Image.h"
#include <Eigen/Dense>

using namespace Eigen;

class OutsideImage : public NonInteractiveObject {
public:
  // Main functions
  OutsideImage(Vector3f location, Vector3f orientation, Vector3f scale,
               Vector3f dimensions); // Constructor
  ~OutsideImage();                   // Destructor
  void virtual draw();
  void virtual setModel(char *imagePath);

protected:
  GLuint image_;
};

#endif