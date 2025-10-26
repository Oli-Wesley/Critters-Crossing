#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_Stamp.h"

REGISTER_PREFAB(
	P_Stamp,            // name
	[]() -> GameObject* // lambda construction func
	{
		GameObject* game_object = new GameObject("stamp_none");
		game_object->getTransform()->setLocalScale(4,4);
		game_object->getTransform()->setLocalZheight(3);

		// give/setup components
		game_object->addComponent<Draggable>();
		game_object->addComponent<Texture>();
		game_object->addComponent<RigidBody>()->is_static = true;
		game_object->addComponent<SpriteRenderer>(); 
		game_object->addComponent<BoxCollider>(60, 26);
		game_object->addScript<S_Stamp>();

		game_object->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Stamp_green.png");

		return game_object;
	});	