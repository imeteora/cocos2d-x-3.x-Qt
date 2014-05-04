include(actions.pri)
include(base-nodes.pri)
include(draw-nodes.pri)
include(effects.pri)
include(event-dispatcher.pri)
include(label-nodes.pri)
include(layers-scenes-transitions-nodes.pri)
include(menu-nodes.pri)
include(misc-nodes.pri)
include(particle-nodes.pri)
include(platform.pri)
#include(script-support.pri)
include(shaders.pri)
include(sprite-nodes.pri)
include(support.pri)
include(text-input-node.pri)
include(textures.pri)
include(tilemap-parallax-nodes.pri)
include(renderer.pri)

HEADERS += \
    ../../cocos/2d/cocos2d.h \
    ../../cocos/2d/ccTypes.h \
    ../../cocos/2d/ccConfig.h \
    ../../cocos/2d/CCConfiguration.h \
    ../../cocos/2d/CCDirector.h \
    ../../cocos/2d/CCEventType.h \
    ../../cocos/2d/ccFPSImages.h \
    ../../cocos/2d/CCGLBufferedNode.h \
    ../../cocos/2d/ccMacros.h \
    ../../cocos/2d/CCProtocols.h \
    ../../cocos/2d/CCScheduler.h \
    ../../cocos/2d/firePngData.h \
    ../../cocos/2d/TransformUtils.h \

SOURCES += \
    ../../cocos/2d/ccTypes.cpp \
    ../../cocos/2d/CCConfiguration.cpp \
    ../../cocos/2d/CCDirector.cpp \
    ../../cocos/2d/ccFPSImages.c \
    ../../cocos/2d/CCGLBufferedNode.cpp \
    ../../cocos/2d/CCScheduler.cpp \
    ../../cocos/2d/cocos2d.cpp \
    ../../cocos/2d/TransformUtils.cpp \
