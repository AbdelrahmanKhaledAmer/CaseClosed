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

void loadToiletModel(Toilet &toilet){
	char* toiletPath = "assets/models/furniture/Toilet/Lavatory pan N200317.3DS";
	Model_3DS toiletModel;
	toiletModel.Load(toiletPath);
	toilet.setModel(toiletModel);
}

void loadTvModel(Tv &tv){
	char* tvPath = "assets/models/furniture/Tv/TV set samsung N160913.3DS";
	Model_3DS tvModel;
	tvModel.Load(tvPath);
	tv.setModel(tvModel);
}

void loadKitchenModel(Kitchen &kitchen){
	char* kitchenPath = "assets/models/furniture/Kitchen/Kitchen N100714.3DS";
	Model_3DS kitchenModel;
	kitchenModel.Load(kitchenPath);
	kitchen.setModel(kitchenModel);
}

void loadCoffeeTableModel(CoffeeTable &coffeeTable){
	char* coffeeTablePath = "assets/models/furniture/CoffeeTable/Table N280817.3DS";
	Model_3DS coffeeTableModel;
	coffeeTableModel.Load(coffeeTablePath);
	coffeeTable.setModel(coffeeTableModel);
}

void loadSinkModel(Sink &sink){
	char* sinkPath = "assets/models/furniture/Sink/Wash-basin Ravak SDZU praktik S N080317.3DS";
	Model_3DS sinkModel;
	sinkModel.Load(sinkPath);
	sink.setModel(sinkModel);
}