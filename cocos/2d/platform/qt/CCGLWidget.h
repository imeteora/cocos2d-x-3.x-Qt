#ifndef  _GL_WIDGET_H_
#define  _GL_WIDGET_H_

#include "CCDirector.h"
#include "CCCommon.h"
#undef CursorShape
#include "CCGL.h"
#include <QtOpenGL/QGLWidget>

class QTimer;
USING_NS_CC;

typedef void(*PTRFUN)(QMouseEvent *event);
typedef void(*ACCEL_PTRFUN)(QKeyEvent *event);

class CC_DLL GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    //GLWidget(){}
    explicit GLWidget(QWidget *parent = 0, const int width = 800, const int height = 600);
    virtual ~GLWidget();

    void setMouseMoveFunc(PTRFUN func);
    void setMousePressFunc(PTRFUN func);
    void setMouseReleaseFunc(PTRFUN func);
    void setKeyEventFunc(ACCEL_PTRFUN func);

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);

    virtual void resizeEvent(QResizeEvent *);

public slots:
//    void update();

private:
    PTRFUN mouseMoveFunc;
    PTRFUN mousePressFunc;
    PTRFUN mouseReleaseFunc;

    ACCEL_PTRFUN keyEventFunc;
};

#endif // _GL_WIDGET_H_
