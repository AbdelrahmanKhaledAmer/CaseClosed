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
#include "headerFiles/Object.h"

// Screen Constants
const int scale = 70;
const int width = 16 * scale;
const int height = 9 * scale;

Eigen::Vector3f eye(1,0.2,1);
Eigen::Vector3f lookAt(0,0,0);
Eigen::Vector3f orientation(0,1,0);

Camera camera(eye, lookAt, orientation);

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
	glFlush();

	glutSwapBuffers();
}

void LoadAssets()
{
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

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(width, height);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Game Title");

	glutDisplayFunc(display);
	glutKeyboardFunc(key);

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