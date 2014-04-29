#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "CCApplication.h"
#include "mainwindow.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by CCDirector.
*/
class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate(int argc, char *argv[]);
    virtual ~AppDelegate();

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    * @js NA
    * @lua NA
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  This function will be called when the application enters background.
    * @js NA
    * @lua NA
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  This function will be called when the application enters foreground.
    * @js NA
    * @lua NA
    */
    virtual void applicationWillEnterForeground();

    /**
     @brief Get current language iso 639-1 code
     @return Current language iso 639-1 code
     * @js NA
     * @lua NA
     */
    virtual const char * getCurrentLanguageCode();

private:
    MainWindow m_mainWindow;
};

#endif // _APP_DELEGATE_H_

