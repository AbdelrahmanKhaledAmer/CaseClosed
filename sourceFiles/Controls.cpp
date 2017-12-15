#include "headerFiles/Controls.h"

void key(unsigned char k, int x, int y)
{
  int len = sizeof(clues) / sizeof(*clues);
  if (gameState == PLAYING_STATE)
  {
    //printf("x:%.2f, z:%.2f\n", player.location().x(),  player.location().z());
    switch (k)
    {
    case 'f':
      enableFlashLight = !enableFlashLight;
      break;
    case 'l':
      // camera.rotateRight();
      player.lookRight();
      break;
    case 'j':
      gameState = JOURNAL_STATE;
      glEnable(GL_LIGHT6);
      //TODO open Journal
      break;
    case 'i':
      // camera.rotateUp();
      player.lookUp();
      break;
    case 'k':
      // camera.rotateDown();
      player.lookDown();
      break;
    case 'w':
      // camera.translateForward();
      player.moveForward();
      if (intersectsWalls())
      {
        player.moveBackward();
      }
      break;
    case 's':
      // camera.translateBackward();
      player.moveBackward();
      if (intersectsWalls())
      {
        player.moveForward();
      }
      break;
    case 'a':
      // camera.translateLeft();
      player.moveLeft();
      if (intersectsWalls())
      {
        player.moveRight();
      }
      break;
    case 'd':
      // camera.translateRight();
      player.moveRight();
      if (intersectsWalls())
      {
        player.moveLeft();
      }
      break;
    case 'e':
      // camera.translateUp();
      if (player.isLookingAt(apartmentDoor))
      {
        if (!apartmentDoor.isOpen())
        {
          PlaySound("assets\\audio\\sfx\\open_door_1.wav", NULL, SND_ASYNC);
          glutTimerFunc(0, openDoor, 0);
        }
        else
        {
          glutTimerFunc(0, closeDoor, 0);
        }
      }
      else if (player.isLookingAt(bedroomDoor))
      {
        if (!bedroomDoor.isOpen())
        {
          PlaySound("assets\\audio\\sfx\\open_door_1.wav", NULL, SND_ASYNC);
          glutTimerFunc(0, openDoor, 1);
        }
        else
        {
          glutTimerFunc(0, closeDoor, 1);
        }
      }
      else if (player.isLookingAt(bathroomDoor))
      {
        if (!bathroomDoor.isOpen())
        {
          PlaySound("assets\\audio\\sfx\\open_door_1.wav", NULL, SND_ASYNC);
          glutTimerFunc(0, openDoor, 2);
        }
        else
        {
          glutTimerFunc(0, closeDoor, 2);
        }
      }
      else
      {
        for (int i = 0; i < len; i++)
        {
          // printf("attempt clues of %d %d\n", (*clues[i]).getState(), i);
        if (player.isLookingAt(*(clues[i])) && !(*clues[i]).isFound())
          {
            // printf("%d\n", clues[0]);
            printf("clues of %d %d\n", (*clues[i]).getState(), i);
            std::string s = (*clues[i]).Interact();
            checkString(s);
            interactingObject = i;
            gameState = INTERACTING_STATE;
            Vector3f newVector = player.getCamera().location() + (player.getCamera().lookAt() - player.getCamera().location()).normalized() * 0.8;
            (*clues[interactingObject]).setLocation(newVector);
            glutTimerFunc(20, interactionTimer, 0);
            (*clues[i]).find(true);
            journal.write(i, NOT_STATED);
            break;
          }
        }
      }
      break;
    case 'q':
      camera.translateDown();
      break;
    }
  }
  else if (gameState == INTERACTING_STATE)
  {
    switch (k)
    {
    case 'e':
      gameState = PLAYING_STATE;
      interactingObject = -1;
      break;
    }
  }
  else if (gameState == JOURNAL_STATE)
  {
    switch (k)
    {
    case 'j':
      gameState = PLAYING_STATE;
       glDisable(GL_LIGHT6);
      break;
    }
  }
  glutPostRedisplay();
}

//=======================================================================
// Motion Function
const int height_center = height / 2, width_center = width / 2;
//=======================================================================
void mouseMovement(int x, int y)
{
  int scale = 1;
  if (gameState == PLAYING_STATE)
  {
    glutSetCursor(GLUT_CURSOR_NONE);
    if (y > height_center)
      // camera.rotateDown(0.4);
      player.lookDown(scale);
    if (y < height_center)
      // camera.rotateUp(0.4);
      player.lookUp(scale);
    if (x > width_center)
      // camera.rotateRight(0.4);
      player.lookRight(scale);
    if (x < width_center)
      // camera.rotateLeft(0.4);
      player.lookLeft(scale);

    y = height - y;

    // pins mouse in screen center
    if (abs(x - width_center) > 1)
    {
      x = width_center;
      glutWarpPointer(width_center, y);
    }

    if (abs(y - height_center) > 1)
      glutWarpPointer(x, height_center);
    glutPostRedisplay();
  }
}