#include "headerFiles/Draw.h"

void drawClues()
{
  // int len = sizeof(clues) / sizeof(*clues);
  // for (int i = 0; i < len; i++)
  // {
  //   if (!(*clues[i]).isFound())
  //   {
  //     (*clues[i]).draw();
  //   }
  // }
  // clues
  if (!photoFrame.isFound() || interactingObject == 0)
    photoFrame.draw(); // clue0
  if (!yellowHoodie.isFound() || interactingObject == 1)
    yellowHoodie.draw(); // clue1
  if (!pills.isFound() || interactingObject == 2)
    pills.draw(); // clue2
  if (!knife.isFound() || interactingObject == 3)
    knife.draw(); // clue3
  if (!newspaper.isFound() || interactingObject == 4)
    newspaper.draw(); // clue4
  if (!answeringMachine.isFound() || interactingObject == 5)
    answeringMachine.draw(); // clue5
  if (!brokenGlass.isFound() || interactingObject == 6)
    brokenGlass.draw(); // clue6
  if (!suicideNote.isFound() || interactingObject == 7)
    suicideNote.draw(); // clue7
}

void drawEnvironment()
{
  for (int i = 0; i < sizeof(walls) / sizeof(*walls); i++)
  {
    (*walls[i]).draw();
  }

  glPushMatrix();
  {
    glTranslatef(0, 2, 0);
    drawImageHorizontal(12, 30, 1, 17, ceilingTex);
  }
  glPopMatrix();
  drawImageHorizontal(12, 30, 1, 17, floorTex);
}

void drawHitBoxes()
{
  apartmentDoor.drawBoundries();
  bedroomDoor.drawBoundries();
  bathroomDoor.drawBoundries();
  armchair.drawBoundries();
  sofa.drawBoundries();
  coffeeTable.drawBoundries();
  tv.drawBoundries();
  tvTable.drawBoundries();
  bookcase.drawBoundries();
  kitchen.drawBoundries();
  diningSet.drawBoundries();
  bed.drawBoundries();
  nightstand1.drawBoundries();
  nightstand2.drawBoundries();
  wardrobe.drawBoundries();
  toilet.drawBoundries();
  sink.drawBoundries();
  bath.drawBoundries();
}

void drawApartment()
{
  apartmentDoor.draw();
  bedroomDoor.draw();
  bathroomDoor.draw();
  livingroomLight.draw();
  kitchenLight.draw();
  bathroomLight.draw();
  bedroomFan.draw();

  bedroomWindow.draw();
  bedroomOutsideImage.draw();
  livingroomWindow1.draw();
  livingOutsideImage1.draw();
  livingroomWindow2.draw();
  livingOutsideImage2.draw();

  // livingroom
  armchair.draw();
  sofa.draw();
  coffeeTable.draw();
  tv.draw();
  tvTable.draw();
  bookcase.draw();

  // kitchen
  kitchen.draw();
  diningSet.draw();

  // bedroom
  body.draw();
  bed.draw();
  nightstand1.draw();
  nightstand2.draw();
  wardrobe.draw();

  // Toilet
  toilet.draw();
  sink.draw();
  bath.draw();
  savior.draw();
  glPopMatrix();
  drawEnvironment();
   savior.draw();
}

void winDraw()
{
  PlaySound("assets\\audio\\soundBytes\\win_state.wav", NULL, SND_ASYNC); 
  float scale=4*2.0/16;
  glPushMatrix();
  {
    glTranslatef(-1.5,-0.7,0.15);
    drawImage(0, 9*scale, 0, 16*scale, WinImg);
  }
  glPopMatrix();

}

void loseDraw()
{
  PlaySound("assets\\audio\\soundBytes\\lose_state.wav", NULL, SND_ASYNC); 
  float scale=4*2.0/16;
  glPushMatrix();
  {
    glTranslatef(-1.5,-0.7,0.15);
    drawImage(0, 9*scale, 0, 16*scale, loseImg);
  }
  glPopMatrix();
}

void idle()
{
  bedroomFan.rotate();
  glutPostRedisplay();
}