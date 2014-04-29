#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T18:29:39
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = HelloCocos2D
TEMPLATE = app
CONFIG  -= app_bundle       # some thing needs to be reviewed.

include($$PWD/../../build/QCocos2DX/libCocos2dx-header.pri)

DESTDIR = $$COCOS2D_DIR/bin

INCLUDEPATH += \
    $$PWD/src \

LIBS    += \
    -L$$COCOS2D_DIR/bin -lcocos2d

SOURCES += main.cpp \
    src/MainWindow.cpp \
    src/AppDelegate.cpp \

#    src/HelloWorldScene.cpp

HEADERS  += \
    src/MainWindow.h \
    src/AppDelegate.h \

#    src/HelloWorldScene.h

FORMS    += \
    ui/MainWindow.ui

