#include "headerFiles/LoadGame.h"

void loadAssets()
{
  for (Object *object : livingroom) {
    (*object).setModel();
  }

  apartmentDoor.setModel();
  bedroomDoor.setModel();
  bathroomDoor.setModel();
  livingroomLight.setModel();
  kitchenLight.setModel();
  bathroomLight.setModel();
  bedroomFan.setModel();

  livingroomWindow1.setModel();
  livingroomWindow2.setModel();
  bedroomWindow.setModel();
  bedroomOutsideImage.setModel("assets/images/window.png");
  livingOutsideImage1.setModel("assets/images/window.png");
  livingOutsideImage2.setModel("assets/images/window.png");

  // armchair.setModel();
  // sofa.setModel();
  // coffeeTable.setModel();
  // tv.setModel();
  // tvTable.setModel();
  // bookcase.setModel();

  kitchen.setModel();
  diningSet.setModel();

  body.setModel();
  bed.setModel();
  nightstand1.setModel();
  nightstand2.setModel();
  wardrobe.setModel();

  toilet.setModel();
  sink.setModel();
  bath.setModel();

  photoFrame.setModel();
  yellowHoodie.setModel();
  pills.setModel();
  knife.setModel();
  newspaper.setModel();
  answeringMachine.setModel();
  brokenGlass.setModel();
  suicideNote.setModel();

  flashlight.setModel();

  journal.setModel();
  // Corridor Texturs
  (*walls[0]).setTexture("assets/images/corridor_wall.jpg");
  (*walls[1]).setTexture("assets/images/corridor_wall.jpg");
  (*walls[2]).setTexture("assets/images/corridor_wall.jpg");
  (*walls[3]).setTexture("assets/images/corridor_wall.jpg");
  (*walls[4]).setTexture("assets/images/corridor_wall.jpg");
  // Kitchen Texturs
  (*walls[5]).setTexture("assets/images/kitchen_wall.jpg");
  (*walls[6]).setTexture("assets/images/kitchen_wall.jpg");
  // Reception and Bedroom Textures
  (*walls[7]).setTexture("assets/images/reception_wall.jpg");
  (*walls[8]).setTexture("assets/images/reception_wall.jpg");
  (*walls[9]).setTexture("assets/images/reception_wall.jpg");
  (*walls[10]).setTexture("assets/images/reception_wall.jpg");
  (*walls[11]).setTexture("assets/images/reception_wall.jpg");
  (*walls[12]).setTexture("assets/images/reception_wall.jpg");
  (*walls[13]).setTexture("assets/images/reception_wall.jpg");
  (*walls[14]).setTexture("assets/images/reception_wall.jpg");
  (*walls[15]).setTexture("assets/images/reception_wall.jpg");
  (*walls[16]).setTexture("assets/images/reception_wall.jpg");
  (*walls[17]).setTexture("assets/images/reception_wall.jpg");
  (*walls[18]).setTexture("assets/images/reception_wall.jpg");
  // Bathroom Textures
  (*walls[19]).setTexture("assets/images/bathroom_wall.jpg");
  (*walls[20]).setTexture("assets/images/bathroom_wall.jpg");
  (*walls[21]).setTexture("assets/images/bathroom_wall.jpg");
  (*walls[22]).setTexture("assets/images/bathroom_wall.jpg");
  (*walls[23]).setTexture("assets/images/bathroom_wall.jpg");
  
  // Starting music
  mciSendString("play assets\\audio\\music\\bgm.mp3 repeat", 0, 0, 0);
}