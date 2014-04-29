#include "MainWindow.h"
#include "AppDelegate.h"
#include "cocos2d.h"
#include <QApplication>

USING_NS_CC;

int main(int argc, char *argv[])
{
#if 1
    AppDelegate app(argc, argv);

    return Application::getInstance()->run();

#else
    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();

    return a.exec();
#endif
}
