#pragma once
#include "../Libraries/GameEngine.h"

REGISTER_PREFAB(
	P_ElFisho,            // name
	[]() -> GameObject* // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* game_object = pref->InstantiatePrefab("P_RenderableObject", "El_Fisho");
		game_object->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/El_Fisho.png");
		GameObject* plaque = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "Plaque"));
		plaque->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Plaque.png");
		game_object->getTransform()->setLocalZheight(5.1);
		game_object->getTransform()->setLocalScale(2.5);

		plaque->getTransform()->setLocalZheight(-0.1);

		return game_object;
	});