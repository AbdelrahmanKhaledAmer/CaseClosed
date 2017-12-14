#include "headerFiles/Objects/InteractiveObjects/Clues/Newspaper.h"

Newspaper::Newspaper(Vector3f location, Vector3f orientation,
                           Vector3f scale, Vector3f dimensions)
    : Clue(location, orientation, scale, dimensions) {}

Newspaper::~Newspaper() {}

void Newspaper::setModel() {
  this->image_ = loadImage("assets/images/Clues/newspaper.png");
}

void Newspaper::draw() {
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