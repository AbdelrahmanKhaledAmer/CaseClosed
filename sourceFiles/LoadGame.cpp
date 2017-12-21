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

  for (Object *furniture : bedroom)
    furniture->setModel();

  for (Object *furniture : bathroom)
    furniture->setModel();

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

  // Wall Texturs
  for (int i = 0; i < sizeof(walls) / sizeof(walls[0]); i++) {
    char *wallpath;

    if (i < 5)
      wallpath = "assets/images/corridor_wall.jpg";
    else if (i < 7)
      wallpath = "assets/images/kitchen_wall.jpg";
    else if (i < 19)
      wallpath = "assets/images/reception_wall.jpg";
    else
      wallpath = "assets/images/bathroom_wall.jpg";

    walls[i]->setModel(wallpath);
  }

  // Starting music
  mciSendString("play assets\\audio\\music\\bgm.mp3 repeat", 0, 0, 0);
}