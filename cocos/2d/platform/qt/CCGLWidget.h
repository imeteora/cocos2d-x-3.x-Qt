#ifndef  _GL_WIDGET_H_
#define  _GL_WIDGET_H_

#include "CCDirector.h"
#include "CCCommon.h"
#undef CursorShape
#include "CCGL.h"
#include <QtOpenGL/QGLWidget>

class QTimer;
USING_NS_CC;

typedef void(*MOUSEEVENT_FUNCPTR)(QMouseEvent *event);
typedef void(*RESIZE_FUNCPTR)(QResizeEvent* event);
typedef void(*ACCEL_FUNCPTR)(QKeyEvent *event);

class CC_DLL GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0, const int width = 800, const int height = 600);
    virtual ~GLWidget();

    void setMouseMoveFunc( MOUSEEVENT_FUNCPTR func);
    void setMousePressFunc( MOUSEEVENT_FUNCPTR func);
    void setMouseReleaseFunc( MOUSEEVENT_FUNCPTR func);
    void setResizeFunc( RESIZE_FUNCPTR func);
    void setKeyEventFunc( ACCEL_FUNCPTR func);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    MOUSEEVENT_FUNCPTR mouseMoveFunc;
    MOUSEEVENT_FUNCPTR mousePressFunc;
    MOUSEEVENT_FUNCPTR mouseReleaseFunc;
    RESIZE_FUNCPTR frameResizeFunc;

    ACCEL_FUNCPTR keyEventFunc;
};

#endif // _GL_WIDGET_H_
