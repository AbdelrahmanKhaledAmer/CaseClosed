#include <glut.h>

class Axes
{
private:
    const int font = (int)GLUT_BITMAP_9_BY_15;
public:
    static void writeString(float x, float y, float z, void *font, const char *line)
    {
        glPushMatrix();
        const char *c;
        glRasterPos3f(x, y, z);
        for (c = line; *c != '\0'; c++)
        {
            glutBitmapCharacter(font, *c);
        }
        glPopMatrix();
    }
    Axes(float length)
    {
	    glLineWidth(1);
        //x-axis
	    glBegin(GL_LINES);
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f(length, 0.0f, 0.0f);
            glVertex3f(-length, 0.0f, 0.0f);
        }
        glEnd();
        glPushMatrix();
        {
            glTranslatef(length, 0.0f, 0.0f);
            glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
            glutSolidCone(length * 0.02, length * 0.09, 50, 50);
        }
        glPopMatrix();
        glPushMatrix();
        {
            glTranslatef(-length, 0.0f, 0.0f);
            glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
            glutSolidCone(length * 0.02, length * 0.09, 50, 50);
        }
        glPopMatrix();
        //y-axis
        glBegin(GL_LINES);
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, length, 0.0f);
            glVertex3f(0.0f, -length, 0.0f);
        }
        glEnd();
        glPushMatrix();
        {
            glTranslatef(0.0f, 0.0f, -length);
            glRotatef(180.0f, length, 0.0f, 0.0f);
            glutSolidCone(length * 0.02, length * 0.09, 50, 50);
        }
        glPopMatrix();
        glPushMatrix();
        {
            glTranslatef(0.0f, 0.0f, length);
            glutSolidCone(length * 0.02, length * 0.09, 50, 50);
        }
        glPopMatrix();
        //z-axis
        glBegin(GL_LINES);
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, length);
            glVertex3f(0.0f, 0.0f, -length);
        }
        glEnd();
        glPushMatrix();
        {
            glTranslatef(0.0f, length, 0.0f);
            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
            glutSolidCone(length * 0.02, length * 0.09, 50, 50);
        }
        glPopMatrix();
        glPushMatrix();
        {
            glTranslatef(0.0f, -length, 0.0f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glutSolidCone(length * 0.02, length * 0.09, 50, 50);
        }
        glPopMatrix();
        glColor3f(1.0, 0.0, 0.0);
        writeString(length, 0.0f, 0.0f, (void *)font, "x-axis");
        writeString(0.0f, length, 0.0f, (void *)font, "y-axis");
        writeString(0.0f, 0.0f, length, (void *)font, "z-axis");
    }
    ~Axes() { }
};