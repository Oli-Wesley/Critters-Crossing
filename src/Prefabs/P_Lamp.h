#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_LampManager.h"

REGISTER_PREFAB(
	P_Lamp,            // name
	[]() -> GameObject* // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* game_object = pref->InstantiatePrefab("P_RenderableObject", "Lamp");
		game_object->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Lamp.png");
		GameObject* glow = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "Lamp_Glow"));
		glow->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Lamp_glow.png");
		glow->getTransform()->setLocalZheight(0.1);
		glow->setDrawn(0); // default to glow being hidden.
		game_object->getTransform()->setLocalScale(0.5);

		game_object->addScript<S_LampManager>();
		return game_object;
	});