#include "headerFiles\Objects\InteractiveObjects\Clues\ClueImage.h"

/*
Constructor for the ClueImage object.
Returns a pointer for a ClueImage.

@param (location) The current location of the Body with respect to the global
origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.


@return: Pointer to InteractiveObject interactiveObject
*/
ClueImage::ClueImage(Vector3f location, Vector3f orientation,
                         Vector3f scale, Vector3f dimensions)
    : Clue(location, orientation, scale, dimensions) {}

/**
Destructor for the ClueImage object.
Deletes the pointer for the ClueImage object.
*/
ClueImage::~ClueImage() {}

void ClueImage::setModel(char* imagePath) { 
  image_ = SOIL_load_OGL_texture(
   	imagePath, 
    SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT |SOIL_FLAG_MULTIPLY_ALPHA
  );    
}

void ClueImage::draw() {
  glPushMatrix();
  {
    glTranslated(0, location_.y(), 0);
    glTranslated(0,  0.001, 0);
   
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
