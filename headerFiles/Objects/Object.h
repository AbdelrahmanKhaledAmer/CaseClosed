#ifndef OBJECT_H
#define OBJECT_H

#include "headerFiles/Model_3DS.h"
#include "headerFiles/GLTexture.h"
#include <headerFiles/GL/glut.h>
#include <Eigen/Dense>

using namespace Eigen;

class Object
{
public:
    // Main functions
    Object(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions);   // Constructor
    ~Object();                                                                              // Destructor

    // Getteres and Setters
    Vector3f location();    // Get Location
    Vector3f orientation(); // Get Orientation
    Vector3f scale();       // Get Scale
    Vector3f dimensions();  // Get Dimensions
    void setModel(Model_3DS model);     // Get Model

    // Game logic functions
    bool intersects(Object object); // Check overlapping objects
    void draw();                    // Draw Objects
protected:
    Model_3DS model_;
    Vector3f location_;     // Current Object location
    Vector3f orientation_;  // Current object rotation (angle rotated along every axis)
    Vector3f scale_;        // Current object size (scale factor along every axis)
    Vector3f dimensions_;   // Current object dimensions (length along every axis)
};

#endif