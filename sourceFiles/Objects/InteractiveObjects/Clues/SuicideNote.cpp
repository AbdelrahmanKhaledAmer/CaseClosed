#include "headerFiles/Objects/InteractiveObjects/Clues/SuicideNote.h"

SuicideNote::SuicideNote(Vector3f location, Vector3f orientation,
                           Vector3f scale, Vector3f dimensions)
    : Clue(location, orientation, scale, dimensions) {}

SuicideNote::~SuicideNote() {}

void SuicideNote::setModel() {
  this->image_ = loadImage("assets/images/Clues/suicide_note.png");
}

void SuicideNote::draw() {
  float minX = -dimensions_.x();
  float maxX = dimensions_.x();
  float minY = -dimensions_.z();
  float maxY = dimensions_.z();

  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(scale_.x(), scale_.y(), scale_.z());
    drawImageHorizontal(minX, maxX, minY, maxY, this->image_);
  }
  glPopMatrix();
}

std::string SuicideNote::Interact()
{
  return "7";
}