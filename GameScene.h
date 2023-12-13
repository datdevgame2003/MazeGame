#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include"Map/GameMap.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    bool OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
protected:
    GameMap* _gameMap;

};

#endif // __GAME_SCENE_H__
