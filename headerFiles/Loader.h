#ifndef LOADER_H
#define LOADER_H

#include "headerFiles/Objects/NonInteractiveObjects/DiningSet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sofa.h"
#include "headerFiles/Objects/InteractiveObjects/Door.h"
#include "headerFiles/Objects/NonInteractiveObjects/Toilet.h"
#include "headerFiles/Objects/NonInteractiveObjects/Kitchen.h"
#include "headerFiles/Objects/NonInteractiveObjects/Tv.h"
#include "headerFiles/Objects/NonInteractiveObjects/CoffeeTable.h"
#include "headerFiles/Objects/NonInteractiveObjects/Sink.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bed.h"
#include "headerFiles/Objects/NonInteractiveObjects/Wardrobe.h"
#include "headerFiles/Objects/NonInteractiveObjects/Bookcase.h"
#include "headerFiles/Objects/NonInteractiveObjects/CellingLight.h"
#include "headerFiles/Objects/NonInteractiveObjects/Fan.h"
#include "headerFiles/Objects/NonInteractiveObjects/Nightstand.h"
#include "headerFiles/Objects/InteractiveObjects/Clues/Knife.h"
#include "headerFiles/Objects/Flashlight.h"

void loadDoorModel(Door &door);
void loadDiningSetModel(DiningSet &diningSet);
void loadSofaModel(Sofa &sofa);
void loadToiletModel(Toilet &toilet);
void loadTvModel(Tv &tv);
void loadKitchenModel(Kitchen &kitchen);
void loadCoffeeTableModel(CoffeeTable &coffeeTable);
void loadSinkModel(Sink &sink);
void loadBedModel(Bed &bed);
void loadBookcaseModel(Bookcase &bookcase);
void loadWardrobeModel(Wardrobe &wardrobe);
void loadKnifeModel(Knife &knife);
void loadCellingLightModel(CellingLight &cellingLight);
void loadFanModel(Fan &fan);
void loadNightstandModel(Nightstand &nightstand);
void loadFlashlightModel(Flashlight &flashlight);
#endif