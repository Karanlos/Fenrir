#include <QtGui>
#include "oglwidget.h"
#include "pngloader.h"

#include <iostream>
#define DEBUG_DRAW
#ifdef DEBUG_DRAW
#define DEBUG_(opt) opt //
#else
#define DEBUG_(opt) //
#endif

using namespace std;

int NUM_POINTS = 10;

int GRID_SIZE = 40;

bool debug = false;

float start[4][2] = {{10, 10},
                    {0.0, 60},
                    {0.0, -60},
                    {60, 60}};

OGLWidget::OGLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::AccumBuffer|QGL::Rgba|QGL::DoubleBuffer),parent)
{
    setFocusPolicy(Qt::StrongFocus);

    for(int i = 0; i < key_ENUM_END; i++)
        keyPressedArray[i] = false;

    winPos = QPoint(0,0);

    nodePos = QPoint(10 + 128/2, 10+128/2);

}

OGLWidget::~OGLWidget() {

    glDeleteTextures(1, &texID);

}

bool OGLWidget::event(QEvent *e) {
    if((e->type() == QEvent::KeyPress)) {
        QKeyEvent* k = static_cast<QKeyEvent*>(e);

        int kp = k->key();

        if(kp == Qt::Key_W)
            keyPressedArray[key_W] = true;
        if(kp == Qt::Key_S)
            keyPressedArray[key_S] = true;
        if(kp == Qt::Key_D)
            keyPressedArray[key_D] = true;
        if(kp == Qt::Key_A)
            keyPressedArray[key_A] = true;
        if(kp == Qt::Key_Control)
            keyPressedArray[key_CTRL] = true;

        if(keyPressedArray[key_D] && keyPressedArray[key_CTRL])
            debug = !debug;
    }

    if((e->type() == QEvent::KeyRelease)) {
        QKeyEvent* k = static_cast<QKeyEvent*>(e);

        int kp = k->key();

        if(kp == Qt::Key_W)
            keyPressedArray[key_W] = false;
        if(kp == Qt::Key_S)
            keyPressedArray[key_S] = false;
        if(kp == Qt::Key_D)
            keyPressedArray[key_D] = false;
        if(kp == Qt::Key_A)
            keyPressedArray[key_A] = false;
        if(kp == Qt::Key_Control)
            keyPressedArray[key_CTRL] = false;
    }

    if((e->type() == QEvent::MouseMove)) {
        QMouseEvent* m = static_cast<QMouseEvent*>(e);
        if(keyPressedArray[mouse_Left] && keyPressedArray[key_CTRL]) {
            start[1][1] = winSize.y() - m->y() - start[0][1];
        } else if(keyPressedArray[mouse_Right] && keyPressedArray[key_CTRL]) {
            start[2][1] = winSize.y() - m->y() - start[3][1];
        } else if(keyPressedArray[mouse_Left]) {
            start[0][0] = m->x();
            start[0][1] = winSize.y() - m->y();
        } else if(keyPressedArray[mouse_Right]) {

            start[3][0] = m->x();
            start[3][1] = winSize.y() - m->y();
        }
    }

    if((e->type() == QEvent::MouseButtonPress)) {
        QMouseEvent* m = static_cast<QMouseEvent*>(e);
        if(m->button() == Qt::LeftButton)
            keyPressedArray[mouse_Left] = true;
        if(m->button() == Qt::RightButton)
            keyPressedArray[mouse_Right] = true;
    }


    if((e->type() == QEvent::MouseButtonRelease)) {
        QMouseEvent* m = static_cast<QMouseEvent*>(e);
        if(m->button() == Qt::LeftButton)
            keyPressedArray[mouse_Left] = false;
        if(m->button() == Qt::RightButton)
            keyPressedArray[mouse_Right] = false;
    }

    QWidget::event(e);

    return true;
}

void OGLWidget::initializeGL() {
    glClearColor (0.1, 0.1, 0.4, 1.0);

    /* set up standard orthogonal view with clipping */
    /* box as cube of side 2 centered at origin */
    /* This is default view and these statement could be removed */
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glLineWidth(1.5f);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA
    glEnable(GL_DEPTH_TEST);

    TexInfo img = loadPNG("../../Skrivebord/NodeEditor/NodeBaseTest.png");
    texID = 0;

    glGenTextures(1, &texID);

    glBindTexture(GL_TEXTURE_2D, texID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.buffer);

    glBindTexture(GL_TEXTURE_2D, 0);

    if(img.buffer == 0)
        std::cout << "Error while loading png" << std::endl;

    if(img.buffer != 0)
        delete img.buffer;

}

void OGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.2f);
    for(int i = 0; i < winSize.x() / GRID_SIZE + 2; i++) {
        glVertex3f(GRID_SIZE * i + winPos.x(), -10, -0.2);
        glVertex3f(GRID_SIZE * i + winPos.x(), winSize.y() + 10, -0.2);
    }

    for(int i = 0; i < winSize.y() / GRID_SIZE + 2; i++) {
        glVertex3f(-10, GRID_SIZE * i + winPos.y(), -0.2);
        glVertex3f(winSize.x() + 10, GRID_SIZE * i + winPos.y(), -0.2);
    }

    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    start[1][0] = -(start[0][0] - start[3][0]) * 0.25f;
    start[1][1] = -(start[0][1] - start[3][1]) * 0.75f;
    start[2][0] = (start[0][0] - start[3][0]) * 0.25f;
    start[2][1] = (start[0][1] - start[3][1]) * 0.75f;



    for(int i = 0; i <= NUM_POINTS; i++) {
        float point[2];
        float t = float(i) / float(NUM_POINTS);
        point[0] = (1 - t) * (1 - t) * (1 - t) * start[0][0] + 3 * (1 - t) * (1 - t) * t * (start[1][0] + start[0][0]) + 3 * (1 -t) * t * t * (start[2][0] + start[3][0]) + t * t * t * start[3][0];
        point[1] = (1 - t) * (1 - t) * (1 - t) * start[0][1] + 3 * (1 - t) * (1 - t) * t * (start[1][1] + start[0][1]) + 3 * (1 -t) * t * t * (start[2][1] + start[3][1]) + t * t * t * start[3][1];
        glVertex3f(point[0], point[1], -0.1);
    }
    glEnd();

    if(debug) {
        glBegin(GL_LINE_STRIP);
        glColor4f(1.0f,0.15f,0.15f, 1.0f);
        glVertex3f(start[0][0], start[0][1], -0.1);
        glVertex3f(start[1][0]+start[0][0], start[1][1]+start[0][1], -0.1);
        glVertex3f(start[2][0]+start[3][0], start[2][1]+start[3][1], -0.1);
        glVertex3f(start[3][0], start[3][1], -0.1);
        glEnd();
    }
    glBindTexture(GL_TEXTURE_2D, texID);

    glBegin(GL_QUADS);
    glColor4f(0.8f,0.8f,1.0f, 1.0f);

    glTexCoord2f(0.0f, (128.0f - 36.0f) / 128.0f);
    glVertex3f(nodePos.x() - 128/2, nodePos.y() - 128/2 + 128 - 36, 0.0);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(nodePos.x() - 128/2, nodePos.y() + 128/2, 0.0);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(nodePos.x() + 128/2, nodePos.y() + 128/2, 0.0);

    glTexCoord2f(1.0f, (128.0f - 36.0f) / 128.0f);
    glVertex3f(nodePos.x() + 128/2, nodePos.y() - 128/2 + 128 - 36, 0.0);


    glColor4f(1.0f,1.0f,1.0f, 1.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(nodePos.x() - 128/2, nodePos.y() - 128/2, 0.0);

    glTexCoord2f(0.0f, (128.0f - 36.0f) / 128.0f);
    glVertex3f(nodePos.x() - 128/2, nodePos.y() + 128/2 - 36, 0.0);

    glTexCoord2f(1.0f, (128.0f - 36.0f) / 128.0f);
    glVertex3f(nodePos.x() + 128/2, nodePos.y() + 128/2 - 36, 0.0);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(nodePos.x() + 128/2, nodePos.y() - 128/2, 0.0);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

    QTimer::singleShot(20, this, SLOT(update()));
}

void OGLWidget::resizeGL(int width, int height)
{
    winSize.setX(width);
    winSize.setY(height);

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

