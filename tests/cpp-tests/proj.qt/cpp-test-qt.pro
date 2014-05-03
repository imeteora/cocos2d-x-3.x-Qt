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
        }
    }
}

include(BaseTest.pri)
include(AccelerometerTest.pri)
include(ActionManagerTest.pri)
include(ActionsEaseTest.pri)
include(ActionsProgressTest.pri)
include(ActionsTest.pri)
include(Box2DTest.pri)
include(Box2DTestBed.pri)
include(BugsTest.pri)
include(ChipmunkTest.pri)
include(ClickAndMoveTest.pri)
include(ClippingNodeTest.pri)
include(CocosDenshionTest.pri)
include(ConfigurationTest.pri)
include(ConsoleTest.pri)
include(CurlTest.pri)
include(CurrentLanguageTest.pri)
include(DataVisitorTest.pri)
include(DrawPrimitivesTest.pri)
include(EffectsAdvancedTest.pri)
include(EffectsTest.pri)
include(ExtensionsTest.pri)
include(FileUtilsTest.pri)
include(FontTest.pri)
include(InputTest.pri)
include(IntervalTest.pri)
include(KeyboardTest.pri)
include(KeypadTest.pri)
include(LabelTest.pri)
include(LayerTest.pri)
include(MenuTest.pri)
include(MotionStreakTest.pri)
include(MutiTouchTest.pri)
include(NewEventDispatcherTest.pri)
include(NewRendererTest.pri)
include(NodeTest.pri)
include(ParallaxTest.pri)
include(ParticleTest.pri)
include(PerformanceTest.pri)
include(PhysicsTest.pri)
include(ReleasePoolTest.pri)
include(RenderTextureTest.pri)
include(RotateWorldTest.pri)
include(SceneTest.pri)
include(SchedulerTest.pri)
include(ShaderTest.pri)
include(SpineTest.pri)
include(SpriteTest.pri)
include(TextInputTest.pri)
include(Texture2dTest.pri)
include(TextureCacheTest.pri)
include(TexturePackerEncryptionTest.pri)
include(TileMapTest.pri)
include(TouchesTest.pri)
include(TransitionsTest.pri)
include(UnitTest.pri)
include(UserDefaultTest.pri)
include(ZwoptexTest.pri)

INCLUDEPATH += \
    $$PWD   \
    $$PWD/src   \
    $$PWD/../Classes \

SOURCES += main.cpp\
    AppDelegate.cpp \
    src/MainWindow.cpp \

HEADERS  += \
    AppDelegate.h \
    src/MainWindow.h \

FORMS    += \
    ui/MainWindow.ui

OTHER_FILES += \

