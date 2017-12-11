#include <headerFiles/GL/glut.h>

class Lights
{
public:
    // Function to initiate lighting
    static void initLightSource()
    {
        // Enable Lighting for this OpenGL Program
        glEnable(GL_LIGHTING);

        // Enable Light Source number 0
        // OpengL has 8 light sources
        glEnable(GL_LIGHT0);

        // Define Light source 0 ambient light
        GLfloat ambient[] = { 0.1f, 0.1f, 0.1, 1.0f };
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

        // Define Light source 0 diffuse light
        GLfloat diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

        // Define Light source 0 Specular light
        GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

        // Finally, define light source 0 position in World Space
        GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    }
    // Function to set up lights for the scene.
    static void setupLights()
    {
        GLfloat lightIntensity[] = { 0.01, 0.01, 0.01, 1.0f };
	    GLfloat lightPosition[] = {0.0f, 100.0f, 0.0f, 0.0f };
	    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	    glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);
    }
};