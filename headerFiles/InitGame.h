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
extern Armchair armchair;
extern Sofa sofa;
extern CoffeeTable coffeeTable;
extern Tv tv;
extern TvTable tvTable;
extern Bookcase bookcase;

//kitchen
extern DiningSet diningSet;
extern Kitchen kitchen;

//Bedroom
extern Body body;
extern Bed bed;
extern Nightstand nightstand1;
extern Nightstand nightstand2;
extern Wardrobe wardrobe;

//Bathroom
extern Toilet toilet;
extern Sink sink;
extern Bath bath;

//Clues
extern PhotoFrame photoFrame;
extern YellowHoodie yellowHoodie;
extern Pills pills;
extern Knife knife;
extern Newspaper newspaper;
extern AnsweringMachine answeringMachine;
extern BrokenGlass brokenGlass;
extern SuicideNote suicideNote;

extern YellowHoodie savior;

// Functions ====================================================
void initClues();
void initEnvironment();

#endif