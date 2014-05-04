include(chipmunk.pri)
include(box2d.pri)
include(lua_external.pri)

HEADERS += \
    ../../external/edtaa3func/edtaa3func.h \
    ../../external/tinyxml2/tinyxml2.h \
    ../../external/unzip/ioapi.h \
    ../../external/unzip/unzip.h \
    ../../external/xxhash/xxhash.h \
    ../../external/chipmunk/src/prime.h \

SOURCES += \
    ../../external/edtaa3func/edtaa3func.cpp \
    ../../external/tinyxml2/tinyxml2.cpp \
    ../../external/unzip/ioapi.cpp \
    ../../external/unzip/unzip.cpp \
    ../../external/xxhash/xxhash.c \
