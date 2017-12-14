#include "headerFiles\Objects\Journal.h"

/*
Constructor for the Journal object.
Returns a pointer for a Journal.

@param (location) The current location of the Journal with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to Object Object
*/

Journal::Journal(Vector3f location, Vector3f orientation, Vector3f scale)
    : Object(location, orientation, scale, Vector3f(0.975, 0.9, 0.975)) {}

/**
Destructor for the Journal object.
Deletes the pointer for the Journal object.
*/
Journal::~Journal() {}

void Journal::write(int clueIndex, int property) {
  printf("write in jouurnal %d\n",clueIndex);
  clues_[clueIndex] = true;
  cluesState_[clueIndex] = property;
}

void Journal::draw() {
  float minX = location_.x();
  float maxX = location_.x() + dimensions_.x();
  float minY = location_.y();
  float maxY = location_.y() + dimensions_.y();

  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(scale_.x(), scale_.y(), scale_.z());

    drawImage(minX, maxX, minY, maxY, journalImage_);

    for (int i = 0; i < 10; i++) {
      if (clues_[i] == true) {
        glTranslatef(0, 0, (i + 1) * 0.01);
        //  printf("Drawing journal %d\n\n",i);
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
          break;
        }
      }
    }
  }
  glPopMatrix();
}

void Journal::setModel() {
  journalImage_ = loadImage("assets/images/Journal/journal.png");

  clueImages_[0][0] = loadImage("assets/images/Journal/clue_0.png");
  clueImages_[0][1] = loadImage("assets/images/Journal/clue_0_relevant.png");
  clueImages_[0][2] = loadImage("assets/images/Journal/clue_0_irrelevant.png");

  clueImages_[1][0] = loadImage("assets/images/Journal/clue_1.png");
  clueImages_[1][1] = loadImage("assets/images/Journal/clue_1_relevant.png");
  clueImages_[1][2] = loadImage("assets/images/Journal/clue_1_irrelevant.png");

  clueImages_[2][0] = loadImage("assets/images/Journal/clue_2.png");
  clueImages_[2][1] = loadImage("assets/images/Journal/clue_2_relevant.png");
  clueImages_[2][2] = loadImage("assets/images/Journal/clue_2_irrelevant.png");

  clueImages_[3][0] = loadImage("assets/images/Journal/clue_3.png");
  clueImages_[3][1] = loadImage("assets/images/Journal/clue_3_relevant.png");
  clueImages_[3][2] = loadImage("assets/images/Journal/clue_3_irrelevant.png");

  clueImages_[4][0] = loadImage("assets/images/Journal/clue_4.png");
  clueImages_[4][1] = loadImage("assets/images/Journal/clue_4_relevant.png");
  clueImages_[4][2] = loadImage("assets/images/Journal/clue_4_irrelevant.png");

  clueImages_[5][0] = loadImage("assets/images/Journal/clue_5.png");
  clueImages_[5][1] = loadImage("assets/images/Journal/clue_5_relevant.png");
  clueImages_[5][2] = loadImage("assets/images/Journal/clue_5_irrelevant.png");

  clueImages_[6][0] = loadImage("assets/images/Journal/clue_6.png");
  clueImages_[6][1] = loadImage("assets/images/Journal/clue_6_relevant.png");
  clueImages_[6][2] = loadImage("assets/images/Journal/clue_6_irrelevant.png");

  clueImages_[7][0] = loadImage("assets/images/Journal/clue_7.png");
  clueImages_[7][1] = loadImage("assets/images/Journal/clue_7_relevant.png");
  clueImages_[7][2] = loadImage("assets/images/Journal/clue_7_irrelevant.png");
}