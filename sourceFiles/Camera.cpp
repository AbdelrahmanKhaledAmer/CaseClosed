#include <headerFiles/Camera.h>

/**
    Constructor for the Camera object.
    Returns a pointer for a camera.

    @param (eye) The current location of the camera with respect to the global origin.
    @param (lookAt) The coordinate currently at the center of the screen with respect to the global origin.
    @param (orientation) A vector determining which direction is considered upright for the camera.

    @return: Pointer to camera object
*/
Camera::Camera(Vector3f eye, Vector3f lookAt, Vector3f orientation)
{
    this->eye_ = eye;
    this->lookAt_ = lookAt;
    this->orientation_ = orientation;
}

/**
    Destructor for the Camera object.
    Deletes the pointer for the Camera object.
*/
Camera::~Camera()
{
    
}

/**
    Setup function.
    Should be called whenever any camera variable changes.
*/
void Camera::setup()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 16 / 9.0, 0.001, 200);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_.x(), eye_.y(), eye_.z(), lookAt_.x(), lookAt_.y(), lookAt_.z(), orientation_.x(), orientation_.y(), orientation_.z());
}

/**
    Getter Function.
    Returns the current location of the Camera object.
*/
Vector3f Camera::location()
{
    return this->eye_;
}

/**
    Rotation Function.
    Rotates the Camera object by the preset angular step along the Camera's y axis. This is done by changing the lookAt_ variable.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::rotateRight(float scale)
{
    float theta = rotationAngle_ * scale / 2;
    Quaternionf rotAxis(theta, orientation_.x(), orientation_.y(), orientation_.z());
    rotAxis.normalize();
    Quaternionf VectorToRotate;
    VectorToRotate.w() = 0;
    VectorToRotate.vec() = eye_ - lookAt_;
    lookAt_ = eye_ + (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
    Quaternionf rotAxis2(theta, orientation_.x(), orientation_.y(), orientation_.z());
    rotAxis2.normalize();
    Quaternionf VectorToRotate2;
    VectorToRotate2.w() = 0;
    VectorToRotate2.vec() = eye_ - lookAt_;
    lookAt_ = eye_ + (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
}

/**
    Rotation Function.
    Rotates the Camera object by the preset angular step along the Camera's y axis. This is done by changing the lookAt_ variable.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::rotateLeft(float scale)
{
    float theta = - rotationAngle_ * scale / 2;
    Quaternionf rotAxis(theta, orientation_.x(), orientation_.y(), orientation_.z());
    rotAxis.normalize();
    Quaternionf VectorToRotate;
    VectorToRotate.w() = 0;
    VectorToRotate.vec() = eye_ - lookAt_;
    lookAt_ = eye_ + (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
    Quaternionf rotAxis2(theta, orientation_.x(), orientation_.y(), orientation_.z());
    rotAxis2.normalize();
    Quaternionf VectorToRotate2;
    VectorToRotate2.w() = 0;
    VectorToRotate2.vec() = eye_ - lookAt_;
    lookAt_ = eye_ + (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
}

/**
    Rotation Function.
    Rotates the Camera object by the preset angular step along the Camera's x axis. This is done by changing the lookAt_ variable.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::rotateUp(float scale)
{
    float theta = -rotationAngle_ * scale / 2;
    Vector3f newX = orientation_.cross(eye_ - lookAt_);
    Quaternionf rotAxis(theta, newX.x(), newX.y(), newX.z());
    rotAxis.normalize();
    Quaternionf VectorToRotate;
    VectorToRotate.w() = 0;
    VectorToRotate.vec() = eye_ - lookAt_;
    lookAt_ = eye_ + (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
    Quaternionf rotAxis2(theta, newX.x(), newX.y(), newX.z());
    rotAxis2.normalize();
    Quaternionf VectorToRotate2;
    VectorToRotate2.w() = 0;
    VectorToRotate2.vec() = eye_ - lookAt_;
    lookAt_ = eye_ + (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
}

/**
    Rotation Function.
    Rotates the Camera object by the preset angular step along the Camera's x axis. This is done by changing the lookAt_ variable.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::rotateDown(float scale)
{
    float theta = rotationAngle_ * scale / 2;
    Vector3f newX = orientation_.cross(eye_ - lookAt_);
    Quaternionf rotAxis(theta, newX.x(), newX.y(), newX.z());
    rotAxis.normalize();
    Quaternionf VectorToRotate;
    VectorToRotate.w() = 0;
    VectorToRotate.vec() = eye_ - lookAt_;
    lookAt_ = eye_ + (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
    Quaternionf rotAxis2(theta, newX.x(), newX.y(), newX.z());
    rotAxis2.normalize();
    Quaternionf VectorToRotate2;
    VectorToRotate2.w() = 0;
    VectorToRotate2.vec() = eye_ - lookAt_;
    lookAt_ = eye_ + (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
}

/**
    Rotation Function.
    Rotates the Camera object by the preset angular step along the Camera's z axis. This is done by changing the orientation_ variable.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::tiltRight(float scale)
{
    float theta = rotationAngle_ * scale / 2;
    Vector3f newZ = eye_ - lookAt_;
    Quaternionf rotAxis(theta, newZ.x(), newZ.y(), newZ.z());
    rotAxis.normalize();
    Quaternionf VectorToRotate;
    VectorToRotate.w() = 0;
    VectorToRotate.vec() = orientation_;
    orientation_ = (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
    Quaternionf rotAxis2(theta, newZ.x(), newZ.y(), newZ.z());
    rotAxis2.normalize();
    Quaternionf VectorToRotate2;
    VectorToRotate2.w() = 0;
    VectorToRotate2.vec() = orientation_;
    orientation_ = (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
}

/**
    Rotation Function.
    Rotates the Camera object by the preset angular step along the Camera's z axis. This is done by changing the orientation_ variable.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::tiltLeft(float scale)
{
    float theta = -rotationAngle_ * scale / 2;
    Vector3f newZ = eye_ - lookAt_;
    Quaternionf rotAxis(theta, newZ.x(), newZ.y(), newZ.z());
    rotAxis.normalize();
    Quaternionf VectorToRotate;
    VectorToRotate.w() = 0;
    VectorToRotate.vec() = orientation_;
    orientation_ = (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
    Quaternionf rotAxis2(theta, newZ.x(), newZ.y(), newZ.z());
    rotAxis2.normalize();
    Quaternionf VectorToRotate2;
    VectorToRotate2.w() = 0;
    VectorToRotate2.vec() = orientation_;
    orientation_ = (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
}

/**
    Translation Function.
    Transaltes the Camera object by the translation step along the Camera's z axis. This is done by changing the eye_ and lookAt_ variables.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::translateForward(float scale)
{
    float step = translationStep_ * scale;
    Vector3f direction = (lookAt_ - eye_).normalized();
    direction *= step;
    direction.y() = 0;
    eye_ += direction;
    lookAt_ += direction;
}

/**
    Translation Function.
    Transaltes the Camera object by the translation step along the Camera's z axis. This is done by changing the eye_ and lookAt_ variables.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::translateBackward(float scale)
{
    float step = translationStep_ * scale;
    Vector3f direction = (lookAt_ - eye_).normalized();
    direction *= step;
    direction.y() = 0;
    eye_ -= direction;
    lookAt_ -= direction;
}

/**
    Translation Function.
    Transaltes the Camera object by the translation step along the Camera's x axis. This is done by changing the eye_ and lookAt_ variables.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::translateLeft(float scale)
{
    float step = translationStep_ * scale;
    Vector3f direction = (orientation_.cross(lookAt_ - eye_)).normalized();
    direction *= step;
    direction.y() = 0;
    eye_ += direction;
    lookAt_ += direction;
}

/**
    Translation Function.
    Transaltes the Camera object by the translation step along the Camera's x axis. This is done by changing the eye_ and lookAt_ variables.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::translateRight(float scale)
{
    float step = translationStep_ * scale;
    Vector3f direction = (orientation_.cross(lookAt_ - eye_)).normalized();
    direction *= step;
    direction.y() = 0;
    eye_ -= direction;
    lookAt_ -= direction;
}

/**
    Translation Function.
    Transaltes the Camera object by the translation step along the Camera's y axis. This is done by changing the eye_ and lookAt_ variables.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::translateUp(float scale)
{
    float step = translationStep_ * scale;
    Vector3f direction = (orientation_).normalized();
    direction *= step;
    direction.x() = 0;
    direction.z() = 0;
    eye_ += direction;
    lookAt_ += direction;
}

/**
    Translation Function.
    Transaltes the Camera object by the translation step along the Camera's y axis. This is done by changing the eye_ and lookAt_ variables.

    @param (scale) a variable to determine the magnitude of the motion (default is 1)
*/
void Camera::translateDown(float scale)
{
    float step = translationStep_ * scale;
    Vector3f direction = (orientation_).normalized();
    direction *= step;
    direction.x() = 0;
    direction.z() = 0;
    eye_ -= direction;
    lookAt_ -= direction;
}