#include "AppDelegate.h"
#include "cocos2d.h"
#include "MainWindow.h"
#include "HelloWorldScene.h"

// Qt
#include <QLabel>
#include <QHBoxLayout>
#include <QGLWidget>

#include "CCLuaEngine.h"
#include "lua_extensions.h"
//#include "cocos2dx_extensions_luabinding.h"
//#include "cocos2dx_extra_luabinding.h"

USING_NS_CC;

AppDelegate::AppDelegate(int argc, char *argv[])
    : Application(argc, argv)
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    Director* pDirector = Director::getInstance();
    cocos2d::GLView* eglView = cocos2d::GLView::createWithWidget(m_mainWindow.getGLViewSuperWidget());
//    cocos2d::GLView *eglView = cocos2d::GLView::createWithRect("HelloCocos2d",cocos2d::Rect(0,0,960,640));

    //    eglView->setFrameSize(960, 640);
    eglView->setDesignResolutionSize(960,640,ResolutionPolicy::NO_BORDER);
    pDirector->setOpenGLView(eglView);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60 );
#ifdef defx
    // create a scene. it's an autorelease object
    Scene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

#else

    // register lua engine
    LuaEngine *pEngine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(pEngine);

    LuaStack *pStack = pEngine->getLuaStack();
    lua_State* L = pStack->getLuaState();

//    // load lua extensions
//    luaopen_lua_extensions(L);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    luaopen_cocos2dx_extra_ios_iap_luabinding(L);
#endif

//    CCLOG("------------------------------------------------");
//    CCLOG("LOAD LUA FILE: %s", path.c_str());
//    CCLOG("------------------------------------------------");
//    pEngine->executeScriptFile(path.c_str());

    pEngine->executeScriptFile("src/hello.lua");

#endif
//    m_mainWindow.setCocosAppDelegate(this);
    m_mainWindow.show();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

const char * AppDelegate::getCurrentLanguageCode()
{
    return (const char*)NULL;
}
