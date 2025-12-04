#include "TitleScene.h"
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_SceneButton.h"
#include "../Scripts/S_GlobalData.h"
#include "../Scripts/S_ScoreDisplay.h"

void TitleScene::load()
{
  PrefabRegistry* pref = PrefabRegistry::get();

  // background
  GameObject* background = new GameObject("background");
  background->getTransform()->setLocalPosition(0, 0);
  background->getTransform()->setLocalScale(5, 5);
  background->getTransform()->setLocalZheight(-5);

  background->addComponent<SpriteRenderer>();
  background->addComponent<Texture>("../Data/Images/Pixelartimages/Title Screen.png");
  scene_root->addChild(background);

  GameObject* notices = scene_root->addChild(pref->InstantiatePrefab("P_RenderableObject", "Notices"));
  notices->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Notices.png");
  notices->getTransform()->setLocalScale(2.5, 2.5);
  notices->getTransform()->setLocalPosition(685, 35);

  GameObject* record = scene_root->addChild(pref->InstantiatePrefab("P_RenderableObject", "Record"));
  record->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Workplace Record.png");
  record->getTransform()->setLocalScale(2.5, 2.5);
  record->getTransform()->setLocalPosition(675, 400);

  // play button
  GameObject* play_button = new GameObject("PlayButton");
  play_button->getTransform()->setLocalPosition(280, 350);
  play_button->getTransform()->setLocalScale(5, 5);
  play_button->addComponent<SpriteRenderer>();
  play_button->addComponent<Clickable>();
  play_button->addComponent<Texture>();
  play_button->addComponent<BoxCollider>(21, 15);
  play_button->addScript<S_SceneButton>("GameScene", "../Data/Images/Pixelartimages/Desk_button_wide_Idle.png", "../Data/Images/Pixelartimages/Desk_button_wide_hover.png");
  scene_root->addChild(play_button);


  // only create global data the first time the scene is loaded. 
  if (dont_destroy->getChildByName("global_data") == nullptr) {
	  dont_destroy->addChild(new GameObject("global_data"))->addScript<S_GlobalData>();
  }


  // Score Displays
  GameObject* number_display = record->addChild(pref->InstantiatePrefab("P_NumberDisplay", 11, 25));
  int high_score = dont_destroy->getChildByName("global_data")->getComponent<S_GlobalData>()->high_score;
  number_display->getComponent<S_ScoreDisplay>()->setvalue(high_score);
}
