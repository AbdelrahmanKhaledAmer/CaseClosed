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

Object *livingroom[NUM_LIVINGROOM];
Object *kitchen[NUM_KITCHEN];
Object *bedroom[NUM_BEDROOM];
Object *bathroom[NUM_BATHROOM];

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
  Vector3f dim(0.2, 2, 1);
  Vector3f alongX(0, 90, 0);
  Vector3f alongZ(0, 0, 0);
  // Corridor
  walls[0] = new Wall(Vector3f(12, 0, 1.63), alongZ, Vector3f(1, 1, 3), dim);   // South wall
  walls[1] = new Wall(Vector3f(12, 0, 1.63), alongX, Vector3f(1, 1, 18), dim);  // West wall
  walls[2] = new Wall(Vector3f(30, 0, 1.63), alongZ, Vector3f(1, 1, 3), dim);   // North wall
  walls[3] = new Wall(Vector3f(12, 0, 4.63), alongX, Vector3f(1, 1, 12), dim);  // East wall part 1
  walls[4] = new Wall(Vector3f(25, 0, 4.63), alongX, Vector3f(1, 1, 5), dim);   // East wall part 2

  // Kitchen
  walls[5] = new Wall(Vector3f(19.5, 0, 4.64), alongX, Vector3f(1, 1, 3.5), dim);   // West wall
  walls[6] = new Wall(Vector3f(19.5, 0, 4.64), alongZ, Vector3f(1, 1, 1.97), dim);  // South wall

  // Reception
  walls[7] = new Wall(Vector3f(26, 0, 4.64), alongZ, Vector3f(1, 1, 7.37), dim);    // North wall
  walls[8] = new Wall(Vector3f(23, 0, 4.64), alongX, Vector3f(1, 1, 1), dim);       // West wall part 1
  walls[9] = new Wall(Vector3f(25.01, 0, 4.64), alongX, Vector3f(1, 1, 0.99), dim); // West wall part 2
  walls[10] = new Wall(Vector3f(19.5, 0, 6.6), alongZ, Vector3f(1, 1, 5.4), dim);   // South wall
  walls[11] = new Wall(Vector3f(19.5, 0, 12), alongX, Vector3f(1, 1, 1.55), dim);   // East wall part 1
  walls[12] = new Wall(Vector3f(21.9, 0, 12), alongX, Vector3f(1, 1, 4.1), dim);    // East wall part 2

  // Bedroom
  walls[13] = new Wall(Vector3f(25.5, 0, 12.01), alongZ, Vector3f(1, 1, 1.09), dim);  // North wall part 1
  walls[14] = new Wall(Vector3f (25.5, 0, 13.95), alongZ, Vector3f(1, 1, 2.6), dim);  // North wall part 2
  walls[15] = new Wall(Vector3f(19.5, 0, 12.01), alongX, Vector3f(1, 1, 1.55), dim);  // West wall part 1
  walls[16] = new Wall(Vector3f(21.9, 0, 12.01), alongX, Vector3f(1, 1, 3.6), dim);   // West wall part 2
  walls[17] = new Wall(Vector3f(19.5, 0, 12), alongZ, Vector3f(1, 1, 4.5), dim);      // South wall
  walls[18] = new Wall(Vector3f(19.5, 0, 16.5), alongX, Vector3f(1, 1, 6), dim);      // East wall

  // Bathroom
  walls[19] = new Wall(Vector3f(28.5, 0, 12), alongZ, Vector3f(1, 1, 4), dim);        // North wall
  walls[20] = new Wall(Vector3f(25.5, 0, 12.01), alongX, Vector3f(1, 1, 3), dim);     // West wall
  walls[21] = new Wall(Vector3f(25.51, 0, 12.01), alongZ, Vector3f(1, 1, 1.09), dim); // South wall part 1
  walls[22] = new Wall(Vector3f(25.51, 0, 13.96), alongZ, Vector3f(1, 1, 2.1), dim);  // South wall part 2
  walls[23] = new Wall(Vector3f(25.51, 0, 16), alongX, Vector3f(1, 1, 3), dim);       // East wall

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

void initKitchen(){
  kitchen[KITCHEN]        = new Kitchen(Vector3f(21.15, 0, 5.5), Vector3f(0, 270, 0), Vector3f(1, 1, 1));
  kitchen[DININGSET]      = new DiningSet(Vector3f(22.2, 0, 7), Vector3f(0, -90, 0), Vector3f(1, 1, 1));
}

void initBedroom(){
  bedroom[BODY]           = new Body(Vector3f(23, 0, 14.9), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
  bedroom[BED]            = new Bed(Vector3f(23, 0, 14.9), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
  bedroom[NIGHTSTAND1]    = new Nightstand(Vector3f(24.17, 0, 16.2), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
  bedroom[NIGHTSTAND2]    = new Nightstand(Vector3f(21.27, 0, 16.2), Vector3f(0, 180, 0), Vector3f(1, 1, 1));
  bedroom[WARDROBE]       = new Wardrobe(Vector3f(19.85, 0, 12.6), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
}

void initBathroom(){
  bathroom[TOILET]        = new Toilet(Vector3f(26, 0, 15), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  bathroom[SINK]          = new Sink(Vector3f(27.2, 0, 12.3), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  bathroom[BATH]          = new Bath(Vector3f(28, 0, 14.9), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
}

void initApartment(){
  initLivingRoom();
  initKitchen();
  initBedroom();
  initBathroom();
}