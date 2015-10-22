#ifndef __SampleScene_h__
#define __SampleScene_h__

#include "cocos2d.h"

class SampleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SampleScene);
};

#endif // __SampleScene_h__
