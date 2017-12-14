// Defines ==========================================================
#define PI 3.14159265358979323846
#define PLAYING_STATE 0
#define LOSING_STATE 1
#define WINNING_STATE 2
#define INTERACTING_STATE 3
#define JOURNAL_STATE 4

// Libraries, dependencies and classes ==============================
#include "headerFiles/TextureBuilder.h"

#include "headerFiles/GLTexture.h"
#include "headerFiles/Model_3DS.h"
#include <math.h>
#include <iostream>

#include <Eigen/Dense>
#include <headerFiles/GL/glut.h>

#include "headerFiles/Axes.h"
#include "headerFiles/Camera.h"
#include "headerFiles/Lights.h"
#include "headerFiles/Objects/Flashlight.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/AnsweringMachine.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Bloodtrail.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Body.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/BrokenGlass.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Footprints.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Knife.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Newspaper.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/PhotoFrame.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Pills.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/SuicideNote.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/YellowHoodie.h"
#include "headerFiles/Objects/InteractiveObjects/Door.h"
#include "headerFiles/Objects/InteractiveObjects/Door1.h"
#include "headerFiles/Objects/Journal.h"
#include "headerFiles/Objects/NonInteractiveObjects/Armchair.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bath.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bed.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bookcase.h"
#include "headerFiles/Objects/NonInteractiveObjects/CellingLight.h"
#include "headerFiles/Objects/NonInteractiveObjects/CellingLight1.h"
#include "headerFiles/Objects/NonInteractiveObjects/CoffeeTable.h"
#include "headerFiles/Objects/NonInteractiveObjects/DiningSet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Fan.h"
#include "headerFiles/Objects/NonInteractiveObjects/Kitchen.h"
#include "headerFiles/Objects/NonInteractiveObjects/Nightstand.h"
#include "headerFiles/Objects/NonInteractiveObjects/OutsideImage.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sink.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sofa.h"
#include "headerFiles/Objects/NonInteractiveObjects/Toilet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Tv.h"
#include "headerFiles/Objects/NonInteractiveObjects/TvTable.h"
#include "headerFiles/Objects/NonInteractiveObjects/Wall.h"
#include "headerFiles/Objects/NonInteractiveObjects/Wardrobe.h"
#include "headerFiles/Objects/NonInteractiveObjects/Window.h"
#include "headerFiles/Objects/Object.h"
#include "headerFiles/Objects/Player.h"

// Screen Constants =================================================
const int scale = 70;
const int width = 16 * scale;
const int height = 9 * scale;

// Textures ==========================================================
// int floorTexWidth;
// int floorTexHeight;
// unsigned char *floorTex;
// int ceilingTexWidth;
// int ceilingTexHeight;
// unsigned char *ceilingTex;
GLuint floorTex, ceilingTex;

//flashLight ON/OFF
bool enableFlashLight = true;

// Game variables ===================================================
int gameState = PLAYING_STATE;
int interactingObject;

// Eigen::Vector3f eye(-2, 1, 1.2);
Eigen::Vector3f eye(13, 1, 2);
Eigen::Vector3f lookAt(15, 0.5, 2);
Eigen::Vector3f orientation(0, 1, 0);

Camera camera(eye, lookAt, orientation);
Player player(eye, Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0.5, 1.5, 0.2), camera);
Flashlight flashlight(Vector3f(0, 0, 0), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0, 0, 0));
Journal journal(Vector3f(0, 0, 0), Vector3f(0, 0, 0), Vector3f(2, 2, 1)); //x:1.95, z:2.53
//Knife knife(Vector3f(3, 0.5, 1), Vector3f(45, 45, 45), Vector3f(1, 1, 1), Vector3f(1, 1, 1));

Eigen::Vector3f eye2(1.8, 1.1, 2.45);
Eigen::Vector3f lookAt2(1.8, 1.525, 0);
Eigen::Vector3f orientation2(0, 1, 0);
Camera jCam(eye2, lookAt2, orientation2);

int cluesAnswer[8] = {RELEVANT, RELEVANT, IRRELEVANT, RELEVANT, IRRELEVANT, RELEVANT, RELEVANT, IRRELEVANT};
Clue *clues[8];
Wall *walls[24];

// Appartment Layout ================================================
Door apartmentDoor(Vector3f(24.5, 1, 4.5), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Door1 bedroomDoor(Vector3f(21.5, 1, 11.9), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
Door1 bathroomDoor(Vector3f(25.6, 1, 13.5), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
Window window(Vector3f(0, 0, 0), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
CellingLight livingroomLight(Vector3f(24.4, 2.25, 10.38), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
CellingLight kitchenLight(Vector3f(22.04, 2.25, 6.89), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
CellingLight1 bathroomLight(Vector3f(26.68, 2.25, 13.3), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
Fan bedroomFan(Vector3f(22.79, 2.5, 14.57), Vector3f(0, 0, 0), Vector3f(1, 1, 1));

Window bedroomWindow(Vector3f(19.7, 0.75, 14.6), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
OutsideImage bedroomOutsideImage(Vector3f(19.7 + 0.001, 1.12, 14.6), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0.37, 0.20, 0.30));
Window livingroomWindow1(Vector3f(19.7, 0.75, 8.5), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
OutsideImage livingOutsideImage1(Vector3f(19.7 + 0.001, 1.12, 8.5), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0.37, 0.20, 0.30));
Window livingroomWindow2(Vector3f(26.0, 0.75, 5.4), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
OutsideImage livingOutsideImage2(Vector3f(26.0 - 0.001, 1.12, 5.4), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0.37, 0.20, 0.30));

//livingroom
Armchair armchair(Vector3f(22.8, 0, 10.2), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
Sofa sofa(Vector3f(24.5, 0, 9), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
CoffeeTable coffeeTable(Vector3f(23.7, 0, 10.6), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
Tv tv(Vector3f(24.5, 0, 11.5), Vector3f(0, -115 + 180, 0), Vector3f(1, 1, 1));
TvTable tvTable(Vector3f(24.5, 0, 11.5), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Bookcase bookcase(Vector3f(25.7, 0, 7), Vector3f(0, 180, 0), Vector3f(1, 1, 1));

//kitchen
DiningSet diningSet(Vector3f(22.2, 0, 7), Vector3f(0, -90, 0), Vector3f(1, 1, 1));
Kitchen kitchen(Vector3f(21.15, 0, 5.5), Vector3f(0, 270, 0), Vector3f(1, 1, 1));

//Bedroom
Body body(Vector3f(23, 0, 14.9), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Bed bed(Vector3f(23, 0, 14.9), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Nightstand nightstand1(Vector3f(24.17, 0, 16.2), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Nightstand nightstand2(Vector3f(21.27, 0, 16.2), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
Wardrobe wardrobe(Vector3f(19.85, 0, 12.6), Vector3f(0, 0, 0), Vector3f(1, 1, 1));

//Bathroom
Toilet toilet(Vector3f(26, 0, 15), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
Sink sink(Vector3f(27.2, 0, 12.3), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
Bath bath(Vector3f(28, 0, 14.9), Vector3f(0, 0, 0), Vector3f(1, 1, 1));

//Clues
PhotoFrame photoFrame(Vector3f(24.24, 0.5, 16.11), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
YellowHoodie yellowHoodie(Vector3f(24.53, 0.31, 10.63), Vector3f(0, 0, 0), Vector3f(0.7, 1, 0.7), Vector3f(1, 1, 0.77));
Pills pills(Vector3f(20.08, 0.72, 6.38), Vector3f(0, 0, 0), Vector3f(0.8, 0.8, 0.8));
Knife knife(Vector3f(21.41, 0.1, 14.57), Vector3f(0, 35, 0), Vector3f(1, 1, 1));
Newspaper newspaper(Vector3f(22.2, 0.75, 7.28), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0.3, 1, 0.3));
AnsweringMachine answeringMachine(Vector3f(24.38, 0.25, 11.38), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
BrokenGlass brokenGlass(Vector3f(20.68, 0.01, 8.47), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0.25, 0.25, 0.25));
SuicideNote suicideNote(Vector3f(21.94, 0.51, 15.28), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(0.2, 1, 0.2));

YellowHoodie savior(Vector3f(0, 3, 0), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(1, 1, 1));

void initClues()
{
  int len = sizeof(clues) / sizeof(*clues);
  clues[0] = &photoFrame;
  clues[1] = &yellowHoodie;
  clues[2] = &pills;
  clues[3] = &knife;
  clues[4] = &newspaper;
  clues[5] = &answeringMachine;
  clues[6] = &brokenGlass;
  clues[7] = &suicideNote;
  //  for (int i = 0; i < len; i++)
  //  {
  //     (*clues[i]).find(true);
  //    journal.write(i, NOT_STATED);
  //  }
}

void drawClues()
{
  // int len = sizeof(clues) / sizeof(*clues);
  // for (int i = 0; i < len; i++)
  // {
  //   if (!(*clues[i]).isFound())
  //   {
  //     (*clues[i]).draw();
  //   }
  // }
    // clues
  if(!photoFrame.isFound()||interactingObject==0)  
  photoFrame.draw();       // clue0
  if(!yellowHoodie.isFound() || interactingObject == 1)
  yellowHoodie.draw();     // clue1
  if(!pills.isFound() || interactingObject ==2)
  pills.draw();            // clue2
  if(!knife.isFound() || interactingObject == 3)
  knife.draw();            // clue3
  if(!newspaper.isFound()||interactingObject ==4)
  newspaper.draw();        // clue4
  if(!answeringMachine.isFound() || interactingObject ==5)
  answeringMachine.draw(); // clue5
  if(!brokenGlass.isFound()||interactingObject ==6)
  brokenGlass.draw();      // clue6
  if(!suicideNote.isFound() || interactingObject ==7)
  suicideNote.draw();      // clue7
}

void initEnvironment()
{
  Eigen::Vector3f dim(0.2, 2, 1);
  // Corridor
  Eigen::Vector3f loc0(12, 0, 1.63);          // (1.63, 12)
  Eigen::Vector3f ori0(0, 0, 0);              // along z
  Eigen::Vector3f scl0(1, 1, 3);              // length 3
  walls[0] = new Wall(loc0, ori0, scl0, dim); // South wall
  Eigen::Vector3f loc1(12, 0, 1.63);          // (1.63, 12)
  Eigen::Vector3f ori1(0, 90, 0);             // along x
  Eigen::Vector3f scl1(1, 1, 18);             // length 18
  walls[1] = new Wall(loc1, ori1, scl1, dim); // West wall
  Eigen::Vector3f loc2(30, 0, 1.63);          // (1.63, 30)
  Eigen::Vector3f ori2(0, 0, 0);              // along z
  Eigen::Vector3f scl2(1, 1, 3);              // length 3
  walls[2] = new Wall(loc2, ori2, scl2, dim); // North wall
  Eigen::Vector3f loc3(12, 0, 4.63);          // (4.63, 12)
  Eigen::Vector3f ori3(0, 90, 0);             // along x
  Eigen::Vector3f scl3(1, 1, 12);             // length 12
  walls[3] = new Wall(loc3, ori3, scl3, dim); // East wall part 1
  Eigen::Vector3f loc4(25, 0, 4.63);          // (4.63, 25)
  Eigen::Vector3f ori4(0, 90, 0);             // along x
  Eigen::Vector3f scl4(1, 1, 5);              // length 5
  walls[4] = new Wall(loc4, ori4, scl4, dim); // East wall part 2

  // Kitchen
  Eigen::Vector3f loc5(19.5, 0, 4.64);        // (4.63, 19.5)
  Eigen::Vector3f ori5(0, 90, 0);             // along x
  Eigen::Vector3f scl5(1, 1, 3.5);            // length 3
  walls[5] = new Wall(loc5, ori5, scl5, dim); // West wall
  Eigen::Vector3f loc6(19.5, 0, 4.64);        // (4.63, 19.5)
  Eigen::Vector3f ori6(0, 0, 0);              // along z
  Eigen::Vector3f scl6(1, 1, 1.97);           // length 1.97
  walls[6] = new Wall(loc6, ori6, scl6, dim); // South wall

  // Reception
  Eigen::Vector3f loc7(26, 0, 4.64);              // (4.63, 26)
  Eigen::Vector3f ori7(0, 0, 0);                  // along z
  Eigen::Vector3f scl7(1, 1, 7.37);               // length 7.37
  walls[7] = new Wall(loc7, ori7, scl7, dim);     // North wall
  Eigen::Vector3f loc8(23, 0, 4.64);              // (4.63, 23)
  Eigen::Vector3f ori8(0, 90, 0);                 // along x
  Eigen::Vector3f scl8(1, 1, 1);                  // length 1
  walls[8] = new Wall(loc8, ori8, scl8, dim);     // West wall part 1
  Eigen::Vector3f loc9(25.01, 0, 4.64);           // (4.63, 25)
  Eigen::Vector3f ori9(0, 90, 0);                 // along x
  Eigen::Vector3f scl9(1, 1, 0.99);               // length 1
  walls[9] = new Wall(loc9, ori9, scl9, dim);     // West wall part 2
  Eigen::Vector3f loc10(19.5, 0, 6.6);            // (7.5, 19.5)
  Eigen::Vector3f ori10(0, 0, 0);                 // along z
  Eigen::Vector3f scl10(1, 1, 5.4);               // length 4.5
  walls[10] = new Wall(loc10, ori10, scl10, dim); // South wall
  Eigen::Vector3f loc11(19.5, 0, 12);             // (12, 19.5)
  Eigen::Vector3f ori11(0, 90, 0);                // along x
  Eigen::Vector3f scl11(1, 1, 1.55);              // length 1.5
  walls[11] = new Wall(loc11, ori11, scl11, dim); // East wall part 1
  Eigen::Vector3f loc12(21.9, 0, 12);             // (12, 22)
  Eigen::Vector3f ori12(0, 90, 0);                // along x
  Eigen::Vector3f scl12(1, 1, 4.1);               // length 4
  walls[12] = new Wall(loc12, ori12, scl12, dim); // East wall part 2

  // Bedroom
  Eigen::Vector3f loc13(25.5, 0, 12.01);          // (12, 25.5)
  Eigen::Vector3f ori13(0, 0, 0);                 // along z
  Eigen::Vector3f scl13(1, 1, 1.09);              // length 1
  walls[13] = new Wall(loc13, ori13, scl13, dim); // North wall part 1
  Eigen::Vector3f loc14(25.5, 0, 13.95);          // (14, 25.5)
  Eigen::Vector3f ori14(0, 0, 0);                 // along z
  Eigen::Vector3f scl14(1, 1, 2.6);               // length 2.5
  walls[14] = new Wall(loc14, ori14, scl14, dim); // North wall part 2
  Eigen::Vector3f loc15(19.5, 0, 12.01);          // (12, 19.5)
  Eigen::Vector3f ori15(0, 90, 0);                // along x
  Eigen::Vector3f scl15(1, 1, 1.55);              // length 1.5
  walls[15] = new Wall(loc15, ori15, scl15, dim); // West wall part 1
  Eigen::Vector3f loc16(21.9, 0, 12.01);          // (12, 22)
  Eigen::Vector3f ori16(0, 90, 0);                // along x
  Eigen::Vector3f scl16(1, 1, 3.6);               // length 3.5
  walls[16] = new Wall(loc16, ori16, scl16, dim); // West wall part 2
  Eigen::Vector3f loc17(19.5, 0, 12);             // (12, 19.5)
  Eigen::Vector3f ori17(0, 0, 0);                 // along z
  Eigen::Vector3f scl17(1, 1, 4.5);               // length 4.5
  walls[17] = new Wall(loc17, ori17, scl17, dim); // South wall
  Eigen::Vector3f loc18(19.5, 0, 16.5);           // (16.5, 19.5)
  Eigen::Vector3f ori18(0, 90, 0);                // along x
  Eigen::Vector3f scl18(1, 1, 6);                 // length 6
  walls[18] = new Wall(loc18, ori18, scl18, dim); // East wall

  // Bathroom
  Eigen::Vector3f loc19(28.5, 0, 12);             // (12, 28.5)
  Eigen::Vector3f ori19(0, 0, 0);                 // along z
  Eigen::Vector3f scl19(1, 1, 4);                 // length 4
  walls[19] = new Wall(loc19, ori19, scl19, dim); // North wall
  Eigen::Vector3f loc20(25.5, 0, 12.01);          // (12, 25.5)
  Eigen::Vector3f ori20(0, 90, 0);                // along x
  Eigen::Vector3f scl20(1, 1, 3);                 // length 3
  walls[20] = new Wall(loc20, ori20, scl20, dim); // West wall
  Eigen::Vector3f loc21(25.51, 0, 12.01);         // (12, 25.5)
  Eigen::Vector3f ori21(0, 0, 0);                 // along z
  Eigen::Vector3f scl21(1, 1, 1.09);              // length 1
  walls[21] = new Wall(loc21, ori21, scl21, dim); // South wall part 1
  Eigen::Vector3f loc22(25.51, 0, 13.96);         // (14, 25.5)
  Eigen::Vector3f ori22(0, 0, 0);                 // along z
  Eigen::Vector3f scl22(1, 1, 2.1);               // length 2
  walls[22] = new Wall(loc22, ori22, scl22, dim); // South wall part 2
  Eigen::Vector3f loc23(25.51, 0, 16);            // (16, 25.5)
  Eigen::Vector3f ori23(0, 90, 0);                // along x
  Eigen::Vector3f scl23(1, 1, 3);                 // length 3
  walls[23] = new Wall(loc23, ori23, scl23, dim); // East wall

  floorTex = loadImage("assets/images/floor.png");
  ceilingTex = loadImage("assets/images/celling.png");
}

void drawEnvironment()
{
  for (int i = 0; i < sizeof(walls) / sizeof(*walls); i++)
  {
    (*walls[i]).draw();
  }

  glPushMatrix();
  {
    glTranslatef(0, 2, 0);
    drawImageHorizontal(12, 30, 1, 17, ceilingTex);
  }
  glPopMatrix();
  drawImageHorizontal(12, 30, 1, 17, floorTex);
}

bool intersectsWalls()
{
  bool intersects = false;
  for (int i = 0; i < sizeof(walls) / sizeof(*walls); i++)
  {
    intersects |= (*walls[i]).intersects(player);
  }
  if (!apartmentDoor.isOpen())
  {
    intersects |= apartmentDoor.intersects(player);
  }
  if (!bedroomDoor.isOpen())
  {
    intersects |= bedroomDoor.intersects(player);
  }
  if (!bathroomDoor.isOpen())
  {
    intersects |= bathroomDoor.intersects(player);
  }

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

  //  return intersects;
  return false;
}

void initFlashLight()
{
  //GLfloat lmodel_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
  //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

  //
  glEnable(GL_LIGHT1);
  Vector3f viewVec = (player.getCamera().lookAt() - player.location()).normalized();
  Vector3f diff(viewVec.x() * 0.2, -0.2, viewVec.z() * 0.2);
  flashlight.setLocation(player.location() + viewVec * 0.7 - diff);

  //Vector3f upVector = player.getCamera().Upvector();
  //Vector3f eye = player.getCamera().location().normalized();
  //Vector3f ViewCross = viewVec.cross(upVector).normalized();
  GLfloat l1Diffuse[] = {1.0f, 0.0f, 0.0f, 1.0f};
  GLfloat l1Ambient[] = {1.0f, 0.0f, 0.0f, 1.0f};
  GLfloat l1Position[] = {player.location().x(), player.location().y(), player.location().z(), true};
  //GLfloat l1Position[] = {eye.x(),eye.y(),eye.z()};
  Vector3f dir = viewVec;
  GLfloat l1Direction[] = {dir.x(), dir.y(), dir.z()};
  GLfloat lightIntensity[] = {5, 5, 5, 1.0f};
  glLightfv(GL_LIGHT1, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT1, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT1, GL_POSITION, l1Position);
  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0);
  glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT1, GL_AMBIENT, lightIntensity);
}

void initLightHere()
{

  //GLfloat lmodel_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
  //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
  //Vector3f viewVec=(player.getCamera().lookAt() - player.location()).normalized();
  //Vector3f upVector = player.getCamera().Upvector();
  //Vector3f eye = player.getCamera().location().normalized();
  //Vector3f ViewCross = viewVec.cross(upVector).normalized();

  //   CellingLight livingroomLight(Vector3f(24.4, 2.25, 10.38), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  // CellingLight kitchenLight(Vector3f(22.04, 2, 6.89), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  // CellingLight1 bathroomLight(Vector3f(26.68, 2.25, 13.3), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  // Fan bedroomFan(Vector3f(22.79, 2.5, 14.57), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  GLfloat l1Diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat l1Ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat l1Position[] = {22.04, 2, 6.89, true};
  GLfloat l2position[] = {24.4, 2, 10.38, true};
  GLfloat l3position[] = {26.68, 2, 13.3, true};
  GLfloat l4position[] = {22.79, 2, 14.57, true};
  //GLfloat l1Position[] = {eye.x(),eye.y(),eye.z()};
  // Vector3f dir = viewVec;
  GLfloat l1Direction[] = {0, -1, 0};
  GLfloat lightIntensity[] = {5, 5, 5, 1.0f};

  float cutoff = 30;
  //light2
  glLightfv(GL_LIGHT2, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT2, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT2, GL_POSITION, l1Position);
  glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, cutoff);
  //glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT2, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT2, GL_ATTENUATION_EXT, lightIntensity);

  //light3
  glLightfv(GL_LIGHT3, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT3, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT3, GL_POSITION, l2position);
  glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, cutoff + 30);
  //glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT3, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT3, GL_ATTENUATION_EXT, lightIntensity);

  //light4
  glLightfv(GL_LIGHT4, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT4, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT4, GL_POSITION, l3position);
  glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, cutoff + 10);
  glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT4, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT4, GL_ATTENUATION_EXT, lightIntensity);

  //light5
  glLightfv(GL_LIGHT5, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT5, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT5, GL_POSITION, l4position);
  glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, cutoff + 30);
  glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT5, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT5, GL_ATTENUATION_EXT, lightIntensity);
}

void drawHitBoxes()
{
  apartmentDoor.drawBoundries();
  bedroomDoor.drawBoundries();
  bathroomDoor.drawBoundries();
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

void drawApartment()
{
  apartmentDoor.draw();
  bedroomDoor.draw();
  bathroomDoor.draw();
  livingroomLight.draw();
  kitchenLight.draw();
  bathroomLight.draw();
  bedroomFan.draw();

  bedroomWindow.draw();
  bedroomOutsideImage.draw();
  livingroomWindow1.draw();
  livingOutsideImage1.draw();
  livingroomWindow2.draw();
  livingOutsideImage2.draw();

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
  savior.draw();
  glPopMatrix();
  drawEnvironment();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Setup light
  // Lights::initLightSource();
  // Lights::setupLights();

  // Set the camera
  if (enableFlashLight)
  {
    initFlashLight();
  }
  else
  {
    glDisable(GL_LIGHT1);
  }
  initLightHere();
  if (gameState == JOURNAL_STATE)
  {
    jCam.setup();
  }
  else
  {
    player.getCamera().setup();
  }
  //	camera.setup();

  // Axes for modeling
  Axes axes(0.5);

  glColor3f(0.8f, 0.1f, 0.2f);
  

  // Reset color and flush buffer
  glColor3f(1.0, 1.0, 1.0);

  Vector3f viewVec = (player.getCamera().lookAt() - player.location()).normalized();
  Vector3f xAxis(1, 0, 0);
  Vector3f zAxis(0, 0, 1);
  float angle = acos((viewVec.dot(xAxis)) / viewVec.norm()) * 180 / PI;
  float check = acos((viewVec.dot(zAxis)) / viewVec.norm()) * 180 / PI;
  glPushMatrix();
  {
    if (check < 90)
    {
      flashlight.draw(90 - angle);
    }
    else
    {
      flashlight.draw(90 + angle);
    }
    journal.draw();
    drawApartment();
    drawClues();
    // drawHitBoxes();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslated(1, 0.5, 1);
  glutSolidCube(0.1);
  glPopMatrix();

  glPushMatrix();
  Vector3f viewVec2 = ((player.getCamera().lookAt() - player.location()).normalized()) * 1.5;
  Vector3f loc = player.location();
  Vector3f Upvector = player.getCamera().upVector();
  Vector3f crossV = viewVec2.cross(Upvector);
  //the required plane is the plane between the up and cross vector
  glColor3f(1, 0, 0);
  glBegin(GL_QUADS);
  {
    glNormal3f(0, 1, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0, -1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1, 0.5, -1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1, 0.5, -2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1, 0, -2);
  }
  glEnd();
  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void loadAssets()
{
  apartmentDoor.setModel();
  bedroomDoor.setModel();
  bathroomDoor.setModel();
  livingroomLight.setModel();
  kitchenLight.setModel();
  bathroomLight.setModel();
  bedroomFan.setModel();

  livingroomWindow1.setModel();
  livingroomWindow2.setModel();
  bedroomWindow.setModel();
  bedroomOutsideImage.setImage("assets/images/window.png");
  livingOutsideImage1.setImage("assets/images/window.png");
  livingOutsideImage2.setImage("assets/images/window.png");

  armchair.setModel();
  sofa.setModel();
  coffeeTable.setModel();
  tv.setModel();
  tvTable.setModel();
  bookcase.setModel();

  kitchen.setModel();
  diningSet.setModel();

  body.setModel();
  bed.setModel();
  nightstand1.setModel();
  nightstand2.setModel();
  wardrobe.setModel();

  toilet.setModel();
  sink.setModel();
  bath.setModel();

  photoFrame.setModel();
  yellowHoodie.setModel();
  pills.setModel();
  knife.setModel();
  newspaper.setModel();
  answeringMachine.setModel();
  brokenGlass.setModel();
  suicideNote.setModel();

  flashlight.setModel();

  journal.setModel();
  // Corridor Texturs
  (*walls[0]).setTexture("assets/images/corridor_wall.jpg");
  (*walls[1]).setTexture("assets/images/corridor_wall.jpg");
  (*walls[2]).setTexture("assets/images/corridor_wall.jpg");
  (*walls[3]).setTexture("assets/images/corridor_wall.jpg");
  (*walls[4]).setTexture("assets/images/corridor_wall.jpg");
  // Kitchen Texturs
  (*walls[5]).setTexture("assets/images/kitchen_wall.jpg");
  (*walls[6]).setTexture("assets/images/kitchen_wall.jpg");
  // Reception and Bedroom Textures
  (*walls[7]).setTexture("assets/images/reception_wall.jpg");
  (*walls[8]).setTexture("assets/images/reception_wall.jpg");
  (*walls[9]).setTexture("assets/images/reception_wall.jpg");
  (*walls[10]).setTexture("assets/images/reception_wall.jpg");
  (*walls[11]).setTexture("assets/images/reception_wall.jpg");
  (*walls[12]).setTexture("assets/images/reception_wall.jpg");
  (*walls[13]).setTexture("assets/images/reception_wall.jpg");
  (*walls[14]).setTexture("assets/images/reception_wall.jpg");
  (*walls[15]).setTexture("assets/images/reception_wall.jpg");
  (*walls[16]).setTexture("assets/images/reception_wall.jpg");
  (*walls[17]).setTexture("assets/images/reception_wall.jpg");
  (*walls[18]).setTexture("assets/images/reception_wall.jpg");
  // Bathroom Textures
  (*walls[19]).setTexture("assets/images/bathroom_wall.jpg");
  (*walls[20]).setTexture("assets/images/bathroom_wall.jpg");
  (*walls[21]).setTexture("assets/images/bathroom_wall.jpg");
  (*walls[22]).setTexture("assets/images/bathroom_wall.jpg");
  (*walls[23]).setTexture("assets/images/bathroom_wall.jpg");
  // // Starting music
}

void interactionTimer(int val)
{
  if (gameState == INTERACTING_STATE)
  {
    (*clues[interactingObject]).rotate();
    glutPostRedisplay();
    glutTimerFunc(20, interactionTimer, 0);
  }
}

void idle()
{
  bedroomFan.rotate();
  glutPostRedisplay();
}

void openDoor(int val)
{
  if (val == 0)
  {
    apartmentDoor.openDoor();
    if (!apartmentDoor.isOpen())
    {
      glutTimerFunc(0, openDoor, 0);
    }
  }
  else if (val == 1)
  {
    bedroomDoor.openDoor();
    if (!bedroomDoor.isOpen())
    {
      glutTimerFunc(0, openDoor, 1);
    }
  }
  else if (val == 2)
  {
    bathroomDoor.openDoor();
    if (!bathroomDoor.isOpen())
    {
      glutTimerFunc(0, openDoor, 2);
    }
  }
}

void closeDoor(int val)
{
  if (val == 0)
  {
    apartmentDoor.closeDoor();
    if (apartmentDoor.isOpen())
    {
      glutTimerFunc(0, closeDoor, 0);
    }
  }
  else if (val == 1)
  {
    bedroomDoor.closeDoor();
    if (bedroomDoor.isOpen())
    {
      glutTimerFunc(0, closeDoor, 1);
    }
  }
  else if (val == 2)
  {
    bathroomDoor.closeDoor();
    if (bathroomDoor.isOpen())
    {
      glutTimerFunc(0, closeDoor, 2);
    }
  }
}

void key(unsigned char k, int x, int y)
{
  int len = sizeof(clues) / sizeof(*clues);
  if (gameState == PLAYING_STATE)
  {
    printf("x:%.2f, z:%.2f\n", player.location().x(),  player.location().z());
    switch (k)
    {
    case 'f':
      enableFlashLight = !enableFlashLight;
      break;
    case 'l':
      // camera.rotateRight();
      player.lookRight();
      break;
    case 'j':
      gameState = JOURNAL_STATE;
      //TODO open Journal
      break;
    case 'i':
      // camera.rotateUp();
      player.lookUp();
      break;
    case 'k':
      // camera.rotateDown();
      player.lookDown();
      break;
    case 'w':
      // camera.translateForward();
      player.moveForward();
      if (intersectsWalls())
      {
        player.moveBackward();
      }
      break;
    case 's':
      // camera.translateBackward();
      player.moveBackward();
      if (intersectsWalls())
      {
        player.moveForward();
      }
      break;
    case 'a':
      // camera.translateLeft();
      player.moveLeft();
      if (intersectsWalls())
      {
        player.moveRight();
      }
      break;
    case 'd':
      // camera.translateRight();
      player.moveRight();
      if (intersectsWalls())
      {
        player.moveLeft();
      }
      break;
    case 'e':
      // camera.translateUp();
      if (player.isLookingAt(apartmentDoor))
      {
        if (!apartmentDoor.isOpen())
        {
          glutTimerFunc(0, openDoor, 0);
        }
        else
        {
          glutTimerFunc(0, closeDoor, 0);
        }
      }
      else if (player.isLookingAt(bedroomDoor))
      {
        if (!bedroomDoor.isOpen())
        {
          glutTimerFunc(0, openDoor, 1);
        }
        else
        {
          glutTimerFunc(0, closeDoor, 1);
        }
      }
      else if (player.isLookingAt(bathroomDoor))
      {
        if (!bathroomDoor.isOpen())
        {
          glutTimerFunc(0, openDoor, 2);
        }
        else
        {
          glutTimerFunc(0, closeDoor, 2);
        }
      }
      else
      {
        for (int i = 0; i < len; i++)
        {
          // printf("attempt clues of %d %d\n", (*clues[i]).getState(), i);
        if (player.isLookingAt(*(clues[i])) && !(*clues[i]).isFound())
          {
            // printf("%d\n", clues[0]);
            // printf("clues of %d %d\n", (*clues[i]).getState(), i);
            std::string s = (*clues[i]).Interact().append("\n");
            interactingObject = i;
            gameState = INTERACTING_STATE;
            Vector3f newVector = player.getCamera().location() + (player.getCamera().lookAt() - player.getCamera().location()).normalized() * 0.8;
            (*clues[interactingObject]).setLocation(newVector);
            glutTimerFunc(20, interactionTimer, 0);
            (*clues[i]).find(true);
            journal.write(i, NOT_STATED);
            break;
          }
        }
      }
      break;
    case 'q':
      camera.translateDown();
      break;
    }
  }
  else if (gameState == INTERACTING_STATE)
  {
    switch (k)
    {
    case 'e':
      gameState = PLAYING_STATE;
      interactingObject=-1;
      break;
    }
  }
  else if (gameState == JOURNAL_STATE)
  {
    switch (k)
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
  int scale = 1;
  if (gameState == PLAYING_STATE)
  {
    glutSetCursor(GLUT_CURSOR_NONE);
    if (y > height_center)
      // camera.rotateDown(0.4);
      player.lookDown(scale);
    if (y < height_center)
      // camera.rotateUp(0.4);
      player.lookUp(scale);
    if (x > width_center)
      // camera.rotateRight(0.4);
      player.lookRight(scale);
    if (x < width_center)
      // camera.rotateLeft(0.4);
      player.lookLeft(scale);

    y = height - y;

    // pins mouse in screen center
    if (abs(x - width_center) > 1)
    {
      x = width_center;
      glutWarpPointer(width_center, y);
    }

    if (abs(y - height_center) > 1)
      glutWarpPointer(x, height_center);
    glutPostRedisplay();
  }
}

void setClueType(int idx)
{
  int lenClues = (sizeof(cluesAnswer) / sizeof(int));

  if (idx >= lenClues || !(*clues[idx]).isFound())
  {
    return;
  }
  // printf("%d %d %d\n", gameState, idx, (*clues[idx]).getState());
  //set the clue type here
  bool win = true;
  (*clues[idx]).setState((*clues[idx]).getState() == 1 ? -1 : 1);
  for (int i = 0; i < lenClues; i++)
  {
    if ((*clues[i]).getState() != cluesAnswer[i])
    {
      win = false;
      break;
    }
  }
  journal.write(idx, (*clues[idx]).getState());
  gameState = win == true ? WINNING_STATE : gameState;
  glutPostRedisplay();
}

void mouseOverJournal(int button, int state, int x, int y)
{
  if (gameState == JOURNAL_STATE)
  {
    glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
    glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
      if (x < 550)
      {
        if (y < 110 && y > 20)
        {
          setClueType(0);
        }
        else if (y < 220 && y > 120)
        {
          setClueType(1);
        }
        else if (y < 325 && y > 225)
        {
          setClueType(2);
        }
        else if (y < 450 && y > 335)
        {
          setClueType(3);
        }
        else if (y < 575 && y > 455)
        {
          setClueType(4);
        }
      }
      else
      {
        if (y < 110 && y > 20)
        {
          setClueType(5);
        }
        else if (y < 220 && y > 120)
        {
          setClueType(6);
        }
        else if (y < 325 && y > 225)
        {
          setClueType(7);
        }
        else if (y < 450 && y > 335)
        {
          setClueType(8);
        }
        else if (y < 575 && y > 455)
        {
          setClueType(9);
        }
      }
    }
  }
}

void losingStateCaller(int val)
{
  if (gameState != WINNING_STATE)
  {
    gameState = LOSING_STATE;
    printf("koko lost\n");
  }
  glutPostRedisplay();
}

void main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowSize(width, height);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Game Title");

  glutDisplayFunc(display);
  glutKeyboardFunc(key);
  glutPassiveMotionFunc(mouseMovement);

  glClearColor(1, 1, 1, 0);

  initEnvironment();
  initClues();
  loadAssets();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glEnable(GL_LIGHT4);
  glEnable(GL_LIGHT5);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);
  glShadeModel(GL_SMOOTH);

  GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat shinness[] = {100};
  GLfloat lDiffuse[] = {0.1f, 0.1f, 0.1f, 1.0f};
  GLfloat lAmbient[] = {0.1f, 0.1f, 0.1f, 1.0f};
  glMaterialfv(GL_FRONT, GL_AMBIENT, lAmbient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, lDiffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shinness);
  glDisable(GL_COLOR_MATERIAL);

  // TODO 10 mins
  // glutTimerFunc(10000, losingStateCaller, 0);
  glutIdleFunc(idle);
  glutMouseFunc(mouseOverJournal);

  glutMainLoop();
}