#include "AppDelegate.h"
#include "cocos2d.h"
#include "MainWindow.h"
#include "HelloWorldScene.h"
// Qt
#include <QLabel>
#include <QHBoxLayout>
#include <QGLWidget>

//#include "CCLuaEngine.h"
//#include "lua_extensions.h"
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
    eglView->setFrameSize(640, 480);

    pDirector->setOpenGLView(eglView);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60 );
#if 1
    // create a scene. it's an autorelease object
    Scene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);
#else

    // register lua engine
    CCLuaEngine *pEngine = CCLuaEngine::defaultEngine();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);

    CCLuaStack *pStack = pEngine->getLuaStack();
    lua_State* L = pStack->getLuaState();

    // load lua extensions
    luaopen_lua_extensions(L);

    // FIXME:

    // load cocos2dx_extensions luabinding
    luaopen_cocos2dx_extensions_luabinding(L);
    // load cocos2dx_extra luabinding
    luaopen_cocos2dx_extra_luabinding(L);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    luaopen_cocos2dx_extra_ios_iap_luabinding(L);
#endif

    string path("scripts/main.lua");
    path = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
    size_t p = path.find_last_of("/\\");
    if (p != path.npos)
    {
        const string dir = path.substr(0, p);
        pStack->addSearchPath(dir.c_str());

        p = dir.find_last_of("/\\");
        if (p != dir.npos)
        {
            pStack->addSearchPath(dir.substr(0, p).c_str());
        }
    }

    string env = "__LUA_STARTUP_FILE__=\"";
    env.append(path);
    env.append("\"");
    pEngine->executeString(env.c_str());

    CCLOG("------------------------------------------------");
    CCLOG("LOAD LUA FILE: %s", path.c_str());
    CCLOG("------------------------------------------------");
    pEngine->executeScriptFile(path.c_str());
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
