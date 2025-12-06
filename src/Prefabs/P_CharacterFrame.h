#pragma once

#pragma once
#include "../Libraries/GameEngine.h"

REGISTER_PREFAB(
	P_CharacterFrame,            // name
	[]() -> std::unique_ptr<GameObject> // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		std::unique_ptr<GameObject> game_object = std::make_unique<GameObject>("CharacterFrame");
		game_object->getTransform()->setLocalScale(5);

		game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "background"))->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Frame_Background.png");
		GameObject* foreground = game_object.get()->addChild(pref->InstantiatePrefab("P_RenderableObject", "foreground"));
		foreground->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Frame_Foreground.png");
		foreground->getTransform()->setLocalZheight(2.9); // just under the stamps

		return game_object;
	});