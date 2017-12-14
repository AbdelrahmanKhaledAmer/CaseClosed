#include "headerFiles\Objects\Journal.h"

/*
Constructor for the Journal object.
Returns a pointer for a Journal.

@param (location) The current location of the Journal with respect to the global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to Object Object
*/

Journal::Journal(Vector3f location, Vector3f orientation, Vector3f scale)
    : Object(location, orientation, scale, Vector3f(0, 0, 0)) {}

/**
Destructor for the Journal object.
Deletes the pointer for the Journal object.
*/
Journal::~Journal() {}

void Journal::write(int clueIndex, int property) {
  clues_[clueIndex] = true;
  cluesState_[clueIndex] = property;
}

void Journal::draw() {
	float minX = location_.x();
	float maxX = location_.x() + dimensions_.x();
	float minY = location_.y();
	float maxY = location_.y()+ dimensions_.y();

  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(scale_.x(), scale_.y(), scale_.z());

    drawImage(minX, maxX, minY, maxY, journalImage_);
    for (int i = 0; i < 10; i++) {
      if (clues_[i] == true) {
        glTranslatef(0, 0, (i+1) * 0.01);

        switch (cluesState_[i]) {
        case NOT_STATED:
          drawImage(minX, maxX, minY, maxY, clueImages_[i][0]);
          break;
        case RELEVANT:
          drawImage(minX, maxX, minY, maxY, clueImages_[i][1]);
          break;
        case IRRELEVANT:
          drawImage(minX, maxX, minY, maxY, clueImages_[i][2]);
          break;
        default:
        }
      }
    }
  }
  glPopMatrix();
}

void Journal::setModel(){
	journalImage_ = loadImage("assets/images/Journal/journal.png");
	clueImages_[0][0] = loadImage("assets/images/Journal/clue_0.png"); 
	clueImages_[0][1] = loadImage("assets/images/Journal/clueRelevant_0.png"); 
	clueImages_[0][2] = loadImage("assets/images/Journal/clueIrrelevant_0.png"); 
}