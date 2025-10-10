#include "TitleScene.h"
#include "../Libraries/GameEngine.h"

void TitleScene::load()
{
  PrefabRegistry* pref = PrefabRegistry::get();

  // background
  GameObject* background = new GameObject("background");
  background->getTransform()->setLocalPosition(0, 0);
  background->getTransform()->setLocalScale(10, 10);
  background->getTransform()->setLocalZheight(-5);

  background->addComponent<SpriteRenderer>();
  background->addComponent<Texture>("../Data/Images/Background.png");
  scene_root->addChild(background);

  // play button
  GameObject* play_button = new GameObject("PlayButton");
  play_button->getTransform()->setLocalPosition(750, 490);
  play_button->getTransform()->setLocalScale(10, 10);
  play_button->addComponent<SpriteRenderer>();
  play_button->addComponent<Clickable>();
  play_button->addComponent<Texture>();
  play_button->addComponent<BoxCollider>(42, 16);
  play_button->addComponent<SceneButton>(
    "../Data/Images/PlayButton.png",
    "../Data/Images/PlayButton_hover.png",
    "Level");
  scene_root->addChild(play_button);

  // options button
  GameObject* quit_button = new GameObject("QuitButton");
  quit_button->getTransform()->setLocalPosition(800, 850);
  quit_button->getTransform()->setLocalScale(10, 10);
  quit_button->addComponent<SpriteRenderer>();
  quit_button->addComponent<Clickable>();
  quit_button->addComponent<Texture>();
  quit_button->addComponent<BoxCollider>(32, 16);
  quit_button->addComponent<SceneButton>(
    "../Data/Images/QuitButton.png",
    "../Data/Images/QuitButton_hover.png",
    "~Quit~");
  scene_root->addChild(quit_button);
}
