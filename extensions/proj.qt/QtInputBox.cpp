#include "QtInputBox.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_QT5)
#include <QHBoxLayout>

LineEditor::LineEditor(const char *contents, char *pText, QWidget *parent)
    : QDialog(parent)
{
    m_editor = new QLineEdit(QString(contents)+QString(pText), this);
    connect(m_editor, SIGNAL(returnPressed()), this, SLOT(accept()));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_editor);
    layout->setMargin(0);
}

bool LineEditor::InputBox(const char *placeHolder, char *pText, int textMaxLen
                          , cocos2d::extension::EditBox::InputMode inputMode
                          , cocos2d::extension::EditBox::InputFlag inputFlag)
{
    Q_UNUSED(inputMode);
    Q_UNUSED(inputFlag);

    bool bRet = false;
    LineEditor *lineEditor = new LineEditor(placeHolder, pText);
    lineEditor->text = std::string(pText);
    lineEditor->exec();
    ::snprintf(pText, textMaxLen, "%s", lineEditor->text.c_str());

    bRet = true;
    return bRet;
}

void LineEditor::accept()
{
    this->text = m_editor->text().toStdString();
    QDialog::accept();
}

#endif /* #if (CC_TARGET_PLATFORM == CC_PLATFORM_QT5) */
