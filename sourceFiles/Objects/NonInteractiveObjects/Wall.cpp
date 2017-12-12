#include "headerFiles/Objects/NonInteractiveObjects/Wall.h"

/*
    Constructor for the Wall object.
    Returns a pointer for a Wall.

    @param (location) The current location of the Sofa with respect to the
   global origin.
    @param (orientation) The current rotation angles across all three axes.
    @param (scale) The amount to scale across all three axes.
    @param (dimensions) The length of the object along every axis before
   scaling.

    @return: Pointer to Wall Object.
*/
Wall::Wall(Vector3f location, Vector3f orientation, Vector3f scale,
           Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions) {}

/**
    Destructor for the Sofa object.
    Deletes the pointer for the Sofa object.
*/
Wall::~Wall() {}

/**
    Drawing fuction.
    Draws the Wall object as a cuboid.

    @Override
*/

void Wall::drawBox(GLfloat size, GLenum type)
{
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

  for (i = 5; i >= 0; i--) {
    glBegin(type);
    glNormal3fv(&n[i][0]);
    glTexCoord2f(0, 0);                 glVertex3fv(&v[faces[i][0]][0]);
    glTexCoord2f(dimensions_.z(), 0);   glVertex3fv(&v[faces[i][1]][0]);
    glTexCoord2f(dimensions_.z(), 2);   glVertex3fv(&v[faces[i][2]][0]);
    glTexCoord2f(0, 2);                 glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

void Wall::gluCube(GLdouble size)
{
  drawBox(size, GL_QUADS);
}

void Wall::draw() {
  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glRotatef(orientation_.z(), 0.0f, 0.0f, 1.0f);
    glRotatef(orientation_.y(), 0.0f, 1.0f, 0.0f);
    glRotatef(orientation_.x(), 1.0f, 0.0f, 0.0f);
    glTranslatef(dimensions_.x() / 2, dimensions_.y() / 2, dimensions_.z() / 2);
    glScalef(dimensions_.x(), dimensions_.y(), dimensions_.z());

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth_, imageHeight_, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluCube(1);
    glDisable(GL_TEXTURE_2D);
  }
  glPopMatrix();
}

void Wall::setTexture(char* imagePath) { 
  // texture_ = SOIL_load_OGL_texture(
  //  	imagePath, 
  //   SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
  //   SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT |SOIL_FLAG_MULTIPLY_ALPHA
  // );
  image_ = SOIL_load_image(imagePath, &imageWidth_, &imageHeight_, 0, SOIL_LOAD_RGBA);
}

/**
    Collision logic function.
    Detects if an object occupies the same space as another.

    @param (object) The object to which the subject is being compared with

    @return: true if the objects collide, false otherwise.

    @Override
*/
bool Wall::intersects(Object object) {
  float obj1XMax, obj1ZMax;
  float obj1XMin = this->location_.x();
  float obj1YMin = this->location_.y();
  float obj1ZMin = this->location_.z();
  float obj1YMax = this->location_.y() + this->dimensions_.y();
  if (this->orientation_.y() > -0.5 && this->orientation_.y() < 0.5) {
    // printf("No Rotation\n");
    obj1XMax = this->location_.x() + this->dimensions_.x();
    obj1ZMax = this->location_.z() + this->dimensions_.z();
  } else {
    // printf("Rotation\n");
    obj1XMax = this->location_.x() + this->dimensions_.z();
    obj1ZMax = this->location_.z() - this->dimensions_.x();
  }
  float obj2XMin = object.location().x() - object.dimensions().x() / 2;
  float obj2XMax = object.location().x() + object.dimensions().x() / 2;
  float obj2YMin = object.location().y() - object.dimensions().y() / 2;
  float obj2YMax = object.location().y() + object.dimensions().y() / 2;
  float obj2ZMin = object.location().z() - object.dimensions().z() / 2;
  float obj2ZMax = object.location().z() + object.dimensions().z() / 2;
  bool intersectsX = (obj1XMin >= obj2XMin && obj1XMin <= obj2XMax) ||
                     (obj1XMax >= obj2XMin && obj1XMax <= obj2XMax) ||
                     (obj2XMin >= obj1XMin && obj2XMin <= obj1XMax) ||
                     (obj2XMax >= obj1XMin && obj2XMax <= obj1XMax);
  bool intersectsY = (obj1YMin >= obj2YMin && obj1YMin <= obj2YMax) ||
                     (obj1YMax >= obj2YMin && obj1YMax <= obj2YMax) ||
                     (obj2YMin >= obj1YMin && obj2YMin <= obj1YMax) ||
                     (obj2YMax >= obj1YMin && obj2YMax <= obj1YMax);
  bool intersectsZ = (obj1ZMin >= obj2ZMin && obj1ZMin <= obj2ZMax) ||
                     (obj1ZMax >= obj2ZMin && obj1ZMax <= obj2ZMax) ||
                     (obj2ZMin >= obj1ZMin && obj2ZMin <= obj1ZMax) ||
                     (obj2ZMax >= obj1ZMin && obj2ZMax <= obj1ZMax);
  return intersectsX && intersectsY && intersectsZ;
}