#ifndef __LABELCHANGETO_H__
#define __LABELCHANGETO_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

template<typename T>
class LabelChangeTo : public ActionInterval
{
public:
    
    LabelChangeTo()
    : _num()
    , _startNum()
    , _endNum()
    , _deltaNum()
    , _didChangeCallBack()
    {};
    
    static LabelChangeTo* create(float duration, T n, std::function<void()> didChangeCallback = nullptr)
    {
        LabelChangeTo *pChangeTo = new LabelChangeTo();
        pChangeTo->initWithDuration(duration, n, didChangeCallback);
        pChangeTo->autorelease();
        
        return pChangeTo;
    };
    
    bool initWithDuration(float duration, T n, std::function<void()> didChangeCallback)
    {
        if (ActionInterval::initWithDuration(duration))
        {
            _endNum = n;
            
            _didChangeCallBack = didChangeCallback;
            
            return true;
        }
        
        return false;
    };
    
    virtual void startWithTarget(Node* target)
    {
        ActionInterval::startWithTarget(target);
        auto targetText = (ui::Text*)target;
        
        this->setStartNum(_startNum, targetText->getString().c_str());
        _deltaNum = _endNum - _startNum;
    };
    
    virtual void update(float time)
    {
        if (_target)
        {
            auto targetText = (ui::Text*)_target;
            const std::string& nowString = targetText->getString();
            const std::string& nextString = getStringFromNum(_startNum + (T)(_deltaNum * time));
            if(nowString != nextString)
            {
                targetText->setString(nextString);
                if(_didChangeCallBack) _didChangeCallBack();
            }
        }
    };
    
protected:
    
    void setStartNum(int& startNum, const std::string& text)
    {
        startNum = atoi(text.c_str());
    };
    
    void setStartNum(float& startNum, const std::string& text)
    {
        startNum = atof(text.c_str());
    };
    
    void setStartNum(double& startNum, const std::string& text)
    {
        startNum = atof(text.c_str());
    };
    
    void setStartNum(long& startNum, const std::string& text)
    {
        startNum = atol(text.c_str());
    };
    
    std::string getStringFromNum(const int& num)
    {
        char buffer[64] = {0};
        sprintf(buffer, "%d",num);
        return std::string(buffer);
    }
    
    std::string getStringFromNum(const float& num)
    {
        char buffer[64] = {0};
        sprintf(buffer, "%.2f",num);
        return std::string(buffer);
    }
    
    std::string getStringFromNum(const double& num)
    {
        char buffer[64] = {0};
        sprintf(buffer, "%.2lf",num);
        return std::string(buffer);
    }
    
    std::string getStringFromNum(const long& num)
    {
        char buffer[64] = {0};
        sprintf(buffer, "%ld",num);
        return std::string(buffer);
    }
    
    T _num;
    T _startNum;
    T _endNum;
    T _deltaNum;
    
    std::function<void()> _didChangeCallBack;
};

#endif