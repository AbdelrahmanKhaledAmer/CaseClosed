#ifndef WALL_H
#define WALL_H

#include "headerFiles/Objects/NonInteractiveObjects/NonInteractiveObject.h"
#include <Eigen/Dense>
#include "SOIL/src/SOIL.h"

using namespace Eigen;

class Wall : public NonInteractiveObject {
public:
  // Main functions
  Wall(Vector3f location, Vector3f orientation, Vector3f scale,
       Vector3f dimensions); // Constructor
  ~Wall();                   // Destructor

  // Game Logic Functions
  void draw();
  bool intersects(Object object);
  void setTexture(char *texturePath);

private:
  GLuint texture_;
};

#endif