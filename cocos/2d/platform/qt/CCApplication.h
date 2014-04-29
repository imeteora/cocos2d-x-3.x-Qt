#ifndef __CC_APPLICATION_WIN32_H__
#define __CC_APPLICATION_WIN32_H__

#include "CCStdC.h"
#include "platform/CCCommon.h"
#include "platform/CCApplicationProtocol.h"
#include <string>

#undef CursorShape
#include <QApplication>

NS_CC_BEGIN

//class CCRect;

class CC_DLL Application : public QApplication, public ApplicationProtocol
{
    Q_OBJECT
public:
    Application(int argc, char *argv[]);
    virtual ~Application();

    /**
    @brief    Run the message loop.
    */
    int run();

    /**
    @brief    Get current applicaiton instance.
    @return Current application instance pointer.
    */
    static Application* getInstance();

    /* override functions */
    virtual void setAnimationInterval(double interval);
    virtual LanguageType getCurrentLanguage();
    
    /**
     @brief Get target platform
     */
    virtual Platform getTargetPlatform();

    const std::string& getStartupScriptFilename(void) {
        return m_startupScriptFilename;
    }
    void setStartupScriptFilename(const std::string& startupScriptFile);

public slots:
    void timerUpdate();

protected:
    long long           m_nAnimationInterval;
    std::string         m_startupScriptFilename;

    static Application * sm_pSharedApplication;

private:
    QTimer *m_timer;
    int m_refCount;
};

NS_CC_END

#endif    // __CC_APPLICATION_WIN32_H__
