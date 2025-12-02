#include "GameOverScene.h"
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_SceneButton.h"
#include "../Scripts/S_GlobalData.h"

void GameOverScene::load()
{
  PrefabRegistry* pref = PrefabRegistry::get();

  // background
  GameObject* background = new GameObject("background");
  background->getTransform()->setLocalPosition(0, 0);
  background->getTransform()->setLocalScale(5, 5);
  background->getTransform()->setLocalZheight(-5);

  background->addComponent<SpriteRenderer>();
  background->addComponent<Texture>("../Data/Images/Pixelartimages/GameOverScreen.png");
  scene_root->addChild(background);

  // play button
  GameObject* play_button = new GameObject("PlayButton");
  play_button->getTransform()->setLocalPosition(280, 350);
  play_button->getTransform()->setLocalScale(5, 5);
  play_button->addComponent<SpriteRenderer>();
  play_button->addComponent<Clickable>();
  play_button->addComponent<Texture>();
  play_button->addComponent<BoxCollider>(21, 15);
  play_button->addScript<S_SceneButton>("GameScene", "../Data/Images/Pixelartimages/Desk_button_wide_Idle.png", "../Data/Images/Pixelartimages/Desk_button_wide_hover.png", "../Data/Images/Pixelartimages/Desk_button_wide_pressed.png");
  scene_root->addChild(play_button);

  // get score from global data (used to transfer between scenes)
  //std::cout << GameSystem::get()->getCurrentScene()->dont_destroy->getChildByName("global_data")->getComponent<S_GlobalData>()->score;
}
