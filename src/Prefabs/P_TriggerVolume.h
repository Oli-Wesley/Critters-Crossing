#pragma once
#include "../Libraries/GameEngine.h"
REGISTER_PREFAB(
	P_TriggerVolume,            // name
	[]() -> GameObject* // lambda construction func
	{
		GameObject* game_object = new GameObject("trigger_volume");

		game_object->addComponent<BoxCollider>(10, 10);
		RigidBody* rb = game_object->addComponent<RigidBody>();

		rb->is_static = 1;
		rb->is_trigger = 1;

		return game_object;
	});