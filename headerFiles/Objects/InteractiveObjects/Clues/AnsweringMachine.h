#ifndef AnsweringMachine_H
#define AnsweringMachine_H

#include "headerFiles/Objects/InteractiveObjects/Clues/Clue.h"
#include <Eigen/Dense>

using namespace Eigen;

class AnsweringMachine : public Clue {
public:
  // Main functions
  AnsweringMachine(Vector3f location, Vector3f orientation,
                   Vector3f scale); // Constructor
  ~AnsweringMachine();              // Destructor
  void draw();
  void setModel();
};

#endif