#include "CCGLWidget.h"


GLWidget::GLWidget(QWidget *parent, const int width, const int height)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
    , mouseMoveFunc(NULL)
    , mousePressFunc(NULL)
    , mouseReleaseFunc(NULL)
    , frameResizeFunc(NULL)
    , keyEventFunc(NULL)
{
    resize(width, height);
}

GLWidget::~GLWidget()
{
}

void GLWidget::setMouseMoveFunc(MOUSEEVENT_FUNCPTR func)
{
    mouseMoveFunc = func;
}

void GLWidget::setMousePressFunc(MOUSEEVENT_FUNCPTR func)
{
    mousePressFunc = func;
}

void GLWidget::setMouseReleaseFunc(MOUSEEVENT_FUNCPTR func)
{
    mouseReleaseFunc = func;
}

void
GLWidget::setResizeFunc(RESIZE_FUNCPTR func)
{
    frameResizeFunc = func;
}

void GLWidget::setKeyEventFunc(ACCEL_FUNCPTR func)
{
    keyEventFunc = func;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (mouseMoveFunc)
        mouseMoveFunc(event);

    QGLWidget::mouseMoveEvent(event);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if (mousePressFunc)
        mousePressFunc(event);

    QGLWidget::mousePressEvent(event);
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (mouseReleaseFunc)
        mouseReleaseFunc(event);

    QGLWidget::mouseReleaseEvent(event);
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
    if (keyEventFunc)
        keyEventFunc(e);

    QGLWidget::keyPressEvent(e);
}

void GLWidget::keyReleaseEvent(QKeyEvent *e)
{
    if (keyEventFunc)
        keyEventFunc(e);

    QGLWidget::keyReleaseEvent(e);
}

void
GLWidget::resizeEvent(QResizeEvent *e)
{
    if (frameResizeFunc)
        frameResizeFunc(e);

    QGLWidget::resizeEvent(e);
}

