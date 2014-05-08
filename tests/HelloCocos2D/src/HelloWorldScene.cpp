#include "HelloWorldScene.h"
#include <cocos-ext.h>
#include <SimpleAudioEngine.h>

USING_NS_CC;
USING_NS_CC_EXT;
using namespace CocosDenshion;

static HelloWorld *g_pHelloWorld = NULL;
Scene *HelloWorld::scene()
{
	// 'scene' is an autorelease object
    Scene *scene = Scene::create();
	
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
    UserDefault* _userDefault = UserDefault::getInstance();
    _userDefault->setIntegerForKey("Hello", 2);
    _userDefault->flush();

	//////////////////////////////
	// 1. super init first
    if ( !Layer::init() )
	{
		return false;
    }

    /////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
//    MenuItemImage *pCloseItem = MenuItemImage::create(
//                                        "CloseNormal.png",
//                                        "CloseSelected.png",
//                                        this,
//                                        menu_selector(HelloWorld::menuCloseCallback) );
    MenuItemImage* pCloseItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", [&](Ref* sender)->void {
        Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_QT5)
        exit(0);
#endif
    });
    pCloseItem->setPosition( Point(Director::getInstance()->getWinSize().width - 20, 20) );

	// create menu, it's an autorelease object
    Menu* pMenu = Menu::create(pCloseItem, NULL);
    pMenu->setPosition( Point::ZERO );
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
    Label* pLabel = Label::createWithSystemFont("Hello World By Qt", "Arial", 24);   //LabelTTF::create("Hello World By Qt", "Arial", 24);
    m_label = pLabel;
	// ask director the window size
    Size size = Director::getInstance()->getWinSize();
    CCLOG("HelloWorldScene: %lf, %lf", size.width, size.height);

	// position the label on the center of the screen
    pLabel->setPosition( Point(size.width / 2, size.height - 50) );

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "HelloWorld" splash screen"
    Sprite* pSprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
    pSprite->setPosition( Point(size.width/2, size.height/2) );

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);

    this->schedule(schedule_selector(HelloWorld::addSpriteRamdon), 0.5f);
    this->addEditBox(0);

    this->setAccelerometerEnabled(true);

    // test for accelerometer
    m_pBall = NULL;
    {
        m_pBall = Sprite::create("Pea.png");
        m_pBall->setPosition( Point(size.width/2, size.height/2) );
        addChild(m_pBall);
    }

//    SimpleAudioEngine::getInstance()->playEffect("background.mp3");

	return true;
}

void HelloWorld::menuCloseCallback(Ref* /*pSender*/)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_QT5)
    exit(0);
#endif
}

void HelloWorld::addSpriteRamdon(float /*dt*/)
{
    Size size = Director::getInstance()->getWinSize();
    Sprite *pSprite = Sprite::create("CloseNormal.png");
    pSprite->setPosition(Point(CCRANDOM_0_1()*size.width, CCRANDOM_0_1()*size.height));
    this->addChild(pSprite);
}

void HelloWorld::addSpriteRamdon2(float /*dt*/)
{
    Size size = Director::getInstance()->getWinSize();
    Sprite *pSprite = Sprite::create("Qt.png");
    pSprite->setPosition(Point(CCRANDOM_0_1()*size.width, CCRANDOM_0_1()*size.height));
    this->addChild(pSprite);


    ParticleSystemQuad *fire = ParticleSystemQuad::create();
    this->addChild(fire);
    fire->setPosition(Point(CCRANDOM_0_1()*size.width, CCRANDOM_0_1()*size.height));
    fire->setTexture( Director::getInstance()->getTextureCache()->addImage("Qt.png") );
}

void HelloWorld::addEditBox(float /*dt*/)
{
    Size winSize = Director::getInstance()->getWinSize();
    Size editBoxSize = Size(winSize.width, 60);
    // bottom
    EditBox *m_pEditEmail = EditBox::create(Size(editBoxSize.width, editBoxSize.height), Scale9Sprite::create("yellow_edit.png"));
    m_pEditEmail->setPosition(Point(winSize.width/2, 100));
    m_pEditEmail->setAnchorPoint(Point(0.5, 1.0f));
    m_pEditEmail->setPlaceHolder("Email:");
    m_pEditEmail->setInputMode(EditBox::InputMode::EMAIL_ADDRESS);
    m_pEditEmail->setDelegate(this);
    addChild(m_pEditEmail);
}

void HelloWorld::editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox)
{
    CCLOG("editBox %p DidBegin !", editBox);
}

void HelloWorld::editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox)
{
    CCLOG("editBox %p DidEnd !", editBox);
}

void HelloWorld::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text)
{
    CCLOG("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

void HelloWorld::editBoxReturn(EditBox* editBox)
{
    CCLOG("editBox %p was returned !", editBox);
}


#define FIX_POS(_pos, _min, _max) \
    if (_pos < _min)        \
    _pos = _min;        \
else if (_pos > _max)   \
    _pos = _max;        \

//void HelloWorld::didAccelerate(CCAcceleration *pAccelerationValue)
//{
//    CCLOG("Acceleration method called!");

//    CCDirector* pDir = Director::getInstance();

//    /*FIXME: Testing on the Nexus S sometimes m_pBall is NULL */
//    if ( m_pBall == NULL ) {
//        return;
//    }

//    CCSize ballSize  = m_pBall->getContentSize();

//    CCPoint ptNow  = m_pBall->getPosition();
//    CCPoint ptTemp = pDir->convertToUI(ptNow);

//    ptTemp.x += pAccelerationValue->x * 9.81f;
//    ptTemp.y -= pAccelerationValue->y * 9.81f;

//    CCSize winSize = Director::getInstance()->getWinSize();

//    CCPoint ptNext = pDir->convertToGL(ptTemp);
//    FIX_POS(ptNext.x, (0+ballSize.width / 2.0), (winSize.width - ballSize.width / 2.0));
//    FIX_POS(ptNext.y, (0+ballSize.height / 2.0), (winSize.height - ballSize.height / 2.0));
//    m_pBall->setPosition(ptNext);
//}
