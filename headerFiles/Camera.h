#include <glut.h>

class Camera
{
private:

public:
    // Function to set up all camera variables
    void setup()
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, 16 / 9.0, 0.001, 200);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        cameraPosition();
        //gluLookAt(15, 15, 15, 0.0, 10.0, 0.0, 0.0, 1.0, 0.0);
    }

    // Constructor for camera object
    Camera() { }
    // Destructor for camera object
    ~Camera() { }
    
    // Reset all variables to base values if needed
    void reset()
    {

    }
};