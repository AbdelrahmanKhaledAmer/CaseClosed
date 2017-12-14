#include "headerFiles\Objects\InteractiveObjects\Clues\AnsweringMachine.h"

/*
Constructor for the AnsweringMachine object.
Returns a pointer for a AnsweringMachine.

@param (location) The current location of the AnsweringMachine with respect to
the global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
AnsweringMachine::AnsweringMachine(Vector3f location, Vector3f orientation,
                                   Vector3f scale)
    : Clue(location, orientation, scale, Vector3f(0, 0, 0)) {}

/**
Destructor for the AnsweringMachine object.
Deletes the pointer for the AnsweringMachine object.
*/
AnsweringMachine::~AnsweringMachine() {}

void AnsweringMachine::draw() {
  float scale = 0.05;

  glPushMatrix();
  {
    glScalef(scale, scale, scale);
    __super::draw(scale);
  }
  glPopMatrix();
}

void AnsweringMachine::setModel() {
  __super::setModel("assets/models/clues/Answering Machine/Phone siemens gigaset ap185 N220417.3DS");
}

std::string AnsweringMachine::Interact()
{
  return "5";
}