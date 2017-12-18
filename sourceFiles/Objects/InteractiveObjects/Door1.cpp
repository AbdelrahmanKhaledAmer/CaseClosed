#include "headerFiles\Objects\InteractiveObjects\Door1.h"

/*
Constructor for the Door1 object.
Returns a pointer for a Door1.

@param (location) The current location of the Door1 with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
Door1::Door1(Vector3f location, Vector3f orientation, Vector3f scale)
:InteractiveObject(location, orientation, scale, Vector3f(0.15, 1.7, 0.15))
{
  initialAngle_ = orientation_.y();
}

/**
Destructor for the Door1 object.
Deletes the pointer for the Door1 object.
*/
Door1::~Door1() {}

std::string Door1::Interact()
{
  return "Door:1";
}

void Door1::draw()
{
  locscale_ = 0.0235;
  glPushMatrix();
  {
    if(initialAngle_ < 0.05 && initialAngle_ > -0.05)
    {
      glTranslatef((-0.7/2), -1, -dimensions_.z()/2);    
  
      glTranslatef(location_.x() / locscale_, location_.y() / locscale_, location_.z() / locscale_);
      glScalef(scale_.x(), scale_.y(), scale_.z());
      glRotatef(orientation_.y(), 0, 1, 0);
      glTranslatef((0.7/2)/ locscale_, 0, (dimensions_.z()/2)/ locscale_);
      model_.Draw();
    } else {
      glTranslatef(-dimensions_.z()/2, -1, 0.7/2);    
  
      glTranslatef(location_.x() / locscale_, location_.y() / locscale_, location_.z() / locscale_);
      glScalef(scale_.x(), scale_.y(), scale_.z());
      glRotatef(orientation_.y(), 0, 1, 0);
      glTranslatef((0.7/2)/ locscale_, 0, (dimensions_.z()/2)/ locscale_);
      model_.Draw();
    }
  }
  glPopMatrix();
}

void Door1::drawBoundries() { __super::drawBoundries(0.15, 1.7, 0.15); }

void Door1::setModel(char *modelPath) {
  __super::setModel("assets/models/furniture/Door1/Door ROMAGNOLI Senso Fly N040717.3DS");
}

void Door1::openDoor(float scale) 
{
  if(orientation_.y() > initialAngle_ - 90 && !isOpen_)
  {
    orientation_.y() -= 1;
  } else {
    isOpen_ = true;
  }
}

void Door1::closeDoor(float scale)
{
  if(orientation_.y() < initialAngle_ && isOpen_)
  {
    orientation_.y() += 1;
  } else {
    isOpen_ = false;
  }
}

bool Door1::isOpen()
{
  return this->isOpen_;
}