#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <gl/glut.h>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    //void mykeyfun(unsigned char key, int xmouse, int ymouse);
    void Set_Default_Pos();
    void Increase_Xdis() {Move_x += 0.2; updateGL();}
    void Decrease_Xdis() {Move_x -= 0.2; updateGL();}
    void Increase_Ydis() {Move_y += 0.2; updateGL();}
    void Decrease_Ydis() {Move_y -= 0.2; updateGL();}

    void Increase_Xrot() {Rotate_x += 5; updateGL();}
    void Decrease_Xrot() {Rotate_x -= 5; updateGL();}
    void Increase_Yrot() {Rotate_y += 5; updateGL();}
    void Decrease_Yrot() {Rotate_y -= 5; updateGL();}

private:
    float Rotate_x, Rotate_y, Rotate_z;
    float Move_x, Move_y, Move_z;
};

#endif // GLWIDGET_H
