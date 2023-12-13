#include "Setting.h"
USING_NS_CC;

Scene* Setting::createScene()
{
    return Setting::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Setting::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    return true;
}


void Setting::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
