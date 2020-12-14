//
//  MainScreen.cpp
//  test-game-mobile
//
//  Created by luoxiangyu on 2020/12/12.
//
#include "MainScreen.h"
#include "SimpleAudioEngine.h"
#include <iostream>

USING_NS_CC;

Scene* MainScreen::createScene()
{
    return MainScreen::create();
}

// on "init" you need to initialize your instance
bool MainScreen::init()
{
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainScreen::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Main Screen", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    
    this->schedule(schedule_selector(MainScreen::animation));
    this->_defaultCamera->lookAt(Vec3(0, 0, 0), Vec3(0.5, 0.5, 0));
    
    return true;
}

void MainScreen::animation(float f) {
    auto sp = this->getChildren();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    for (auto a: sp) {
        Camera *camera = dynamic_cast<Camera *>(a);
        if (camera) {
            continue;
        }
        
        auto currentPosition = a->getPosition();
        MoveTo::create(2, Vec2(50,10));
        
        if (currentPosition.y > 0) {
            a->setPosition(currentPosition.x, currentPosition.y - 2);
        } else {
            a->setPosition(currentPosition.x, visibleSize.height);
        }
    }
    std::cout<<f<<std::endl;

}

void MainScreen::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}

