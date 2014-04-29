## latest cocos2d-x using c++11 or c++0x, so you will see below.
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7

SOURCE_ROOT_DIR = $$PWD/../..
COCOS2D_DIR = $$SOURCE_ROOT_DIR/cocos

DEFINES += CC_TARGET_QT5
DEFINES += USE_FILE32API
DEFINES += CC_KEYBOARD_SUPPORT

DEFINES += __QT__
DEFINES += CC_UNDER_QT
DEFINES += COCOS2D_DEBUG=1

unix:macx{
    # system libraries.
    INCLUDEPATH += /usr/local/include \
        /usr/include/libxml2 \
        /usr/local/include/webp \
        /usr/local/include/freetype2 \

    LIBS += -L/usr/local/lib/ -lpng
    LIBS += -L/usr/local/lib/ -ljpeg
    LIBS += -L/usr/local/lib/ -lxml2
    LIBS += -L/usr/local/lib/ -lGLEW
    LIBS += -L/usr/local/lib/ -lz
    LIBS += -L/usr/local/lib/ -lcurl
    LIBS += -L/usr/local/lib/ -lwebp
    LIBS += -L/usr/local/lib/ -lwebpdecoder
    LIBS += -L/usr/local/lib/ -ltiff
    LIBS += -L/usr/local/lib/ -lfreetype

    # prebuilt libraries
    INCLUDEPATH += ../../external/glfw3/include/mac
    INCLUDEPATH += ../../external/openal/include
    INCLUDEPATH += ../../external/libvorbis/include \
    LIBS += -L$$PWD/../../external/glfw3/prebuilt/mac -lglfw3
    LIBS += -L$$PWD/../../external/openal/prebuilt/mac -lopenal
    LIBS += -L$$PWD/../../external/libvorbis/prebuilt/mac -lvorbis
    LIBS += -L$$PWD/../../external/libvorbis/prebuilt/mac -lvorbisenc
    LIBS += -L$$PWD/../../external/libvorbis/prebuilt/mac -lvorbisfile
}

COCOS2D_INCLUDEPATH = \
    $$COCOS2D_DIR \
    $$COCOS2D_DIR/.. \
    $$COCOS2D_DIR/2d \
    $$COCOS2D_DIR/2d/platform \
    $$COCOS2D_DIR/2d/platform/qt \
    $$COCOS2D_DIR/2d/platform/renderer \
    $$COCOS2D_DIR/audio/include \
    $$COCOS2D_DIR/base \
    $$COCOS2D_DIR/editor-support \
    $$COCOS2D_DIR/math/kazmath \
    $$COCOS2D_DIR/storage/local-storage \
    $$COCOS2D_DIR/ui \
    $$COCOS2D_DIR/physics \
    $$COCOS2D_DIR/physics/chipmunk \
    $$COCOS2D_DIR/../external \
    $$COCOS2D_DIR/../external/chipmunk/include \
    $$COCOS2D_DIR/../external/chipmunk/include/chipmunk \
    $$COCOS2D_DIR/../external/edtaa3func \
    $$COCOS2D_DIR/../external/tinyxml2 \
    $$COCOS2D_DIR/../external/unzip \
    $$COCOS2D_DIR/../external/xxhash \
    $$COCOS2D_DIR/../external/json \

INCLUDEPATH += $$COCOS2D_INCLUDEPATH
