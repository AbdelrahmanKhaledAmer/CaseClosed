#include "headerFiles/Objects/NonInteractiveObjects/Window.h"

/*
Constructor for the Window object.
Returns a pointer for a Window.

@param (location) The current location of the Window with respect to the
global origin.
@param (orientation) The current rotation angles across all three axes.
@param (scale) The amount to scale across all three axes.
@param (dimensions) The length of the object along every axis before scaling.

@return: Pointer to InteractiveObject interactiveObject
*/

Window::Window(Vector3f location, Vector3f orientation, Vector3f scale)
    : NonInteractiveObject(location, orientation, scale,
                           Vector3f(0, 0, 0)) {}

/**
Destructor for the Window object.
Deletes the pointer for the Window object.
*/
Window::~Window() {}

void drawSprite(GLint left, GLint right, GLint bottom, GLint top, GLuint texture){  
    glColor3f(1.0, 0, 0);
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2i(1,1); glVertex2i(right , top);
    glTexCoord2i(1,0); glVertex2i(right , bottom);
    glTexCoord2i(0,0); glVertex2i(left , bottom);
    glTexCoord2i(0,1); glVertex2i(left , top);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0, 1.0, 1.0);
}


void Window::draw() {
  locscale_ = 0.0005;

  glPushMatrix();
  {

    __super::draw();
  }
  glPopMatrix();
}

void Window::setModel(char *modelPath)  {
  __super::setModel("assets/models/furniture/Window/Window.3DS");
}