#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "extensions/GUI/CCEditBox/CCEditBoxImpl.h"
#include "extensions/GUI/CCEditBox/CCEditBoxImplMac.h"
//#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HelloWorld : public cocos2d::Layer, public cocos2d::extension::EditBoxDelegate
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::Scene* scene();
    static HelloWorld* curHelloWorld();
	
	// a selector callback
    virtual void menuCloseCallback(Ref* pSender);

	// implement the "static node()" method manually
    CREATE_FUNC(HelloWorld)

    void addSpriteRamdon(float dt);
    void addSpriteRamdon2(float dt);

    void addEditBox(float dt);
    virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);

//    void didAccelerate(cocos2d::CCAcceleration* pAccelerationValue);
private:
    cocos2d::Label *m_label;
    cocos2d::Sprite *m_pBall;
};

#endif // __HELLOWORLD_SCENE_H__
