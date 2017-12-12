// Defines ==========================================================
#define PI 3.14159265358979323846
#define PLAYING_STATE 			0
#define LOSING_STATE 			1
#define WINNING_STATE 			2
#define INTERACTING_STATE 		3
#define JOURNAL_STATE 			4

// Libraries, dependencies and classes ==============================
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
#include "headerFiles/Objects/Flashlight.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Bloodtrail.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Body.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/BrokenGlass.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Footprints.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Knife.h"
#include "headerFiles/Objects/InteractiveObjects/Door.h"
#include "headerFiles/Objects/InteractiveObjects/Door1.h"
#include "headerFiles/Objects/NonInteractiveObjects/Armchair.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bath.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bed.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bookcase.h"
#include "headerFiles/Objects/NonInteractiveObjects/CellingLight.h"
#include "headerFiles/Objects/NonInteractiveObjects/CoffeeTable.h"
#include "headerFiles/Objects/NonInteractiveObjects/DiningSet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Fan.h"
#include "headerFiles/Objects/NonInteractiveObjects/Kitchen.h"
#include "headerFiles/Objects/NonInteractiveObjects/Nightstand.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sink.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sofa.h"
#include "headerFiles/Objects/NonInteractiveObjects/Toilet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Tv.h"
#include "headerFiles/Objects/NonInteractiveObjects/TvTable.h"
#include "headerFiles/Objects/NonInteractiveObjects/Wall.h"
#include "headerFiles/Objects/NonInteractiveObjects/Wardrobe.h"
#include "headerFiles/Objects/Object.h"
#include "headerFiles/Objects/Player.h"

// Screen Constants =================================================
const int scale = 70;
const int width = 16 * scale;
const int height = 9 * scale;

// Game variables ===================================================
int gameState = PLAYING_STATE;
InteractiveObject interactingObject(Vector3f(0, 0, 0), Vector3f(0, 0, 0), Vector3f(0, 0, 0), Vector3f(0, 0, 0));

Eigen::Vector3f eye(13, 1, 2);
Eigen::Vector3f lookAt(15, 0.5, 2);
Eigen::Vector3f orientation(0, 1, 0);

Camera camera(eye, lookAt, orientation);
Player player(eye, Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0.5, 1.5, 0.2), camera);
//Knife knife(Vector3f(3, 0.5, 1), Vector3f(45, 45, 45), Vector3f(1, 1, 1), Vector3f(1, 1, 1));
Clue* clues[3];
//Same texture for each group?
//Groups are Separated by an empty line.
Wall* walls[24];
//Wall* wall0;	// South wall of corridor
//Wall* wall1;	// West wall of corridor
//Wall* wall2;	// North wall of corridor
//Wall* wall3;	// East wall of corridor part 1
//Wall* wall4;	// East wall of corridor part 2
//limits for corridor are east and west limits for total frame are
//
//Wall* wall5;	// West wall of kitchen
//Wall* wall6;	// South wall of kitchen
//
//Wall* wall7;	// North wall of reception area
//Wall* wall8;	// West wall of reception area part 1
//Wall* wall9;	// West wall of reception area part 2
//Wall* wall10;	// South wall of reception area
//Wall* wall11;	// East wall of reception area part 1
//Wall* wall12; // East wall of reception area part 2
//
//Wall* wall13;	// North wall of bedroom part 1
//Wall* wall14;	// North wall of bedroom part 2
//Wall* wall15;	// West wall of bedroom part 1
//Wall* wall16;	// West wall of bedroom part 2
//Wall* wall17;	// South wall of bedroom
//Wall* wall18;	// East wall of bedroom
//
//Wall* wall19;	// North wall of bathroom
//Wall* wall20;	// West wall of bathroom
//Wall* wall21;	// South wall of bathroom part 1
//Wall* wall22;	// South wall of bathroom part 2
//Wall* wall23;	// East wall of bathroom

// Appartment Layout ================================================
Door door(Vector3f(24.5, 0, 4.5), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Door1 door1(Vector3f(24, 0, 5), Vector3f(0, 90, 0), Vector3f(1, 1, 1));

//livingroom
Armchair armchair(Vector3f(22.8, 0, 10.2), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
Sofa sofa(Vector3f(24.5, 0, 9), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
CoffeeTable coffeeTable(Vector3f(23.7, 0, 10.6), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
Tv tv(Vector3f(24.5, 0, 11.5), Vector3f(0, -115+180, 0), Vector3f(1, 1, 1));
TvTable tvTable(Vector3f(24.5, 0, 11.5), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Bookcase bookcase(Vector3f(25.7, 0, 7), Vector3f(0, 180, 0), Vector3f(1, 1, 1));

//kitchen
DiningSet diningSet(Vector3f(22.2, 0, 7), Vector3f(0, -90, 0), Vector3f(1, 1, 1));
Kitchen kitchen(Vector3f(21.15, 0, 5.5), Vector3f(0, 270, 0), Vector3f(1, 1, 1));

//Bedroom
Bed bed(Vector3f(23, 0, 14.9), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Nightstand nightstand1(Vector3f(24.17, 0, 16.2), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Nightstand nightstand2(Vector3f(21.27, 0, 16.2), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Wardrobe wardrobe(Vector3f(19.85, 0, 12.6), Vector3f(0, 0, 0), Vector3f(1, 1, 1));

//Bathroom
Toilet toilet(Vector3f(25.9, 0, 15), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
Sink sink(Vector3f(27.2, 0, 12.3), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
Bath bath(Vector3f(28, 0, 14.9), Vector3f(0, 0, 0), Vector3f(1, 1, 1));

//Clues
Body body(Vector3f(23, 0, 14.9), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
BrokenGlass brokenGlass(Vector3f(0, 0, 0), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(1, 1, 1));
Footprints footprints(Vector3f(0, 0, 0), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(1, 1, 1));
Bloodtrail bloodtrail(Vector3f(0, 0, 0), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(1, 1, 1));

void initClues() {

	
	int len = sizeof(clues) / sizeof(*clues);
	//TODO
	for (int i = 0; i < len; i++)
	{
		//clues[i]=


	}
	clues[0] = new Knife(Vector3f(4, 0.5, 1), Vector3f(45, 45, 45), Vector3f(1, 1, 1), Vector3f(1, 1, 1));
	clues[1] = new Knife(Vector3f(3, 0.5, 1), Vector3f(45, 45, 45), Vector3f(1, 1, 1), Vector3f(1, 1, 1));
	clues[2] = new Knife(Vector3f(2, 0.5, 1), Vector3f(45, 45, 45), Vector3f(1, 1, 1), Vector3f(1, 1, 1));
	// printf("%p",clues[0]);
}

void drawClues() {
	int len = sizeof(clues) / sizeof(*clues);
	bool win = true;
	for (int i = 0; i < len; i++)
	{
		if (!(*clues[i]).isFound())
		{
			if(i==0)
			glColor3f(0, 1, 0);
			if(i==1)
				glColor3f(0, 1,1);
			if(i==2)
				glColor3f(1,0,0);
			(*clues[i]).draw();
			win = false;
		}
	}
	if (win)
		gameState = WINNING_STATE;
}

void initEnvironment()
{
	Eigen::Vector3f dim(0.2, 2, 1);
	// Corridor
	Eigen::Vector3f loc0(12, 0, 1.63);	// (1.63, 12)
	Eigen::Vector3f ori0(0, 0, 0);		// along z
	Eigen::Vector3f scl0(1, 1, 3);		// length 3
	walls[0] = new Wall(loc0, ori0, scl0, dim);
	Eigen::Vector3f loc1(12, 0, 1.63);	// (1.63, 12)
	Eigen::Vector3f ori1(0, 90, 0);		// along x
	Eigen::Vector3f scl1(1, 1, 18);		// length 18
	walls[1] = new Wall(loc1, ori1, scl1, dim);
	Eigen::Vector3f loc2(30, 0, 1.63);	// (1.63, 30)
	Eigen::Vector3f ori2(0, 0, 0);		// along z
	Eigen::Vector3f scl2(1, 1, 3);		// length 3
	walls[2] = new Wall(loc2, ori2, scl2, dim);
	Eigen::Vector3f loc3(12, 0, 4.63);	// (4.63, 12)
	Eigen::Vector3f ori3(0, 90, 0);		// along x
	Eigen::Vector3f scl3(1, 1, 12);		// length 12 
	walls[3] = new Wall(loc3, ori3, scl3, dim);
	Eigen::Vector3f loc4(25, 0, 4.63);	// (4.63, 25)
	Eigen::Vector3f ori4(0, 90, 0);		// along x
	Eigen::Vector3f scl4(1, 1, 5);		// length 5
	walls[4] = new Wall(loc4, ori4, scl4, dim);

	// Kitchen
	Eigen::Vector3f loc5(19.5, 0, 4.64);	// (4.63, 19.5)
	Eigen::Vector3f ori5(0, 90, 0);			// along x
	Eigen::Vector3f scl5(1, 1, 3.5);		// length 3
	walls[5] = new Wall(loc5, ori5, scl5, dim);
	Eigen::Vector3f loc6(19.5, 0, 4.64);	// (4.63, 19.5)
	Eigen::Vector3f ori6(0, 0, 0);			// along z
	Eigen::Vector3f scl6(1, 1, 2.87);		// length 2.87
	walls[6] = new Wall(loc6, ori6, scl6, dim);

	// Reception
	Eigen::Vector3f loc7(26, 0, 4.64);		// (4.63, 26)
	Eigen::Vector3f ori7(0, 0, 0);			// along z
	Eigen::Vector3f scl7(1, 1, 7.37);		// length 7.37
	walls[7] = new Wall(loc7, ori7, scl7, dim);
	Eigen::Vector3f loc8(23, 0, 4.64); 		// (4.63, 23)
	Eigen::Vector3f ori8(0, 90, 0);			// along x
	Eigen::Vector3f scl8(1, 1, 1);			// length 1
	walls[8] = new Wall(loc8, ori8, scl8, dim);
	Eigen::Vector3f loc9(25, 0, 4.64);	 	// (4.63, 25)
	Eigen::Vector3f ori9(0, 90, 0);			// along x
	Eigen::Vector3f scl9(1, 1, 1);			// length 1
	walls[9] = new Wall(loc9, ori9, scl9, dim);
	Eigen::Vector3f loc10(19.5, 0, 7.5);	// (6.5, 19.5)
	Eigen::Vector3f ori10(0, 0, 0);			// along z
	Eigen::Vector3f scl10(1, 1, 4.5);		// length 4.5
	walls[10] = new Wall(loc10, ori10, scl10, dim);
	Eigen::Vector3f loc11(19.5, 0, 12);		// (12, 19.5)
	Eigen::Vector3f ori11(0, 90, 0);		// along x
	Eigen::Vector3f scl11(1, 1, 1.5);		// length 1.5
	walls[11] = new Wall(loc11, ori11, scl11, dim);
	Eigen::Vector3f loc12(22, 0, 12);		// (12, 22)
	Eigen::Vector3f ori12(0, 90, 0);		// along x
	Eigen::Vector3f scl12(1, 1, 3.5);		// length 3.5
	walls[12] = new Wall(loc12, ori12, scl12, dim);

	// Bedroom
	Eigen::Vector3f loc13(25.5, 0, 12.01);	// (12, 25.5)
	Eigen::Vector3f ori13(0, 0, 0);			// along z
	Eigen::Vector3f scl13(1, 1, 0.99);		// length 1
	walls[13] = new Wall(loc13, ori13, scl13, dim);
	Eigen::Vector3f loc14(25.5, 0, 14);	// (14, 25.5)
	Eigen::Vector3f ori14(0, 0, 0);			// along z
	Eigen::Vector3f scl14(1, 1, 2.5);		// length 2.5
	walls[14] = new Wall(loc14, ori14, scl14, dim);
	Eigen::Vector3f loc15(19.5, 0, 12.01);	// (12, 19.5)
	Eigen::Vector3f ori15(0, 90, 0);		// along x
	Eigen::Vector3f scl15(1, 1, 1.5);		// length 1.5
	walls[15] = new Wall(loc15, ori15, scl15, dim);
	Eigen::Vector3f loc16(22, 0, 12.01);	// (12, 22)
	Eigen::Vector3f ori16(0, 90, 0);		// along x
	Eigen::Vector3f scl16(1, 1, 3.5);		// length 3.5
	walls[16] = new Wall(loc16, ori16, scl16, dim);
	Eigen::Vector3f loc17(19.5, 0, 12);		// (12, 19.5)
	Eigen::Vector3f ori17(0, 0, 0);			// along z
	Eigen::Vector3f scl17(1, 1, 4.5);		// length 4.5
	walls[17] = new Wall(loc17, ori17, scl17, dim);
	Eigen::Vector3f loc18(19.5, 0, 16.5);	// (16.5, 19.5)
	Eigen::Vector3f ori18(0, 90, 0);		// along x
	Eigen::Vector3f scl18(1, 1, 6);			// length 6
	walls[18] = new Wall(loc18, ori18, scl18, dim);

	// Bathroom
	Eigen::Vector3f loc19(28.5, 0, 12);		// (12, 28.5)
	Eigen::Vector3f ori19(0, 0, 0);			// along z
	Eigen::Vector3f scl19(1, 1, 4);			// length 4
	walls[19] = new Wall(loc19, ori19, scl19, dim);
	Eigen::Vector3f loc20(25.5, 0, 12.01);	// (12, 25.5)
	Eigen::Vector3f ori20(0, 90, 0);		// along x
	Eigen::Vector3f scl20(1, 1, 3);			// length 3
	walls[20] = new Wall(loc20, ori20, scl20, dim);
	Eigen::Vector3f loc21(25.51, 0, 12.01);	// (12, 25.5)
	Eigen::Vector3f ori21(0, 0, 0);			// along z
	Eigen::Vector3f scl21(1, 1, 0.99);		// length 1
	walls[21] = new Wall(loc21, ori21, scl21, dim);
	Eigen::Vector3f loc22(25.51, 0, 14.01);	// (14, 25.5)
	Eigen::Vector3f ori22(0, 0, 0);			// along z
	Eigen::Vector3f scl22(1, 1, 2);			// length 2
	walls[22] = new Wall(loc22, ori22, scl22, dim);
	Eigen::Vector3f loc23(25.51, 0, 16);	// (16, 25.5)
	Eigen::Vector3f ori23(0, 90, 0);		// along x
	Eigen::Vector3f scl23(1, 1, 3);			// length 3
	walls[23] = new Wall(loc23, ori23, scl23, dim);
}

void drawEnvironment()
{
	for (int i = 0; i < sizeof(walls) / sizeof(*walls); i++)
	{
		(*walls[i]).draw();
	}

	GLuint floorTexture = SOIL_load_OGL_texture(
		"assets/images/floor.jpg", 
		SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT |SOIL_FLAG_MULTIPLY_ALPHA
	);

    glColor4ub(255, 255, 255, 255);
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, floorTexture);
	glBegin(GL_QUADS);
	{
		glNormal3f(0, 1, 0);
		glVertex3f(-1, 0, -1);	glTexCoord2f(1, 1);
		glVertex3f(-1, 0, 31);	glTexCoord2f(1, 0);
		glVertex3f(31, 0, 31);	glTexCoord2f(0, 0);
		glVertex3f(31, 0, -1);	glTexCoord2f(0, 1);
	}
	glEnd();
    glDisable(GL_TEXTURE_2D);

	GLuint roofTexture = SOIL_load_OGL_texture(
		"assets/images/celling.jpg", 
		SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT |SOIL_FLAG_MULTIPLY_ALPHA
	);

    glColor4ub(255, 255, 255, 255);
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, roofTexture);
	glBegin(GL_QUADS);
	{
		glNormal3f(0, -1, 0);
		glVertex3f(-1, 2, -1);	glTexCoord2f(1, 1);
		glVertex3f(-1, 2, 31);	glTexCoord2f(1, 0);
		glVertex3f(31, 2, 31);	glTexCoord2f(0, 0);
		glVertex3f(31, 2, -1);	glTexCoord2f(0, 1);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

bool intersectsWalls()
{
	bool intersects = false;
	for (int i = 0; i < sizeof(walls) / sizeof(*walls); i++)
	{
		intersects |= (*walls[i]).intersects(player);
	}

	// intersects |= door.intersects(player);    
	// intersects |= door1.intersects(player);    
	intersects |= armchair.intersects(player);    
	intersects |= sofa.intersects(player);    
	intersects |= coffeeTable.intersects(player);
	intersects |= tv.intersects(player);
	intersects |= bookcase.intersects(player);
	intersects |= diningSet.intersects(player);
	intersects |= kitchen.intersects(player);
	intersects |= bed.intersects(player);
	intersects |= nightstand1.intersects(player);
	intersects |= nightstand2.intersects(player);
	intersects |= wardrobe.intersects(player);
	intersects |= toilet.intersects(player);
	intersects |= sink.intersects(player);
	intersects |= bath.intersects(player);

	return intersects;
}

void initFlashLight() {




	//GLfloat lmodel_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	//
	Vector3f viewVec=(player.getCamera().lookAt() - player.location()).normalized();
	
	//Vector3f upVector = player.getCamera().Upvector();
	//Vector3f eye = player.getCamera().location().normalized();
	//Vector3f ViewCross = viewVec.cross(upVector).normalized();
	GLfloat l1Diffuse[] = { 1.0f,1.0f, 1.0f, 1.0f };
	GLfloat l1Ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat l1Position[] = { player.location().x(), player.location().y(),player.location().z(), true };
	//GLfloat l1Position[] = {eye.x(),eye.y(),eye.z()};
	Vector3f dir = viewVec;
	GLfloat l1Direction[] = {dir.x(),dir.y(),dir.z()};
	GLfloat lightIntensity[] = { 1.3, 1.3, 1.3, 1.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l1Diffuse);
	glLightfv(GL_LIGHT1, GL_AMBIENT, l1Ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, l1Position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 90.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l1Direction);

	glLightfv(GL_LIGHT1, GL_AMBIENT, lightIntensity);


}

void drawHitBoxes(){
  door.drawBoundries();
  door1.drawBoundries();
  armchair.drawBoundries();
  sofa.drawBoundries();
  coffeeTable.drawBoundries();
  tv.drawBoundries();
  tvTable.drawBoundries();
  bookcase.drawBoundries();
  kitchen.drawBoundries();
  diningSet.drawBoundries();
  bed.drawBoundries();
  nightstand1.drawBoundries();
  nightstand2.drawBoundries();
  wardrobe.drawBoundries();
  toilet.drawBoundries();
  sink.drawBoundries();
  bath.drawBoundries();
}

void drawApartment() {
    drawEnvironment();
	door.draw();
	// door1.draw();

    // livingroom
    armchair.draw();
    sofa.draw();
    coffeeTable.draw();
    tv.draw();
    tvTable.draw();
    bookcase.draw();

    // kitchen
    kitchen.draw();
    diningSet.draw();

    // bedroom
    body.draw();
    bed.draw();
    nightstand1.draw();
    nightstand2.draw();
    wardrobe.draw();

    // Toilet
    toilet.draw();
    sink.draw();
    bath.draw();

    // clues
    body.draw();
    // brokenGlass.draw();
    // footprints.draw();
    bloodtrail.draw();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Setup light
  Lights::initLightSource();
  Lights::setupLights();

  // Set the camera
  initFlashLight();
  player.getCamera().setup();
  //	camera.setup();

  // Axes for modeling
  Axes axes(0.5);

  glColor3f(0.8f, 0.1f, 0.2f);
  if (gameState == PLAYING_STATE) {
    drawClues();
  } else if (gameState == INTERACTING_STATE) {
    interactingObject.rotate();
    interactingObject.draw();
  }

  // Reset color and flush buffer
  glColor3f(1.0, 1.0, 1.0);

  glPushMatrix();
  {
    drawApartment();
    // drawHitBoxes();
  }
  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void loadAssets()
{
	door.setModel();
	door1.setModel();
	
	armchair.setModel();
	sofa.setModel();
	coffeeTable.setModel();
	tv.setModel();
	tvTable.setModel();
	bookcase.setModel();

	kitchen.setModel();
	diningSet.setModel();

	bed.setModel();
	nightstand1.setModel();
	nightstand2.setModel();
	wardrobe.setModel();

	toilet.setModel();
	sink.setModel();
	bath.setModel();
	
	body.setModel();
	brokenGlass.setImage();
	footprints.setImage();
	bloodtrail.setImage();

	for (int i = 0; i < sizeof(walls) / sizeof(*walls); i++) {
		(*walls[i]).setTexture("assets/images/paint_wall.jpg");
	}

	(*walls[0]).setTexture("assets/images/corridor_wall.jpg");
	(*walls[1]).setTexture("assets/images/corridor_wall.jpg");
	(*walls[2]).setTexture("assets/images/corridor_wall.jpg");
	(*walls[3]).setTexture("assets/images/corridor_wall.jpg");
	(*walls[4]).setTexture("assets/images/corridor_wall.jpg");
	// Starting music
}

void interactionTimer(int val)
{
	if(gameState == INTERACTING_STATE)
	{
		interactingObject.rotate();
		glutPostRedisplay();
		glutTimerFunc(20, interactionTimer, 0);
	}
}

void key(unsigned char k, int x, int y)
{
	int len = sizeof(clues) / sizeof(*clues);
	if(gameState == PLAYING_STATE)
	{
		switch (k)
		{
		case 'l':
			//camera.rotateRight();
			player.lookRight();
			break;
		case 'j':
			
			break;
		case 'i':
			//camera.rotateUp();
			player.lookUp();
			break;
		case 'k':
			//camera.rotateDown();
			player.lookDown();
			break;
		case 'o':
			camera.tiltRight();
			break;
		case 'u':
			camera.tiltLeft();
			break;
		case 'w':
			//camera.translateForward();
			player.moveForward();
			if (intersectsWalls()) {
				player.moveBackward();
			}
			break;
		case 's':
			//camera.translateBackward();
			player.moveBackward();
			if (intersectsWalls()) {
				player.moveForward();
			}
			break;
		case 'a':
			//camera.translateLeft();
			player.moveLeft();
			if (intersectsWalls()) {
				player.moveRight();
			}
			break;
		case 'd':
			//camera.translateRight();
			player.moveRight();
			if (intersectsWalls()) {
				player.moveLeft();
			}
			break;
		case 'e':
			// camera.translateUp();
			
			for ( int i = 0;  i < len;  i++)
			{
				//printf("%d\n", clues[0]);
			  if(player.isLookingAt(*(clues[i]))&&!(*clues[i]).isFound())
				{
					std::string s = (*clues[i]).Interact().append("\n");
					interactingObject = *clues[i];
					gameState = INTERACTING_STATE;
					Vector3f newVector = player.getCamera().location() + (player.getCamera().lookAt() - player.getCamera().location()).normalized() * 0.8;
					interactingObject.setLocation(newVector);
					glutTimerFunc(20, interactionTimer, 0);
					//remove clue
					(*clues[i]).find(true);
					break;
				}
			 

			}
			break;
		case 'q':
			camera.translateDown();
			break;
		}
	} else if (gameState == INTERACTING_STATE) {
		switch(k)
		{
		case 'e':
			gameState = PLAYING_STATE;
			break;
		} 
	}else if (gameState == JOURNAL_STATE) {
		switch(k)
		{
			case 'j':
			gameState = PLAYING_STATE;
			break;
		}
	}
	glutPostRedisplay();
}

//=======================================================================
// Motion Function
const int height_center = height / 2, width_center = width / 2;
//=======================================================================
void mouseMovement(int x, int y)
{
	if(gameState == PLAYING_STATE)
	{
		if (y > height_center)
			//camera.rotateDown(0.4);
			player.lookDown(0.4);
		if (y < height_center)
			//camera.rotateUp(0.4);
			player.lookUp(0.4);
		if (x > width_center)
			//camera.rotateRight(0.4);
			player.lookRight(0.4);
		if (x < width_center)
			//camera.rotateLeft(0.4);
			player.lookLeft(0.4);

		y = height - y;

		//pins mouse in screen center
		if (abs(x - width_center) > 1) {
			x = width_center;
			glutWarpPointer(width_center, y);
		}

		if (abs(y - height_center) > 1)
			glutWarpPointer(x, height_center);
		glutPostRedisplay();
	}
}

void losingStateCaller(int val)
{

	if (gameState != WINNING_STATE) {
		gameState = LOSING_STATE;
		printf("koko lost\n");
	}
	glutPostRedisplay();
}

void journalStateCaller(int val)
{
	if(gameState != PLAYING_STATE){
		gameState = JOURNAL_STATE;
		printf("journal appear\n");
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
	glutPassiveMotionFunc(mouseMovement);
	glutSetCursor(GLUT_CURSOR_NONE);

	glClearColor(1, 1, 1, 0);

	initEnvironment();
	initClues();
	loadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT2);
	glEnable(GL_NORMALIZE);
	//glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);

	//TODO 10 mins
	// glutTimerFunc(10000, losingStateCaller, 0);

	glutMainLoop();
}