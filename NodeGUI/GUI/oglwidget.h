#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QtOpenGL/QGLWidget>

#include <QGraphicsScene>

class OGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OGLWidget(QWidget *parent = 0);
    ~OGLWidget();

    enum {
        key_W,
        key_S,
        key_D,
        key_A,
        key_CTRL,
        mouse_Left,
        mouse_Right,
        key_ENUM_END
    };

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    bool event(QEvent *);

    bool leftPress, rightPress, ctrlPress;
    QPoint winSize;
    QPoint winPos;
    QPoint nodePos;

    GLuint texID;

    bool keyPressedArray[key_ENUM_END];

signals:

public slots:

};


#endif // OGLWIDGET_H
