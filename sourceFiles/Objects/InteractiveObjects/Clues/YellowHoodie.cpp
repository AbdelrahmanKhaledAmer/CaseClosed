#include "headerFiles/Objects/InteractiveObjects/Clues/YellowHoodie.h"

YellowHoodie::YellowHoodie(Vector3f location, Vector3f orientation,
                           Vector3f scale, Vector3f dimensions)
    : Clue(location, orientation, scale, dimensions) {}

YellowHoodie::~YellowHoodie() {}

void YellowHoodie::setModel(char *modelPath)  {
  this->image_ = loadImage("assets/images/Clues/yellow_hoodie.png");
}

void YellowHoodie::draw() {
  float minX = -dimensions_.x()/2;
  float maxX = dimensions_.x()/2;
  float minY = -dimensions_.z()/2;
  float maxY = dimensions_.z()/2;
  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(scale_.x(), scale_.y(), scale_.z());
    drawImageHorizontal(minX, maxX, minY, maxY, this->image_);
  }
  glPopMatrix();
}

std::string YellowHoodie::Interact()
{
  return "1";
}