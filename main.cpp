// Defines
#define PI 3.14159265358979323846
// Libraries, dependencies and classes
#include "headerFiles/TextureBuilder.h"
#include "headerFiles/Model_3DS.h"
#include "headerFiles/GLTexture.h"
#include <math.h>
#include <windows.h>
#include <glut.h>
#include "headerFiles/Axes.h"
#include "headerFiles/Camera.h"
#include "headerFiles/Lights.h"

// Screen Constants
const int scale = 70;
const int width = 16 * scale;
const int height = 9 * scale;

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Setup light
	Lights::initLightSource();
	Lights::setupLights();
	// Set the camera

	//
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

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(width, height);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Game Title");

	glutDisplayFunc(display);

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