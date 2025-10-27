#pragma once

#pragma once
#include "../Libraries/GameEngine.h"

REGISTER_PREFAB(
	P_CharacterFrame,            // name
	[]() -> GameObject* // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* game_object = new GameObject("CharacterFrame");
		game_object->getTransform()->setLocalScale(5);

		game_object->addChild(pref->InstantiatePrefab("P_RenderableObject"))->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Frame_Background.png");
		GameObject* foreground = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject"));
		foreground->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Frame_Foreground.png");
		foreground->getTransform()->setLocalZheight(2.9); // just under the stamps

		return game_object;
	});