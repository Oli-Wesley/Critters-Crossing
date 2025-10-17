#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_CharactorCreator.h"

REGISTER_PREFAB(
	P_Renderable_Object,            // name
	[]() -> GameObject* // lambda construction func
	{
		GameObject* game_object = new GameObject("Renderable_Object");
		game_object->addComponent<SpriteRenderer>();
		game_object->addComponent<Texture>();

		return game_object;
	});