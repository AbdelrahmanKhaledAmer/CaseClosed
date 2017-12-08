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
#include "headerFiles/Objects/NonInteractiveObjects/Wall.h"
#include "headerFiles/Loader.h"

// Screen Constants
const int scale = 70;
const int width = 16 * scale;
const int height = 9 * scale;

Eigen::Vector3f eye(1, 1, 1);
Eigen::Vector3f lookAt(3, 0.5, 1);
Eigen::Vector3f orientation(0, 1, 0);

Camera camera(eye, lookAt, orientation);
//Same texture for each group?
//Groups are Separated by an empty line.
Wall* wall0;	// South wall of corridor
Wall* wall1;	// West wall of corridor
Wall* wall2;	// North wall of corridor
Wall* wall3;	// East wall of corridor part 1
Wall* wall4;	// East wall of corridor part 2

Wall* wall5;	// North wall of kitchen
Wall* wall6;	// West wall of kitchen

Wall* wall7;	// West wall of reception area part 1
Wall* wall8;	// West wall of reception area part 2
Wall* wall9;	// South wall of reception area
Wall* wall10;	// East wall of reception area part 1
Wall* wall11;	// East wall of reception area part 2

Wall* wall12;	// North wall of bedroom part 1
Wall* wall13;	// North wall of bedroom part 2
Wall* wall14;	// West wall of bedroom part 1
Wall* wall15;	// West wall of bedroom part 2
Wall* wall16;	// South wall of bedroom
Wall* wall17;	// East wall of bedroom

Wall* wall18;	// North wall of bathroom
Wall* wall19;	// West wall of bathroom
Wall* wall20;	// South wall of bathroom part 1
Wall* wall21;	// South wall of bathroom part 2
Wall* wall22;	// East wall of bathroom

void initEnvironment()
{
	Eigen::Vector3f dim(0.1, 2, 1);

	Eigen::Vector3f loc0(0, 0, 0);
	Eigen::Vector3f ori0(0, 0, 0);
	Eigen::Vector3f scl0(1, 1, 3);
	wall0 = new Wall(loc0, ori0, scl0, dim);
	Eigen::Vector3f loc1(0, 0, 0);
	Eigen::Vector3f ori1(0, 90, 0);
	Eigen::Vector3f scl1(1, 1, 30);
	wall1 = new Wall(loc1, ori1, scl1, dim);
	Eigen::Vector3f loc2(30, 0, 0);
	Eigen::Vector3f ori2(0, 0, 0);
	Eigen::Vector3f scl2(1, 1, 3);
	wall2 = new Wall(loc2, ori2, scl2, dim);
	Eigen::Vector3f loc3(0, 0, 3);
	Eigen::Vector3f ori3(0, 90, 0);
	Eigen::Vector3f scl3(1, 1, 24);
	wall3 = new Wall(loc3, ori3, scl3, dim);
	Eigen::Vector3f loc4(24.75, 0, 3);
	Eigen::Vector3f ori4(0, 90, 0);
	Eigen::Vector3f scl4(1, 1, 5.25);
	wall4 = new Wall(loc4, ori4, scl4, dim);

	Eigen::Vector3f loc5(28.5, 0, 3);
	Eigen::Vector3f ori5(0, 0, 0);
	Eigen::Vector3f scl5(1, 1, 9);
	wall5 = new Wall(loc5, ori5, scl5, dim);
	Eigen::Vector3f loc6(25.5, 0, 3.01);
	Eigen::Vector3f ori6(0, 90, 0);
	Eigen::Vector3f scl6(1, 1, 3);
	wall6 = new Wall(loc6, ori6, scl6, dim);
	
	Eigen::Vector3f loc7(24.76, 0, 3.01);
	Eigen::Vector3f ori7(0, 90, 0);
	Eigen::Vector3f scl7(1, 1, 0.75);
	wall7 = new Wall(loc7, ori7, scl7, dim);
	Eigen::Vector3f loc8(16.5, 0, 3.01);
	Eigen::Vector3f ori8(0, 90, 0);
	Eigen::Vector3f scl8(1, 1, 7.49);
	wall8 = new Wall(loc8, ori8, scl8, dim);
	Eigen::Vector3f loc9(16.5, 0, 3.01);
	Eigen::Vector3f ori9(0, 0, 0);
	Eigen::Vector3f scl9(1, 1, 9);
	wall9 = new Wall(loc9, ori9, scl9, dim);
	Eigen::Vector3f loc10(16.5, 0, 12);
	Eigen::Vector3f ori10(0, 90, 0);
	Eigen::Vector3f scl10(1, 1, 1.5);
	wall10 = new Wall(loc10, ori10, scl10, dim);
	Eigen::Vector3f loc11(18.75, 0, 12);
	Eigen::Vector3f ori11(0, 90, 0);
	Eigen::Vector3f scl11(1, 1, 9.75);
	wall11 = new Wall(loc11, ori11, scl11, dim);

	Eigen::Vector3f loc12(24, 0, 12.01);
	Eigen::Vector3f ori12(0, 0, 0);
	Eigen::Vector3f scl12(1, 1, 0.99);
	wall12 = new Wall(loc12, ori12, scl12, dim);
	Eigen::Vector3f loc13(24, 0, 13.75);
	Eigen::Vector3f ori13(0, 0, 0);
	Eigen::Vector3f scl13(1, 1, 4.25);
	wall13 = new Wall(loc13, ori13, scl13, dim);
	Eigen::Vector3f loc14(16.5, 0, 12.01);
	Eigen::Vector3f ori14(0, 90, 0);
	Eigen::Vector3f scl14(1, 1, 1.5);
	wall14 = new Wall(loc14, ori14, scl14, dim);
	Eigen::Vector3f loc15(18.75, 0, 12.01);
	Eigen::Vector3f ori15(0, 90, 0);
	Eigen::Vector3f scl15(1, 1, 5.25);
	wall15 = new Wall(loc15, ori15, scl15, dim);
	Eigen::Vector3f loc16(16.5, 0, 12);
	Eigen::Vector3f ori16(0, 0, 0);
	Eigen::Vector3f scl16(1, 1, 6);
	wall16 = new Wall(loc16, ori16, scl16, dim);
	Eigen::Vector3f loc17(16.5, 0, 18);
	Eigen::Vector3f ori17(0, 90, 0);
	Eigen::Vector3f scl17(1, 1, 7.5);
	wall17 = new Wall(loc17, ori17, scl17, dim);
	
	Eigen::Vector3f loc18(28.5, 0, 12);
	Eigen::Vector3f ori18(0, 0, 0);
	Eigen::Vector3f scl18(1, 1, 6);
	wall18 = new Wall(loc18, ori18, scl18, dim);
	Eigen::Vector3f loc19(24, 0, 12.01);
	Eigen::Vector3f ori19(0, 90, 0);
	Eigen::Vector3f scl19(1, 1, 4.5);
	wall19 = new Wall(loc19, ori19, scl19, dim);
	Eigen::Vector3f loc20(24.01, 0, 12.01);
	Eigen::Vector3f ori20(0, 90, 0);
	Eigen::Vector3f scl20(1, 1, 0.99);
	wall20 = new Wall(loc20, ori20, scl20, dim);
	Eigen::Vector3f loc21(24.01, 0, 13.76);
	Eigen::Vector3f ori21(0, 0, 0);
	Eigen::Vector3f scl21(1, 1, 4.25);
	wall21 = new Wall(loc21, ori21, scl21, dim);
	Eigen::Vector3f loc22(24, 0, 18);
	Eigen::Vector3f ori22(0, 90, 0);
	Eigen::Vector3f scl22(1, 1, 4.5);
	wall22 = new Wall(loc22, ori22, scl22, dim);
}

void drawEnvironment()
{
	glColor3f(0.95f, 0.95f, 0.95f);
	(*wall0).draw();
	glColor3f(0.95f, 0.95f, 0.95f);
	(*wall1).draw();
	glColor3f(0.95f, 0.95f, 0.95f);
	(*wall2).draw();
	glColor3f(0.95f, 0.95f, 0.95f);
	(*wall3).draw();
	glColor3f(0.95f, 0.95f, 0.95f);
	(*wall4).draw();

	glColor3f(0.85f, 0.85f, 0.85f);
	(*wall5).draw();
	glColor3f(0.85f, 0.85f, 0.85f);
	(*wall6).draw();

	glColor3f(0.75f, 0.75f, 0.75f);
	(*wall7).draw();
	glColor3f(0.75f, 0.75f, 0.75f);
	(*wall8).draw();
	glColor3f(0.75f, 0.75f, 0.75f);
	(*wall9).draw();
	glColor3f(0.75f, 0.75f, 0.75f);
	(*wall10).draw();
	glColor3f(0.75f, 0.75f, 0.75f);
	(*wall11).draw();

	glColor3f(0.65f, 0.65f, 0.65f);
	(*wall12).draw();
	glColor3f(0.65f, 0.65f, 0.65f);
	(*wall13).draw();
	glColor3f(0.65f, 0.65f, 0.65f);
	(*wall14).draw();
	glColor3f(0.65f, 0.65f, 0.65f);
	(*wall15).draw();
	glColor3f(0.65f, 0.65f, 0.65f);
	(*wall16).draw();
	glColor3f(0.65f, 0.65f, 0.65f);
	(*wall17).draw();

	glColor3f(0.55f, 0.55f, 0.55f);
	(*wall18).draw();
	glColor3f(0.55f, 0.55f, 0.55f);
	(*wall19).draw();
	glColor3f(0.55f, 0.55f, 0.55f);
	(*wall20).draw();
	glColor3f(0.55f, 0.55f, 0.55f);
	(*wall21).draw();
	glColor3f(0.55f, 0.55f, 0.55f);
	(*wall22).draw();
}

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

	drawEnvironment();

	// Reset color and flush buffer
	glColor3f(1.0, 1.0, 1.0);
	glFlush();

	glutSwapBuffers();
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

	initEnvironment();
	loadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}