#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T14:22:11
#
#-------------------------------------------------

QT      += core gui opengl

TARGET = libCocos2dx
TEMPLATE = lib

# disble the Qt keywords extension here for cocos2d-x 3.x, there is some qt extension keywords in code.
DEFINES += QT_NO_KEYWORDS

# the cocos2d-x-3.x library
include(libCocos2dx.pri)

DESTDIR = $$PWD/../../bin

win32 {
    TARGET = libcocos2d
}
unix:macx {
    TARGET = cocos2d
}

SOURCES +=

HEADERS +=

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES +=
