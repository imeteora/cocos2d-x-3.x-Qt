#-------------------------------------------------
#
# Project created by QtCreator 2014-05-03T17:16:06
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPPTestForQt
TEMPLATE = app

include(../../../build/QCocos2DX/libCocos2dx-header.pri)
DESTDIR = $$PWD/../../../bin

APP_BUNDLE  = ${DESTDIR}CPPTestForQt.app
DEPLOY_RES  = $$PWD/../Resources
LIBS    += -L$$PWD/../../../bin -lcocos2d

macx {
    contains(CONFIG, app_bundle) {
        QMAKE_INFO_PLIST    = $$PWD/Info.plist
        ICON                = $$PWD/Images/Icons/icon_mac.icns
#        QMAKE_POST_LINK += ${QTDIR}/bin/lupdate $$PWD/HelloCocos2D.pro &
#        QMAKE_POST_LINK += ${QTDIR}/bin/lrelease $$PWD/HelloCocos2D.pro &
        QMAKE_POST_LINK     += ${QTDIR}/bin/macdeployqt $$APP_BUNDLE -verbose=1 &
        contains(CONFIG, shared) {
            QMAKE_POST_LINK += cp -R $$DEPLOY_RES/* $$APP_BUNDLE/Contents/Resources &
            QMAKE_POST_LINK += cp -R $$PWD/../../../bin/libcocos2d.1.0.0.dylib $$APP_BUNDLE/Contents/Frameworks/libcocos2d.1.dylib &
#            QMAKE_POST_LINK += ln -s $$APP_BUNDLE/Contents/Frameworks/libcocos2d.1.0.0.dylib $$APP_BUNDLE/Contents/Frameworks/libcocos2d.dylib &
#            QMAKE_POST_LINK += ln -s $$APP_BUNDLE/Contents/Frameworks/libcocos2d.1.0.0.dylib $$APP_BUNDLE/Contents/Frameworks/libcocos2d.1.dylib &
#            QMAKE_POST_LINK += ln -s $$APP_BUNDLE/Contents/Frameworks/libcocos2d.1.0.0.dylib $$APP_BUNDLE/Contents/Frameworks/libcocos2d.1.0.dylib &
        }
    }
}

SOURCES += main.cpp\
    MainWindow.cpp

HEADERS  += \
    MainWindow.h

FORMS    += \
    MainWindow.ui


