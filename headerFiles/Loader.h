#ifndef LOADER_H
#define LOADER_H

#include "headerFiles/Objects/NonInteractiveObjects/DiningSet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sofa.h"
#include "headerFiles/Objects/InteractiveObjects/Door.h"

void loadDoorModel(Door &door);
void loadDiningSetModel(DiningSet &diningSet);
void loadSofaModel(Sofa &sofa);
void loadAssets();

#endif