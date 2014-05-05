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

include($$PWD/../../build/QCocos2DX/libCocos2dx-header.pri)

DESTDIR = $$PWD/../../bin

APP_BUNDLE  = ${DESTDIR}/HelloCocos2D.app
DEPLOY_RES  = $$PWD/media/deploy
LIBS    += -L$$PWD/../../bin -lcocos2d

macx {
    contains(CONFIG, app_bundle) {
        QMAKE_INFO_PLIST    = Info.plist
        ICON                = $$PWD/Images/Icons/icon_mac.icns
#        QMAKE_POST_LINK += ${QTDIR}/bin/lupdate $$PWD/HelloCocos2D.pro &
#        QMAKE_POST_LINK += ${QTDIR}/bin/lrelease $$PWD/HelloCocos2D.pro &
        QMAKE_POST_LINK     += ${QTDIR}/bin/macdeployqt $$APP_BUNDLE -verbose=1 &
        contains(CONFIG, shared) {
            QMAKE_POST_LINK += cp -f $$PWD/../../bin/libcocos2d.1.0.0.dylib $$APP_BUNDLE/Contents/Frameworks/libcocos2d.1.dylib &
            QMAKE_POST_LINK += cp -R $$DEPLOY_RES/* $$APP_BUNDLE/Contents/Resources &
        }
    }
}

INCLUDEPATH += \
    $$PWD/src \

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
