/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2013 Jozef Pridavok
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "CCEditBoxImplQt.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_QT5)

#include "CCEditBoxImpl.h"
#include "proj.qt/QtInputBox.h"

NS_CC_BEGIN
extern CC_DLL long cc_utf8_strlen (const char * p, int max);
NS_CC_END

NS_CC_EXT_BEGIN

EditBoxImpl* __createSystemEditBox(EditBox* pEditBox)
{
    return new EditBoxImplQt(pEditBox);
}

EditBoxImplQt::EditBoxImplQt(EditBox *pEditText)
: EditBoxImpl(pEditText)
, m_pLabel(NULL)
, m_pLabelPlaceHolder(NULL)
, m_eEditBoxInputMode(EditBox::InputMode::EMAIL_ADDRESS)
, m_eEditBoxInputFlag(EditBox::InputFlag::INITIAL_CAPS_WORD)
, m_eKeyboardReturnType(EditBox::KeyboardReturnType::DEFAULT)
, m_colText(Color3B::WHITE)
, m_colPlaceHolder(Color3B::GRAY)
, m_nMaxLength(-1)
{
    
}

EditBoxImplQt::~EditBoxImplQt()
{
}

void EditBoxImplQt::doAnimationWhenKeyboardMove(float duration, float distance)
{
}

bool EditBoxImplQt::initWithSize(const Size &size)
{
    //! int fontSize = getFontSizeAccordingHeightJni(size.height-12);
    m_pLabel = Label::createWithSystemFont("", "Helvetica",14);         // LabelTTF::create("", "", size.height-12);
    m_pLabel->setAnchorPoint(Point::ZERO);
    m_pLabel->setPosition(Point(5, 2));
    m_pLabel->setColor(m_colText);
    _editBox->addChild(m_pLabel);

    m_pLabelPlaceHolder = Label::createWithSystemFont("", "Helvetica", 14);    //LabelTTF::create("", "", size.height-12);
    m_pLabelPlaceHolder->setAnchorPoint(Point::ZERO);
    m_pLabelPlaceHolder->setPosition(Point(5, 2));
    m_pLabelPlaceHolder->setVisible(false);
    m_pLabelPlaceHolder->setColor(m_colPlaceHolder);
    _editBox->addChild(m_pLabelPlaceHolder);
    
    m_EditSize = size;
    return true;
}

void EditBoxImplQt::setFontColor(const Color3B& color)
{
    m_colText = color;
    m_pLabel->setColor(color);
}

void EditBoxImplQt::setPlaceholderFontColor(const Color3B& color)
{
    m_colPlaceHolder = color;
    m_pLabelPlaceHolder->setColor(color);
}

void EditBoxImplQt::setInputMode(EditBox::InputMode inputMode)
{
    m_eEditBoxInputMode = inputMode;
}

void EditBoxImplQt::setMaxLength(int maxLength)
{
    m_nMaxLength = maxLength;
}

int EditBoxImplQt::getMaxLength()
{
    return m_nMaxLength;
}

void EditBoxImplQt::setInputFlag(EditBox::InputFlag inputFlag)
{
    m_eEditBoxInputFlag = inputFlag;
}

void EditBoxImplQt::setReturnType(EditBox::KeyboardReturnType returnType)
{
    m_eKeyboardReturnType = returnType;
}

bool EditBoxImplQt::isEditing()
{
    return false;
}

void EditBoxImplQt::setText(const char* pText)
{
    if (pText != NULL)
    {
        m_strText = pText;

        if (m_strText.length() > 0)
        {
            m_pLabelPlaceHolder->setVisible(false);

            std::string strToShow;

            if ( EditBox::InputFlag::PASSWORD == m_eEditBoxInputFlag)
            {
                long length = cc_utf8_strlen(m_strText.c_str(), -1);
                for (long i = 0; i < length; i++)
                {
                    strToShow.append("*");
                }
            }
            else
            {
                strToShow = m_strText;
            }

            //! std::string strWithEllipsis = getStringWithEllipsisJni(strToShow.c_str(), m_EditSize.width, m_EditSize.height-12);
            //! m_pLabel->setString(strWithEllipsis.c_str());
			m_pLabel->setString(strToShow.c_str());
        }
        else
        {
            m_pLabelPlaceHolder->setVisible(true);
            m_pLabel->setString("");
        }

    }
}

const char*  EditBoxImplQt::getText(void)
{
    return m_strText.c_str();
}

void EditBoxImplQt::setPlaceHolder(const char* pText)
{
    if (pText != NULL)
    {
        m_strPlaceHolder = pText;
        if (m_strPlaceHolder.length() > 0 && m_strText.length() == 0)
        {
            m_pLabelPlaceHolder->setVisible(true);
        }

        m_pLabelPlaceHolder->setString(m_strPlaceHolder.c_str());
    }
}

void EditBoxImplQt::setPosition(const Point &pos)
{
	//m_pLabel->setPosition(pos);
	//m_pLabelPlaceHolder->setPosition(pos);
}

void EditBoxImplQt::setContentSize(const Size& size)
{
}

void EditBoxImplQt::visit(void)
{   
}

//static void editBoxCallbackFunc(const char* pText, void* ctx)
//{
//    EditBoxImplQt* thiz = (EditBoxImplQt*)ctx;
//    thiz->setText(pText);

//    if (thiz->getDelegate() != NULL)
//    {
//        thiz->getDelegate()->editBoxTextChanged(thiz->getEditBox(), thiz->getText());
//        thiz->getDelegate()->editBoxEditingDidEnd(thiz->getEditBox());
//        thiz->getDelegate()->editBoxReturn(thiz->getCCEditBox());
//    }

//    int handler = thiz->getScriptEditBoxHandler();
//    if (handler)
//    {
//        cocos2d::ScriptEngineProtocol* pEngine = cocos2d::ScriptEngineManager::getInstance()->getScriptEngine();
//        pEngine->executeEvent(handler, "changed");
//        pEngine->executeEvent(handler, "ended");
//        pEngine->executeEvent(handler, "return");
//    }
//}

void EditBoxImplQt::openKeyboard()
{
    if (_delegate != NULL)
    {
        _delegate->editBoxEditingDidBegin(_editBox);
    }

	std::string placeHolder = m_pLabelPlaceHolder->getString();
	if (placeHolder.length() == 0)
		placeHolder = "Enter value";

	char pText[100]= {0};
	std::string text = getText();
	if (text.length())
		strncpy(pText, text.c_str(), 100);

    bool didChange = LineEditor::InputBox(placeHolder.c_str(), pText, 100, m_eEditBoxInputMode, m_eEditBoxInputFlag);

    if (didChange)
        setText(pText);

    if (_delegate != NULL) {
		if (didChange)
            _delegate->editBoxTextChanged(_editBox, getText());
        _delegate->editBoxEditingDidEnd(_editBox);
        _delegate->editBoxReturn(_editBox);
	}

//	if (m_nScriptEditBoxHandler)
//    {
//        cocos2d::ScriptEngineProtocol* pEngine = cocos2d::ScriptEngineManager::getInstance()->getScriptEngine();
//        if (didChange)
//        {
//            pEngine->executeEvent(m_nScriptEditBoxHandler, "changed");
//        }
//        pEngine->executeEvent(m_nScriptEditBoxHandler, "ended");
//        pEngine->executeEvent(m_nScriptEditBoxHandler, "return");
//    }
}

void EditBoxImplQt::closeKeyboard()
{

}

void
EditBoxImplQt::setVisible(bool visible)
{
    CCLOG("Not Implement yet.");
}

void
EditBoxImplQt::setAnchorPoint(const Point &anchorPoint)
{
    CCLOG("Not Implement yet.");
}

void
EditBoxImplQt::setPlaceholderFont(const char *pFontName, int fontSize)
{
    CCLOG("Not Implement yet.");
}

void
EditBoxImplQt::onEnter()
{
    CCLOG("Not Implement yet.");
}

void
EditBoxImplQt::setFont(const char *pFontName, int fontSize)
{
    CCLOG("Not Implement yet.");
}

NS_CC_EXT_END

#endif /* (CC_TARGET_PLATFORM == CC_PLATFORM_QT5) */
