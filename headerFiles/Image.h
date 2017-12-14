#ifndef IMAGE_H
#define IMAGE_H

#include <headerFiles/GL/glut.h>
#include "SOIL/src/SOIL.h"

void drawImage(float bottom, float top, float left, float right,GLuint texture);
void drawImageHorizontal(float bottom, float top, float left, float right,GLuint texture);

GLuint loadImage(char* path);
#endif