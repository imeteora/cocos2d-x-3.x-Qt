#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T18:29:39
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = HelloCocos2D
TEMPLATE    = app
#CONFIG      -= app_bundle       # some thing needs to be reviewed.

DESTDIR = $$PWD/../../bin

APP_BUNDLE  = ${DESTDIR}/HelloCocos2D.app
DEPLOY_RES  = $$PWD/media/deploy
SCRIPTS_RES = $$PWD/../../cocos/scripting/lua-bindings/script

include($$PWD/../../build/QCocos2DX/libCocos2dx-header.pri)

LIBS    += $$PWD/../../bin/libcocos2d.1.0.0.dylib
LIBS    += $$PWD/../../external/openal/prebuilt/mac/libopenal.dylib

macx {
    contains(CONFIG, app_bundle) {
        QMAKE_INFO_PLIST    = Info.plist
        ICON                = $$PWD/Images/Icons/icon_mac.icns

        QMAKE_POST_LINK += cp -R $$SCRIPTS_RES/*.lua $$APP_BUNDLE/Contents/Resources &
        QMAKE_POST_LINK += cp -R $$DEPLOY_RES/* $$APP_BUNDLE/Contents/Resources &

    }
}

INCLUDEPATH += \
    $$PWD/src \
    $$PWD/../../external/openal/prebuilt/include/ \

SOURCES += main.cpp \
    src/MainWindow.cpp \
    src/AppDelegate.cpp \
    src/HelloWorldScene.cpp

HEADERS  += \
    src/MainWindow.h \
    src/AppDelegate.h \
    src/HelloWorldScene.h

FORMS    += \
    ui/MainWindow.ui

OTHER_FILES += \
    $$PWD/../../bin/CloseNormal.png \
