#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_Stamp.h"

REGISTER_PREFAB(
	P_Stamp,            // name
	[]() -> std::unique_ptr<GameObject> // lambda construction func
	{
		std::unique_ptr<GameObject> game_object = std::make_unique<GameObject>("stamp_none");
		game_object->getTransform()->setLocalScale(2.5);
		game_object->getTransform()->setLocalZheight(10);

		// give/setup components
		game_object->addComponent<Draggable>();
		game_object->addComponent<Texture>();
		game_object->addComponent<RigidBody>()->is_static = true;
		game_object->addComponent<SpriteRenderer>(); 
		game_object->addComponent<BoxCollider>(68, 28);
		game_object->addScript<S_Stamp>();

		game_object->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Stamp_green.png");

		return game_object;
	});	