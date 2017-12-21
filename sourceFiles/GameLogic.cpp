#include "headerFiles/GameLogic.h"

void checkString(std::string s)
{
  if(s == "0")
  {
    printf("0\n");
    PlaySound("assets\\audio\\soundBytes\\photoframe.wav", NULL, SND_ASYNC);
  } else if(s == "1") {
    printf("1\n");
    PlaySound("assets\\audio\\soundBytes\\yellow_hoodie.wav", NULL, SND_ASYNC);
  } else if(s == "2") {
    printf("2\n");
    PlaySound("assets\\audio\\soundBytes\\pills.wav", NULL, SND_ASYNC);
  } else if(s == "3") {
    printf("3\n");
    PlaySound("assets\\audio\\soundBytes\\knife.wav", NULL, SND_ASYNC);
  } else if(s == "4") {
    printf("4\n");
    PlaySound("assets\\audio\\soundBytes\\newspaper.wav", NULL, SND_ASYNC);
  } else if(s == "5") {
    printf("5\n");
    PlaySound("assets\\audio\\soundBytes\\answering_machine.wav", NULL, SND_ASYNC);
  } else if(s == "6") {
    printf("6\n");
    PlaySound("assets\\audio\\soundBytes\\broken_glass.wav", NULL, SND_ASYNC);    
  } else if(s == "7") {
    printf("7\n");
    PlaySound("assets\\audio\\soundBytes\\suicide_note.wav", NULL, SND_ASYNC);  
  }
}

bool intersectsWalls() {
  bool intersects = false;

  for (Wall *wall : walls)
    wall->intersects(player);

  if (!apartmentDoor.isOpen()) {
    intersects |= apartmentDoor.intersects(player);
  }
  if (!bedroomDoor.isOpen()) {
    intersects |= bedroomDoor.intersects(player);
  }
  if (!bathroomDoor.isOpen()) {
    intersects |= bathroomDoor.intersects(player);
  }

  for (Object *furniture : livingroom)
    furniture->intersects(player);

  for (Object *furniture : kitchen)
    furniture->intersects(player);

  for (Object *furniture : bedroom)
    furniture->intersects(player);

  for (Object *furniture : bathroom)
    furniture->intersects(player);

  return intersects;
  // return false;
}

void interactionTimer(int val)
{
  if (gameState == INTERACTING_STATE)
  {
    (*clues[interactingObject]).rotate();
    glutPostRedisplay();
    glutTimerFunc(20, interactionTimer, 0);
  }
}

void setClueType(int idx)
{
  int lenClues = (sizeof(cluesAnswer) / sizeof(int));

  if (idx >= lenClues || !(*clues[idx]).isFound())
  {
    return;
  }
  // printf("%d %d %d\n", gameState, idx, (*clues[idx]).getState());
  //set the clue type here
  bool win = true;
  (*clues[idx]).setState((*clues[idx]).getState() == 1 ? -1 : 1);
  for (int i = 0; i < lenClues; i++)
  {
    if ((*clues[i]).getState() != cluesAnswer[i])
    {
      win = false;
      break;
    }
  }
  journal.write(idx, (*clues[idx]).getState());
  gameState = win == true ? WINNING_STATE : gameState;
  glutPostRedisplay();
}

void mouseOverJournal(int button, int state, int x, int y)
{
  if (gameState == JOURNAL_STATE)
  {
    glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
    glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
      if (x < 550)
      {
        if (y < 110 && y > 20)
        {
          setClueType(0);
        }
        else if (y < 220 && y > 120)
        {
          setClueType(1);
        }
        else if (y < 325 && y > 225)
        {
          setClueType(2);
        }
        else if (y < 450 && y > 335)
        {
          setClueType(3);
        }
        else if (y < 575 && y > 455)
        {
          setClueType(4);
        }
      }
      else
      {
        if (y < 110 && y > 20)
        {
          setClueType(5);
        }
        else if (y < 220 && y > 120)
        {
          setClueType(6);
        }
        else if (y < 325 && y > 225)
        {
          setClueType(7);
        }
        else if (y < 450 && y > 335)
        {
          setClueType(8);
        }
        else if (y < 575 && y > 455)
        {
          setClueType(9);
        }
      }
    }
  }
}

void losingStateCaller(int val)
{
  if (gameState != WINNING_STATE)
  {
    gameState = LOSING_STATE;
    printf("koko lost\n");
  }
  glutPostRedisplay();
}

void openDoor(int val)
{
  if (val == 0)
  {
    apartmentDoor.openDoor();
    if (!apartmentDoor.isOpen())
    {
      glutTimerFunc(0, openDoor, 0);
    }
  }
  else if (val == 1)
  {
    bedroomDoor.openDoor();
    if (!bedroomDoor.isOpen())
    {
      glutTimerFunc(0, openDoor, 1);
    }
  }
  else if (val == 2)
  {
    bathroomDoor.openDoor();
    if (!bathroomDoor.isOpen())
    {
      glutTimerFunc(0, openDoor, 2);
    }
  }
}

void closeDoor(int val)
{
  if (val == 0)
  {
    apartmentDoor.closeDoor();
    if (apartmentDoor.isOpen())
    {
      glutTimerFunc(0, closeDoor, 0);
    }
  }
  else if (val == 1)
  {
    bedroomDoor.closeDoor();
    if (bedroomDoor.isOpen())
    {
      glutTimerFunc(0, closeDoor, 1);
    }
  }
  else if (val == 2)
  {
    bathroomDoor.closeDoor();
    if (bathroomDoor.isOpen())
    {
      glutTimerFunc(0, closeDoor, 2);
    }
  }
}