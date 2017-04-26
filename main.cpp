#define GLUT_DISABLE_ATEXIT_HACK
#include "gl/freeglut.h"
#include <time.h>
#include <math.h>


void CubeProjection(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glEnable(GL_DEPTH_TEST); //启用深度检测

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glViewport(0,0,400,400);


glOrtho(-2.0,2.0,-2.0,2.0,-2.0,200.0);
//gluPerspective(60.0f,1.0f,1.0f,500.0f);
//glFrustum(0.1,2.0,0.1,2.0,1.0,100.0);

glRotatef(30.0f,1.0f,0.0f,0.0f);
glRotatef(15.0f,0.0f,1.0f,0.0f);

glColor3f(0.7f,0.5f,0.3f);
//glutSolidCube(1.0f);

  glBegin(GL_QUADS);
    //top(red)
    glColor4f(1.0, 0.0, 0.0,0.5);
    glVertex3f(0.45, -0.45,-1.55);
    glVertex3f(0.55, -0.45,-1.55);
    glVertex3f(0.55, -0.45, -1.45);
    glVertex3f(0.45, -0.45, -1.45);
    //bottom(white)
    glColor4f(1.0, 1.0, 1.0,0.5);
    glVertex3f( 0.55,-0.55,-1.55);
    glVertex3f( 0.55,-0.55, -1.45);
    glVertex3f(0.45,-0.55, -1.45);
    glVertex3f(0.45,-0.55,-1.55);

    //right(yellow
    glColor4f(1.0, 1.0, 0.0,0.5);
    glVertex3f( 0.55, -0.45,-1.55);
    glVertex3f( 0.55,-0.55,-1.55);
    glVertex3f( 0.55,-0.55, -1.45);
    glVertex3f( 0.55, -0.45, -1.45);
    //front(blue)
    glColor4f(0.0, 0.0, 1.0,0.5);
    glVertex3f( 0.55, -0.45, -1.45);
    glVertex3f( 0.55,-0.55, -1.45);
    glVertex3f(0.45,-0.55, -1.45);
    glVertex3f(0.45, -0.45, -1.45);
    //back(green)
    glColor4f(0.0, 1.0, 0.0,0.5);
    glVertex3f(0.45, -0.45,-1.55);
    glVertex3f(0.55,-0.45,-1.55);
    glVertex3f( 0.55,-0.55,-1.55);
    glVertex3f( 0.45, -0.55,-1.55);
    //left(pink)
    glColor4f(0.7, 0.0, 0.5,0.5);
    glVertex3f(0.45, -0.45,-1.55);
    glVertex3f(0.45, -0.55, -1.55);
    glVertex3f(0.45, -0.55, -1.45);
    glVertex3f(0.45, -0.45,-1.45);

    glEnd();

glutSwapBuffers();

}


void CubeViewChange(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glEnable(GL_DEPTH_TEST); //open depth_test

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glColor3f(0.7f,0.5f,0.3f);
//glutSolidCube(1.0f);

double camPosX = sin(clock()/1000.0)*0.8;
double camPosZ = cos(clock()/1000.0)*0.8;

gluLookAt(camPosX,0,camPosZ,0.0,0.0,0.0,0.0,1.0,0.0);
glFrustum(-1.0,1.0,-1.0,1.0,-1.0,10.0);

  glBegin(GL_QUADS);
    //top(red)
    glColor4f(1.0, 0.0, 0.0,0.5);
    glVertex3f(-0.1, 0.1,-0.1);
    glVertex3f(0.1, 0.1,-0.1);
    glVertex3f(0.1, 0.1, 0.1);
    glVertex3f(-0.1, 0.1, 0.1);
    //bottom(white)
    glColor4f(1.0, 1.0, 1.0,0.5);
    glVertex3f( 0.1,-0.1,-0.1);
    glVertex3f( 0.1,-0.1, 0.1);
    glVertex3f(-0.1,-0.1, 0.1);
    glVertex3f(-0.1,-0.1,-0.1);

    //right(yellow
    glColor4f(1.0, 1.0, 0.0,0.5);
    glVertex3f( 0.1, 0.1,-0.1);
    glVertex3f( 0.1,-0.1,-0.1);
    glVertex3f( 0.1,-0.1, 0.1);
    glVertex3f( 0.1, 0.1, 0.1);
    //front(blue)
    glColor4f(0.0, 0.0, 1.0,0.5);
    glVertex3f( 0.1, 0.1, 0.1);
    glVertex3f( 0.1,-0.1, 0.1);
    glVertex3f(-0.1,-0.1, 0.1);
    glVertex3f(-0.1, 0.1, 0.1);
    //back(green)
    glColor4f(0.0, 1.0, 0.0,0.5);
    glVertex3f(-0.1, 0.1,-0.1);
    glVertex3f(-0.1,-0.1,-0.1);
    glVertex3f( 0.1,-0.1,-0.1);
    glVertex3f( 0.1, 0.1,-0.1);
    //left(pink)
    glColor4f(1.0, 0.0, 0.5,0.5);
    glVertex3f(-0.1, 0.1,-0.1);
    glVertex3f(-0.1, 0.1, 0.1);
    glVertex3f(-0.1,-0.1, 0.1);
    glVertex3f(-0.1,-0.1,-0.1);

    glEnd();

glutSwapBuffers();



}



//顯示
void OnDisplay(void)
{

    CubeProjection();
   //CubeViewChange();

}


int main(int argc,char* argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(400,400);
glutCreateWindow("HomeWork5");

glutDisplayFunc(OnDisplay);
glutIdleFunc(OnDisplay);

glutMainLoop();
}

