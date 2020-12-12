//
//  MainScreen.cpp
//  test-game-mobile
//
//  Created by luoxiangyu on 2020/12/12.
//
#include "MainScreen.h"

USING_NS_CC;

Scene* MainScreen::createScene()
{
    return MainScreen::create();
}

// on "init" you need to initialize your instance
bool MainScreen::init()
{
    return true;
}


void MainScreen::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}

