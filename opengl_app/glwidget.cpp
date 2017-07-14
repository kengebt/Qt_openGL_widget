#include "glwidget.h"
#include "QMessageBox"

//void mykeyfun(unsigned char key, int xmouse, int ymouse)
/*void GLWidget::mykeyfun(unsigned char key, int xmouse, int ymouse)
{
    switch(key)
    {
        case 'w':
           glClearColor(0.0, 0.0, 0.0, 0.0);
           break;

        default:
            break;
    }
    //glutPostRedisplay(); //request display() call ASAP
}*/

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    Rotate_x = Rotate_y = Rotate_z = 0.0;
    Move_x = Move_y = 0.0;
    Move_z = -3.0;
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL() {

    glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
    glClearDepth(1.0f);									// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

    //glutKeyboardFunc(mykeyfun);
    // move zero point to left-down, compensate x scale
    //glScaled(0.5, 0.5, 0.5);
    //glRotatef(45, 1, 0, 0);
}

void GLWidget::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();									// Reset The Current Modelview Matrix
    //glEnable(GL_CULL_FACE);

    glTranslatef(Move_x, Move_y, Move_z);
    glRotatef(Rotate_x, 1.0, 0.0, 0.0);
    glRotatef(Rotate_y, 0.0, 1.0, 0.0);
    glRotatef(Rotate_z, 0.0, 0.0, 1.0);

/*    glBegin(GL_TRIANGLES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f( 0.0, 0.0, 0.0);
            glColor3f(0.0, 1.0, 0.0);
            glVertex3f( 1.0, 0.0, 0.0);
            glColor3f(0.0, 0.0, 1.0);
            glVertex3f( 1.0, 1.0, 0.0);
        glEnd();
*/

    // draw pyramid
    glBegin(GL_TRIANGLES);
      //Triangle 1
        glColor3f(1.0f,0.0f,0.0f); glVertex3f( 0.0f, 1.0f, 0.0f);   //V0(red)
        glColor3f(0.0f,1.0f,0.0f); glVertex3f(-1.0f,-1.0f, 1.0f);   //V1(green)
        glColor3f(0.0f,0.0f,1.0f); glVertex3f( 1.0f,-1.0f, 1.0f);   //V2(blue)
      //Triangle 2
        glColor3f(1.0f,0.0f,0.0f); glVertex3f( 0.0f, 1.0f, 0.0f);   //V0(red)
        glColor3f(0.0f,0.0f,1.0f); glVertex3f( 1.0f,-1.0f, 1.0f);   //V2(blue)
        glColor3f(0.0f,1.0f,0.0f); glVertex3f( 1.0f,-1.0f,-1.0f);   //V3(green)
      //Triangle 3
        glColor3f(1.0f,0.0f,0.0f); glVertex3f( 0.0f, 1.0f, 0.0f);   //V0(red)
        glColor3f(0.0f,1.0f,0.0f); glVertex3f( 1.0f,-1.0f,-1.0f);   //V3(green)
        glColor3f(0.0f,0.0f,1.0f); glVertex3f(-1.0f,-1.0f,-1.0f);   //V4(blue)
      //Triangle 4
        glColor3f(1.0f,0.0f,0.0f); glVertex3f( 0.0f, 1.0f, 0.0f);   //V0(red)
        glColor3f(0.0f,0.0f,1.0f); glVertex3f(-1.0f,-1.0f,-1.0f);   //V4(blue)
        glColor3f(0.0f,1.0f,0.0f); glVertex3f(-1.0f,-1.0f, 1.0f);   //V1(green)
    glEnd();
}

void GLWidget::resizeGL(int width, int height) {
    if (height==0)										// Prevent A Divide By Zero By
    {
        height=1;										// Making Height Equal One
    }

    glViewport(0,0,width,height);						// Reset The Current Viewport

    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    //gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,-5.0f,50.0f);

    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
    glLoadIdentity();									// Reset The Modelview Matrix

}

void GLWidget::Set_Default_Pos()
{
    //QMessageBox msg;
    //msg.setText("test");
    //msg.exec();
    Rotate_x = Rotate_y = Rotate_z = 0.0;
    Move_x = Move_y = Move_z = 0.0;
    updateGL();
}
