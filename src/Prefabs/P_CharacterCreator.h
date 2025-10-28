#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_CharactorCreator.h"

REGISTER_PREFAB(
	P_CharacterCreator,            // name
	[]() -> GameObject* // lambda construction func
	{		
		GameObject* game_object = new GameObject("Character_Creator");
		game_object->addScript<S_CharactorCreator>();
		game_object->getTransform()->setLocalScale(5);
		return game_object;
	});