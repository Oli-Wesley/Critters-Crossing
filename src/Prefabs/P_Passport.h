#pragma once

#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_AcceptDeny.h"

REGISTER_PREFAB(
	P_Passport,            // name
	[]() -> GameObject* // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* game_object = new GameObject("Passport");
		game_object->getTransform()->setLocalScale(4, 4);

		GameObject* passport_background = game_object->addChild(pref->InstantiatePrefab("P_Renderable_Object"));
		GameObject* passport_foreground = game_object->addChild(pref->InstantiatePrefab("P_Renderable_Object"));
		GameObject* passport_person = game_object->addChild(pref->InstantiatePrefab("P_Renderable_Object"));
		GameObject* passport_accept_deny = game_object->addChild(pref->InstantiatePrefab("P_Renderable_Object"));

		passport_background->setName("passport_background");
		passport_foreground->setName("passport_foreground");
		passport_person->setName("passport_person");
		passport_accept_deny->setName("passport_accept_deny");

		passport_person->getTransform()->setLocalScale(0.5, 0.5); // scale down so person fits. 
		
		passport_background->getTransform()->setLocalZheight(1);
		passport_person->getTransform()->setLocalZheight(1.1);
		passport_foreground->getTransform()->setLocalZheight(2.5); // big jump to let the person layers fit.
		passport_accept_deny->getTransform()->setLocalZheight(2.6);


		passport_background->getComponent<Texture>()->setTexture("../Data/Images/PassportLayers/Passport_background.png");
		passport_foreground->getComponent<Texture>()->setTexture("../Data/Images/PassportLayers/Passport_layer.png");
		passport_accept_deny->addScript<S_AcceptDeny>();

		return game_object;
	});