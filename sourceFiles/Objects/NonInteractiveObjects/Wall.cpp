#include "headerFiles/Objects/NonInteractiveObjects/Wall.h"

/*
    Constructor for the Wall object.
    Returns a pointer for a Wall.

    @param (location) The current location of the Sofa with respect to the global origin.
    @param (orientation) The current rotation angles across all three axes.
    @param (scale) The amount to scale across all three axes.
    @param (dimensions) The length of the object along every axis before scaling.

    @return: Pointer to Wall Object.
*/

Wall::Wall(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions)
    : NonInteractiveObject(location, orientation, scale, dimensions)
{

}

/**
    Destructor for the Sofa object.
    Deletes the pointer for the Sofa object.
*/
Wall::~Wall()
{

}

/**
    Drawing fuction.
    Draws the Wall object as a cuboid.

    @Override
*/
void Wall::draw()
{
    glPushMatrix();
    {
        glTranslatef(location_.x(), location_.y(), location_.z());
        glRotatef(orientation_.z(), 0.0f, 0.0f, 1.0f);
        glRotatef(orientation_.y(), 0.0f, 1.0f, 0.0f);
        glRotatef(orientation_.x(), 1.0f, 0.0f, 0.0f);
        glTranslatef(dimensions_.x() / 2 , dimensions_.y() / 2, dimensions_.z() / 2);
        glScalef(dimensions_.x(), dimensions_.y(), dimensions_.z());
        glutSolidCube(1);
    }
    glPopMatrix();
}

/**
    Collision logic function.
    Detects if an object occupies the same space as another.

    @param (object) The object to which the subject is being compared with

    @return: true if the objects collide, false otherwise.

    @Override
*/
bool Wall::intersects(Object object)
{
    float obj1XMax, obj1ZMax;
    float obj1XMin = this->location_.x();
    float obj1YMin = this->location_.y();
    float obj1ZMin = this->location_.z();
    float obj1YMax = this->location_.y() + this->dimensions_.y();
    if(this->orientation_.y() > -0.5 && this->orientation_.y() < 0.5)
    {
        // printf("No Rotation\n");
        obj1XMax = this->location_.x() + this->dimensions_.x();
        obj1ZMax = this->location_.z() + this->dimensions_.z();
    }else{
        // printf("Rotation\n");
        obj1XMax = this->location_.x() + this->dimensions_.z();
        obj1ZMax = this->location_.z() - this->dimensions_.x();
    }
    float obj2XMin = object.location().x() - object.dimensions().x()/2;
    float obj2XMax = object.location().x() + object.dimensions().x()/2;
    float obj2YMin = object.location().y() - object.dimensions().y()/2;
    float obj2YMax = object.location().y() + object.dimensions().y()/2;
    float obj2ZMin = object.location().z() - object.dimensions().z()/2;
    float obj2ZMax = object.location().z() + object.dimensions().z()/2;
    bool intersectsX = (obj1XMin >= obj2XMin && obj1XMin <= obj2XMax)
                    || (obj1XMax >= obj2XMin && obj1XMax <= obj2XMax)
                    || (obj2XMin >= obj1XMin && obj2XMin <= obj1XMax)
                    || (obj2XMax >= obj1XMin && obj2XMax <= obj1XMax);
    bool intersectsY = (obj1YMin >= obj2YMin && obj1YMin <= obj2YMax)
                    || (obj1YMax >= obj2YMin && obj1YMax <= obj2YMax)
                    || (obj2YMin >= obj1YMin && obj2YMin <= obj1YMax)
                    || (obj2YMax >= obj1YMin && obj2YMax <= obj1YMax);
    bool intersectsZ = (obj1ZMin >= obj2ZMin && obj1ZMin <= obj2ZMax)
                    || (obj1ZMax >= obj2ZMin && obj1ZMax <= obj2ZMax)
                    || (obj2ZMin >= obj1ZMin && obj2ZMin <= obj1ZMax)
                    || (obj2ZMax >= obj1ZMin && obj2ZMax <= obj1ZMax);
    return intersectsX && intersectsY && intersectsZ;
}