#ifndef INCLUDE_H
#define INCLUDE_H

// Defines ==========================================================
#define PI 3.14159265358979323846
#define PLAYING_STATE 0
#define LOSING_STATE 1
#define WINNING_STATE 2
#define INTERACTING_STATE 3
#define JOURNAL_STATE 4

// Libraries, dependencies and classes ==============================
//#include "headerFiles/TextureBuilder.h"

#include "headerFiles/GL/glew.h"
#include "headerFiles/GL/glaux.h"

#include "headerFiles/GLTexture.h"
#include "headerFiles/Model_3DS.h"
#include "windows.h"
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

#endif