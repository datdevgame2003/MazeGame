#include "Tutorial.h"
USING_NS_CC;

Scene* Tutorial::createScene()
{
    return Tutorial::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Tutorial::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    

    
    return true;
}


void Tutorial::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
