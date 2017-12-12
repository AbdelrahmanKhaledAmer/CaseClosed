#ifndef OBJECT_H
#define OBJECT_H

#include "headerFiles/GLTexture.h"
#include "headerFiles/Model_3DS.h"
#include <Eigen/Dense>
#include <headerFiles/GL/glut.h>

using namespace Eigen;

class Object
{
public:
    // Main functions
    Object(Vector3f location, Vector3f orientation, Vector3f scale, Vector3f dimensions);   // Constructor
    ~Object();                                                                              // Destructor

    // Getteres and Setters
    Vector3f location();                // Get Location
    Vector3f orientation();             // Get Orientation
    Vector3f scale();                   // Get Scale
    Vector3f dimensions();              // Get Dimensions

    // Setters
    void setLocation(Vector3f location);        //Set Location
    void setOrientation(Vector3f orientation);  //Set Orientation
    void setScale(Vector3f scale);              //Set Scale
    void setDimension(Vector3f dimensions);     //Set Dimensions
	void setModel(char * modelPath);            //Set Model

    // Game logic functions
    bool intersects(Object object); // Check overlapping objects
    void draw(float locScale = 1);  // Draw Objects
    void drawBoundries(float xLength, float yLength, float zLength);   // Draw Object Boundries
    void rotate(float step = 1);    // Rotate an object
protected:
    Model_3DS model_;
    Vector3f location_;     // Current Object location
    Vector3f orientation_;  // Current object rotation (angle rotated along every axis)
    Vector3f scale_;        // Current object size (scale factor along every axis)
    Vector3f dimensions_;   // Current object dimensions (length along every axis)
};

#endif