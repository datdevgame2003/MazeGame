#include "Start.h"
#include"MainMenu.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

Scene* Start::createScene()
{
    return Start::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Start::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("background.png");
    background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    background->setScale(0.8);
    this->addChild(background, -1);

    auto nameGame = Label::createWithTTF("Maze Game", "fonts/victoria.ttf", 200);
    nameGame->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 250));
    nameGame->enableGlow(Color4B::GREEN);
    this->addChild(nameGame);

    auto button = ui::Button::create("BtnBlue.png");
    button->setTitleText("START");
    button->setTitleFontName("fonts/victoria.ttf");
    button->setTitleFontSize(160);
    button->setTitleColor(Color3B::ORANGE);
    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                CCLOG("Button 1 clicked!");
                Director::getInstance()->replaceScene(TransitionFade::create(2, MainMenu::createScene()));
                break;
            case ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });
    button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2-150));
    button->setScale(0.3);
    this->addChild(button);

    return true;
}


void Start::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
