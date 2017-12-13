#include "headerFiles/Objects/InteractiveObjects/Clues/SuicideNote.h"

SuicideNote::SuicideNote(Vector3f location, Vector3f orientation,
                           Vector3f scale, Vector3f dimensions)
    : Clue(location, orientation, scale, dimensions) {}

SuicideNote::~SuicideNote() {}

void SuicideNote::setModel() {
  this->image_ = loadImage("assets/images/Clues/suicide_note.png");
}

void SuicideNote::draw() {
  float minX = location_.x();
  float maxX = location_.x() + dimensions_.x();
  float minY = location_.z();
  float maxY = location_.z() + dimensions_.z();

  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(scale_.x(), scale_.y(), scale_.z());
    drawImageHorizontal(minX, maxX, minY, maxY, this->image_);
  }
  glPopMatrix();
}