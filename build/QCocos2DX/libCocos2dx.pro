#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T14:22:11
#
#-------------------------------------------------

QT      += core gui opengl

TARGET = libCocos2dx
TEMPLATE = lib

DEFINES += QT_NO_KEYWORDS

include(libCocos2dx.pri)

SOURCES +=

HEADERS +=

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES +=
