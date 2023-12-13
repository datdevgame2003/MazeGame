#include "MainMenu.h"
#include"ui/CocosGUI.h"
#include"GameScene.h"
#include"Setting.h"
#include"Tutorial.h"
USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool MainMenu::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("menu_bg.png");
    background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    background->setScale(3);
    this->addChild(background, -1);

   

    auto button = ui::Button::create("button.png");
    button->setTitleText("Play");
    button->setTitleColor(Color3B::BLACK);
    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                CCLOG("Button 1 clicked!");
                Director::getInstance()->replaceScene(TransitionFade::create(2, GameScene::createScene()));
                break;
            case ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });
    button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    button->setScale(2);
    this->addChild(button);

    auto button1 = ui::Button::create("button.png");
    button1->setTitleText("Setting");
    button1->setTitleColor(Color3B::BLACK);
    button1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                CCLOG("Button 1 clicked!");
                Director::getInstance()->replaceScene(TransitionFade::create(2, Setting::createScene()));
                break;
            case ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });
    button1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 80));
    button1->setScale(2);
    this->addChild(button1);

    auto button2 = ui::Button::create("button.png");
    button2->setTitleText("Tutorial");
    button2->setTitleColor(Color3B::BLACK);
    button2->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                CCLOG("Button 1 clicked!");
                Director::getInstance()->replaceScene(TransitionFade::create(2, Tutorial::createScene()));
                break;
            case ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });
    button2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 160));
    button2->setScale(2);
    this->addChild(button2);

    auto button3 = ui::Button::create("button.png");
    button3->setTitleText("Quit");
    button3->setTitleColor(Color3B::BLACK);
    button3->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                CCLOG("Button 3 clicked!");
                Director::getInstance()->end();
                break;
            case ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });
    button3->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 240));
    button3->setScale(2);
    this->addChild(button3);


    return true;
}


void MainMenu::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
