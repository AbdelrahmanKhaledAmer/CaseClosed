#include "headerFiles\Objects\InteractiveObjects\Clues\BrokenGlass.h"

/*
Constructor for the Body object.
Returns a pointer for a Body.

@param (location) The current location of the Body with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
BrokenGlass::BrokenGlass(Vector3f location, Vector3f orientation,
                         Vector3f scale, Vector3f dimensions)
    : Clue(location, orientation, scale, dimensions) {}

/**
Destructor for the Body object.
Deletes the pointer for the Body object.
*/
BrokenGlass::~BrokenGlass() {}

void BrokenGlass::setImage(GLuint image) { this->image_ = image; }

void BrokenGlass::draw() {
  glPushMatrix();
  {
    glTranslated(0, location_.y(), 0);
    glColor4ub(255, 255, 255, 255);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBindTexture(GL_TEXTURE_2D, image_);

    glBegin(GL_QUADS);
    glVertex3f(1, 0, 1); glTexCoord2f(location_.x() + dimensions_.x() , location_.z() + dimensions_.z());
    glVertex3f(1, 0, 0); glTexCoord2f(location_.x() + dimensions_.x() , location_.z());
    glVertex3f(0, 0, 0); glTexCoord2f(location_.x() , location_.z());
    glVertex3f(0, 0, 1); glTexCoord2f(location_.x() , location_.z() + dimensions_.z());
    glEnd();

    glDisable(GL_TEXTURE_2D);
  }
  glPopMatrix();
}
