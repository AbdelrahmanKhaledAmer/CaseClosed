#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "headerFiles/InitGame.h"

void checkString(std::string s);
bool intersectsWalls();
void interactionTimer(int val);
void setClueType(int idx);
void mouseOverJournal(int button, int state, int x, int y);
void losingStateCaller(int val);
void openDoor(int val);
void closeDoor(int val);

#endif