#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T14:22:11
#
#-------------------------------------------------

QT      += core gui opengl

TARGET = libCocos2dx
TEMPLATE = lib
CONFIG += shared

# disble the Qt keywords extension here for cocos2d-x 3.x,
# there is some qt extension keywords in code.
DEFINES += QT_NO_KEYWORDS

# the cocos2d-x-3.x library
include($$PWD/libCocos2dx.pri)
include($$PWD/../../external/log4qt/src/log4qt/log4qt.pri)

DESTDIR = $$PWD/../../bin

win32 {
    TARGET = libcocos2d
}
unix:macx {
    TARGET = cocos2d
}

macx {
    LIBS    += -framework Cocoa
    LIBS    += -framework Foundation
}
#unix:!symbian {
#    maemo5 {
#        target.path = /opt/usr/lib
#    } else {
#        target.path = /usr/lib
#    }
#    INSTALLS += target
#}

SOURCES +=

HEADERS +=

OTHER_FILES +=
