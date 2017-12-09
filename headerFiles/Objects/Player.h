#ifndef PLAYER_H
#define PLAYER_H

#include <Eigen/Dense>
#include "headerFiles/Camera.h"
#include "headerFiles/Objects/Object.h"

using namespace Eigen;

class Player : public Object
{
public:
    // Main functions
    Player(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions, Camera camera);    // Constructor
    ~Player();                                                                                              // Destructor

    // Getters and Setters
    Camera getCamera();

    // Motion functions
    void moveForward(float scale = 1);
    void moveBackward(float scale = 1);
    void moveLeft(float scale = 1);
    void moveRight(float scale = 1);

    // Look functions
    void lookRight(float scale = 1);
    void lookLeft(float scale = 1);
    void lookUp(float scale = 1);
    void lookDown(float scale = 1);
protected:
    Camera head_;
};

#endif