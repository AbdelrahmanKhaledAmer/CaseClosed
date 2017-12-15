#include "headerFiles/Include.h"
#include "headerFiles/InitGame.h"
#include "headerFiles/LoadGame.h"
#include "headerFiles/Draw.h"
#include "headerFiles/GameLogic.h"
#include "headerFiles/Controls.h"

void initFlashLight()
{
  //GLfloat lmodel_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
  //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

  //
  glEnable(GL_LIGHT1);
  Vector3f viewVec = (player.getCamera().lookAt() - player.location()).normalized();
  Vector3f diff(viewVec.x() * 0.2, -0.2, viewVec.z() * 0.2);
  flashlight.setLocation(player.location() + viewVec * 0.7 - diff);

  //Vector3f upVector = player.getCamera().Upvector();
  //Vector3f eye = player.getCamera().location().normalized();
  //Vector3f ViewCross = viewVec.cross(upVector).normalized();
  GLfloat l1Diffuse[] = {1.0f, 0.0f, 0.0f, 1.0f};
  GLfloat l1Ambient[] = {1.0f, 0.0f, 0.0f, 1.0f};
  GLfloat l1Position[] = {player.location().x(), player.location().y(), player.location().z(), true};
  //GLfloat l1Position[] = {eye.x(),eye.y(),eye.z()};
  Vector3f dir = viewVec;
  GLfloat l1Direction[] = {dir.x(), dir.y(), dir.z()};
  GLfloat lightIntensity[] = {5, 5, 5, 1.0f};
  glLightfv(GL_LIGHT1, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT1, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT1, GL_POSITION, l1Position);
  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0);
  glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT1, GL_AMBIENT, lightIntensity);
}

void initLightHere()
{
  // GLfloat lmodel_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
  // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
  // Vector3f viewVec=(player.getCamera().lookAt() - player.location()).normalized();
  // Vector3f upVector = player.getCamera().Upvector();
  // Vector3f eye = player.getCamera().location().normalized();
  // Vector3f ViewCross = viewVec.cross(upVector).normalized();

  // CellingLight livingroomLight(Vector3f(24.4, 2.25, 10.38), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  // CellingLight kitchenLight(Vector3f(22.04, 2, 6.89), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  // CellingLight1 bathroomLight(Vector3f(26.68, 2.25, 13.3), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  // Fan bedroomFan(Vector3f(22.79, 2.5, 14.57), Vector3f(0, 0, 0), Vector3f(1, 1, 1));
  GLfloat l1Diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat l1Ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat l1Position[] = {22.04, 2, 6.89, true};
  GLfloat l2position[] = {24.4, 2, 10.38, true};
  GLfloat l3position[] = {26.68, 2, 13.3, true};
  GLfloat l4position[] = {22.79, 2, 14.57, true};
  //GLfloat l1Position[] = {eye.x(),eye.y(),eye.z()};
  // Vector3f dir = viewVec;
  GLfloat l1Direction[] = {0, -1, 0};
  GLfloat lightIntensity[] = {5, 5, 5, 1.0f};

  float cutoff = 30;
  //light2
  glLightfv(GL_LIGHT2, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT2, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT2, GL_POSITION, l1Position);
  glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, cutoff);
  //glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT2, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT2, GL_ATTENUATION_EXT, lightIntensity);

  //light3
  glLightfv(GL_LIGHT3, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT3, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT3, GL_POSITION, l2position);
  glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, cutoff + 30);
  //glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT3, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT3, GL_ATTENUATION_EXT, lightIntensity);

  //light4
  glLightfv(GL_LIGHT4, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT4, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT4, GL_POSITION, l3position);
  glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, cutoff + 10);
  glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT4, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT4, GL_ATTENUATION_EXT, lightIntensity);

  //light5
  glLightfv(GL_LIGHT5, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT5, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT5, GL_POSITION, l4position);
  glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, cutoff + 30);
  glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT5, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT5, GL_ATTENUATION_EXT, lightIntensity);
}

void journalLight()
{
  GLfloat l1Diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat l1Ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};

  GLfloat l1Position[] = {4.96,1.0,22.37,true};
  // Vector3f dir = viewVec;
  //GLfloat l1Direction[] = {-0.17,0.06,-0.98};
  GLfloat l1Direction[] = {-0,0,-1};
  GLfloat lightIntensity[] = {5, 5, 5, 1.0f};

  float cutoff = 30;
  //light2
  glLightfv(GL_LIGHT6, GL_DIFFUSE, l1Diffuse);
  glLightfv(GL_LIGHT6, GL_AMBIENT, l1Ambient);
  glLightfv(GL_LIGHT6, GL_POSITION, l1Position);
  glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, cutoff);
  //glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 90.0);
  glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, l1Direction);

  glLightfv(GL_LIGHT6, GL_INTENSITY, lightIntensity);
  glLightfv(GL_LIGHT6, GL_ATTENUATION_EXT, lightIntensity);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Set the camera
  if (enableFlashLight)
  {
    initFlashLight();
  } else {
    glDisable(GL_LIGHT1);
  }
  initLightHere();
  //glDisable(GL_LIGHT6);
  if (gameState == JOURNAL_STATE || gameState == WINNING_STATE || gameState == LOSING_STATE)
  {
    glEnable(GL_LIGHT6);
    journalLight();
    jCam.setup();
    if (gameState == WINNING_STATE)
    {
      winDraw();
      glFlush();
    } else if (gameState == LOSING_STATE) {
      loseDraw();
      glFlush();
    }
  } else {
    player.getCamera().setup();
    // camera.setup();    
  }

  // Axes for modeling
  //Axes axes(0.5);

  // Reset color and flush buffer
  glColor3f(1.0, 1.0, 1.0);

  Vector3f viewVec = (player.getCamera().lookAt() - player.location()).normalized();
  Vector3f xAxis(1, 0, 0);
  Vector3f zAxis(0, 0, 1);
  float angle = acos((viewVec.dot(xAxis)) / viewVec.norm()) * 180 / PI;
  float check = acos((viewVec.dot(zAxis)) / viewVec.norm()) * 180 / PI;
  glPushMatrix();
  {
    if (check < 90)
    {
      flashlight.draw(90 - angle);
    } else {
      flashlight.draw(90 + angle);
    }
    if(gameState != WINNING_STATE && gameState != LOSING_STATE)
    {
      journal.draw();
    }
    drawApartment();
    drawClues();
    // drawHitBoxes();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslated(1, 0.5, 1);
  glutSolidCube(0.1);
  glPopMatrix();

  glPushMatrix();
  Vector3f viewVec2 = ((player.getCamera().lookAt() - player.location()).normalized()) * 1.5;
  Vector3f loc = player.location();
  Vector3f Upvector = player.getCamera().upVector();
  Vector3f crossV = viewVec2.cross(Upvector);
  //the required plane is the plane between the up and cross vector
  glColor3f(1, 0, 0);
  glBegin(GL_QUADS);
  {
    glNormal3f(0, 1, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0, -1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1, 0.5, -1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1, 0.5, -2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1, 0, -2);
  }
  glEnd();
  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowSize(width, height);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Game Title");

  glutDisplayFunc(display);
  glutKeyboardFunc(key);
  glutPassiveMotionFunc(mouseMovement);

  glClearColor(1, 1, 1, 0);
  initEnvironment();
  initClues();
  loadAssets();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glEnable(GL_LIGHT4);
  glEnable(GL_LIGHT5);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);
  glShadeModel(GL_SMOOTH);

  GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat shinness[] = {100};
  GLfloat lDiffuse[] = {0.1f, 0.1f, 0.1f, 1.0f};
  GLfloat lAmbient[] = {0.1f, 0.1f, 0.1f, 1.0f};
  glMaterialfv(GL_FRONT, GL_AMBIENT, lAmbient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, lDiffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shinness);
  glDisable(GL_COLOR_MATERIAL);

  glutTimerFunc(1000 * 60 * 10, losingStateCaller, 0);
  glutIdleFunc(idle);
  glutMouseFunc(mouseOverJournal);

  glutMainLoop();
}