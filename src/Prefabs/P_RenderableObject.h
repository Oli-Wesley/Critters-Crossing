#pragma once
#include "../Libraries/GameEngine.h"

REGISTER_PREFAB(
	P_RenderableObject,            // name
	[]() -> GameObject* // lambda construction func
	{
		GameObject* game_object = new GameObject("Renderable_Object");
		game_object->addComponent<SpriteRenderer>();
		game_object->addComponent<Texture>();

		return game_object;
	});