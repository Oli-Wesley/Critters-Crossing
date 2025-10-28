#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_LampManager.h"

REGISTER_PREFAB(
	P_LampManager,            // name
	[]() -> GameObject* // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* game_object = new GameObject("Lamp_Manager");
		game_object->getTransform()->setLocalZheight(5);
		game_object->getTransform()->setLocalScale(5);

		game_object->addChild(pref->InstantiatePrefab("P_Lamp"));
		game_object->addChild(pref->InstantiatePrefab("P_Lamp", 17, 0));
		game_object->addChild(pref->InstantiatePrefab("P_Lamp", 34, 0));

		game_object->addScript<S_LampManager>();
		return game_object;
	});