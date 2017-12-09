#include "headerFiles/Objects/Object.h"

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
    return this->dimensions_;
}

/**
    Getter Function.
    Returns the current rotation data of the Object object.
*/
Vector3f Object::orientation()
{
    return this->dimensions_;
}

/**
    Getter Function.
    Returns the current scaling data of the Object object.
*/
Vector3f Object::scale()
{
    return this->dimensions_;
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
void Object::setModel(Model_3DS model){
    this->model_ = model;
}

/**
    OpenGL drawing function.
    Draws an Object on the screen. To be Overridden by the subclasses.
*/
void Object::draw()
{
    model_.Draw();
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