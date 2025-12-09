#include "GameOverScene.h"
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_SceneButton.h"
#include "../Scripts/S_GlobalData.h"
#include "../Scripts/S_ScoreDisplay.h"
#include <iostream>

void GameOverScene::load()
{
  PrefabRegistry* pref = PrefabRegistry::get();

  // background
  GameObject* background = scene_root->addChild(std::make_unique<GameObject>("background"));
  background->getTransform()->setLocalPosition(0, 0);
  background->getTransform()->setLocalScale(5, 5);
  background->getTransform()->setLocalZheight(-5);

  background->addComponent<SpriteRenderer>();
  background->addComponent<Texture>("../Data/Images/Pixelartimages/GameOverScreen.png");

  // replay button
  GameObject* replay_button = scene_root->addChild(std::make_unique<GameObject>("RePlayButton"));
  replay_button->getTransform()->setLocalPosition(525, 350);
  replay_button->getTransform()->setLocalScale(5, 5);
  replay_button->addComponent<SpriteRenderer>();
  replay_button->addComponent<Clickable>();
  replay_button->addComponent<Texture>();
  replay_button->addComponent<BoxCollider>(61, 23);
  replay_button->addScript<S_SceneButton>("GameScene", "../Data/Images/Pixelartimages/Replay_button_idle.png", "../Data/Images/Pixelartimages/Replay_button_hover.png");


  // title button
  GameObject* title_button = scene_root->addChild(std::make_unique<GameObject>("TitleButton"));
  title_button->getTransform()->setLocalPosition(125, 350);
  title_button->getTransform()->setLocalScale(5, 5);
  title_button->addComponent<SpriteRenderer>();
  title_button->addComponent<Clickable>();
  title_button->addComponent<Texture>();
  title_button->addComponent<BoxCollider>(61, 23);
  title_button->addScript<S_SceneButton>("TitleScene", "../Data/Images/Pixelartimages/Title_button_idle.png", "../Data/Images/Pixelartimages/Title_button_hover.png");



  // fallback to create global data here, incase title screen was never run (SHOULD NEVER HAPPEN IN GAMEPLAY, BUT HAPPENS IN TESTING DUE TO LOADING THE SCENES DIRECTLY AND SKIPPING TITLE SCENE)
  if (dont_destroy->getChildByName("global_data") == nullptr) {
	  dont_destroy->addChild(std::make_unique<GameObject>("global_data"))->addScript<S_GlobalData>();
  }

  // score
  GameObject* score_obj = scene_root->addChild(pref->InstantiatePrefab("P_NumberDisplay", "Score", 660, 125));
  int score = dont_destroy->getChildByName("global_data")->getComponent<S_GlobalData>()->score;
  score_obj->getComponent<S_ScoreDisplay>()->setvalue(score);
  score_obj->getComponent<TextComponent>()->setCharacterSize(25);

  // jogj scpre
  GameObject* high_score_obj = scene_root->addChild(pref->InstantiatePrefab("P_NumberDisplay", "HighScore", 660, 195));
  int high_score = dont_destroy->getChildByName("global_data")->getComponent<S_GlobalData>()->high_score;
  high_score_obj->getComponent<S_ScoreDisplay>()->setvalue(high_score);
  high_score_obj->getComponent<TextComponent>()->setCharacterSize(25);
}
