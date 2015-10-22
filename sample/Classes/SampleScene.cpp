#include "SampleScene.h"
#include "ui/CocosGUI.h"
#include "LabelChangeTo.h"

USING_NS_CC;

Scene* SampleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SampleScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SampleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    
    auto intText = ui::Text::create("0", "fonts/arial.ttf", 30);
    intText->setPosition(Vec2(winSize.width/2, winSize.height - 100));
    this->addChild(intText);
    
    auto longText = ui::Text::create("0", "fonts/arial.ttf", 30);
    longText->setPosition(Vec2(winSize.width/2, winSize.height - 150));
    this->addChild(longText);
    
    auto floatText = ui::Text::create("0.00", "fonts/arial.ttf", 30);
    floatText->setPosition(Vec2(winSize.width/2, winSize.height - 200));
    this->addChild(floatText);
    
    auto doubleText = ui::Text::create("0.00", "fonts/arial.ttf", 30);
    doubleText->setPosition(Vec2(winSize.width/2, winSize.height - 250));
    this->addChild(doubleText);
    
    
    auto countUpButton = ui::Button::create();
    countUpButton->setSizePercent(Vec2(200,200));
    countUpButton->setTitleText("count up");
    countUpButton->setPosition(Vec2(winSize.width/4,100));
    
    countUpButton->addTouchEventListener([=](Ref* target, ui::Widget::TouchEventType type){
        
        if(type == ui::Widget::TouchEventType::ENDED)
        {
            
            {
                auto value = atoi(intText->getString().c_str());
                intText->runAction(LabelChangeTo<int>::create(0.4f, value + 20));
            }
            
            {
                auto value = atol(longText->getString().c_str());
                longText->runAction(LabelChangeTo<long>::create(0.4f, value + 20));
            }
            
            {
                auto value = (float)atof(floatText->getString().c_str());
                floatText->runAction(LabelChangeTo<float>::create(0.4f, value + 20.45f));
            }
            
            {
                auto value = atof(doubleText->getString().c_str());
                doubleText->runAction(LabelChangeTo<double>::create(0.4f, value + 20.45));
            }
        }
        
    });
    
    this->addChild(countUpButton);
    
    auto countDownButton = ui::Button::create();
    countDownButton->setSizePercent(Vec2(200,200));
    countDownButton->setTitleText("count down");
    countDownButton->setPosition(Vec2(winSize.width/4 * 3,100));
    
    countDownButton->addTouchEventListener([=](Ref* target, ui::Widget::TouchEventType type){
        
        if(type == ui::Widget::TouchEventType::ENDED)
        {
            
            {
                auto value = atoi(intText->getString().c_str());
                intText->runAction(LabelChangeTo<int>::create(0.4f, value - 20));
            }
            
            {
                auto value = atol(longText->getString().c_str());
                longText->runAction(LabelChangeTo<long>::create(0.4f, value - 20));
            }
            
            {
                auto value = (float)atof(floatText->getString().c_str());
                floatText->runAction(LabelChangeTo<float>::create(0.4f, value - 20.45f));
            }
            
            {
                auto value = atof(doubleText->getString().c_str());
                doubleText->runAction(LabelChangeTo<double>::create(0.4f, value - 20.45));
            }
        }
        
    });
    
    this->addChild(countDownButton);
    
    return true;
}
