#ifndef SUICIDE_NOTE_H
#define SUICIDE_NOTE_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include "headerFiles/Image.h"
#include <Eigen/Dense>

using namespace Eigen;

class SuicideNote : public Clue {
public:
  // Main functions
  SuicideNote(Vector3f location, Vector3f orientation, Vector3f scale,
               Vector3f dimensions); // Constructor
  ~SuicideNote();                   // Destructor
  void draw();
  void setModel();

private:
  GLuint image_;
};

#endif