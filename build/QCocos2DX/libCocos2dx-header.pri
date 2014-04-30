## latest cocos2d-x using c++11 or c++0x, so you will see below.
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_LFLAGS += -lc++
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7

SOURCE_ROOT_DIR = $$PWD/../..
COCOS2D_DIR = $$SOURCE_ROOT_DIR

DEFINES += CC_TARGET_QT5
DEFINES += USE_FILE32API
DEFINES += CC_KEYBOARD_SUPPORT

DEFINES += __QT__
DEFINES += CC_UNDER_QT
DEFINES += COCOS2D_DEBUG=1

unix:macx{
    # system libraries.
    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib/ -lGLEW
    LIBS += -L/usr/local/lib/ -lz

    # prebuilt libraries
    INCLUDEPATH += ../../external/png/include/mac
    LIBS        += -L$$PWD/../../external/curl/prebuilt/mac -lpng

    INCLUDEPATH += ../../external/tiff/include/mac
    LIBS        += -L$$PWD/../../external/tiff/prebuilt/mac -ltiff

    INCLUDEPATH += ../../external/jpeg/include/mac
    LIBS += -L$$PWD/../../external/jpeg/prebuilt/mac -ljpeg

    INCLUDEPATH += ../../external/curl/include/mac
    LIBS        += -L$$PWD/../../external/curl/prebuilt/mac -lcurl

#    INCLUDEPATH += ../../external/glfw3/include/mac
#    LIBS += -L$$PWD/../../external/glfw3/prebuilt/mac -lglfw3

#    INCLUDEPATH += ../../external/openal/include
#    LIBS += -L$$PWD/../../external/openal/prebuilt/mac -lopenal

#    INCLUDEPATH += ../../external/freealut/include
#    LIBS += -L$$PWD/../../external/freealut/prebuilt/mac -lalut

#    INCLUDEPATH += ../../external/libvorbis/include
#    LIBS += -L$$PWD/../../external/libvorbis/prebuilt/mac -lvorbis
#    LIBS += -L$$PWD/../../external/libvorbis/prebuilt/mac -lvorbisenc
#    LIBS += -L$$PWD/../../external/libvorbis/prebuilt/mac -lvorbisfile

    INCLUDEPATH += ../../external/sqlite3/include
    LIBS += -L$$PWD/../../external/sqlite3/libraries/mac -lsqlite3

    INCLUDEPATH += ../../external/freetype2/include/mac
    LIBS += -L$$PWD/../../external/freetype2/prebuilt/mac -lfreetype

    INCLUDEPATH += ../../external/websockets/include/mac
    LIBS += -L$$PWD/../../external/websockets/prebuilt/mac -lwebsockets

    INCLUDEPATH += ../../external/webp/include/mac
    LIBS += -L$$PWD/../../external/webp/prebuilt/mac -lwebp
}

COCOS2D_INCLUDEPATH = \
    $$COCOS2D_DIR \
    $$COCOS2D_DIR/cocos \
    $$COCOS2D_DIR/cocos/2d \
    $$COCOS2D_DIR/cocos/2d/platform \
    $$COCOS2D_DIR/cocos/2d/platform/qt \
    $$COCOS2D_DIR/cocos/2d/platform/renderer \
    $$COCOS2D_DIR/cocos/audio/include \
    $$COCOS2D_DIR/cocos/base \
    $$COCOS2D_DIR/cocos/math/kazmath \
    $$COCOS2D_DIR/cocos/storage/local-storage \
    $$COCOS2D_DIR/cocos/ui \
    $$COCOS2D_DIR/cocos/physics \
    $$COCOS2D_DIR/cocos/physics/chipmunk \
    $$COCOS2D_DIR/external \
    $$COCOS2D_DIR/external/chipmunk/include \
    $$COCOS2D_DIR/external/chipmunk/include/chipmunk \
    $$COCOS2D_DIR/external/edtaa3func \
    $$COCOS2D_DIR/external/tinyxml2 \
    $$COCOS2D_DIR/external/unzip \
    $$COCOS2D_DIR/external/xxhash \
    $$COCOS2D_DIR/external/json \
    $$COCOS2D_DIR/cocos/editor-support \

INCLUDEPATH += $$COCOS2D_INCLUDEPATH

PRECOMPILED_HEADER  += $$COCOS2D_DIR/cocos/base/CCPlatformConfig.h
