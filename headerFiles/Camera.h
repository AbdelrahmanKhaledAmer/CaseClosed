#ifndef CAMERA_H
#define CAMERA_H

#include <Eigen/Dense>
#include <headerFiles/GL/glut.h>

using namespace Eigen;

class Camera
{
public:
    // Main Functions
    Camera();                                                     // Default Constructor
    Camera(Vector3f eye, Vector3f lookAt, Vector3f orientation); // Constructor
    ~Camera();                                                   // Destructor
    void setup();                                                // Setup

    // Getters and Setters
    Vector3f location();    // Get Location

    // Rotation Functions
    void rotateRight(float scale = 1);  // Horizontal rotation
    void rotateLeft(float scale = 1);   // Horizontal rotation
    void rotateUp(float scale = 1);     // Vertical rotation
    void rotateDown(float scale = 1);   // Vertical rotation
    void tiltRight(float scale = 1);    // Sideways rotation
    void tiltLeft(float scale = 1);     // Sideways rotation

    // Translation Functions
    void translateForward(float scale = 1); // Translate to the front
    void translateBackward(float scale = 1);// Translate to the back
    void translateLeft(float scale = 1);    // Translate to the left
    void translateRight(float scale = 1);   // Translate to the right
    void translateUp(float scale = 1);      // Translate to the top
    void translateDown(float scale = 1);    // Translate to the bottom

    // Other Functions
    void reset();
private:
    Vector3f eye_;                              // Current camera loaction
    Vector3f lookAt_;                           // Current Camera target
    Vector3f orientation_;                      // Current camera upwards direction
    float translationStep_ = 0.1;               // How much to move in any direction
    float rotationAngle_ = 0.0174532925199433;  // How much to rotate on any axis
};

#endif