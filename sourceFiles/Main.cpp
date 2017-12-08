// Defines
#define PI 3.14159265358979323846
// Libraries, dependencies and classes
#include "headerFiles/TextureBuilder.h"
#include "headerFiles/Model_3DS.h"
#include "headerFiles/GLTexture.h"
#include <math.h>
#include <iostream>
#include <Eigen/Dense>
#include <headerFiles/GL/glut.h>
#include "headerFiles/Axes.h"
#include "headerFiles/Camera.h"
#include "headerFiles/Lights.h"
#include "headerFiles/Objects/Object.h"
#include "headerFiles/Objects/InteractiveObjects/Door.h"
#include "headerFiles/Objects/NonInteractiveObjects/DiningSet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sofa.h"
#include "headerFiles/Objects/NonInteractiveObjects/Toilet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Kitchen.h"
#include "headerFiles/Objects/NonInteractiveObjects/Tv.h"
#include "headerFiles/Objects/NonInteractiveObjects/CoffeeTable.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sink.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bed.h"
#include "headerFiles/Objects/NonInteractiveObjects/Wardrobe.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bookcase.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Knife.h"
#include "headerFiles/Loader.h"

// Screen Constants
const int scale = 70;
const int width = 16 * scale;
const int height = 9 * scale;

Eigen::Vector3f eye(1,0.2,1);
Eigen::Vector3f lookAt(0,0,0);
Eigen::Vector3f orientation(0,1,0);

Camera camera(eye, lookAt, orientation);

Eigen::Vector3f doorLocation(0,0,0);
Eigen::Vector3f doorOrientation(0,0,0);
Eigen::Vector3f doorScale(1,1,1);
Eigen::Vector3f doorDimensions(1,1,1);

Door toilet(doorLocation, doorOrientation, doorScale, doorDimensions);

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Setup light
	Lights::initLightSource();
	Lights::setupLights();
	// Set the camera
	camera.setup();

	// Axes for modeling 
	Axes axes(0.5);

	// Reset color and flush buffer
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	// glScaled(0.15, 0.15, 0.15);
	// glScaled(0.0003, 0.0003, 0.0003);
	glScaled(0.001, 0.001, 0.001);
	//glRotatef(90.f, 1, 0, 0);
	toilet.draw();
	glPopMatrix();

	glFlush();

	glutSwapBuffers();
}

void LoadAssets()
{
	loadDoorModel(toilet);
	// Loading texture files
	// Starting music
}

void key(unsigned char k, int x, int y)
{
	switch(k)
	{
	case 'l':
		camera.rotateRight();
		break;
	case 'j':
		camera.rotateLeft();
		break;
	case 'i':
		camera.rotateUp();
		break;
	case 'k':
		camera.rotateDown();
		break;
	case 'o':
		camera.tiltRight();
		break;
	case 'u':
		camera.tiltLeft();
		break;
	case 'w':
		camera.translateForward();
		break;
	case 's':
		camera.translateBackward();
		break;
	case 'a':
		camera.translateLeft();
		break;
	case 'd':
		camera.translateRight();
		break;
	case 'e':
		camera.translateUp();
		break;
	case 'q':
		camera.translateDown();
		break;
	}
	glutPostRedisplay();
}

//=======================================================================
// Motion Function
const int height_center = height / 2, width_center = width / 2;
//=======================================================================
void mouseMovement(int x, int y)
{
	if(y > height_center)
			camera.rotateDown(0.4);
	if(y < height_center)
			camera.rotateUp(0.4);
	if(x > width_center)
			camera.rotateRight(0.4);
	if(x < width_center)
			camera.rotateLeft(0.4);

	y = height - y;

	//pins mouse in screen center
	if(abs(x - width / 2) > 1)
		glutWarpPointer(width / 2, y);
		 
	if(abs(y - height / 2) > 1)
          glutWarpPointer(width / 2, height / 2);
    glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(width, height);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Game Title");

	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutPassiveMotionFunc(mouseMovement);
	glutSetCursor(GLUT_CURSOR_NONE);

	glClearColor(1, 1, 1, 0);

	LoadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}