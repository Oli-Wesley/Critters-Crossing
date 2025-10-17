#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_CharactorCreator.h"

REGISTER_PREFAB(
	P_Stamp,            // name
	[]() -> GameObject* // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* game_object = pref->InstantiatePrefab("P_Renderable_Object");
		game_object->setName("Stamp");
		game_object->getTransform()->setLocalScale(4,4);
		game_object->getTransform()->setLocalZheight(3);

		// give/setup components
		game_object->addComponent<Draggable>();
		game_object->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Stamp_green.png");
		game_object->addComponent<BoxCollider>(60, 26);

		return game_object;
	});