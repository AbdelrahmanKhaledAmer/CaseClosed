#include "headerFiles/Image.h"

void drawImage(float bottom, float top, float left, float right,
               GLuint texture) {
  glColor4ub(255, 255, 255, 255);

  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glBindTexture(GL_TEXTURE_2D, texture);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 0); glVertex3f(left, bottom, 0);
  glTexCoord2f(0, 1); glVertex3f(left, top, 0);
  glTexCoord2f(1, 1); glVertex3f(right, top, 0);
  glTexCoord2f(1, 0); glVertex3f(right, bottom, 0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}