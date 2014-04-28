SOURCE_ROOT_DIR = $$PWD/../..

COCOS2D_DIR = $$SOURCE_ROOT_DIR/cocos

QT      += core gui opengl

DEFINES += USE_FILE32API
DEFINES += CC_TARGET_QT5
DEFINES += CC_KEYBOARD_SUPPORT

DEFINES += __QT__
DEFINES += CC_UNDER_QT

unix:macx{
    INCLUDEPATH += /usr/local/include \
        /usr/include/libxml2 \

    LIBS += -L/usr/local/lib/ -lpng
    LIBS += -L/usr/local/lib/ -ljpeg
    LIBS += -L/usr/local/lib/ -lxml2
    LIBS += -L/usr/local/lib/ -lGLEW
    LIBS += -L/usr/local/lib/ -lz
    LIBS += -L/usr/local/lib/ -lcurl
    LIBS += -L/usr/local/lib/ -lwebp
    LIBS += -L/usr/local/lib/ -lwebpdecoder
    LIBS += -L/usr/local/lib/ -ltiff
}

COCOS2D_INCLUDEPATH = \
    $$COCOS2D_DIR \
    $$COCOS2D_DIR/2d \
    $$COCOS2D_DIR/2d/platform \
    $$COCOS2D_DIR/2d/platform/mac \
    $$COCOS2D_DIR/2d/platform/qt \
    $$COCOS2D_DIR/2d/platform/renderer \
    $$COCOS2D_DIR/base \
    $$COCOS2D_DIR/math/kazmath \
    $$COCOS2D_DIR/storage/local-storage \
    $$COCOS2D_DIR/ui \
    $$COCOS2D_DIR/physics \
    $$COCOS2D_DIR/physics/chipmunk \

INCLUDEPATH += $$COCOS2D_INCLUDEPATH
