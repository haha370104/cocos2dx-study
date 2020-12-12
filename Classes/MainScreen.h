//
//  MainScreen.hpp
//  test-game-mobile
//
//  Created by luoxiangyu on 2020/12/12.
//

#ifndef MainScreen_hpp
#define MainScreen_hpp

#include "cocos2d.h"

class MainScreen : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScreen);
};

#endif /* MainScreen_hpp */
