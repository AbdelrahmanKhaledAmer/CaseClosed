#include "headerFiles/Objects/Object.h"
#include <iostream>

/*
    Constructor for the Object object.
    Returns a pointer for an Object.

    @param (location) The current location of the Object with respect to the global origin.
    @param (orientation) The current rotation angles across all three axes.
    @param (scale) The amount to scale across all three axes.
    @param (dimensions) The length of the object along every axis before scaling.

    @return: Pointer to Object object
*/
Object::Object(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions)
{
    this->location_ = location;
    this->orientation_ = orientation;
    this->scale_ = scale;
    this->dimensions_ = Vector3f(dimensions.x() * scale.x(), dimensions.y() * scale.y(), dimensions.z() * scale.z());
}

/**
    Destructor for the Object object.
    Deletes the pointer for the Object object.
*/
Object::~Object()
{

}

/**
    Getter Function.
    Returns the current location of the Object object.
*/
Vector3f Object::location()
{
    return this->location_;
}

/**
    Getter Function.
    Returns the current rotation data of the Object object.
*/
Vector3f Object::orientation()
{
    return this->orientation_;
}

/**
    Getter Function.
    Returns the current scaling data of the Object object.
*/
Vector3f Object::scale()
{
    return this->scale_;
}

/**
    Getter Function.
    Returns the current size of the Object object.
*/
Vector3f Object::dimensions()
{
    return this->dimensions_;
}

/**
    Setter Function.
    Sets the current model of the Object object.
*/
void Object::setModel(char *modelPath) {
	model_.Load(modelPath);	
}

/**
    OpenGL drawing function.
    Draws an Object on the screen. To be Overridden by the subclasses.
*/
void Object::draw(float locScale) {
  glPushMatrix();
  {
    glTranslatef(location_.x() / locScale, location_.y() / locScale, location_.z() / locScale);
    glScalef(scale_.x(), scale_.y(), scale_.z());
    glRotatef(orientation_.y(), 0, 1, 0);
    model_.Draw();
  }
  glPopMatrix();
}

/**
    OpenGL drawing function.
    Draws an Object's boundries on the screen. To be Overridden by the subclasses.
*/
void Object::drawBoundries(float xLength, float yLength, float zLength) {
  glColor3f(1.0, 1.0, 1.0);
  glColor3f(1.0, 0, 0);
  glPushMatrix();
  {
    glTranslatef(location_.x(), location_.y(), location_.z());
    glScalef(xLength, yLength, zLength);
    glTranslatef(0, 0.5f, 0);
    glutSolidCube(1);
  }
  glPopMatrix();
  glColor3f(1.0, 1.0, 1.0);
}

/**
    Collision logic function.
    Detects if an object occupies the same space as another.

    @param (object) The object to which the subject is being compared with

    @return: true if the objects collide, false otherwise.
*/
bool Object::intersects(Object object)
{
    float obj1XMin = this->location_.x() - this->dimensions_.x()/2;
    float obj1XMax = this->location_.x() + this->dimensions_.x()/2;
    float obj1YMin = this->location_.y() - this->dimensions_.y()/2;
    float obj1YMax = this->location_.y() + this->dimensions_.y()/2;
    float obj1ZMin = this->location_.z() - this->dimensions_.z()/2;
    float obj1ZMax = this->location_.z() + this->dimensions_.z()/2;
    float obj2XMin = object.location_.x() - object.dimensions_.x()/2;
    float obj2XMax = object.location_.x() + object.dimensions_.x()/2;
    float obj2YMin = object.location_.y() - object.dimensions_.y()/2;
    float obj2YMax = object.location_.y() + object.dimensions_.y()/2;
    float obj2ZMin = object.location_.z() - object.dimensions_.z()/2;
    float obj2ZMax = object.location_.z() + object.dimensions_.z()/2;
    bool intersectsX = (obj1XMin >= obj2XMin && obj1XMin <= obj2XMax) || (obj1XMax >= obj2XMin && obj1XMax <= obj2XMax);
    bool intersectsY = (obj1YMin >= obj2YMin && obj1YMin <= obj2YMax) || (obj1YMax >= obj2YMin && obj1YMax <= obj2YMax);
    bool intersectsZ = (obj1ZMin >= obj2ZMin && obj1ZMin <= obj2ZMax) || (obj1ZMax >= obj2ZMin && obj1ZMax <= obj2ZMax);
    return intersectsX && intersectsY && intersectsZ;
}

void Object::rotate(float scale)
{
    this->orientation_.y() += scale;
}