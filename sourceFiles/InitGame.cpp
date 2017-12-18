#include "headerFiles/InitGame.h"

//win and lose textures
GLuint WinImg, loseImg;

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

YellowHoodie savior(Vector3f(30, 30, 30), Vector3f(0, 0, 0), Vector3f(1, 1, 1), Vector3f(1, 1, 1));

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
  WinImg = loadImage("assets/images/win.png");
  loseImg = loadImage("assets/images/lose.png");
}

void initLivingRoom(){
  livingroom[ARMCHAIR]    = new Armchair(Vector3f(22.8, 0, 10.2), Vector3f(0, 90, 0), Vector3f(1, 1, 1));
  livingroom[SOFA]        = new Sofa(Vector3f(24.5, 0, 9), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  livingroom[COFFEETABLE] = new CoffeeTable(Vector3f(23.7, 0, 10.6), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  livingroom[TV]          = new Tv(Vector3f(24.5, 0, 11.5), Vector3f(0, -115 + 180, 0), Vector3f(1, 1, 1));
  livingroom[TVTABLE]     = new TvTable(Vector3f(24.5, 0, 11.5), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
  livingroom[BOOKCASE]    = new Bookcase(Vector3f(25.7, 0, 7), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
}

void initApartment(){
  initLivingRoom();
}