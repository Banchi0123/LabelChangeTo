# LabelChangeTo  
  
  This class provides an easy counting-up/down action to cocos2d-x ui::Text.  
  
# Sample  
  
  ```c++
  
  ui::Text* scoreText = (ui::Text*)resultLayer->getChildByName("Score");
  scoreText->setString("0.00");
  scoreText->runAction(LabelChangeTo<float>::create(2,10.0f));
  
  ```
