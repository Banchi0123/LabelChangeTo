# Summary  
  
  This class provides an easy counting-up/down action to cocos2d-x ui::Text.  
  
# Requirements
  
* cocos2d-x v3.0+
  
# Sample  
  
  ```c++
  
  ui::Text* scoreText = (ui::Text*)resultLayer->getChildByName("Score");
  scoreText->setString("0.00");
  scoreText->runAction(LabelChangeTo<float>::create(2,10.0f));
  
  ```
  
Other examples have been here.   <https://github.com/Banchi0123/LabelChangeTo/blob/master/sample/Classes/SampleScene.cpp>.
