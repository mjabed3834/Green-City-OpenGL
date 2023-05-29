#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

float p = -0.005;
float s = -0.005;
float u = -0.005;
float m = -0.005;
float n = -0.005;
float o = -0.005;


void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i < 100; i++)

    {
        float angle = 4.0f * 3.1416f * i / 100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x + cx), (y + cy));
    }
    glEnd();

}


// Global variables for animation
GLfloat sunAngle = 0.0f;
GLfloat cloudTranslateX = -1.0f;
GLfloat cloud2TranslateX = -0.50f;
GLfloat shipTranslateX = 0.0f;
GLfloat carTranslateX = 0.0f;

// Function to draw the scene
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glMatrixMode(GL_MODELVIEW); // Switch to the modelview matrix

    glLoadIdentity(); // Load the identity matrix

    // Draw the sun
    glPushMatrix();
    glTranslatef(-0.6f, 0.7f, 0.0f);
    glRotatef(sunAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); // Set sun color to yellow
    glutSolidSphere(0.1f, 20, 20);
    glPopMatrix();

    // Draw the clouds
    glPushMatrix();
    glTranslatef(cloud2TranslateX, 0.8f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Set cloud color to white
    glutSolidSphere(0.08f, 20, 20);
    glTranslatef(0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.08f, 20, 20);
    glTranslatef(0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.08f, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudTranslateX, 0.6f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Set cloud color to white
    glutSolidSphere(0.08f, 20, 20);
    glTranslatef(0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.08f, 20, 20);
    glTranslatef(0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.08f, 20, 20);
    glPopMatrix();

    // Draw the hill
    glColor3f(0.4f, 0.75f, 0.1f); // Set hill color to green
    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 0.50f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, 0.10f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, 0.10f);
    glEnd();
    glPopMatrix();

    //hillside
    glColor3f(0.4f, 0.8f, 0.1f); // Set hill color to green
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.05f);
    glVertex2f(-1.0f, 0.20f);
    glVertex2f(1.0f, 0.20f);
    glVertex2f(1.0f, 0.05f);
    glEnd();

    // Draw the road
    glColor3f(0.2f, 0.2f, 0.2f); // Set road color to dark gray
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-1.0f, 0.05f);
    glVertex2f(1.0f, 0.05f);
    glVertex2f(1.0f, -0.2f);
    glEnd();


    //reverside
    glColor3f(0.956863f, 0.643137f, 0.376471f); // Set color to green
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.2f);
    glEnd();

    // Draw the river
    glColor3f(0.0f, 0.4f, 0.8f); // Set river color to blue
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.3f);
    glEnd();

    //Ship 
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-0.80f, -0.6f, 0.0f);
    glVertex3f(-0.80f, -0.75f, 0.0f);
    glVertex3f(-0.20f, -0.75f, 0.0f);
    glVertex3f(-0.0f, -0.6, 0.0f);

    // contener1
    glColor3f(1, 1, 1);
    glVertex3f(-0.78f, -0.60f, 0.0f);
    glVertex3f(-0.78f, -0.55f, 0.0f);
    glVertex3f(-0.58f, -0.55f, 0.0f);
    glVertex3f(-0.58f, -0.60f, 0.0f);
    // contener1
    glColor3f(0.956863f, 0.643137f, 0.376471f);
    glVertex3f(-0.58f, -0.60f, 0.0f);
    glVertex3f(-0.58f, -0.55f, 0.0f);
    glVertex3f(-0.38f, -0.55f, 0.0f);
    glVertex3f(-0.38f, -0.60f, 0.0f);
    // contener3
    glColor3f(1, 0, 1);
    glVertex3f(-0.38f, -0.60f, 0.0f);
    glVertex3f(-0.38f, -0.55f, 0.0f);
    glVertex3f(-0.18f, -0.55f, 0.0f);
    glVertex3f(-0.18f, -0.60f, 0.0f);

    // 2nd flor contener1
    glColor3f(1, 0, 1);
    glVertex3f(-0.78f, -0.55f, 0.0f);
    glVertex3f(-0.78f, -0.50f, 0.0f);
    glVertex3f(-0.58f, -0.50f, 0.0f);
    glVertex3f(-0.58f, -0.55f, 0.0f);
    //2nd flor contener1
    glColor3f(1, 1, 1);
    glVertex3f(-0.58f, -0.55f, 0.0f);
    glVertex3f(-0.58f, -0.50f, 0.0f);
    glVertex3f(-0.38f, -0.50f, 0.0f);
    glVertex3f(-0.38f, -0.55f, 0.0f);

    // 2nd flor contener3
    glColor3f(0.956863f, 0.643137f, 0.376471f);
    glVertex3f(-0.38f, -0.55f, 0.0f);
    glVertex3f(-0.38f, -0.50f, 0.0f);
    glVertex3f(-0.18f, -0.50f, 0.0f);
    glVertex3f(-0.18f, -0.55f, 0.0f);

    // 3rd flor contener1
    glColor3f(1, 0.5, 0.5);
    glVertex3f(-0.78f, -0.50f, 0.0f);
    glVertex3f(-0.78f, -0.45f, 0.0f);
    glVertex3f(-0.58f, -0.45f, 0.0f);
    glVertex3f(-0.58f, -0.50f, 0.0f);
    //3rd flor contener2
    glColor3f(1.5, 1, 0.196078);
    glVertex3f(-0.58f, -0.50f, 0.0f);
    glVertex3f(-0.58f, -0.45f, 0.0f);
    glVertex3f(-0.38f, -0.45f, 0.0f);
    glVertex3f(-0.38f, -0.50f, 0.0f);

    // 3rd flor contener3
    glColor3f(0.0, 0.05, 1.0);
    glVertex3f(-0.38f, -0.50f, 0.0f);
    glVertex3f(-0.38f, -0.45f, 0.0f);
    glVertex3f(-0.18f, -0.45f, 0.0f);
    glVertex3f(-0.18f, -0.50f, 0.0f);


    glutPostRedisplay();

    /*car2*/
    glBegin(GL_QUADS); //upper body
    glColor3f(0.255, 0.102, 0.255);
    glVertex3f(p - 0.31, 0.06, 0);
    glVertex3f(p - 0.31, 0.02, 0);
    glVertex3f(p - 0.40, 0.02, 0);
    glVertex3f(p - 0.40, 0.06, 0);
    glEnd();

    glBegin(GL_QUADS); // lower body
    glVertex3f(p - 0.46, -0.015, 0);
    glVertex3f(p - 0.46, 0.025, 0);
    glVertex3f(p - 0.25, 0.025, 0);
    glVertex3f(p - 0.25, -0.015, 0);
    glEnd();

    //first car body in back side
    glBegin(GL_TRIANGLES);
    glVertex3f(p - 0.31, 0.02, 0);
    glVertex3f(p - 0.31, 0.06, 0);
    glVertex3f(p - 0.29, 0.02, 0);

    glVertex3f(p - 0.40, 0.02, 0);
    glVertex3f(p - 0.40, 0.06, 0);
    glVertex3f(p - 0.425, 0.02, 0);
    glEnd();

    glBegin(GL_QUADS);
    //window 1
    glColor3f(0.0, 0.0, 0);
    glVertex3f(p - 0.31, 0.03, 0);
    glVertex3f(p - 0.325, 0.05, 0);
    glVertex3f(p - 0.35, 0.05, 0);
    glVertex3f(p - 0.35, 0.03, 0);
    //windows 2
    glVertex3f(p - 0.36, 0.03, 0);
    glVertex3f(p - 0.36, 0.05, 0);
    glVertex3f(p - 0.38, 0.05, 0);
    glVertex3f(p - 0.395, 0.03, 0);
    glEnd();

    glColor3f(0.0, 0.0, 0);
    circle(0.02, 0.02, p - 0.30, -0.01); //tier 1
    circle(0.02, 0.02, p - 0.40, -0.01); //tier 2
    //bus
    glBegin(GL_QUADS); //lower body
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(p - 0.55, -0.02, 0);
    glVertex3f(p - 0.55, 0.05, 0);
    glVertex3f(p - 0.75, 0.05, 0);
    glVertex3f(p - 0.75, -0.02, 0);
    //upper body

    glVertex3f(p - 0.75, 0.08, 0);
    glVertex3f(p - 0.75, 0.05, 0);
    glVertex3f(p - 0.55, 0.05, 0);
    glVertex3f(p - 0.55, 0.08, 0);

    //windows 1
    glColor3f(1.0, 1.0, 1);
    glVertex3f(p - 0.56, 0.02, 0);
    glVertex3f(p - 0.56, 0.07, 0);
    glVertex3f(p - 0.59, 0.07, 0);
    glVertex3f(p - 0.59, 0.02, 0);
    //windows 2
    glColor3f(1.0, 1.0, 1);
    glVertex3f(p - 0.60, 0.02, 0);
    glVertex3f(p - 0.60, 0.07, 0);
    glVertex3f(p - 0.63, 0.07, 0);
    glVertex3f(p - 0.63, 0.02, 0);

    //windows 3
    glColor3f(1.0, 1.0, 1);
    glVertex3f(p - 0.64, 0.02, 0);
    glVertex3f(p - 0.64, 0.07, 0);
    glVertex3f(p - 0.67, 0.07, 0);
    glVertex3f(p - 0.67, 0.02, 0);
    //windows 4
    glColor3f(1.0, 1.0, 1);
    glVertex3f(p - 0.68, 0.02, 0);
    glVertex3f(p - 0.68, 0.07, 0);
    glVertex3f(p - 0.71, 0.07, 0);
    glVertex3f(p - 0.71, 0.02, 0);
    //windows 5
    glColor3f(1.0, 1.0, 1);
    glVertex3f(p - 0.72, 0.02, 0);
    glVertex3f(p - 0.72, 0.07, 0);
    glVertex3f(p - 0.735, 0.07, 0);
    glVertex3f(p - 0.735, 0.02, 0);
    glEnd();

    //tier1
    glColor3f(0.0, 0.0, 0);
    circle(0.025, 0.025, p - 0.60, -0.01); //tier 1
    circle(0.025, 0.025, p - 0.70, -0.01); //tier 2

    //first building
    glBegin(GL_QUADS);
    glColor3f(0.196078, 0.803922, 0.196078);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.26f, 0.0f);
    glVertex3f(0.05f, 0.25f, 0.0f);

    //first building side
    glColor3f(0.196078, 0.803922, 0.196078);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.05f, 0.25f, 0.0f);
    glVertex3f(0.04f, 0.23f, 0.0f);
    glVertex3f(0.04f, 0.06f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.08f, 0.0f);
    glVertex3f(0.13f, 0.08f, 0.0f);
    glVertex3f(0.13f, 0.12f, 0.0f);
    glVertex3f(0.07f, 0.12f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.15f, 0.0f);
    glVertex3f(0.13f, 0.15f, 0.0f);
    glVertex3f(0.13f, 0.19f, 0.0f);
    glVertex3f(0.07f, 0.19f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.21f, 0.0f);
    glVertex3f(0.13f, 0.21f, 0.0f);
    glVertex3f(0.13f, 0.24f, 0.0f);
    glVertex3f(0.07f, 0.24f, 0.0f);

    //2nd building
    glColor3f(0.5, 0.0, 0.0);
    glVertex3f(0.15f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.05f, 0.0f);

    // 2nd building windows by floor sequence
    //2nd building 1st floor
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.07f, 0.0f);
    glVertex3f(0.19f, 0.07f, 0.0f);
    glVertex3f(0.19f, 0.09f, 0.0f);
    glVertex3f(0.16f, 0.09f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.07f, 0.0f);
    glVertex3f(0.24f, 0.07f, 0.0f);
    glVertex3f(0.24f, 0.09f, 0.0f);
    glVertex3f(0.21f, 0.09f, 0.0f);

    //2nd building 2nd floor.

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.12f, 0.0f);
    glVertex3f(0.19f, 0.12f, 0.0f);
    glVertex3f(0.19f, 0.14f, 0.0f);
    glVertex3f(0.16f, 0.14f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.12f, 0.0f);
    glVertex3f(0.24f, 0.12f, 0.0f);
    glVertex3f(0.24f, 0.14f, 0.0f);
    glVertex3f(0.21f, 0.14f, 0.0f);
    //2nd building 3rd floor.
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.17f, 0.0f);
    glVertex3f(0.19f, 0.17f, 0.0f);
    glVertex3f(0.19f, 0.19f, 0.0f);
    glVertex3f(0.16f, 0.19f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.17f, 0.0f);
    glVertex3f(0.24f, 0.17f, 0.0f);
    glVertex3f(0.24f, 0.19f, 0.0f);
    glVertex3f(0.21f, 0.19f, 0.0f);

    //2nd building 4th floor
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.22f, 0.0f);
    glVertex3f(0.19f, 0.22f, 0.0f);
    glVertex3f(0.19f, 0.24f, 0.0f);
    glVertex3f(0.16f, 0.24f, 0.0f);

    glVertex3f(0.21f, 0.22f, 0.0f);
    glVertex3f(0.24f, 0.22f, 0.0f);
    glVertex3f(0.24f, 0.24f, 0.0f);
    glVertex3f(0.21f, 0.24f, 0.0f);
    //2nd building 5th floor
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.27f, 0.0f);
    glVertex3f(0.19f, 0.27f, 0.0f);
    glVertex3f(0.19f, 0.29f, 0.0f);
    glVertex3f(0.16f, 0.29f, 0.0f);

    glVertex3f(0.21f, 0.27f, 0.0f);
    glVertex3f(0.24f, 0.27f, 0.0f);
    glVertex3f(0.24f, 0.29f, 0.0f);
    glVertex3f(0.21f, 0.29f, 0.0f);

    //3rd building
    glColor3f(0, 0, 0);
    glVertex3f(0.25f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.32f, 0.0f);
    glVertex3f(0.25f, 0.32f, 0.0f);
    //3rd building windows
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.07f, 0.0f);
    glVertex3f(0.29f, 0.07f, 0.0f);
    glVertex3f(0.29f, 0.13f, 0.0f);
    glVertex3f(0.26f, 0.13f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.17f, 0.0f);
    glVertex3f(0.29f, 0.17f, 0.0f);
    glVertex3f(0.29f, 0.23f, 0.0f);
    glVertex3f(0.26f, 0.23f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.26f, 0.0f);
    glVertex3f(0.29f, 0.26f, 0.0f);
    glVertex3f(0.29f, 0.30f, 0.0f);
    glVertex3f(0.26f, 0.30f, 0.0f);

    // last border black on building footer
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.04f, 0.05f, 0.0f);
    glVertex3f(0.04f, 0.06f, 0.0f);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.05f, 0.04f, 0.0f);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.05f, 0.04f, 0.0f);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.04f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    //1st building win 1
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.10f, 0.08f, 0.0f);
    glVertex3f(0.10f, 0.12f, 0.0f);
    //sideline 1 building
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.05f, 0.25f, 0.0f);

    //sideline 2 building
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.15f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.30f, 0.0f);
    //sideline 1 building
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.25f, 0.05f, 0.0f);
    glVertex3f(0.25f, 0.32f, 0.0f);

    // 1st building win 2
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.10f, 0.15f, 0.0f);
    glVertex3f(0.10f, 0.19f, 0.0f);
    //1st building win 3
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.10f, 0.21f, 0.0f);
    glVertex3f(0.10f, 0.24f, 0.0f);
    // 2nd building 1st floor
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.15f, 0.10f, 0.0f);
    glVertex3f(0.25f, 0.10f, 0.0f);
    // 2nd building 2nd floor
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.15f, 0.15f, 0.0f);
    glVertex3f(0.25f, 0.15f, 0.0f);
    // 2nd floor 3rd floor
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.15f, 0.20f, 0.0f);
    glVertex3f(0.25f, 0.20f, 0.0f);
    // 2nd floor 4th floor
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.15f, 0.25f, 0.0f);
    glVertex3f(0.25f, 0.25f, 0.0f);

    //3rd building
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.25f, 0.14f, 0.0f);
    glVertex3f(0.30f, 0.14f, 0.0f);

    glVertex3f(0.25f, 0.24f, 0.0f);
    glVertex3f(0.30f, 0.24f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.0, 0.0);
    glVertex3f(0.15f, 0.30f, 0.0f);
    glVertex3f(0.06f, 0.25f, 0.0f);
    glVertex3f(0.15f, 0.26f, 0.0f);

    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(0.25f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.32f, 0.0f);
    glVertex3f(0.22f, 0.30f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    // bus stand
    glColor3f(0.0, 0.05, 1.0);
    glVertex3f(-0.05f, 0.16f, 0.0f);
    glVertex3f(0.03f, 0.16f, 0.0f);
    glVertex3f(0.00f, 0.20f, 0.0f);
    glVertex3f(-0.05f, 0.20f, 0.0f);

    //bus stand upper corner
    glColor3f(0, 0, 0);
    glVertex3f(-0.05f, 0.15f, 0.0f);
    glVertex3f(0.03f, 0.15f, 0.0f);
    glVertex3f(0.03f, 0.16f, 0.0f);
    glVertex3f(-0.05f, 0.16f, 0.0f);

    //bus stand lower corner
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-0.05f, 0.12f, 0.0f);
    glVertex3f(0.01f, 0.12f, 0.0f);
    glVertex3f(0.01f, 0.05f, 0.0f);
    glVertex3f(-0.05f, 0.05f, 0.0f);

    // bus stand large pillar
    glColor3f(0, 0, 0);
    glVertex3f(0.0f, 0.05f, 0.0f);
    glVertex3f(0.0f, 0.15f, 0.0f);
    glVertex3f(-0.01f, 0.15f, 0.0f);
    glVertex3f(-0.01f, 0.05f, 0.0f);

    // bus stand small pillar
    glColor3f(0, 0, 0);
    glVertex3f(-0.02f, 0.10f, 0.0f);
    glVertex3f(-0.02f, 0.15f, 0.0f);
    glVertex3f(-0.03f, 0.15f, 0.0f);
    glVertex3f(-0.03f, 0.10f, 0.0f);
    glEnd();



    glBegin(GL_QUADS);
    //clubhouse bside 1 house
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-0.80f, 0.1f, 0.0f);
    glVertex3f(-0.80f, 0.40f, 0.0f);
    glVertex3f(-0.60f, 0.40f, 0.0f);
    glVertex3f(-0.60f, 0.1f, 0.0f);

    //first flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.78f, 0.14f, 0.0f);
    glVertex3f(-0.78f, 0.20f, 0.0f);
    glVertex3f(-0.70f, 0.20f, 0.0f);
    glVertex3f(-0.70f, 0.14f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.69f, 0.14f, 0.0f);
    glVertex3f(-0.69f, 0.20f, 0.0f);
    glVertex3f(-0.62f, 0.20f, 0.0f);
    glVertex3f(-0.62f, 0.14f, 0.0f);
    // second flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.78f, 0.22f, 0.0f);
    glVertex3f(-0.78f, 0.28f, 0.0f);
    glVertex3f(-0.70f, 0.28f, 0.0f);
    glVertex3f(-0.70f, 0.22f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.69f, 0.22f, 0.0f);
    glVertex3f(-0.69f, 0.28f, 0.0f);
    glVertex3f(-0.62f, 0.28f, 0.0f);
    glVertex3f(-0.62f, 0.22f, 0.0f);
    // 3rd flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.78f, 0.30f, 0.0f);
    glVertex3f(-0.78f, 0.36f, 0.0f);
    glVertex3f(-0.70f, 0.36f, 0.0f);
    glVertex3f(-0.70f, 0.30f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.69f, 0.30f, 0.0f);
    glVertex3f(-0.69f, 0.36f, 0.0f);
    glVertex3f(-0.62f, 0.36f, 0.0f);
    glVertex3f(-0.62f, 0.30f, 0.0f);

    glBegin(GL_QUADS);
    //clubhouse bside 2 house
    glColor3f(0.4, 0.0, 0.4);
    glVertex3f(-0.55f, 0.1f, 0.0f);
    glVertex3f(-0.55f, 0.50f, 0.0f);
    glVertex3f(-0.30f, 0.50f, 0.0f);
    glVertex3f(-0.30f, 0.1f, 0.0f);

    //first flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.54f, 0.14f, 0.0f);
    glVertex3f(-0.54f, 0.20f, 0.0f);
    glVertex3f(-0.47f, 0.20f, 0.0f);
    glVertex3f(-0.47f, 0.14f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.46f, 0.14f, 0.0f);
    glVertex3f(-0.46f, 0.20f, 0.0f);
    glVertex3f(-0.39f, 0.20f, 0.0f);
    glVertex3f(-0.39f, 0.14f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.38f, 0.14f, 0.0f);
    glVertex3f(-0.38f, 0.20f, 0.0f);
    glVertex3f(-0.31f, 0.20f, 0.0f);
    glVertex3f(-0.31f, 0.14f, 0.0f);

    // second flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.54f, 0.22f, 0.0f);
    glVertex3f(-0.54f, 0.28f, 0.0f);
    glVertex3f(-0.47f, 0.28f, 0.0f);
    glVertex3f(-0.47f, 0.22f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.46f, 0.22f, 0.0f);
    glVertex3f(-0.46f, 0.28f, 0.0f);
    glVertex3f(-0.39f, 0.28f, 0.0f);
    glVertex3f(-0.39f, 0.22f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.38f, 0.22f, 0.0f);
    glVertex3f(-0.38f, 0.28f, 0.0f);
    glVertex3f(-0.31f, 0.28f, 0.0f);
    glVertex3f(-0.31f, 0.22f, 0.0f);

    // 3rd flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.54f, 0.30f, 0.0f);
    glVertex3f(-0.54f, 0.36f, 0.0f);
    glVertex3f(-0.47f, 0.36f, 0.0f);
    glVertex3f(-0.47f, 0.30f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.46f, 0.30f, 0.0f);
    glVertex3f(-0.46f, 0.36f, 0.0f);
    glVertex3f(-0.39f, 0.36f, 0.0f);
    glVertex3f(-0.39f, 0.30f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.38f, 0.30f, 0.0f);
    glVertex3f(-0.38f, 0.36f, 0.0f);
    glVertex3f(-0.31f, 0.36f, 0.0f);
    glVertex3f(-0.31f, 0.30f, 0.0f);
    // 4th flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.54f, 0.38f, 0.0f);
    glVertex3f(-0.54f, 0.44f, 0.0f);
    glVertex3f(-0.47f, 0.44f, 0.0f);
    glVertex3f(-0.47f, 0.38f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.46f, 0.38f, 0.0f);
    glVertex3f(-0.46f, 0.44f, 0.0f);
    glVertex3f(-0.39f, 0.44f, 0.0f);
    glVertex3f(-0.39f, 0.38f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.38f, 0.38f, 0.0f);
    glVertex3f(-0.38f, 0.44f, 0.0f);
    glVertex3f(-0.31f, 0.44f, 0.0f);
    glVertex3f(-0.31f, 0.38f, 0.0f);

    glBegin(GL_QUADS);
    //clubhouse 1
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.98f, 0.05f, 0.0f);
    glVertex3f(-0.98f, 0.50f, 0.0f);
    glVertex3f(-0.82f, 0.50f, 0.0f);
    glVertex3f(-0.82f, 0.05f, 0.0f);
    //door
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.92f, 0.05f, 0.0f);
    glVertex3f(-0.92f, 0.12f, 0.0f);
    glVertex3f(-0.88f, 0.12f, 0.0f);
    glVertex3f(-0.88f, 0.05f, 0.0f);

    //first flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.965f, 0.14f, 0.0f);
    glVertex3f(-0.965f, 0.20f, 0.0f);
    glVertex3f(-0.905f, 0.20f, 0.0f);
    glVertex3f(-0.905f, 0.14f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.90f, 0.14f, 0.0f);
    glVertex3f(-0.90f, 0.20f, 0.0f);
    glVertex3f(-0.84f, 0.20f, 0.0f);
    glVertex3f(-0.84f, 0.14f, 0.0f);

    // second flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.965f, 0.22f, 0.0f);
    glVertex3f(-0.965f, 0.28f, 0.0f);
    glVertex3f(-0.905f, 0.28f, 0.0f);
    glVertex3f(-0.905f, 0.22f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.90f, 0.22f, 0.0f);
    glVertex3f(-0.90f, 0.28f, 0.0f);
    glVertex3f(-0.84f, 0.28f, 0.0f);
    glVertex3f(-0.84f, 0.22f, 0.0f);

    // 3rd flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.965f, 0.30f, 0.0f);
    glVertex3f(-0.965f, 0.36f, 0.0f);
    glVertex3f(-0.905f, 0.36f, 0.0f);
    glVertex3f(-0.905f, 0.30f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.90f, 0.30f, 0.0f);
    glVertex3f(-0.90f, 0.36f, 0.0f);
    glVertex3f(-0.84f, 0.36f, 0.0f);
    glVertex3f(-0.84f, 0.30f, 0.0f);

    // 4th flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(-0.965f, 0.38f, 0.0f);
    glVertex3f(-0.965f, 0.44f, 0.0f);
    glVertex3f(-0.905f, 0.44f, 0.0f);
    glVertex3f(-0.905f, 0.38f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(-0.90f, 0.38f, 0.0f);
    glVertex3f(-0.90f, 0.44f, 0.0f);
    glVertex3f(-0.84f, 0.44f, 0.0f);
    glVertex3f(-0.84f, 0.38f, 0.0f);


    glBegin(GL_QUADS);
    //clubhouse frame beside another house
    glColor3f(0.0, 0.05, 1.0);
    glVertex3f(0.70f, 0.10f, 0.0f);
    glVertex3f(0.70f, 0.50f, 0.0f);
    glVertex3f(0.90f, 0.50f, 0.0f);
    glVertex3f(0.90f, 0.10f, 0.0f);

    //first flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(0.72f, 0.14f, 0.0f);
    glVertex3f(0.72f, 0.20f, 0.0f);
    glVertex3f(0.78f, 0.20f, 0.0f);
    glVertex3f(0.78f, 0.14f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(0.79f, 0.14f, 0.0f);
    glVertex3f(0.79f, 0.20f, 0.0f);
    glVertex3f(0.88f, 0.20f, 0.0f);
    glVertex3f(0.88f, 0.14f, 0.0f);


    // second flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(0.72f, 0.22f, 0.0f);
    glVertex3f(0.72f, 0.28f, 0.0f);
    glVertex3f(0.78f, 0.28f, 0.0f);
    glVertex3f(0.78f, 0.22f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(0.79f, 0.22f, 0.0f);
    glVertex3f(0.79f, 0.28f, 0.0f);
    glVertex3f(0.88f, 0.28f, 0.0f);
    glVertex3f(0.88f, 0.22f, 0.0f);

    // 3rd flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(0.72f, 0.30f, 0.0f);
    glVertex3f(0.72f, 0.36f, 0.0f);
    glVertex3f(0.78f, 0.36f, 0.0f);
    glVertex3f(0.78f, 0.30f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(0.79f, 0.30f, 0.0f);
    glVertex3f(0.79f, 0.36f, 0.0f);
    glVertex3f(0.88f, 0.36f, 0.0f);
    glVertex3f(0.88f, 0.30f, 0.0f);

    // 4th flor windwo
    glColor3f(1, 1, 1);
    glVertex3f(0.72f, 0.38f, 0.0f);
    glVertex3f(0.72f, 0.44f, 0.0f);
    glVertex3f(0.78f, 0.44f, 0.0f);
    glVertex3f(0.78f, 0.38f, 0.0f);

    glColor3f(1, 1, 1);
    glVertex3f(0.79f, 0.38f, 0.0f);
    glVertex3f(0.79f, 0.44f, 0.0f);
    glVertex3f(0.88f, 0.44f, 0.0f);
    glVertex3f(0.88f, 0.38f, 0.0f);



    glBegin(GL_QUADS);

    //clubhouse 2
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.05f, 0.0f);


    //clubshouse frame upper
    glColor3f(0.255, 0.102, 0.255);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.60f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    //clubhouse frame sider
    glColor3f(0.51, 0.255, 0.255);
    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.07f, 0.0f);


    //windows clubhouse in row 1
    glColor3f(1, 1, 1);
    glVertex3f(0.60f, 0.10f, 0.0f);
    glVertex3f(0.62f, 0.10f, 0.0f);
    glVertex3f(0.62f, 0.12f, 0.0f);
    glVertex3f(0.60f, 0.12f, 0.0f);

    glVertex3f(0.60f, 0.13f, 0.0f);
    glVertex3f(0.62f, 0.13f, 0.0f);
    glVertex3f(0.62f, 0.15f, 0.0f);
    glVertex3f(0.60f, 0.15f, 0.0f);

    //windows clubhouse in row 2
    glColor3f(1, 1, 1);
    glVertex3f(0.63f, 0.10f, 0.0f);
    glVertex3f(0.65f, 0.10f, 0.0f);
    glVertex3f(0.65f, 0.12f, 0.0f);
    glVertex3f(0.63f, 0.12f, 0.0f);

    glVertex3f(0.63f, 0.13f, 0.0f);
    glVertex3f(0.65f, 0.13f, 0.0f);
    glVertex3f(0.65f, 0.15f, 0.0f);
    glVertex3f(0.63f, 0.15f, 0.0f);

    //windows clubhouse in row 3
    glColor3f(1, 1, 1);
    glVertex3f(0.66f, 0.10f, 0.0f);
    glVertex3f(0.68f, 0.10f, 0.0f);
    glVertex3f(0.68f, 0.12f, 0.0f);
    glVertex3f(0.66f, 0.12f, 0.0f);

    glVertex3f(0.66f, 0.13f, 0.0f);
    glVertex3f(0.68f, 0.13f, 0.0f);
    glVertex3f(0.68f, 0.15f, 0.0f);
    glVertex3f(0.66f, 0.15f, 0.0f);

    //windows clubhouse in row 4
    glColor3f(1, 1, 1);
    glVertex3f(0.69f, 0.10f, 0.0f);
    glVertex3f(0.71f, 0.10f, 0.0f);
    glVertex3f(0.71f, 0.12f, 0.0f);
    glVertex3f(0.69f, 0.12f, 0.0f);

    glVertex3f(0.69f, 0.13f, 0.0f);
    glVertex3f(0.71f, 0.13f, 0.0f);
    glVertex3f(0.71f, 0.15f, 0.0f);
    glVertex3f(0.69f, 0.15f, 0.0f);

    //windows clubhouse in row 5
    glColor3f(1, 1, 1);
    glVertex3f(0.73f, 0.10f, 0.0f);
    glVertex3f(0.75f, 0.10f, 0.0f);
    glVertex3f(0.75f, 0.12f, 0.0f);
    glVertex3f(0.73f, 0.12f, 0.0f);

    glVertex3f(0.73f, 0.13f, 0.0f);
    glVertex3f(0.75f, 0.13f, 0.0f);
    glVertex3f(0.75f, 0.15f, 0.0f);
    glVertex3f(0.73f, 0.15f, 0.0f);


    //clubhouse door
    glColor3f(1, 1, 1);
    glVertex3f(0.65f, 0.05f, 0.0f);
    glVertex3f(0.65f, 0.08f, 0.0f);
    glVertex3f(0.70f, 0.08f, 0.0f);
    glVertex3f(0.70f, 0.05f, 0.0f);

    glEnd();

    glBegin(GL_LINES);
    // clubhouse lines
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.60f, 0.22f, 0.0f);

    glVertex3f(0.60f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    glVertex3f(0.84f, 0.07f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.84f, 0.07f, 0.0f);

    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.05f, 0.0f);

    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glEnd();


    glFlush(); // Flush the OpenGL buffers
}

// Function to update the animation
void updateAnimation(int value)
{
    sunAngle += 1.0f; // Rotate the sun
    cloudTranslateX += 0.001f;
    cloud2TranslateX += 0.0015f;// Translate the clouds
    glutPostRedisplay(); // Mark the current window as needing to be redisplayed

    glutTimerFunc(10, updateAnimation, 0); // Call the updateAnimation function after 10 milliseconds
}

// Function to handle window resizing
void resizeWindow(int width, int height)
{
    glViewport(0, 0, width, height); // Set the viewport
    glMatrixMode(GL_PROJECTION); // Switch to the projection matrix
    glLoadIdentity(); // Load the identity matrix
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // Set the orthographic projection

    glMatrixMode(GL_MODELVIEW); // Switch back to the modelview matrix
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode

    glutInitWindowSize(1000, 2000); // Set the window size
    glutCreateWindow("Md Jabed Hosen"); // Create a window with the specified title

    glClearColor(0.5f, 0.7f, 1.0f, 1.0f); // Set the clear color to light blue

    glutDisplayFunc(drawScene); // Set the display callback function
    glutReshapeFunc(resizeWindow); // Set the window resize callback function

    glutTimerFunc(10, updateAnimation, 0); // Call the updateAnimation function after 10 milliseconds

    glutMainLoop(); // Enter the GLUT event processing loop

    return 0;
}
