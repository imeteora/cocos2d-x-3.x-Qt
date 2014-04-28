#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T14:22:11
#
#-------------------------------------------------

TARGET = libCocos2dx
TEMPLATE = lib

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -stdlib=libc++

include(libCocos2dx.pri)

SOURCES +=

HEADERS +=

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES +=
