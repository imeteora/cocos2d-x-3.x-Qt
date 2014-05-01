#ifndef __Qt__INPUTBOX__
#define __Qt__INPUTBOX__

#include "cocos2d.h"
#include "../GUI/CCEditBox/CCEditBox.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_QT5)

#include <QLineEdit>
#include <QDialog>

class LineEditor : public QDialog
{
    Q_OBJECT
public:
    LineEditor(const char *placeHolder, char *pText, QWidget *parent = 0);
    static bool InputBox(const char *contents, char *pText, int textMaxLen
                         , cocos2d::extension::EditBox::InputMode inputMode
                         , cocos2d::extension::EditBox::InputFlag inputFlag);

    std::string text;

    void accept();
private:
    QLineEdit *m_editor;
};


#endif

#endif
