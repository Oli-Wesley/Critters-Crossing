#pragma once
#include "../Libraries/GameEngine.h"

REGISTER_PREFAB(
	P_SceneButton,            // name
	[]()->GameObject* // lambda construction func
	{
		GameObject* game_object = new GameObject("Scene_Button");
		game_object->addComponent<Texture>();
		game_object->addComponent<Clickable>();
		game_object->addComponent<BoxCollider>();
		game_object->addComponent<SpriteRenderer>();
		return game_object;
	});