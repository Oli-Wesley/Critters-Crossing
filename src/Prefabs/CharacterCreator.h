#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_CharactorCreator.h"

REGISTER_PREFAB(
	P_Character_Creator,            // name
	[]() -> GameObject* // lambda construction func
	{

		PrefabRegistry* pref = PrefabRegistry::get();		
		GameObject* game_object = new GameObject("Character_Creator");
		game_object->addScript<S_CharactorCreator>();
		game_object->getTransform()->setLocalScale(4, 4);
		return game_object;
	});