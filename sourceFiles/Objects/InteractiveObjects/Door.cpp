#include "headerFiles\Objects\InteractiveObjects\Door.h"

/*
Constructor for the Door object.
Returns a pointer for a Door.

@param (location) The current location of the Door with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Door::Door(Vector3f location, Vector3f orientation, Vector3f scale)
:InteractiveObject(location, orientation, scale, Vector3f(0.85, 1.7, 0.15))
{
  initialAngle_ = orientation_.y();
}

/**
Destructor for the Door object.
Deletes the pointer for the Door object.
*/
Door::~Door() {}

std::string Door::Interact()
{
  return "Door:0";
}

void Door::draw()
{
  locscale_ = 0.009;
  glPushMatrix();
  {
    glTranslatef((-dimensions_.x()/2), -1, 0);    

    glTranslatef(location_.x() / locscale_, location_.y() / locscale_, location_.z() / locscale_);
    glScalef(scale_.x(), scale_.y(), scale_.z());
    glRotatef(orientation_.y(), 0, 1, 0);
    glTranslatef((-dimensions_.x()/2)/ locscale_, 0, (orientation_.z()/2)/ locscale_);
    model_.Draw();
  }
  glPopMatrix();
}

void Door::drawBoundries() { __super::drawBoundries(0.7, 1.7, 0.15); }

void Door::setModel(char *modelPath) {
  __super::setModel("assets/models/furniture/Door/Door Endless Boiserie Sliding Door Longhi N291216.3DS");
}

void Door::openDoor(float scale) 
{
  if(orientation_.y() > initialAngle_ - 90 && !isOpen_)
  {
    orientation_.y() -= 1;
  } else {
    isOpen_ = true;
  }
}

void Door::closeDoor(float scale)
{
  if(orientation_.y() < initialAngle_ && isOpen_)
  {
    orientation_.y() += 1;
  } else {
    isOpen_ = false;
  }
}

bool Door::isOpen()
{
  return this->isOpen_;
}