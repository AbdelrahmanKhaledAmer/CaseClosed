#include "headerFiles/Loader.h"

void loadDoorModel(Door &door){
	char* door_path = "assets/models/furniture/Door/Door.3DS";
	Model_3DS door_model;
	door_model.Load(door_path);	
	door.setModel(door_model);
}

void loadDiningSetModel(DiningSet &diningSet){
	char* diningSetPath = "assets/models/furniture/DiningSet/4 Chair 2 Tone.3ds";
	Model_3DS diningSetModel;
	diningSetModel.Load(diningSetPath);
	diningSet.setModel(diningSetModel);
}

void loadSofaModel(Sofa &sofa){
	char* sofaPath = "assets/models/furniture/Sofa/Sofa 1.3DS";
	Model_3DS sofaModel;
	sofaModel.Load(sofaPath);
	sofa.setModel(sofaModel);
}

void loadAssets()
{
	// Loading texture files
	// Starting music
}