#include "HelloWorldScene.h"
//#include <cocos-ext.h>

USING_NS_CC;
//USING_NS_CC_EXT;

static HelloWorld *g_pHelloWorld = NULL;
CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
	
	// 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
    g_pHelloWorld = layer;

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

HelloWorld * HelloWorld::curHelloWorld()
{
    return g_pHelloWorld;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
    }

    /////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
										"CloseNormal.png",
										"CloseSelected.png",
										this,
										menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

	// create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition( CCPointZero );
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World By Qt", "Arial", 24);
    m_label = pLabel;
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLog("HelloWorldScene: %lf, %lf", size.width, size.height);

	// position the label on the center of the screen
	pLabel->setPosition( ccp(size.width / 2, size.height - 50) );

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);

    this->schedule(schedule_selector(HelloWorld::addSpriteRamdon), 2.0f);
    this->addEditBox(0);

    this->setAccelerometerEnabled(true);

    // test for accelerometer
    m_pBall = NULL;
    {
        m_pBall = CCSprite::create("Pea.png");
        m_pBall->setPosition( ccp(size.width/2, size.height/2) );
        addChild(m_pBall);
    }
	return true;
}

void HelloWorld::menuCloseCallback(CCObject* /*pSender*/)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_QT)
    exit(0);
#endif
}

void HelloWorld::addSpriteRamdon(float /*dt*/)
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *pSprite = CCSprite::create("CloseNormal.png");
    pSprite->setPosition(ccp(CCRANDOM_0_1()*size.width, CCRANDOM_0_1()*size.height));
    this->addChild(pSprite);
}

void HelloWorld::addSpriteRamdon2(float /*dt*/)
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *pSprite = CCSprite::create("Qt.png");
    pSprite->setPosition(ccp(CCRANDOM_0_1()*size.width, CCRANDOM_0_1()*size.height));
    this->addChild(pSprite);


    CCParticleSystemQuad *fire = CCParticleFireworks::create();
    this->addChild(fire);
    fire->setPosition(ccp(CCRANDOM_0_1()*size.width, CCRANDOM_0_1()*size.height));
    fire->setTexture( CCTextureCache::sharedTextureCache()->addImage("Qt.png") );
}

void HelloWorld::addEditBox(float /*dt*/)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize editBoxSize = CCSizeMake(winSize.width, 60);
    // bottom
    CCEditBox *m_pEditEmail = CCEditBox::create(CCSizeMake(editBoxSize.width, editBoxSize.height), CCScale9Sprite::create("yellow_edit.png"));
    m_pEditEmail->setPosition(ccp(winSize.width/2, 100));
    m_pEditEmail->setAnchorPoint(ccp(0.5, 1.0f));
    m_pEditEmail->setPlaceHolder("Email:");
    m_pEditEmail->setInputMode(kEditBoxInputModeEmailAddr);
    m_pEditEmail->setDelegate(this);
    addChild(m_pEditEmail);
}

void HelloWorld::editBoxEditingDidBegin(cocos2d::extension::CCEditBox* editBox)
{
    CCLog("editBox %p DidBegin !", editBox);
}

void HelloWorld::editBoxEditingDidEnd(cocos2d::extension::CCEditBox* editBox)
{
    CCLog("editBox %p DidEnd !", editBox);
}

void HelloWorld::editBoxTextChanged(cocos2d::extension::CCEditBox* editBox, const std::string& text)
{
    CCLog("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

void HelloWorld::editBoxReturn(CCEditBox* editBox)
{
    CCLog("editBox %p was returned !", editBox);
}


#define FIX_POS(_pos, _min, _max) \
    if (_pos < _min)        \
    _pos = _min;        \
else if (_pos > _max)   \
    _pos = _max;        \

void HelloWorld::didAccelerate(CCAcceleration *pAccelerationValue)
{
    CCLog("Acceleration method called!");

    CCDirector* pDir = CCDirector::sharedDirector();

    /*FIXME: Testing on the Nexus S sometimes m_pBall is NULL */
    if ( m_pBall == NULL ) {
        return;
    }

    CCSize ballSize  = m_pBall->getContentSize();

    CCPoint ptNow  = m_pBall->getPosition();
    CCPoint ptTemp = pDir->convertToUI(ptNow);

    ptTemp.x += pAccelerationValue->x * 9.81f;
    ptTemp.y -= pAccelerationValue->y * 9.81f;

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    CCPoint ptNext = pDir->convertToGL(ptTemp);
    FIX_POS(ptNext.x, (0+ballSize.width / 2.0), (winSize.width - ballSize.width / 2.0));
    FIX_POS(ptNext.y, (0+ballSize.height / 2.0), (winSize.height - ballSize.height / 2.0));
    m_pBall->setPosition(ptNext);
}
