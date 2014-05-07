#include "CCGLWidget.h"
#include <QResizeEvent>

GLWidget::GLWidget(QWidget *parent, const int width, const int height)
    : QGLWidget(QGLFormat(QGL::SampleBuffers | QGL::DoubleBuffer), parent)
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
    CCTRACE();
    if (mouseMoveFunc)
        mouseMoveFunc(event);

    QGLWidget::mouseMoveEvent(event);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    CCTRACE();
    if (mousePressFunc)
        mousePressFunc(event);

    QGLWidget::mousePressEvent(event);
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    CCTRACE();
    if (mouseReleaseFunc)
        mouseReleaseFunc(event);

    QGLWidget::mouseReleaseEvent(event);
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
    CCTRACE();
    if (keyEventFunc)
        keyEventFunc(e);

    QGLWidget::keyPressEvent(e);
}

void GLWidget::keyReleaseEvent(QKeyEvent *e)
{
    CCTRACE();
    if (keyEventFunc)
        keyEventFunc(e);

    QGLWidget::keyReleaseEvent(e);
}

void
GLWidget::resizeEvent(QResizeEvent *event)
{
    CCTRACE();
    QSize newSize = event->size();
    resize(newSize);

    if (frameResizeFunc)
        frameResizeFunc(event);

    QGLWidget::resizeEvent(event);
}

