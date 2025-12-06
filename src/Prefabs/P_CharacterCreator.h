#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_CharactorCreator.h"

REGISTER_PREFAB(
	P_CharacterCreator,            // name
	[]() -> std::unique_ptr<GameObject> // lambda construction func
	{		
		std::unique_ptr<GameObject> game_object = std::make_unique<GameObject>("Character_Creator");
		game_object.get()->addScript<S_CharactorCreator>();
		game_object.get()->getTransform()->setLocalScale(5);
		return game_object;
	});