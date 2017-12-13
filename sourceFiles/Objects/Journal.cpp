#include "headerFiles\Objects\Journal.h"
#include <iostream>
using namespace std;
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
    : Object(location, orientation, scale, Vector3f(0.975, 0.9, 0.975)) {}

/**
Destructor for the Journal object.
Deletes the pointer for the Journal object.
*/
Journal::~Journal() {}

void Journal::write(int clueIndex) { clues_[clueIndex] = true; }

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
	if(clues_[0] == true){
		glTranslatef(0, 0, 0.001);
        drawImage(minX, maxX, minY, maxY, clueImages_[0]);
	}
  }
  glPopMatrix();
}

void Journal::setModel(){
	journalImage_ = SOIL_load_OGL_texture(
        "assets/images/Journal/journal.png",
		SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
    	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT |SOIL_FLAG_MULTIPLY_ALPHA
	);    

	clueImages_[0] = SOIL_load_OGL_texture(
        "assets/images/Journal/clue_1.png",
		SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
    	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT |SOIL_FLAG_MULTIPLY_ALPHA
	);    
}