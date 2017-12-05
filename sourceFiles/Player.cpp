#include "headerFiles/Player.h"

/*
    Constructor for the Player object.
    Returns a pointer for a player.

    @param (location) The current location of the Player with respect to the global origin.
    @param (orientation) The current rotation angles across all three axes.
    @param (scale) The amount to scale across all three axes.
    @param (dimensions) The length of the object along every axis before scaling.
    @param (camera) The first person camera that will act as the Player's head

    @return: Pointer to Object object
*/
Player::Player(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions, Camera camera):Object(location, orientation, scale, dimensions)
{
    this->head_ = camera;
}

/**
    Destructor for the Player object.
    Deletes the pointer for the Player object.
*/
Player::~Player()
{

}

/**
    Translation Function.
    Moves the player one step forward

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Player::moveForward(float scale)
{
    head_.translateForward(scale);
    location_ = head_.location();
}

/**
    Translation Function.
    Moves the player one step backward

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Player::moveBackward(float scale)
{
    head_.translateBackward(scale);
    location_ = head_.location();
}

/**
    Translation Function.
    Moves the player one step to the right

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Player::moveRight(float scale)
{
    head_.translateRight(scale);
    location_ = head_.location();
}

/**
    Translation Function.
    Moves the player one step to the left

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Player::moveForward(float scale)
{
    head_.translateLeft(scale);
    location_ = head_.location();
}

/**
    Rotation Function.
    Rotates the player's head to look slightly more to the right.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Player::lookRight(float scale)
{
    head_.rotateRight(scale);
}

/**
    Rotation Function.
    Rotates the player's head to look slightly more to the left.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Player::lookLeft(float scale)
{
    head_.rotateLeft(scale);
}

/**
    Rotation Function.
    Rotates the player's head to look slightly more upward.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Player::lookUp(float scale)
{
    head_.rotateUp(scale);
    // TODO add limit
}

/**
    Rotation Function.
    Rotates the player's head to look slightly downwards.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Player::lookDown(float scale)
{
    head_.rotateDown(scale);
    // TODO add limit
}