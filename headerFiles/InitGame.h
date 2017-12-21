#ifndef INIT_GAME_H
#define INIT_GAME_H

#include "headerFiles/Include.h"

// Screen Constants =================================================
extern const int scale;
extern const int width;
extern const int height;

// Textures ==========================================================
extern GLuint floorTex, ceilingTex;
extern GLuint WinImg, loseImg;

//flashLight ON/OFF
extern bool enableFlashLight;

// Game variables ===================================================
extern int gameState;
extern int interactingObject;

extern Eigen::Vector3f eye;
extern Eigen::Vector3f lookAt;
extern Eigen::Vector3f orientation;

extern Camera camera;
extern Player player;
extern Flashlight flashlight;
extern Journal journal;

extern Eigen::Vector3f eye2;
extern Eigen::Vector3f lookAt2;
extern Eigen::Vector3f orientation2;
extern Camera jCam;

extern int cluesAnswer[8];
extern Clue *clues[8];
extern Wall *walls[24];

// Appartment Layout ================================================
extern Door apartmentDoor;
extern Door1 bedroomDoor;
extern Door1 bathroomDoor;
extern Window window;
extern CellingLight livingroomLight;
extern CellingLight kitchenLight;
extern CellingLight1 bathroomLight;
extern Fan bedroomFan;

extern Window bedroomWindow;
extern OutsideImage bedroomOutsideImage;
extern Window livingroomWindow1;
extern OutsideImage livingOutsideImage1;
extern Window livingroomWindow2;
extern OutsideImage livingOutsideImage2;

//livingroom
#define ARMCHAIR        0
#define SOFA            1
#define COFFEETABLE     2
#define TV              3
#define TVTABLE         4
#define BOOKCASE        5
extern AnsweringMachine answeringMachine;
extern YellowHoodie yellowHoodie;
#define NUM_LIVINGROOM  6
extern Object *livingroom[NUM_LIVINGROOM];

//kitchen
#define KITCHEN         0
#define DININGSET       1
extern Pills pills;
extern Newspaper newspaper;
extern BrokenGlass brokenGlass;
#define NUM_KITCHEN     2
extern Object *kitchen[NUM_KITCHEN];

//Bedroom
#define BODY            0
#define BED             1
#define NIGHTSTAND1     2
#define NIGHTSTAND2     3
#define WARDROBE        4
extern Knife knife;
extern SuicideNote suicideNote;
extern PhotoFrame photoFrame;
#define NUM_BEDROOM     5
extern Object *bedroom[NUM_BEDROOM];

//Bathroom
#define TOILET          0
#define SINK            1
#define BATH            2
#define NUM_BATHROOM    3
extern Object *bathroom[NUM_BATHROOM];


extern YellowHoodie savior;

// Functions ====================================================
void initClues();
void initEnvironment();
void initApartment();

#endif