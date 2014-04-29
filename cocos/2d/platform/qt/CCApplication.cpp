#include "CCApplication.h"
#include "CCGLView.h"
#include "CCDirector.h"
#include <algorithm>
#include "platform/CCFileUtils.h"

#include <QTimer>
/**
@brief    This function change the PVRFrame show/hide setting in register.
@param  bEnable If true show the PVRFrame window, otherwise hide.
*/
static void PVRFrameEnableControlWindow(bool bEnable);

NS_CC_BEGIN

// sharedApplication pointer
Application * Application::sm_pSharedApplication = 0;

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv)
    , m_timer(NULL)
    , m_refCount(0)
{
    m_nAnimationInterval = 1.0f / 60.0f * 1000.0f;
    CC_ASSERT(! sm_pSharedApplication);
    sm_pSharedApplication = this;
}

Application::~Application()
{
    CC_ASSERT(this == sm_pSharedApplication);
    sm_pSharedApplication = NULL;
}

int Application::run()
{
    // Initialize instance and cocos2d.
    if (!applicationDidFinishLaunching())
    {
        return 0;
    }

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    m_timer->start(m_nAnimationInterval);

    return cocos2d::Application::getInstance()->exec();
}

void Application::setAnimationInterval(double interval)
{
    m_nAnimationInterval = interval * 1000.0f;
    if (m_timer)
    {
        m_timer->start(m_nAnimationInterval);
    }
}

//////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////
Application* Application::getInstance()
{
    CC_ASSERT(sm_pSharedApplication);
    return sm_pSharedApplication;
}

LanguageType Application::getCurrentLanguage()
{
    switch (QLocale::system().language())
    {
    case QLocale::Chinese: return LanguageType::CHINESE;
    case QLocale::French:  return LanguageType::FRENCH;
    case QLocale::Italian: return LanguageType::ITALIAN;
    case QLocale::German:  return LanguageType::GERMAN;
    case QLocale::Spanish: return LanguageType::SPANISH;
    case QLocale::Russian: return LanguageType::RUSSIAN;
    case QLocale::Polish:   return LanguageType::POLISH;
    case QLocale::Norwegian:    return LanguageType::NORWEGIAN;
    default:               return LanguageType::ENGLISH;
    }
}

ApplicationProtocol::Platform Application::getTargetPlatform()
{
    return Platform::OS_MAC;
}

void Application::setStartupScriptFilename(const std::string& startupScriptFile)
{
    m_startupScriptFilename = startupScriptFile;
    int pos;
    while ((pos = m_startupScriptFilename.find_first_of("\\")) != std::string::npos)
    {
        m_startupScriptFilename.replace(pos, 1, "/");
    }
}

void Application::timerUpdate()
{
    // m_refCount is here to prevent calling the mainloop from nested event loops
    if (!m_refCount)
    {
        Director::getInstance()->mainLoop();
    }
}

NS_CC_END

