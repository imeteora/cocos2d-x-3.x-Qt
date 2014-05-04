#include "MainWindow.h"
#include "cocos2d.h"
#include "AppDelegate.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    AppDelegate app(argc, argv);
    return cocos2d::Application::getInstance()->run();
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
}
