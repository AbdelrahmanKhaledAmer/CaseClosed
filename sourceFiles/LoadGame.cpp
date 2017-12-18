#include "headerFiles/LoadGame.h"

void loadAssets() {
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

  for (Object *furniture : livingroom)
    furniture->setModel();

  for (Object *furniture : kitchen)
    furniture->setModel();

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
  (*walls[0]).setModel("assets/images/corridor_wall.jpg");
  (*walls[1]).setModel("assets/images/corridor_wall.jpg");
  (*walls[2]).setModel("assets/images/corridor_wall.jpg");
  (*walls[3]).setModel("assets/images/corridor_wall.jpg");
  (*walls[4]).setModel("assets/images/corridor_wall.jpg");
  // Kitchen Texturs
  (*walls[5]).setModel("assets/images/kitchen_wall.jpg");
  (*walls[6]).setModel("assets/images/kitchen_wall.jpg");
  // Reception and Bedroom Textures
  (*walls[7]).setModel("assets/images/reception_wall.jpg");
  (*walls[8]).setModel("assets/images/reception_wall.jpg");
  (*walls[9]).setModel("assets/images/reception_wall.jpg");
  (*walls[10]).setModel("assets/images/reception_wall.jpg");
  (*walls[11]).setModel("assets/images/reception_wall.jpg");
  (*walls[12]).setModel("assets/images/reception_wall.jpg");
  (*walls[13]).setModel("assets/images/reception_wall.jpg");
  (*walls[14]).setModel("assets/images/reception_wall.jpg");
  (*walls[15]).setModel("assets/images/reception_wall.jpg");
  (*walls[16]).setModel("assets/images/reception_wall.jpg");
  (*walls[17]).setModel("assets/images/reception_wall.jpg");
  (*walls[18]).setModel("assets/images/reception_wall.jpg");
  // Bathroom Textures
  (*walls[19]).setModel("assets/images/bathroom_wall.jpg");
  (*walls[20]).setModel("assets/images/bathroom_wall.jpg");
  (*walls[21]).setModel("assets/images/bathroom_wall.jpg");
  (*walls[22]).setModel("assets/images/bathroom_wall.jpg");
  (*walls[23]).setModel("assets/images/bathroom_wall.jpg");
  
  // Starting music
  mciSendString("play assets\\audio\\music\\bgm.mp3 repeat", 0, 0, 0);
}